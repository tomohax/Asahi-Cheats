#include <cheats.hpp>
#include <time.h>
#include <vector>
#include <sstream>

namespace	CTRPluginFramework
{
    static StringVector items(200);

	//------------------------------
	//ゲーム開始/停止
	//------------------------------
	void GameStop(MenuEntry *entry)
	{
		static bool mode;

		if(Controller::IsKeysPressed(entry->Hotkeys[0].GetKeys()))
		{
			if(mode)
			{
				mode = true;
				Process::Play();
			}
			else {
				mode = false;
				Process::Pause();
                Sleep(Milliseconds(100.0f));
			}
		}
	}
	
	//------------------------------
	//プラグイン終了
	//------------------------------
	void plugin_exit(MenuEntry *entry)
	{
		if ( (MessageBox("プラグインを終了してよろしいですか？", DialogType::DialogOkCancel))() == true )
		{
			abort();
		}
	}
	
	//------------------------------
	//システム情報
	//------------------------------
	std::string SystemModel()
    {
        u8 model = 0;
        std::stringstream models;
        
        std::vector<std::string> Model = 
        {
            "OLD 3DS",
            "OLD 3DS XL",
            "NEW 3DS",
            "OLD 2DS",
            "NEW 3DS XL",
            "NEW 2DS XL"
        };
        
        CFGU_GetSystemModel(&model);
        models << "Model: " << Model[model];
        return models.str();
    }
    
    std::string SystemRegion()
    {
        u8 region = 0;
        std::stringstream regions;

        std::vector<std::string> Region =
        {
            "Japan",
            "USA",
            "Europe",
            "Australia",
            "China",
            "Korea",
            "Taiwan"
        };
        
        CFGU_SecureInfoGetRegion(&region);
        regions << "Region: " << Region[region];
        return regions.str();
    }
    
    std::string SystemLanguage()
    {
        std::stringstream language;
        LanguageId lang = System::GetSystemLanguage();
        int lang_num = static_cast<int>(lang);
        
        
        std::vector<std::string> Language =
        {
            "Japanese",
            "English",
            "French",
            "German",
            "Italian",
            "Spanish",
            "Simplified Chinese",
            "Korean",
            "Dutch",
            "Portugese",
            "Russian",
            "Traditional Chinese"
        };
        
        language << "Language: " << Language[lang_num];
        return language.str();
    }

    void DrawInfo(MenuEntry *entry)
    {   
		(
			MessageBox(
				"System Information\n"+
				SystemModel()+"\n"+
				SystemRegion()+"\n"+
				SystemLanguage()
			)
		)();
    }

	void DrawRegInfo(MenuEntry *entry)
    {
        CpuRegisters reg;
        
        OSDManager.Lock();
        const Screen &scr = OSD::GetTopScreen();

        u32 dy = 0, i = 0;
        for(const u32 &r : reg.r)
            dy = scr.Draw(Utils::Format("r%-2d  = %08X", i++, r), 0, dy);

        dy = scr.Draw(Utils::Format("sp   = %08X", reg.sp), 0, dy);
        dy = scr.Draw(Utils::Format("lr   = %08X", reg.lr), 0, dy);
        dy = scr.Draw(Utils::Format("pc   = %08X", reg.pc), 0, dy);
        dy = scr.Draw(Utils::Format("cpsr = %08X", reg.cpsr), 0, dy);
        
        OSDManager.Unlock();
    }

    void RangeWrite_4Byte(MenuEntry *entry)
    {
        static std::vector<u32> address_list={};
        static u32 start = 0x00100000;
        static u32 stop = 0x00100000;
        static u32 hex_before;
        static u32 hex_after;
        Keyboard keyboard("アドレスを書き込みますか?",{"書き込む","戻す","アドレス一覧"});
        int result1;
        int result2;
        result1 = keyboard.Open();
        if (result1 == 0) {
            Keyboard keyboard1("開始アドレス変更");
            keyboard1.Open(start, start);
            Keyboard keyboard2("終わりのアドレス変更");
            keyboard2.Open(stop, stop);
            Keyboard keyboard3("書き換え前の値を入力してください");
            keyboard3.Open(hex_before, hex_before);
            Keyboard keyboard4("書き換え後の値を入力してください");
            keyboard4.Open(hex_after, hex_after);
            address_list.clear();
            for(u32 address = start;address <= stop;address+=4) {
                u32 cmp;
                if (Process::Read32(address, cmp) && cmp == hex_before) {
                    Process::Write32(address, hex_after);
                    address_list.push_back(address);
                }
            }
        }
        else if(result1 == 1) {
            for(int i = 0;i < address_list.size();i++) {
                Process::Write32(address_list[i], hex_before);
            }
        }
        else if(result1 == 2) {
            items.clear();
            for(int i = 0;i < address_list.size();i++)
            items.push_back(Utils::ToHex(address_list[i]));
            Keyboard keyboard5("アドレス一覧", items);
            Keyboard keyboard6("このアドレスをどうしますか?", {"値変更", "一覧から削除"});
            result1 = keyboard5.Open();
            if(result1 != -1) {
                result2 = keyboard5.Open();
                if( result2 == 0) {
                    Keyboard keyboard7("値を入力してください");
                    u32 c;
                    if (keyboard7.Open (c) != -1) {
                        Process::Write16(address_list[result1], c);
                    }
                }
                else if(result2 == 1)
                address_list.erase(address_list.begin() + result1);
            }
        }
    }

