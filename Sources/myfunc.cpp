#include <cheats.hpp>

namespace CTRPluginFramework
{
    bool IsNew3DS()
    {
        u8 ModelType;
        CFGU_GetSystemModel(&ModelType);
        if (ModelType == 0x00 || ModelType == 0x01 || ModelType == 0x03) {
            return false;
        }
        else {
            return true;
        }
    }

    void PointerWrite32(u32 baseaddress, u32 add_value, u32 value)
    {
        u32 basevalue;
        Process::Read32(baseaddress, basevalue);
		if (basevalue != 0x00000000) {
			Process::Write32(basevalue + add_value, value);
		}
    }

    void PointerWrite16(u32 baseaddress, u32 add_value, u16 value)
    {
        u32 basevalue;
        Process::Read32(baseaddress, basevalue);
		if (basevalue != 0x00000000) {
	        Process::Write16(basevalue + add_value, value);
		}
    }

    void PointerWrite8(u32 baseaddress, u32 add_value, u8 value)
    {
        u32 basevalue;
        Process::Read32(baseaddress, basevalue);
		if (basevalue != 0x00000000) {
        	Process::Write8(basevalue + add_value, value);
		}
    }

    void PointerWriteFloat(u32 baseaddress, u32 add_value, float value)
    {
        u32 basevalue;
        Process::Read32(baseaddress, basevalue);
		if (basevalue != 0x00000000) {
        	Process::WriteFloat(basevalue + add_value, value);
		}
    }

    u32 PointerRead32(u32 baseaddress, u32 add_value)
    {
        u32 basevalue, value;
        Process::Read32(baseaddress, basevalue);
		if (basevalue != 0x00000000) {
        	Process::Read32(basevalue + add_value, value);
        	return value;
		}
		else {
			return 0x00000000;
		}
    }

    u16 PointerRead16(u32 baseaddress, u32 add_value)
    {
        u32 basevalue;
        u16 value;
        Process::Read32(baseaddress, basevalue);
		if (basevalue != 0x00000000) {
			Process::Read16(basevalue + add_value, value);
			return value;
		}
		else {
			return 0x0000;
		}
    }

    u8 PointerRead8(u32 baseaddress, u32 add_value)
    {
        u32 basevalue;
        u8 value;
        Process::Read32(baseaddress, basevalue);
		if (basevalue != 0x00000000) {
			Process::Read8(basevalue + add_value, value);
			return value;
		}
		else {
			return 0x00;
		}
    }

    float PointerReadFloat(u32 baseaddress, u32 add_value)
    {
        u32 basevalue;
        float value;
        Process::Read32(baseaddress, basevalue);
		if (basevalue != 0x00000000) {
			Process::ReadFloat(basevalue + add_value, value);
			return value;
		}
		else {
			return 0;
		}
    }
}