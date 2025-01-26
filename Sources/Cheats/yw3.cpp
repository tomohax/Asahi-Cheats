//TITLE: 妖怪ウォッチ3 スシ
//TITLEID: 0004000000191000
//PROCESSNAME: YW3
//TITLE: 妖怪ウォッチ3 テンプラ
//TITLEID: 0004000000191100
//PROCESSNAME: YW3
//TITLE: 妖怪ウォッチ3 スキヤキ
//TITLEID: 00040000001AF400
//PROCESSNAME: YW3

/* OLD NEW変換表
OLD: 08000000 = NEW: 0BC00000
OLD: 08100000 = NEW: 0BD00000
OLD: 08200000 = NEW: 0BE00000
OLD: 08300000 = NEW: 0BF00000
OLD: 08400000 = NEW: 0C000000
OLD: 08500000 = NEW: 0C100000
OLD: 08600000 = NEW: 0C200000
OLD: 08700000 = NEW: 0C300000
OLD: 08800000 = NEW: 0C400000
OLD: 08900000 = NEW: 0C500000
OLD: 08A00000 = NEW: 0C600000
OLD: 08B00000 = NEW: 0C700000
OLD: 08C00000 = NEW: 0C800000
OLD: 08D00000 = NEW: 0C900000
OLD: 08E00000 = NEW: 0CA00000
*/

#include <cheats.hpp>

namespace	CTRPluginFramework
{
    static StringVector items_yw3(200);

	bool IsSukiyaki()
    {
        if (Process::GetTitleID() == 0x00040000001AF400) {
            return true;
        }
        else {
            return false;
        }
    }

