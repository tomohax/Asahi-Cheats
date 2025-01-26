#include <cheats.hpp>
#include <BottomBackground.hpp>
#include <TopBackground.hpp>

namespace CTRPluginFramework
{
	bool DEBUG_BUILD = false;

	#define VERSION_A 2
    #define VERSION_B 0
    #define VERSION_C 0
	std::string VERSION_STRING = Utils::Format("%d.%d.%d", VERSION_A, VERSION_B, VERSION_C);
	std::string BUILD_DATETIME = Utils::Format("%s %s", __DATE__, __TIME__);

	static const std::string about =
		"Asahi-Cheats\n"
		"Version: " + VERSION_STRING + "\n"
		"BuildDateTime: " + BUILD_DATETIME + "\n"
		"\n"
        "-----Developer-----\n"
		"[Graycie]\n"
		"    HP: https://graycie.tk/\n"
		"    Twitter: @Graycie_X\n"
		"    Discord: @Graycie#0384\n"
		"---------------------\n"
		"\n"
		"-----Credit-----\n"
		"[〆Keito様]\n"
		"[Sky様]\n"
		"[だいち村長様]\n"
		"[DEGU村長様]\n"
		"[ひでごん様]\n"
		"[Bom様]\n"
		"[ぽんぽこ様]\n"
		"[〆ゆー様]\n"
		"[陽太様]\n"
		"[Redo様]\n"
		"----------------\n"
		"\n"
		"-----対応タイトル一覧-----\n"
		"[マリオカート7]\n"
		"0004000000030600\n"
		"[妖怪ウォッチ2 真打]\n"
		"0004000000155100\n"
		"[とびだす! にゃんこ大戦争]\n"
		"000400000015DA00\n"
		"[妖怪ウォッチバスターズ 白犬隊]\n"
		"000400000016C600\n"
		"[妖怪ウォッチバスターズ 赤猫団]\n"
		"000400000016C700\n"
		"[IRONFALL Invasion]\n"
		"000400000017D000\n"
		"[太鼓の達人 ドコドン! ミステリーアドベンチャー]\n"
		"0004000000190E00\n"
		"[妖怪ウォッチ3 スシ]\n"
		"0004000000191000\n"
		"[妖怪ウォッチ3 テンプラ]\n"
		"0004000000191100\n"
		"[妖怪ウォッチ3 スキヤキ]\n"
		"00040000001AF400\n"
		"-------------------------\n"
		"\n"
		"-----備考-----\n"
		"開発環境:OLD3DS\n"
		"・複数セーブデータがある場合\n"
		"    1つ目で動作確認しています。\n"
		"・逆サーチを防ぐために\n"
		"    バイナリエディタ機能,サーチ機能を\n"
		"    無効化しています。\n"
		"・3gxの容量が極端に多いのは\n"
		"    プラグインにCTRPF背景を入れているからです。\n"
		"--------------\n"
		"\n"
		"libctru\n"
		"CTRPluginFramework";
		
	//↓↓↓↓↓消さないで↓↓↓↓↓
    static MenuEntry *EntryWithHotkey(MenuEntry *entry, const Hotkey &hotkey)
    {
        if (entry != nullptr)
        {
            entry->Hotkeys += hotkey;
            entry->SetArg(new std::string(entry->Name()));
            entry->Name() += " " + hotkey.ToString();
            entry->Hotkeys.OnHotkeyChangeCallback([](MenuEntry *entry, int index)
            {
                std::string *name = reinterpret_cast<std::string *>(entry->GetArg());

                entry->Name() = *name + " " + entry->Hotkeys[0].ToString();
            });
        }

        return entry;
    }

    static MenuEntry *EntryWithHotkey(MenuEntry *entry, const std::vector<Hotkey> &hotkeys)
    {
        if (entry != nullptr)
        {
            for (const Hotkey &hotkey : hotkeys)
                entry->Hotkeys += hotkey;
        }

        return entry;
    }

	static MenuEntry *EnableEntry(MenuEntry *entry)
    {
        if (entry != nullptr)
        {
            entry->Enable();
        }
        return entry;
    }

	static MenuEntry *TopSeparator(MenuEntry *entry)
    {
        entry->UseTopSeparator();
        return entry;
    }

	static MenuEntry *BottomSeparator(MenuEntry *entry)
    {
        entry->UseBottomSeparator();
        return entry;
    }
	//↑↑↑↑↑消さないで↑↑↑↑↑

	// This patch the NFC disabling the touchscreen when scanning an amiibo, which prevents ctrpf to be used
    static void    ToggleTouchscreenForceOn(void)
    {
        static u32 original = 0;
        static u32 *patchAddress = nullptr;

        if (patchAddress && original)
        {
            *patchAddress = original;
            return;
        }

        static const std::vector<u32> pattern =
        {
            0xE59F10C0, 0xE5840004, 0xE5841000, 0xE5DD0000,
            0xE5C40008, 0xE28DD03C, 0xE8BD80F0, 0xE5D51001,
            0xE1D400D4, 0xE3510003, 0x159F0034, 0x1A000003
        };

        Result  res;
        Handle  processHandle;
        s64     textTotalSize = 0;
        s64     startAddress = 0;
        u32 *   found;

        if (R_FAILED(svcOpenProcess(&processHandle, 16)))
            return;

        svcGetProcessInfo(&textTotalSize, processHandle, 0x10002);
        svcGetProcessInfo(&startAddress, processHandle, 0x10005);
        if(R_FAILED(svcMapProcessMemoryEx(CUR_PROCESS_HANDLE, 0x14000000, processHandle, (u32)startAddress, textTotalSize)))
            goto exit;

        found = (u32 *)Utils::Search<u32>(0x14000000, (u32)textTotalSize, pattern);

        if (found != nullptr)
        {
            original = found[13];
            patchAddress = (u32 *)PA_FROM_VA((found + 13));
            found[13] = 0xE1A00000;
        }

        svcUnmapProcessMemoryEx(CUR_PROCESS_HANDLE, 0x14000000, textTotalSize);
exit:
        svcCloseHandle(processHandle);
    }

    // This function is called before main and before the game starts
    // Useful to do code edits safely
    void    PatchProcess(FwkSettings &settings)
    {
		if (!DEBUG_BUILD) {
			settings.AllowSearchEngine = false;
		}

		FwkSettings::SetTopScreenBackground((void*) TopBackground);
        FwkSettings::SetBottomScreenBackground((void*) BottomBackground);
		ToggleTouchscreenForceOn();
    }

    // This function is called when the process exits
    // Useful to save settings, undo patchs or clean up things
    void    OnProcessExit(void)
    {
        ToggleTouchscreenForceOn();
    }

	MenuFolder *Folder_1, *Folder_1_1, *Folder_1_2, *Folder_1_3, *Folder_1_4, *Folder_1_5;
	MenuFolder *Folder_2, *Folder_2_1, *Folder_2_2, *Folder_2_3, *Folder_2_4, *Folder_2_5;
	MenuFolder *Folder_3, *Folder_3_1, *Folder_3_2, *Folder_3_3, *Folder_3_4, *Folder_3_5;
	MenuFolder *Folder_4, *Folder_4_1, *Folder_4_2, *Folder_4_3, *Folder_4_4, *Folder_4_5;
	MenuFolder *Folder_5, *Folder_5_1, *Folder_5_2, *Folder_5_3, *Folder_5_4, *Folder_5_5;
	MenuFolder *Folder_6, *Folder_6_1, *Folder_6_2, *Folder_6_3, *Folder_6_4, *Folder_6_5;
	MenuFolder *Folder_7, *Folder_7_1, *Folder_7_2, *Folder_7_3, *Folder_7_4, *Folder_7_5;
	MenuFolder *Folder_8, *Folder_8_1, *Folder_8_2, *Folder_8_3, *Folder_8_4, *Folder_8_5;
	MenuFolder *Folder_9, *Folder_9_1, *Folder_9_2, *Folder_9_3, *Folder_9_4, *Folder_9_5;
	MenuFolder *Folder_10, *Folder_10_1, *Folder_10_2, *Folder_10_3, *Folder_10_4, *Folder_10_5;

