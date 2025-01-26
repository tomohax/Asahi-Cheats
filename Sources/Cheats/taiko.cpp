//TITLE: 太鼓の達人 ドコドン! ミステリーアドベンチャー
//TITLEID: 0004000000190E00
//PROCESSNAME: TAIKO

#include <cheats.hpp>

namespace	CTRPluginFramework
{	
	void TAIKO_ResultAllGood(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0020C274, 0xE3A00000);
            Process::Write32(0x0037342C, 0xE3A00000);
        }
        else {
            Process::Write32(0x0020C274, 0xE1D000D8);
            Process::Write32(0x0037342C, 0xE1D000D8);
        }
    }

    void TAIKO_AllCombo(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0020C234, 0xE3A01001);
        }
        else {
            Process::Write32(0x0020C234, 0xE1D110D8);
        }
    }

    void TAIKO_Soulfullafterchange(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0037707C, 0xEA011ADF);
            Process::Write32(0x003BDC00, 0xED9F0A00);
            Process::Write32(0x003BDC04, 0xEAFEE51D);
            Process::Write32(0x003BDC08, 0x461C4000);
        }
        else {
            Process::Write32(0x0037707C, 0xEE300A20);
            Process::Write32(0x003BDC00, 0x00000000);
            Process::Write32(0x003BDC04, 0x00000000);
            Process::Write32(0x003BDC08, 0x00000000);
        }
    }

    void TAIKO_AllStump(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0024BF6C, 0xEA05C72F);
            Process::Write32(0x0037036C, 0xEA013627);
            Process::Write32(0x003BDC10, 0xE3A070FF);
            Process::Write32(0x003BDC14, 0xE5C170AA);
            Process::Write32(0x003BDC18, 0xE1A07006);
            Process::Write32(0x003BDC1C, 0xE5D110AA);
            Process::Write32(0x003BDC20, 0xEAFEC9D2);
            Process::Write32(0x003BDC30, 0xE3A030FF);
            Process::Write32(0x003BDC34, 0xE5C130DD);
            Process::Write32(0x003BDC38, 0xE5D110DD);
            Process::Write32(0x003BDC3C, 0xEAFA38CB);
        }
        else {
            Process::Write32(0x0024BF6C, 0xE5D110DD);
            Process::Write32(0x0037036C, 0xE5D110AA);
            Process::Write32(0x003BDC10, 0x00000000);
            Process::Write32(0x003BDC14, 0x00000000);
            Process::Write32(0x003BDC18, 0x00000000);
            Process::Write32(0x003BDC1C, 0x00000000);
            Process::Write32(0x003BDC20, 0x00000000);
            Process::Write32(0x0003BDC30, 0x00000000);
            Process::Write32(0x003BDC34, 0x00000000);
            Process::Write32(0x003BDC38, 0x00000000);
            Process::Write32(0x003BDC3C, 0x00000000);
        }
    }

    void TAIKO_AllTrimble(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00367E38, 0xEA015780);
            Process::Write32(0x003BDC40, 0xE3A000FF);
            Process::Write32(0x003BDC44, 0xE5C301E2);
            Process::Write32(0x003BDC48, 0xE5D331E2);
            Process::Write32(0x003BDC4C, 0xEAFEA87A);
        }
        else {
            Process::Write32(0x00367E38, 0xE5D331E2);
            Process::Write32(0x003BDC40, 0x00000000);
            Process::Write32(0x003BDC44, 0x00000000);
            Process::Write32(0x003BDC48, 0x00000000);
            Process::Write32(0x003BDC4C, 0x00000000);
        }
    }
}