    void DecCalculator(MenuEntry *entry)
    {
        u32 data;
        int dec1, dec2, ans, choice;
        Keyboard keyboard("1番目の10進数を入力してください。");
        keyboard.IsHexadecimal(false);
        if (keyboard.Open(data) != -1) {
            dec1 = data;
            Keyboard keyboard("算術演算子を選んでください。", {"+", "-", "×", "÷"});
            choice = keyboard.Open();
            if (choice != -1) {
                Keyboard keyboard("2番目の10進数を入力してください。");
                keyboard.IsHexadecimal(false);
                if (keyboard.Open(data) != -1) {
                    dec2 = data;
                    if (choice == 0) {
                        ans = dec1 + dec2;
                    }
                    if (choice == 1) {
                        ans = dec1 - dec2;
                    }
                    if (choice == 2) {
                        ans = dec1 * dec2;
                    }
                    if (choice == 3) {
                        ans = dec1 / dec2;
                    }
                    MessageBox(Utils::Format("結果は %d です。", ans))();
                }
            }
        }
    }

    void HexCalculator(MenuEntry *entry)
    {
        u32 data;
        int hex1, hex2, ans, choice;
        Keyboard keyboard("1番目の16進数を入力してください。");
        if (keyboard.Open(data) != -1) {
            hex1 = data;
            Keyboard keyboard("算術演算子を選んでください。", {"+", "-", "×", "÷"});
            choice = keyboard.Open();
            if (choice != -1) {
                Keyboard keyboard("2番目の16進数を入力してください。");
                if (keyboard.Open(data) != -1) {
                    hex2 = data;
                    if (choice == 0) {
                        ans = hex1 + hex2;
                    }
                    if (choice == 1) {
                        ans = hex1 - hex2;
                    }
                    if (choice == 2) {
                        ans = hex1 * hex2;
                    }
                    if (choice == 3) {
                        ans = hex1 / hex2;
                    }
                    MessageBox(Utils::Format("結果は %X です。", ans))();
                }
            }
        }
    }

	void DecToHex(MenuEntry *entry)
    {
        u32 out;
        Keyboard keyboard("10進数を入力してください。");
        keyboard.IsHexadecimal(false);
        if (keyboard.Open(out) != -1) {
            MessageBox(Utils::Format("結果は %X です。", out))();
        }
    }

    void HexToDec(MenuEntry *entry) {
        u32 out;
        Keyboard keyboard("16進数を入力してください。");
        if (keyboard.Open(out) != -1) {
            MessageBox(Utils::Format("結果は %d です。", (s32) out))();
        }
    }

    void GameInfo(MenuEntry *entry)
    {
        std::string processname, titleid;
        u32 processid;
        u16 version;
        Process::GetName(processname);
        Process::GetTitleID(titleid);
        processid = Process::GetProcessID();
        version = Process::GetVersion();
        MessageBox(
            "プロセス名: " + processname +
            "\nプロセスID: " + std::to_string(processid) +
            "\nバージョン: " + std::to_string(version) +
            "\nタイトルID: " + titleid
        )();
    }

    /*u32 drawvalue_address1

    void DrawValueSettings(MenuEntry *entry)
    {
        Keyboard keyboard("表示するアドレスを入力してください");
        if (keyboard.Open(drawvalue_address1) != -1) {
            MessageBox(Utils::Format("%x", drawvalue_address1))();
        }
    }

    void DrawValue(MenuEntry *entry)
    {
        u32 drawvalue_address2, drawvalue_address3;
        OSDManager.Lock();
        const Screen &scr = OSD::GetTopScreen();
        Process::Read32(drawvalue_address1, value1);
        Process::Read32(drawvalue_address2 - 0x00000004, value2);
        Process::Read32(drawvalue_address3 + 0x00000004, value3);
        scr.Draw(Utils::Format("%x : %x", drawvalue_address2, value2), 10, 100);
        scr.Draw(Color::Green << Utils::Format("%x : %x", drawvalue_address1, value1), 10, 110);
        scr.Draw(Utils::Format("%x : %x", drawvalue_address3, value3), 10, 120);
        OSDManager.Unlock();
    }*/

    void PointerCodeAddress(MenuEntry *entry)
    {
        u32 baseaddress, add_value, basevalue, address;
        Keyboard keyboard("ベースアドレスを入力してください");
        if (keyboard.Open(baseaddress) != -1) {
            Keyboard keyboard("加算値を入力してください");
            if (keyboard.Open(add_value) != -1) {
                Process::Read32(baseaddress, basevalue);
                address = basevalue + add_value;
                MessageBox(Utils::Format("%x", address))();
            }
        }
    }
}