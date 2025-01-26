//TITLE: 妖怪ウォッチバスターズ 白犬隊
//TITLEID: 000400000016C600
//TITLE: 妖怪ウォッチバスターズ 赤猫団
//TITLEID: 000400000016C700
//PROCESSNAME: YW-B

/* OLD NEW変換表
OLD: 08500000 = NEW: 0C100000
OLD: 08600000 = NEW: 0C200000
OLD: 08700000 = NEW: 0C300000
OLD: 08800000 = NEW: 0C400000
OLD: 08900000 = NEW: 0C500000
OLD: 08A00000 = NEW: 0C600000
OLD: 08B00000 = NEW: 0C700000
OLD: 08C00000 = NEW: 0C900000
OLD: 08D00000 = NEW: 0CA00000
*/

#include "cheats.hpp"

namespace	CTRPluginFramework
{
    static StringVector items_ywb(200);
    
    static u32 yokai1_id, yokai2_id, yokai3_id, yokai4_id;
    static u8 yokai1_level, yokai2_level, yokai3_level, yokai4_level;
    static u32 item1, item2, item3, item4;
    static u32 otakara_atari;
    static u32 sakura_yokai1, sakura_yokai2, sakura_yokai3, sakura_yokai4;
    static u32 dandan_yokai1, dandan_yokai2, dandan_yokai3, dandan_yokai4;
    static u32 soyokaze_yokai1, soyokaze_yokai2, soyokaze_yokai3, soyokaze_yokai4;
    static u32 otsukai_yokai1, otsukai_yokai2, otsukai_yokai3, otsukai_yokai4;
    static u32 sakuracity_yokai1, sakuracity_yokai2, sakuracity_yokai3, sakuracity_yokai4;
    static u32 kemamoto_yokai1, kemamoto_yokai2, kemamoto_yokai3, kemamoto_yokai4;
    static u32 nagisaki_yokai1, nagisaki_yokai2, nagisaki_yokai3, nagisaki_yokai4;
    static u32 sakuramachi_yokai1, sakuramachi_yokai2, sakuramachi_yokai3, sakuramachi_yokai4;
    static u32 hiragama_yokai1, hiragama_yokai2, hiragama_yokai3, hiragama_yokai4;
    static u32 item_id;

    void YWB_VipLink(MenuEntry *entry)
    {
        Process::Write32(0x0055C7AC, 0xE3A00001);
        Process::Write32(0x005600A8, 0xE3A00000);
    }

    void YWB_EnemyStop(MenuEntry *entry)
    {
        Process::Write32(0x003D9004, 0xE3A00000);
    }