	static void MARIOKAR_MENU(PluginMenu &menu)
	{
		MenuFolder *Folder_1 = new MenuFolder("Kart Codes");
		{
			*Folder_1 += new MenuEntry("Invincibility", MARIOKAR_Invincible, "You will be invincible. You will also appear blinking on other people's screens online.");
			*Folder_1 += new MenuEntry("Aimbot", MARIOKAR_Aimbot, "Your aim will be locked onto a specific player. Press D-Pad Up to increase player, and D-Pad Down to reset it.");
			*Folder_1 += new MenuEntry("Always Star Power", MARIOKAR_AlwaysStarPower, "You will always have star effects, such as invincibility and color.");
			*Folder_1 += new MenuEntry("Always Black Kart", MARIOKAR_AlwaysBlackKart, "Your kart will awlays be black as if you got bloopered.");
			*Folder_1 += new MenuEntry("Always Shocked", MARIOKAR_AlwaysShocked, "Your kart will always be small as if you got shocked.");
			*Folder_1 += new MenuEntry("Always Crushed", MARIOKAR_AlwaysCrushed, "Your kart will always be flat as if you got crushed. This is only visible on opponents screens online. On your screen, you'll appear normally.");
			*Folder_1 += new MenuEntry("Trick Anywhere", MARIOKAR_TrickAnywhere, "You will be able to perform a trick anywhere by pressing R.");
			*Folder_1 += new MenuEntry("Instant MiniTurbo", MARIOKAR_InstantMT, "You will instantly get red and blue MiniTurbos when drifting.");
			*Folder_1 += new MenuEntry("Huge Bunnyhop", MARIOKAR_HugeBunnyhop, "You will jump very high when hopping before a drift.");
			*Folder_1 += new MenuEntry("Size Changer", MARIOKAR_SizeChanger, "Your kart will constantly increase and decrease in size. Use D-Pad Left and D-Pad Right to change the speed at which your kart will change size. This code can cause problems sometimes.");
		}
		menu += Folder_1;
		
		MenuFolder *Folder_2 = new MenuFolder("Speed&Movement Codes");
		{
			*Folder_2 += new MenuEntry("200cc", MARIOKAR_TwoHundredCC, "You will go 200cc speeds. Restart the race after applying the code for the effect to take place.");
			*Folder_2 += new MenuEntry("500cc", MARIOKAR_FiveHundredCC, "You will go 500cc speeds. Restart the race after applying the code for the effect to take place.");
			*Folder_2 += new MenuEntry("Instant Acceleration", MARIOKAR_InstantAcceleration, "Your kart will instantly accelerate to the maximum speed when pressing A.");
			*Folder_2 += new MenuEntry("Instant Backwards Acceleration", MARIOKAR_InstantBackAcceleration, "Your kart will instantly accelerate to it's maximum reverse speed when pressing B.");
			*Folder_2 += new MenuEntry("Instant Stop", MARIOKAR_InstantStop, "Your kart will instantly come to a complete stop when pressing A+B.");
			*Folder_2 += new MenuEntry("Fast Reverse Speeds", MARIOKAR_FastReverse, "You will reverse at higher speeds than before when holding B.");
			*Folder_2 += new MenuEntry("Inside Drifing Kart", MARIOKAR_InsideDrift, "Your kart will drift inwards, like certain bikes did in Mario Kart Wii.");
			*Folder_2 += new MenuEntry("Stalking Hack", MARIOKAR_Stalking, "-Y + Right = Increase Player\n-Y + Left = Decrease Player\n-Y + Up = Stalk the player until code is disabled\n-Hold Y to stalk the player temporarily, release Y to stop stalking\n-Y + Down = Disable Code");
			*Folder_2 += new MenuEntry("Touch Screen Teleporter", MARIOKAR_TouchCode, "Touch the bottom screen or drag your stylus across it to warp your kart to that position on the map!");
			*Folder_2 += new MenuEntry("Moonjump", MARIOKAR_MoonJump, "-Start + R = Enable\n\nThis code will let you fly high.");
			*Folder_2 += new MenuEntry("Drive Anywhere", MARIOKAR_DriveAnywhere, "-Start = Disable\n-Select = Enable\n-Select + Up = Go Up\n-Select + Down = Go Down\n\nThis code is a remake of Supastarrio's code for MKDS.");
			*Folder_2 += new MenuEntry("Save Slot Teleporter", MARIOKAR_SaveSlotTeleporter, "-Start + X = Save Current Position\n-Start + Y = Load Saved Position");
		}
		menu += Folder_2;

		MenuFolder *Folder_3 = new MenuFolder("Item Codes");
		{
			*Folder_3 += new MenuEntry("Item Wheel", MARIOKAR_ItemWheel, "-X = Bullet\n-Y = Tanooki\n-Start = Blue Shell\n-Select = Lightning\n-D-Pad Left = Lucky 7\n-D-Pad Right = Red Shell\n-D-Pad Up = Green Shell\n-D-Pad Down = Bob-Omb");
			*Folder_3 += new MenuEntry("Always Have Certain Item", nullptr, MARIOKAR_SetItem, "You will be able to choose the item you want when exiting the menu.");
			*Folder_3 += new MenuEntry("Cycle Completely Random Item", MARIOKAR_RandomItems, "You will be constantly given a random item.");
			*Folder_3 += new MenuEntry("Truly Random Items", MARIOKAR_TrulyRandomItems, "Items will be completely random, regardless of your position. The bottom screen item icon will tell you the item you were supposed to recieve, while the top screen item icon will tell you the purely random item you recieved.");
			*Folder_3 += new MenuEntry("Drop Mushrooms", MARIOKAR_DropMushrooms, "This code replaces green shells with droppable mushrooms. Throw a 'green shell' to drop a mushroom.");
			*Folder_3 += new MenuEntry("Fast Blue Shell", MARIOKAR_FastBlueShell, "Blue shells will go very fast.");
			*Folder_3 += new MenuEntry("Stopped Blue Shell", MARIOKAR_StoppedBlueShell, "Blue shells will not move after being thrown.");
			*Folder_3 += new MenuEntry("Fast Green Shell", MARIOKAR_FastGreenShell, "Green shells will go very fast.");
			*Folder_3 += new MenuEntry("Stopped Green Shell", MARIOKAR_StoppedGreenShell, "Green shells will not move after being thrown.");
			*Folder_3 += new MenuEntry("Control Bullet", MARIOKAR_BulletControl, "You will be able to control your bullets.\n-Start + Right = Enable\n-Start + Left = Disable");
			*Folder_3 += new MenuEntry("Bullet Speed Modifier", MARIOKAR_BulletSpeed, "-X = Very Fast\n-B = Stopped\n-A = Normal Speed");
			*Folder_3 += new MenuEntry("Blue Shell Ride", MARIOKAR_BlueShellRide, "-D-Pad Left = Enable\nYou will warp to a blue shell and ride it.");
			*Folder_3 += new MenuEntry("Disable Star Music", MARIOKAR_DisableStarMusic, "The star music won't play when you're in a star.");
		}
		menu += Folder_3;

		MenuFolder *Folder_4 = new MenuFolder("Course Codes");
		{
			*Folder_4 += new MenuEntry("CPU Brawl", MARIOKAR_CpuBrawl, "The CPU will on top of each other, fighting.");
			*Folder_4 += new MenuEntry("Max Timer", MARIOKAR_MaxTimer, "The timer will freeze at 4:59.9xx.");
			*Folder_4 += new MenuEntry("Water Everywhere", MARIOKAR_WaterEverywhere, "You will always be underwater.");
		}
		menu += Folder_4;

		MenuFolder *Folder_5 = new MenuFolder("Menu&Other Codes");
		{
			*Folder_5 += new MenuEntry("No Countdown", MARIOKAR_NoCountdown, "You will be able to drive when the countdown normally would be happening.");
			*Folder_5 += new MenuEntry("Speedometer", MARIOKAR_SpeedMeter, "You will be able to see your current speed in your preferred unit.");
			*Folder_5 += new MenuEntry("Mii Dumper", nullptr, MARIOKAR_MiiDumper, "This code can dump any player's Mii from an online match. Follow the instructions on screen after enabling the code in an online lobby. If the room is not fully populated, certain buttons may be blank or contain previous player's names. You can dump previous players with no problem even if they're not in the room.");
			*Folder_5 += new MenuEntry("Disable First Person View", MARIOKAR_DisableFirstPersonView, "You will not be able to activate first person view by pressing Up on the D-Pad.");
			*Folder_5 += new MenuEntry("No Disconnect", MARIOKAR_NoDC, "You will not get disconnected unless the cause of the disconnection is an actual network problem.");
			*Folder_5 += new MenuEntry("Fast Game/Anti-Matrix", MARIOKAR_FastGame, "The game will move at a very fast speed. Unstable, use at your own risk!");
			*Folder_5 += new MenuEntry("Live Time Trial Ghost Replay", MARIOKAR_TimeTrialGhost, "This code will let you view any ghost. Please follow these steps:\n1. Activate this code and then enter the time trial with the ghost you want to view.\n2. Your kart will be out of bounds. Restart the race.\n3. Done! The code should be working.");
			*Folder_5 += new MenuEntry("VR Extender", MARIOKAR_VRExtender, "-Start = 999999\n-Select = 420000\n-D-Pad Down = 0\n-D-Pad Up = 696969\n-D-Pad Right = 666666\n-D-Pad Left = 777777");
			*Folder_5 += new MenuEntry("Set Custom VR", nullptr, MARIOKAR_SetVR, "A keyboard will come up when you exit the menu and you will be allowed to enter your desired VR, between 0 and 999999 (Be sure to enter values in hexadecimal)");
			*Folder_5 += new MenuEntry("Random VR", MARIOKAR_RandomVR, "A random VR value between 1 and 999999 will be generated.");
			*Folder_5 += new MenuEntry("Unlock Everything", MARIOKAR_UnlockEverything, "Everything will be unlocked. After enabling, save the game by completing a time trial or something, exit the game, and open it again. At this point everything should be permanently unlocked.");
		}
		menu += Folder_5;

		MenuFolder *Folder_6 = new MenuFolder("Custom Game Modes");
		{
			//*Folder_6 += new MenuEntry("Shine Thief", MARIOKAR_ShineTheif, MARIOKAR_shineTheif_note);
			//*Folder_6 += new MenuEntry("Tag", MARIOKAR_tagMode, MARIOKAR_TagMode_note);
			*Folder_6 += new MenuEntry("Elimination Mode", MARIOKAR_EliminationMode, "Every 30 seconds, the player in last place will be eliminated. The last player standing wins! This mode works best in rooms with more players.");
			*Folder_6 += new MenuEntry("Countdown Mode", MARIOKAR_CountdownMode, "You will have 2 minutes to race. Every time you hit a player with an item, your time will increase by 3 seconds. You will need to strategically gain more time while still being towards the front of the pack. The player in first place when everyone's time runs out wins!");
			*Folder_6 += new MenuEntry("Drivable 200cc", MARIOKAR_TwoHundredCCStable, "This version of 200cc has brake drifting by pressing B during drifts (also works in boosts and while in the air), and drifting at lower speeds and in off road. Items will also travel at speeds proprtional to the CC.");
			*Folder_6 += new MenuEntry("Drivable 500cc", MARIOKAR_FiveHundredCCStable, "This version of 500cc has brake drifting by pressing B during drifts (also works in boosts and while in the air), and drifting at lower speeds and in off road. Items will also travel at speeds proprtional to the CC.");
		}
		menu += Folder_6;

		MenuFolder *Folder_7 = new MenuFolder("Region&Flag Codes");
		{
			*Folder_7 += new MenuEntry("Set Custom Flag", nullptr, MARIOKAR_SetFlag, "A keyboard will come up when you exit the menu and you will be allowed to enter your desired flag ID (in hexadecimal). You can get these from the MK7 NTR Plugin GBAtemp thread.");
			*Folder_7 += new MenuEntry("Set Custom Globe Coordinates", nullptr, MARIOKAR_SetCoordinates, "A keyboard will come up when you exit the menu and you will be allowed to enter your desired coordinates. You can get these from the MK7 NTR Plugin GBAtemp thread.");
		}
		menu += Folder_7;
	}
	
