//TITLE: とびだす! にゃんこ大戦争
//TITLEID: 000400000015DA00
//PROCESSNAME: NYANKO-R

#include <cheats.hpp>

namespace	CTRPluginFramework
{	
	void NYANKOR_touitu(MenuEntry *entry)
	{
		Keyboard keyboard("統一力変更");
        std::vector < std::string > option =
        {
            "100",
			"変更"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
		if(userchoice == 0)
		{
			Process::Write32(0x08103B90,0x00000064);
			return;
		}
        if(userchoice == 1)
		{
			Keyboard
			keyboard("統一力変更\n16進数で入力してください。");
			u32 a;

			if (keyboard.Open (a) != -1)
			{
				Process::Write32(0x08103B90, a);
			}
		}
	}
		
	void NYANKOR_rapidnyankohou(MenuEntry *entry)
	{
		Process::Write32(0x0810992C, 0x00000000);
	}
	
	void NYANKOR_speedup_max(MenuEntry *entry)
	{
		Process::Write32(0x08105D4C, 0x0000270F);
	}
	
	void NYANKOR_treasurerader_max(MenuEntry *entry)
	{
		Process::Write32(0x08105D50, 0x0000270F);
	}
	
	void NYANKOR_nekobon_max(MenuEntry *entry)
	{
		Process::Write32(0x08105D54, 0x0000270F);
	}
	
	void NYANKOR_nyanputer_max(MenuEntry *entry)
	{
		Process::Write32(0x08105D58, 0x0000270F);
	}
	
	void NYANKOR_xpup_max(MenuEntry *entry)
	{
		Process::Write32(0x08105D5C, 0x0000270F);
	}
	
	void NYANKOR_sunyaiper_max(MenuEntry *entry)
	{
		Process::Write32(0x08105D60, 0x0000270F);
	}
	
	void NYANKOR_hp_max(MenuEntry *entry)
	{
		Process::Write32(0x0810991C, 0x000F423F);
	}
	
	void NYANKOR_aitehp_0(MenuEntry *entry)
	{
		Process::Write32(0x0810D348, 0x00000000);
	}

	void NYANKOR_MoneyMax(MenuEntry *entry)
	{
		Process::Write32(0x08109620, 0x0FFFFFF0);
		Process::Write32(0x08109624, 0x0FFFFFF0);
	}
}