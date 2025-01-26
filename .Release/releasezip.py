import zipfile
from pathlib import Path

path = Path(__file__).parent
path /= '../'
version = input("バージョンを入力してください。\n")
filename = '.Release/ReleaseFiles/Asahi-Cheats_' + version + '.zip'
with zipfile.ZipFile(filename, "w", zipfile.ZIP_DEFLATED) as zf:
    zf.write("Asahi-Cheats_0.5.1.3gx", "luma/plugins/Asahi-Cheats_0.5.1.3gx")
    zf.write("Asahi-Cheats_0.7.0.3gx", "luma/plugins/Asahi-Cheats_0.7.0.3gx")
    zf.write(".Release/sound_accept.bcwav", "luma/plugins/snd/sound_accept.bcwav")
    zf.write(".Release/sound_cancel.bcwav", "luma/plugins/snd/sound_cancel.bcwav")
    zf.write(".Release/sound_cursor.bcwav", "luma/plugins/snd/sound_cursor.bcwav")
    zf.write(".Release/sound_deselect.bcwav", "luma/plugins/snd/sound_deselect.bcwav")
    zf.write(".Release/sound_select.bcwav", "luma/plugins/snd/sound_select.bcwav")
    zf.write(".Release/.README.txt", "マニュアル/説明書.txt")
    zf.write(".Release/.VERSION.txt", "マニュアル/更新履歴.txt")

print(filename + "に保存しました。")