	static void YW2_MENU(PluginMenu &menu)
	{
		MenuFolder *Folder_1 = new MenuFolder("移動系コード");
		{
			*Folder_1 += EntryWithHotkey(new MenuEntry("座標移動", YW2_CoordinateMovement),
			{
				Hotkey(Key::A + DPadUp, "上へ移動"),
				Hotkey(Key::A + DPadDown, "下へ移動"),
				Hotkey(Key::A + DPadLeft, "左へ移動"),
				Hotkey(Key::A + DPadRight, "右へ移動"),
			});
			*Folder_1 += EntryWithHotkey(new MenuEntry("ムーンジャンプ", YW2_MoonJump),
			{
				Hotkey(Key::B + DPadUp, "上へ移動"),
				Hotkey(Key::B + DPadDown, "下へ移動"),
			});
			*Folder_1 += EntryWithHotkey(new MenuEntry("壁貫通",YW2_WalkOver,"Keyを自分で設定できます"),
			{
				Hotkey(Key::L + DPadUp, "ON/OFF")
			});
			*Folder_1 += new MenuEntry("スピードハック", YW2_RunSpeed);
			*Folder_1 += new MenuEntry("スタミナ無限", YW2_InfinityStamina);
			*Folder_1 += new MenuEntry("プレイヤー状態変更", nullptr, YW2_Luminous);
			*Folder_1 += new MenuEntry("階段で自転車使用可能", YW2_BicycleStairs);
			*Folder_1 += new MenuEntry("落下速度", YW2_DownSpeed);
			*Folder_1 += new MenuEntry("空中歩行", YW2_SkyWalk);
			*Folder_1 += new MenuEntry("モーション変更", nullptr, YW2_Motion);
			*Folder_1 += new MenuEntry("エリアワープ", nullptr, YW2_AreaWarp);
			*Folder_1 += new MenuEntry("位置セーブ&リストア", nullptr, YW2_SaveCoordinate);
		}
		menu += Folder_1;
		
		MenuFolder *Folder_2 = new MenuFolder("バトルコード");
		{
			*Folder_2 += new MenuEntry("HP無限", YW2_HPInfinity);
			*Folder_2 += new MenuEntry("技無限", YW2_WazaInfinity);
			*Folder_2 += new MenuEntry("ワンヒットキル", YW2_OneHitKill);
			*Folder_2 += new MenuEntry("クリティカル確定", YW2_AttackCritical);
			*Folder_2 += new MenuEntry("ダメージ65535", YW2_Damage65535);
			*Folder_2 += new MenuEntry("全回避", YW2_AllAvoidance);
			*Folder_2 += new MenuEntry("とりつき無効", YW2_ToritsukiDisable);
			*Folder_2 += new MenuEntry("必ず友達になる", YW2_FriendChance);
		}
		menu += Folder_2;

		MenuFolder *Folder_3 = new MenuFolder("友達妖怪コード");
		{
			*Folder_3 += new MenuEntry("手持ち妖怪1 編集", nullptr, YW2_YokaiEditor1);
			*Folder_3 += new MenuEntry("手持ち妖怪2 編集", nullptr, YW2_YokaiEditor2);
			*Folder_3 += new MenuEntry("手持ち妖怪3 編集", nullptr, YW2_YokaiEditor3);
			*Folder_3 += new MenuEntry("手持ち妖怪4 編集", nullptr, YW2_YokaiEditor4);
			*Folder_3 += new MenuEntry("手持ち妖怪5 編集", nullptr, YW2_YokaiEditor5);
			*Folder_3 += new MenuEntry("手持ち妖怪6 編集", nullptr, YW2_YokaiEditor6);
		}
		menu += Folder_3;	

		MenuFolder *Folder_4 = new MenuFolder("フラグコード");
		{
			*Folder_4 += new MenuEntry("大辞典フラグ編集", nullptr, YW2_Daijiten);
			*Folder_4 += new MenuEntry("トロフィーフラグ編集", nullptr,YW2_Trophy);
			*Folder_4 += new MenuEntry("妖怪スポットフラグ編集", nullptr,YW2_YokaiSpot);
			*Folder_4 += new MenuEntry("クエストフラグ編集", nullptr,YW2_Quest);
			*Folder_4 += new MenuEntry("お手伝いフラグ編集", nullptr,YW2_Otetsudai);
			*Folder_4 += new MenuEntry("ストーリーフラグ編集", nullptr,YW2_Story);
		}
		menu += Folder_4;

		MenuFolder *Folder_5 = new MenuFolder("NPCコード");
		{
			*Folder_5 += new MenuEntry("NPC選択[開発中]", YW2_NPC_Selector, "開発中\nL+右左");
			*Folder_5 += new MenuEntry("NPC座標移動[開発中]", YW2_NPC_CoordinateMovement, "開発中\nB+十字キー");
			*Folder_5 += new MenuEntry("NPCストーキング[開発中]", YW2_NPC_Stalker, "開発中\nL+A");
			*Folder_5 += new MenuEntry("NPCテレポート[開発中]", YW2_NPC_Teleport, "開発中\nL+B");
		}
		menu += Folder_5;

		MenuFolder *Folder_6 = new MenuFolder("プロフィールコード");
		{
			*Folder_6 += new MenuEntry("顔アイコン変更", nullptr,YW2_Profile_FaceIcon);
			*Folder_6 += new MenuEntry("大辞典開放率変更", nullptr,YW2_Profile_Daijiten);
			*Folder_6 += new MenuEntry("金トロフィー取得率変更", nullptr,YW2_Profile_GoldTrophy);
			*Folder_6 += new MenuEntry("銀トロフィー取得率変更", nullptr,YW2_Profile_SilverTrophy);
			*Folder_6 += new MenuEntry("銅トロフィー取得率変更", nullptr,YW2_Profile_BronzTrophy);

			MenuFolder *Folder_6_1 = new MenuFolder("色々な記録1");
			{
				*Folder_6_1 += new MenuEntry("あそんだ時間変更", nullptr,YW2_Profile_PlayTime);
				*Folder_6_1 += new MenuEntry("すれ違った回数変更", nullptr,YW2_Profile_Suretigai);
				*Folder_6_1 += new MenuEntry("頼み事を解決した数変更", nullptr,YW2_Profile_Tanomigoto);
				*Folder_6_1 += new MenuEntry("ふしぎなレンズで写した妖怪数変更", nullptr,YW2_Profile_FushigiRenz);
				*Folder_6_1 += new MenuEntry("逮捕した指名手配妖怪数変更", nullptr,YW2_Profile_Shimeitehai);
			}
			*Folder_6 += Folder_6_1;

			MenuFolder *Folder_6_2 = new MenuFolder("色々な記録2");
			{
				*Folder_6_2 += new MenuEntry("捕まえた虫の種類数変更", nullptr,YW2_Profile_Bug);
				*Folder_6_2 += new MenuEntry("釣った魚の種類数変更", nullptr,YW2_Profile_Fish);
			}
			*Folder_6 += Folder_6_2;

			MenuFolder *Folder_6_3 = new MenuFolder("自転車レース");
			{

			}
			*Folder_6 += Folder_6_3;

			MenuFolder *Folder_6_4 = new MenuFolder("対戦");
			{
				*Folder_6_4 += new MenuEntry("称号変更", nullptr,YW2_Profile_Syougou);
				*Folder_6_4 += new MenuEntry("近くの友達・フレンド対戦勝利数変更", nullptr,YW2_Profile_FriendBattle);
				*Folder_6_4 += new MenuEntry("ランダム対戦勝利数変更", nullptr,YW2_Profile_RandomBattle);
			}
			*Folder_6 += Folder_6_4;

			MenuFolder *Folder_6_5 = new MenuFolder("お気に入りの妖怪");
			{
				*Folder_6_5 += new MenuEntry("お気に入りの妖怪1位変更", nullptr,YW2_Profile_FavoriteYokai1);
				*Folder_6_5 += new MenuEntry("お気に入りの妖怪2位変更", nullptr,YW2_Profile_FavoriteYokai2);
				*Folder_6_5 += new MenuEntry("お気に入りの妖怪3位変更", nullptr,YW2_Profile_FavoriteYokai3);
				*Folder_6_5 += new MenuEntry("お気に入りの妖怪4位変更", nullptr,YW2_Profile_FavoriteYokai4);
				*Folder_6_5 += new MenuEntry("お気に入りの妖怪5位変更", nullptr,YW2_Profile_FavoriteYokai5);
				*Folder_6_5 += new MenuEntry("お気に入りの妖怪6位変更", nullptr,YW2_Profile_FavoriteYokai6);
			}
			*Folder_6 += Folder_6_5;
		}
		menu += Folder_6;
		
		MenuFolder *Folder_7 = new MenuFolder("その他コード");
		{
			*Folder_7 += new MenuEntry("プレイヤーモデル変更", nullptr, YW2_PlayerModel);
			*Folder_7 += new MenuEntry("バージョン変更", nullptr, YW2_VersionChange);
			*Folder_7 += new MenuEntry("性別変更", nullptr, YW2_GenderChange);
			*Folder_7 += new MenuEntry("所持金変更", nullptr, YW2_MoneyChange);
			*Folder_7 += new MenuEntry("天気変更", nullptr, YW2_WeatherChanger);
			*Folder_7 += new MenuEntry("強制鬼時間発動", nullptr, YW2_Onijikan);
			*Folder_7 += new MenuEntry("時間変更", nullptr, YW2_ChangeTime);
			*Folder_7 += new MenuEntry("ゲームスピード変更", YW2_GameSpeed);
			*Folder_7 += new MenuEntry("会話メッセージスルー", YW2_TalkMessageThrough);
			*Folder_7 += new MenuEntry("LRカメラ操作無効", YW2_LRCamera);
			*Folder_7 += new MenuEntry("テクスチャバグ", YW2_TextureBug);
			*Folder_7 += new MenuEntry("インスタントフィッシング", YW2_Fishing_Success);
		}
		menu += Folder_7;
	}
	
