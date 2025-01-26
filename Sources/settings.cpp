#include <cheats.hpp>

namespace	CTRPluginFramework
{
    FwkSettings &settings = FwkSettings::Get();
    u8 a = 0xFF;

	void Setting_MainTextColor(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.MainTextColor = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_WindowTitleColor(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.MainTextColor = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_MenuSelectedItemColor(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.MenuSelectedItemColor = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_MenuUnselectedItemColor(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.MenuUnselectedItemColor = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_BackgroundMainColor(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.BackgroundMainColor = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_BackgroundSecondaryColor(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.BackgroundSecondaryColor = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_BackgroundBorderColor(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.BackgroundBorderColor = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_Keyboard_Background(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.Keyboard.Background = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_Keyboard_KeyBackground(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.Keyboard.KeyBackground = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_Keyboard_KeyBackgroundPressed(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.Keyboard.KeyBackgroundPressed = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_Keyboard_KeyText(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.Keyboard.KeyText = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_Keyboard_KeyTextPressed(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.Keyboard.KeyTextPressed = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_Keyboard_Cursor(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.Keyboard.Cursor = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_Keyboard_Input(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.Keyboard.Input = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_CustomKeyboard_BackgroundMain(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.CustomKeyboard.BackgroundMain = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_CustomKeyboard_BackgroundSecondary(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.CustomKeyboard.BackgroundSecondary = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_CustomKeyboard_BackgroundBorder(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.CustomKeyboard.BackgroundBorder = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_CustomKeyboard_KeyBackground(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.CustomKeyboard.KeyBackground = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_CustomKeyboard_KeyBackgroundPressed(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.CustomKeyboard.KeyBackgroundPressed = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_CustomKeyboard_KeyText(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.CustomKeyboard.KeyText = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_CustomKeyboard_KeyTextPressed(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.CustomKeyboard.KeyTextPressed = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_CustomKeyboard_ScrollBarBackground(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.CustomKeyboard.ScrollBarBackground = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_CustomKeyboard_ScrollBarThumb(MenuEntry *entry)
    {
        u8 r, g, b;
        Keyboard keyboard("赤を入力してください。");
		if (keyboard.Open(r) != -1) {
            Keyboard keyboard("緑を入力してください。");
		    if (keyboard.Open(g) != -1) {
                Keyboard keyboard("青を入力してください。");
		        if (keyboard.Open(b) != -1) {
                    settings.CustomKeyboard.ScrollBarThumb = Color(r, g, b, a);
		        }
		    }
		}
    }

    void Setting_Reset(MenuEntry *entry)
    {
        if ((MessageBox("設定を初期化してよろしいですか?", DialogType::DialogOkCancel))() == true)
		{
			settings.SetThemeDefault();
		}
    }
}