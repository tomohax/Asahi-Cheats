#include <cheats.hpp>

namespace	CTRPluginFramework
{	
	//------------------------------
	//コード実行(4Byte)
	//------------------------------
	void execution_4Byte()
	{
		u32 address;
		u32 value;
		Sleep(Milliseconds(100.0f));
		Keyboard keyboard("サブメニュー -> コード実行 -> コード実行(4Byte)\n\nアドレスを入力してください。");
		if (keyboard.Open(address) != -1)
		{
			Sleep(Milliseconds(100.0f));
			Keyboard keyboard("サブメニュー -> コード実行 -> コード実行(4Byte)\n\n値を入力してください。");
			if (keyboard.Open(value) != -1)
			{
				Process::Write32(address,value);
			}
		}
	}
	
	//------------------------------
	//コード実行(2Byte)
	//------------------------------
	void execution_2Byte()
	{
		u32 address;
		u16 value;
		Sleep(Milliseconds(100.0f));
		Keyboard keyboard("サブメニュー -> コード実行 -> コード実行(2Byte)\n\nアドレスを入力してください。");
		if (keyboard.Open(address) != -1)
		{
			Sleep(Milliseconds(100.0f));
			Keyboard keyboard("サブメニュー -> コード実行 -> コード実行(2Byte)\n\n値を入力してください。");
			if (keyboard.Open(value) != -1)
			{
				Process::Write16(address,value);
			}
		}
	}

	//------------------------------
	//コード実行(1Byte)
	//------------------------------
	void execution_1Byte()
	{
		u32 address;
		u8 value;
		Sleep(Milliseconds(100.0f));
		Keyboard keyboard("サブメニュー -> コード実行 -> コード実行(1Byte)\n\nアドレスを入力してください。");
		if (keyboard.Open(address) != -1)
		{
			Sleep(Milliseconds(100.0f));
			Keyboard keyboard("サブメニュー -> コード実行 -> コード実行(1Byte)\n\n値を入力してください。");
			if (keyboard.Open(value) != -1)
			{
				Process::Write8(address,value);
			}
		}
	}

	//------------------------------
	//コード実行(Float)
	//------------------------------
	void execution_Float()
	{
		u32 address;
		float value;
		Sleep(Milliseconds(100.0f));
		Keyboard keyboard("サブメニュー -> コード実行 -> コード実行(Float)\n\nアドレスを入力してください。");
		if (keyboard.Open(address) != -1)
		{
			Sleep(Milliseconds(100.0f));
			Keyboard keyboard("サブメニュー -> コード実行 -> コード実行(Float)\n\n値を入力してください。");
			if (keyboard.Open(value) != -1)
			{
				Process::WriteFloat(address,value);
			}
		}
	}

	//------------------------------
	//コード実行(Double)
	//------------------------------
	void execution_Double()
	{
		u32 address;
		double value;
		Sleep(Milliseconds(100.0f));
		Keyboard keyboard("サブメニュー -> コード実行 -> コード実行(Double)\n\nアドレスを入力してください。");
		if (keyboard.Open(address) != -1)
		{
			Sleep(Milliseconds(100.0f));
			Keyboard keyboard("サブメニュー -> コード実行 -> コード実行(Double)\n\n値を入力してください。");
			if (keyboard.Open(value) != -1)
			{
				Process::WriteDouble(address,value);
			}
		}
	}

	//------------------------------
	//コード実行(String)
	//------------------------------
	void execution_String()
	{
		u32 address;
		std::string value;
		Sleep(Milliseconds(100.0f));
		Keyboard keyboard("サブメニュー -> コード実行 -> コード実行(String)\n\nアドレスを入力してください。");
		if (keyboard.Open(address) != -1)
		{
			Sleep(Milliseconds(100.0f));
			Keyboard keyboard("サブメニュー -> コード実行 -> コード実行(String)\n\n値を入力してください。");
			if (keyboard.Open(value) != -1)
			{
				Process::WriteString(address,value);
			}
		}
	}

    //------------------------------
	//OSDテスト
	//------------------------------
	void OSD_Test()
    {
		Sleep(Milliseconds(100.0f));
        Keyboard keyboard("サブメニュー -> コード実行 -> OSDテスト\n\n表示したい文字を入力してください\n※アルファベット・数字・一部の記号のみ対応。");
        std::string text;

        if (keyboard.Open(text) != -1)
        {
			OSD::Notify(text);
        }
    }
	
	//------------------------------
	//MessasgeBoxテスト
	//------------------------------
	void MessageBox_Test()
    {
		Sleep(Milliseconds(100.0f));
        Keyboard keyboard("サブメニュー -> コード実行 -> MessageBoxテスト\n\n表示したい文字を入力してください");
        std::string text;

        if (keyboard.Open(text) != -1)
        {
			Sleep(Milliseconds(100.0f));
			(MessageBox(text))();
        }
    }

	void SubMenu(MenuEntry *entry)
    {
		if(Controller::IsKeysPressed(entry->Hotkeys[0].GetKeys()))
		{
			Sleep(Milliseconds(100.0f));
			Keyboard keyboard("サブメニュー",
			{
				"コード実行", "テスト"
			});
			int userchoice = keyboard.Open();
			if(userchoice == 0)
			{
				Sleep(Milliseconds(100.0f));
				Keyboard keyboard("サブメニュー -> コード実行",
				{
					"コード実行(4Byte)", "コード実行(2Byte)", "コード実行(1Byte)", "コード実行(Float)", "コード実行(Double)", "コード実行(String)"
				});
				int userchoice = keyboard.Open();
				if(userchoice == 0){execution_4Byte();}
				if(userchoice == 1){execution_2Byte();}
				if(userchoice == 2){execution_1Byte();}
				if(userchoice == 3){execution_Float();}
				if(userchoice == 4){execution_Double();}
				if(userchoice == 5){execution_String();}
			}
			if(userchoice == 1)
			{
				Sleep(Milliseconds(100.0f));
				Keyboard keyboard("サブメニュー -> コード閲覧",
				{
					"OSDテスト", "MessageBoxテスト" 
				});
				int userchoice = keyboard.Open();
				if(userchoice == 0){OSD_Test();}
				if(userchoice == 1){MessageBox_Test();}
			}
		}
    }
}