	static void NYANKOR_MENU(PluginMenu &menu)
	{
		MenuFolder *Folder_1 = new MenuFolder("バトルコード");
		{
			*Folder_1 += new MenuEntry("にゃんこ砲無限", NYANKOR_rapidnyankohou);
			*Folder_1 += new MenuEntry("自分のHP無限", NYANKOR_hp_max);
			*Folder_1 += new MenuEntry("相手のHP0", NYANKOR_aitehp_0);
			*Folder_1 += new MenuEntry("統一力変更", nullptr, NYANKOR_touitu);
		}
		menu += Folder_1;

		MenuFolder *Folder_2 = new MenuFolder("アイテムコード");
		{
			*Folder_2 += new MenuEntry("スピードアップ", NYANKOR_speedup_max);
			*Folder_2 += new MenuEntry("トレジャーレーダー", NYANKOR_treasurerader_max);
			*Folder_2 += new MenuEntry("ネコボン", NYANKOR_nekobon_max);
			*Folder_2 += new MenuEntry("ニャンピューター", NYANKOR_nyanputer_max);
			*Folder_2 += new MenuEntry("経験値アップ", NYANKOR_xpup_max);
			*Folder_2 += new MenuEntry("スニャイパー", NYANKOR_sunyaiper_max);
		}
		menu += Folder_2;
	}
	
