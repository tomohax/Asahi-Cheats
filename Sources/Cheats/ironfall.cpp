//TITLE: IRONFALL Invation
//TITLEID: 000400000017D000
//PROCESSNAME: Ironfall

#include <cheats.hpp>

namespace CTRPluginFramework
{
	void Ironfall_InfinityBullet(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00117900, 0xE3A06301);
        }
        else {
            Process::Write32(0x00117900, 0xE0800101);
        }
    }

    void Ironfall_WallThrough(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x001FE8FC, 0xE2400E11);
        }
        else {
            Process::Write32(0x001FE8FC, 0xE2800E11);
        }
    }

    void Ironfall_FishEye_Lens(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0014DF54, 0xC0000000);
        }
        else {
            Process::Write32(0x0014DF54, 0xBF800000);
        }
    }

    void Ironfall_CoordinateMovement(MenuEntry *entry)
	{
        u32 pointer;
		float coord_x, coord_y;
        Process::Read32(0x0034B5CC, pointer);
        if(Controller::IsKeysDown(Y + DPadUp))
        {
            Process::ReadFloat(pointer + 0x118, coord_x);
            coord_x = coord_x - 3;
            Process::WriteFloat(pointer + 0x118, coord_x);
        }
        if(Controller::IsKeysDown(Y + DPadDown))
        {
            Process::ReadFloat(pointer + 0x118, coord_x);
            coord_x = coord_x + 3;
            Process::WriteFloat(pointer + 0x118, coord_x);
        }
        if(Controller::IsKeysDown(Y + DPadLeft))
        {
            Process::ReadFloat(pointer + 0x110, coord_y);
            coord_y = coord_y - 3;
            Process::WriteFloat(pointer + 0x110, coord_y);
        }
        if(Controller::IsKeysDown(Y + DPadRight))
        {
            Process::ReadFloat(pointer + 0x110, coord_y);
            coord_y = coord_y + 3;
            Process::WriteFloat(pointer + 0x110, coord_y);
        }
    }

    void Ironfall_MoonJump(MenuEntry *entry)
	{
        u32 pointer;
		float coord_z;
        Process::Read32(0x0034B5CC, pointer);
        if(Controller::IsKeysDown(L + DPadUp))
        {
            Process::ReadFloat(pointer + 0x114, coord_z);
            coord_z = coord_z + 5;
            Process::WriteFloat(pointer + 0x114, coord_z);
        }
        if(Controller::IsKeysDown(L + DPadDown))
        {
            Process::ReadFloat(pointer + 0x114, coord_z);
            coord_z = coord_z - 5;
            Process::WriteFloat(pointer + 0x114, coord_z);
        }
    }
}