    void YW3_CoordinateMovement(MenuEntry *entry)
	{
		float coord_x, coord_y;
        if (IsSukiyaki()) {
            if (IsNew3DS()) {
                if (Controller::IsKeysDown(entry->Hotkeys[0].GetKeys())) {
                    Process::ReadFloat(0x0C4F09C4, coord_x);
                    coord_x = coord_x - 5;
                    Process::WriteFloat(0x0C4F09C4, coord_x);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys())) {
                    Process::ReadFloat(0x0C4F09C4, coord_x);
                    coord_x = coord_x + 5;
                    Process::WriteFloat(0x0C4F09C4, coord_x);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[2].GetKeys())) {
                    Process::ReadFloat(0x0C4F09BC, coord_y);
                    coord_y = coord_y - 5;
                    Process::WriteFloat(0x0C4F09BC, coord_y);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[3].GetKeys())) {
                    Process::ReadFloat(0x0C4F09BC, coord_y);
                    coord_y = coord_y + 5;
                    Process::WriteFloat(0x0C4F09BC, coord_y);
                }
            }
            else {
                if (Controller::IsKeysDown(entry->Hotkeys[0].GetKeys())) {
                    Process::ReadFloat(0x088F09C4, coord_x);
                    coord_x = coord_x - 5;
                    Process::WriteFloat(0x088F09C4, coord_x);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys())) {
                    Process::ReadFloat(0x088F09C4, coord_x);
                    coord_x = coord_x + 5;
                    Process::WriteFloat(0x088F09C4, coord_x);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[2].GetKeys())) {
                    Process::ReadFloat(0x088F09BC, coord_y);
                    coord_y = coord_y - 5;
                    Process::WriteFloat(0x088F09BC, coord_y);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[3].GetKeys())) {
                    Process::ReadFloat(0x088F09BC, coord_y);
                    coord_y = coord_y + 5;
                    Process::WriteFloat(0x088F09BC, coord_y);
                }
            }
        }
        else {
            if (IsNew3DS()) {
                if (Controller::IsKeysDown(entry->Hotkeys[0].GetKeys())) {
                    Process::ReadFloat(0x0C5004C4, coord_x);
                    coord_x = coord_x - 5;
                    Process::WriteFloat(0x0C5004C4, coord_x);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys())) {
                    Process::ReadFloat(0x0C5004C4, coord_x);
                    coord_x = coord_x + 5;
                    Process::WriteFloat(0x0C5004C4, coord_x);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[2].GetKeys())) {
                    Process::ReadFloat(0x0C5004BC, coord_y);
                    coord_y = coord_y - 5;
                    Process::WriteFloat(0x0C5004BC, coord_y);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[3].GetKeys())) {
                    Process::ReadFloat(0x0C5004BC, coord_y);
                    coord_y = coord_y + 5;
                    Process::WriteFloat(0x0C5004BC, coord_y);
                }
            }
            else {
                if (Controller::IsKeysDown(entry->Hotkeys[0].GetKeys())) {
                    Process::ReadFloat(0x089004C4, coord_x);
                    coord_x = coord_x - 5;
                    Process::WriteFloat(0x089004C4, coord_x);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys())) {
                    Process::ReadFloat(0x089004C4, coord_x);
                    coord_x = coord_x + 5;
                    Process::WriteFloat(0x089004C4, coord_x);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[2].GetKeys())) {
                    Process::ReadFloat(0x089004BC, coord_y);
                    coord_y = coord_y - 5;
                    Process::WriteFloat(0x089004BC, coord_y);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[3].GetKeys())) {
                    Process::ReadFloat(0x089004BC, coord_y);
                    coord_y = coord_y + 5;
                    Process::WriteFloat(0x089004BC, coord_y);
                }
            }
        }
	}

    void YW3_MoonJump(MenuEntry *entry)
	{
		float coord_z;
        if (IsSukiyaki()) {
            if (IsNew3DS()) {
                if (Controller::IsKeysDown(entry->Hotkeys[0].GetKeys())) {
                    Process::ReadFloat(0x0C4F09C0, coord_z);
                    coord_z = coord_z + 5;
                    Process::WriteFloat(0x0C4F09C0, coord_z);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys())) {
                    Process::ReadFloat(0x0C4F09C0, coord_z);
                    coord_z = coord_z - 5;
                    Process::WriteFloat(0x0C4F09C0, coord_z);
                }
            }
            else {
                if (Controller::IsKeysDown(entry->Hotkeys[0].GetKeys())) {
                    Process::ReadFloat(0x088F09C0, coord_z);
                    coord_z = coord_z + 5;
                    Process::WriteFloat(0x088F09C0, coord_z);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys())) {
                    Process::ReadFloat(0x088F09C0, coord_z);
                    coord_z = coord_z - 5;
                    Process::WriteFloat(0x088F09C0, coord_z);
                }
            }
        }
        else {
            if (IsNew3DS()) {
                if (Controller::IsKeysDown(entry->Hotkeys[0].GetKeys())) {
                    Process::ReadFloat(0x0C5004C0, coord_z);
                    coord_z = coord_z + 5;
                    Process::WriteFloat(0x0C5004C0, coord_z);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys())) {
                    Process::ReadFloat(0x0C5004C0, coord_z);
                    coord_z = coord_z - 5;
                    Process::WriteFloat(0x0C5004C0, coord_z);
                }
            }
            else {
                if (Controller::IsKeysDown(entry->Hotkeys[0].GetKeys())) {
                    Process::ReadFloat(0x089004C0, coord_z);
                    coord_z = coord_z + 5;
                    Process::WriteFloat(0x089004C0, coord_z);
                }
                if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys())) {
                    Process::ReadFloat(0x089004C0, coord_z);
                    coord_z = coord_z - 5;
                    Process::WriteFloat(0x089004C0, coord_z);
                }
            }
        }
	}

    void YW3_SpeedHack(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x003C8F38, 0x40400000);
        }
        else {
            Process::Write32(0x003C8F38, 0x3F800000);
        }
    }

    void YW3_WallThrough(MenuEntry *entry)
    {
        static bool mode;
        if (Controller::IsKeysPressed(entry->Hotkeys[0].GetKeys()))
		{
			if (mode)
			{
				mode = false;
				OSD::Notify("Wall Through:Disable");
                Process::Write32(0x00276838, 0xE28D301C);
			    Process::Write32(0x0027683C, 0xE3A09000);
			}
			else {
				mode = true;
				OSD::Notify("Wall Through:Enabled");
				Process::Write32(0x00276838, 0xE24D301C);
			    Process::Write32(0x0027683C, 0xE3A09001);
			}
		}
    }

    void YW3_DamageLimitUnlock_forBattle(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0068F8D8, 0x0000FFFF);
        }
        else {
            Process::Write32(0x0068F8D8, 0x000003E7);
        }
    }

    void YW3_GiveItemFriend_forBattle(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x007D05B0, 0xE1A00000);
            Process::Write32(0x007D05C0, 0xE3A00000);
            Process::Write32(0x007D05C4, 0xE1A00000);
        }
        else {
            Process::Write32(0x007D05B0, 0xE0824201);
            Process::Write32(0x007D05C0, 0xE3A00001);
            Process::Write32(0x007D05C4, 0xEBFA88F8);
        }
    }

    void YW3_MoveNoWait_forBattle(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x007D81B8, 0xEB02DE82);
            Process::Write32(0x0088FBC8, 0xE5D1247E);
            Process::Write32(0x0088FBCC, 0xE3520000);
            Process::Write32(0x0088FBD0, 0x028EE034);
            Process::Write32(0x0088FBD4, 0x012FFF1E);
            Process::Write32(0x0088FBD8, 0xE5912498);
            Process::Write32(0x0088FBDC, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x007D81B8, 0xE5912498);
            Process::Write32(0x0088FBC8, 0x00000000);
            Process::Write32(0x0088FBCC, 0x00000000);
            Process::Write32(0x0088FBD0, 0x00000000);
            Process::Write32(0x0088FBD4, 0x00000000);
            Process::Write32(0x0088FBD8, 0x00000000);
            Process::Write32(0x0088FBDC, 0x00000000);
        }
    }

    void YW3_InfinityHP_forBattle(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x006AAC98, 0xEB0794D2);
            Process::Write32(0x0088FFE8, 0xE5D4547E);
            Process::Write32(0x0088FFEC, 0xE3550000);
            Process::Write32(0x0088FFF0, 0x01D400B2);
            Process::Write32(0x0088FFF4, 0x03A01000);
            Process::Write32(0x0088FFF8, 0xE1D450B6);
            Process::Write32(0x0088FFFC, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x006AAC98, 0xE1D450B6);
            Process::Write32(0x0088FFE8, 0x00000000);
            Process::Write32(0x0088FFEC, 0x00000000);
            Process::Write32(0x0088FFF0, 0x00000000);
            Process::Write32(0x0088FFF4, 0x00000000);
            Process::Write32(0x0088FFF8, 0x00000000);
            Process::Write32(0x0088FFFC, 0x00000000);
        }
    }

    void YW3_InfinityTechnique_forBattle(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x006ABA44, 0xEB079161);
            Process::Write32(0x0088FFD0, 0xE5554082);
            Process::Write32(0x0088FFD4, 0xE3540000);
            Process::Write32(0x0088FFD8, 0x03A00C07);
            Process::Write32(0x0088FFDC, 0xE1C50AB2);
            Process::Write32(0x0088FFE0, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x006ABA44, 0xE1C50AB2);
            Process::Write32(0x0088FFD0, 0x00000000);
            Process::Write32(0x0088FFD4, 0x00000000);
            Process::Write32(0x0088FFD8, 0x00000000);
            Process::Write32(0x0088FFDC, 0x00000000);
            Process::Write32(0x0088FFE0, 0x00000000);
        }
    }

    void YW3_InstantKill_forBattle(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x006AAC9C, 0xEB079412);
            Process::Write32(0x0088FCEC, 0xE5D4947E);
            Process::Write32(0x0088FCF0, 0xE3590000);
            Process::Write32(0x0088FCF4, 0x13A00000);
            Process::Write32(0x0088FCF8, 0xE3A09001);
            Process::Write32(0x0088FCFC, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x006AAC9C, 0xE3A09001);
            Process::Write32(0x0088FCEC, 0x00000000);
            Process::Write32(0x0088FCF0, 0x00000000);
            Process::Write32(0x0088FCF4, 0x00000000);
            Process::Write32(0x0088FCF8, 0x00000000);
            Process::Write32(0x0088FCFC, 0x00000000);
        }
    }

    void YW3_DamageMax_forBattle(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0068F880, 0xEB0B41DE);
            Process::Write32(0x00960000, 0xE6FF0074);
            Process::Write32(0x00960004, 0xE92D4002);
            Process::Write32(0x00960008, 0xE5D5147E);
            Process::Write32(0x0096000C, 0xE3510000);
            Process::Write32(0x00960010, 0x13E00000);
            Process::Write32(0x00960014, 0xE8BD8002);
        }
        else {
            Process::Write32(0x0068F880, 0xE6FF0074);
            Process::Write32(0x00960000, 0x00000000);
            Process::Write32(0x00960004, 0x00000000);
            Process::Write32(0x00960008, 0x00000000);
            Process::Write32(0x0096000C, 0x00000000);
            Process::Write32(0x00960010, 0x00000000);
            Process::Write32(0x00960014, 0x00000000);
        }
    }

    void YW3_AllAvoidance_forBattle(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0068DC70, 0xEB0B48E8);
            Process::Write32(0x00960018, 0xE3A00000);
            Process::Write32(0x0096001C, 0xE92D4002);
            Process::Write32(0x00960020, 0xE5D9147E);
            Process::Write32(0x00960024, 0xE3510000);
            Process::Write32(0x00960028, 0x13A00001);
            Process::Write32(0x0096002C, 0xE8BD8002);
        }
        else {
            Process::Write32(0x0068DC70, 0xE3A00000);
            Process::Write32(0x00960018, 0x00000000);
            Process::Write32(0x0096001C, 0x00000000);
            Process::Write32(0x00960020, 0x00000000);
            Process::Write32(0x00960024, 0x00000000);
            Process::Write32(0x00960028, 0x00000000);
            Process::Write32(0x0096002C, 0x00000000);
        }
    }

    void YW3_TPose(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x008447E8, 0x3A000000);
        }
        else {
            Process::Write32(0x008447E8, 0x40000000);
        }
    }

    void YW3_GameSpeed(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00928A58, 0x40000000);
        }
        else {
            Process::Write32(0x00928A58, 0x3F800000);
        }
    }

    void YW3_MessageThrough(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x001E0940, 0xE35000FF);
        }
        else {
            Process::Write32(0x001E0940, 0xE3500002);
        }
    }

    void YW3_PlayerModel(MenuEntry *entry)
    {
		Keyboard keyboard("プレイヤーモデル変更");
        std::vector < std::string > option =
        {
            "IDを入力して設定", "プロフィールアイコンから設定", "元に戻す"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        u32 model;
        if (userchoice == 0) {
			Keyboard keyboard("プレイヤーモデル変更\nメダル/モデルIDを入力してください。");
			if (keyboard.Open(model) != -1) {
				Process::Write32(0x003F63FC, model);
				Process::Write32(0x003F6400, model);
			}
		}
        if (userchoice == 1) {
            u32 faceicon;
            if (IsNew3DS()) {
                Process::Read32(0x0C32E018, faceicon);
            }
            else {
                Process::Read32(0x0872E018, faceicon);
            }
            Process::Write32(0x003F63FC, faceicon);
			Process::Write32(0x003F6400, faceicon);
        }
		if (userchoice == 2) {
            Process::Write32(0x003F63FC, 0xBD0382AD);
			Process::Write32(0x003F6400, 0x170A4A26);
		}
    }

    void YW3_OtomoModel(MenuEntry *entry)
    {
        Keyboard keyboard("おともモデル変更");
        std::vector < std::string > option =
        {
            "IDを入力して設定", "プロフィールアイコンから設定"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        u32 model;
        if (userchoice == 0) {
			Keyboard keyboard("プレイヤーモデル変更\nメダル/モデルIDを入力してください。");
			if (keyboard.Open(model) != -1) {
				if (IsNew3DS()) {
                    Process::Write32(0x0C31B82C, model);
                }
                else {
                    Process::Write32(0x0871B82C, model);
                }
			}
		}
        if (userchoice == 1) {
            u32 faceicon;
            if (IsNew3DS()) {
                Process::Read32(0x0C32E018, faceicon);
                Process::Write32(0x0C31B82C, faceicon);
            }
            else {
                Process::Read32(0x0872E018, faceicon);
                Process::Write32(0x0871B82C, faceicon);
            }
        }
    }

    void YW3_NameChanger(MenuEntry *entry)
    {
        Keyboard keyboard("名前変更");
        std::vector < std::string > option =
        {
            "ケータ", "イナホ"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        std::string name;
        if (userchoice == 0) {
			Keyboard keyboard("名前変更\nケータ");
			if (keyboard.Open(name) != -1) {
                if (IsNew3DS()) {
                    Process::WriteString(0x0C32693C, name);
                }
                else {
                    Process::WriteString(0x0872693C, name);
                }
			}
		}
		if (userchoice == 1) {
            Keyboard keyboard("名前変更\nイナホ");
			if (keyboard.Open(name) != -1) {
                if (IsNew3DS()) {
                    Process::WriteString(0x0C326954, name);
                }
                else {
                    Process::WriteString(0x08726954, name);
                }
			}
		}
    }

    void YW3_DisableCameraControl(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0070F2B4, 0xE3A010FF);
            Process::Write32(0x0070F2CC, 0xE3A010FF);
            Process::Write32(0x0070F2F8, 0xE3A010FF);
            Process::Write32(0x0070F334, 0xE3A010FF);
            Process::Write32(0x0071282C, 0xE3A010FF);
            Process::Write32(0x00712844, 0xE3A010FF);
            Process::Write32(0x0071289C, 0xE3A010FF);
            Process::Write32(0x007128D0, 0xE3A010FF);
        }
        else {
            Process::Write32(0x0070F2B4, 0xE3A0100A);
            Process::Write32(0x0070F2CC, 0xE3A0100B);
            Process::Write32(0x0070F2F8, 0xE3A0100A);
            Process::Write32(0x0070F334, 0xE3A0100B);
            Process::Write32(0x0071282C, 0xE3A0100A);
            Process::Write32(0x00712844, 0xE3A0100B);
            Process::Write32(0x0071289C, 0xE3A0100A);
            Process::Write32(0x007128D0, 0xE3A0100B);
        }
    }

    void YW3_InstantFishing(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00773CBC, 0xEB046FB5);
            Process::Write32(0x0088FB98, 0xE92D4002);
            Process::Write32(0x0088FB9C, 0xE59F001C);
            Process::Write32(0x0088FBA0, 0xE5141118);
            Process::Write32(0x0088FBA4, 0xE1500001);
            Process::Write32(0x0088FBA8, 0x059F000C);
            Process::Write32(0x0088FBAC, 0x05840004);
            Process::Write32(0x0088FBB0, 0xE3A00001);
            Process::Write32(0x0088FBB4, 0x05040034);
            Process::Write32(0x0088FBB8, 0xE8BD8002);
            Process::Write32(0x0088FBBC, 0x43C80000);
            Process::Write32(0x0088FBC0, 0x5F746365);
        }
        else {
            Process::Write32(0x00773CBC, 0xE3A00001);
            Process::Write32(0x0088FB98, 0x00000000);
            Process::Write32(0x0088FB9C, 0x00000000);
            Process::Write32(0x0088FBA0, 0x00000000);
            Process::Write32(0x0088FBA4, 0x00000000);
            Process::Write32(0x0088FBA8, 0x00000000);
            Process::Write32(0x0088FBAC, 0x00000000);
            Process::Write32(0x0088FBB0, 0x00000000);
            Process::Write32(0x0088FBB4, 0x00000000);
            Process::Write32(0x0088FBB8, 0x00000000);
            Process::Write32(0x0088FBBC, 0x00000000);
            Process::Write32(0x0088FBC0, 0x00000000);
        }
    }

    void YW3_MoneyChanger(MenuEntry *entry)
    {
        Keyboard keyboard("所持金変更");
        std::vector < std::string > option =
        {
            "ケータ", "イナホ"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        u32 money;
        if (userchoice == 0) {
			Keyboard keyboard("所持金変更\nケータ\n16進数で入力してください");
			if (keyboard.Open(money) != -1) {
                if (IsNew3DS()) {
                    Process::Write32(0x0C31B55C, money);
                }
                else {
                    Process::Write32(0x0871B55C, money);
                }
			}
		}
		if (userchoice == 1) {
            Keyboard keyboard("所持金変更\nイナホ\n16進数で入力してください");
			if (keyboard.Open(money) != -1) {
                if (IsNew3DS()) {
                    Process::Write32(0x0C31C2C8, money);
                }
                else {
                    Process::Write32(0x0871C2C8, money);
                }
			}
		}
    }

    void YW3_DokodemoError(MenuEntry *entry)
    {
        Process::Write32(0x00245418, 0xE1D101B0);
        Process::Write32(0x00245430, 0xE5D400F2);
        Process::Write32(0x00245454, 0xE1D510B0);
        if (Controller::IsKeysDown(R)) {
            Process::Write32(0x00245418, 0xE1C101B0);
            Process::Write32(0x00245430, 0xE5C400F2);
            Process::Write32(0x00245454, 0xE1C510B0);
        }
    }

    void YW3_InvisibleInRoom(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x002451C8, 0xE89D0440);
        }
        else {
            Process::Write32(0x002451C8, 0xE88D0440);
        }
    }

    void YW3_NoKick(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00245774, 0xE3A00000);
        }
        else {
            Process::Write32(0x00245774, 0xE58E2668);
        }
    }

    void YW3_InRoomError(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x002864C8, 0xE1A00000);
        }
        else {
            Process::Write32(0x002864C8, 0xEB1403DE);
        }
    }

    void YW3_InRoomErrorDisable(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0024582C, 0xE1A00000);
            Process::Write32(0x0024583C, 0xE1A00000);
        }
        else {
            Process::Write32(0x0024582C, 0xE5923000);
            Process::Write32(0x0024583C, 0xE5821000);
        }
    }

    void YW3_GetKickPermission(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x001FED30, 0x13A00001);
        }
        else {
            Process::Write32(0x001FED30, 0x13A00000);
        }
    }

    void YW3_RapidChat(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x001DEBF4, 0xEA000005);
        }
        else {
            Process::Write32(0x001DEBF4, 0x0A000005);
        }
    }

    void YW3_InstantFriendChance_forTBusters(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00458B6C, 0xE3A00001);
        }
        else {
            Process::Write32(0x00458B6C, 0xEB0D4F06);
        }
    }

    void YW3_InfHissatuTech_forTBusters(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00477D88, 0xE1A00000);
        }
        else {
            Process::Write32(0x00477D88, 0xBA000011);
        }
    }

    void YW3_SkillNoCooldown(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00481748, 0xE3A00001);
        }
        else {
            Process::Write32(0x00481748, 0xEB0C9B0B);
        }
    }

    void YW3_CustomCombo(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00481840, 0xE3A03001);
        }
        else {
            Process::Write32(0x00481840, 0xE59D312C);
        }
    }

    void YW3_RapidABXY(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x004AAC08, 0xEB0D255C);
            Process::Write32(0x004AAC38, 0xEB0D2550);
            Process::Write32(0x004AAC5C, 0xEB0D2547);
            Process::Write32(0x004AAC8C, 0xEB0D253B);
        }
        else {
            Process::Write32(0x004AAC08, 0xEB0D2575);
            Process::Write32(0x004AAC38, 0xEB0D2569);
            Process::Write32(0x004AAC5C, 0xEB0D2560);
            Process::Write32(0x004AAC8C, 0xEB0D2554);
        }
    }

    void YW3_InstantKill_forTBusters(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x004525A8, 0xEB10F5C0);
            Process::Write32(0x0088FCB0, 0xE92D000C);
            Process::Write32(0x0088FCB4, 0xE5972078);
            Process::Write32(0x0088FCB8, 0xE2873A01);
            Process::Write32(0x0088FCBC, 0xE5D335A0);
            Process::Write32(0x0088FCC0, 0xE3520000);
            Process::Write32(0x0088FCC4, 0x1A000001);
            Process::Write32(0x0088FCC8, 0xE3530000);
            Process::Write32(0x0088FCCC, 0x13A00201);
            Process::Write32(0x0088FCD0, 0xE8BD000C);
            Process::Write32(0x0088FCD4, 0xE31100F0);
            Process::Write32(0x0088FCD8, 0xE58D0074);
            Process::Write32(0x0088FCDC, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x004525A8, 0xE58D0074);
            Process::Write32(0x0088FCB0, 0x00000000);
            Process::Write32(0x0088FCB4, 0x00000000);
            Process::Write32(0x0088FCB8, 0x00000000);
            Process::Write32(0x0088FCBC, 0x00000000);
            Process::Write32(0x0088FCC0, 0x00000000);
            Process::Write32(0x0088FCC4, 0x00000000);
            Process::Write32(0x0088FCC8, 0x00000000);
            Process::Write32(0x0088FCCC, 0x00000000);
            Process::Write32(0x0088FCD0, 0x00000000);
            Process::Write32(0x0088FCD4, 0x00000000);
            Process::Write32(0x0088FCD8, 0x00000000);
            Process::Write32(0x0088FCDC, 0x00000000);
        }
    }

    void YW3_InfHP_forTBusters(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00452764, 0xEB10F607);
            Process::Write32(0x0088FF88, 0xE5992078);
            Process::Write32(0x0088FF8C, 0xE3520000);
            Process::Write32(0x0088FF90, 0x15992074);
            Process::Write32(0x0088FF94, 0x15802578);
            Process::Write32(0x0088FF98, 0xE5901578);
            Process::Write32(0x0088FF9C, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x00452764, 0xE5901578);
            Process::Write32(0x0088FF88, 0x00000000);
            Process::Write32(0x0088FF8C, 0x00000000);
            Process::Write32(0x0088FF90, 0x00000000);
            Process::Write32(0x0088FF94, 0x00000000);
            Process::Write32(0x0088FF98, 0x00000000);
            Process::Write32(0x0088FF9C, 0x00000000);
        }
    }

    void YW3_3RenzokuAttack(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0049628C, 0xEB0FE745);
            Process::Write32(0x0088FFA8, 0xE92D4002);
            Process::Write32(0x0088FFAC, 0xEBFC8AB8);
            Process::Write32(0x0088FFB0, 0xE3500000);
            Process::Write32(0x0088FFB4, 0x18BD8002);
            Process::Write32(0x0088FFB8, 0xE5890C7C);
            Process::Write32(0x0088FFBC, 0xE59D1004);
            Process::Write32(0x0088FFC0, 0xE2411014);
            Process::Write32(0x0088FFC4, 0xE58D1004);
            Process::Write32(0x0088FFC8, 0xE8BD8002);
        }
        else {
            Process::Write32(0x0049628C, 0xEB0C7200);
            Process::Write32(0x0088FFA8, 0x00000000);
            Process::Write32(0x0088FFAC, 0x00000000);
            Process::Write32(0x0088FFB0, 0x00000000);
            Process::Write32(0x0088FFB4, 0x00000000);
            Process::Write32(0x0088FFB8, 0x00000000);
            Process::Write32(0x0088FFBC, 0x00000000);
            Process::Write32(0x0088FFC0, 0x00000000);
            Process::Write32(0x0088FFC4, 0x00000000);
            Process::Write32(0x0088FFC8, 0x00000000);
        }
    }

    void YW3_InfHP_forZombie(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x004525A4, 0xEB10F5DB);
            Process::Write32(0x0088FD18, 0xE92D000C);
            Process::Write32(0x0088FD1C, 0xE5972078);
            Process::Write32(0x0088FD20, 0xE2873A01);
            Process::Write32(0x0088FD24, 0xE5D335A0);
            Process::Write32(0x0088FD28, 0xE3520000);
            Process::Write32(0x0088FD2C, 0x03530000);
            Process::Write32(0x0088FD30, 0x03A00000);
            Process::Write32(0x0088FD34, 0xE8BD000C);
            Process::Write32(0x0088FD38, 0xE31100F0);
            Process::Write32(0x0088FD3C, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x004525A4, 0xE31100F0);
            Process::Write32(0x0088FD18, 0x00000000);
            Process::Write32(0x0088FD1C, 0x00000000);
            Process::Write32(0x0088FD20, 0x00000000);
            Process::Write32(0x0088FD24, 0x00000000);
            Process::Write32(0x0088FD28, 0x00000000);
            Process::Write32(0x0088FD2C, 0x00000000);
            Process::Write32(0x0088FD30, 0x00000000);
            Process::Write32(0x0088FD34, 0x00000000);
            Process::Write32(0x0088FD38, 0x00000000);
            Process::Write32(0x0088FD3C, 0x00000000);
        }
    }

    void YW3_InfStamina(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x006E0E9C, 0xED801A03);
        }
        else {
            Process::Write32(0x006E0E9C, 0xDD801A03);
        }
    }

    static u32 modelcolor_red = 0x3F800000, modelcolor_green = 0x3F800000, modelcolor_blue = 0x3F800000;

    void YW3_ModelColorSettings(MenuEntry *entry)
    {
        Keyboard keyboard("モデル着色\n赤の値を入力してください\nデフォルト:3F800000");
        if (keyboard.Open(modelcolor_red) != -1) {
            Keyboard keyboard("モデル着色\n緑の値を入力してください\nデフォルト:3F800000");
            if (keyboard.Open(modelcolor_green) != -1) {
                Keyboard keyboard("モデル着色\n青の値を入力してください\nデフォルト:3F800000");
                if (keyboard.Open(modelcolor_blue) != -1) {
                    MessageBox(Utils::Format("赤:%f\n緑:%f\n青:%f", modelcolor_red, modelcolor_green, modelcolor_blue))();
                }
            }
        }
    }

    void YW3_ModelColor(MenuEntry *entry)
    {
        Process::WriteFloat(0x3049A128, modelcolor_red);
        Process::WriteFloat(0x3049A12C, modelcolor_green);
        Process::WriteFloat(0x3049A130, modelcolor_blue);
    }

    void YW3_DokodemoSave(MenuEntry *entry)
    {
        if (IsNew3DS()) {
            Process::Write32(0x0C3264D8, 0x00000000);
        }
        else {
            Process::Write32(0x087264D8, 0x00000000);
        }
    }

    void YW3_LRSeigenUnlock(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            if (IsNew3DS()) {
                PointerWrite32(0x0C9DAB5C, 0x6F8, 0xCF490FDB);
                PointerWrite32(0x0C9DAB5C, 0x6FC, 0x4F490FDB);
            }
            else {
                PointerWrite32(0x08DDAB5C, 0x6F8, 0xCF490FDB);
                PointerWrite32(0x08DDAB5C, 0x6FC, 0x4F490FDB);
            }
        }
        else {
            if (IsNew3DS()) {
                PointerWrite32(0x0C9DAB5C, 0x6F8, 0xBF490FDB);
                PointerWrite32(0x0C9DAB5C, 0x6FC, 0x3F490FDB);
            }
            else {
                PointerWrite32(0x08DDAB5C, 0x6F8, 0xBF490FDB);
                PointerWrite32(0x08DDAB5C, 0x6FC, 0x3F490FDB);
            }
        }
    }

    void YW3_MapEvent(MenuEntry *entry)
    {
        Keyboard keyboard("マップイベント実行");
        std::vector < std::string > option =
        {
            "Tバスターズ", "鬼時間", "ゾンビナイト", "解除"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
			if (IsNew3DS()) {
                Process::Write32(0x0C3264DC, 0x00000010);
            }
            else {
                Process::Write32(0x087264DC, 0x00000010);
            }
		}
        if (userchoice == 1) {
			if (IsNew3DS()) {
                Process::Write32(0x0C3264DC, 0x00000040);
            }
            else {
                Process::Write32(0x087264DC, 0x00000040);
            }
		}
        if (userchoice == 2) {
			if (IsNew3DS()) {
                Process::Write32(0x0C3264DC, 0x00000080);
            }
            else {
                Process::Write32(0x087264DC, 0x00000080);
            }
		}
        if (userchoice == 3) {
			if (IsNew3DS()) {
                Process::Write32(0x0C3264DC, 0x0000000);
            }
            else {
                Process::Write32(0x087264DC, 0x0000000);
            }
		}
    }

    void YW3_CleanerRobotEnd(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x005492D0, 0xE3A01000);
            Process::Write32(0x005492D4, 0xE5841008);
            Process::Write32(0x00549338, 0xE3A01000);
            Process::Write32(0x0054933C, 0xE5841008);
            Process::Write32(0x00549340, 0xEAFFFFE4);
        }
        else {
            Process::Write32(0x005492D0, 0xE1510000);
            Process::Write32(0x005492D4, 0x8A000020);
            Process::Write32(0x00549338, 0xE5941008);
            Process::Write32(0x0054933C, 0xE1510005);
            Process::Write32(0x00549340, 0x9AFFFFE4);
        }
    }

    void YW3_MyNyanTrainingEnd(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x074648C, 0xEA000005);
            Process::Write32(0x0746728, 0xE1A00003);
        }
        else {
            Process::Write32(0x074648C, 0x3A000005);
            Process::Write32(0x0746728, 0x81A00003);
        }
    }

    void YW3_KuruKuru(MenuEntry *entry)
    {
        float value;
        Process::ReadFloat(0x0889CD78, value);
        value = value + 1;
        Process::WriteFloat(0x0889CD78, value);
    }

    static u32 worldcolor_red = 0x3F800000, worldcolor_green = 0x3F800000, worldcolor_blue = 0x3F800000;

    void YW3_WorldColorSettings(MenuEntry *entry)
    {
        Keyboard keyboard("ワールド着色\n赤の値を入力してください\nデフォルト:3F800000");
        if (keyboard.Open(worldcolor_red) != -1) {
            Keyboard keyboard("ワールド着色\n緑の値を入力してください\nデフォルト:3F800000");
            if (keyboard.Open(worldcolor_green) != -1) {
                Keyboard keyboard("ワールド着色\n青の値を入力してください\nデフォルト:3F800000");
                if (keyboard.Open(worldcolor_blue) != -1) {
                    MessageBox(Utils::Format("赤:%x\n緑:%x\n青:%x", worldcolor_red, worldcolor_green, worldcolor_blue))();
                }
            }
        }
    }

    void YW3_WorldColor(MenuEntry *entry)
    {
        if (IsNew3DS()) {
            Process::Write32(0x0C4E7210, worldcolor_red);
            Process::Write32(0x0C4E7214, worldcolor_green);
            Process::Write32(0x0C4E7218, worldcolor_blue);
            Process::Write32(0x0C4E721C, worldcolor_red);
            Process::Write32(0x0C4E7220, worldcolor_green);
            Process::Write32(0x0C4E7224, worldcolor_blue);
        }
        else {
            Process::Write32(0x088E7210, worldcolor_red);
            Process::Write32(0x088E7214, worldcolor_green);
            Process::Write32(0x088E7218, worldcolor_blue);
            Process::Write32(0x088E721C, worldcolor_red);
            Process::Write32(0x088E7220, worldcolor_green);
            Process::Write32(0x088E7224, worldcolor_blue);
        }
    }

    void YW3_YokaiEditor(MenuEntry *entry)
    {
        u16 storage_id;
		u32 storage_address, check_storage;
        int choice, yokaiedit_flag_1, yokaiedit_flag_2;
        Keyboard keyboard("妖怪エディタ\n統合後はケータを選択してください。", {"ケータ", "イナホ"});
        choice = keyboard.Open();
        if (choice != -1) {
            yokaiedit_flag_1 = choice;
        }
        Keyboard keyboard2("妖怪エディタ\n編集する妖怪を選択してください。", {"手持ち妖怪1", "手持ち妖怪2", "手持ち妖怪3", "手持ち妖怪4", "手持ち妖怪5", "手持ち妖怪6"});
        choice = keyboard2.Open();
        if (choice != -1) {
            yokaiedit_flag_2 = choice;
        }
        if (yokaiedit_flag_1 == 0) {
            if (yokaiedit_flag_2 == 0) {
                if (IsNew3DS()) {
                    storage_address = 0x0C31B84C;
                }
                else {
                    storage_address = 0x0871B84C;
                }
            }
            if (yokaiedit_flag_2 == 1) {
                if (IsNew3DS()) {
                    storage_address = 0x0C31B850;
                }
                else {
                    storage_address = 0x0871B850;
                }
            }
            if (yokaiedit_flag_2 == 2) {
                if (IsNew3DS()) {
                    storage_address = 0x0C31B854;
                }
                else {
                    storage_address = 0x0871B854;
                }
            }
            if (yokaiedit_flag_2 == 3) {
                if (IsNew3DS()) {
                    storage_address = 0x0C31B858;
                }
                else {
                    storage_address = 0x0871B858;
                }
            if (yokaiedit_flag_2 == 4) {
                if (IsNew3DS()) {
                    storage_address = 0x0C31B85C;
                }
                else {
                    storage_address = 0x0871B85C;
                }
            }
            if (yokaiedit_flag_2 == 5) {
                if (IsNew3DS()) {
                    storage_address = 0x0C31B860;
                }
                else {
                    storage_address = 0x0871B860;
                }
            }
        }
        if (yokaiedit_flag_1 == 1) {
            if (yokaiedit_flag_2 == 0) {
                if (IsNew3DS()) {
                    storage_address = 0x0C31C5B8;
                }
                else {
                    storage_address = 0x0871C5B8;
                }
            }
            if (yokaiedit_flag_2 == 1) {
                if (IsNew3DS()) {
                    storage_address = 0x0C31C5BC;
                }
                else {
                    storage_address = 0x0871C5BC;
                }
            }
            if (yokaiedit_flag_2 == 2) {
                if (IsNew3DS()) {
                    storage_address = 0x0C31C5C0;
                }
                else {
                    storage_address = 0x0871C5C0;
                }
            }
            if (yokaiedit_flag_2 == 3) {
                if (IsNew3DS()) {
                    storage_address = 0x0C31C5C4;
                }
                else {
                    storage_address = 0x0871C5C4;
                }
            }
            if (yokaiedit_flag_2 == 4) {
                if (IsNew3DS()) {
                    storage_address = 0x0C31C5C8;
                }
                else {
                    storage_address = 0x0871C5C8;
                }
            }
            if (yokaiedit_flag_2 == 5) {
                if (IsNew3DS()) {
                    storage_address = 0x0C31C5CC;
                }
                else {
                    storage_address = 0x0871C5CC;
                }
            }
        }
		Process::Read32(storage_address, check_storage);
		if (check_storage == 0x00000000) {
			MessageBox("妖怪をセットしてから実行して下さい。")();
			return;
		}
		else {
			Process::Read16(storage_address, storage_id);
		}
		u32 difference = storage_id * 0xBC;
        Keyboard keyboard3("妖怪エディタ\n編集する項目を選択してください。", {"妖怪変更", "HP変更", "レベル変更", "力変更", "妖力変更", "守り変更", "素早さ変更"});
        int userchoice = keyboard3.Open();
        u32 address;
        if (userchoice == 0) {
            u32 value;
            Keyboard keyboard("妖怪変更\n妖怪IDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (IsNew3DS()) {
                    address = 0x0C2F9FBC + difference;
                }
                else {
                    address = 0x086F9FBC + difference;
                }
                Process::Write32(address, value);
            }
		}
        if (userchoice == 1) {
            u16 value;
            Keyboard keyboard("HP変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (IsNew3DS()) {
                    address = 0x0C2F9FE4 + difference;
                    Process::Write16(address, value);
                    address = 0x0C2FA010 + difference;
                    Process::Write16(address, value);
                }
                else {
                    address = 0x086F9FE4 + difference;
                    Process::Write16(address, value);
                    address = 0x086FA010 + difference;
                    Process::Write16(address, value);
                }
            }
		}
        if (userchoice == 2) {
            u8 value;
            Keyboard keyboard("レベル変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (IsNew3DS()) {
                    address = 0x0C2FA001 + difference;
                }
                else {
                    address = 0x086FA001 + difference;
                }
                Process::Write8(address, value);
            }
		}
        if (userchoice == 3) {
            u16 value;
            Keyboard keyboard("力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (IsNew3DS()) {
                    address = 0x0C2FA012 + difference;
                }
                else {
                    address = 0x086FA012 + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 4) {
            u16 value;
            Keyboard keyboard("妖力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (IsNew3DS()) {
                    address = 0x0C2FA014 + difference;
                }
                else {
                    address = 0x086FA014 + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 5) {
            u16 value;
            Keyboard keyboard("守り変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (IsNew3DS()) {
                    address = 0x0C2FA016 + difference;
                }
                else {
                    address = 0x086FA016 + difference;
                }
                Process::Write16(address, value);
            }
		}
		if (userchoice == 6) {
            u16 value;
            Keyboard keyboard("素早さ変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (IsNew3DS()) {
                    address = 0x0C2FA018 + difference;
                }
                else {
                    address = 0x086FA018 + difference;
                }
                Process::Write16(address, value);
            }
		}
        }
    }

    void YW3_InstantYokaiCatch(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x001EB6C8, 0xEB1A918C);
            Process::Write32(0x0088FD00, 0xE1A05000);
            Process::Write32(0x0088FD04, 0xE3530008);
            Process::Write32(0x0088FD08, 0x03A05000);
            Process::Write32(0x0088FD0C, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x001EB6C8, 0xE1A05000);
            Process::Write32(0x0088FD00, 0x00000000);
            Process::Write32(0x0088FD04, 0x00000000);
            Process::Write32(0x0088FD08, 0x00000000);
            Process::Write32(0x0088FD0C, 0x00000000);
        }
    }

    void YW3_BossYokaiSave(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x003D637C, 0xE3A00000);
        }
        else {
            Process::Write32(0x003D637C, 0xEB0CAA59);
        }
    }

    void YW3_BossYokaiBattle(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x007A669C, 0xE3A00000);
        }
        else {
            Process::Write32(0x007A669C, 0xE3A00001);
        }
    }

    void YW3_InstantKill_forZombieNight(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x004525A8, 0xEB10F5C0);
            Process::Write32(0x0088FCB0, 0xE92D000C);
            Process::Write32(0x0088FCB4, 0xE5972078);
            Process::Write32(0x0088FCB8, 0xE2873A01);
            Process::Write32(0x0088FCBC, 0xE5D335A0);
            Process::Write32(0x0088FCC0, 0xE3520000);
            Process::Write32(0x0088FCC4, 0x1A000001);
            Process::Write32(0x0088FCC8, 0xE3530000);
            Process::Write32(0x0088FCCC, 0x13A00201);
            Process::Write32(0x0088FCD0, 0xE8BD000C);
            Process::Write32(0x0088FCD4, 0xE31100F0);
            Process::Write32(0x0088FCD8, 0xE58D0074);
            Process::Write32(0x0088FCDC, 0xE12FFF1E);

        }
        else {
            Process::Write32(0x004525A8, 0xE58D0074);
            Process::Write32(0x0088FCB0, 0x00000000);
            Process::Write32(0x0088FCB4, 0x00000000);
            Process::Write32(0x0088FCB8, 0x00000000);
            Process::Write32(0x0088FCBC, 0x00000000);
            Process::Write32(0x0088FCC0, 0x00000000);
            Process::Write32(0x0088FCC4, 0x00000000);
            Process::Write32(0x0088FCC8, 0x00000000);
            Process::Write32(0x0088FCCC, 0x00000000);
            Process::Write32(0x0088FCD0, 0x00000000);
            Process::Write32(0x0088FCD4, 0x00000000);
            Process::Write32(0x0088FCD8, 0x00000000);
            Process::Write32(0x0088FCDC, 0x00000000);
        }
    }

    void YW3_UngaiFlag(MenuEntry *entry)
	{
		Keyboard keyboard("うんがい鏡フラグ編集");
        std::vector < std::string > option =
        {
            "全発見", "未発見"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
		if (userchoice == 0)
		{
            if (IsNew3DS()) {
                Process::Write32(0x0C3258E8, 0xFFFFFFFF);
                Process::Write32(0x0C3258EC, 0xFFFFFFFF);
                Process::Write32(0x0C3258F0, 0xFFFFFFFF);
            }
            else {
                Process::Write32(0x087258E8, 0xFFFFFFFF);
                Process::Write32(0x087258EC, 0xFFFFFFFF);
                Process::Write32(0x087258F0, 0xFFFFFFFF);
            }
		}
        if (userchoice == 1)
		{
            if (IsNew3DS()) {
                Process::Write32(0x0C3258E8, 0x00000000);
                Process::Write32(0x0C3258EC, 0x00000000);
                Process::Write32(0x0C3258F0, 0x00000000);
            }
            else {
                Process::Write32(0x087258E8, 0x00000000);
                Process::Write32(0x087258EC, 0x00000000);
                Process::Write32(0x087258F0, 0x00000000);
            }
		}
	}

    void YW3_DaijitenFlag(MenuEntry *entry)
	{
		Keyboard keyboard("妖怪大辞典フラグ編集");
        std::vector < std::string > option =
        {
            "コンプリート", "発見", "未発見"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
		if (userchoice == 0)
		{
            if (IsNew3DS()) {
                Process::Write32(0x0C3263A8, 0xFFFFFFFF);
                Process::Write32(0x0C3263AC, 0xFFFFFFFF);
                Process::Write32(0x0C3263B0, 0xFFFFFFFF);
                Process::Write32(0x0C3263B4, 0xFFFFFFFF);
                Process::Write32(0x0C3263B8, 0xFFFFFFFF);
                Process::Write32(0x0C3263BC, 0xFFFFFFFF);
                Process::Write32(0x0C3263C0, 0xFFFFFFFF);
                Process::Write32(0x0C3263C4, 0xFFFFFFFF);
                Process::Write32(0x0C3263C8, 0xFFFFFFFF);
                Process::Write32(0x0C3263CC, 0xFFFFFFFF);
                Process::Write32(0x0C3263D0, 0xFFFFFFFF);
                Process::Write32(0x0C3263D4, 0xFFFFFFFF);
                Process::Write32(0x0C3263D8, 0xFFFFFFFF);
                Process::Write32(0x0C3263D8, 0xFFFFFFFF);
                Process::Write32(0x0C3263DC, 0xFFFFFFFF);
                Process::Write32(0x0C3263E0, 0xFFFFFFFF);
                Process::Write32(0x0C3263E4, 0xFFFFFFFF);
                Process::Write32(0x0C3263E8, 0xFFFFFFFF);
                Process::Write32(0x0C3263EC, 0xFFFFFFFF);
                Process::Write32(0x0C3263F0, 0xFFFFFFFF);
                Process::Write32(0x0C3263F4, 0xFFFFFFFF);
                Process::Write32(0x0C3263F8, 0xFFFFFFFF);
                Process::Write32(0x0C3263FC, 0xFFFFFFFF);
                Process::Write32(0x0C326418, 0xFFFFFFFF);
                Process::Write32(0x0C32641C, 0xFFFFFFFF);
                Process::Write32(0x0C326328, 0xFFFFFFFF);
                Process::Write32(0x0C32632C, 0xFFFFFFFF);
                Process::Write32(0x0C326330, 0xFFFFFFFF);
                Process::Write32(0x0C326334, 0xFFFFFFFF);
                Process::Write32(0x0C326338, 0xFFFFFFFF);
                Process::Write32(0x0C32633C, 0xFFFFFFFF);
                Process::Write32(0x0C326340, 0xFFFFFFFF);
                Process::Write32(0x0C326344, 0xFFFFFFFF);
                Process::Write32(0x0C326348, 0xFFFFFFFF);
                Process::Write32(0x0C32634C, 0xFFFFFFFF);
                Process::Write32(0x0C326350, 0xFFFFFFFF);
                Process::Write32(0x0C326354, 0xFFFFFFFF);
                Process::Write32(0x0C326358, 0xFFFFFFFF);
                Process::Write32(0x0C32635C, 0xFFFFFFFF);
                Process::Write32(0x0C326360, 0xFFFFFFFF);
                Process::Write32(0x0C326364, 0xFFFFFFFF);
                Process::Write32(0x0C326368, 0xFFFFFFFF);
                Process::Write32(0x0C32636C, 0xFFFFFFFF);
                Process::Write32(0x0C326370, 0xFFFFFFFF);
                Process::Write32(0x0C326374, 0xFFFFFFFF);
                Process::Write32(0x0C326378, 0xFFFFFFFF);
                Process::Write32(0x0C32637C, 0xFFFFFFFF);
                Process::Write32(0x0C326398, 0xFFFFFFFF);
                Process::Write32(0x0C32639C, 0xFFFFFFFF);
            }
            else {
                Process::Write32(0x087263A8, 0xFFFFFFFF);
                Process::Write32(0x087263AC, 0xFFFFFFFF);
                Process::Write32(0x087263B0, 0xFFFFFFFF);
                Process::Write32(0x087263B4, 0xFFFFFFFF);
                Process::Write32(0x087263B8, 0xFFFFFFFF);
                Process::Write32(0x087263BC, 0xFFFFFFFF);
                Process::Write32(0x087263C0, 0xFFFFFFFF);
                Process::Write32(0x087263C4, 0xFFFFFFFF);
                Process::Write32(0x087263C8, 0xFFFFFFFF);
                Process::Write32(0x087263CC, 0xFFFFFFFF);
                Process::Write32(0x087263D0, 0xFFFFFFFF);
                Process::Write32(0x087263D4, 0xFFFFFFFF);
                Process::Write32(0x087263D8, 0xFFFFFFFF);
                Process::Write32(0x087263D8, 0xFFFFFFFF);
                Process::Write32(0x087263DC, 0xFFFFFFFF);
                Process::Write32(0x087263E0, 0xFFFFFFFF);
                Process::Write32(0x087263E4, 0xFFFFFFFF);
                Process::Write32(0x087263E8, 0xFFFFFFFF);
                Process::Write32(0x087263EC, 0xFFFFFFFF);
                Process::Write32(0x087263F0, 0xFFFFFFFF);
                Process::Write32(0x087263F4, 0xFFFFFFFF);
                Process::Write32(0x087263F8, 0xFFFFFFFF);
                Process::Write32(0x087263FC, 0xFFFFFFFF);
                Process::Write32(0x08726418, 0xFFFFFFFF);
                Process::Write32(0x0872641C, 0xFFFFFFFF);
                Process::Write32(0x08726328, 0xFFFFFFFF);
                Process::Write32(0x0872632C, 0xFFFFFFFF);
                Process::Write32(0x08726330, 0xFFFFFFFF);
                Process::Write32(0x08726334, 0xFFFFFFFF);
                Process::Write32(0x08726338, 0xFFFFFFFF);
                Process::Write32(0x0872633C, 0xFFFFFFFF);
                Process::Write32(0x08726340, 0xFFFFFFFF);
                Process::Write32(0x08726344, 0xFFFFFFFF);
                Process::Write32(0x08726348, 0xFFFFFFFF);
                Process::Write32(0x0872634C, 0xFFFFFFFF);
                Process::Write32(0x08726350, 0xFFFFFFFF);
                Process::Write32(0x08726354, 0xFFFFFFFF);
                Process::Write32(0x08726358, 0xFFFFFFFF);
                Process::Write32(0x0872635C, 0xFFFFFFFF);
                Process::Write32(0x08726360, 0xFFFFFFFF);
                Process::Write32(0x08726364, 0xFFFFFFFF);
                Process::Write32(0x08726368, 0xFFFFFFFF);
                Process::Write32(0x0872636C, 0xFFFFFFFF);
                Process::Write32(0x08726370, 0xFFFFFFFF);
                Process::Write32(0x08726374, 0xFFFFFFFF);
                Process::Write32(0x08726378, 0xFFFFFFFF);
                Process::Write32(0x0872637C, 0xFFFFFFFF);
                Process::Write32(0x08726398, 0xFFFFFFFF);
                Process::Write32(0x0872639C, 0xFFFFFFFF);
            }
		}
        if (userchoice == 1)
		{
            if (IsNew3DS()) {
                Process::Write32(0x0C3263A8, 0x00000000);
                Process::Write32(0x0C3263AC, 0x00000000);
                Process::Write32(0x0C3263B0, 0x00000000);
                Process::Write32(0x0C3263B4, 0x00000000);
                Process::Write32(0x0C3263B8, 0x00000000);
                Process::Write32(0x0C3263BC, 0x00000000);
                Process::Write32(0x0C3263C0, 0x00000000);
                Process::Write32(0x0C3263C4, 0x00000000);
                Process::Write32(0x0C3263C8, 0x00000000);
                Process::Write32(0x0C3263CC, 0x00000000);
                Process::Write32(0x0C3263D0, 0x00000000);
                Process::Write32(0x0C3263D4, 0x00000000);
                Process::Write32(0x0C3263D8, 0x00000000);
                Process::Write32(0x0C3263D8, 0x00000000);
                Process::Write32(0x0C3263DC, 0x00000000);
                Process::Write32(0x0C3263E0, 0x00000000);
                Process::Write32(0x0C3263E4, 0x00000000);
                Process::Write32(0x0C3263E8, 0x00000000);
                Process::Write32(0x0C3263EC, 0x00000000);
                Process::Write32(0x0C3263F0, 0x00000000);
                Process::Write32(0x0C3263F4, 0x00000000);
                Process::Write32(0x0C3263F8, 0x00000000);
                Process::Write32(0x0C3263FC, 0x00000000);
                Process::Write32(0x0C326418, 0x00000000);
                Process::Write32(0x0C32641C, 0x00000000);
                Process::Write32(0x0C326328, 0xFFFFFFFF);
                Process::Write32(0x0C32632C, 0xFFFFFFFF);
                Process::Write32(0x0C326330, 0xFFFFFFFF);
                Process::Write32(0x0C326334, 0xFFFFFFFF);
                Process::Write32(0x0C326338, 0xFFFFFFFF);
                Process::Write32(0x0C32633C, 0xFFFFFFFF);
                Process::Write32(0x0C326340, 0xFFFFFFFF);
                Process::Write32(0x0C326344, 0xFFFFFFFF);
                Process::Write32(0x0C326348, 0xFFFFFFFF);
                Process::Write32(0x0C32634C, 0xFFFFFFFF);
                Process::Write32(0x0C326350, 0xFFFFFFFF);
                Process::Write32(0x0C326354, 0xFFFFFFFF);
                Process::Write32(0x0C326358, 0xFFFFFFFF);
                Process::Write32(0x0C32635C, 0xFFFFFFFF);
                Process::Write32(0x0C326360, 0xFFFFFFFF);
                Process::Write32(0x0C326364, 0xFFFFFFFF);
                Process::Write32(0x0C326368, 0xFFFFFFFF);
                Process::Write32(0x0C32636C, 0xFFFFFFFF);
                Process::Write32(0x0C326370, 0xFFFFFFFF);
                Process::Write32(0x0C326374, 0xFFFFFFFF);
                Process::Write32(0x0C326378, 0xFFFFFFFF);
                Process::Write32(0x0C32637C, 0xFFFFFFFF);
                Process::Write32(0x0C326398, 0xFFFFFFFF);
                Process::Write32(0x0C32639C, 0xFFFFFFFF);
            }
            else {
                Process::Write32(0x087263A8, 0x00000000);
                Process::Write32(0x087263AC, 0x00000000);
                Process::Write32(0x087263B0, 0x00000000);
                Process::Write32(0x087263B4, 0x00000000);
                Process::Write32(0x087263B8, 0x00000000);
                Process::Write32(0x087263BC, 0x00000000);
                Process::Write32(0x087263C0, 0x00000000);
                Process::Write32(0x087263C4, 0x00000000);
                Process::Write32(0x087263C8, 0x00000000);
                Process::Write32(0x087263CC, 0x00000000);
                Process::Write32(0x087263D0, 0x00000000);
                Process::Write32(0x087263D4, 0x00000000);
                Process::Write32(0x087263D8, 0x00000000);
                Process::Write32(0x087263D8, 0x00000000);
                Process::Write32(0x087263DC, 0x00000000);
                Process::Write32(0x087263E0, 0x00000000);
                Process::Write32(0x087263E4, 0x00000000);
                Process::Write32(0x087263E8, 0x00000000);
                Process::Write32(0x087263EC, 0x00000000);
                Process::Write32(0x087263F0, 0x00000000);
                Process::Write32(0x087263F4, 0x00000000);
                Process::Write32(0x087263F8, 0x00000000);
                Process::Write32(0x087263FC, 0x00000000);
                Process::Write32(0x08726418, 0x00000000);
                Process::Write32(0x0872641C, 0x00000000);
                Process::Write32(0x08726328, 0xFFFFFFFF);
                Process::Write32(0x0872632C, 0xFFFFFFFF);
                Process::Write32(0x08726330, 0xFFFFFFFF);
                Process::Write32(0x08726334, 0xFFFFFFFF);
                Process::Write32(0x08726338, 0xFFFFFFFF);
                Process::Write32(0x0872633C, 0xFFFFFFFF);
                Process::Write32(0x08726340, 0xFFFFFFFF);
                Process::Write32(0x08726344, 0xFFFFFFFF);
                Process::Write32(0x08726348, 0xFFFFFFFF);
                Process::Write32(0x0872634C, 0xFFFFFFFF);
                Process::Write32(0x08726350, 0xFFFFFFFF);
                Process::Write32(0x08726354, 0xFFFFFFFF);
                Process::Write32(0x08726358, 0xFFFFFFFF);
                Process::Write32(0x0872635C, 0xFFFFFFFF);
                Process::Write32(0x08726360, 0xFFFFFFFF);
                Process::Write32(0x08726364, 0xFFFFFFFF);
                Process::Write32(0x08726368, 0xFFFFFFFF);
                Process::Write32(0x0872636C, 0xFFFFFFFF);
                Process::Write32(0x08726370, 0xFFFFFFFF);
                Process::Write32(0x08726374, 0xFFFFFFFF);
                Process::Write32(0x08726378, 0xFFFFFFFF);
                Process::Write32(0x0872637C, 0xFFFFFFFF);
                Process::Write32(0x08726398, 0xFFFFFFFF);
                Process::Write32(0x0872639C, 0xFFFFFFFF);
            }
		}
        if (userchoice == 2)
		{
            if (IsNew3DS()) {
                Process::Write32(0x0C3263A8, 0x00000000);
                Process::Write32(0x0C3263AC, 0x00000000);
                Process::Write32(0x0C3263B0, 0x00000000);
                Process::Write32(0x0C3263B4, 0x00000000);
                Process::Write32(0x0C3263B8, 0x00000000);
                Process::Write32(0x0C3263BC, 0x00000000);
                Process::Write32(0x0C3263C0, 0x00000000);
                Process::Write32(0x0C3263C4, 0x00000000);
                Process::Write32(0x0C3263C8, 0x00000000);
                Process::Write32(0x0C3263CC, 0x00000000);
                Process::Write32(0x0C3263D0, 0x00000000);
                Process::Write32(0x0C3263D4, 0x00000000);
                Process::Write32(0x0C3263D8, 0x00000000);
                Process::Write32(0x0C3263D8, 0x00000000);
                Process::Write32(0x0C3263DC, 0x00000000);
                Process::Write32(0x0C3263E0, 0x00000000);
                Process::Write32(0x0C3263E4, 0x00000000);
                Process::Write32(0x0C3263E8, 0x00000000);
                Process::Write32(0x0C3263EC, 0x00000000);
                Process::Write32(0x0C3263F0, 0x00000000);
                Process::Write32(0x0C3263F4, 0x00000000);
                Process::Write32(0x0C3263F8, 0x00000000);
                Process::Write32(0x0C3263FC, 0x00000000);
                Process::Write32(0x0C326418, 0x00000000);
                Process::Write32(0x0C32641C, 0x00000000);
                Process::Write32(0x0C326328, 0x00000000);
                Process::Write32(0x0C32632C, 0x00000000);
                Process::Write32(0x0C326330, 0x00000000);
                Process::Write32(0x0C326334, 0x00000000);
                Process::Write32(0x0C326338, 0x00000000);
                Process::Write32(0x0C32633C, 0x00000000);
                Process::Write32(0x0C326340, 0x00000000);
                Process::Write32(0x0C326344, 0x00000000);
                Process::Write32(0x0C326348, 0x00000000);
                Process::Write32(0x0C32634C, 0x00000000);
                Process::Write32(0x0C326350, 0x00000000);
                Process::Write32(0x0C326354, 0x00000000);
                Process::Write32(0x0C326358, 0x00000000);
                Process::Write32(0x0C32635C, 0x00000000);
                Process::Write32(0x0C326360, 0x00000000);
                Process::Write32(0x0C326364, 0x00000000);
                Process::Write32(0x0C326368, 0x00000000);
                Process::Write32(0x0C32636C, 0x00000000);
                Process::Write32(0x0C326370, 0x00000000);
                Process::Write32(0x0C326374, 0x00000000);
                Process::Write32(0x0C326378, 0x00000000);
                Process::Write32(0x0C32637C, 0x00000000);
                Process::Write32(0x0C326398, 0x00000000);
                Process::Write32(0x0C32639C, 0x00000000);
            }
            else {
                Process::Write32(0x087263A8, 0x00000000);
                Process::Write32(0x087263AC, 0x00000000);
                Process::Write32(0x087263B0, 0x00000000);
                Process::Write32(0x087263B4, 0x00000000);
                Process::Write32(0x087263B8, 0x00000000);
                Process::Write32(0x087263BC, 0x00000000);
                Process::Write32(0x087263C0, 0x00000000);
                Process::Write32(0x087263C4, 0x00000000);
                Process::Write32(0x087263C8, 0x00000000);
                Process::Write32(0x087263CC, 0x00000000);
                Process::Write32(0x087263D0, 0x00000000);
                Process::Write32(0x087263D4, 0x00000000);
                Process::Write32(0x087263D8, 0x00000000);
                Process::Write32(0x087263D8, 0x00000000);
                Process::Write32(0x087263DC, 0x00000000);
                Process::Write32(0x087263E0, 0x00000000);
                Process::Write32(0x087263E4, 0x00000000);
                Process::Write32(0x087263E8, 0x00000000);
                Process::Write32(0x087263EC, 0x00000000);
                Process::Write32(0x087263F0, 0x00000000);
                Process::Write32(0x087263F4, 0x00000000);
                Process::Write32(0x087263F8, 0x00000000);
                Process::Write32(0x087263FC, 0x00000000);
                Process::Write32(0x08726418, 0x00000000);
                Process::Write32(0x0872641C, 0x00000000);
                Process::Write32(0x08726328, 0x00000000);
                Process::Write32(0x0872632C, 0x00000000);
                Process::Write32(0x08726330, 0x00000000);
                Process::Write32(0x08726334, 0x00000000);
                Process::Write32(0x08726338, 0x00000000);
                Process::Write32(0x0872633C, 0x00000000);
                Process::Write32(0x08726340, 0x00000000);
                Process::Write32(0x08726344, 0x00000000);
                Process::Write32(0x08726348, 0x00000000);
                Process::Write32(0x0872634C, 0x00000000);
                Process::Write32(0x08726350, 0x00000000);
                Process::Write32(0x08726354, 0x00000000);
                Process::Write32(0x08726358, 0x00000000);
                Process::Write32(0x0872635C, 0x00000000);
                Process::Write32(0x08726360, 0x00000000);
                Process::Write32(0x08726364, 0x00000000);
                Process::Write32(0x08726368, 0x00000000);
                Process::Write32(0x0872636C, 0x00000000);
                Process::Write32(0x08726370, 0x00000000);
                Process::Write32(0x08726374, 0x00000000);
                Process::Write32(0x08726378, 0x00000000);
                Process::Write32(0x0872637C, 0x00000000);
                Process::Write32(0x08726398, 0x00000000);
                Process::Write32(0x0872639C, 0x00000000);
            }
		}
	}

    void YW3_CrossWalkNoYokai(MenuEntry *entry)
    {
        if (IsNew3DS()) {
            Process::Write8(0x0C325ACE, 0x00);
            Process::Write8(0x0C325ACE, 0x00);
        }
        else {
            Process::Write8(0x08725ACE, 0x00);
            Process::Write8(0x08725ACE, 0x00);
        }
    }

    void YW3_AlwaysBright(MenuEntry *entry)
    {
        if (IsNew3DS()) {
            Process::Write32(0x0C4E7210, 0x3F800000);
            Process::Write32(0x0C4E7214, 0x3F800000);
            Process::Write32(0x0C4E7218, 0x3F800000);
            Process::Write32(0x0C4E721C, 0x3F800000);
            Process::Write32(0x0C4E7220, 0x3F800000);
            Process::Write32(0x0C4E7224, 0x3F800000);
        }
        else {
            Process::Write32(0x088E7210, 0x3F800000);
            Process::Write32(0x088E7214, 0x3F800000);
            Process::Write32(0x088E7218, 0x3F800000);
            Process::Write32(0x088E721C, 0x3F800000);
            Process::Write32(0x088E7220, 0x3F800000);
            Process::Write32(0x088E7224, 0x3F800000);
        }
    }

    void YW3_1Day1EventReset(MenuEntry *entry)
    {
        if (IsNew3DS()) {
            Process::Write8(0x0C426299, 0x00);
        }
        else {
            Process::Write8(0x08726299, 0x00);
        }
    }

    void YW3_FloorThrough(MenuEntry *entry)
    {
        static bool mode;
        if (Controller::IsKeysPressed(entry->Hotkeys[0].GetKeys()))
		{
			if (mode)
			{
				mode = false;
				OSD::Notify("Floor Through:Disable");
                Process::Write32(0x00257FA4, 0xEBFBF6EA);
			}
			else {
				mode = true;
				OSD::Notify("Floor Through:Enabled");
				Process::Write32(0x00257FA4, 0xE1A00000);
			}
		}
    }

    void YW3_Profile_PlayTime(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("プレイ時間(秒数)\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C32E010, value);
            }
            else {
                Process::Write32(0x0872E010, value);
            }
        }
    }

    void YW3_Profile_FaceIcon(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("顔アイコン\n\nメダル/モデルIDを入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C32E018, value);
            }
            else {
                Process::Write32(0x0872E018, value);
            }
        }
    }

    void YW3_Profile_Daijiten(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("大辞典発見数変更\n\n16進数で入力してください(0~3E7)");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E032, value);
            }
            else {
                Process::Write8(0x0872E032, value);
            }
        }
    }

    void YW3_Profile_BronzeTrophy(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("銅トロフィー取得数変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E00C, value);
            }
            else {
                Process::Write8(0x0872E00C, value);
            }
        }
    }

    void YW3_Profile_SilverTrophy(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("銀トロフィー取得数変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E00D, value);
            }
            else {
                Process::Write8(0x0872E00D, value);
            }
        }
    }

    void YW3_Profile_GoldTrophy(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("金トロフィー取得数変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E00E, value);
            }
            else {
                Process::Write8(0x0872E00E, value);
            }
        }
    }

    void YW3_Profile_Suretigai(MenuEntry *entry)
    {
        u16 value;
        Keyboard keyboard("すれちがった数変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write16(0x0C32E030, value);
            }
            else {
                Process::Write16(0x0872E030, value);
            }
        }
    }

    void YW3_Profile_KeitaQuest(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("ケータのクエストを解決した数変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E020, value);
            }
            else {
                Process::Write8(0x0872E020, value);
            }
        }
    }

    void YW3_Profile_InahoQuest(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("イナホのクエストを解決した数変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E021, value);
            }
            else {
                Process::Write8(0x0872E021, value);
            }
        }
    }

    void YW3_Profile_Arrestyokai(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("逮捕したウォンテッド妖怪の数変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E022, value);
            }
            else {
                Process::Write8(0x0872E022, value);
            }
        }
    }

    void YW3_Profile_YokainoWa(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("つないだ妖怪の輪の数変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E023, value);
            }
            else {
                Process::Write8(0x0872E023, value);
            }
        }
    }

    void YW3_Profile_CollectBug(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("集めた生き物の数(網)\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E024, value);
            }
            else {
                Process::Write8(0x0872E024, value);
            }
        }
    }

    void YW3_Profile_CollectFish(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("集めた生き物の数(釣竿)\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E025, value);
            }
            else {
                Process::Write8(0x0872E025, value);
            }
        }
    }

    void YW3_Profile_KatinukiBattleRensyou(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("勝ち抜きバトル連勝記録変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E028, value);
            }
            else {
                Process::Write8(0x0872E028, value);
            }
        }
    }

    void YW3_Profile_KatinukiKoushikiBattleRensyou(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("勝ち抜き公式バトル連勝記録変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E029, value);
            }
            else {
                Process::Write8(0x0872E029, value);
            }
        }
    }

    void YW3_Profile_ClearMission(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("達成したミッションの数変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C32E02B, value);
            }
            else {
                Process::Write32(0x0872E02B, value);
            }
        }
    }

    void YW3_Profile_Unknown1(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("解析中...\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E038, value);
            }
            else {
                Process::Write8(0x0872E038, value);
            }
        }
    }

    void YW3_Profile_TreasureSearchClear(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("宝探しクリア記録変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E026, value);
            }
            else {
                Process::Write8(0x0872E026, value);
            }
        }
    }

    void YW3_Profile_CollectMyNyan(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("集めたマイニャンパーツ数変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E03A, value);
            }
            else {
                Process::Write8(0x0872E03A, value);
            }
        }
    }

    void YW3_Profile_Unknown2(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("解析中...\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E039, value);
            }
            else {
                Process::Write8(0x0872E039, value);
            }
        }
    }

    void YW3_Profile_Sakura(MenuEntry *entry)
    {
        float value;
        Keyboard keyboard("自転車レース(さくら住宅街)最速記録変更\n\nfloatで入力してください\n例:3分20秒の場合=3.20");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::WriteFloat(0x0C32E048, value);
            }
            else {
                Process::WriteFloat(0x0872E048, value);
            }
        }
    }

    void YW3_Profile_Aohabara(MenuEntry *entry)
    {
        float value;
        Keyboard keyboard("自転車レース(アオハバラ)最速記録変更\n\nfloatで入力してください\n例:3分20秒の場合=3.20");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::WriteFloat(0x0C32E04C, value);
            }
            else {
                Process::WriteFloat(0x0872E04C, value);
            }
        }
    }

    void YW3_Profile_Unknown3(MenuEntry *entry)
    {
        float value;
        Keyboard keyboard("自転車レース(解析中...)変更\n\nfloatで入力してください\n例:3分20秒の場合=3.20");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::WriteFloat(0x0C32E050, value);
            }
            else {
                Process::WriteFloat(0x0872E050, value);
            }
        }
    }

    void YW3_Profile_Unknown4(MenuEntry *entry)
    {
        float value;
        Keyboard keyboard("自転車レース(解析中...)変更\n\nfloatで入力してください\n例:3分20秒の場合=3.20");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::WriteFloat(0x0C32E054, value);
            }
            else {
                Process::WriteFloat(0x0872E054, value);
            }
        }
    }

    void YW3_Profile_Unknown5(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("解析中...\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C32E058, value);
            }
            else {
                Process::Write32(0x0872E058, value);
            }
        }
    }

    void YW3_Profile_Unknown6(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("解析中...\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C32E05C, value);
            }
            else {
                Process::Write32(0x0872E05C, value);
            }
        }
    }

    void YW3_Profile_Unknown7(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("解析中\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C32E060, value);
            }
            else {
                Process::Write32(0x0872E060, value);
            }
        }
    }

    void YW3_Profile_Unknown8(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("解析中\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C32E064, value);
            }
            else {
                Process::Write32(0x0872E064, value);
            }
        }
    }

    void YW3_Profile_NyaKBLive(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("ニャーKBライブ最高得点変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C32E068, value);
            }
            else {
                Process::Write32(0x0872E068, value);
            }
        }
    }

    void YW3_Profile_Unknown9(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("解析中...\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C32E06C, value);
            }
            else {
                Process::Write32(0x0872E06C, value);
            }
        }
    }

    void YW3_Profile_Unknown10(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("解析中...\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C32E070, value);
            }
            else {
                Process::Write32(0x0872E070, value);
            }
        }
    }

    void YW3_Profile_Poltergeist(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("ポルターガイスト最高得点変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C32E074, value);
            }
            else {
                Process::Write32(0x0872E074, value);
            }
        }
    }

    void YW3_Profile_FavoriteYokai1(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("お気に入り妖怪1位変更\n\nメダル/モデルIDを入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C32E03C, value);
            }
            else {
                Process::Write32(0x0872E03C, value);
            }
        }
    }

    void YW3_Profile_FavoriteYokai2(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("お気に入り妖怪2位変更\n\nメダル/モデルIDを入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C32E040, value);
            }
            else {
                Process::Write32(0x0872E040, value);
            }
        }
    }

    void YW3_Profile_FavoriteYokai3(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("お気に入り妖怪3位変更\n\nメダル/モデルIDを入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C32E044, value);
            }
            else {
                Process::Write32(0x0872E044, value);
            }
        }
    }

    void YW3_RedBoxEvent(MenuEntry *entry)
    {
        Keyboard keyboard("赤い箱イベント実行");
        std::vector < std::string > option =
        {
            "おなら", "犬時間", "鬼時間(鬼役)", "解除"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
			if (IsNew3DS()) {
                Process::Write32(0x0C325838, 0x04000000);
                Process::Write32(0x0C325B08, 0x00000004);
            }
            else {
                Process::Write32(0x08725838, 0x04000000);
                Process::Write32(0x08725B08, 0x00000004);
            }
		}
        if (userchoice == 1) {
			if (IsNew3DS()) {
                Process::Write32(0x0C325838, 0x04000000);
                Process::Write32(0x0C325B08, 0x00000005);
            }
            else {
                Process::Write32(0x08725838, 0x04000000);
                Process::Write32(0x08725B08, 0x00000005);
            }
		}
        if (userchoice == 2) {
			if (IsNew3DS()) {
                Process::Write32(0x0C325838, 0x04000000);
                Process::Write32(0x0C325B08, 0x00000006);
            }
            else {
                Process::Write32(0x08725838, 0x04000000);
                Process::Write32(0x08725B08, 0x00000006);
            }
		}
        if (userchoice == 3) {
			if (IsNew3DS()) {
                Process::Write32(0x0C325838, 0x00002000);
                Process::Write32(0x0C325B08, 0x00000000);
            }
            else {
                Process::Write32(0x08725838, 0x00002000);
                Process::Write32(0x08725B08, 0x00000000);
            }
		}
    }

    void YW3_YokaiBrusterMax(MenuEntry *entry)
    {
        if (IsNew3DS()) {
            Process::Write16(0x0C3267BA, 0x03E8);
        }
        else {
            Process::Write16(0x087267BA, 0x03E8);
        }
    }

    static const std::vector<U32_VALUE_TEXT> map_sakura_list =
	{
		{0x17DC03F6, "さくら住宅街"},
		{0x6A451E6A, "天野家 1階"},
		{0xF34C4FD0, "天野家 2階"},
		{0x844B7F46, "木霊家 1階"},
		{0x1A2FEAE5, "木霊家 2階"},
		{0xB67D1DC4, "ヨロズマートさんかく通り店"},
		{0xB110D9DD, "こぶた銀行"},
		{0x56A8F4DA, "こやぎ郵便"},
		{0x41684DA9, "ジャングルハンター"},
		{0x58737CE8, "アッカンベーカリー"},
		{0x5F1EB8F1, "公民館"},
		{0x460589B0, "おもいで屋"},
		{0x1732EA2F, "さくら第一小学校 南校舎1階"},
		{0x8E3BBB95, "さくら第一小学校 北校舎1階"},
		{0xF93C8B03, "さくら第一小学校 2階"},
		{0x105F2E36, "さくら第一小学校 3階"},
		{0x6EEE528B, "さくら第一小学校 屋上"},
		{0x19E9621D, "さくら第一小学校 体育館"},
		{0x8C93EC15, "ねこの通り道"},
		{0x65F04920, "ひとなし路地"},
		{0x629D8D39, "怪しい路地裏"},
		{0x629D8D39, "さびしげな水路"}
	};
	
	static const std::vector<U32_VALUE_TEXT> map_soyokaze_list =
	{
		{0x8A0B3B4F, "そよ風ヒルズ"},
		{0xC5A44451, "ヨロズマート そよ風ヒルズ店"},
		{0xD467E643, "ひょうたん池博物館 1階"},
		{0x4D6EB7F9, "ひょうたん池博物館 2階"},
		{0x3A69876F, "ひょうたん池博物館 資料保管庫"},
		{0xF79226D3, "今田家 1階"},
		{0x6E9B7769, "今田家 2階"},
		{0xF0FFE2CA, "倉岩家"},
		{0x13EC832C, "リリィガーデン エントランス"},
		{0x8AE5D296, "リリィガーデン 地下駐車場"},
		{0x2BAA257D, "トロフィールーム"},
		{0x9E2643FB, "ジャンボスライダー"},
		{0x6FAD8CDA, "しおかぜトンネル"},
        {0x008776BE, "そよ風ヒルズ レジデンス エントランス"},
        {0xE9E4D38B, "そよ風ヒルズ レジデンス 7階"},
        {0xEE891792, "未空家"}
	};
	
	static const std::vector<U32_VALUE_TEXT> map_dandan_list =
	{
		{0xBDD5CB7D, "団々坂"},
		{0xF517707A, "ヨロズマート 団々坂店"},
		{0xEB618522, "正天寺"},
		{0xEC0C413B, "冥心漢方"},
		{0xF27AB463, "チョーシ堂"},
		{0x1C74D54F, "駄菓子屋"},
		{0x02022017, "さくらの湯 ロビー"},
		{0x92BD3D86, "さくらの湯 男湯"},
		{0xE5BA0D10, "さくらの湯 女湯"},
		{0xC04CD6E1, "熊島家 1階"},
		{0x5945875B, "熊島家 2階"},
		{0x2E42B7CD, "熊島家 3階"},
		{0xBD3B22A4, "鳥飼家 大広間"},
		{0x53354388, "鳥飼家 隠し部屋"},
		{0xE3B91671, "ぼろやしき"},
		{0x0DB7775D, "ぼろやしき 母屋"},
		{0xE11141F1, "さすらい荘 1階 1部屋目"},
		{0x96167167, "さすらい荘 1階 2部屋目"},
		{0x0F1F20DD, "さすらい荘 1階 3部屋目"},
		{0x7818104B, "さすらい荘 1階 4部屋目"},
		{0xE67C85E8, "さすらい荘 1階 5部屋目"},
		{0x917BB57E, "さすらい荘 2階 1部屋目"},
		{0x0872E4C4, "さすらい荘 2階 2部屋目"},
		{0x7F75D452, "さすらい荘 2階 3部屋目"},
		{0xEFCAC9C3, "さすらい荘 2階 4部屋目"},
		{0x98CDF955, "さすらい荘 2階 5部屋目"},
		{0x269A249E, "ないしょの横路"},
		{0xC89445B2, "こっそり空地"},
		{0xD18F74F3, "ひみつの抜け道"},
		{0x056FE40E, "ひがん山トンネル"}
	};
	
	static const std::vector<U32_VALUE_TEXT> map_otsukai_list =
	{
		{0x98BE94A1, "おつかい横丁"},
		{0xD07C2FA6, "ヨロズマート おつかい横丁店"},
		{0xCE0ADAFE, "コインランドリー"},
		{0xC9671EE7, "めっけもん"},
		{0x8993DF6A, "かげむら医院 1階"},
		{0x679DBE46, "かげむら医院 2階"},
		{0x60F07A5F, "かげむら医院 地下階段"},
		{0xF04F67CE, "かげむら医院 地下実験室"},
		{0xF4E42B2F, "あんのん団地 A-101号室"},
		{0x6DED7A95, "あんのん団地 A-201号室"},
		{0x31C719C0, "あんのん団地 A-202号室"},
		{0x1AEA4A03, "あんのん団地 A-203号室"},
		{0x41ADED4F, "あんのん団地 A-302号室"},
		{0x848EDFA0, "あんのん団地 B-102号室"},
		{0xAFA38C63, "あんのん団地 B-104号室"},
		{0xF389EF36, "あんのん団地 B-201号室"},
		{0x6A80BE8C, "あんのん団地 B-204号室"},
		{0x1D878E1A, "あんのん団地 B-301号室"},
		{0x8D38938B, "あんのん団地 C-101号室"},
		{0xA8CE487A, "あんのん団地 C-202号室"},
		{0xD8A4BCF5, "あんのん団地 C-203号室"},
		{0xDFC978EC, "あんのん団地 C-204号室"},
		{0xFA3FA31D, "あんのん団地 C-302号室"},
		{0x46C02956, "あんのん団地 C-303号室"},
		{0xA016DB29, "桜町フラワーロード"},
		{0xD711EBBF, "どっこい書店"},
		{0x27697FCB, "お花見寿司"},
		{0x3E724E8A, "タイヨー軒"},
		{0x391F8A93, "風ラーメン"},
		{0xD9CA638D, "ワククポケット"},
		{0x2004BBD2, "カリススタイル"},
		{0xEDFF1A6E, "商店の細道"}
	};
	
	static const std::vector<U32_VALUE_TEXT> map_sakuracity_list =
	{
		{0xCDBF7197, "さくら中央シティ 紹介時エリア"},
		{0x2002F3C4, "さくら中央シティ"},
		{0x98B8DCB7, "ヨロズマート さくら中央シティ店"},
		{0x617604E8, "福北病院 1階"},
		{0x01B18D0D, "福北病院 2階"},
		{0x76B6BD9B, "はるこい学習塾"},
		{0x68C048C3, "ピコピコランド"},
		{0x71DB7982, "カフェ・オ・シャレンヌ"},
		{0x9FD518AE, "さくらスポーツクラブ 1階"},
		{0x0F6A053F, "さくらスポーツクラブ 2階"},
		{0x786D35A9, "さくらスポーツクラブ 3階"},
		{0x20EC1A1D, "さくらビジネスガーデンビル 1階"},
		{0x4C584C4A, "さくらビジネスガーデンビル 4階"},
		{0xCEE27B31, "さくらビジネスガーデンビル 7階"},
		{0xA2562D66, "さくらビジネスガーデンビル 13階"},
		{0x86CE29EF, "モグモグバーガー"},
		{0x39F72B5C, "カレーハウス ナマステ"},
		{0x81A3EDF6, "スナックゆきおんな"},
		{0x522EB912, "うんぱん通路"},
		{0x55437D0B, "塾への近道"},
		{0xBB4D1C27, "ゆきおんなへの裏道"},
        {0x2781DE04, "スキヤキ 千牛"},
        {0x3E9AEF45, "サンセットモール B1階"},
        {0xD0948E69, "サンセットモール 1階"},
        {0x372CA36E, "サンセットモール ドルフィンカフェ"},
        {0xD7F94A70, "カメカメラ"},
        {0x3387EF8F, "桜中央地下街"},
        {0xBC20D83E, "桜中央地下駐輪場"}
	};
	
	static const std::vector<U32_VALUE_TEXT> map_oomori_list =
	{
		{0x0569AC18, "おおもり山"},
		{0x702822D7, "おおもり山 登山道"},
		{0xE921736D, "おおもり山 山頂"},
		{0x78F0B184, "廃屋"},
		{0x4AC6D306, "滝の裏の祠"},
		{0xC20C20AE, "廃トンネル 東"},
		{0x5B057114, "廃トンネル 西"}
	};
	
	static const std::vector<U32_VALUE_TEXT> map_extree_list =
	{
		{0x32B75C2A, "さくらEXツリー"},
		{0x4F2E41B6, "さくらEXツリー エントランス"},
		{0xA120209A, "さくらEXツリー 展望台"},
		{0xD627100C, "エレベーター"}
	};

    static const std::vector<U32_VALUE_TEXT> map_aobahara_list =
	{
		{0x6AD44C7C, "アオバハラ"},
        {0x0E5660A1, "イナウサ不思議探偵社"},
        {0xE058018D, "青葉そば"},
        {0x174D51E0, "ニャーKB劇場 エントランス"},
        {0x1F95C2B3, "ひかげパーキング"},
        {0xFE2EF4D5, "カフェ♡めいどらんど"},
        {0x102095F9, "アニメ堂"},
        {0x1996D9D2, "ヨロズマート アオバハラ店"},
        {0xF19BA39F, "ジャンク横丁"},
        {0x5A410E13, "アオバ駅"}
	};
	
	static const std::vector<U32_VALUE_TEXT> map_kemamoto_list =
	{
		{0x42C9D6C8, "ケマモト駅 駅前"},
		{0x37885807, "駅前の古い民間"},
		{0x507C7926, "ケマモト村"},
		{0x600CA5FD, "えんえんトンネル"},
		{0x7E7A50A5, "むこうがわ"},
		{0x2DE564BA, "おばあちゃんの家"},
		{0xC3EB0596, "分校"},
		{0x2A88A0A3, "入山商店"},
		{0xCB3396C5, "キウチ山 正面岩"},
		{0x55570366, "キウチ山 かわせみ渓谷"},
		{0x225033F0, "キウチ山 山頂"},
		{0x253DF7E9, "棚田の跡地"}
	};
	
	static const std::vector<U32_VALUE_TEXT> map_nagisaki_list =
	{
		{0x6D1C5096, "ナギサキ"},
		{0xFE8B2C26, "こじま商店"},
		{0x10854D0A, "さざなみ集会所"},
		{0x185DDE59, "潮騒の岩屋"},
		{0xF653BF75, "裏の作業場"},
		{0x0146EF18, "海辺の洞穴"},
		{0x55B41F1E, "海上"},
		{0x7E994CDD, "廃屋"}
	};

    static const std::vector<U32_VALUE_TEXT> map_tazono_list =
	{
		{0xD2682B19, "たぞの駅 駅前"}
	};
	
	static const std::vector<U32_VALUE_TEXT> map_sakura60_list =
	{
		{0x91487158, "桜町"},
		{0x83FDDEB6, "おおもり山"},
		{0x02DF0DE8, "超視堂"},
		{0xECD16CC4, "正天寺"},
		{0xFD12CED6, "桜町鉄工所"},
		{0x82CD6D13, "花道商店街"},
		{0xE409FF97, "お稲荷さん通り"},
		{0x0A079EBB, "中井戸通り"},
		{0xD63F9D15, "夕陽ヶ丘工場 正門"},
		{0x3831FC39, "夕陽ヶ丘工場 第一炉"},
		{0xA9E03ED0, "ひがん山トンネル"},
		{0x2BB2A864, "平釜平原"},
		{0x0C9F49E1, "60年前のひょうたん池"}
	};
	
	static const std::vector<U32_VALUE_TEXT> map_kemamoto60_list =
	{
		{0xC45DA466, "ケマモト駅 駅前"},
		{0xD6E80B88, "ケマモト村"},
		{0xAC1CD20D, "昔の家"},
		{0xA3A98547, "棚田"},
		{0xAB711614, "しのびの森"},
		{0x457F7738, "秘密基地"},
		{0xD3C371C8, "キウチ山 かわせみ渓谷"},
		{0x4DA7E46B, "キウチ山 かわせみ渓谷 山頂"},
		{0xA4C4415E, "キウチ山 山頂"}
	};
	
	static const std::vector<U32_VALUE_TEXT> map_station_list =
	{
		{0x3330CBDD, "さくらぎ駅"},
		{0xC3485FA9, "桜中央駅(構内)"},
		{0x0BC149DE, "桜中央駅"},
		{0x5A410E13, "アオバ駅"},
		{0x2D463E85, "ひばり台駅"},
		{0xB322AB26, "はなやま駅"},
		{0xC4259BB0, "いわくり駅"},
		{0x5D2CCA0A, "かすが野駅"},
		{0x2A2BFA9C, "福ノ宮駅"},
		{0xBA94E70D, "はしぶね駅"},
		{0xCD93D79B, "ねぼとけ駅"},
		{0xAD545E7E, "やまなか駅"},
		{0xDA536EE8, "きしべ駅"},
		{0x435A3F52, "ナギサキ駅"},
		{0xA38FD64C, "こひなた駅"},
		{0x345D0FC4, "たぞの駅"},
		{0xAA399A67, "おさらぎ駅"},
		{0xDD3EAAF1, "たにあい駅"},
		{0x4437FB4B, "ケマモト駅"}
	};
	
	static const std::vector<U32_VALUE_TEXT> map_train_list =
	{
		{0xB10079BA, "通常世界 列車"},
		{0x5BE99CC0, "妖魔特急 普通車"},
		{0xB5E7FDEC, "妖魔特急 機関室"},
		{0x495C332E, "ふくふく超特急"}
	};
	
	static const std::vector< U32_VALUE_TEXT > map_yokaiworld_list =
	{
		{0xCDAD9B98, "妖楽門"}
	};

    static const std::vector<U32_VALUE_TEXT> map_southmond_list =
	{
		{0x47119245, "サウスモンド地区"},
        {0x3A888FD9, "USA 天野家 1階"},
        {0xA381DE63, "USA 天野家 2階"},
        {0xE6B08C77, "ピジョン郵便"},
        {0x08BEED5B, "アルモンド銀行"},
        {0xCD9DDFB4, "ボックスハウス"},
        {0x32501C8A, "BBQガーデン"},
        {0x00667E08, "スクラップヤード"},
        {0x2393BE98, "ザッカリーストア"},
        {0x47FF7B9C, "サウスモンドスクール"},
        {0x4092BF85, "サウスモンドスクール カフェテリア"}
	};

    static const std::vector<U32_VALUE_TEXT> map_nospista_list =
	{
		{0x55A43DAB, "ノースピスタ地区"},
        {0xDF28705A, "スシバー MAKISUGI"},
        {0x364BD56F, "PIZZA アモーレ"},
        {0x26E6A805, "スター☆バーガー"},
        {0x31261176, "チキントイトイ"},
        {0x031073F4, "市役所 1階"},
        {0x9A19224E, "市役所 2階"},
        {0xED1E12D8, "市役所 屋上"},
        {0x20E5B364, "ヒップホップな路地裏"},
        {0xC15E8502, "ミラクルサーカス"},
        {0x283D2037, "ヨロズマート ノースピスタ店"},
        {0x1A0B42B5, "3番倉庫マーケット"},
        {0xCEEBD248, "2番倉庫"},
        {0xC633411B, "サクラ商事 SPBオフィス"},
        {0x12D3D1E6, "きまぐれパーリールーム"},
        {0x2F50E42E, "ワンダーボート"}
	};

    static const std::vector<U32_VALUE_TEXT> map_eastcasue_list =
	{
        {0xED185ACE, "イーストカシュー地区"},
		{0x8EF7B20A, "SUKIYAKI スキスキ"},
        {0x8142E540, "モーシンデルマート"},
        {0x8142E540, "モーシンデルマート バックヤード"},
        {0x7E8F267E, "ボブの時計屋"},
        {0x9859D401, "ホテル裏の抜け道"},
        {0xB1DCD042, "SASURAI荘 #101"},
        {0xC6DBE0D4, "SASURAI荘 #102"},
        {0x5FD2B16E, "SASURAI荘 #103"},
        {0x28D581F8, "SASURAI荘 #104"},
        {0xB6B1145B, "SASURAI荘 #105"},
        {0xC1B624CD, "SASURAI荘 #201"},
        {0x58BF7577, "SASURAI荘 #202"},
        {0x2FB845E1, "SASURAI荘 #203"},
        {0xBF075870, "SASURAI荘 #204"},
        {0xC80068E6, "SASURAI荘 #205"},
        {0x90814752, "ブロッコリン教会"},
        {0x97EC834B, "ステーキハウス 29"},
        {0x79E2E267, "古びた洋館"},
        {0x6794173F, "TEMPURA 天天"}
	};

    static const std::vector<U32_VALUE_TEXT> map_damian_list =
	{
        {0xDAC6AAFC, "ダミアン農場"},
        {0x9DB146B1, "ダミアン農場(麦畑)"}
	};

    static const std::vector<U32_VALUE_TEXT> map_forest_list =
	{
        {0xC8730512, "森の秘密基地"},
        {0xB5EA188E, "秘密基地"},
        {0xA429BA9C, "モクノームの森"}
	};

    static const std::vector<U32_VALUE_TEXT> map_hezeltain_list =
	{
        {0x70CF6277, "ヘーゼルタイン邸"},
        {0xEB808D94, "エントランスホール"},
        {0x02E328A1, "1階廊下"},
        {0xECED498D, "美食の間"},
        {0x1C95DDF9, "厨房"},
        {0x0B55648A, "審判の間"},
        {0xF29BBCD5, "バスルーム"},
        {0x1BF819E0, "2階廊下"},
        {0xF5F678CC, "大書庫"},
        {0x124E55CB, "ドロシーとマックの部屋"},
        {0x058EECB8, "地下通路"}
	};

    static const std::vector<U32_VALUE_TEXT> map_makkura_list =
	{
        {0x8F04E95F, "マックラーナ洞窟"}
	};

    static const std::vector<U32_VALUE_TEXT> map_seibu_list =
	{
        {0x68C4141B, "ノランポート"},
        {0x783705AC, "ノランポニー峡谷"},
        {0x7A71BBF5, "ウォルナービレッジ"},
        {0x00856270, "雑貨屋 ワイルドハンターズ"},
        {0x07E8A669, "ホテル アウトルート"},
        {0xE9E6C745, "保安官オフィス"}
	};

    static const std::vector<U32_VALUE_TEXT> map_yopple_list =
	{
        {0x9BF73C1E, "エントランスガーデン"},
        {0x75F95D32, "エントランスロビー"},
        {0x7294992B, "妖怪ウォッチセンター"},
        {0x82EC0D5F, "ウォッチラボ"},
        {0x952CB42C, "ミーティングルーム"},
        {0x6B8FA86A, "カフェテリア"},
        {0x8581C946, "ファイティングルーム"},
        {0x6CE26C73, "ファクトリールーム"},
        {0x8C37856D, "オーシャンフロア"},
        {0x9C9AF807, "社長室"}
	};

    static const std::vector<U32_VALUE_TEXT> map_newyoumacity_list =
	{
        {0xDC80D053, "ニュー妖魔シティ"},
        {0xDB03FD93, "ヨップルストア"},
        {0xD2B5B1B8, "TEMPURA 大往生"},
        {0x350D9CBF, "SUSHI 輪廻"},
        {0xEE585B08, "SUKIYAKI 浄土"},
        {0x326058A6, "エンマ離宮"},
        {0xF7436A49, "バスターズハウス"},
        {0x80445ADF, "バスターズハウス B1階"},
        {0xDC6E398A, "クラブ MONGEE"},
        {0xD4B6AAD9, "ゴッドタワー ロビー"},
	};

    void YW3_AreaWarp(MenuEntry *entry)
	{
		Keyboard keyboard("エリアワープ\n\nワープしたい場所を選んでください");
        std::vector < std::string > option = {"USA", "日本", "妖怪ワールド"};
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
            Keyboard keyboard("エリアワープ\nUSA\n\nワープしたい場所を選んでください");
            std::vector < std::string > option = 
            {
                "サウスモンド地区", "ノースピスタ地区", "イーストカシュー地区",
                "ダミアン農場", "森の秘密基地", "ヘーゼルタイン邸", "マックラーナ洞窟", "ノランポート/ウォルナービレッジ"
            };
            keyboard.Populate(option);
            userchoice = keyboard.Open();
            if (userchoice == 0)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_southmond_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\nUSA -> サウスモンド地区\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_southmond_list[choice].id);
                        Process::Write32(0x0C3268F4,map_southmond_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_southmond_list[choice].id);
                        Process::Write32(0x089268F4,map_southmond_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 1)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_nospista_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\nUSA -> ノースピスタ地区\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_nospista_list[choice].id);
                        Process::Write32(0x0C3268F4,map_nospista_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_nospista_list[choice].id);
                        Process::Write32(0x089268F4,map_nospista_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 2)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_eastcasue_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\nUSA -> イーストカシュー地区\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_eastcasue_list[choice].id);
                        Process::Write32(0x0C3268F4,map_eastcasue_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_eastcasue_list[choice].id);
                        Process::Write32(0x089268F4,map_eastcasue_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 3)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_damian_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\nUSA -> ダミアン農場\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_damian_list[choice].id);
                        Process::Write32(0x0C3268F4,map_damian_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_damian_list[choice].id);
                        Process::Write32(0x089268F4,map_damian_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 4)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_forest_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\nUSA -> 森の秘密基地\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_forest_list[choice].id);
                        Process::Write32(0x0C3268F4,map_forest_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_forest_list[choice].id);
                        Process::Write32(0x089268F4,map_forest_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 5)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_hezeltain_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\nUSA -> ヘーゼルタイン邸\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_hezeltain_list[choice].id);
                        Process::Write32(0x0C3268F4,map_hezeltain_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_hezeltain_list[choice].id);
                        Process::Write32(0x089268F4,map_hezeltain_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 6)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_makkura_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\nUSA -> マックラーナ洞窟\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_makkura_list[choice].id);
                        Process::Write32(0x0C3268F4,map_makkura_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_makkura_list[choice].id);
                        Process::Write32(0x089268F4,map_makkura_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 7)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_seibu_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\nUSA -> ノランポート/ウォルナービレッジ\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_seibu_list[choice].id);
                        Process::Write32(0x0C3268F4,map_seibu_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_seibu_list[choice].id);
                        Process::Write32(0x089268F4,map_seibu_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
        }
        else if (userchoice == 1) {
            Keyboard keyboard("エリアワープ\n日本\n\nワープしたい場所を選んでください\n\n");
            std::vector < std::string > option =
            {
                "さくら住宅街", "そよ風ヒルズ", "団々坂", "おつかい横丁", "さくら中央シティ",
                "おおもり山", "さくらEXツリー", "アオハバラ", "ケマモト村", "ナギサキ",
                "たぞの", "60年前のさくらニュータウン", "60年前のケマモト村", "駅", "電車内", "妖楽門"
            };
            keyboard.Populate(option);
            userchoice = keyboard.Open();
            if (userchoice == 0)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_sakura_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> さくら住宅街\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_sakura_list[choice].id);
                        Process::Write32(0x0C3268F4,map_sakura_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_sakura_list[choice].id);
                        Process::Write32(0x089268F4,map_sakura_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 1)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_soyokaze_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> そよ風ヒルズ\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_soyokaze_list[choice].id);
                        Process::Write32(0x0C3268F4,map_soyokaze_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_soyokaze_list[choice].id);
                        Process::Write32(0x089268F4,map_soyokaze_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 2)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_dandan_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> 団々坂\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_dandan_list[choice].id);
                        Process::Write32(0x0C3268F4,map_dandan_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_dandan_list[choice].id);
                        Process::Write32(0x089268F4,map_dandan_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 3)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_otsukai_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> おつかい横丁\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_otsukai_list[choice].id);
                        Process::Write32(0x0C3268F4,map_otsukai_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_otsukai_list[choice].id);
                        Process::Write32(0x089268F4,map_otsukai_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 4)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_sakuracity_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> さくら中央シティ\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_sakuracity_list[choice].id);
                        Process::Write32(0x0C3268F4,map_sakuracity_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_sakuracity_list[choice].id);
                        Process::Write32(0x089268F4,map_sakuracity_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 5)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_oomori_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> おおもり山\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_oomori_list[choice].id);
                        Process::Write32(0x0C3268F4,map_oomori_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_oomori_list[choice].id);
                        Process::Write32(0x089268F4,map_oomori_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 6)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_extree_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> さくらEXツリー\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_extree_list[choice].id);
                        Process::Write32(0x0C3268F4,map_extree_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_extree_list[choice].id);
                        Process::Write32(0x089268F4,map_extree_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 7)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_aobahara_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> アオバハラ\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_aobahara_list[choice].id);
                        Process::Write32(0x0C3268F4,map_aobahara_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_aobahara_list[choice].id);
                        Process::Write32(0x089268F4,map_aobahara_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 8)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_kemamoto_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> ケマモト村\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_kemamoto_list[choice].id);
                        Process::Write32(0x0C3268F4,map_kemamoto_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_kemamoto_list[choice].id);
                        Process::Write32(0x089268F4,map_kemamoto_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 9)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_nagisaki_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> ナギサキ\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_nagisaki_list[choice].id);
                        Process::Write32(0x0C3268F4,map_nagisaki_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_nagisaki_list[choice].id);
                        Process::Write32(0x089268F4,map_nagisaki_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 10)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_tazono_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> たぞの\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_tazono_list[choice].id);
                        Process::Write32(0x0C3268F4,map_tazono_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_tazono_list[choice].id);
                        Process::Write32(0x089268F4,map_tazono_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 11)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_sakura60_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> 60年前のさくらニュータウン\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_sakura60_list[choice].id);
                        Process::Write32(0x0C3268F4,map_sakura60_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_sakura60_list[choice].id);
                        Process::Write32(0x089268F4,map_sakura60_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 12)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_kemamoto60_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> 60年前のケマモト村\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_kemamoto60_list[choice].id);
                        Process::Write32(0x0C3268F4,map_kemamoto60_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_kemamoto60_list[choice].id);
                        Process::Write32(0x089268F4,map_kemamoto60_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 13)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_station_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> 駅\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_station_list[choice].id);
                        Process::Write32(0x0C3268F4,map_station_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_station_list[choice].id);
                        Process::Write32(0x089268F4,map_station_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 14)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_train_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> 電車\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_train_list[choice].id);
                        Process::Write32(0x0C3268F4,map_train_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_train_list[choice].id);
                        Process::Write32(0x089268F4,map_train_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
            else if (userchoice == 15)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_yokaiworld_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n日本 -> 妖楽門\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_yokaiworld_list[choice].id);
                        Process::Write32(0x0C3268F4,map_yokaiworld_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_yokaiworld_list[choice].id);
                        Process::Write32(0x089268F4,map_yokaiworld_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
        }
        else if (userchoice == 2) {
            Keyboard keyboard("エリアワープ\n\nワープしたい場所を選んでください\n\n妖怪ワールド ->");
            std::vector < std::string > option =
            {
                "ヨップル社", "ニュー妖魔シティ"
            };
            keyboard.Populate(option);
            userchoice = keyboard.Open();
            if (userchoice == 0)
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_yopple_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n妖怪ワールド -> ヨップル社\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= 0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_yopple_list[choice].id);
                        Process::Write32(0x0C3268F4,map_yopple_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_yopple_list[choice].id);
                        Process::Write32(0x089268F4,map_yopple_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
        }
        if (userchoice == 1) {
            {
                items_yw3.clear();
                if (items_yw3.empty())
                    for(const U32_VALUE_TEXT &i: map_newyoumacity_list)
                    items_yw3.push_back(i.name);
                Keyboard keyboard("エリアワープ\n妖怪ワールド -> ニュー妖魔シティ\n\nワープしたい場所を選んでください", items_yw3);
                int choice = keyboard.Open();
                if (choice >= -0)
                {
                    if (IsNew3DS()) {
                        Process::Write32(0x0C3266E4,map_newyoumacity_list[choice].id);
                        Process::Write32(0x0C3268F4,map_newyoumacity_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x0C4F09BC, 0x00000000);
                            Process::Write32(0x0C4F09C0, 0xF0000000);
                            Process::Write32(0x0C4F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x0C5004BC, 0x00000000);
                            Process::Write32(0x0C5004C0, 0xF0000000);
                            Process::Write32(0x0C5004C4, 0x00000000);
                        }
                    }
                    else {
                        Process::Write32(0x087266E4,map_newyoumacity_list[choice].id);
                        Process::Write32(0x089268F4,map_newyoumacity_list[choice].id);
                        if (IsSukiyaki()) {
                            Process::Write32(0x088F09BC, 0x00000000);
                            Process::Write32(0x088F09C0, 0xF0000000);
                            Process::Write32(0x088F09C4, 0x00000000);
                        }
                        else {
                            Process::Write32(0x089004BC, 0x00000000);
                            Process::Write32(0x089004C0, 0xF0000000);
                            Process::Write32(0x089004C4, 0x00000000);
                        }
                    }
                }
            }
        }
	}

    void YW3_ZombieNightFlag(MenuEntry *entry)
	{
		Keyboard keyboard("ゾンビナイト開放フラグ編集");
        std::vector < std::string > option =
        {
            "全開放", "未開放"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
		if (userchoice == 0)
		{
            if (IsNew3DS()) {
                Process::Write32(0x0C325ADC, 0xFFFFFFFF);
                Process::Write32(0x0C325AE0, 0xFFFFFFFF);
                Process::Write32(0x0C325AE4, 0xFFFFFFFF);
                Process::Write32(0x0C325AE8, 0xFFFFFFFF);
                Process::Write32(0x0C325AEC, 0xFFFFFFFF);
            }
            else {
                Process::Write32(0x08725ADC, 0xFFFFFFFF);
                Process::Write32(0x08725AE0, 0xFFFFFFFF);
                Process::Write32(0x08725AE4, 0xFFFFFFFF);
                Process::Write32(0x08725AE8, 0xFFFFFFFF);
                Process::Write32(0x08725AEC, 0xFFFFFFFF);
            }
		}
        if (userchoice == 1)
		{
            if (IsNew3DS()) {
                Process::Write32(0x0C325ADC, 0x00000000);
                Process::Write32(0x0C325AE0, 0x00000000);
                Process::Write32(0x0C325AE4, 0x00000000);
                Process::Write32(0x0C325AE8, 0x00000000);
                Process::Write32(0x0C325AEC, 0x00000000);
            }
            else {
                Process::Write32(0x08725ADC, 0x00000000);
                Process::Write32(0x08725AE0, 0x00000000);
                Process::Write32(0x08725AE4, 0x00000000);
                Process::Write32(0x08725AE8, 0x00000000);
                Process::Write32(0x08725AEC, 0x00000000);
            }
		}
	}

    void YW3_KabegamiFlag(MenuEntry *entry)
	{
		Keyboard keyboard("妖怪パッド壁紙開放フラグ編集");
        std::vector < std::string > option =
        {
            "全開放", "未開放"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
		if (userchoice == 0)
		{
            if (IsNew3DS()) {
                Process::Write8(0x0C32581B, 0xFF);
            }
            else {
                Process::Write8(0x0872581B, 0xFF);
            }
		}
        if (userchoice == 1)
		{
            if (IsNew3DS()) {
                Process::Write8(0x0C32581B, 0x00);
            }
            else {
                Process::Write8(0x0872581B, 0x00);
            }
		}
	}

    /*void YW3_JunglePoint(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("所持ジャングルポイント変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C31B560, value);
            }
            else {
                Process::Write32(0x0871B560, value);
            }
        }
    }

    void YW3_WantedPoint(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("所持ウォンテッドポイント変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C3266F8, value);
            }
            else {
                Process::Write32(0x087266F8, value);
            }
        }
    }*/

    static u32 resultxp, resultmoney;

    void YW3_BattleResultXP(MenuEntry *entry)
    {
        if (IsNew3DS()) {
            Process::Write32(0x0C31B688, resultxp);
        }
        else {
            Process::Write32(0x0871B688, resultxp);
        }
    }

    void YW3_BattleResultXP_Settings(MenuEntry *entry)
    {
        Keyboard keyboard("バトル後獲得経験値変更\n\n16進数で入力してください");
        keyboard.Open(resultxp);
    }

    void YW3_BattleResultMoney(MenuEntry *entry)
    {
        if (IsNew3DS()) {
            Process::Write32(0x0C31B684, resultmoney);
        }
        else {
            Process::Write32(0x0871B684, resultmoney);
        }
    }

    void YW3_BattleResultMoney_Settings(MenuEntry *entry)
    {
        Keyboard keyboard("バトル後獲得お金変更\n\n16進数で入力してください");
        keyboard.Open(resultmoney);
    }

    void YW3_Gasha(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("ガシャ回数変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C325A88, value);
                Process::Write8(0x0C325A90, value);
            }
            else {
                Process::Write8(0x08725A88, value);
                Process::Write8(0x08725A90, value);
            }
        }
    }

    void YW3_DownSpeed(MenuEntry *entry)
    {
        if (IsNew3DS()) {
            Process::Write8(0x0C4D57D0, 0x01);
        }
        else {
            Process::Write8(0x088D57D0, 0x01);
        }
    }

    void YW3_SkyWalk(MenuEntry *entry)
    {
        if (IsNew3DS()) {
            Process::Write32(0x0C48D384, 0x00000000);
            Process::Write32(0x0C48D498, 0x0000007F);
        }
        else {
            Process::Write32(0x0888D384, 0x00000000);
            Process::Write32(0x0888D498, 0x0000007F);
        }
    }

    void YW3_Item98(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00501508, 0xE3A01062);
        }
        else {
            Process::Write32(0x00501508, 0xE3510000);
        }
    }

    void YW3_Minigame9999Point_treasure(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0045B474, 0xE3A00C27);
            Process::Write32(0x0045B478, 0xE280000F);
        }
        else {
            Process::Write32(0x0045B474, 0xE1D706B8);
            Process::Write32(0x0045B478, 0xE0800005);
        }
    }

    void YW3_Coin100_treasure(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0038C7A8, 0xE1A00001);
        }
        else {
            Process::Write32(0x0038C7A8, 0xC1A00001);
        }
    }

    void YW3_TreasureRank(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("トレジャーランク変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C331400, value);
            }
            else {
                Process::Write8(0x08731400, value);
            }
        }
    }

    void YW3_KoshikiRank(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("公式バトルランク変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C32E01F, value);
            }
            else {
                Process::Write8(0x0872E01F, value);
            }
        }
    }

    void YW3_KoshikiLate(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("公式バトルレート変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C33055A, value);
            }
            else {
                Process::Write8(0x0873055A, value);
            }
        }
    }

    void YW3_KoshikiRenshou(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("公式バトル連勝記録変更\n\n16進数で入力してください");
        if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C330569, value);
            }
            else {
                Process::Write8(0x08730569, value);
            }
        }
    }

    void YW3_WideCamera(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0016D21C, 0x3F800000);
        }
        else {
            Process::Write32(0x0016D21C, 0x40000000);
        }
    }

    void YW3_TPSCameraMove(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0070F2B4, 0xE3A010FF);
            Process::Write32(0x0070F2CC, 0xE3A010FF);
            Process::Write32(0x0070F2F8, 0xE3A010FF);
            Process::Write32(0x0070F334, 0xE3A010FF);
            Process::Write32(0x0071282C, 0xE3A010FF);
            Process::Write32(0x00712844, 0xE3A010FF);
            Process::Write32(0x0071289C, 0xE3A010FF);
            Process::Write32(0x007128D0, 0xE3A010FF);
            if (IsNew3DS()) {
                PointerWrite32(0x0C9DAB5C, 0x6F8, 0xCF490FDB);
                PointerWrite32(0x0C9DAB5C, 0x6FC, 0x4F490FDB);
            }
            else {
                PointerWrite32(0x08DDAB5C, 0x6F8, 0xCF490FDB);
                PointerWrite32(0x08DDAB5C, 0x6FC, 0x4F490FDB);
            }
        }
        else {
            Process::Write32(0x0070F2B4, 0xE3A0100A);
            Process::Write32(0x0070F2CC, 0xE3A0100B);
            Process::Write32(0x0070F2F8, 0xE3A0100A);
            Process::Write32(0x0070F334, 0xE3A0100B);
            Process::Write32(0x0071282C, 0xE3A0100A);
            Process::Write32(0x00712844, 0xE3A0100B);
            Process::Write32(0x0071289C, 0xE3A0100A);
            Process::Write32(0x007128D0, 0xE3A0100B);
            if (IsNew3DS()) {
                PointerWrite32(0x0C9DAB5C, 0x6F8, 0xBF490FDB);
                PointerWrite32(0x0C9DAB5C, 0x6FC, 0x3F490FDB);
            }
            else {
                PointerWrite32(0x08DDAB5C, 0x6F8, 0xBF490FDB);
                PointerWrite32(0x08DDAB5C, 0x6FC, 0x3F490FDB);
            }
        }
        u32 coord_x, coord_y;
        if (Controller::IsKeysPressed(R)) {
            if (IsSukiyaki()) {
                if (IsNew3DS()) {
                    Process::Read32(0x0C4F09BC, coord_x);
                    Process::Read32(0x0C4F09C4, coord_y);
                }
                else {
                    Process::Read32(0x088F09BC, coord_x);
                    Process::Read32(0x088F09C4, coord_y);
                }
            }
            else {
                if (IsNew3DS()) {
                    Process::Read32(0x0C5004BC, coord_x);
                    Process::Read32(0x0C5004C4, coord_y);
                }
                else {
                    Process::Read32(0x089004BC, coord_x);
                    Process::Read32(0x089004C4, coord_y);
                }
            }
        }
        else if (Controller::IsKeysDown(R)) {
            if (IsSukiyaki()) {
                if (IsNew3DS()) {
                    Process::Write32(0x0C4F09BC, coord_x);
                    Process::Write32(0x0C4F09C4, coord_y);
                }
                else {
                    Process::Write32(0x088F09BC, coord_x);
                    Process::Write32(0x088F09C4, coord_y);
                }
            }
            else {
                if (IsNew3DS()) {
                    Process::Write32(0x0C5004BC, coord_x);
                    Process::Write32(0x0C5004C4, coord_y);
                }
                else {
                    Process::Write32(0x089004BC, coord_x);
                    Process::Write32(0x089004C4, coord_y);
                }
            }
            
            float value;
            if (Controller::IsKeysDown(CPadUp)) {
                if (IsNew3DS()) {
                    value = PointerReadFloat(0x0C9DAB5C, 0x6E0);
                    PointerWriteFloat(0x0C9DAB5C, 0x6E0, value + 0.125);
                }
                else {
                    value = PointerReadFloat(0x08DDAB5C, 0x6E0);
                    PointerWriteFloat(0x08DDAB5C, 0x6E0, value + 0.125);
                }
            }
            if (Controller::IsKeysDown(CPadDown)) {
                if (IsNew3DS()) {
                    value = PointerReadFloat(0x0C9DAB5C, 0x6E0);
                    PointerWriteFloat(0x0C9DAB5C, 0x6E0, value - 0.125);
                }
                else {
                    value = PointerReadFloat(0x08DDAB5C, 0x6E0);
                    PointerWriteFloat(0x08DDAB5C, 0x6E0, value - 0.125);
                }
            }
            if (Controller::IsKeysDown(CPadLeft)) {
                if (IsNew3DS()) {
                    value = PointerReadFloat(0x0C9DAB5C, 0x6DC);
                    PointerWriteFloat(0x0C9DAB5C, 0x6DC, value - 0.125);
                }
                else {
                    value = PointerReadFloat(0x08DDAB5C, 0x6DC);
                    PointerWriteFloat(0x08DDAB5C, 0x6DC, value - 0.125);
                }
            }
            if (Controller::IsKeysDown(CPadRight)) {
                if (IsNew3DS()) {
                    value = PointerReadFloat(0x0C9DAB5C, 0x6DC);
                    PointerWriteFloat(0x0C9DAB5C, 0x6DC, value + 0.125);
                }
                else {
                    value = PointerReadFloat(0x08DDAB5C, 0x6DC);
                    PointerWriteFloat(0x08DDAB5C, 0x6DC, value + 0.125);
                }
            }
        }
    }

    void YW3_SaveCoordinate(MenuEntry *entry)
	{
        Keyboard keyboard("位置セーブ&リストア");
        std::vector < std::string > option =
        {
            "位置セーブ", "位置リストア"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        u32 coord_x, coord_y, coord_z;
        if (userchoice == 0) {
			if (IsSukiyaki()) {
                if (IsNew3DS()) {
                    Process::Read32(0x0C4F09C4, coord_x);
                    Process::Read32(0x0C4F09BC, coord_y);
                    Process::Read32(0x0C4F09C0, coord_z);
                }
                else {
                    Process::Read32(0x088F09C4, coord_x);
                    Process::Read32(0x088F09BC, coord_y);
                    Process::Read32(0x088F09C0, coord_z);
                }
            }
            else {
                if (IsNew3DS()) {
                    Process::Read32(0x0C5004C4, coord_x);
                    Process::Read32(0x0C5004BC, coord_y);
                    Process::Read32(0x0C5004C0, coord_z);
                }
                else {
                    Process::Read32(0x089004C4, coord_x);
                    Process::Read32(0x089004BC, coord_y);
                    Process::Read32(0x089004C0, coord_z);
                }
            }
		}
		if (userchoice == 1) {
            if (IsSukiyaki()) {
                if (IsNew3DS()) {
                    Process::Write32(0x0C4F09C4, coord_x);
                    Process::Write32(0x0C4F09BC, coord_y);
                    Process::Write32(0x0C4F09C0, coord_z);
                }
                else {
                    Process::Write32(0x088F09C4, coord_x);
                    Process::Write32(0x088F09BC, coord_y);
                    Process::Write32(0x088F09C0, coord_z);
                }
            }
            else {
                if (IsNew3DS()) {
                    Process::Write32(0x0C5004C4, coord_x);
                    Process::Write32(0x0C5004BC, coord_y);
                    Process::Write32(0x0C5004C0, coord_z);
                }
                else {
                    Process::Write32(0x089004C4, coord_x);
                    Process::Write32(0x089004BC, coord_y);
                    Process::Write32(0x089004C0, coord_z);
                }
            }
		}
	}

    void YW3_CameraZoom(MenuEntry *entry)
	{
        float value;
        if (Controller::IsKeysDown(entry->Hotkeys[0].GetKeys())) {
            if (IsNew3DS()) {
                value = PointerReadFloat(0x0C9DAB5C, 0x6E4);
                PointerWriteFloat(0x0C9DAB5C, 0x6E4, value + 1.5);
            }
            else {
                value = PointerReadFloat(0x08DDAB5C, 0x6E4);
                PointerWriteFloat(0x08DDAB5C, 0x6E4, value + 1.5);
            }
        }
        if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys())) {
            if (IsNew3DS()) {
                value = PointerReadFloat(0x0C9DAB5C, 0x6E4);
                PointerWriteFloat(0x0C9DAB5C, 0x6E4, value - 1.5);
            }
            else {
                value = PointerReadFloat(0x08DDAB5C, 0x6E4);
                PointerWriteFloat(0x08DDAB5C, 0x6E4, value - 1.5);
            }
        }
	}
}