	static void YWB_MENU(PluginMenu &menu)
	{
		MenuFolder *Folder_1 = new MenuFolder("移動系コード");
		{
			*Folder_1 += EntryWithHotkey(new MenuEntry("座標移動", YWB_CoordinateMovement),
			{
				Hotkey(Key::Y + DPadUp, "上へ移動"),
				Hotkey(Key::Y + DPadDown, "下へ移動"),
				Hotkey(Key::Y + DPadLeft, "左へ移動"),
				Hotkey(Key::Y + DPadRight, "右へ移動"),
			});
			*Folder_1 += EntryWithHotkey(new MenuEntry("ムーンジャンプ", YWB_MoonJump),
			{
				Hotkey(Key::B + DPadUp, "上へ移動"),
				Hotkey(Key::B + DPadDown, "下へ移動"),
			});
			*Folder_1 += EntryWithHotkey(new MenuEntry("壁貫通", YWB_WallThrough),
			{
				Hotkey(Key::L + DPadUp, "ON/OFF"),
			});
			*Folder_1 += EntryWithHotkey(new MenuEntry("プレイヤー追跡", YWB_PlayerStalk),
			{
				Hotkey(Key::R + DPadUp, "プレイヤー1追跡"),
				Hotkey(Key::R + DPadRight, "プレイヤー2追跡"),
				Hotkey(Key::R + DPadDown, "プレイヤー3追跡"),
			});
			*Folder_1 += new MenuEntry("スタミナ無限", YWB_InfStamina); //OFFの解析お願いします。
			*Folder_1 += new MenuEntry("空中歩行", YWB_SkyWalk);
			*Folder_1 += new MenuEntry("落下無視", YWB_NoDown);
			*Folder_1 += new MenuEntry("歩くスピード上昇", YWB_WalkSpeed);
			*Folder_1 += new MenuEntry("Tポーズ", YWB_TPose);
			*Folder_1 += new MenuEntry("プレイヤー状態変更", nullptr, YWB_PlayerStateChange);
			*Folder_1 += new MenuEntry("位置セーブ&リストア", nullptr, YWB_SaveCoordinate);
		}
		menu += Folder_1;

		MenuFolder *Folder_2 = new MenuFolder("ミッションコード");
		{
			*Folder_2 += new MenuEntry("友達チャンス確定", YWB_AbsolutelyFriend);
			*Folder_2 += new MenuEntry("技無限", YWB_InfTechnique);
			*Folder_2 += new MenuEntry("攻撃されなくなる", YWB_NoAttack);
			*Folder_2 += new MenuEntry("ダメージ制限解除", YWB_NoDamageLimit, "9999 → 65535");
			*Folder_2 += new MenuEntry("ABXY連射", YWB_RapidABXY);
			*Folder_2 += new MenuEntry("即技発動", YWB_ImmediateTechnique);
			*Folder_2 += new MenuEntry("離れた場所から友達登録可",YWB_DistanceFriend);
			*Folder_2 += new MenuEntry("敵ストップ",  YWB_EnemyStop);
			*Folder_2 += new MenuEntry("アイテムドロップ", YWB_ItemDrop, YWB_ItemDropSettings);
			*Folder_2 += new MenuEntry("ダメージブースト", YWB_DamageBoost);
			*Folder_2 += new MenuEntry("技範囲拡大", YWB_TechniqueRange);
			*Folder_2 += new MenuEntry("ミッション制限時間ストップ", YWB_MissionTimeStop);
			*Folder_2 += new MenuEntry("技自動発動", YWB_AutoTechnique);
			*Folder_2 += new MenuEntry("技キャンセル可能", YWB_TechniqueCancel);
			*Folder_2 += new MenuEntry("無反動", YWB_Recoilless);
			*Folder_2 += new MenuEntry("全回避", YWB_AllAvoidance);
			*Folder_2 += new MenuEntry("友達チャンス発生可能数上限解除", YWB_FriendChanceLimit);
			*Folder_2 += new MenuEntry("常時65535回復", YWB_EveryRecovery65535);
			*Folder_2 += new MenuEntry("HP無限", YWB_InfinityHP);
			*Folder_2 += new MenuEntry("即脱出", YWB_ImmediateEscape);
			*Folder_2 += new MenuEntry("攻撃/回復 判定変更", nullptr, YWB_DamageRecoveryDecision);
			*Folder_2 += new MenuEntry("鬼玉操作", nullptr, YWB_Onidama2);
		}
		menu += Folder_2;

		MenuFolder *Folder_3 = new MenuFolder("お宝ハック");
		{
			*Folder_3 += new MenuEntry("お宝ハック(妖怪)", YWB_TreasureHackYokai, YWB_TreasureHackYokaiSettings);
			*Folder_3 += new MenuEntry("お宝ハック(アイテム)", YWB_TreasureHackItem, YWB_TreasureHackItemSettings);
			*Folder_3 += new MenuEntry("お宝あたり表記変更", YWB_TreasureAtari, YWB_TreasureAtariSettings);
		}
		menu += Folder_3;

		MenuFolder *Folder_4 = new MenuFolder("パトロールハック");
		{
			*Folder_4 += new MenuEntry("パトロールハック(さくら住宅街)", YWB_PatrolSakura, YWB_PatrolSakuraSettings);
			*Folder_4 += new MenuEntry("パトロールハック(団々坂)", YWB_PatrolDandan, YWB_PatrolDandanSettings);
			*Folder_4 += new MenuEntry("パトロールハック(そよ風ヒルズ)", YWB_PatrolSoyokaze, YWB_PatrolSoyokazeSettings);
			*Folder_4 += new MenuEntry("パトロールハック(おつかい横丁)", YWB_PatrolOtsukai, YWB_PatrolOtsukaiSettings);
			*Folder_4 += new MenuEntry("パトロールハック(桜中央シティ)", YWB_PatrolSakuracity, YWB_PatrolSakuracitySettings);
			*Folder_4 += new MenuEntry("パトロールハック(ケマモト村)", YWB_PatrolKemamoto, YWB_PatrolKemamotoSettings);
			*Folder_4 += new MenuEntry("パトロールハック(ナギサキ)", YWB_PatrolNagisaki, YWB_PatrolNagisakiSettings);
			*Folder_4 += new MenuEntry("パトロールハック(桜町)", YWB_PatrolSakuramachi, YWB_PatrolSakuramachiSettings);
			*Folder_4 += new MenuEntry("パトロールハック(平釜平原)", YWB_PatrolHiragama, YWB_PatrolHiragamaSettings);
		}
		menu += Folder_4;

		MenuFolder *Folder_5 = new MenuFolder("オンラインコード");
		{
			*Folder_5 += new MenuEntry("入室エラー", YWB_EnterRoomError, "しばらくロードして通信に失敗したら成功");
			*Folder_5 += new MenuEntry("入室エラー回避", YWB_EnterRoomErrorAvoidance);
			*Folder_5 += new MenuEntry("入室拒否", YWB_WaitError, "自分も入室出来なくなるので\n入室する場合はオフにしてください。");
			*Folder_5 += new MenuEntry("どこでもエラー", YWB_DokodemoError, "Press:R");
			*Folder_5 += new MenuEntry("透明入室 V1", YWB_EnterRoomTransparentV1, "相手視点から透明");
			*Folder_5 += new MenuEntry("透明入室 V2", YWB_EnterRoomTransparentV2, "相手視点から透明\nチャット送信可");
			*Folder_5 += new MenuEntry("キック無効", YWB_NoKick);
			*Folder_5 += new MenuEntry("チャット連投可能", YWB_RapidChat);
			*Folder_5 += new MenuEntry("無限部屋増殖", YWB_InfinityRoom);
			*Folder_5 += new MenuEntry("ランク100以上マッチ可能", YWB_Rank100Match);
			*Folder_5 += new MenuEntry("通信している人のIPアドレス表示", YWB_DrawPlayerIP);
			*Folder_5 += new MenuEntry("無限部屋している人のIPアドレス表示", YWB_DrawMugenheyaIP);
			*Folder_5 += new MenuEntry("個人ID表示", YWB_DrawPlayerID);
			*Folder_5 += new MenuEntry("フレンド申請してきた人のID取得", YWB_DrawPlayerIDFriend);
			*Folder_5 += new MenuEntry("ブロックでID取得", YWB_DrawPlayerIDBlock);
			*Folder_5 += new MenuEntry("キック権限取得", YWB_GetKickAuthority);
			*Folder_5 += new MenuEntry("ダミープレイヤー1[開発中]", YWB_DummyPlayer1, YWB_DummyPlayer1_Settings, "開発中");
			*Folder_5 += new MenuEntry("ダミープレイヤー2[開発中]", YWB_DummyPlayer2, YWB_DummyPlayer2_Settings, "開発中");
			*Folder_5 += new MenuEntry("ダミープレイヤー3[開発中]", YWB_DummyPlayer3, YWB_DummyPlayer3_Settings, "開発中");
			*Folder_5 += new MenuEntry("ダミープレイヤー4[開発中]", YWB_DummyPlayer4, YWB_DummyPlayer4_Settings, "開発中");
			*Folder_5 += new MenuEntry("乗っ取り", nullptr, YWB_PlayerJack);
			*Folder_5 += new MenuEntry("プレイヤーにミッション選ばせる", nullptr, YWB_MissionSelectPlayer);
		}
		menu += Folder_5;

		MenuFolder *Folder_6 = new MenuFolder("友達妖怪コード");
		{
			*Folder_6 += new MenuEntry("リーダー妖怪 編集", nullptr, YWB_YokaiEditor1);
			*Folder_6 += new MenuEntry("おとも妖怪1 編集", nullptr, YWB_YokaiEditor2);
			*Folder_6 += new MenuEntry("おとも妖怪2 編集", nullptr, YWB_YokaiEditor3);
			*Folder_6 += new MenuEntry("おとも妖怪3 編集", nullptr, YWB_YokaiEditor4);
			*Folder_6 += new MenuEntry("全ステータス65535", nullptr, YWB_Status65535);
			*Folder_6 += new MenuEntry("起動時レベル255", YWB_StartupLevel255);
		}
		menu += Folder_6;

		MenuFolder *Folder_7 = new MenuFolder("映像関連コード");
		{
			*Folder_7 += new MenuEntry("モデル着色", YWB_ModelColor, YWB_ModelColorSettings);
			*Folder_7 += new MenuEntry("吹き出しサイズ変更", nullptr, YWB_HukidashiSize);
			*Folder_7 += new MenuEntry("ふきだし/オーラサイズ変更", nullptr, YWB_HukidashiSize);
		}
		menu += Folder_7;

		MenuFolder *Folder_8 = new MenuFolder("プロフィールコード");
		{
			*Folder_8 += new MenuEntry("顔アイコン変更", nullptr, YWB_Profile_FaceIcon);
			*Folder_8 += new MenuEntry("銅トロフィー取得数変更", nullptr, YWB_Profile_BronzeTrophy);
			*Folder_8 += new MenuEntry("銀トロフィー取得数変更", nullptr, YWB_Profile_SilverTrophy);
			*Folder_8 += new MenuEntry("金トロフィー取得数変更", nullptr, YWB_Profile_GoldTrophy);
			*Folder_8 += new MenuEntry("大辞典開放率変更", nullptr, YWB_Profile_Daijiten);
			MenuFolder *Folder_8_1 = new MenuFolder("色々な記録");
			{
				*Folder_8_1 += new MenuEntry("プレイ時間変更", nullptr, YWB_Profile_PlayTime);
				*Folder_8_1 += new MenuEntry("クリアしたミッション数変更", nullptr, YWB_Profile_ClearMission);
				*Folder_8_1 += new MenuEntry("赤猫団と協力したかず変更", nullptr, YWB_Profile_AkanekoKyouryoku);
				*Folder_8_1 += new MenuEntry("白犬隊と協力した数変更", nullptr, YWB_Profile_ShiroinuKyouryoku);
				*Folder_8_1 += new MenuEntry("赤猫団とすれちがった数変更", nullptr, YWB_Profile_AkanekoSuretigai);
				*Folder_8_1 += new MenuEntry("白犬隊とすれちがった数変更", nullptr, YWB_Profile_ShiroinuSuretigai);
				*Folder_8_1 += new MenuEntry("集めた装備数変更", nullptr, YWB_Profile_CollectSoubi);
				*Folder_8_1 += new MenuEntry("つないだ妖怪の輪数変更", nullptr, YWB_Profile_YokainoWa);
				*Folder_8_1 += new MenuEntry("アタッカーで出動した回数変更", nullptr, YWB_Profile_Attacker);
				*Folder_8_1 += new MenuEntry("タンクで出動した回数変更", nullptr, YWB_Profile_Tank);
				*Folder_8_1 += new MenuEntry("ヒーラーで出動した回数変更", nullptr, YWB_Profile_Heeler);
				*Folder_8_1 += new MenuEntry("レンジャーで出動した回数変更", nullptr, YWB_Profile_Ranger);
			}
			*Folder_8 += Folder_8_1;

			MenuFolder *Folder_8_2 = new MenuFolder("チャレンジミッション");
			{
				*Folder_8_2 += new MenuEntry("黒鬼", nullptr, YWB_Profile_Kurooni);
				*Folder_8_2 += new MenuEntry("マイティードッグ", nullptr, YWB_Profile_MityDog);
				*Folder_8_2 += new MenuEntry("レッドJ", nullptr, YWB_Profile_RedJ);
				*Folder_8_2 += new MenuEntry("どんどろ", nullptr, YWB_Profile_Dondoro);
				*Folder_8_2 += new MenuEntry("プリズンブレイカー", nullptr, YWB_Profile_PrisonBreaker);
				*Folder_8_2 += new MenuEntry("Gババーン", nullptr, YWB_Profile_GBabaan);
				*Folder_8_2 += new MenuEntry("あやとりさま", nullptr, YWB_Profile_Ayatori);
				*Folder_8_2 += new MenuEntry("日ノ神", nullptr, YWB_Profile_Hinoshin);
			}
			*Folder_8 += Folder_8_2;

			MenuFolder *Folder_8_3 = new MenuFolder("お気に入りの妖怪");
			{
				*Folder_8_3 += new MenuEntry("お気に入りの妖怪1位変更", nullptr, YWB_Profile_FavoriteYokai1);
				*Folder_8_3 += new MenuEntry("お気に入りの妖怪2位変更", nullptr, YWB_Profile_FavoriteYokai2);
				*Folder_8_3 += new MenuEntry("お気に入りの妖怪3位変更", nullptr, YWB_Profile_FavoriteYokai3);
				*Folder_8_3 += new MenuEntry("お気に入りの妖怪4位変更", nullptr, YWB_Profile_FavoriteYokai4);
				*Folder_8_3 += new MenuEntry("お気に入りの妖怪5位変更", nullptr, YWB_Profile_FavoriteYokai5);
				*Folder_8_3 += new MenuEntry("お気に入りの妖怪6位変更", nullptr, YWB_Profile_FavoriteYokai6);
			}
			*Folder_8 += Folder_8_3;
		}
		menu += Folder_8;

		MenuFolder *Folder_9 = new MenuFolder("その他コード");
		{
			*Folder_9 += new MenuEntry("ボス妖怪セーブ", YWB_BossYokaiSave);
			*Folder_9 += new MenuEntry("ゲームスピード上昇", YWB_GameSpeed);
			*Folder_9 += new MenuEntry("メッセージの表示の仕方変更", YWB_MessageDrawType);
			*Folder_9 += new MenuEntry("メッセージ表示速度変更", YWB_MessageSpeed);
			*Folder_9 += new MenuEntry("会話メッセージスルー", YWB_TalkMessageThrough);
			*Folder_9 += new MenuEntry("LRカメラ操作無効", YWB_LRCamera);
			*Folder_9 += new MenuEntry("NGワード規制無効", YWB_NGWord);
			*Folder_9 += new MenuEntry("1日1回イベントリセット", YWB_DayOnlyEventReset);
			*Folder_9 += new MenuEntry("VIPリンク済", YWB_VipLink);
			*Folder_9 += new MenuEntry("LRカメラ可動域拡張", YWB_LRCameraSeigen);
			*Folder_9 += new MenuEntry("ランク変更", nullptr, YWB_ChangeRank);
			*Folder_9 += new MenuEntry("鬼玉数変更", nullptr, YWB_Onidama);
			*Folder_9 += new MenuEntry("記章数変更", nullptr, YWB_Kisho);
			*Folder_9 += new MenuEntry("妖怪パッド機能変更", nullptr, YWB_YokaiPadChange);
			*Folder_9 += new MenuEntry("妖怪パッド編集", nullptr, YWB_YokaiPad);
			*Folder_9 += new MenuEntry("妖怪大辞典編集", nullptr, YWB_Daijiten);
		}
		menu += Folder_9;
	}
	