    void YWB_GameSpeed(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x006B8DA8, 0x40000000);
        }
        else {
            Process::Write32(0x006B8DA8, 0x3F800000);
        }
    }

    void YWB_DayOnlyEventReset(MenuEntry *entry)
    {
        Process::Write32(0x005147DC, 0xE3A00001);
    }

    void YWB_DistanceFriend(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00432CD4, 0xE1A00000);
            Process::Write32(0x00432E94, 0xEEF09A49);
            Process::Write32(0x00432E98, 0xE1A08004);
        }
        else {
            Process::Write32(0x00432CD4, 0xCA000070);
            Process::Write32(0x00432E94, 0x3EF09A49);
            Process::Write32(0x00432E98, 0x31A08004);
        }
    }

    void YWB_TreasureHackYokaiSettings(MenuEntry *entry)
    {
        Keyboard keyboard("妖怪1のIDを入力してください。");
		if (keyboard.Open(yokai1_id) != -1) {
			Keyboard keyboard("妖怪1のレベルを入力してください。");
            if (keyboard.Open(yokai1_level) != -1) {
                Keyboard keyboard("妖怪2のIDを入力してください。");
                if (keyboard.Open(yokai2_id) != -1) {
                    Keyboard keyboard("妖怪2のレベルを入力してください。");
                    if (keyboard.Open(yokai2_level) != -1) {
                        Keyboard keyboard("妖怪3のIDを入力してください。");
                        if (keyboard.Open(yokai3_id) != -1) {
                            Keyboard keyboard("妖怪3のレベルを入力してください。");
                            if (keyboard.Open(yokai3_level) != -1) {
                                Keyboard keyboard("妖怪4のIDを入力してください。");
                                if (keyboard.Open(yokai4_id) != -1) {
                                    Keyboard keyboard("妖怪4のレベルを入力してください。");
                                    if (keyboard.Open(yokai4_level) != -1) {
                                        (MessageBox("妖怪1: " + std::to_string(yokai1_id) + "\n妖怪1 レベル: " + std::to_string(yokai1_level) + "\n妖怪2: " + std::to_string(yokai2_id) +"\n妖怪2 レベル: " + std::to_string(yokai2_level) + "\n妖怪3: " + std::to_string(yokai3_id) + "\n妖怪 レベル: " + std::to_string(yokai3_level) + "\n妖怪4: " + std::to_string(yokai4_id) + "\n妖怪4 レベル: " + std::to_string(yokai4_level)))();
                                    }
                                }
                            }
                        }
                    }
                }
            }
		}
    }

    void YWB_TreasureHackYokai(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::Write32(0x087D84FC, yokai1_id);
            Process::Write32(0x087D8508, yokai2_id);
            Process::Write32(0x087D8514, yokai3_id);
            Process::Write32(0x087D8520, yokai4_id);
            Process::Write32(0x087D8500, 0x00006301);
            Process::Write32(0x087D850C, 0x00006301);
            Process::Write32(0x087D8518, 0x00006301);
            Process::Write32(0x087D8524, 0x00006301);
        }
        else {
            Process::Write32(0x0C3D84FC, yokai1_id);
            Process::Write32(0x0C3D8508, yokai2_id);
            Process::Write32(0x0C3D8514, yokai3_id);
            Process::Write32(0x0C3D8520, yokai4_id);
            Process::Write32(0x0C3D8500, 0x00006301);
            Process::Write32(0x0C3D850C, 0x00006301);
            Process::Write32(0x0C3D8518, 0x00006301);
            Process::Write32(0x0C3D8524, 0x00006301);
        }
    }

    void YWB_TreasureHackItemSettings(MenuEntry *entry)
    {
        Keyboard keyboard("アイテム1のIDを入力してください。");
		if (keyboard.Open(item1) != -1) {
			Keyboard keyboard("アイテム2のIDを入力してください。");
            if (keyboard.Open(item2) != -1) {
                Keyboard keyboard("アイテム3のIDを入力してください。");
                if (keyboard.Open(item3) != -1) {
                    Keyboard keyboard("アイテム4のIDを入力してください。");
                    if (keyboard.Open(item4) != -1) {
                        (MessageBox("アイテム1: " + std::to_string(item1) + "\nアイテム2: " + std::to_string(item2) + "\nアイテム3: " + std::to_string(item3) + "\nアイテム4: " + std::to_string(item4)))();
                    }
                }
            }
		}
    }

    void YWB_TreasureHackItem(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::Write32(0x087D84FC, item1);
            Process::Write32(0x087D8508, item2);
            Process::Write32(0x087D8514, item3);
            Process::Write32(0x087D8520, item4);
            Process::Write32(0x087D8500, 0x00000000);
            Process::Write32(0x087D850C, 0x00000000);
            Process::Write32(0x087D8518, 0x00000000);
            Process::Write32(0x087D8524, 0x00000000);
            }
        else {
            Process::Write32(0x0C3D84FC, item1);
            Process::Write32(0x0C3D8508, item2);
            Process::Write32(0x0C3D8514, item3);
            Process::Write32(0x0C3D8520, item4);
            Process::Write32(0x0C3D8500, 0x00000000);
            Process::Write32(0x0C3D850C, 0x00000000);
            Process::Write32(0x0C3D8518, 0x00000000);
            Process::Write32(0x0C3D8524, 0x00000000);
        }
    }

    void YWB_TreasureAtariSettings(MenuEntry *entry)
    {
        Keyboard keyboard("お宝表記変更");
        std::vector < std::string > option =
        {
            "スペシャル", "大当たり", "中当たり", "小当たり", "はずれ"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
			otakara_atari = 0x00000007;
		}
        if (userchoice == 1) {
			otakara_atari = 0x00000001;
		}
        if (userchoice == 2) {
			otakara_atari = 0x00000002;
		}
        if (userchoice == 3) {
			otakara_atari = 0x00000004;
		}
        if (userchoice == 4) {
			otakara_atari = 0x00000006;
		}
    }

    void YWB_TreasureAtari(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::Write32(0x087D8504, otakara_atari);
            Process::Write32(0x087D8510, otakara_atari);
            Process::Write32(0x087D851C, otakara_atari);
            Process::Write32(0x087D8528, otakara_atari);
            }
        else {
            Process::Write32(0x0C3D8504, otakara_atari);
            Process::Write32(0x0C3D8510, otakara_atari);
            Process::Write32(0x0C3D851C, otakara_atari);
            Process::Write32(0x0C3D8528, otakara_atari);
        }
    }

    void YWB_PatrolSakuraSettings(MenuEntry *entry)
    {
        Keyboard keyboard("パトロールハック\nさくら住宅街\n\n妖怪1のIDを入力してください。");
		if (keyboard.Open(sakura_yokai1) != -1) {
			Keyboard keyboard("パトロールハック\nさくら住宅街\n\n妖怪2のIDを入力してください。");
            if (keyboard.Open(sakura_yokai2) != -1) {
                Keyboard keyboard("パトロールハック\nさくら住宅街\n\n妖怪3のIDを入力してください。");
                if (keyboard.Open(sakura_yokai3) != -1) {
                    Keyboard keyboard("パトロールハック\nさくら住宅街\n\n妖怪4のIDを入力してください。");
                    if (keyboard.Open(sakura_yokai4) != -1) {
                        (MessageBox(Utils::Format("妖怪1: %X\n妖怪2: %X\n妖怪3: %X\n妖怪4: %X", sakura_yokai1, sakura_yokai2, sakura_yokai3, sakura_yokai4)))();
                    }
                }
            }
		}
    }

    void YWB_PatrolSakura(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::Write32(0x08A9EE78, sakura_yokai1);
            Process::Write32(0x08A9EE7C, sakura_yokai2);
            Process::Write32(0x08A9EE80, sakura_yokai3);
            Process::Write32(0x08A9EE84, sakura_yokai4);
        }
        else {
            Process::Write32(0x0C69EE78, sakura_yokai1);
            Process::Write32(0x0C69EE7C, sakura_yokai2);
            Process::Write32(0x0C69EE80, sakura_yokai3);
            Process::Write32(0x0C69EE84, sakura_yokai4);
        }
    }

    void YWB_PatrolDandanSettings(MenuEntry *entry)
    {
        Keyboard keyboard("パトロールハック\n団々坂\n\n妖怪1のIDを入力してください。");
		if (keyboard.Open(otsukai_yokai1) != -1) {
			Keyboard keyboard("パトロールハック\n団々坂\n\n妖怪2のIDを入力してください。");
            if (keyboard.Open(otsukai_yokai2) != -1) {
                Keyboard keyboard("パトロールハック\n団々坂\n\n妖怪3のIDを入力してください。");
                if (keyboard.Open(otsukai_yokai3) != -1) {
                    Keyboard keyboard("パトロールハック\n団々坂\n\n妖怪4のIDを入力してください。");
                    if (keyboard.Open(otsukai_yokai4) != -1) {
                        (MessageBox("妖怪1: " + std::to_string(dandan_yokai1) + "\n妖怪2: " + std::to_string(dandan_yokai2) + "\n妖怪3: " + std::to_string(dandan_yokai3) + "\n妖怪4: " + std::to_string(dandan_yokai4)))();
                    }
                }
            }
		}
    }

    void YWB_PatrolDandan(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::Write32(0x08A9EE8C, dandan_yokai1);
            Process::Write32(0x08A9EE90, dandan_yokai2);
            Process::Write32(0x08A9EE94, dandan_yokai3);
            Process::Write32(0x08A9EE98, dandan_yokai4);
        }
        else {
            Process::Write32(0x0C69EE8C, dandan_yokai1);
            Process::Write32(0x0C69EE90, dandan_yokai2);
            Process::Write32(0x0C69EE94, dandan_yokai3);
            Process::Write32(0x0C69EE98, dandan_yokai4);
        }
    }

    void YWB_PatrolSoyokazeSettings(MenuEntry *entry)
    {
        Keyboard keyboard("パトロールハック\nそよ風ヒルズ\n\n妖怪1のIDを入力してください。");
		if (keyboard.Open(soyokaze_yokai1) != -1) {
			Keyboard keyboard("パトロールハック\nそよ風ヒルズ\n\n妖怪2のIDを入力してください。");
            if (keyboard.Open(soyokaze_yokai2) != -1) {
                Keyboard keyboard("パトロールハック\nそよ風ヒルズ\n\n妖怪3のIDを入力してください。");
                if (keyboard.Open(soyokaze_yokai3) != -1) {
                    Keyboard keyboard("パトロールハック\nそよ風ヒルズ\n\n妖怪4のIDを入力してください。");
                    if (keyboard.Open(soyokaze_yokai4) != -1) {
                        (MessageBox("妖怪1: " + std::to_string(soyokaze_yokai1) + "\n妖怪2: " + std::to_string(soyokaze_yokai2) + "\n妖怪3: " + std::to_string(soyokaze_yokai3) + "\n妖怪4: " + std::to_string(soyokaze_yokai4)))();
                    }
                }
            }
		}
    }

    void YWB_PatrolSoyokaze(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::Write32(0x08A9EEC8, soyokaze_yokai1);
            Process::Write32(0x08A9EECC, soyokaze_yokai2);
            Process::Write32(0x08A9EED0, soyokaze_yokai3);
            Process::Write32(0x08A9EED4, soyokaze_yokai4);
        }
        else {
            Process::Write32(0x0C69EEC8, soyokaze_yokai1);
            Process::Write32(0x0C69EECC, soyokaze_yokai2);
            Process::Write32(0x0C69EED0, soyokaze_yokai3);
            Process::Write32(0x0C69EED4, soyokaze_yokai4);
        }
    }

    void YWB_PatrolOtsukaiSettings(MenuEntry *entry)
    {
        Keyboard keyboard("パトロールハック\nおつかい横丁\n\n妖怪1のIDを入力してください。");
		if (keyboard.Open(otsukai_yokai1) != -1) {
			Keyboard keyboard("パトロールハック\nおつかい横丁\n\n妖怪2のIDを入力してください。");
            if (keyboard.Open(otsukai_yokai2) != -1) {
                Keyboard keyboard("パトロールハック\nおつかい横丁\n\n妖怪3のIDを入力してください。");
                if (keyboard.Open(otsukai_yokai3) != -1) {
                    Keyboard keyboard("パトロールハック\nおつかい横丁\n\n妖怪4のIDを入力してください。");
                    if (keyboard.Open(otsukai_yokai4) != -1) {
                        (MessageBox("妖怪1: " + std::to_string(otsukai_yokai1) + "\n妖怪2: " + std::to_string(otsukai_yokai2) + "\n妖怪3: " + std::to_string(otsukai_yokai3) + "\n妖怪4: " + std::to_string(otsukai_yokai4)))();
                    }
                }
            }
		}
    }

    void YWB_PatrolOtsukai(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::Write32(0x08A9EEB4, otsukai_yokai1);
            Process::Write32(0x08A9EEB8, otsukai_yokai2);
            Process::Write32(0x08A9EEBC, otsukai_yokai3);
            Process::Write32(0x08A9EEC0, otsukai_yokai4);
        }
        else {
            Process::Write32(0x0C69EEB4, otsukai_yokai1);
            Process::Write32(0x0C69EEB8, otsukai_yokai2);
            Process::Write32(0x0C69EEBC, otsukai_yokai3);
            Process::Write32(0x0C69EEC0, otsukai_yokai4);
        }
    }

    void YWB_PatrolSakuracitySettings(MenuEntry *entry)
    {
        Keyboard keyboard("パトロールハック\nさくら中央シティ\n\n妖怪1のIDを入力してください。");
		if (keyboard.Open(sakuracity_yokai1) != -1) {
			Keyboard keyboard("パトロールハック\nさくら中央シティ\n\n妖怪2のIDを入力してください。");
            if (keyboard.Open(sakuracity_yokai2) != -1) {
                Keyboard keyboard("パトロールハック\nさくら中央シティ\n\n妖怪3のIDを入力してください。");
                if (keyboard.Open(sakuracity_yokai3) != -1) {
                    Keyboard keyboard("パトロールハック\nさくら中央シティ\n\n妖怪4のIDを入力してください。");
                    if (keyboard.Open(sakuracity_yokai4) != -1) {
                        (MessageBox("妖怪1: " + std::to_string(sakuracity_yokai1) + "\n妖怪2: " + std::to_string(sakuracity_yokai2) + "\n妖怪3: " + std::to_string(sakuracity_yokai3) + "\n妖怪4: " + std::to_string(sakuracity_yokai4)))();
                    }
                }
            }
		}
    }

    void YWB_PatrolSakuracity(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::Write32(0x08A9EEA0, sakuracity_yokai1);
            Process::Write32(0x08A9EEA4, sakuracity_yokai2);
            Process::Write32(0x08A9EEA8, sakuracity_yokai3);
            Process::Write32(0x08A9EEAC, sakuracity_yokai4);
        }
        else {
            Process::Write32(0x0C69EEA0, sakuracity_yokai1);
            Process::Write32(0x0C69EEA4, sakuracity_yokai2);
            Process::Write32(0x0C69EEA8, sakuracity_yokai3);
            Process::Write32(0x0C69EEAC, sakuracity_yokai4);
        }
    }

    void YWB_PatrolKemamotoSettings(MenuEntry *entry)
    {
        Keyboard keyboard("パトロールハック\nケマモト村\n\n妖怪1のIDを入力してください。");
		if (keyboard.Open(kemamoto_yokai1) != -1) {
			Keyboard keyboard("パトロールハック\nケマモト村\n\n妖怪2のIDを入力してください。");
            if (keyboard.Open(kemamoto_yokai2) != -1) {
                Keyboard keyboard("パトロールハック\nケマモト村\n\n妖怪3のIDを入力してください。");
                if (keyboard.Open(kemamoto_yokai3) != -1) {
                    Keyboard keyboard("パトロールハック\nケマモト村\n\n妖怪4のIDを入力してください。");
                    if (keyboard.Open(kemamoto_yokai4) != -1) {
                        (MessageBox("妖怪1: " + std::to_string(kemamoto_yokai1) + "\n妖怪2: " + std::to_string(kemamoto_yokai2) + "\n妖怪3: " + std::to_string(kemamoto_yokai3) + "\n妖怪4: " + std::to_string(kemamoto_yokai4)))();
                    }
                }
            }
		}
    }

    void YWB_PatrolKemamoto(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::Write32(0x08A9EEF0, kemamoto_yokai1);
            Process::Write32(0x08A9EEF4, kemamoto_yokai2);
            Process::Write32(0x08A9EEF8, kemamoto_yokai3);
            Process::Write32(0x08A9EEFC, kemamoto_yokai4);
        }
        else {
            Process::Write32(0x0C69EEF0, kemamoto_yokai1);
            Process::Write32(0x0C69EEF4, kemamoto_yokai2);
            Process::Write32(0x0C69EEF8, kemamoto_yokai3);
            Process::Write32(0x0C69EEFC, kemamoto_yokai4);
        }
    }

    void YWB_PatrolNagisakiSettings(MenuEntry *entry)
    {
        Keyboard keyboard("パトロールハック\nナギサキ\n\n妖怪1のIDを入力してください。");
		if (keyboard.Open(nagisaki_yokai1) != -1) {
			Keyboard keyboard("パトロールハック\nナギサキ\n\n妖怪2のIDを入力してください。");
            if (keyboard.Open(nagisaki_yokai2) != -1) {
                Keyboard keyboard("パトロールハック\nナギサキ\n\n妖怪3のIDを入力してください。");
                if (keyboard.Open(nagisaki_yokai3) != -1) {
                    Keyboard keyboard("パトロールハック\nナギサキ\n\n妖怪4のIDを入力してください。");
                    if (keyboard.Open(nagisaki_yokai4) != -1) {
                        (MessageBox("妖怪1: " + std::to_string(nagisaki_yokai1) + "\n妖怪2: " + std::to_string(nagisaki_yokai2) + "\n妖怪3: " + std::to_string(nagisaki_yokai3) + "\n妖怪4: " + std::to_string(nagisaki_yokai4)))();
                    }
                }
            }
		}
    }

    void YWB_PatrolNagisaki(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::Write32(0x08A9EEDC, nagisaki_yokai1);
            Process::Write32(0x08A9EEE0, nagisaki_yokai2);
            Process::Write32(0x08A9EEE4, nagisaki_yokai3);
            Process::Write32(0x08A9EEE8, nagisaki_yokai4);
        }
        else {
            Process::Write32(0x0C69EEDC, nagisaki_yokai1);
            Process::Write32(0x0C69EEE0, nagisaki_yokai2);
            Process::Write32(0x0C69EEE4, nagisaki_yokai3);
            Process::Write32(0x0C69EEE8, nagisaki_yokai4);
        }
    }

    void YWB_PatrolSakuramachiSettings(MenuEntry *entry)
    {
        Keyboard keyboard("パトロールハック\n桜町\n\n妖怪1のIDを入力してください。");
		if (keyboard.Open(sakuramachi_yokai1) != -1) {
			Keyboard keyboard("パトロールハック\n桜町\n\n妖怪2のIDを入力してください。");
            if (keyboard.Open(sakuramachi_yokai2) != -1) {
                Keyboard keyboard("パトロールハック\n桜町\n\n妖怪3のIDを入力してください。");
                if (keyboard.Open(sakuramachi_yokai3) != -1) {
                    Keyboard keyboard("パトロールハック\n桜町\n\n妖怪4のIDを入力してください。");
                    if (keyboard.Open(sakuramachi_yokai4) != -1) {
                        (MessageBox("妖怪1: " + std::to_string(sakuramachi_yokai1) + "\n妖怪2: " + std::to_string(sakuramachi_yokai2) + "\n妖怪3: " + std::to_string(sakuramachi_yokai3) + "\n妖怪4: " + std::to_string(sakuramachi_yokai4)))();
                    }
                }
            }
		}
    }

    void YWB_PatrolSakuramachi(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::Write32(0x08A9EF04, sakuramachi_yokai1);
            Process::Write32(0x08A9EF08, sakuramachi_yokai2);
            Process::Write32(0x08A9EF0C, sakuramachi_yokai3);
            Process::Write32(0x08A9EF10, sakuramachi_yokai4);
        }
        else {
            Process::Write32(0x0C69EF04, sakuramachi_yokai1);
            Process::Write32(0x0C69EF08, sakuramachi_yokai2);
            Process::Write32(0x0C69EF0C, sakuramachi_yokai3);
            Process::Write32(0x0C69EF10, sakuramachi_yokai4);
        }
    }

    void YWB_PatrolHiragamaSettings(MenuEntry *entry)
    {
        Keyboard keyboard("パトロールハック\n平釜平原\n\n妖怪1のIDを入力してください。");
		if (keyboard.Open(hiragama_yokai1) != -1) {
			Keyboard keyboard("パトロールハック\n平釜平原\n\n妖怪2のIDを入力してください。");
            if (keyboard.Open(hiragama_yokai2) != -1) {
                Keyboard keyboard("パトロールハック\n平釜平原\n\n妖怪3のIDを入力してください。");
                if (keyboard.Open(hiragama_yokai3) != -1) {
                    Keyboard keyboard("パトロールハック\n平釜平原\n\n妖怪4のIDを入力してください。");
                    if (keyboard.Open(hiragama_yokai4) != -1) {
                        (MessageBox("妖怪1: " + std::to_string(hiragama_yokai1) + "\n妖怪2: " + std::to_string(hiragama_yokai2) + "\n妖怪3: " + std::to_string(hiragama_yokai3) + "\n妖怪4: " + std::to_string(hiragama_yokai4)))();
                    }
                }
            }
		}
    }

    void YWB_PatrolHiragama(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::Write32(0x08A9EF18, hiragama_yokai1);
            Process::Write32(0x08A9EF1C, hiragama_yokai2);
            Process::Write32(0x08A9EF20, hiragama_yokai3);
            Process::Write32(0x08A9EF24, hiragama_yokai4);
        }
        else {
            Process::Write32(0x0C69EF18, hiragama_yokai1);
            Process::Write32(0x0C69EF1C, hiragama_yokai2);
            Process::Write32(0x0C69EF20, hiragama_yokai3);
            Process::Write32(0x0C69EF24, hiragama_yokai4);
        }
    }

    void YWB_EveryRecovery65535(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00409E7C, 0x55555555);
        }
        else {
            Process::Write32(0x00409E7C, 0x00000000);
        }
    }

    void YWB_Recoilless(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00391158, 0xE1A00000);
            Process::Write32(0x00391574, 0xE1A00000);
            Process::Write32(0x00391580, 0xE1A00000);
            Process::Write32(0x00500A74, 0xE5C50000);
        }
        else {
            Process::Write32(0x00391158, 0xE5C016BC);
            Process::Write32(0x00391574, 0xE5803684);
            Process::Write32(0x00391580, 0xE5C016BC);
            Process::Write32(0x00500A74, 0xE5D50000);
        }
    }

    void YWB_InfStamina(MenuEntry *entry)
    {
        Process::Write32(0x00509AC0, 0xE1A00000);
    }

    void YWB_ImmediateTechnique(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x004038CC, 0x50000000);
        }
        else {
            Process::Write32(0x004038CC, 0x3F800000);
        }
    }

    void YWB_AbsolutelyFriend(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x003D8F30, 0xE3A00001);
        }
        else {
            Process::Write32(0x003D8F30, 0xEB072155);
        }
    }

	void YWB_WallThrough(MenuEntry *entry)
    {
        static bool mode;

		if (Controller::IsKeysPressed(entry->Hotkeys[0].GetKeys()))
		{
			if (mode)
			{
				mode = false;
				OSD::Notify("Wall Through:Disable");
				Process::Write32(0x00261470, 0xE3A00000);
			    Process::Write32(0x0026149C, 0xE3580000);
			}
			else {
				mode = true;
				OSD::Notify("Wall Through:Enabled");
				Process::Write32(0x00261470, 0xE3A00001);
			    Process::Write32(0x0026149C, 0xE3580001);
			}
		}
    }

    void YWB_Onidama2(MenuEntry *entry)
    {
        Keyboard keyboard("鬼玉操作");
        std::vector < std::string > option =
        {
            "増加", "減少", "OFF"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0)
		{
			Process::Write32(0x003FB2C4, 0xE3A000FF);
			Process::Write32(0x003FB694, 0xEA000000);
		}
        if (userchoice == 1)
		{
			Process::Write32(0x003FB2C4, 0xE25000FF);
			Process::Write32(0x003FB694, 0xEA000000);
		}
        if (userchoice == 2)
		{
			Process::Write32(0x003FB2C4, 0xE3A00000);
			Process::Write32(0x003FB694, 0xE3A00001);
		}
    }

    void YWB_WalkSpeed(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x003A44C8, 0x40000000);
        }
        else {
            Process::Write32(0x003A44C8, 0x3F800000);
        }
    }

    void YWB_StartupLevel255(MenuEntry *entry)
    {
        Process::Write32(0x00373778, 0xE35100FF);
        Process::Write32(0x003B8B04, 0xE3A020FF);
    }

    void YWB_InfTechnique(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x003FAC68, 0xE3A00001);
            Process::Write32(0x003FAD04, 0xEB08DF8D);
            Process::Write32(0x003FAFF0, 0xE3A00001);
            Process::Write32(0x00632B40, 0xE5980000);
            Process::Write32(0x00632B44, 0xE92D400F);
            Process::Write32(0x00632B48, 0xE59F001C);
            Process::Write32(0x00632B4C, 0xE59F101C);
            Process::Write32(0x00632B50, 0xE5900000);
            Process::Write32(0x00632B54, 0xEBEC6F81);
            Process::Write32(0x00632B58, 0xE3500000);
            Process::Write32(0x00632B5C, 0x08BD800F);
            Process::Write32(0x00632B60, 0xE3A01000);
            Process::Write32(0x00632B64, 0xE5801178);
            Process::Write32(0x00632B68, 0xE8BD800F);
            Process::Write32(0x00632B6C, 0x0068F3A8);
            Process::Write32(0x00632B70, 0xF64BEC60);
        }
        else {
            Process::Write32(0x003FAC68, 0xEB068E91);
            Process::Write32(0x003FAD04, 0xE5980000);
            Process::Write32(0x003FAFF0, 0xEB068DAF);
            Process::Write32(0x00632B40, 0x00000000);
            Process::Write32(0x00632B44, 0x00000000);
            Process::Write32(0x00632B48, 0x00000000);
            Process::Write32(0x00632B4C, 0x00000000);
            Process::Write32(0x00632B50, 0x00000000);
            Process::Write32(0x00632B54, 0x00000000);
            Process::Write32(0x00632B58, 0x00000000);
            Process::Write32(0x00632B5C, 0x00000000);
            Process::Write32(0x00632B60, 0x00000000);
            Process::Write32(0x00632B64, 0x00000000);
            Process::Write32(0x00632B68, 0x00000000);
            Process::Write32(0x00632B6C, 0x00000000);
            Process::Write32(0x00632B70, 0x00000000);
        }
    }

    void YWB_RapidABXY(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00426754, 0xEB065CB4);
            Process::Write32(0x00426784, 0xEB065CA8);
            Process::Write32(0x004267A8, 0xEB065C9F);
            Process::Write32(0x00426800, 0xEB065C89);
        }
        else {
            Process::Write32(0x00426754, 0xEB065CCD);
            Process::Write32(0x00426784, 0xEB065CC1);
            Process::Write32(0x004267A8, 0xEB065CB8);
            Process::Write32(0x00426800, 0xEB065CA2);
        }
    }

    void YWB_SkyWalk(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00502544, 0xEA000026);
        }
        else {
            Process::Write32(0x00502544, 0x0A000026);
        }
    }

    void YWB_CoordinateMovement(MenuEntry *entry)
	{
		float coord_x, coord_y;
        if (!IsNew3DS()) {
		    if (Controller::IsKeysDown(entry->Hotkeys[0].GetKeys()))
		    {
                Process::ReadFloat(0x088B08E8, coord_y);
			    coord_y = coord_y - 5;
    			Process::WriteFloat(0x088B08E8, coord_y);
	    	}
			if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys()))
		    {
                Process::ReadFloat(0x088B08E8, coord_y);
			    coord_y = coord_y + 5;
    			Process::WriteFloat(0x088B08E8, coord_y);
	    	}
			if (Controller::IsKeysDown(entry->Hotkeys[2].GetKeys()))
		    {
                Process::ReadFloat(0x088B08E0, coord_x);
			    coord_x = coord_x - 5;
				Process::WriteFloat(0x088B08E0, coord_x);
	    	}
			if (Controller::IsKeysDown(entry->Hotkeys[3].GetKeys()))
		    {
                Process::ReadFloat(0x088B08E0, coord_x);
			    coord_x = coord_x + 5;
    			Process::WriteFloat(0x088B08E0, coord_x);
	    	}
        }
        else {
		    if (Controller::IsKeysDown(entry->Hotkeys[0].GetKeys()))
		    {
                Process::ReadFloat(0x0C4B08E8, coord_y);
			    coord_y = coord_y - 5;
    			Process::WriteFloat(0x0C4B08E8, coord_y);
	    	}
			if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys()))
		    {
                Process::ReadFloat(0x0C4B08E8, coord_y);
			    coord_y = coord_y + 5;
    			Process::WriteFloat(0x0C4B08E8, coord_y);
	    	}
			if (Controller::IsKeysDown(entry->Hotkeys[2].GetKeys()))
		    {
                Process::ReadFloat(0x0C4B08E0, coord_x);
			    coord_x = coord_x - 5;
				Process::WriteFloat(0x0C4B08E0, coord_x);
    		    
	    	}
			if (Controller::IsKeysDown(entry->Hotkeys[3].GetKeys()))
		    {
                Process::ReadFloat(0x0C4B08E0, coord_x);
			    coord_x = coord_x + 5;
    			Process::WriteFloat(0x0C4B08E0, coord_x);
	    	}
		}
    }

    void YWB_MoonJump(MenuEntry *entry)
	{
		float coord_z;
        if (!IsNew3DS()) {
		    if (Controller::IsKeysDown(entry->Hotkeys[0].GetKeys())) {
                Process::ReadFloat(0x088B08E4, coord_z);
			    coord_z = coord_z + 5;
				Process::WriteFloat(0x088B08E4, coord_z);
	    	}
			if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys())) {
                Process::ReadFloat(0x088B08E4, coord_z);
			    coord_z = coord_z - 5;
    			Process::WriteFloat(0x088B08E4, coord_z);
	    	}
        }
        else {
		    if (Controller::IsKeysDown(entry->Hotkeys[0].GetKeys())) {
                Process::ReadFloat(0x0C4B08E4, coord_z);
			    coord_z = coord_z + 5;
				Process::WriteFloat(0x0C4B08E4, coord_z);
	    	}
			if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys())) {
                Process::ReadFloat(0x0C4B08E4, coord_z);
			    coord_z = coord_z - 5;
    			Process::WriteFloat(0x0C4B08E4, coord_z);
	    	}
		}
    }

    void YWB_GetKickAuthority(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::Write32(0x0886F790, 0x00000003);
        }
        else {
            Process::Write32(0x0C46F790, 0x00000003);
        }
    }

    void YWB_NoDown(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00509064, 0x00000000);
        }
        else {
            Process::Write32(0x00509064, 0xBF800000);
        }
    }

    void YWB_NoDamageLimit(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x003CD524, 0xE3510000);
        }
        else {
            Process::Write32(0x003CD524, 0xE3510001);
        }
    }

    void YWB_TPose(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x005F8834, 0x00000000);
        }
        else {
            Process::Write32(0x005F8834, 0x40000000);
        }
    }

    void YWB_ImmediateEscape(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00358C0C, 0x00000000);
            Process::Write32(0x00358C30, 0x00000000);
            Process::Write32(0x00358C34, 0x00000000);
        }
        else {
            Process::Write32(0x00358C0C, 0xEEB40AC1);
            Process::Write32(0x00358C30, 0xED9A0A03);
            Process::Write32(0x00358C34, 0xEEB40AE8);
        }
    }

    void YWB_PlayerStalk(MenuEntry *entry)
    {
        float coord_x, coord_y, coord_z;
        if (!IsNew3DS()) {
            if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys())) { //Player1
                Process::ReadFloat(0x0887A148, coord_x);
                Process::ReadFloat(0x0887A150, coord_y);
                Process::ReadFloat(0x0887A14C, coord_z);
                Process::WriteFloat(0x088B08E0, coord_x);
                Process::WriteFloat(0x088B08E8, coord_y);
                Process::WriteFloat(0x088B08E4, coord_z + 3);
            }
            if (Controller::IsKeysDown(entry->Hotkeys[2].GetKeys())) { //Player2
                Process::ReadFloat(0x08879C74, coord_x);
                Process::ReadFloat(0x08879C7C, coord_y);
                Process::ReadFloat(0x08879C78, coord_z);
                Process::WriteFloat(0x088B08E0, coord_x);
                Process::WriteFloat(0x088B08E8, coord_y);
                Process::WriteFloat(0x088B08E4, coord_z + 3);
            }
            if (Controller::IsKeysDown(entry->Hotkeys[3].GetKeys())) { //Player3
                Process::ReadFloat(0x088798FC, coord_x);
                Process::ReadFloat(0x08879904, coord_y);
                Process::ReadFloat(0x08879900, coord_z);
                Process::WriteFloat(0x088B08E0, coord_x);
                Process::WriteFloat(0x088B08E8, coord_y);
                Process::WriteFloat(0x088B08E4, coord_z + 3);
            }
        }
        else {
            if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys())) { //Player1
                Process::ReadFloat(0x0C47A148, coord_x);
                Process::ReadFloat(0x0C47A150, coord_y);
                Process::ReadFloat(0x0C47A14C, coord_z);
                Process::WriteFloat(0x0C4B08E0, coord_x);
                Process::WriteFloat(0x0C4B08E8, coord_y);
                Process::WriteFloat(0x0C4B08E4, coord_z + 3);
            }
            if (Controller::IsKeysDown(entry->Hotkeys[2].GetKeys())) { //Player2
                Process::ReadFloat(0x0C479C74, coord_x);
                Process::ReadFloat(0x0C479C7C, coord_y);
                Process::ReadFloat(0x0C479C78, coord_z);
                Process::WriteFloat(0x0C4B08E0, coord_x);
                Process::WriteFloat(0x0C4B08E8, coord_y);
                Process::WriteFloat(0x0C4B08E4, coord_z + 3);
            }
            if (Controller::IsKeysDown(entry->Hotkeys[3].GetKeys())) { //Player3
                Process::ReadFloat(0x0C4798FC, coord_x);
                Process::ReadFloat(0x0C479904, coord_y);
                Process::ReadFloat(0x0C479900, coord_z);
                Process::WriteFloat(0x0C4B08E0, coord_x);
                Process::WriteFloat(0x0C4B08E8, coord_y);
                Process::WriteFloat(0x0C4B08E4, coord_z + 3);
            }
        }
    }

    void YWB_ItemDropSettings(MenuEntry *entry)
    {
        Keyboard keyboard("アイテムドロップ");
		if (keyboard.Open(item_id) != -1) {
            (MessageBox("ドロップするアイテム: " + std::to_string(item_id)))();
        }
    }

    void YWB_ItemDrop(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x003EAD5C, 0xE3590003);
            Process::Write32(0x003EAF48, 0xE3A0B003);
        }
        else {
            Process::Write32(0x003EAD5C, 0xE3590000);
            Process::Write32(0x003EAF48, 0xE3A0B000);
        }
        if (!IsNew3DS()) {
            Process::Write32(0x08B62A04, item_id);
            Process::Write32(0x08B62A20, item_id);
        }
        else {
            Process::Write32(0x0C762A04, item_id);
            Process::Write32(0x0C762A20, item_id);
        }
    }

    void YWB_Daijiten(MenuEntry *entry)
    {
        Keyboard keyboard("大辞典");
        std::vector < std::string > option =
        {
            "New", "コンプリート", "発見", "未発見"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
            if (!IsNew3DS()) {

                Process::Write32(0x087D0E94, 0xFFFFFFFF);
                Process::Write32(0x087D0E98, 0xFFFFFFFF);
                Process::Write32(0x087D0E9C, 0xFFFFFFFF);
                Process::Write32(0x087D0EA0, 0xFFFFFFFF);
                Process::Write32(0x087D0EA4, 0xFFFFFFFF);
                Process::Write32(0x087D0EA8, 0xFFFFFFFF);
                Process::Write32(0x087D0EAC, 0xFFFFFFFF);
                Process::Write32(0x087D0EB0, 0xFFFFFFFF);
                Process::Write32(0x087D0EB4, 0xFFFFFFFF);
                Process::Write32(0x087D0EB8, 0xFFFFFFFF);
                Process::Write32(0x087D0EBC, 0xFFFFFFFF);
                Process::Write32(0x087D0EC0, 0xFFFFFFFF);
                Process::Write32(0x087D0EC4, 0xFFFFFFFF);
                Process::Write32(0x087D0EC8, 0xFFFFFFFF);
                Process::Write32(0x087D0ECC, 0xFFFFFFFF);
            }
            else {
                Process::Write32(0x0C3D0E94, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E98, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E9C, 0xFFFFFFFF);
                Process::Write32(0x0C3D0EA0, 0xFFFFFFFF);
                Process::Write32(0x0C3D0EA4, 0xFFFFFFFF);
                Process::Write32(0x0C3D0EA8, 0xFFFFFFFF);
                Process::Write32(0x0C3D0EAC, 0xFFFFFFFF);
                Process::Write32(0x0C3D0EB0, 0xFFFFFFFF);
                Process::Write32(0x0C3D0EB4, 0xFFFFFFFF);
                Process::Write32(0x0C3D0EB8, 0xFFFFFFFF);
                Process::Write32(0x0C3D0EBC, 0xFFFFFFFF);
                Process::Write32(0x0C3D0EC0, 0xFFFFFFFF);
                Process::Write32(0x0C3D0EC4, 0xFFFFFFFF);
                Process::Write32(0x0C3D0EC8, 0xFFFFFFFF);
                Process::Write32(0x0C3D0ECC, 0xFFFFFFFF);
            }

        }
        if (userchoice == 1) {
            if (!IsNew3DS()) {
                Process::Write32(0x087D0E14, 0xFFFFFFFF);
                Process::Write32(0x087D0E18, 0xFFFFFFFF);
                Process::Write32(0x087D0E1C, 0xFFFFFFFF);
                Process::Write32(0x087D0E20, 0xFFFFFFFF);
                Process::Write32(0x087D0E24, 0xFFFFFFFF);
                Process::Write32(0x087D0E28, 0xFFFFFFFF);
                Process::Write32(0x087D0E2C, 0xFFFFFFFF);
                Process::Write32(0x087D0E30, 0xFFFFFFFF);
                Process::Write32(0x087D0E34, 0xFFFFFFFF);
                Process::Write32(0x087D0E38, 0xFFFFFFFF);
                Process::Write32(0x087D0E3C, 0xFFFFFFFF);
                Process::Write32(0x087D0E40, 0xFFFFFFFF);
                Process::Write32(0x087D0E44, 0xFFFFFFFF);
                Process::Write32(0x087D0E48, 0xFFFFFFFF);
                Process::Write32(0x087D0E4C, 0xFFFFFFFF);
    			Process::Write32(0x087D0E54, 0xFFFFFFFF);
                Process::Write32(0x087D0E58, 0xFFFFFFFF);
                Process::Write32(0x087D0E5C, 0xFFFFFFFF);
                Process::Write32(0x087D0E60, 0xFFFFFFFF);
                Process::Write32(0x087D0E64, 0xFFFFFFFF);
                Process::Write32(0x087D0E68, 0xFFFFFFFF);
                Process::Write32(0x087D0E6C, 0xFFFFFFFF);
                Process::Write32(0x087D0E70, 0xFFFFFFFF);
                Process::Write32(0x087D0E74, 0xFFFFFFFF);
                Process::Write32(0x087D0E78, 0xFFFFFFFF);
                Process::Write32(0x087D0E7C, 0xFFFFFFFF);
                Process::Write32(0x087D0E80, 0xFFFFFFFF);
                Process::Write32(0x087D0E84, 0xFFFFFFFF);
                Process::Write32(0x087D0E88, 0xFFFFFFFF);
                Process::Write32(0x087D0E8C, 0xFFFFFFFF);
            }
            else {
                Process::Write32(0x0C3D0E14, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E18, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E1C, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E20, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E24, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E28, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E2C, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E30, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E34, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E38, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E3C, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E40, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E44, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E48, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E4C, 0xFFFFFFFF);
    			Process::Write32(0x0C3D0E54, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E58, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E5C, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E60, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E64, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E68, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E6C, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E70, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E74, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E78, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E7C, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E80, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E84, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E88, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E8C, 0xFFFFFFFF);
            }
		}
        if (userchoice == 2) {
            if (!IsNew3DS()) {
                Process::Write32(0x087D0E14, 0xFFFFFFFF);
                Process::Write32(0x087D0E18, 0xFFFFFFFF);
                Process::Write32(0x087D0E1C, 0xFFFFFFFF);
                Process::Write32(0x087D0E20, 0xFFFFFFFF);
                Process::Write32(0x087D0E24, 0xFFFFFFFF);
                Process::Write32(0x087D0E28, 0xFFFFFFFF);
                Process::Write32(0x087D0E2C, 0xFFFFFFFF);
                Process::Write32(0x087D0E30, 0xFFFFFFFF);
                Process::Write32(0x087D0E34, 0xFFFFFFFF);
                Process::Write32(0x087D0E38, 0xFFFFFFFF);
                Process::Write32(0x087D0E3C, 0xFFFFFFFF);
                Process::Write32(0x087D0E40, 0xFFFFFFFF);
                Process::Write32(0x087D0E44, 0xFFFFFFFF);
                Process::Write32(0x087D0E48, 0xFFFFFFFF);
                Process::Write32(0x087D0E4C, 0xFFFFFFFF);
                Process::Write32(0x087D0E54, 0x00000000);
                Process::Write32(0x087D0E58, 0x00000000);
                Process::Write32(0x087D0E5C, 0x00000000);
                Process::Write32(0x087D0E60, 0x00000000);
                Process::Write32(0x087D0E64, 0x00000000);
                Process::Write32(0x087D0E68, 0x00000000);
                Process::Write32(0x087D0E6C, 0x00000000);
                Process::Write32(0x087D0E70, 0x00000000);
                Process::Write32(0x087D0E74, 0x00000000);
                Process::Write32(0x087D0E78, 0x00000000);
                Process::Write32(0x087D0E7C, 0x00000000);
                Process::Write32(0x087D0E80, 0x00000000);
                Process::Write32(0x087D0E84, 0x00000000);
                Process::Write32(0x087D0E88, 0x00000000);
                Process::Write32(0x087D0E8C, 0x00000000);
            }
            else {
                Process::Write32(0x0C3D0E14, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E18, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E1C, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E20, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E24, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E28, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E2C, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E30, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E34, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E38, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E3C, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E40, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E44, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E48, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E4C, 0xFFFFFFFF);
                Process::Write32(0x0C3D0E54, 0x00000000);
                Process::Write32(0x0C3D0E58, 0x00000000);
                Process::Write32(0x0C3D0E5C, 0x00000000);
                Process::Write32(0x0C3D0E60, 0x00000000);
                Process::Write32(0x0C3D0E64, 0x00000000);
                Process::Write32(0x0C3D0E68, 0x00000000);
                Process::Write32(0x0C3D0E6C, 0x00000000);
                Process::Write32(0x0C3D0E70, 0x00000000);
                Process::Write32(0x0C3D0E74, 0x00000000);
                Process::Write32(0x0C3D0E78, 0x00000000);
                Process::Write32(0x0C3D0E7C, 0x00000000);
                Process::Write32(0x0C3D0E80, 0x00000000);
                Process::Write32(0x0C3D0E84, 0x00000000);
                Process::Write32(0x0C3D0E88, 0x00000000);
                Process::Write32(0x0C3D0E8C, 0x00000000);
            }
		}

        if (userchoice == 3) {
            if (!IsNew3DS()) {
                Process::Write32(0x087D0E14, 0x00000000);
                Process::Write32(0x087D0E18, 0x00000000);
                Process::Write32(0x087D0E1C, 0x00000000);
                Process::Write32(0x087D0E20, 0x00000000);
                Process::Write32(0x087D0E24, 0x00000000);
                Process::Write32(0x087D0E28, 0x00000000);
                Process::Write32(0x087D0E2C, 0x00000000);
                Process::Write32(0x087D0E30, 0x00000000);
                Process::Write32(0x087D0E34, 0x00000000);
                Process::Write32(0x087D0E38, 0x00000000);
                Process::Write32(0x087D0E3C, 0x00000000);
                Process::Write32(0x087D0E40, 0x00000000);
                Process::Write32(0x087D0E44, 0x00000000);
                Process::Write32(0x087D0E48, 0x00000000);
                Process::Write32(0x087D0E4C, 0x00000000);
                Process::Write32(0x087D0E54, 0x00000000);
                Process::Write32(0x087D0E58, 0x00000000);
                Process::Write32(0x087D0E5C, 0x00000000);
                Process::Write32(0x087D0E60, 0x00000000);
                Process::Write32(0x087D0E64, 0x00000000);
                Process::Write32(0x087D0E68, 0x00000000);
                Process::Write32(0x087D0E6C, 0x00000000);
                Process::Write32(0x087D0E70, 0x00000000);
                Process::Write32(0x087D0E74, 0x00000000);
                Process::Write32(0x087D0E78, 0x00000000);
                Process::Write32(0x087D0E7C, 0x00000000);
                Process::Write32(0x087D0E80, 0x00000000);
                Process::Write32(0x087D0E84, 0x00000000);
                Process::Write32(0x087D0E88, 0x00000000);
                Process::Write32(0x087D0E8C, 0x00000000);
                Process::Write32(0x087D0E94, 0x00000000);
                Process::Write32(0x087D0E98, 0x00000000);
                Process::Write32(0x087D0E9C, 0x00000000);
                Process::Write32(0x087D0EA0, 0x00000000);
                Process::Write32(0x087D0EA4, 0x00000000);
                Process::Write32(0x087D0EA8, 0x00000000);
                Process::Write32(0x087D0EAC, 0x00000000);
                Process::Write32(0x087D0EB0, 0x00000000);
                Process::Write32(0x087D0EB4, 0x00000000);
                Process::Write32(0x087D0EB8, 0x00000000);
                Process::Write32(0x087D0EBC, 0x00000000);
                Process::Write32(0x087D0EC0, 0x00000000);
                Process::Write32(0x087D0EC4, 0x00000000);
                Process::Write32(0x087D0EC8, 0x00000000);
                Process::Write32(0x087D0ECC, 0x00000000);
            }
            else {
                Process::Write32(0x0C3D0E14, 0x00000000);
                Process::Write32(0x0C3D0E18, 0x00000000);
                Process::Write32(0x0C3D0E1C, 0x00000000);
                Process::Write32(0x0C3D0E20, 0x00000000);
                Process::Write32(0x0C3D0E24, 0x00000000);
                Process::Write32(0x0C3D0E28, 0x00000000);
                Process::Write32(0x0C3D0E2C, 0x00000000);
                Process::Write32(0x0C3D0E30, 0x00000000);
                Process::Write32(0x0C3D0E34, 0x00000000);
                Process::Write32(0x0C3D0E38, 0x00000000);
                Process::Write32(0x0C3D0E3C, 0x00000000);
                Process::Write32(0x0C3D0E40, 0x00000000);
                Process::Write32(0x0C3D0E44, 0x00000000);
                Process::Write32(0x0C3D0E48, 0x00000000);
                Process::Write32(0x0C3D0E4C, 0x00000000);
                Process::Write32(0x0C3D0E54, 0x00000000);
                Process::Write32(0x0C3D0E58, 0x00000000);
                Process::Write32(0x0C3D0E5C, 0x00000000);
                Process::Write32(0x0C3D0E60, 0x00000000);
                Process::Write32(0x0C3D0E64, 0x00000000);
                Process::Write32(0x0C3D0E68, 0x00000000);
                Process::Write32(0x0C3D0E6C, 0x00000000);
                Process::Write32(0x0C3D0E70, 0x00000000);
                Process::Write32(0x0C3D0E74, 0x00000000);
                Process::Write32(0x0C3D0E78, 0x00000000);
                Process::Write32(0x0C3D0E7C, 0x00000000);
                Process::Write32(0x0C3D0E80, 0x00000000);
                Process::Write32(0x0C3D0E84, 0x00000000);
                Process::Write32(0x0C3D0E88, 0x00000000);
                Process::Write32(0x0C3D0E8C, 0x00000000);
                Process::Write32(0x0C3D0E94, 0x00000000);
                Process::Write32(0x0C3D0E98, 0x00000000);
                Process::Write32(0x0C3D0E9C, 0x00000000);
                Process::Write32(0x0C3D0EA0, 0x00000000);
                Process::Write32(0x0C3D0EA4, 0x00000000);
                Process::Write32(0x0C3D0EA8, 0x00000000);
                Process::Write32(0x0C3D0EAC, 0x00000000);
                Process::Write32(0x0C3D0EB0, 0x00000000);
                Process::Write32(0x0C3D0EB4, 0x00000000);
                Process::Write32(0x0C3D0EB8, 0x00000000);
                Process::Write32(0x0C3D0EBC, 0x00000000);
                Process::Write32(0x0C3D0EC0, 0x00000000);
                Process::Write32(0x0C3D0EC4, 0x00000000);
                Process::Write32(0x0C3D0EC8, 0x00000000);
                Process::Write32(0x0C3D0ECC, 0x00000000);
            }
		} 
    }

    void YWB_EnterRoomError(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0026F97C, 0xE1A00000);
        }
        else {
            Process::Write32(0x0026F97C, 0xEB0C4A71);
        }
    }

    void YWB_EnterRoomTransparentV1(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0023D4C8, 0xE8800440);
        }
        else {
            Process::Write32(0x0023D4C8, 0xE8900440);
        }
    }

    void YWB_EnterRoomTransparentV2(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0023D564, 0xE89D0440);
        }
        else {
            Process::Write32(0x0023D564, 0xE88D0440);
        }
    }

    void YWB_NoKick(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0026FB00, 0xEA00000E);
        }
        else {
            Process::Write32(0x0026FB00, 0x0A00000E);
        }
    }

    void YWB_YokaiPad(MenuEntry *entry)
    {
        Keyboard keyboard("妖怪パッド編集");
        std::vector < std::string > option =
        {
            
            "通常", "全て持ち物", "全て日記", "全て設定", "全てヘルプ", "全て大辞典", "全てトロフィー", "全て手帳", "全て音楽", "全て動画", "全てメダル交換", "全て妖怪の輪", "全て出動メンバー", "何もない"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
            if (!IsNew3DS()) {
                Process::Write32(0x087E7A30, 0x01020304);
                Process::Write32(0x087E7A34, 0x05060708);
                Process::Write32(0x087E7A38, 0x090A0B0C);
                Process::Write32(0x087E7A3C, 0x00000000);
            }
            else {
                Process::Write32(0x0C3E7A30, 0x01020304);
                Process::Write32(0x0C3E7A34, 0x05060708);
                Process::Write32(0x0C3E7A38, 0x090A0B0C);
                Process::Write32(0x0C3E7A3C, 0x00000000);
            }

        }
        if (userchoice == 1) {
            if (!IsNew3DS()) {
                Process::Write32(0x087E7A30, 0x01010101);
                Process::Write32(0x087E7A34, 0x01010101);
                Process::Write32(0x087E7A38, 0x01010101);
                Process::Write32(0x087E7A3C, 0x01010101);
            }
            else {
                Process::Write32(0x0C3E7A30, 0x01010101);
                Process::Write32(0x0C3E7A34, 0x01010101);
                Process::Write32(0x0C3E7A38, 0x01010101);
                Process::Write32(0x0C3E7A3C, 0x01010101);
            }
		}
        if (userchoice == 2) {
            if (!IsNew3DS()) {
                Process::Write32(0x087E7A30, 0x02020202);
                Process::Write32(0x087E7A34, 0x02020202);
                Process::Write32(0x087E7A38, 0x02020202);
                Process::Write32(0x087E7A3C, 0x02020202);
            }
            else {
                Process::Write32(0x0C3E7A30, 0x02020202);
                Process::Write32(0x0C3E7A34, 0x02020202);
                Process::Write32(0x0C3E7A38, 0x02020202);
                Process::Write32(0x0C3E7A3C, 0x02020202);
            }
		}

        if (userchoice == 3) {
            if (!IsNew3DS()) {
                Process::Write32(0x087E7A30, 0x03030303);
                Process::Write32(0x087E7A34, 0x03030303);
                Process::Write32(0x087E7A38, 0x03030303);
                Process::Write32(0x087E7A3C, 0x03030303);
            }
            else {
                Process::Write32(0x0C3E7A30, 0x03030303);
                Process::Write32(0x0C3E7A34, 0x03030303);
                Process::Write32(0x0C3E7A38, 0x03030303);
                Process::Write32(0x0C3E7A3C, 0x03030303);
            }
		} 
        if (userchoice == 4) {
            if (!IsNew3DS()) {
                Process::Write32(0x087E7A30, 0x04040404);
                Process::Write32(0x087E7A34, 0x04040404);
                Process::Write32(0x087E7A38, 0x04040404);
                Process::Write32(0x087E7A3C, 0x04040404);
            }
            else {
                Process::Write32(0x0C3E7A30, 0x04040404);
                Process::Write32(0x0C3E7A34, 0x04040404);
                Process::Write32(0x0C3E7A38, 0x04040404);
                Process::Write32(0x0C3E7A3C, 0x04040404);
            }
		} 
        if (userchoice == 5) {
            if (!IsNew3DS()) {
                Process::Write32(0x087E7A30, 0x05050505);
                Process::Write32(0x087E7A34, 0x05050505);
                Process::Write32(0x087E7A38, 0x05050505);
                Process::Write32(0x087E7A3C, 0x05050505);
            }
            else {
                Process::Write32(0x0C3E7A30, 0x05050505);
                Process::Write32(0x0C3E7A34, 0x05050505);
                Process::Write32(0x0C3E7A38, 0x05050505);
                Process::Write32(0x0C3E7A3C, 0x05050505);
            }
		} 
        if (userchoice == 6) {
            if (!IsNew3DS()) {
                Process::Write32(0x087E7A30, 0x06060606);
                Process::Write32(0x087E7A34, 0x06060606);
                Process::Write32(0x087E7A38, 0x06060606);
                Process::Write32(0x087E7A3C, 0x06060606);
            }
            else {
                Process::Write32(0x0C3E7A30, 0x06060606);
                Process::Write32(0x0C3E7A34, 0x06060606);
                Process::Write32(0x0C3E7A38, 0x06060606);
                Process::Write32(0x0C3E7A3C, 0x06060606);
            }
		} 
        if (userchoice == 7) {
            if (!IsNew3DS()) {
                Process::Write32(0x087E7A30, 0x07070707);
                Process::Write32(0x087E7A34, 0x07070707);
                Process::Write32(0x087E7A38, 0x07070707);
                Process::Write32(0x087E7A3C, 0x07070707);
            }
            else {
                Process::Write32(0x0C3E7A30, 0x07070707);
                Process::Write32(0x0C3E7A34, 0x07070707);
                Process::Write32(0x0C3E7A38, 0x07070707);
                Process::Write32(0x0C3E7A3C, 0x07070707);
            }
		} 
        if (userchoice == 8) {
            if (!IsNew3DS()) {
                Process::Write32(0x087E7A30, 0x08080808);
                Process::Write32(0x087E7A34, 0x08080808);
                Process::Write32(0x087E7A38, 0x08080808);
                Process::Write32(0x087E7A3C, 0x08080808);
            }
            else {
                Process::Write32(0x0C3E7A30, 0x08080808);
                Process::Write32(0x0C3E7A34, 0x08080808);
                Process::Write32(0x0C3E7A38, 0x08080808);
                Process::Write32(0x0C3E7A3C, 0x08080808);
            }
		} 
        if (userchoice == 9) {
            if (!IsNew3DS()) {
                Process::Write32(0x087E7A30, 0x09090909);
                Process::Write32(0x087E7A34, 0x09090909);
                Process::Write32(0x087E7A38, 0x09090909);
                Process::Write32(0x087E7A3C, 0x09090909);
            }
            else {
                Process::Write32(0x0C3E7A30, 0x09090909);
                Process::Write32(0x0C3E7A34, 0x09090909);
                Process::Write32(0x0C3E7A38, 0x09090909);
                Process::Write32(0x0C3E7A3C, 0x09090909);
            }
		} 
        if (userchoice == 10) {
            if (!IsNew3DS()) {
                Process::Write32(0x087E7A30, 0x0A0A0A0A);
                Process::Write32(0x087E7A34, 0x0A0A0A0A);
                Process::Write32(0x087E7A38, 0x0A0A0A0A);
                Process::Write32(0x087E7A3C, 0x0A0A0A0A);
            }
            else {
                Process::Write32(0x0C3E7A30, 0x0A0A0A0A);
                Process::Write32(0x0C3E7A34, 0x0A0A0A0A);
                Process::Write32(0x0C3E7A38, 0x0A0A0A0A);
                Process::Write32(0x0C3E7A3C, 0x0A0A0A0A);
            }
		} 
        if (userchoice == 11) {
            if (!IsNew3DS()) {
                Process::Write32(0x087E7A30, 0x0B0B0B0B);
                Process::Write32(0x087E7A34, 0x0B0B0B0B);
                Process::Write32(0x087E7A38, 0x0B0B0B0B);
                Process::Write32(0x087E7A3C, 0x0B0B0B0B);
            }
            else {
                Process::Write32(0x0C3E7A30, 0x0B0B0B0B);
                Process::Write32(0x0C3E7A34, 0x0B0B0B0B);
                Process::Write32(0x0C3E7A38, 0x0B0B0B0B);
                Process::Write32(0x0C3E7A3C, 0x0B0B0B0B);
            }
		} 
        if (userchoice == 12) {
            if (!IsNew3DS()) {
                Process::Write32(0x087E7A30, 0x0C0C0C0C);
                Process::Write32(0x087E7A34, 0x0C0C0C0C);
                Process::Write32(0x087E7A38, 0x0C0C0C0C);
                Process::Write32(0x087E7A3C, 0x0C0C0C0C);
            }
            else {
                Process::Write32(0x0C3E7A30, 0x0C0C0C0C);
                Process::Write32(0x0C3E7A34, 0x0C0C0C0C);
                Process::Write32(0x0C3E7A38, 0x0C0C0C0C);
                Process::Write32(0x0C3E7A3C, 0x0C0C0C0C);
            }
		} 
        if (userchoice == 13) {
            if (!IsNew3DS()) {
                Process::Write32(0x087E7A30, 0x00000000);
                Process::Write32(0x087E7A34, 0x00000000);
                Process::Write32(0x087E7A38, 0x00000000);
                Process::Write32(0x087E7A3C, 0x00000000);
            }
            else {
                Process::Write32(0x0C3E7A30, 0x00000000);
                Process::Write32(0x0C3E7A34, 0x00000000);
                Process::Write32(0x0C3E7A38, 0x00000000);
                Process::Write32(0x0C3E7A3C, 0x00000000);
            }
		} 
    }

    void YWB_Onidama(MenuEntry *entry)
    {
        u32 onidama;
        Keyboard keyboard("鬼玉数変更\n16進数で入力してください。");
		if (keyboard.Open(onidama) != -1) {
            if (!IsNew3DS()) {
                Process::Write32(0x087CBF2C, onidama);
            }
            else {
                Process::Write32(0x0C3CBF2C, onidama);
            }
        }
    }

    void YWB_Kisho(MenuEntry *entry)
    {
        u32 kisho;
        Keyboard keyboard("記章数変更\n16進数で入力してください。");
		if (keyboard.Open(kisho) != -1) {
            if (!IsNew3DS()) {
                Process::Write32(0x087CBFBC, kisho);
            }
            else {
                Process::Write32(0x0C3CBFBC, kisho);
            }
        }
    }

    void YWB_LRCamera(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0051FBD0, 0xE3A010FF);
            Process::Write32(0x0051FC58, 0xE3A010FF);
            Process::Write32(0x00523174, 0xE3A010FF);
            Process::Write32(0x005231A8, 0xE3A010FF);
        }
        else {
            Process::Write32(0x0051FBD0, 0xE3A0100A);
            Process::Write32(0x0051FC58, 0xE3A0100B);
            Process::Write32(0x00523174, 0xE3A0100A);
            Process::Write32(0x005231A8, 0xE3A0100B);
        }
    }

    void YWB_MissionSelectPlayer(MenuEntry *entry)
    {
        Keyboard keyboard("プレイヤーにミッション選ばせる");
        std::vector < std::string > option =
        {
            "P1", "P2", "P3", "P4"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
			if (!IsNew3DS()) {
                Process::Write32(0x0876C824, 0x00000001);
            }
            else {
                Process::Write32(0x0C36C824, 0x00000001);
            }
		}
        if (userchoice == 1) {
			if (!IsNew3DS()) {
                Process::Write32(0x0876C824, 0x00000002);
            }
            else {
                Process::Write32(0x0C36C824, 0x00000002);
            }
		}
        if (userchoice == 2) {
			if (!IsNew3DS()) {
                Process::Write32(0x0876C824, 0x00000003);
            }
            else {
                Process::Write32(0x0C36C824, 0x00000003);
            }
		}
        if (userchoice == 3) {
			if (!IsNew3DS()) {
                Process::Write32(0x0876C824, 0x00000004);
            }
            else {
                Process::Write32(0x0C36C824, 0x00000004);
            }
		}
    }

    void YWB_KeyboardRegulationInvalid(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write16(0x002DBF2C, 0x9999);
        }
        else {
            Process::Write16(0x002DBF2C, 0x0077);
        }
    }

    void YWB_AllAvoidance(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x003CC714, 0xEB0999AD);
			Process::Write32(0x00632DD0, 0xE3A00000);
            Process::Write32(0x00632DD4, 0xE5D6B004);
            Process::Write32(0x00632DD8, 0xE35B0001);
            Process::Write32(0x00632DDC, 0x03A00001);
            Process::Write32(0x00632DE0, 0x135B0002);
            Process::Write32(0x00632DE4, 0x03A00001);
            Process::Write32(0x00632DE8, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x003CC714, 0xE3A00000);
        }
    }

    void YWB_Rank100Match(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            if (!IsNew3DS()) {
                Process::Write32(0x0886F968, 0x00000063);
                Process::Write32(0x0886F994, 0x00000063);
            }
            else {
                Process::Write32(0x0C46F968, 0x00000063);
                Process::Write32(0x0C46F994, 0x00000063);
            }
        }
        else {
            if (!IsNew3DS()) {
                Process::Write32(0x0886F968, 0x00000000);
                Process::Write32(0x0886F994, 0x00000000);
            }
            else {
                Process::Write32(0x0C46F968, 0x00000000);
                Process::Write32(0x0C46F994, 0x00000000);
            }
        }
    }

    void YWB_PlayerJack(MenuEntry *entry)
    {
        Keyboard keyboard("乗っ取り");
        std::vector < std::string > option =
        {
            "P1", "P2", "P3", "P4"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
            if (!IsNew3DS()) {
                Process::Write8(0x0886F79C, 0x00000001);
                Process::Write8(0x0886F9C0, 0x00000001);
            }
            else {
                Process::Write8(0x0C46F79C, 0x00000001);
                Process::Write8(0x0C46F9C0, 0x00000001);
            }
		}
        if (userchoice == 1) {
            if (!IsNew3DS()) {
                Process::Write8(0x0886F79C, 0x00000002);
                Process::Write8(0x0886F9C0, 0x00000002);
            }
            else {
                Process::Write8(0x0C46F79C, 0x00000002);
                Process::Write8(0x0C46F9C0, 0x00000002);
            }
		}
        if (userchoice == 2) {
            if (!IsNew3DS()) {
                Process::Write8(0x0886F79C, 0x00000003);
                Process::Write8(0x0886F9C0, 0x00000003);
            }
            else {
                Process::Write8(0x0C46F79C, 0x00000003);
                Process::Write8(0x0C46F9C0, 0x00000003);
            }
		}
        if (userchoice == 3) {
            if (!IsNew3DS()) {
                Process::Write8(0x0886F79C, 0x00000004);
                Process::Write8(0x0886F9C0, 0x00000004);
            }
            else {
                Process::Write8(0x0C46F79C, 0x00000004);
                Process::Write8(0x0C46F9C0, 0x00000004);
            }
		}
    }

    void YWB_ChangeRank(MenuEntry *entry)
    {
        u8 rank;
        Keyboard keyboard("ランク変更\n16進数で入力してください。");
		if (keyboard.Open(rank) != -1) {
            if (!IsNew3DS()) {
                Process::Write32(0x087D0D28, rank);
            }
            else {
                Process::Write32(0x0C3D0D28, rank);
            }
        }
    }

    void YWB_MessageDrawType(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x001DEC38, 0xE3A03000);
        }
        else {
            Process::Write32(0x001DEC38, 0xE3A03001);
        }
    }

    void YWB_PlayerStateChange(MenuEntry *entry)
    {
        Keyboard keyboard("プレイヤーの状態変更");
        std::vector < std::string > option =
        {
            "発光", "透明", "OFF"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
            Process::Write32(0x00161140, 0x3FFFFFFF);
		}
        if (userchoice == 1) {
            Process::Write32(0x00161140, 0xFFFFFFFF);
		}
        if (userchoice == 2) {
            Process::Write32(0x00161140, 0x3F800000);
		}
    }

    void YWB_AutoTechnique(MenuEntry *entry)
    {
        Keyboard keyboard("技自動発動");
        std::vector < std::string > option =
        {
            "Aボタン技", "Xボタン技", "Yボタン技", "必殺技", "OFF"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
            Process::Write32(0x003FAD10, 0xE3A08000);
		}
        if (userchoice == 1) {
            Process::Write32(0x003FAD10, 0xE3A08001);
		}
        if (userchoice == 2) {
            Process::Write32(0x003FAD10, 0xE3A08002);
		}
        if (userchoice == 3) {
            Process::Write32(0x003FAD10, 0xE3A08003);
		}
        if (userchoice == 4) {
            Process::Write32(0x003FAD10, 0x13A08000);
		}
    }

    void YWB_DamageRecoveryDecision(MenuEntry *entry)
    {
        Keyboard keyboard("攻撃/回復 判定変更");
        std::vector < std::string > option =
        {
            "回復", "攻撃", "OFF"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
            Process::Write32(0x003D40E4, 0xEA000001);
		}
        if (userchoice == 1) {
            Process::Write32(0x003D40E4, 0xEA000003);
		}
        if (userchoice == 2) {
            Process::Write32(0x003D40E4, 0x0A000001);
		}
    }
    
    static const std::vector< U16_TEXT_VALUE > yokaipad_list =
	{
		{"通常", 0x07E4},
		{"ジミーショップ", 0x0A55},
		{"合成", 0x0A5A},
		{"わかめくん", 0x0A48},
		{"コンブさん", 0x0A46},
		{"メカブちゃん", 0x0A47},
		{"さすらい闘技場", 0x0A6E},
		{"リフォーム", 0x0A65},
		{"ガシャ", 0x0834},
		{"出動", 0x0A2B},
		{"メンバー編成", 0x0802},
		{"成長", 0x0A32},
		{"連動", 0x0A96},
		{"魂変化", 0x0A37},
	};

    void YWB_YokaiPadChange(MenuEntry *entry)
    {

        items_ywb.clear();
        if (items_ywb.empty())
            for(const U16_TEXT_VALUE &i: yokaipad_list)
            items_ywb.push_back(i.name);
        Keyboard keyboard("妖怪パッド変更\n", items_ywb);
        int choice = keyboard.Open();
        if (choice >= 0)
        {
            Process::Write16(0x00383C08,yokaipad_list[choice].id);
        }
    }

    void YWB_MessageSpeed(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x001DEC5C, 0xE3500009);
        }
        else {
            Process::Write32(0x001DEC5C, 0xE3500003);
        }
    }

    void YWB_TalkMessageThrough(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x001DEBC4, 0xE35000FF);
        }
        else {
            Process::Write32(0x001DEBC4, 0xE3500002);
        }
    }

    void YWB_DamageBoost(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x003CC6D0, 0xEB0999A0);
            Process::Write32(0x00632D58, 0xE3510000);
            Process::Write32(0x00632D5C, 0xE5D6B004);
            Process::Write32(0x00632D60, 0xE35B0001);
            Process::Write32(0x00632D64, 0x03A01000);
            Process::Write32(0x00632D68, 0x135B0002);
            Process::Write32(0x00632D6C, 0x03A01000);
            Process::Write32(0x00632D70, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x03CC6D0, 0xE3510000);
            Process::Write32(0x0632D58, 0x00000000);
            Process::Write32(0x0632D5C, 0x00000000);
            Process::Write32(0x0632D60, 0x00000000);
            Process::Write32(0x0632D64, 0x00000000);
            Process::Write32(0x0632D68, 0x00000000);
            Process::Write32(0x0632D6C, 0x00000000);
            Process::Write32(0x0632D70, 0x00000000);
        }
    }

    void YWB_TechniqueCancel(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x003FB050, 0xE3A01001);
        }
        else {
            Process::Write32(0x003FB050, 0xE59D1010);
        }
    }

    void YWB_Status65535(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x003BFF20, 0xEB09CB5E);
            Process::Write32(0x003BFF90, 0xEB09CB42);
            Process::Write32(0x003BFFF0, 0xEB09CB2A);
            Process::Write32(0x003C004C, 0xEB09CB13);
            Process::Write32(0x00632CA0, 0xE92D4001);
            Process::Write32(0x00632CA4, 0xE59F2008);
            Process::Write32(0x00632CA8, 0xE1A00002);
            Process::Write32(0x00632CAC, 0xE0C400B2);
            Process::Write32(0x00632CB0, 0xE8BD8001);
            Process::Write32(0x00632CB4, 0x0000FFFF);
        }
        else {
            Process::Write32(0x003BFF20, 0xE0C400B2);
            Process::Write32(0x003BFF90, 0xE0C400B2);
            Process::Write32(0x003BFFF0, 0xE0C400B2);
            Process::Write32(0x003C004C, 0xE1C400B0);
            Process::Write32(0x00632CA0, 0x00000000);
            Process::Write32(0x00632CA4, 0x00000000);
            Process::Write32(0x00632CA8, 0x00000000);
            Process::Write32(0x00632CAC, 0x00000000);
            Process::Write32(0x00632CB0, 0x00000000);
            Process::Write32(0x00632CB4, 0x00000000);
        }
    }

    void YWB_FriendChanceLimit(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x003D8F08, 0xE35100FF);
        }
        else {
            Process::Write32(0x003D8F08, 0xE3510003);
        }
    }

    void YWB_HukidashiSize(MenuEntry *entry)
    {
        u32 size;
        Keyboard keyboard("ふきだしサイズ変更\n16進数で入力してください。\nデフォルト:3F800000");
		if (keyboard.Open(size) != -1) {
            Process::Write32(0x005F8290, size);
        }
    }

    void YWB_DrawPlayerID(MenuEntry *entry)
    {
        u32 player1_id, player2_id, player3_id, player4_id;
        if (!IsNew3DS()) {
            Process::Read32(0x0886FBD0, player1_id);
            Process::Read32(0x0886FC80, player2_id);
            Process::Read32(0x0886FD30, player3_id);
            Process::Read32(0x0886FDE0, player4_id);
        }
        else {
            Process::Read32(0x0C46FBD0, player1_id);
            Process::Read32(0x0C46FC80, player2_id);
            Process::Read32(0x0C46FD30, player3_id);
            Process::Read32(0x0C46FDE0, player4_id);
        }

        OSDManager.Lock();
        const Screen &scr = OSD::GetTopScreen();
        scr.Draw(Utils::Format("Player1 ID = %X", player1_id), 0, 0);
        scr.Draw(Utils::Format("Player2 ID = %X", player2_id), 0, 10);
        scr.Draw(Utils::Format("Player3 ID = %X", player3_id), 0, 20);
        scr.Draw(Utils::Format("Player4 ID = %X", player4_id), 0, 30);
        
        OSDManager.Unlock();
    }

    void YWB_DrawPlayerIDFriend(MenuEntry *entry)
    {
        u32 playerid;
        if (!IsNew3DS()) {
            Process::Read32(0x0886C8A4, playerid);
        }
        else {
            Process::Read32(0x0C46C8A4, playerid);
        }
        
        OSDManager.Lock();
        const Screen &scr = OSD::GetTopScreen();
        scr.Draw(Utils::Format("FriendRequestID = %X", playerid), 0, 40);
        
        OSDManager.Unlock();
    }

    void YWB_DrawPlayerIDBlock(MenuEntry *entry)
    {
        u32 playerid;
        if (!IsNew3DS()) {
            Process::Read32(0x087D8594, playerid);
        }
        else {
            Process::Read32(0x0C3D8594, playerid);
        }
        
        OSDManager.Lock();
        const Screen &scr = OSD::GetTopScreen();
        scr.Draw(Utils::Format("BlockPlayerID = %X", playerid), 0, 50);
        
        OSDManager.Unlock();
    }

    void YWB_YokaiEditor1(MenuEntry *entry)
    {
        u16 storage_id;
        u32 address;
        u32 storage_id2;
        if (!IsNew3DS()) {
            Process::Read32(0x087CC060, storage_id2);
            if (storage_id2 == 0x00000000) {
                MessageBox("妖怪をセットしてから実行して下さい。")();
                return;
            }
            else {
                Process::Read16(0x087CC060, storage_id);
            }
        }
        else {
            Process::Read32(0x0C3CC060, storage_id2);
            if (storage_id2 == 0x00000000) {
                MessageBox("妖怪をセットしてから実行して下さい。")();
                return;
            }
            else {
                Process::Read16(0x0C3CC060, storage_id);
            }
        }
        u32 difference = storage_id * 0x88;

        Keyboard keyboard("リーダー妖怪 編集");
        std::vector < std::string > option =
        {
            "妖怪変更", "Aボタン技変更", "Xボタン技変更", "Yボタン技変更", "必殺技変更", "HP変更", "レベル変更", "力変更", "妖力変更", "守り変更", "スキル変更", "装備変更"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
            u32 value;
            Keyboard keyboard("どのように変更しますか？");
            std::vector < std::string > option =
            {
                "大辞典から", "IDを入力"
            };
            keyboard.Populate(option);
            int userchoice = keyboard.Open();
            if (!IsNew3DS()) {
                address = 0x087BBC94 + difference;
            }
            else {
                address = 0x0C3BBC94 + difference;
            }
            if (userchoice == 0) {
                if (!IsNew3DS()) {
                    Process::Read32(0x08AC7914, value);
                    if (value == 0x00000000) {
                        MessageBox("妖怪大辞典で妖怪を選択してください。")();
                    }
                    else {
                        Process::Write32(address, value);
                    }
                }
                else {
                    Process::Read32(0x0C6C7914, value);
                    if (value == 0x00000000) {
                        MessageBox("妖怪大辞典で妖怪を選択してください。")();
                    }
                    else {
                        Process::Write32(address, value);
                    }
                }
            }
            if (userchoice == 1) {
                Keyboard keyboard("妖怪変更\n妖怪IDを入力してください。");
                if (keyboard.Open(value) != -1) {
                    Process::Write32(address, value);
                }
            }
		}
        if (userchoice == 1) {
            u32 address2;
            u32 value, value2;
            Keyboard keyboard("Aボタン技変更\n技ID1を入力してください。");
		    if (keyboard.Open(value) != -1) {
                Keyboard keyboard("Aボタン技変更\n技ID2を入力してください。");
		        if (keyboard.Open(value2) != -1) {  
                    if (!IsNew3DS()) {
                        address = 0x087BBCB8 + difference;
                        address2 = 0x087BBCF0 + difference;
                    }
                    else {
                        address = 0x0C3BBCB8 + difference;
                        address2 = 0x0C3BBCF0 + difference;
                    }
                    Process::Write32(address, value);
                    Process::Write32(address2, value2);
                }
            }
		}
        if (userchoice == 2) {
            u32 address2;
            u32 value, value2;
            Keyboard keyboard("Xボタン技変更\n技ID1を入力してください。");
		    if (keyboard.Open(value) != -1) {
                Keyboard keyboard("Xボタン技変更\n技ID2を入力してください。");
		        if (keyboard.Open(value2) != -1) {  
                    if (!IsNew3DS()) {
                        address = 0x087BBCBC + difference;
                        address2 = 0x087BBCF4 + difference;
                    }
                    else {
                        address = 0x0C3BBCBC + difference;
                        address2 = 0x0C3BBCF4 + difference;
                    }
                    Process::Write32(address, value);
                    Process::Write32(address2, value2);
                }
            }
		}
        if (userchoice == 3) {
            u32 address2;
            u32 value, value2;
            Keyboard keyboard("Yボタン技変更\n技ID1を入力してください。");
		    if (keyboard.Open(value) != -1) {
                Keyboard keyboard("Yボタン技変更\n技ID2を入力してください。");
		        if (keyboard.Open(value2) != -1) {  
                    if (!IsNew3DS()) {
                        address = 0x087BBCC0 + difference;
                        address2 = 0x087BBCF8 + difference;
                    }
                    else {
                        address = 0x0C3BBCC0 + difference;
                        address2 = 0x0C3BBCF8 + difference;
                    }
                    Process::Write32(address, value);
                    Process::Write32(address2, value2);
                }
            }
		}
        if (userchoice == 4) {
            u32 value;
            Keyboard keyboard("必殺技変更\n技IDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBC74 + difference;
                }
                else {
                    address = 0x0C3BBC74 + difference;
                }
                Process::Write32(address, value);
            }
		}
        if (userchoice == 5) {
            u16 value;
            Keyboard keyboard("HP変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCDC + difference;
                }
                else {
                    address = 0x0C3BBCDC + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 6) {
            u8 value;
            Keyboard keyboard("レベル変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCD5 + difference;
                }
                else {
                    address = 0x0C3BBCD5 + difference;
                }
                Process::Write8(address, value);
            }
		}
        if (userchoice == 7) {
            u16 value;
            Keyboard keyboard("力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCDE + difference;
                }
                else {
                    address = 0x0C3BBCDE + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 8) {
            u16 value;
            Keyboard keyboard("妖力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCE0 + difference;
                }
                else {
                    address = 0x0C3BBCE0 + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 9) {
            u16 value;
            Keyboard keyboard("守り変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCE2 + difference;
                }
                else {
                    address = 0x0C3BBCE2 + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 10) {
            u32 value;
            Keyboard keyboard("スキル変更\nスキルIDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBFAC + difference;
                }
                else {
                    address = 0x0C3BBFAC + difference;
                }
                Process::Write32(address, value);
            }
		}
        if (userchoice == 11) {
            u32 value;
            Keyboard keyboard("装備変更\n装備IDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087CE828 + difference;
                }
                else {
                    address = 0x0C3CE828 + difference;
                }
                Process::Write32(address, value);
            }
		}
    }

    void YWB_YokaiEditor2(MenuEntry *entry)
    {
        u16 storage_id;
        u32 address;
        u32 storage_id2;
        if (!IsNew3DS()) {
            Process::Read32(0x087CC064, storage_id2);
            if (storage_id2 == 0x00000000) {
                MessageBox("妖怪をセットしてから実行して下さい。")();
                return;
            }
            else {
                Process::Read16(0x087CC064, storage_id);
            }
        }
        else {
            Process::Read32(0x0C3CC064, storage_id2);
            if (storage_id2 == 0x00000000) {
                MessageBox("妖怪をセットしてから実行して下さい。")();
                return;
            }
            else {
                Process::Read16(0x0C3CC064, storage_id);
            }
        }
        u32 difference = storage_id * 0x88;

        Keyboard keyboard("おとも妖怪1 編集");
        std::vector < std::string > option =
        {
            "妖怪変更", "Aボタン技変更", "Xボタン技変更", "Yボタン技変更", "必殺技変更", "HP変更", "レベル変更", "力変更", "妖力変更", "守り変更", "スキル変更", "装備変更"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
            u32 value;
            Keyboard keyboard("どのように変更しますか？");
            std::vector < std::string > option =
            {
                "大辞典から", "IDを入力"
            };
            keyboard.Populate(option);
            int userchoice = keyboard.Open();
            if (!IsNew3DS()) {
                address = 0x087BBC94 + difference;
            }
            else {
                address = 0x0C3BBC94 + difference;
            }
            if (userchoice == 0) {
                if (!IsNew3DS()) {
                    Process::Read32(0x08AC7914, value);
                    if (value == 0x00000000) {
                        MessageBox("妖怪大辞典で妖怪を選択してください。")();
                    }
                    else {
                        Process::Write32(address, value);
                    }
                }
                else {
                    Process::Read32(0x0C6C7914, value);
                    if (value == 0x00000000) {
                        MessageBox("妖怪大辞典で妖怪を選択してください。")();
                    }
                    else {
                        Process::Write32(address, value);
                    }
                }
            }
            if (userchoice == 1) {
                Keyboard keyboard("妖怪変更\n妖怪IDを入力してください。");
                if (keyboard.Open(value) != -1) {
                    Process::Write32(address, value);
                }
            }
		}
        if (userchoice == 1) {
            u32 address2;
            u32 value, value2;
            Keyboard keyboard("Aボタン技変更\n技ID1を入力してください。");
		    if (keyboard.Open(value) != -1) {
                Keyboard keyboard("Aボタン技変更\n技ID2を入力してください。");
		        if (keyboard.Open(value2) != -1) {  
                    if (!IsNew3DS()) {
                        address = 0x087BBCB8 + difference;
                        address2 = 0x087BBCF0 + difference;
                    }
                    else {
                        address = 0x0C3BBCB8 + difference;
                        address2 = 0x0C3BBCF0 + difference;
                    }
                    Process::Write32(address, value);
                    Process::Write32(address2, value2);
                }
            }
		}
        if (userchoice == 2) {
            u32 address2;
            u32 value, value2;
            Keyboard keyboard("Xボタン技変更\n技ID1を入力してください。");
		    if (keyboard.Open(value) != -1) {
                Keyboard keyboard("Xボタン技変更\n技ID2を入力してください。");
		        if (keyboard.Open(value2) != -1) {  
                    if (!IsNew3DS()) {
                        address = 0x087BBCBC + difference;
                        address2 = 0x087BBCF4 + difference;
                    }
                    else {
                        address = 0x0C3BBCBC + difference;
                        address2 = 0x0C3BBCF4 + difference;
                    }
                    Process::Write32(address, value);
                    Process::Write32(address2, value2);
                }
            }
		}
        if (userchoice == 3) {
            u32 address2;
            u32 value, value2;
            Keyboard keyboard("Yボタン技変更\n技ID1を入力してください。");
		    if (keyboard.Open(value) != -1) {
                Keyboard keyboard("Yボタン技変更\n技ID2を入力してください。");
		        if (keyboard.Open(value2) != -1) {  
                    if (!IsNew3DS()) {
                        address = 0x087BBCC0 + difference;
                        address2 = 0x087BBCF8 + difference;
                    }
                    else {
                        address = 0x0C3BBCC0 + difference;
                        address2 = 0x0C3BBCF8 + difference;
                    }
                    Process::Write32(address, value);
                    Process::Write32(address2, value2);
                }
            }
		}
        if (userchoice == 4) {
            u32 value;
            Keyboard keyboard("必殺技変更\n技IDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBC74 + difference;
                }
                else {
                    address = 0x0C3BBC74 + difference;
                }
                Process::Write32(address, value);
            }
		}
        if (userchoice == 5) {
            u16 value;
            Keyboard keyboard("HP変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCDC + difference;
                }
                else {
                    address = 0x0C3BBCDC + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 6) {
            u8 value;
            Keyboard keyboard("レベル変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCD5 + difference;
                }
                else {
                    address = 0x0C3BBCD5 + difference;
                }
                Process::Write8(address, value);
            }
		}
        if (userchoice == 7) {
            u16 value;
            Keyboard keyboard("力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCDE + difference;
                }
                else {
                    address = 0x0C3BBCDE + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 8) {
            u16 value;
            Keyboard keyboard("妖力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCE0 + difference;
                }
                else {
                    address = 0x0C3BBCE0 + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 9) {
            u16 value;
            Keyboard keyboard("守り変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCE2 + difference;
                }
                else {
                    address = 0x0C3BBCE2 + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 10) {
            u32 value;
            Keyboard keyboard("スキル変更\nスキルIDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBFAC + difference;
                }
                else {
                    address = 0x0C3BBFAC + difference;
                }
                Process::Write32(address, value);
            }
		}
        if (userchoice == 11) {
            u32 value;
            Keyboard keyboard("装備変更\n装備IDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087CE828 + difference;
                }
                else {
                    address = 0x0C3CE828 + difference;
                }
                Process::Write32(address, value);
            }
		}
    }

    void YWB_YokaiEditor3(MenuEntry *entry)
    {
        u16 storage_id;
        u32 address;
        u32 storage_id2;
        if (!IsNew3DS()) {
            Process::Read32(0x087CC068, storage_id2);
            if (storage_id2 == 0x00000000) {
                MessageBox("妖怪をセットしてから実行して下さい。")();
                return;
            }
            else {
                Process::Read16(0x087CC068, storage_id);
            }
        }
        else {
            Process::Read32(0x0C3CC068, storage_id2);
            if (storage_id2 == 0x00000000) {
                MessageBox("妖怪をセットしてから実行して下さい。")();
                return;
            }
            else {
                Process::Read16(0x0C3CC068, storage_id);
            }
        }
        u32 difference = storage_id * 0x88;

        Keyboard keyboard("おとも妖怪2 編集");
        std::vector < std::string > option =
        {
            "妖怪変更", "Aボタン技変更", "Xボタン技変更", "Yボタン技変更", "必殺技変更", "HP変更", "レベル変更", "力変更", "妖力変更", "守り変更", "スキル変更", "装備変更"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
            u32 value;
            Keyboard keyboard("どのように変更しますか？");
            std::vector < std::string > option =
            {
                "大辞典から", "IDを入力"
            };
            keyboard.Populate(option);
            int userchoice = keyboard.Open();
            if (!IsNew3DS()) {
                address = 0x087BBC94 + difference;
            }
            else {
                address = 0x0C3BBC94 + difference;
            }
            if (userchoice == 0) {
                if (!IsNew3DS()) {
                    Process::Read32(0x08AC7914, value);
                    if (value == 0x00000000) {
                        MessageBox("妖怪大辞典で妖怪を選択してください。")();
                    }
                    else {
                        Process::Write32(address, value);
                    }
                }
                else {
                    Process::Read32(0x0C6C7914, value);
                    if (value == 0x00000000) {
                        MessageBox("妖怪大辞典で妖怪を選択してください。")();
                    }
                    else {
                        Process::Write32(address, value);
                    }
                }
            }
            if (userchoice == 1) {
                Keyboard keyboard("妖怪変更\n妖怪IDを入力してください。");
                if (keyboard.Open(value) != -1) {
                    Process::Write32(address, value);
                }
            }
		}
        if (userchoice == 1) {
            u32 address2;
            u32 value, value2;
            Keyboard keyboard("Aボタン技変更\n技ID1を入力してください。");
		    if (keyboard.Open(value) != -1) {
                Keyboard keyboard("Aボタン技変更\n技ID2を入力してください。");
		        if (keyboard.Open(value2) != -1) {  
                    if (!IsNew3DS()) {
                        address = 0x087BBCB8 + difference;
                        address2 = 0x087BBCF0 + difference;
                    }
                    else {
                        address = 0x0C3BBCB8 + difference;
                        address2 = 0x0C3BBCF0 + difference;
                    }
                    Process::Write32(address, value);
                    Process::Write32(address2, value2);
                }
            }
		}
        if (userchoice == 2) {
            u32 address2;
            u32 value, value2;
            Keyboard keyboard("Xボタン技変更\n技ID1を入力してください。");
		    if (keyboard.Open(value) != -1) {
                Keyboard keyboard("Xボタン技変更\n技ID2を入力してください。");
		        if (keyboard.Open(value2) != -1) {  
                    if (!IsNew3DS()) {
                        address = 0x087BBCBC + difference;
                        address2 = 0x087BBCF4 + difference;
                    }
                    else {
                        address = 0x0C3BBCBC + difference;
                        address2 = 0x0C3BBCF4 + difference;
                    }
                    Process::Write32(address, value);
                    Process::Write32(address2, value2);
                }
            }
		}
        if (userchoice == 3) {
            u32 address2;
            u32 value, value2;
            Keyboard keyboard("Yボタン技変更\n技ID1を入力してください。");
		    if (keyboard.Open(value) != -1) {
                Keyboard keyboard("Yボタン技変更\n技ID2を入力してください。");
		        if (keyboard.Open(value2) != -1) {  
                    if (!IsNew3DS()) {
                        address = 0x087BBCC0 + difference;
                        address2 = 0x087BBCF8 + difference;
                    }
                    else {
                        address = 0x0C3BBCC0 + difference;
                        address2 = 0x0C3BBCF8 + difference;
                    }
                    Process::Write32(address, value);
                    Process::Write32(address2, value2);
                }
            }
		}
        if (userchoice == 4) {
            u32 value;
            Keyboard keyboard("必殺技変更\n技IDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBC74 + difference;
                }
                else {
                    address = 0x0C3BBC74 + difference;
                }
                Process::Write32(address, value);
            }
		}
        if (userchoice == 5) {
            u16 value;
            Keyboard keyboard("HP変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCDC + difference;
                }
                else {
                    address = 0x0C3BBCDC + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 6) {
            u8 value;
            Keyboard keyboard("レベル変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCD5 + difference;
                }
                else {
                    address = 0x0C3BBCD5 + difference;
                }
                Process::Write8(address, value);
            }
		}
        if (userchoice == 7) {
            u16 value;
            Keyboard keyboard("力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCDE + difference;
                }
                else {
                    address = 0x0C3BBCDE + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 8) {
            u16 value;
            Keyboard keyboard("妖力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCE0 + difference;
                }
                else {
                    address = 0x0C3BBCE0 + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 9) {
            u16 value;
            Keyboard keyboard("守り変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCE2 + difference;
                }
                else {
                    address = 0x0C3BBCE2 + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 10) {
            u32 value;
            Keyboard keyboard("スキル変更\nスキルIDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBFAC + difference;
                }
                else {
                    address = 0x0C3BBFAC + difference;
                }
                Process::Write32(address, value);
            }
		}
        if (userchoice == 11) {
            u32 value;
            Keyboard keyboard("装備変更\n装備IDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087CE828 + difference;
                }
                else {
                    address = 0x0C3CE828 + difference;
                }
                Process::Write32(address, value);
            }
		}
    }

    void YWB_YokaiEditor4(MenuEntry *entry)
    {
        u16 storage_id;
        u32 address;
        u32 storage_id2;
        if (!IsNew3DS()) {
            Process::Read32(0x087CC06C, storage_id2);
            if (storage_id2 == 0x00000000) {
                MessageBox("妖怪をセットしてから実行して下さい。")();
                return;
            }
            else {
                Process::Read16(0x087CC06C, storage_id);
            }
        }
        else {
            Process::Read32(0x0C3CC06C, storage_id2);
            if (storage_id2 == 0x00000000) {
                MessageBox("妖怪をセットしてから実行して下さい。")();
                return;
            }
            else {
                Process::Read16(0x0C3CC06C, storage_id);
            }
        }
        u32 difference = storage_id * 0x88;

        Keyboard keyboard("おとも妖怪3 編集");
        std::vector < std::string > option =
        {
            "妖怪変更", "Aボタン技変更", "Xボタン技変更", "Yボタン技変更", "必殺技変更", "HP変更", "レベル変更", "力変更", "妖力変更", "守り変更", "スキル変更", "装備変更"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
            u32 value;
            Keyboard keyboard("どのように変更しますか？");
            std::vector < std::string > option =
            {
                "大辞典から", "IDを入力"
            };
            keyboard.Populate(option);
            int userchoice = keyboard.Open();
            if (!IsNew3DS()) {
                address = 0x087BBC94 + difference;
            }
            else {
                address = 0x0C3BBC94 + difference;
            }
            if (userchoice == 0) {
                if (!IsNew3DS()) {
                    Process::Read32(0x08AC7914, value);
                    if (value == 0x00000000) {
                        MessageBox("妖怪大辞典で妖怪を選択してください。")();
                    }
                    else {
                        Process::Write32(address, value);
                    }
                }
                else {
                    Process::Read32(0x0C6C7914, value);
                    if (value == 0x00000000) {
                        MessageBox("妖怪大辞典で妖怪を選択してください。")();
                    }
                    else {
                        Process::Write32(address, value);
                    }
                }
            }
            if (userchoice == 1) {
                Keyboard keyboard("妖怪変更\n妖怪IDを入力してください。");
                if (keyboard.Open(value) != -1) {
                    Process::Write32(address, value);
                }
            }
		}
        if (userchoice == 1) {
            u32 address2;
            u32 value, value2;
            Keyboard keyboard("Aボタン技変更\n技ID1を入力してください。");
		    if (keyboard.Open(value) != -1) {
                Keyboard keyboard("Aボタン技変更\n技ID2を入力してください。");
		        if (keyboard.Open(value2) != -1) {  
                    if (!IsNew3DS()) {
                        address = 0x087BBCB8 + difference;
                        address2 = 0x087BBCF0 + difference;
                    }
                    else {
                        address = 0x0C3BBCB8 + difference;
                        address2 = 0x0C3BBCF0 + difference;
                    }
                    Process::Write32(address, value);
                    Process::Write32(address2, value2);
                }
            }
		}
        if (userchoice == 2) {
            u32 address2;
            u32 value, value2;
            Keyboard keyboard("Xボタン技変更\n技ID1を入力してください。");
		    if (keyboard.Open(value) != -1) {
                Keyboard keyboard("Xボタン技変更\n技ID2を入力してください。");
		        if (keyboard.Open(value2) != -1) {  
                    if (!IsNew3DS()) {
                        address = 0x087BBCBC + difference;
                        address2 = 0x087BBCF4 + difference;
                    }
                    else {
                        address = 0x0C3BBCBC + difference;
                        address2 = 0x0C3BBCF4 + difference;
                    }
                    Process::Write32(address, value);
                    Process::Write32(address2, value2);
                }
            }
		}
        if (userchoice == 3) {
            u32 address2;
            u32 value, value2;
            Keyboard keyboard("Yボタン技変更\n技ID1を入力してください。");
		    if (keyboard.Open(value) != -1) {
                Keyboard keyboard("Yボタン技変更\n技ID2を入力してください。");
		        if (keyboard.Open(value2) != -1) {  
                    if (!IsNew3DS()) {
                        address = 0x087BBCC0 + difference;
                        address2 = 0x087BBCF8 + difference;
                    }
                    else {
                        address = 0x0C3BBCC0 + difference;
                        address2 = 0x0C3BBCF8 + difference;
                    }
                    Process::Write32(address, value);
                    Process::Write32(address2, value2);
                }
            }
		}
        if (userchoice == 4) {
            u32 value;
            Keyboard keyboard("必殺技変更\n技IDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBC74 + difference;
                }
                else {
                    address = 0x0C3BBC74 + difference;
                }
                Process::Write32(address, value);
            }
		}
        if (userchoice == 5) {
            u16 value;
            Keyboard keyboard("HP変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCDC + difference;
                }
                else {
                    address = 0x0C3BBCDC + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 6) {
            u8 value;
            Keyboard keyboard("レベル変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCD5 + difference;
                }
                else {
                    address = 0x0C3BBCD5 + difference;
                }
                Process::Write8(address, value);
            }
		}
        if (userchoice == 7) {
            u16 value;
            Keyboard keyboard("力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCDE + difference;
                }
                else {
                    address = 0x0C3BBCDE + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 8) {
            u16 value;
            Keyboard keyboard("妖力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCE0 + difference;
                }
                else {
                    address = 0x0C3BBCE0 + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 9) {
            u16 value;
            Keyboard keyboard("守り変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBCE2 + difference;
                }
                else {
                    address = 0x0C3BBCE2 + difference;
                }
                Process::Write16(address, value);
            }
		}
        if (userchoice == 10) {
            u32 value;
            Keyboard keyboard("スキル変更\nスキルIDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087BBFAC + difference;
                }
                else {
                    address = 0x0C3BBFAC + difference;
                }
                Process::Write32(address, value);
            }
		}
        if (userchoice == 11) {
            u32 value;
            Keyboard keyboard("装備変更\n装備IDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                if (!IsNew3DS()) {
                    address = 0x087CE828 + difference;
                }
                else {
                    address = 0x0C3CE828 + difference;
                }
                Process::Write32(address, value);
            }
		}
    }

    void YWB_NoAttack(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0062D8FC, 0xE1A00001);
        }
        else {
            Process::Write32(0x0062D8FC, 0xE1A00000);
        }
    }

    void YWB_TechniqueRange(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x003D32EC, 0x50000000);
            Process::Write32(0x004038CC, 0x50000000);
        }
        else {
            Process::Write32(0x003D32EC, 0x3F800000);
            Process::Write32(0x004038CC, 0x3F800000);
        }
    }

    void YWB_MissionTimeStop(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x003DB954, 0xE1A00000);
        }
        else {
            Process::Write32(0x003DB954, 0xEDC40A0A);
        }
    }

    void YWB_ChangeFPS(MenuEntry *entry)
    {
        Keyboard keyboard("FPS変更");
        std::vector < std::string > option =
        {
            "60FPS", "30FPS", "20FPS", "15FPS", "10FPS"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
			Process::Write8(0x006B8965, 0x01);
		}
        if (userchoice == 1) {
			Process::Write8(0x006B8965, 0x02);
		}
        if (userchoice == 2) {
			Process::Write8(0x006B8965, 0x03);
		}
        if (userchoice == 3) {
			Process::Write8(0x006B8965, 0x04);
		}
        if (userchoice == 4) {
			Process::Write8(0x006B8965, 0x05);
		}
    }

    void YWB_EnterRoomErrorAvoidance(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0023DB2C, 0xE1A00000);
            Process::Write32(0x0023DB3C, 0xE1A00000);
            Process::Write32(0x0023DB4C, 0xE1A00000);
        }
        else {
            Process::Write32(0x0023DB2C, 0xE2888001);
            Process::Write32(0x0023DB3C, 0xE5912000);
            Process::Write32(0x0023DB4C, 0xE5810000);
        }
    }

    void YWB_WaitError(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0023D510, 0xE1A00000);
        }
        else {
            Process::Write32(0x0023D510, 0xE3500000);
        }
    }

    void YWB_NGWord(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write16(0x002DBF2C, 0x9999);
        }
        else {
            Process::Write16(0x002DBF2C, 0x0077);
        }
    }

    void YWB_BossYokaiSave(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x004134E8, 0xE3A00001);
            Process::Write32(0x0048C3F8, 0xE3A00001);
            Process::Write32(0x005A1FC0, 0xE3A02E19);
        }
        else {
            Process::Write32(0x004134E8, 0x3AE4B300);
            Process::Write32(0x0048C3F8, 0xEB03B5A0);
            Process::Write32(0x005A1FC0, 0xE1620281);
        }
    }

    void YWB_InfinityHP(MenuEntry *entry) //オフの解析お願いします。
    {
        if (entry->IsActivated()) {
            Process::Write32(0x003F9C0C, 0xEB08E3BB);
            Process::Write32(0x00632B00, 0xE59016FC);
            Process::Write32(0x00632B04, 0xE3510000);
            Process::Write32(0x00632B0C, 0xE58016FC);
            Process::Write32(0x00632B10, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x003F9C0C, 0xEB08E3BB);
            Process::Write32(0x00632B00, 0xE59016FC);
            Process::Write32(0x00632B04, 0xE3510000);
            Process::Write32(0x00632B0C, 0xE58016FC);
            Process::Write32(0x00632B10, 0xE12FFF1E);
        }
    }

    void YWB_DokodemoError(MenuEntry *entry)
    {
	    Process::Write32(0x0023D7B8, 0xE1D103B0);
	    if (Controller::IsKeyDown(R))
	    {
	    	Process::Write32(0x0023D7B8, 0xE1C103B0);
        }
    }

    void YWB_InfinityRoom(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::Write8(0x0886FE34, 0x01);
        }
        else {
            Process::Write8(0x0C46FE34, 0x01);
        }
    }

    float modelcolor_red = 1, modelcolor_green = 1, modelcolor_blue = 1;

    void YWB_ModelColorSettings(MenuEntry *entry)
    {
        Keyboard keyboard("モデル着色\n赤の値を入力してください\nデフォルト:1");
        if (keyboard.Open(modelcolor_red) != -1) {
            Keyboard keyboard("モデル着色\n緑の値を入力してください\nデフォルト:1");
            if (keyboard.Open(modelcolor_green) != -1) {
                Keyboard keyboard("モデル着色\n青の値を入力してください\nデフォルト:1");
                if (keyboard.Open(modelcolor_blue) != -1) {
                    MessageBox(Utils::Format("赤:%f\n緑:%f\n青:%f", modelcolor_red, modelcolor_green, modelcolor_blue))();
                }
            }
        }
    }

    void YWB_ModelColor(MenuEntry *entry)
    {
        Process::WriteFloat(0x305DA988, modelcolor_red);
        Process::WriteFloat(0x305DA98C, modelcolor_green);
        Process::WriteFloat(0x305DA990, modelcolor_blue);
    }

    void YWB_DrawPlayerIP(MenuEntry *entry)
    {
        u8 player1_1, player1_2, player1_3, player1_4;
        u8 player2_1, player2_2, player2_3, player2_4;
        u8 player3_1, player3_2, player3_3, player3_4;
        u8 player4_1, player4_2, player4_3, player4_4;
        if (!IsNew3DS()) {
            Process::Read8(0x081BAE50, player1_1);
            Process::Read8(0x081BAE51, player1_2);
            Process::Read8(0x081BAE52, player1_3);
            Process::Read8(0x081BAE53, player1_4);
            Process::Read8(0x081BAE88, player2_1);
            Process::Read8(0x081BAE89, player2_2);
            Process::Read8(0x081BAE8A, player2_3);
            Process::Read8(0x081BAE8B, player2_4);
            Process::Read8(0x081BAEC0, player3_1);
            Process::Read8(0x081BAEC1, player3_2);
            Process::Read8(0x081BAEC2, player3_3);
            Process::Read8(0x081BAEC3, player3_4);
            Process::Read8(0x081BAEF8, player4_1);
            Process::Read8(0x081BAEF9, player4_2);
            Process::Read8(0x081BAEFA, player4_3);
            Process::Read8(0x081BAEFB, player4_4);
        }
        else {
            Process::Read8(0x0BDBAE50, player1_1);
            Process::Read8(0x0BDBAE51, player1_2);
            Process::Read8(0x0BDBAE52, player1_3);
            Process::Read8(0x0BDBAE53, player1_4);
            Process::Read8(0x0BDBAE88, player2_1);
            Process::Read8(0x0BDBAE89, player2_2);
            Process::Read8(0x0BDBAE8A, player2_3);
            Process::Read8(0x0BDBAE8B, player2_4);
            Process::Read8(0x0BDBAEC0, player3_1);
            Process::Read8(0x0BDBAEC1, player3_2);
            Process::Read8(0x0BDBAEC2, player3_3);
            Process::Read8(0x0BDBAEC3, player3_4);
            Process::Read8(0x0BDBAEF8, player4_1);
            Process::Read8(0x0BDBAEF9, player4_2);
            Process::Read8(0x0BDBAEFA, player4_3);
            Process::Read8(0x0BDBAEFB, player4_4);
        }

        OSDManager.Lock();
        const Screen &scr = OSD::GetTopScreen();
        scr.Draw(Utils::Format("Player1 IP: %d.%d.%d.%d", player1_1, player1_2, player1_3, player1_4), 10, 50);
        scr.Draw(Utils::Format("Player2 IP: %d.%d.%d.%d", player2_1, player2_2, player2_3, player2_4), 10, 60);
        scr.Draw(Utils::Format("Player3 IP: %d.%d.%d.%d", player3_1, player3_2, player3_3, player3_4), 10, 70);
        scr.Draw(Utils::Format("Player4 IP: %d.%d.%d.%d", player4_1, player4_2, player4_3, player4_4), 10, 80);
        OSDManager.Unlock();
    }

    void YWB_DrawMugenheyaIP(MenuEntry *entry)
    {
        u8 ip_1, ip_2, ip_3, ip_4;
        if (!IsNew3DS()) {
            Process::Read8(0x081BB227, ip_1);
            Process::Read8(0x081BB226, ip_2);
            Process::Read8(0x081BB225, ip_3);
            Process::Read8(0x081BB224, ip_4);
        }
        else {
            Process::Read8(0x0BDBB227, ip_1);
            Process::Read8(0x0BDBB226, ip_2);
            Process::Read8(0x0BDBB225, ip_3);
            Process::Read8(0x0BDBB224, ip_4);
        }

        OSDManager.Lock();
        const Screen &scr = OSD::GetTopScreen();
        scr.Draw(Utils::Format("InfRoom IP: %d.%d.%d.%d", ip_1, ip_2, ip_3, ip_4), 10, 100);
        OSDManager.Unlock();
    }

    void YWB_RapidChat(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::Write32(0x001DD2A8, 0xEA000005);
        }
        else {
            Process::Write32(0x001DD2A8, 0x0A000005);
        }
    }

    static const std::vector<U8_VALUE_TEXT> version_list =
	{
		{0x00,"赤猫団"},
		{0x01,"白犬隊"},
		{0x02,"赤猫団(月兎組)"},
		{0x03,"白犬隊(月兎組)"},
        {0x04,"なし"},
	};

    static std::string dummy_name_1, dummy_name_2, dummy_name_3, dummy_name_4;
    static u32 dummy_yokai_1, dummy_yokai_2, dummy_yokai_3, dummy_yokai_4;
    static u8 dummy_version_1, dummy_rank_1, dummy_version_2, dummy_rank_2, dummy_version_3, dummy_rank_3, dummy_version_4, dummy_rank_4;

    void YWB_DummyPlayer1_Settings(MenuEntry *entry)
    {
        Keyboard keyboard1("名前を入力してください");
        keyboard1.SetMaxLength(16);
        if (keyboard1.Open(dummy_name_1) != -1) {
            Keyboard keyboard2("メダル/モデルIDを入力してください");
            if (keyboard2.Open(dummy_yokai_1) != -1) {
                items_ywb.clear();
                if (items_ywb.empty())
                    for(const U8_VALUE_TEXT &i: version_list)
                    items_ywb.push_back(i.name);
                Keyboard keyboard3("バージョンを選択してください", items_ywb);
                int choice = keyboard3.Open();
                if (choice >= 0)
                {
                    dummy_version_1 = version_list[choice].id;
                    Keyboard keyboard4("ランクを入力してください(16進数)");
                    keyboard4.Open(dummy_rank_1);
                }
            }
        }
    }

    void YWB_DummyPlayer1(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::WriteString(0x0886FB24, dummy_name_1);
            Process::Write32(0x0886FB3C, dummy_yokai_1);
            Process::Write8(0x0886FB45, dummy_version_1);
            Process::Write8(0x0886FB46, dummy_rank_1);
            Process::Write32(0x0886FBCC, 0x00070001);
        }
        else {
            Process::WriteString(0x0C46FB24, dummy_name_1);
            Process::Write32(0x0C46FB3C, dummy_yokai_1);
            Process::Write8(0x0C46FB45, dummy_version_1);
            Process::Write8(0x0C46FB46, dummy_rank_1);
            Process::Write32(0x0C46FBCC, 0x00070001);
        }
    }

    void YWB_DummyPlayer2_Settings(MenuEntry *entry)
    {
        Keyboard keyboard1("名前を入力してください");
        keyboard1.SetMaxLength(16);
        if (keyboard1.Open(dummy_name_2) != -1) {
            Keyboard keyboard2("メダル/モデルIDを入力してください");
            if (keyboard2.Open(dummy_yokai_2) != -1) {
                items_ywb.clear();
                if (items_ywb.empty())
                    for(const U8_VALUE_TEXT &i: version_list)
                    items_ywb.push_back(i.name);
                Keyboard keyboard3("バージョンを選択してください", items_ywb);
                int choice = keyboard3.Open();
                if (choice >= 0)
                {
                    dummy_version_2 = version_list[choice].id;
                    Keyboard keyboard4("ランクを入力してください(16進数)");
                    keyboard4.Open(dummy_rank_2);
                }
            }
        }
    }

    void YWB_DummyPlayer2(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::WriteString(0x0886FBD4, dummy_name_2);
            Process::Write32(0x0886FBEC, dummy_yokai_2);
            Process::Write8(0x0886FBF5, dummy_version_2);
            Process::Write8(0x0886FBF6, dummy_rank_2);
            Process::Write32(0x0886FC7C, 0x00070002);
        }
        else {
            Process::WriteString(0x0C46FBD4, dummy_name_2);
            Process::Write32(0x0C46FBEC, dummy_yokai_2);
            Process::Write8(0x0C46FBF5, dummy_version_2);
            Process::Write8(0x0C46FBF6, dummy_rank_2);
            Process::Write32(0x0C46FC7C, 0x00070002);
        }
    }
    
    void YWB_DummyPlayer3_Settings(MenuEntry *entry)
    {
        Keyboard keyboard1("名前を入力してください");
        keyboard1.SetMaxLength(16);
        if (keyboard1.Open(dummy_name_3) != -1) {
            Keyboard keyboard2("メダル/モデルIDを入力してください");
            if (keyboard2.Open(dummy_yokai_3) != -1) {
                items_ywb.clear();
                if (items_ywb.empty())
                    for(const U8_VALUE_TEXT &i: version_list)
                    items_ywb.push_back(i.name);
                Keyboard keyboard3("バージョンを選択してください", items_ywb);
                int choice = keyboard3.Open();
                if (choice >= 0)
                {
                    dummy_version_3 = version_list[choice].id;
                    Keyboard keyboard4("ランクを入力してください(16進数)");
                    keyboard4.Open(dummy_rank_3);
                }
            }
        }
    }

    void YWB_DummyPlayer3(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::WriteString(0x0886FC84, dummy_name_3);
            Process::Write32(0x0886FC9C, dummy_yokai_3);
            Process::Write8(0x0886FCA5, dummy_version_3);
            Process::Write8(0x0886FCA6, dummy_rank_3);
            Process::Write32(0x0886FD2C, 0x00070003);
        }
        else {
            Process::WriteString(0x0C46FC84, dummy_name_3);
            Process::Write32(0x0C46FC9C, dummy_yokai_3);
            Process::Write8(0x0C46FCA5, dummy_version_3);
            Process::Write8(0x0C46FCA6, dummy_rank_3);
            Process::Write32(0x0C46FD2C, 0x00070003);
        }
    }

    void YWB_DummyPlayer4_Settings(MenuEntry *entry)
    {
        Keyboard keyboard1("名前を入力してください");
        keyboard1.SetMaxLength(16);
        if (keyboard1.Open(dummy_name_4) != -1) {
            Keyboard keyboard2("メダル/モデルIDを入力してください");
            if (keyboard2.Open(dummy_yokai_4) != -1) {
                items_ywb.clear();
                if (items_ywb.empty())
                    for(const U8_VALUE_TEXT &i: version_list)
                    items_ywb.push_back(i.name);
                Keyboard keyboard3("バージョンを選択してください", items_ywb);
                int choice = keyboard3.Open();
                if (choice >= 0)
                {
                    dummy_version_4 = version_list[choice].id;
                    Keyboard keyboard4("ランクを入力してください(16進数)");
                    keyboard4.Open(dummy_rank_4);
                }
            }
        }
    }

    void YWB_DummyPlayer4(MenuEntry *entry)
    {
        if (!IsNew3DS()) {
            Process::WriteString(0x0C46FD34, dummy_name_4);
            Process::Write32(0x0C46FD4C, dummy_yokai_4);
            Process::Write8(0x0C46FD55, dummy_version_4);
            Process::Write8(0x0C46FD56, dummy_rank_4);
            Process::Write32(0x0C46FDDC, 0x00070004);
        }
        else {
            Process::WriteString(0x0886FD34, dummy_name_4);
            Process::Write32(0x0886FD4C, dummy_yokai_4);
            Process::Write8(0x0886FD55, dummy_version_4);
            Process::Write8(0x0886FD56, dummy_rank_4);
            Process::Write32(0x0886FDDC, 0x00070004);
        }
    }

    void YWB_LRCameraSeigen(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            if (IsNew3DS()) {
                PointerWrite32(0x0CB3847C, 0x698, 0xCFC90FDB);
                PointerWrite32(0x0CB3847C, 0x69C, 0x4FC90FDB);
            }
            else {
                PointerWrite32(0x08E3847C, 0x698, 0xCFC90FDB);
                PointerWrite32(0x08E3847C, 0x69C, 0x4FC90FDB);
            }
        }
        else {
            if (IsNew3DS()) {
                PointerWrite32(0x0CB3847C, 0x698, 0xBFC90FDB);
                PointerWrite32(0x0CB3847C, 0x69C, 0x3FC90FDB);
            }
            else {
                PointerWrite32(0x08E3847C, 0x698, 0xBFC90FDB);
                PointerWrite32(0x08E3847C, 0x69C, 0x3FC90FDB);
            }
        }
    }

    void YWB_Profile_FaceIcon(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("顔アイコン変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C3D5B5C, value);
            }
            else {
                Process::Write32(0x087D5B5C, value);
            }
        }
    }

    void YWB_Profile_Version(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("バージョン変更\n1 = 赤猫団, 2 = 白犬隊");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C3D5BB0, value);
            }
            else {
                Process::Write8(0x087D5BB0, value);
            }
        }
    }

    void YWB_Profile_PlayTime(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("プレイ時間変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C3D5BA4, value);
            }
            else {
                Process::Write32(0x087D5BA4, value);
            }
        }
    }

    void YWB_Profile_Daijiten(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("大辞典開放率変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C3D5BA3, value);
            }
            else {
                Process::Write8(0x087D5BA3, value);
            }
        }
    }

    void YWB_Profile_BronzeTrophy(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("銅トロフィー取得数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C3D5BA0, value);
            }
            else {
                Process::Write8(0x087D5BA0, value);
            }
        }
    }

    void YWB_Profile_SilverTrophy(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("銀トロフィー取得数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C3D5BA1, value);
            }
            else {
                Process::Write8(0x087D5BA1, value);
            }
        }
    }

    void YWB_Profile_GoldTrophy(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("金トロフィー取得数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C3D5BA2, value);
            }
            else {
                Process::Write8(0x087D5BA2, value);
            }
        }
    }

    void YWB_Profile_Attacker(MenuEntry *entry)
    {
        u16 value;
        Keyboard keyboard("アタッカー出動数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write16(0x0C3D5BA8, value);
            }
            else {
                Process::Write16(0x087D5BA8, value);
            }
        }
    }

    void YWB_Profile_Tank(MenuEntry *entry)
    {
        u16 value;
        Keyboard keyboard("タンク出動数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write16(0x0C3D5BAA, value);
            }
            else {
                Process::Write16(0x087D5BAA, value);
            }
        }
    }

    void YWB_Profile_Heeler(MenuEntry *entry)
    {
        u16 value;
        Keyboard keyboard("ヒーラー変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write16(0x0C3D5BAC, value);
            }
            else {
                Process::Write16(0x087D5BAC, value);
            }
        }
    }

    void YWB_Profile_Ranger(MenuEntry *entry)
    {
        u16 value;
        Keyboard keyboard("レンジャー出動数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write16(0x0C3D5BAE, value);
            }
            else {
                Process::Write16(0x087D5BAE, value);
            }
        }
    }

    void YWB_Profile_ClearMission(MenuEntry *entry)
    {
        u16 value;
        Keyboard keyboard("クリアミッション数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write16(0x0C3D5BB6, value);
            }
            else {
                Process::Write16(0x087D5BB6, value);
            }
        }
    }

    void YWB_Profile_AkanekoKyouryoku(MenuEntry *entry)
    {
        u16 value;
        Keyboard keyboard("赤猫団と協力した数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write16(0x0C3D5BB8, value);
            }
            else {
                Process::Write16(0x087D5BB8, value);
            }
        }
    }

    void YWB_Profile_ShiroinuKyouryoku(MenuEntry *entry)
    {
        u16 value;
        Keyboard keyboard("白犬隊と協力した数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write16(0x0C3D5BBA, value);
            }
            else {
                Process::Write16(0x087D5BBA, value);
            }
        }
    }

    void YWB_Profile_AkanekoSuretigai(MenuEntry *entry)
    {
        u16 value;
        Keyboard keyboard("赤猫団とすれちがった数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write16(0x0C3D5BBC, value);
            }
            else {
                Process::Write16(0x087D5BBC, value);
            }
        }
    }

    void YWB_Profile_ShiroinuSuretigai(MenuEntry *entry)
    {
        u16 value;
        Keyboard keyboard("白犬隊とすれちがった数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write16(0x0C3D5BBE, value);
            }
            else {
                Process::Write16(0x087D5BBE, value);
            }
        }
    }

    void YWB_Profile_YokainoWa(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("繋げた妖怪の輪の数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C3D5BB7, value);
            }
            else {
                Process::Write8(0x087D5BB7, value);
            }
        }
    }

    void YWB_Profile_CollectSoubi(MenuEntry *entry)
    {
        u16 value;
        Keyboard keyboard("集めた装備の数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write16(0x0C3D5BC0, value);
            }
            else {
                Process::Write16(0x087D5BC0, value);
            }
        }
    }

    void YWB_Profile_Dondoro(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("どんどろ最高記録変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C3D5BDF, value);
            }
            else {
                Process::Write8(0x087D5BDF, value);
            }
        }
    }

    void YWB_Profile_RedJ(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("レッドJ最高記録変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C3D5BDE, value);
            }
            else {
                Process::Write8(0x087D5BDE, value);
            }
        }
    }

    void YWB_Profile_MityDog(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("マイティドッグ最高記録変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C3D5BDD, value);
            }
            else {
                Process::Write8(0x087D5BDD, value);
            }
        }
    }

    void YWB_Profile_Kurooni(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("黒鬼最高記録変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C3D5BDC, value);
            }
            else {
                Process::Write8(0x087D5BDC, value);
            }
        }
    }

    void YWB_Profile_PrisonBreaker(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("プリズンブレイカー最高記録変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C3D5BE0, value);
            }
            else {
                Process::Write8(0x087D5BE0, value);
            }
        }
    }

    void YWB_Profile_GBabaan(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("Gババーン最高記録変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C3D5BE1, value);
            }
            else {
                Process::Write8(0x087D5BE1, value);
            }
        }
    }

    void YWB_Profile_Hinoshin(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("日ノ神最高記録変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C3D5BE3, value);
            }
            else {
                Process::Write8(0x087D5BE3, value);
            }
        }
    }

    void YWB_Profile_Ayatori(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("あやとリ様最高記録変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write8(0x0C3D5BE2, value);
            }
            else {
                Process::Write8(0x087D5BE2, value);
            }
        }
    }

    void YWB_Profile_FavoriteYokai1(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("お気に入りの妖怪1位変更\nメダル/モデルIDを入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C3D5BC4, value);
            }
            else {
                Process::Write32(0x087D5BC4, value);
            }
        }
    }

    void YWB_Profile_FavoriteYokai2(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("お気に入りの妖怪2位変更\nメダル/モデルIDを入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C3D5BC8, value);
            }
            else {
                Process::Write32(0x087D5BC8, value);
            }
        }
    }

    void YWB_Profile_FavoriteYokai3(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("お気に入りの妖怪3位変更\nメダル/モデルIDを入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C3D5BCC, value);
            }
            else {
                Process::Write32(0x087D5BCC, value);
            }
        }
    }

    void YWB_Profile_FavoriteYokai4(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("お気に入りの妖怪4位変更\nメダル/モデルIDを入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C3D5BD0, value);
            }
            else {
                Process::Write32(0x087D5BD0, value);
            }
        }
    }

    void YWB_Profile_FavoriteYokai5(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("お気に入りの妖怪5位変更\nメダル/モデルIDを入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C3D5BD4, value);
            }
            else {
                Process::Write32(0x087D5BD4, value);
            }
        }
    }

    void YWB_Profile_FavoriteYokai6(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("お気に入りの妖怪6位変更\nメダル/モデルIDを入力してください。");
		if (keyboard.Open(value) != -1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C3D5BD8, value);
            }
            else {
                Process::Write32(0x087D5BD8, value);
            }
        }
    }

    void YWB_SaveCoordinate(MenuEntry *entry)
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
            if (IsNew3DS()) {
                Process::Read32(0x0C4B08E0, coord_x);
                Process::Read32(0x0C4B08E8, coord_y);
                Process::Read32(0x0C4B08E4, coord_z);
            }
            else {
                Process::Read32(0x088B08E0, coord_x);
                Process::Read32(0x088B08E8, coord_y);
                Process::Read32(0x088B08E4, coord_z);
            }
		}
		if (userchoice == 1) {
            if (IsNew3DS()) {
                Process::Write32(0x0C4B08E0, coord_x);
                Process::Write32(0x0C4B08E8, coord_y);
                Process::Write32(0x0C4B08E4, coord_z);
            }
            else {
                Process::Write32(0x088B08E0, coord_x);
                Process::Write32(0x088B08E8, coord_y);
                Process::Write32(0x088B08E4, coord_z);
            }
		}
	}
}