	static void Ironfall_MENU(PluginMenu &menu)
	{
		MenuFolder *Folder_1 = new MenuFolder("移動系コード");
		{
			*Folder_1 += new MenuEntry("壁貫通", Ironfall_WallThrough);
			*Folder_1 += new MenuEntry("座標移動", Ironfall_CoordinateMovement, "Y+十字キー");
			*Folder_1 += new MenuEntry("ムーンジャンプ", Ironfall_MoonJump, "L+十字キー");
		}
		menu += Folder_1;

		MenuFolder *Folder_2 = new MenuFolder("武器系コード");
		{
			*Folder_2 += new MenuEntry("銃弾無限", Ironfall_InfinityBullet);
		}
		menu += Folder_2;

		MenuFolder *Folder_3 = new MenuFolder("その他コード");
		{
			*Folder_3 += new MenuEntry("広角カメラ", Ironfall_FishEye_Lens);
		}
		menu += Folder_3;
	}

	static void TAIKO_MENU(PluginMenu &menu)
	{
		menu += new MenuEntry("自動操作", TAIKO_AllCombo);
		menu += new MenuEntry("演奏結果全良", TAIKO_ResultAllGood);
		menu += new MenuEntry("魂ゲージ最大", TAIKO_Soulfullafterchange);
		menu += new MenuEntry("スタンプ全開放", TAIKO_AllStump);
		menu += new MenuEntry("称号全開放", TAIKO_AllTrimble);
	}

	static void YW3_MENU(PluginMenu &menu)
	{
		MenuFolder *Folder_1 = new MenuFolder("移動系コード");
		{
			*Folder_1 += EntryWithHotkey(new MenuEntry("座標移動", YW3_CoordinateMovement),
			{
				Hotkey(Key::A + DPadUp, "上へ移動"),
				Hotkey(Key::A + DPadDown, "下へ移動"),
				Hotkey(Key::A + DPadLeft, "左へ移動"),
				Hotkey(Key::A + DPadRight, "右へ移動"),
			});
			*Folder_1 += new MenuEntry("くるくる", YW3_KuruKuru);
			*Folder_1 += new MenuEntry("ムーンジャンプ", YW3_MoonJump);
			*Folder_1 += EntryWithHotkey(new MenuEntry("ムーンジャンプ", YW3_MoonJump),
			{
				Hotkey(Key::B + DPadUp, "上へ移動"),
				Hotkey(Key::B + DPadDown, "下へ移動"),
			});
			*Folder_1 += new MenuEntry("移動速度上昇", YW3_SpeedHack);
			*Folder_1 += new MenuEntry("スタミナ無限", YW3_InfStamina);
			*Folder_1 += EntryWithHotkey(new MenuEntry("壁貫通", YW3_WallThrough),
			{
				Hotkey(Key::L + DPadUp, "ON/OFF"),
			});
			*Folder_1 += EntryWithHotkey(new MenuEntry("床貫通", YW3_FloorThrough),
			{
				Hotkey(Key::L + DPadDown, "ON/OFF"),
			});
			*Folder_1 += new MenuEntry("Tポーズ", YW3_TPose);
			*Folder_1 += new MenuEntry("落下速度低下", YW3_DownSpeed);
			*Folder_1 += new MenuEntry("空中歩行", YW3_SkyWalk);
			*Folder_1 += new MenuEntry("位置セーブ&リストア", nullptr, YW3_SaveCoordinate);
			*Folder_1 += new MenuEntry("エリアワープ", nullptr, YW3_AreaWarp);
		}
		menu += Folder_1;

		MenuFolder *Folder_2 = new MenuFolder("バトルコード");
		{
			*Folder_2 += new MenuEntry("ダメージ上限解除", YW3_DamageLimitUnlock_forBattle);
			*Folder_2 += new MenuEntry("アイテムあげると必ず友達", YW3_GiveItemFriend_forBattle);
			*Folder_2 += new MenuEntry("移動後待機無し", YW3_MoveNoWait_forBattle);
			*Folder_2 += new MenuEntry("HP無限", YW3_InfinityHP_forBattle);
			*Folder_2 += new MenuEntry("必殺技無限", YW3_InfinityTechnique_forBattle);
			*Folder_2 += new MenuEntry("インスタントキル", YW3_InstantKill_forBattle);
			*Folder_2 += new MenuEntry("ダメージ最大", YW3_DamageMax_forBattle);
			*Folder_2 += new MenuEntry("全回避", YW3_AllAvoidance_forBattle);
			*Folder_2 += new MenuEntry("妖怪ブラスター ゲージマックス", YW3_AllAvoidance_forBattle);
			*Folder_2 += new MenuEntry("バトル後獲得経験値変更", YW3_BattleResultXP, YW3_BattleResultXP_Settings);
			*Folder_2 += new MenuEntry("バトル後獲得お金変更", YW3_BattleResultMoney, YW3_BattleResultMoney_Settings);
		}
		menu += Folder_2;

		MenuFolder *Folder_3 = new MenuFolder("映像コード");
		{
			*Folder_3 += new MenuEntry("モデル色変更", YW3_ModelColor, YW3_ModelColorSettings);
			*Folder_3 += new MenuEntry("ワールド色変更", YW3_WorldColor, YW3_WorldColorSettings);
			*Folder_3 += new MenuEntry("ワールド常に明るい", YW3_AlwaysBright);
		}
		menu += Folder_3;

		MenuFolder *Folder_4 = new MenuFolder("オンラインコード");
		{
			*Folder_4 += new MenuEntry("どこでもエラー", YW3_DokodemoError);
			*Folder_4 += new MenuEntry("透明入室", YW3_InvisibleInRoom);
			*Folder_4 += new MenuEntry("キック無効", YW3_NoKick);
			*Folder_4 += new MenuEntry("入室エラー", YW3_InRoomError);
			*Folder_4 += new MenuEntry("入室エラー無効", YW3_InRoomErrorDisable);
			*Folder_4 += new MenuEntry("キック権限入手", YW3_GetKickPermission);
			*Folder_4 += new MenuEntry("チャット連打可能", YW3_RapidChat);
			*Folder_4 += new MenuEntry("ボス妖怪対戦可能", YW3_BossYokaiBattle);
			*Folder_4 += new MenuEntry("公式バトルランク変更", nullptr, YW3_KoshikiRank);
			*Folder_4 += new MenuEntry("公式バトルレート変更", nullptr, YW3_KoshikiLate);
			*Folder_4 += new MenuEntry("公式バトル連勝記録変更", nullptr, YW3_KoshikiRenshou);
		}
		menu += Folder_4;

		MenuFolder *Folder_5 = new MenuFolder("Tバスターズ/ゾンビナイトコード");
		{
			*Folder_5 += new MenuEntry("友達チャンス確定", YW3_InstantFriendChance_forTBusters);
			*Folder_5 += new MenuEntry("必殺技無限", YW3_InfHissatuTech_forTBusters);
			*Folder_5 += new MenuEntry("スキル後クールダウン無し", YW3_SkillNoCooldown);
			*Folder_5 += new MenuEntry("カスタムコンボ", YW3_CustomCombo);
			*Folder_5 += new MenuEntry("ABXY連打可能", YW3_RapidABXY);
			*Folder_5 += new MenuEntry("インスタントキル(Tバスターズ)", YW3_InstantKill_forTBusters);
			*Folder_5 += new MenuEntry("HP無限(Tバスターズ)", YW3_InfHP_forTBusters);
			*Folder_5 += new MenuEntry("3連続攻撃", YW3_3RenzokuAttack);
			*Folder_5 += new MenuEntry("HP無限(ゾンビナイト)", YW3_InfHP_forZombie);
			*Folder_5 += new MenuEntry("インスタントキル(ゾンビナイト)", YW3_InstantKill_forZombieNight);
			*Folder_5 += new MenuEntry("ミニゲーム9999ポイント", YW3_Minigame9999Point_treasure);
			*Folder_5 += new MenuEntry("コイン100枚", YW3_Coin100_treasure);
			*Folder_5 += new MenuEntry("トレジャーランク変更", nullptr, YW3_TreasureRank);
		}
		menu += Folder_5;

		MenuFolder *Folder_6 = new MenuFolder("カメラコード");
		{
			*Folder_6 += new MenuEntry("LRカメラ可動域拡張", YW3_LRSeigenUnlock);
			*Folder_6 += new MenuEntry("LRカメラ移動無効", YW3_DisableCameraControl);
			*Folder_6 += new MenuEntry("広角カメラ", YW3_WideCamera);
			*Folder_6 += new MenuEntry("TPSゲーム風カメラ移動[開発中]", YW3_TPSCameraMove, "R+CPad\n・LRカメラ可動域拡張\n・LRカメラ移動無効\nもオンになります");
			*Folder_6 += EntryWithHotkey(new MenuEntry("ズームイン/ズームアウト", YW3_CameraZoom),
			{
				Hotkey(Key::R + A, "ズームイン"),
				Hotkey(Key::R + B, "ズームアウト"),
			});
		}
		menu += Folder_6;

		MenuFolder *Folder_7 = new MenuFolder("イベントコード");
		{
			*Folder_7 += new MenuEntry("マップイベント実行", nullptr, YW3_MapEvent);
			*Folder_7 += new MenuEntry("赤い箱イベント実行", nullptr, YW3_RedBoxEvent);
			*Folder_7 += new MenuEntry("ガシャ回数変更", nullptr, YW3_Gasha);
			*Folder_7 += new MenuEntry("1日1回限定イベントリセット", YW3_1Day1EventReset);
		}
		menu += Folder_7;

		MenuFolder *Folder_8 = new MenuFolder("プロフィールコード");
		{
			*Folder_8 += new MenuEntry("プレイ時間変更", nullptr, YW3_Profile_PlayTime);
			*Folder_8 += new MenuEntry("顔アイコン変更", nullptr, YW3_Profile_FaceIcon);
			*Folder_8 += new MenuEntry("妖怪大辞典発見妖怪数変更", nullptr, YW3_Profile_Daijiten);
			*Folder_8 += new MenuEntry("銅トロフィー取得数変更", nullptr, YW3_Profile_BronzeTrophy);
			*Folder_8 += new MenuEntry("銀トロフィー取得数変更", nullptr, YW3_Profile_SilverTrophy);
			*Folder_8 += new MenuEntry("金トロフィー取得数変更", nullptr, YW3_Profile_GoldTrophy);
			MenuFolder *Folder_8_1 = new MenuFolder("色々な記録");
			{
				*Folder_8_1 += new MenuEntry("すれちがった数変更", nullptr, YW3_Profile_Suretigai);
				*Folder_8_1 += new MenuEntry("ケータのクエストを解決した数変更", nullptr, YW3_Profile_KeitaQuest);
				*Folder_8_1 += new MenuEntry("イナホのクエストを解決した数変更", nullptr, YW3_Profile_InahoQuest);
				*Folder_8_1 += new MenuEntry("逮捕したウォンテッド妖怪の数変更", nullptr, YW3_Profile_Arrestyokai);
				*Folder_8_1 += new MenuEntry("つないだ妖怪の輪の数変更", nullptr, YW3_Profile_YokainoWa);
				*Folder_8_1 += new MenuEntry("集めた生き物の数変更(網)", nullptr, YW3_Profile_CollectBug);
				*Folder_8_1 += new MenuEntry("集めた生き物の数変更(釣竿)", nullptr, YW3_Profile_CollectFish);
				*Folder_8_1 += new MenuEntry("勝ち抜きバトル連勝記録変更", nullptr, YW3_Profile_KatinukiBattleRensyou);
				*Folder_8_1 += new MenuEntry("勝ち抜き公式バトル連勝記録変更", nullptr, YW3_Profile_KatinukiKoushikiBattleRensyou);
				*Folder_8_1 += new MenuEntry("達成したミッションの数変更", nullptr, YW3_Profile_ClearMission);
				*Folder_8_1 += new MenuEntry("[不明]", nullptr, YW3_Profile_Unknown1);
				*Folder_8_1 += new MenuEntry("宝探しクリア記録変更", nullptr, YW3_Profile_TreasureSearchClear);
				*Folder_8_1 += new MenuEntry("集めたマイニャンパーツ数変更", nullptr, YW3_Profile_CollectMyNyan);
				*Folder_8_1 += new MenuEntry("[不明]", nullptr, YW3_Profile_Unknown2);
			}
			*Folder_8 += Folder_8_1;

			MenuFolder *Folder_8_2 = new MenuFolder("自転車レース");
			{
				*Folder_8_2 += new MenuEntry("さくら住宅街最速記録変更", nullptr, YW3_Profile_Sakura);
				*Folder_8_2 += new MenuEntry("アオハバラ最速記録変更", nullptr, YW3_Profile_Aohabara);
				*Folder_8_2 += new MenuEntry("[不明]", nullptr, YW3_Profile_Unknown3);
				*Folder_8_2 += new MenuEntry("[不明]", nullptr, YW3_Profile_Unknown4);
			}
			*Folder_8 += Folder_8_2;

			MenuFolder *Folder_8_3 = new MenuFolder("音楽ゲーム");
			{
				*Folder_8_3 += new MenuEntry("[不明]", nullptr, YW3_Profile_Unknown5);
				*Folder_8_3 += new MenuEntry("[不明]", nullptr, YW3_Profile_Unknown6);
				*Folder_8_3 += new MenuEntry("[不明]", nullptr, YW3_Profile_Unknown7);
				*Folder_8_3 += new MenuEntry("[不明]", nullptr, YW3_Profile_Unknown8);
				*Folder_8_3 += new MenuEntry("ニャーKBライブ最高記録変更", nullptr, YW3_Profile_NyaKBLive);
				*Folder_8_3 += new MenuEntry("[不明]", nullptr, YW3_Profile_Unknown9);
				*Folder_8_3 += new MenuEntry("[不明]", nullptr, YW3_Profile_Unknown10);
				*Folder_8_3 += new MenuEntry("ポルターガイスト最高記録変更", nullptr, YW3_Profile_Poltergeist);
			}
			*Folder_8 += Folder_8_3;

			MenuFolder *Folder_8_4 = new MenuFolder("自転車レース");
			{
				*Folder_8_4 += new MenuEntry("お気に入り妖怪1位変更", nullptr, YW3_Profile_FavoriteYokai1);
				*Folder_8_4 += new MenuEntry("お気に入り妖怪2位変更", nullptr, YW3_Profile_FavoriteYokai2);
				*Folder_8_4 += new MenuEntry("お気に入り妖怪3位変更", nullptr, YW3_Profile_FavoriteYokai3);
			}
			*Folder_8 += Folder_8_4;
		}
		menu += Folder_8;

		MenuFolder *Folder_9 = new MenuFolder("その他コード");
		{
			MenuFolder *Folder_9_1 = new MenuFolder("フラグコード");
			{
				*Folder_9_1 += new MenuEntry("うんがい鏡フラグ", nullptr, YW3_UngaiFlag);
				*Folder_9_1 += new MenuEntry("妖怪大辞典フラグ", nullptr, YW3_DaijitenFlag);
				*Folder_9_1 += new MenuEntry("ゾンビナイト開放フラグ", nullptr, YW3_ZombieNightFlag);
				*Folder_9_1 += new MenuEntry("壁紙開放フラグ", nullptr, YW3_KabegamiFlag);
			}
			*Folder_9 += Folder_9_1;

			*Folder_9 += new MenuEntry("妖怪編集", nullptr, YW3_YokaiEditor);
			*Folder_9 += new MenuEntry("ゲームスピード上昇", YW3_GameSpeed);
			*Folder_9 += new MenuEntry("アイテム消費後98個", YW3_Item98);
			*Folder_9 += new MenuEntry("メッセージスルー", YW3_MessageThrough);
			*Folder_9 += new MenuEntry("どこでもセーブ可能", YW3_DokodemoSave);
			*Folder_9 += new MenuEntry("インスタントフィッシング", YW3_InstantFishing);
			*Folder_9 += new MenuEntry("インスタント妖怪捕獲", YW3_InstantYokaiCatch);
			*Folder_9 += new MenuEntry("ボス妖怪保存", YW3_BossYokaiSave);
			*Folder_9 += new MenuEntry("マイニャン特訓即終了", YW3_MyNyanTrainingEnd);
			*Folder_9 += new MenuEntry("クリーナー即終了", YW3_CleanerRobotEnd);
			*Folder_9 += new MenuEntry("横断歩道で妖怪とバトルにならない", YW3_CrossWalkNoYokai);
			*Folder_9 += new MenuEntry("名前変更", nullptr, YW3_NameChanger);
			*Folder_9 += new MenuEntry("プレイヤーモデル変更", nullptr, YW3_PlayerModel);
			*Folder_9 += new MenuEntry("おともモデル変更", nullptr, YW3_OtomoModel);
			*Folder_9 += new MenuEntry("所持金変更", nullptr, YW3_MoneyChanger);
		}
		menu += Folder_9;
	}

	static void InitMenu(PluginMenu &menu)
	{
		menu += TopSeparator(new MenuEntry("ゲーム情報", nullptr, GameInfo)),
		menu += EntryWithHotkey(new MenuEntry("サブメニュー", SubMenu),
		{
			Hotkey(Key::R + Start, "サブメニュー"),
		});

		MenuFolder *Folder_1 = new MenuFolder("プラグイン設定");
        {
			*Folder_1 += new MenuEntry("初期化", nullptr, Setting_Reset);

			MenuFolder *Folder_1_1 = new MenuFolder("メインメニュー");
        	{
				*Folder_1_1 += new MenuEntry("MainTextColor", nullptr, Setting_MainTextColor);
				*Folder_1_1 += new MenuEntry("WindowTitleColor", nullptr, Setting_WindowTitleColor);
				*Folder_1_1 += new MenuEntry("MenuSelectedItemColor", nullptr, Setting_MenuSelectedItemColor);
				*Folder_1_1 += new MenuEntry("MenuUnselectedItemColor", nullptr, Setting_MenuUnselectedItemColor);
				*Folder_1_1 += new MenuEntry("BackgroundMainColor", nullptr, Setting_BackgroundMainColor);
				*Folder_1_1 += new MenuEntry("BackgroundSecondaryColor", nullptr, Setting_BackgroundSecondaryColor);
				*Folder_1_1 += new MenuEntry("BackgroundBorderColor", nullptr, Setting_BackgroundBorderColor);
			}
			*Folder_1 += Folder_1_1;

			MenuFolder *Folder_1_2 = new MenuFolder("キーボード");
        	{
				*Folder_1_2 += new MenuEntry("Background", nullptr, Setting_Keyboard_Background);
				*Folder_1_2 += new MenuEntry("KeyBackground", nullptr, Setting_Keyboard_KeyBackground);
				*Folder_1_2 += new MenuEntry("KeyBackgroundPressed", nullptr, Setting_Keyboard_KeyBackgroundPressed);
				*Folder_1_2 += new MenuEntry("KeyText", nullptr, Setting_Keyboard_KeyText);
				*Folder_1_2 += new MenuEntry("KeyTextPressed", nullptr, Setting_Keyboard_KeyTextPressed);
				*Folder_1_2 += new MenuEntry("Cursor", nullptr, Setting_Keyboard_Cursor);
				*Folder_1_2 += new MenuEntry("Input", nullptr, Setting_Keyboard_Input);
			}
			*Folder_1 += Folder_1_2;

			MenuFolder *Folder_1_3 = new MenuFolder("カスタムキーボード");
        	{
				*Folder_1_3 += new MenuEntry("BackgroundMain", nullptr, Setting_CustomKeyboard_BackgroundMain);
				*Folder_1_3 += new MenuEntry("BackgroundSecondary", nullptr, Setting_CustomKeyboard_BackgroundSecondary);
				*Folder_1_3 += new MenuEntry("BackgroundBorder", nullptr, Setting_CustomKeyboard_BackgroundBorder);
				*Folder_1_3 += new MenuEntry("KeyBackground", nullptr, Setting_CustomKeyboard_KeyBackground);
				*Folder_1_3 += new MenuEntry("KeyBackgroundPressed", nullptr, Setting_CustomKeyboard_KeyBackgroundPressed);
				*Folder_1_3 += new MenuEntry("KeyText", nullptr, Setting_CustomKeyboard_KeyText);
				*Folder_1_3 += new MenuEntry("KeyTextPressed", nullptr, Setting_CustomKeyboard_KeyTextPressed);
				*Folder_1_3 += new MenuEntry("ScrollBarBackground", nullptr, Setting_CustomKeyboard_ScrollBarBackground);
				*Folder_1_3 += new MenuEntry("ScrollBarThumb", nullptr, Setting_CustomKeyboard_ScrollBarThumb);
			}
			*Folder_1 += Folder_1_3;
    	}
		menu += Folder_1;

		MenuFolder *Folder_2 = new MenuFolder("オプション");
        {
			//*Folder_2 += new MenuEntry("レジスタ情報表示", DrawRegInfo);
			*Folder_2 += new MenuEntry("10進数電卓", nullptr, DecCalculator);
			*Folder_2 += new MenuEntry("16進数電卓", nullptr, HexCalculator);
			*Folder_2 += new MenuEntry("10進数→16進数", nullptr, DecToHex);
			*Folder_2 += new MenuEntry("16進数→10進数", nullptr, HexToDec);
			//*Folder_2 += new MenuEntry("範囲指定値変更(4Byte)", nullptr, RangeWrite_4Byte);
			*Folder_2 += new MenuEntry("本体情報", nullptr, DrawInfo);
			*Folder_2 += new MenuEntry("プラグインを終了", nullptr, plugin_exit);
		}
		menu += Folder_2;
	}

	std::string SystemInformation() {
		u8 BatteryPercentage;
		time_t unixTime = time(NULL);
        struct tm* timeStruct = gmtime((const time_t *)&unixTime);
		int year = timeStruct->tm_year + 1900;
		int month = timeStruct->tm_mon + 1;
		int day = timeStruct->tm_mday;
		int hour = timeStruct->tm_hour;
		int minute = timeStruct->tm_min;
		int second = timeStruct->tm_sec;
		const char *wday[] = {"日曜日","月曜日","火曜日","水曜日","木曜日","金曜日","土曜日"};

		std::string systeminfo = Utils::Format("%d/%d/%d(%s)   %d:%d:%d", year, month, day, wday[timeStruct->tm_wday], hour, minute, second);
		return systeminfo;
	}

	void DrawCallBack(Time time)
	{
  		const Screen& scr = OSD::GetTopScreen();
		scr.DrawRect(30, 0, 340, 20, Color::Black, true);
		scr.DrawRect(32, 2, 336, 16, Color::White, false);
		scr.DrawSysfont(SystemInformation(), 34, 3, Color::White);
	}

    int	main(void)
    {
		PluginMenu* menu;
		if (Process::GetTitleID() == 0x0004001000020000) {
			if (DEBUG_BUILD) {
				Keyboard keyboard("選択してください。", {"MK7", "YW2", "NYANKO", "YWB", "Ironfall", "TAIKO", "YW3"});
				int choice = keyboard.Open();
				if (choice == 0) {
					menu = new PluginMenu("マリオカート7", VERSION_A, VERSION_B, VERSION_C, about);
					MARIOKAR_MENU(*menu);
				}
				if (choice == 1) {
					menu = new PluginMenu("妖怪ウォッチ2 真打", VERSION_A, VERSION_B, VERSION_C, about);
					YW2_MENU(*menu);
				}
				if (choice == 2) {
					menu = new PluginMenu("とびだす! にゃんこ大戦争", VERSION_A, VERSION_B, VERSION_C, about);
					NYANKOR_MENU(*menu);
				}
				if (choice == 3) {
					menu = new PluginMenu("妖怪ウォッチバスターズ 月兎組", VERSION_A, VERSION_B, VERSION_C, about);
					YWB_MENU(*menu);
				}
				if (choice == 4) {
					menu = new PluginMenu("IRONFALL Invasion", VERSION_A, VERSION_B, VERSION_C, about);
					Ironfall_MENU(*menu);
				}
				if (choice == 5) {
					menu = new PluginMenu("太鼓の達人 ミステリーアドベンチャー", VERSION_A, VERSION_B, VERSION_C, about);
					TAIKO_MENU(*menu);
				}
				if (choice == 6) {
					menu = new PluginMenu("妖怪ウォッチ3 スキヤキ", VERSION_A, VERSION_B, VERSION_C, about);
					YW3_MENU(*menu);
				}
			}
			else {
				menu = new PluginMenu("Nintendo 3DS", VERSION_A, VERSION_B, VERSION_C, about);
			}
		}
		else if (Process::GetTitleID() == 0x0004000000030600) {
			menu = new PluginMenu("マリオカート7", VERSION_A, VERSION_B, VERSION_C, about);
			MARIOKAR_MENU(*menu);
		}
		else if (Process::GetTitleID() == 0x0004000000155100) {
			menu = new PluginMenu("妖怪ウォッチ2 真打", VERSION_A, VERSION_B, VERSION_C, about);
			YW2_MENU(*menu);
		}
		else if (Process::GetTitleID() == 0x000400000015DA00) {
			menu = new PluginMenu("とびだす! にゃんこ大戦争", VERSION_A, VERSION_B, VERSION_C, about);
			NYANKOR_MENU(*menu);
		}
		else if (Process::GetTitleID() == 0x000400000016C600) {
			menu = new PluginMenu("妖怪ウォッチバスターズ 月兎組", VERSION_A, VERSION_B, VERSION_C, about);
			YWB_MENU(*menu);
		}
		else if (Process::GetTitleID() == 0x000400000016C700) {
			menu = new PluginMenu("妖怪ウォッチバスターズ 月兎組", VERSION_A, VERSION_B, VERSION_C, about);
			YWB_MENU(*menu);
		}
		else if (Process::GetTitleID() == 0x000400000017D000) {
			menu = new PluginMenu("IRONFALL Invasion", VERSION_A, VERSION_B, VERSION_C, about);
			Ironfall_MENU(*menu);
		}
		else if (Process::GetTitleID() == 0x0004000000190E00) {
			menu = new PluginMenu("太鼓の達人 ミステリーアドベンチャー", VERSION_A, VERSION_B, VERSION_C, about);
			TAIKO_MENU(*menu);
		}
		else if (Process::GetTitleID() == 0x0004000000191000) {
			menu = new PluginMenu("妖怪ウォッチ3 スシ", VERSION_A, VERSION_B, VERSION_C, about);
			YW3_MENU(*menu);
		}
		else if (Process::GetTitleID() == 0x0004000000191100) {
			menu = new PluginMenu("妖怪ウォッチ3 テンプラ", VERSION_A, VERSION_B, VERSION_C, about);
			YW3_MENU(*menu);
		}
		else if (Process::GetTitleID() == 0x00040000001AF400) {
			menu = new PluginMenu("妖怪ウォッチ3 スキヤキ", VERSION_A, VERSION_B, VERSION_C, about);
			YW3_MENU(*menu);
		}
		else {
			menu = new PluginMenu("Nintendo 3DS", VERSION_A, VERSION_B, VERSION_C, about);
		}
		menu->ShowWelcomeMessage(false);
		menu->SynchronizeWithFrame(true);
		menu->OnNewFrame = DrawCallBack;
		if (!DEBUG_BUILD) {
			menu->SetHexEditorState(false);
		}
		InitMenu(*menu);
		OSD::Notify(Color::Red << "P" << Color::Orange << "l" << Color::Yellow << "u" << Color::Green << "g" << Color::SkyBlue << "i" << Color::Purple << "n " << Color::Red << "r" << Color::Orange << "e" << Color::Yellow << "a" << Color::Green << "d" << Color::SkyBlue << "y" << Color::Purple << "!");
		menu->Run();
		delete menu;
        return 0;
    }
}