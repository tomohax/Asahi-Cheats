//TITLE: 妖怪ウォッチ2 真打
//TITLEID: 0004000000155100
//PROCESSNAME: YW2

#include <cheats.hpp>

namespace	CTRPluginFramework
{	
	static StringVector items(200);

	static const std::vector<U32_VALUE_TEXT> motion_list =
	{
		{0x60284354, "走る"},
		{0xFFF727B4, "歩く"},
		{0x0C9C1D8C, "全力疾走"},
		{0x05C2218D, "ふらふら"},
		{0x0CBAE99D, "着地"},
		{0x01F546AE, "落ちる"},
		{0x62786A44, "見渡す"},
		{0x1306EDE6, "周りを警戒する"},
		{0x44E24DCB, "転ぶ"},
		{0x93E4B56D, "ドアを開ける"},
		{0xF16AA0E5, "下を見渡す"},
		{0x7603014A, "蹴る"},
		{0x2C837095, "自転車"},
		{0x4D5E8E1B, "ブロック塀"},
		{0x0CBAE99D, "拾う"},
		{0xFFA7DD46, "スタミナ切れ"},
		{0xA23137F8, "ポール登る"},
		{0x0BF96E0B, "滑り台"},
		{0x2C837095, "座る"},
		{0xA30F8579, "うんがい鏡に吸い込まれる"},
		{0x38F24E98, "うんがい鏡に吐き出される"},
	};
	
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
		{0x629D8D39, "さびしげな水路"},
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
		{0x056FE40E, "ひがん山トンネル"},
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
		{0xEDFF1A6E, "商店の細道"},
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
	};
	
	static const std::vector<U32_VALUE_TEXT> map_oomori_list =
	{
		{0x0569AC18, "おおもり山"},
		{0x702822D7, "おおもり山 登山道"},
		{0xE921736D, "おおもり山 山頂"},
		{0x78F0B184, "廃屋"},
		{0x4AC6D306, "滝の裏の祠"},
		{0xC20C20AE, "廃トンネル 東"},
		{0x5B057114, "廃トンネル 西"},
	};
	
	static const std::vector<U32_VALUE_TEXT> map_extree_list =
	{
		{0x32B75C2A, "さくらEXツリー"},
		{0x4F2E41B6, "さくらEXツリー エントランス"},
		{0xA120209A, "さくらEXツリー 展望台"},
		{0xD627100C, "エレベーター"},
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
		{0x253DF7E9, "棚田の跡地"},
	};
	
	static const std::vector<U32_VALUE_TEXT> map_nagisaki_list =
	{
		{0x6D1C5096, "ナギサキ"},
		{0xFE8B2C26, "こじま商店"},
		{0x10854D0A, "さざなみ集会所"},
		{0x185DDE59, "潮騒の岩屋"},
		{0xF653BF75, "裏の作業場"},
		{0x0146EF18, "海辺の洞穴"},
		{0x55B41F1E, "海上, "},
		{0x7E994CDD, "廃屋"},
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
		{0x0C9F49E1, "60年前のひょうたん池"},
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
		{0xA4C4415E, "キウチ山 山頂"},
	};
	
	static const std::vector<U32_VALUE_TEXT> map_geragera_list =
	{
		{0x30C80F26, "ゲラゲランド入場口"},
		{0xA9C15E9C, "ごくらく温泉入場口"},
		{0x47CF3FB0, "きもだ飯入場口"},
		{0x37A5CB3F, "ゲラゲランド"},
		{0xAEAC9A85, "ごくらく温泉"},
		{0x40A2FBA9, "きもだ飯"},
		{0xD01DE638, "歌舞伎座 スーパーステージ"},
		{0xA71AD6AE, "歌舞伎座 奈落"},
		{0x29A1BAD3, "ゲラゲランド駅"},
		{0xB0A8EB69, "ごくらく温泉駅"},
		{0x5EA68A45, "きもだ飯駅"},
		{0xA21D4487, "満腹おたふく"},
	};
	
	static const std::vector<U32_VALUE_TEXT> map_sawayama_list =
	{
		{0x5A14A2FD, "佐和山城 城下町"},
		{0x48A10D13, "佐和山城 城内"},
		{0x3538108F, "大広間"},
		{0xF01D6A76, "関ヶ原 石田軍本陣"},
	};
	
	static const std::vector<U32_VALUE_TEXT> map_station_list =
	{
		{0x3330CBDD, "さくらぎ駅"},
		{0xC3485FA9, "桜中央駅"},
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
		{0x4437FB4B, "ケマモト駅"},
		{0x29A1BAD3, "ゲラゲランド駅"},
		{0xB0A8EB69, "ごくらく温泉駅"},
		{0x5EA68A45, "きもだ飯駅"},
		{0xA21D4487, "満腹おたふく駅"},
	};
	
	static const std::vector<U32_VALUE_TEXT> map_train_list =
	{
		{0xB10079BA, "通常世界 列車"},
		{0x5BE99CC0, "妖魔特急 普通車"},
		{0xB5E7FDEC, "妖魔特急 機関室"},
		{0x495C332E, "ふくふく超特急"},
	};
	
	static const std::vector< U32_VALUE_TEXT > map_yokaiworld_list =
	{
		{0xCDAD9B98, "世界の狭間"},
		{0x54A4CA22, "えっけん回廊"},
		{0xCAC05F81, "はらぺこ峠"},
		{0x23A3FAB4, "うそつき山"},
		{0xBDC76F17, "あらくれ街道"},
	};
	
	static const std::vector<U32_VALUE_TEXT> map_jigoku_list =
	{
		{0xACF880B6, "無限地獄 第1階層"},
		{0x35F1D10C, "無限地獄 第2階層"},
		{0x42F6E19A, "無限地獄 第3階層"},
		{0xDC927439, "無限地獄 第4階層"},
		{0xAB9544AF, "無限地獄 第5階層"},
		{0x329C1515, "無限地獄 第6階層"},
		{0x459B2583, "無限地獄 第7階層"},
		{0xD5243812, "無限地獄 第8階層"},
		{0xC2E48161, "アミダ極楽 第1階層"},
		{0xB5E3B1F7, "アミダ極楽 第2階層"},
		{0x2CEAE04D, "アミダ極楽 第3階層"},
		{0x5BEDD0DB, "アミダ極楽 第4階層"},
		{0xC5894578, "アミダ極楽 第5階層"},
		{0xB28E75EE, "アミダ極楽 第6階層"},
	};
	
	static const std::vector<U32_VALUE_TEXT> map_ayakashi_list =
	{
		{0x2A6BBCDB, "あやかし通り 1号線"},
		{0x6BE8A868, "あやかし通り 2号線"},
		{0x98EAC294, "あやかし通り 3号線"},
		{0xC465DDF7, "あやかし通り 4号線"},
		{0xAC5E6C2A, "あやかし通り 5号線"},
		{0x22DCF3BD, "あやかし通り 6号線"},
		{0x26200963, "あやかし通り 本線"},
		{0xEA3C7CCD, "あやかし通り 側道"},
		{0x1128FB08, "あやかし通り 裏道"},
		{0x2D0678C2, "あやかし通り ランプウェイ"},
		{0xC30819EE, "ゴーゴー ジャンクション (側道)"},
		{0xAFC67925, "ゴーゴー ジャンクション (元祖)"},
		{0x36CF289F, "ゴーゴー ジャンクション (本家)"},
		{0x6836D077, "真の本家道 入口"},
		{0x2C48D2B8, "真の本家道 出口"},
		{0xED7CDAC6, "真の元祖道 入口"},
		{0x1E7EB03A, "真の元祖道 出口"},
		{0x33708D9A, "金ピカ都市高 入口"},
		{0xDF4AB844, "金ピカ都市高 内回り"},
		{0x72F39929, "金ピカ都市高 外回り"},
		{0xDD7EECB6, "金ピカ都市高 インターチェンジ"},
		{0xA3082718, "金ピカ都市高 西行き"},
		{0x3DB20FEE, "金ピカ都市高 東行き"},
		{0x341D4983, "金ピカ都市高 終点"},
		{0x24B034E9, "あやかし通り 終点"},
	};
	
	static const std::vector<U32_VALUE_TEXT> map_kimagure_list =
	{
		{0x9B267084, "ゲートの間"},
		{0x9C4BB49D, "缶けりの間 1階"},
		{0x0542E527, "缶けりの間 2階"},
		{0x7245D5B1, "缶けりの間 3階"},
		{0x95FDF8B6, "缶けりの間 出口"},
		{0x823D41C5, "信号の間 1階"},
		{0x1B34107F, "信号の間 2階"},
		{0x6C3320E9, "信号の間 3階"},
		{0xF257B54A, "信号の間 出口"},
		{0x1C59D466, "おすべりの間 1階"},
		{0x6B5EE4F0, "おすべりの間 2階"},
		{0xFBE1F961, "おすべりの間 3階"},
		{0x8CE6C9F7, "おすべりの間 出口"},
		{0xA9101206, "ナゾナゾの間 1階"},
		{0x301943BC, "ナゾナゾの間 2階"},
		{0x471E732A, "ナゾナゾの間 3階"},
		{0xD97AE689, "ナゾナゾの間 出口"},
		{0x752811A8, "創造主の間"},
	};
	
	//------------------------------
	//落下速度低下
	//------------------------------
	void YW2_DownSpeed(MenuEntry *entry)
	{
		if (entry->IsActivated()) {
            Process::Write32(0x003D477C, 0xE1A00000);
        }
        else {
            Process::Write32(0x003D477C, 0xE1D56BDC);
		}
	}
	
	//------------------------------
	//階段で自転車使用可能
	//------------------------------
	void YW2_BicycleStairs(MenuEntry *entry)
	{
		if (entry->IsActivated()) {
            Process::Write32(0x0039D928, 0xE3A00000);
			Process::Write32(0x0039D92C, 0xE58511A4);
        }
        else {
            Process::Write32(0x0039D928, 0xE3A00001);
			Process::Write32(0x0039D92C, 0xE59511A4);
        }
	}
	
	//------------------------------
	//走るスピード
	//------------------------------
	void YW2_RunSpeed(MenuEntry *entry)
	{
		if (entry->IsActivated()) {
            Process::Write32(0x003E7C28, 0x40400000);
        }
        else {
            Process::Write32(0x003E7C28, 0x3F800000);
        }
	}
	
	//------------------------------
	//座標移動
	//------------------------------
	void YW2_CoordinateMovement(MenuEntry *entry)
	{
		float coord_x, coord_y;
		if (Controller::IsKeysDown(entry->Hotkeys[0].GetKeys())) {
			Process::ReadFloat(0x08852E18, coord_x);
			coord_x = coord_x - 5;
			Process::WriteFloat(0x08852E18, coord_x);
		}
		if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys())) {
			Process::ReadFloat(0x08852E18, coord_x);
			coord_x = coord_x + 5;
			Process::WriteFloat(0x08852E18, coord_x);
		}
		if (Controller::IsKeysDown(entry->Hotkeys[2].GetKeys())) {
			Process::ReadFloat(0x08852E10, coord_y);
			coord_y = coord_y - 5;
			Process::WriteFloat(0x08852E10, coord_y);
		}
		if (Controller::IsKeysDown(entry->Hotkeys[3].GetKeys())) {
			Process::ReadFloat(0x08852E10, coord_y);
			coord_y = coord_y + 5;
			Process::WriteFloat(0x08852E10, coord_y);
		}
	}
	
	//------------------------------
	//ムーンジャンプ
	//------------------------------
	void YW2_MoonJump(MenuEntry *entry)
	{
		float coord_z;
		if (Controller::IsKeysDown(entry->Hotkeys[0].GetKeys())) {
			Process::ReadFloat(0x08852E14, coord_z);
			coord_z = coord_z + 5;
			Process::WriteFloat(0x8852E14, coord_z);
		}
		if (Controller::IsKeysDown(entry->Hotkeys[1].GetKeys())) {
			Process::ReadFloat(0x08852E14, coord_z);
			coord_z = coord_z - 5;
			Process::WriteFloat(0x08852E14, coord_z);
		}
	}
	
	//------------------------------
	//壁貫通
	//------------------------------
	void YW2_WalkOver(MenuEntry *entry)
	{
		static bool mode;
		if (Controller::IsKeysPressed(entry->Hotkeys[0].GetKeys())) {
			if (mode) {
				mode = false;
				OSD::Notify("Wall Through: Disable");
				Process::Write32(0x00267F68, 0xE3A01000);
				Process::Write32(0x00267F6C, 0xE59D0170);
			}
			else {
				mode = true;
				OSD::Notify("Wall Through: Enabled");
				Process::Write32(0x00267F68, 0xE3A01001);
				Process::Write32(0x00267F6C, 0xE59D0174);
			}
		}
	}
	
	//------------------------------
	//空中歩行
	//------------------------------
	void YW2_SkyWalk(MenuEntry *entry)
	{
		if (entry->IsActivated()) {
            Process::Write32(0x00594798, 0xE3A01001);
			Process::Write32(0x0059479C, 0xE3A02001);
        }
        else {
            Process::Write32(0x00594798, 0xE5D0111C);
			Process::Write32(0x0059479C, 0xE5D02120);
        }
	}
	
	//------------------------------
	//必殺技無限
	//------------------------------
	void YW2_WazaInfinity(MenuEntry *entry)
	{
		if (entry->IsActivated()) {
            Process::Write32(0x00563110, 0xE3A050FF);
        }
        else {
            Process::Write32(0x00563110, 0xC1A0500);
        }
	}
	
	//------------------------------
	//時間変更
	//------------------------------
	void YW2_ChangeTime(MenuEntry *entry)
	{
        Keyboard keyboard("時間変更");
        std::vector < std::string > option =
        {
            "0時", "1時", "2時", "3時", "4時", "5時", "6時", "7時", "8時", "9時", "10時", "11時"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
            Process::Write32(0x08726A40, 0x00010000);
        }
		if (userchoice == 1) {
            Process::Write32(0x08726A40, 0x00015000);
        }
		if (userchoice == 2) {
            Process::Write32(0x08726A40, 0x0001A000);
        }
		if (userchoice == 3) {
            Process::Write32(0x08726A40, 0x00020000);
        }
		if (userchoice == 4) {
            Process::Write32(0x08726A40, 0x00025000);
        }
		if (userchoice == 5) {
            Process::Write32(0x08726A40, 0x0002A000);
        }
		if (userchoice == 6) {
            Process::Write32(0x08726A40, 0x00030000);
        }
		if (userchoice == 7) {
            Process::Write32(0x08726A40, 0x00035000);
        }
		if (userchoice == 8) {
            Process::Write32(0x08726A40, 0x0003A000);
        }
		if (userchoice == 9) {
            Process::Write32(0x08726A40, 0x00040000);
        }
		if (userchoice == 10) {
            Process::Write32(0x08726A40, 0x00045000);
        }
		if (userchoice == 11) {
            Process::Write32(0x08726A40, 0x0004A000);
        }
	}
	
	//------------------------------
	//ゲームスピード変更
	//------------------------------
	void YW2_GameSpeed(MenuEntry *entry)
	{
		if (entry->IsActivated()) {
            Process::Write32(0x00858798, 0x40000000);
        }
        else {
            Process::Write32(0x00858798, 0x3F800000);
        }
	}
	
	void YW2_Luminous(MenuEntry *entry)
	{
        Keyboard keyboard("プレイヤー状態変更");
        std::vector < std::string > option =
        {
            "発光", "透明", "OFF"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0)
        {
            Process::Write32(0x0016076C, 0x3FFFFFFF);
        }
		if (userchoice == 1)
        {
            Process::Write32(0x0016076C, 0xFFFFFFFF);
        }
        if (userchoice == 2)
		{
			Process::Write32(0x0016076C, 0x3F800000);
		}
	}
	
	void YW2_Motion(MenuEntry *entry)
	{
		Keyboard keyboard("モーション変更");
        std::vector < std::string > option =
        {
            "デフォルト", "変更"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
		if (userchoice == 0)
		{
			Process::Write32(0x08001E94, 0x43C3094A);
			return;
		}
        if (userchoice == 1)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: motion_list)
				items.push_back(i.name);
			Keyboard keyboard("モーション変更\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08001E94,motion_list[choice].id);
			}
		}
	}
	
	//------------------------------
	//エリアワープ
	//------------------------------
	void YW2_AreaWarp(MenuEntry *entry)
	{
		Keyboard keyboard("エリアワープ\n\nワープしたい場所を選んでください");
        std::vector < std::string > option =
        {
            "さくら住宅街", "そよ風ヒルズ", "団々坂", "おつかい横丁", "さくら中央シティ",
			"おおもり山", "さくらEXツリー", "ケマモト村", "ナギサキ", "60年前のさくらニュータウン",
			"60年前のケマモト村", "ゲラゲランド", "佐和山城", "駅", "電車内", "妖魔界",
			"ムゲン地獄", "連動ダンジョン", "きまぐれゲート"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_sakura_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\nさくら住宅街\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_sakura_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 1)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_soyokaze_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\nそよ風ヒルズ\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_soyokaze_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 2)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_dandan_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\n団々坂\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_dandan_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 3)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_otsukai_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\nおつかい横丁\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_otsukai_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 4)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_sakuracity_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\nさくら中央シティ\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_sakuracity_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 5)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_oomori_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\nおおもり山\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_oomori_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 6)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_extree_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\nさくらEXツリー\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_extree_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 7)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_kemamoto_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\nケマモト村\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_kemamoto_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 8)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_nagisaki_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\nナギサキ\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_nagisaki_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 9)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_sakura60_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\n60年前のさくらニュータウン\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_sakura60_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 10)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_kemamoto60_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\n60年前のケマモト村\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_kemamoto60_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 11)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_geragera_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\nゲラゲランド\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_geragera_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 12)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_sawayama_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\n佐和山城\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_sawayama_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 13)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_station_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\n駅\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_station_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 14)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_train_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\n駅\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_train_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 15)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_yokaiworld_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\n妖魔界\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_yokaiworld_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 16)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_jigoku_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\nムゲン地獄\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_jigoku_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 17)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_ayakashi_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\n連動ダンジョン\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_ayakashi_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
		if (userchoice == 18)
		{
			items.clear();
			if (items.empty())
				for(const U32_VALUE_TEXT &i: map_kimagure_list)
				items.push_back(i.name);
			Keyboard keyboard("エリアワープ\nきまぐれゲート\n\nワープしたい場所を選んでください\n", items);
			int choice = keyboard.Open();
			if (choice >= 0)
			{
				Process::Write32(0x08727284,map_kimagure_list[choice].id);
				Process::Write32(0x08852E14, 0xF0000000);
			}
		}
	}

	void YW2_WeatherChanger(MenuEntry *entry)
	{
		Keyboard keyboard("エリアワープ\n\nワープしたい場所を選んでください");
        std::vector < std::string > option =
        {
            "晴れ", "曇り", "天気雨", "子雨", "雨", "大雨", "台風"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0)
		{
			Process::Write32(0x0872DF48, 0x00000001);
		}
		if (userchoice == 1)
		{
			Process::Write32(0x0872DF48, 0x00000002);
		}
		if (userchoice == 2)
		{
			Process::Write32(0x0872DF48, 0x00000003);
		}
		if (userchoice == 3)
		{
			Process::Write32(0x0872DF48, 0x00000004);
		}
		if (userchoice == 4)
		{
			Process::Write32(0x0872DF48, 0x00000005);
		}
		if (userchoice == 5)
		{
			Process::Write32(0x0872DF48, 0x00000006);
		}
		if (userchoice == 6)
		{
			Process::Write32(0x0872DF48, 0x00000007);
		}
	}

	void YW2_Daijiten(MenuEntry *entry)
	{
		Keyboard keyboard("大辞典フラグ編集");
        std::vector < std::string > option =
        {
            "New", "コンプリート", "発見", "未発見"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0)
		{
			Process::Write32(0x08726F4C, 0xFFFFFFFF);
			Process::Write32(0x08726F50, 0xFFFFFFFF);
			Process::Write32(0x08726F54, 0xFFFFFFFF);
			Process::Write32(0x08726F58, 0xFFFFFFFF);
			Process::Write32(0x08726F5C, 0xFFFFFFFF);
			Process::Write32(0x08726F60, 0xFFFFFFFF);
			Process::Write32(0x08726F64, 0xFFFFFFFF);
			Process::Write32(0x08726F68, 0xFFFFFFFF);
			Process::Write32(0x08726F6C, 0xFFFFFFFF);
			Process::Write32(0x08726F70, 0xFFFFFFFF);
			Process::Write32(0x08726F74, 0xFFFFFFFF);
			Process::Write32(0x08726F78, 0xFFFFFFFF);
			Process::Write32(0x08726F7C, 0xFFFFFFFF);
			Process::Write32(0x08726F80, 0xFFFFFFFF);
			Process::Write32(0x08726F84, 0xFFFFFFFF);
		}
		if (userchoice == 1)
		{
			Process::Write32(0x08726ED0, 0xFFFFFFFF);
			Process::Write32(0x08726ED4, 0xFFFFFFFF);
			Process::Write32(0x08726ED8, 0xFFFFFFFF);
			Process::Write32(0x08726EDC, 0xFFFFFFFF);
			Process::Write32(0x08726EE0, 0xFFFFFFFF);
			Process::Write32(0x08726EE4, 0xFFFFFFFF);
			Process::Write32(0x08726EE8, 0xFFFFFFFF);
			Process::Write32(0x08726EEC, 0xFFFFFFFF);
			Process::Write32(0x08726EF0, 0xFFFFFFFF);
			Process::Write32(0x08726EF4, 0xFFFFFFFF);
			Process::Write32(0x08726EF8, 0xFFFFFFFF);
			Process::Write32(0x08726EFC, 0xFFFFFFFF);
			Process::Write32(0x08726F00, 0xFFFFFFFF);
			Process::Write32(0x08726F04, 0xFFFFFFFF);
			Process::Write32(0x08726F08, 0xFFFFFFFF);
			Process::Write32(0x08726F10, 0xFFFFFFFF);
			Process::Write32(0x08726F14, 0xFFFFFFFF);
			Process::Write32(0x08726F18, 0xFFFFFFFF);
			Process::Write32(0x08726F1C, 0xFFFFFFFF);
			Process::Write32(0x08726F20, 0xFFFFFFFF);
			Process::Write32(0x08726F24, 0xFFFFFFFF);
			Process::Write32(0x08726F28, 0xFFFFFFFF);
			Process::Write32(0x08726F2C, 0xFFFFFFFF);
			Process::Write32(0x08726F30, 0xFFFFFFFF);
			Process::Write32(0x08726F34, 0xFFFFFFFF);
			Process::Write32(0x08726F38, 0xFFFFFFFF);
			Process::Write32(0x08726F3C, 0xFFFFFFFF);
			Process::Write32(0x08726F40, 0xFFFFFFFF);
			Process::Write32(0x08726F44, 0xFFFFFFFF);
		}
		if (userchoice == 2)
		{
			Process::Write32(0x08726ED0, 0xFFFFFFFF);
			Process::Write32(0x08726ED4, 0xFFFFFFFF);
			Process::Write32(0x08726ED8, 0xFFFFFFFF);
			Process::Write32(0x08726EDC, 0xFFFFFFFF);
			Process::Write32(0x08726EE0, 0xFFFFFFFF);
			Process::Write32(0x08726EE4, 0xFFFFFFFF);
			Process::Write32(0x08726EE8, 0xFFFFFFFF);
			Process::Write32(0x08726EEC, 0xFFFFFFFF);
			Process::Write32(0x08726EF0, 0xFFFFFFFF);
			Process::Write32(0x08726EF4, 0xFFFFFFFF);
			Process::Write32(0x08726EF8, 0xFFFFFFFF);
			Process::Write32(0x08726EFC, 0xFFFFFFFF);
			Process::Write32(0x08726F00, 0xFFFFFFFF);
			Process::Write32(0x08726F04, 0xFFFFFFFF);
			Process::Write32(0x08726F08, 0xFFFFFFFF);
			Process::Write32(0x08726F10, 0x00000000);
			Process::Write32(0x08726F14, 0x00000000);
			Process::Write32(0x08726F18, 0x00000000);
			Process::Write32(0x08726F1C, 0x00000000);
			Process::Write32(0x08726F20, 0x00000000);
			Process::Write32(0x08726F24, 0x00000000);
			Process::Write32(0x08726F28, 0x00000000);
			Process::Write32(0x08726F2C, 0x00000000);
			Process::Write32(0x08726F30, 0x00000000);
			Process::Write32(0x08726F34, 0x00000000);
			Process::Write32(0x08726F38, 0x00000000);
			Process::Write32(0x08726F3C, 0x00000000);
			Process::Write32(0x08726F40, 0x00000000);
			Process::Write32(0x08726F44, 0x00000000);
		}
		if (userchoice == 3)
		{
			Process::Write32(0x08726ED0, 0x00000000);
			Process::Write32(0x08726ED4, 0x00000000);
			Process::Write32(0x08726ED8, 0x00000000);
			Process::Write32(0x08726EDC, 0x00000000);
			Process::Write32(0x08726EE0, 0x00000000);
			Process::Write32(0x08726EE4, 0x00000000);
			Process::Write32(0x08726EE8, 0x00000000);
			Process::Write32(0x08726EEC, 0x00000000);
			Process::Write32(0x08726EF0, 0x00000000);
			Process::Write32(0x08726EF4, 0x00000000);
			Process::Write32(0x08726EF8, 0x00000000);
			Process::Write32(0x08726EFC, 0x00000000);
			Process::Write32(0x08726F00, 0x00000000);
			Process::Write32(0x08726F04, 0x00000000);
			Process::Write32(0x08726F08, 0x00000000);
			Process::Write32(0x08726F10, 0x00000000);
			Process::Write32(0x08726F14, 0x00000000);
			Process::Write32(0x08726F18, 0x00000000);
			Process::Write32(0x08726F1C, 0x00000000);
			Process::Write32(0x08726F20, 0x00000000);
			Process::Write32(0x08726F24, 0x00000000);
			Process::Write32(0x08726F28, 0x00000000);
			Process::Write32(0x08726F2C, 0x00000000);
			Process::Write32(0x08726F30, 0x00000000);
			Process::Write32(0x08726F34, 0x00000000);
			Process::Write32(0x08726F38, 0x00000000);
			Process::Write32(0x08726F3C, 0x00000000);
			Process::Write32(0x08726F40, 0x00000000);
			Process::Write32(0x08726F44, 0x00000000);
		}
	}

	void YW2_Trophy(MenuEntry *entry)
	{
		Keyboard keyboard("トロフィーフラグ編集");
        std::vector < std::string > option =
        {
            "New", "コンプリート", "空"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0)
		{
			Process::Write32(0x087270A0, 0xFFFFFFFF);
			Process::Write32(0x087270A4, 0xFFFFFFFF);
			Process::Write32(0x087270A8, 0xFFFFFFFF);
		}
		if (userchoice == 1)
		{
			Process::Write32(0x08727090, 0xFFFFFFFF);
			Process::Write32(0x08727094, 0xFFFFFFFF);
			Process::Write32(0x08727098, 0xFFFFFFFF);
		}
		if (userchoice == 2)
		{
			Process::Write32(0x08727090, 0x00000000);
			Process::Write32(0x08727094, 0x00000000);
			Process::Write32(0x08727098, 0x00000000);
		}
	}

	void YW2_YokaiSpot(MenuEntry *entry)
	{
		Keyboard keyboard("妖怪スポットフラグ編集");
        std::vector < std::string > option =
        {
            "コンプリート", "空"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0)
		{
			Process::Write32(0x08726B20, 0xFFFFFFFF);
			Process::Write32(0x08726B24, 0xFFFFFFFF);
			Process::Write32(0x08726B28, 0xFFFFFFFF);
			Process::Write32(0x08726B2C, 0xFFFFFFFF);
		}
		if (userchoice == 1)
		{
			Process::Write32(0x08726B20, 0x00000000);
			Process::Write32(0x08726B24, 0x00000000);
			Process::Write32(0x08726B28, 0x00000000);
			Process::Write32(0x08726B2C, 0x00000000);
		}
	}

	void YW2_Quest(MenuEntry *entry)
	{
		Keyboard keyboard("クエストフラグ編集");
        std::vector < std::string > option =
        {
            "New", "解決", "未解決"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
		if (userchoice == 1)
		{
			Process::Write32(0x0872C998, 0xFFFFFFFF);
			Process::Write32(0x0872C99C, 0xFFFFFFFF);
			Process::Write32(0x0872C9A0, 0xFFFFFFFF);
			Process::Write32(0x0872C9A4, 0xFFFFFFFF);
		}
        if (userchoice == 1)
		{
			Process::Write32(0x0872C8D8, 0xFFFFFFFF);
			Process::Write32(0x0872C8DC, 0xFFFFFFFF);
			Process::Write32(0x0872C8E0, 0xFFFFFFFF);
			Process::Write32(0x0872C8E4, 0xFFFFFFFF);
			Process::Write32(0x0872C8E8, 0xFFFFFFFF);
			Process::Write32(0x0872C8EC, 0xFFFFFFFF);
			Process::Write32(0x0872C8F0, 0xFFFFFFFF);
			Process::Write32(0x0872C8F4, 0xFFFFFFFF);
			Process::Write32(0x0872C8F8, 0xFFFFFFFF);
			Process::Write32(0x0872C8FC, 0xFFFFFFFF);
			Process::Write32(0x0872C900, 0xFFFFFFFF);
			Process::Write32(0x0872C904, 0xFFFFFFFF);
			Process::Write32(0x0872C908, 0xFFFFFFFF);
			Process::Write32(0x0872C90C, 0xFFFFFFFF);
			Process::Write32(0x0872C910, 0xFFFFFFFF);
			Process::Write32(0x0872C914, 0xFFFFFFFF);
			Process::Write32(0x0872C918, 0xFFFFFFFF);
			Process::Write32(0x0872C91C, 0xFFFFFFFF);
			Process::Write32(0x0872C920, 0xFFFFFFFF);
			Process::Write32(0x0872C924, 0xFFFFFFFF);
			Process::Write32(0x0872C928, 0xFFFFFFFF);
			Process::Write32(0x0872C92C, 0xFFFFFFFF);
			Process::Write32(0x0872C930, 0xFFFFFFFF);
			Process::Write32(0x0872C934, 0xFFFFFFFF);
			Process::Write32(0x0872C938, 0xFFFFFFFF);
			Process::Write32(0x0872C93C, 0xFFFFFFFF);
			Process::Write32(0x0872C940, 0xFFFFFFFF);
			Process::Write32(0x0872C944, 0xFFFFFFFF);
			Process::Write32(0x0872C948, 0xFFFFFFFF);
			Process::Write32(0x0872C94C, 0xFFFFFFFF);
			Process::Write32(0x0872C950, 0xFFFFFFFF);
			Process::Write32(0x0872C954, 0xFFFFFFFF);
		}
		if (userchoice == 2)
		{
			Process::Write32(0x0872C8D8, 0x00000000);
			Process::Write32(0x0872C8DC, 0x00000000);
			Process::Write32(0x0872C8E0, 0x00000000);
			Process::Write32(0x0872C8E4, 0x00000000);
			Process::Write32(0x0872C8E8, 0x00000000);
			Process::Write32(0x0872C8EC, 0x00000000);
			Process::Write32(0x0872C8F0, 0x00000000);
			Process::Write32(0x0872C8F4, 0x00000000);
			Process::Write32(0x0872C8F8, 0x00000000);
			Process::Write32(0x0872C8FC, 0x00000000);
			Process::Write32(0x0872C900, 0x00000000);
			Process::Write32(0x0872C904, 0x00000000);
			Process::Write32(0x0872C908, 0x00000000);
			Process::Write32(0x0872C90C, 0x00000000);
			Process::Write32(0x0872C910, 0x00000000);
			Process::Write32(0x0872C914, 0x00000000);
			Process::Write32(0x0872C918, 0x00000000);
			Process::Write32(0x0872C91C, 0x00000000);
			Process::Write32(0x0872C920, 0x00000000);
			Process::Write32(0x0872C924, 0x00000000);
			Process::Write32(0x0872C928, 0x00000000);
			Process::Write32(0x0872C92C, 0x00000000);
			Process::Write32(0x0872C930, 0x00000000);
			Process::Write32(0x0872C934, 0x00000000);
			Process::Write32(0x0872C938, 0x00000000);
			Process::Write32(0x0872C93C, 0x00000000);
			Process::Write32(0x0872C940, 0x00000000);
			Process::Write32(0x0872C944, 0x00000000);
			Process::Write32(0x0872C948, 0x00000000);
			Process::Write32(0x0872C94C, 0x00000000);
			Process::Write32(0x0872C950, 0x00000000);
			Process::Write32(0x0872C954, 0x00000000);
		}
	}

	void YW2_Otetsudai(MenuEntry *entry)
	{
		Keyboard keyboard("お手伝いフラグ編集");
        std::vector < std::string > option =
        {
            "New", "解決", "未解決"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
		if (userchoice == 0)
		{
			Process::Write32(0x0872C9A8, 0xFFFFFFFF);
			Process::Write32(0x0872C9B0, 0xFFFFFFFF);
		}
        if (userchoice == 1)
		{
			Process::Write32(0x0872C96C, 0xFFFFFFFF);
			Process::Write32(0x0872C970, 0xFFFFFFFF);
			Process::Write32(0x0872C974, 0xFFFFFFFF);
			Process::Write32(0x0872C978, 0xFFFFFFFF);
			Process::Write32(0x0872C97C, 0xFFFFFFFF);
		}
		if (userchoice == 2)
		{
			Process::Write32(0x0872C96C, 0x00000000);
			Process::Write32(0x0872C970, 0x00000000);
			Process::Write32(0x0872C974, 0x00000000);
			Process::Write32(0x0872C978, 0x00000000);
			Process::Write32(0x0872C97C, 0x00000000);
		}
	}

	void YW2_Story(MenuEntry *entry)
	{
		Keyboard keyboard("ストーリーフラグ編集");
        std::vector < std::string > option =
        {
            "New", "解決", "未解決"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
		if (userchoice == 0)
		{
			Process::Write32(0x0872C9AC, 0xFFFFFFFF);
		}
        if (userchoice == 1)
		{
			Process::Write32(0x0872C980, 0xFFFFFFFF);
			Process::Write32(0x0872C984, 0xFFFFFFFF);
			Process::Write32(0x0872C988, 0xFFFFFFFF);
			Process::Write32(0x0872C98C, 0xFFFFFFFF);
		}
		if (userchoice == 2)
		{
			Process::Write32(0x0872C980, 0x00000000);
			Process::Write32(0x0872C984, 0x00000000);
			Process::Write32(0x0872C988, 0x00000000);
			Process::Write32(0x0872C98C, 0x00000000);
		}
	}

	void YW2_HPInfinity(MenuEntry *entry)
	{
		if (entry->IsActivated()) {
            Process::Write32(0x00575194, 0xEB0C2B9E);
			Process::Write32(0x00880014, 0xE1D400B4);
			Process::Write32(0x00880018, 0xE5D4B38E);
			Process::Write32(0x0088001C, 0xE35B0000);
			Process::Write32(0x00880020, 0x01D400B2);
			Process::Write32(0x00880024, 0x03A01000);
			Process::Write32(0x00880028, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x00575194, 0xE1D400B4);
			Process::Write32(0x00880014, 0x00000000);
			Process::Write32(0x00880018, 0x00000000);
			Process::Write32(0x0088001C, 0x00000000);
			Process::Write32(0x00880020, 0x00000000);
			Process::Write32(0x00880024, 0x00000000);
			Process::Write32(0x00880028, 0x00000000);
        }
	}

	void YW2_OneHitKill(MenuEntry *entry)
	{
		if (entry->IsActivated()) {
            Process::Write32(0x00575198, 0xEB0C2B98);
			Process::Write32(0x00880000, 0xE1D450B6);
			Process::Write32(0x00880004, 0xE5D4B38E);
			Process::Write32(0x00880008, 0xE35B0000);
			Process::Write32(0x0088000C, 0x13A00000);
			Process::Write32(0x00880010, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x00575198, 0xE1D450B6);
			Process::Write32(0x00880000, 0x00000000);
			Process::Write32(0x00880004, 0x00000000);
			Process::Write32(0x00880008, 0x00000000);
			Process::Write32(0x0088000C, 0x00000000);
			Process::Write32(0x00880010, 0x00000000);
        }
	}

	void YW2_AllAvoidance(MenuEntry *entry)
	{
		if (entry->IsActivated()) {
            Process::Write32(0x00567A9C, 0xEB0C616E);
			Process::Write32(0x0088005C, 0xE3A00000);
			Process::Write32(0x00880060, 0xE3590000);
			Process::Write32(0x00880064, 0x012FFF1E);
			Process::Write32(0x00880068, 0xE5D9B38E);
			Process::Write32(0x0088006C, 0xE35B0000);
			Process::Write32(0x00880070, 0x13A00001);
			Process::Write32(0x00880074, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x00567A9C, 0xE3A00000);
			Process::Write32(0x0088005C, 0x00000000);
			Process::Write32(0x00880060, 0x00000000);
			Process::Write32(0x00880064, 0x00000000);
			Process::Write32(0x00880068, 0x00000000);
			Process::Write32(0x0088006C, 0x00000000);
			Process::Write32(0x00880070, 0x00000000);
			Process::Write32(0x00880074, 0x00000000);
        }
	}

	void YW2_AttackCritical(MenuEntry *entry)
	{
		if (entry->IsActivated()) {
            Process::Write32(0x00569F6C, 0xEB0C5833);
			Process::Write32(0x00880040, 0xE3A00000);
			Process::Write32(0x00880044, 0xE3570000);
			Process::Write32(0x00880048, 0x012FFF1E);
			Process::Write32(0x0088004C, 0xE5D7B38E);
			Process::Write32(0x00880050, 0xE35B0000);
			Process::Write32(0x00880054, 0x13A00001);
			Process::Write32(0x00880058, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x00569F6C, 0xE3A00000);
			Process::Write32(0x00880040, 0x00000000);
			Process::Write32(0x00880044, 0x00000000);
			Process::Write32(0x00880048, 0x00000000);
			Process::Write32(0x0088004C, 0x00000000);
			Process::Write32(0x00880050, 0x00000000);
			Process::Write32(0x00880054, 0x00000000);
			Process::Write32(0x00880058, 0x00000000);
        }
	}

	void YW2_Damage65535(MenuEntry *entry)
	{
		if (entry->IsActivated()) {
            Process::Write32(0x00568C6C, 0xEB0C5D01);
			Process::Write32(0x00880078, 0xE6FF0074);
			Process::Write32(0x0088007C, 0xE92D4004);
			Process::Write32(0x00880080, 0xE3550000);
			Process::Write32(0x00880084, 0x08BD8004);
			Process::Write32(0x00880088, 0xE5D5238E);
			Process::Write32(0x0088008C, 0xE3520000);
			Process::Write32(0x00880090, 0x11DF00B0);
			Process::Write32(0x00880094, 0xE8BD8004);
			Process::Write16(0x00880098, 0xFFFF);
        }
        else {
            Process::Write32(0x00568C6C, 0xE6FF0074);
			Process::Write32(0x00880078, 0x00000000);
			Process::Write32(0x0088007C, 0x00000000);
			Process::Write32(0x00880080, 0x00000000);
			Process::Write32(0x00880084, 0x00000000);
			Process::Write32(0x00880088, 0x00000000);
			Process::Write32(0x0088008C, 0x00000000);
			Process::Write32(0x00880090, 0x00000000);
			Process::Write32(0x00880094, 0x00000000);
			Process::Write16(0x00880098, 0xFFFF);
        }
	}

	void YW2_LRCamera(MenuEntry *entry)
    {
		if (entry->IsActivated()) {
            Process::Write32(0x005BAF28, 0xE3A010FF);
            Process::Write32(0x005BAF68, 0xE3A010FF);
            Process::Write32(0x005BAF40, 0xE3A010FF);
            Process::Write32(0x005BAF90, 0xE3A010FF);
        }
        else {
            Process::Write32(0x005BAF28, 0xE3A0100A);
            Process::Write32(0x005BAF68, 0xE3A0100B);
            Process::Write32(0x005BAF40, 0xE3A0100A);
            Process::Write32(0x005BAF90, 0xE3A0100B);
        }
    }

	void YW2_YokaiEditor1(MenuEntry *entry)
    {
        u16 storage_id;
		u32 check_storage;
		Process::Read32(0x08722EF4, check_storage);
		if (check_storage == 0x00000000) {
			MessageBox("妖怪をセットしてから実行して下さい。")();
			return;
		}
		else {
			Process::Read16(0x08722EF4, storage_id);
		}
		u32 difference = storage_id * 0xC4;
        Keyboard keyboard("手持ち妖怪1 変更");
        std::vector < std::string > option =
        {
            "妖怪変更", "HP変更", "レベル変更", "力変更", "妖力変更", "守り変更", "素早さ変更"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        u32 address;
        if (userchoice == 0) {
            u32 value;
            Keyboard keyboard("妖怪変更\n妖怪IDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DBB8 + difference;
                Process::Write32(address, value);
            }
		}
        if (userchoice == 1) {
            u16 value;
            Keyboard keyboard("HP変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DBEC + difference;
                Process::Write16(address, value);
				address = 0x0870DC14 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 2) {
            u8 value;
            Keyboard keyboard("レベル変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC03 + difference;
                Process::Write8(address, value);
            }
		}
        if (userchoice == 3) {
            u16 value;
            Keyboard keyboard("力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC16 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 4) {
            u16 value;
            Keyboard keyboard("妖力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC18 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 5) {
            u16 value;
            Keyboard keyboard("守り変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC1A + difference;
                Process::Write16(address, value);
            }
		}
		if (userchoice == 6) {
            u16 value;
            Keyboard keyboard("素早さ変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC1C + difference;
                Process::Write16(address, value);
            }
		}
    }

	void YW2_YokaiEditor2(MenuEntry *entry)
    {
        u16 storage_id;
		u32 check_storage;
		Process::Read32(0x08722EF8, check_storage);
		if (check_storage == 0x00000000) {
			MessageBox("妖怪をセットしてから実行して下さい。")();
			return;
		}
		else {
			Process::Read16(0x08722EF8, storage_id);
		}
		u32 difference = storage_id * 0xC4;
        Keyboard keyboard("手持ち妖怪2 変更");
        std::vector < std::string > option =
        {
            "妖怪変更", "HP変更", "レベル変更", "力変更", "妖力変更", "守り変更", "素早さ変更"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        u32 address;
        if (userchoice == 0) {
            u32 value;
            Keyboard keyboard("妖怪変更\n妖怪IDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DBB8 + difference;
                Process::Write32(address, value);
            }
		}
        if (userchoice == 1) {
            u16 value;
            Keyboard keyboard("HP変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DBEC + difference;
                Process::Write16(address, value);
				address = 0x0870DC14 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 2) {
            u8 value;
            Keyboard keyboard("レベル変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC03 + difference;
                Process::Write8(address, value);
            }
		}
        if (userchoice == 3) {
            u16 value;
            Keyboard keyboard("力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC16 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 4) {
            u16 value;
            Keyboard keyboard("妖力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC18 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 5) {
            u16 value;
            Keyboard keyboard("守り変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC1A + difference;
                Process::Write16(address, value);
            }
		}
		if (userchoice == 6) {
            u16 value;
            Keyboard keyboard("素早さ変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC1C + difference;
                Process::Write16(address, value);
            }
		}
    }

	void YW2_YokaiEditor3(MenuEntry *entry)
    {
        u16 storage_id;
		u32 check_storage;
		Process::Read32(0x08722EFC, check_storage);
		if (check_storage == 0x00000000) {
			MessageBox("妖怪をセットしてから実行して下さい。")();
			return;
		}
		else {
			Process::Read16(0x08722EFC, storage_id);
		}
		u32 difference = storage_id * 0xC4;
        Keyboard keyboard("手持ち妖怪3 変更");
        std::vector < std::string > option =
        {
            "妖怪変更", "HP変更", "レベル変更", "力変更", "妖力変更", "守り変更", "素早さ変更"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        u32 address;
        if (userchoice == 0) {
            u32 value;
            Keyboard keyboard("妖怪変更\n妖怪IDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DBB8 + difference;
                Process::Write32(address, value);
            }
		}
        if (userchoice == 1) {
            u16 value;
            Keyboard keyboard("HP変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DBEC + difference;
                Process::Write16(address, value);
				address = 0x0870DC14 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 2) {
            u8 value;
            Keyboard keyboard("レベル変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC03 + difference;
                Process::Write8(address, value);
            }
		}
        if (userchoice == 3) {
            u16 value;
            Keyboard keyboard("力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC16 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 4) {
            u16 value;
            Keyboard keyboard("妖力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC18 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 5) {
            u16 value;
            Keyboard keyboard("守り変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC1A + difference;
                Process::Write16(address, value);
            }
		}
		if (userchoice == 6) {
            u16 value;
            Keyboard keyboard("素早さ変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC1C + difference;
                Process::Write16(address, value);
            }
		}
    }

	void YW2_YokaiEditor4(MenuEntry *entry)
    {
        u16 storage_id;
		u32 check_storage;
		Process::Read32(0x08722F00, check_storage);
		if (check_storage == 0x00000000) {
			MessageBox("妖怪をセットしてから実行して下さい。")();
			return;
		}
		else {
			Process::Read16(0x08722F00, storage_id);
		}
		u32 difference = storage_id * 0xC4;
        Keyboard keyboard("手持ち妖怪4 変更");
        std::vector < std::string > option =
        {
            "妖怪変更", "HP変更", "レベル変更", "力変更", "妖力変更", "守り変更", "素早さ変更"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        u32 address;
        if (userchoice == 0) {
            u32 value;
            Keyboard keyboard("妖怪変更\n妖怪IDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DBB8 + difference;
                Process::Write32(address, value);
            }
		}
        if (userchoice == 1) {
            u16 value;
            Keyboard keyboard("HP変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DBEC + difference;
                Process::Write16(address, value);
				address = 0x0870DC14 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 2) {
            u8 value;
            Keyboard keyboard("レベル変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC03 + difference;
                Process::Write8(address, value);
            }
		}
        if (userchoice == 3) {
            u16 value;
            Keyboard keyboard("力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC16 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 4) {
            u16 value;
            Keyboard keyboard("妖力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC18 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 5) {
            u16 value;
            Keyboard keyboard("守り変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC1A + difference;
                Process::Write16(address, value);
            }
		}
		if (userchoice == 6) {
            u16 value;
            Keyboard keyboard("素早さ変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC1C + difference;
                Process::Write16(address, value);
            }
		}
    }

	void YW2_YokaiEditor5(MenuEntry *entry)
    {
        u16 storage_id;
		u32 check_storage;
		Process::Read32(0x08722F04, check_storage);
		if (check_storage == 0x00000000) {
			MessageBox("妖怪をセットしてから実行して下さい。")();
			return;
		}
		else {
			Process::Read16(0x08722F04, storage_id);
		}
		u32 difference = storage_id * 0xC4;
        Keyboard keyboard("手持ち妖怪5 変更");
        std::vector < std::string > option =
        {
            "妖怪変更", "HP変更", "レベル変更", "力変更", "妖力変更", "守り変更", "素早さ変更"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        u32 address;
        if (userchoice == 0) {
            u32 value;
            Keyboard keyboard("妖怪変更\n妖怪IDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DBB8 + difference;
                Process::Write32(address, value);
            }
		}
        if (userchoice == 1) {
            u16 value;
            Keyboard keyboard("HP変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DBEC + difference;
                Process::Write16(address, value);
				address = 0x0870DC14 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 2) {
            u8 value;
            Keyboard keyboard("レベル変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC03 + difference;
                Process::Write8(address, value);
            }
		}
        if (userchoice == 3) {
            u16 value;
            Keyboard keyboard("力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC16 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 4) {
            u16 value;
            Keyboard keyboard("妖力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC18 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 5) {
            u16 value;
            Keyboard keyboard("守り変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC1A + difference;
                Process::Write16(address, value);
            }
		}
		if (userchoice == 6) {
            u16 value;
            Keyboard keyboard("素早さ変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC1C + difference;
                Process::Write16(address, value);
            }
		}
    }

	void YW2_YokaiEditor6(MenuEntry *entry)
    {
        u16 storage_id;
		u32 check_storage;
		Process::Read32(0x08722F08, check_storage);
		if (check_storage == 0x00000000) {
			MessageBox("妖怪をセットしてから実行して下さい。")();
			return;
		}
		else {
			Process::Read16(0x08722F08, storage_id);
		}
		u32 difference = storage_id * 0xC4;
        Keyboard keyboard("手持ち妖怪6 変更");
        std::vector < std::string > option =
        {
            "妖怪変更", "HP変更", "レベル変更", "力変更", "妖力変更", "守り変更", "素早さ変更"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        u32 address;
        if (userchoice == 0) {
            u32 value;
            Keyboard keyboard("妖怪変更\n妖怪IDを入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DBB8 + difference;
                Process::Write32(address, value);
            }
		}
        if (userchoice == 1) {
            u16 value;
            Keyboard keyboard("HP変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DBEC + difference;
                Process::Write16(address, value);
				address = 0x0870DC14 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 2) {
            u8 value;
            Keyboard keyboard("レベル変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC03 + difference;
                Process::Write8(address, value);
            }
		}
        if (userchoice == 3) {
            u16 value;
            Keyboard keyboard("力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC16 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 4) {
            u16 value;
            Keyboard keyboard("妖力変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC18 + difference;
                Process::Write16(address, value);
            }
		}
        if (userchoice == 5) {
            u16 value;
            Keyboard keyboard("守り変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC1A + difference;
                Process::Write16(address, value);
            }
		}
		if (userchoice == 6) {
            u16 value;
            Keyboard keyboard("素早さ変更\n16進数で入力してください。");
		    if (keyboard.Open(value) != -1) {
                address = 0x0870DC1C + difference;
                Process::Write16(address, value);
            }
		}
    }

	void YW2_VersionChange(MenuEntry *entry)
    {
        Keyboard keyboard("バージョン変更");
        std::vector < std::string > option =
        {
            "元祖", "本家"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
            Process::Write8(0x087272D6, 0x00);
		}
        if (userchoice == 1) {
            Process::Write8(0x087272D6, 0x01);
		}
    }

	void YW2_GenderChange(MenuEntry *entry)
    {
        Keyboard keyboard("性別変更");
        std::vector < std::string > option =
        {
            "男", "女"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
            Process::Write8(0x08727244, 0x01);
		}
        if (userchoice == 1) {
            Process::Write8(0x08727244, 0x02);
		}
    }

	void YW2_TextureBug(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0087AE0C, 0x40000000);
			Process::Write32(0x0087AE10, 0x40000000);
        }
        else {
            Process::Write32(0x0087AE0C, 0x3F800000);
			Process::Write32(0x0087AE10, 0x3F800000);
        }
    }

	void YW2_MoneyChange(MenuEntry *entry)
    {
        u32 money;
        Keyboard keyboard("所持金変更\n16進数で入力してください。");
		if (keyboard.Open(money) != -1) {
            Process::Write32(0x08722BF8, money);
        }
    }

	void YW2_InfinityStamina(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0059863C, 0xED801A03);
        }
        else {
            Process::Write32(0x0059863C, 0xDD801A03);
        }
    }

	void YW2_TalkMessageThrough(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x001DB8D8, 0xE35000FF);
        }
        else {
            Process::Write32(0x001DB8D8, 0xE3500002);
        }
    }

	void YW2_Onijikan(MenuEntry *entry)
	{
		Keyboard keyboard("強制鬼時間発動");
        std::vector < std::string > option =
        {
            "発動", "取り消し"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
            Process::Write32(0x08726AC8, 0x00100000);
		}
        if (userchoice == 1) {
            Process::Write32(0x08726AC8, 0xC0004000);
		}
	}

	void YW2_PlayerModel(MenuEntry *entry)
    {
		Keyboard keyboard("プレイヤーモデル変更");
        std::vector < std::string > option =
        {
            "自分のアイコンから設定", "IDを入力して設定", "元に戻す"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
			u32 model;
			Process::Read32(0x0872E4B0, model);
            Process::Write32(0x00412AB0, model);
			Process::Write32(0x00412AB4, model);
		}
        if (userchoice == 1) {
            u32 model;
			Keyboard keyboard("プレイヤーモデル変更\nメダル/モデルIDを入力してください。");
			if (keyboard.Open(model) != -1) {
				Process::Write32(0x00412AB0, model);
				Process::Write32(0x00412AB4, model);
			}
		}
		if (userchoice == 2) {
            Process::Write32(0x00412AB0, 0x05BFE5C8);
			Process::Write32(0x00412AB4, 0x170A4A26);
		}
    }

	void YW2_Profile_FaceIcon(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("顔アイコン変更\nメダル/モデルIDを入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write32(0x00872E4B0, value);
        }
    }

	void YW2_Profile_Daijiten(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("大辞典開放率変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write8(0x0872E4BB, value);
        }
    }

	void YW2_Profile_GoldTrophy(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("金トロフィー取得率変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write8(0x0872E4A6, value);
        }
    }

	void YW2_Profile_SilverTrophy(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("銀トロフィー取得率変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write8(0x0872E4A5, value);
        }
    }

	void YW2_Profile_BronzTrophy(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("銅トロフィー取得率変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write8(0x0872E4A4, value);
        }
    }

	void YW2_Profile_PlayTime(MenuEntry *entry)
    {
        Keyboard keyboard("プレイ時間変更");
        std::vector < std::string > option =
        {
            "999:59", "299:59", "99:59", "29:59"
        };
        keyboard.Populate(option);
        int userchoice = keyboard.Open();
        if (userchoice == 0) {
			Process::Write32(0x0872E4CC, 0x0036EE44);
		}
        if (userchoice == 1) {
            Process::Write32(0x0872E4CC, 0x00107ABF);
		}
		if (userchoice == 2) {
            Process::Write32(0x0872E4CC, 0x00057E3F);
		}
		if (userchoice == 3) {
            Process::Write32(0x0872E4CC, 0x0001A5DF);
		}
    }

	void YW2_Profile_Suretigai(MenuEntry *entry)
    {
        u16 value;
        Keyboard keyboard("すれ違った数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write16(0x0872E4CC, value);
        }
    }

	void YW2_Profile_Tanomigoto(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("頼みごとを解決した数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write8(0x0872E4B9, value);
        }
    }

	void YW2_Profile_FushigiRenz(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("ふしぎなレンズで写した妖怪数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write8(0x0872E4CE, value);
        }
    }

	void YW2_Profile_Shimeitehai(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("逮捕した指名手配妖怪数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write8(0x0872E4BA, value);
        }
    }

	void YW2_Profile_Bug(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("捕まえた虫の種類変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write8(0x0872E4BC, value);
        }
    }

	void YW2_Profile_Fish(MenuEntry *entry)
    {
        u8 value;
        Keyboard keyboard("釣った魚の種類変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write8(0x0872E4BD, value);
        }
    }

	void YW2_Profile_Syougou(MenuEntry *entry)
    {
        static const std::vector<U8_TEXT_VALUE> syougou_list =
		{
			{"初心者", 0x01},
			{"九級", 0x02},
			{"八級", 0x03},
			{"七級", 0x04},
			{"六級", 0x05},
			{"五級", 0x06},
			{"四級", 0x07},
			{"三級", 0x08},
			{"二級", 0x09},
			{"一級", 0x0A},
			{"初段", 0x0B},
			{"二段", 0x0C},
			{"三段", 0x0D},
			{"四段", 0x0E},
			{"五段", 0x0F},
			{"達人", 0x10},
			{"師範代", 0x11},
			{"師範", 0x12},
			{"博士", 0x13},
			{"名人", 0x14},
			{"マスター", 0x15},
			{"超人", 0x16},
			{"仙人", 0x17},
			{"王", 0x18},
			{"魔人", 0x19},
			{"神", 0x1A},
		};
		items.clear();
		if (items.empty()) {
			for(const U8_TEXT_VALUE &i: syougou_list)
			items.push_back(i.name);
		}
		Keyboard keyboard("称号変更", items);
		int choice = keyboard.Open();
		if (choice >= 0)
		{
			Process::Write32(0x0872E4B8,syougou_list[choice].id);
		}
    }

	void YW2_Profile_RandomBattle(MenuEntry *entry)
    {
        u16 value;
        Keyboard keyboard("ランダムバトル勝利数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write16(0x0872E4CA, value);
        }
    }

	void YW2_Profile_FriendBattle(MenuEntry *entry)
    {
        u16 value;
        Keyboard keyboard("近くの友達/フレンド対戦勝利数変更\n16進数で入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write16(0x0872E4C6, value);
        }
    }

	void YW2_Profile_FavoriteYokai1(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("お気に入り妖怪1位変更\nメダル/モデルIDを入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write32(0x0872E4D0, value);
        }
    }

	void YW2_Profile_FavoriteYokai2(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("お気に入り妖怪2位変更\nメダル/モデルIDを入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write32(0x0872E4D4, value);
        }
    }

	void YW2_Profile_FavoriteYokai3(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("お気に入り妖怪3位変更\nメダル/モデルIDを入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write32(0x0872E4D8, value);
        }
    }

	void YW2_Profile_FavoriteYokai4(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("お気に入り妖怪4位変更\nメダル/モデルIDを入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write32(0x0872E4DC, value);
        }
    }

	void YW2_Profile_FavoriteYokai5(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("お気に入り妖怪5位変更\nメダル/モデルIDを入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write32(0x0872E4E0, value);
        }
    }

	void YW2_Profile_FavoriteYokai6(MenuEntry *entry)
    {
        u32 value;
        Keyboard keyboard("お気に入り妖怪6位変更\nメダル/モデルIDを入力してください。");
		if (keyboard.Open(value) != -1) {
            Process::Write32(0x0872E4E4, value);
        }
    }

	void YW2_Fishing_Success(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x0061252C, 0xEB0364D7);
			Process::Write32(0x006EB890, 0xE92D4002);
			Process::Write32(0x006EB894, 0xE59F001C);
			Process::Write32(0x006EB898, 0xE5141118);
			Process::Write32(0x006EB89C, 0xE1500001);
			Process::Write32(0x006EB8A0, 0x059F000C);
			Process::Write32(0x006EB8A4, 0x05840004);
			Process::Write32(0x006EB8A8, 0xE3A00001);
			Process::Write32(0x006EB8AC, 0x05040034);
			Process::Write32(0x006EB8B0, 0xE8BD8002);
			Process::Write32(0x006EB8B4, 0x43C80000);
			Process::Write32(0x006EB8B8, 0x5F746365);
        }
        else {
            Process::Write32(0x0061252C, 0xEB0364D7);
			Process::Write32(0x006EB890, 0x00000000);
			Process::Write32(0x006EB894, 0x00000000);
			Process::Write32(0x006EB898, 0x00000000);
			Process::Write32(0x006EB89C, 0x00000000);
			Process::Write32(0x006EB8A0, 0x00000000);
			Process::Write32(0x006EB8A4, 0x00000000);
			Process::Write32(0x006EB8A8, 0x00000000);
			Process::Write32(0x006EB8AC, 0x00000000);
			Process::Write32(0x006EB8B0, 0x00000000);
			Process::Write32(0x006EB8B4, 0x00000000);
			Process::Write32(0x006EB8B8, 0x00000000);
        }
    }

	void YW2_ToritsukiDisable(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00573688, 0xEB062B51);
			Process::Write32(0x006FE3D4, 0xE5113042);
			Process::Write32(0x006FE3D8, 0xE3533000);
			Process::Write32(0x006FE3DC, 0x03A00000);
			Process::Write32(0x006FE3E0, 0xE3A03000);
			Process::Write32(0x006FE3E4, 0xE1C100BC);
			Process::Write32(0x006FE3E8, 0xE12FFF1E);
        }
        else {
            Process::Write32(0x00573688, 0xE1C100BC);
			Process::Write32(0x006FE3D4, 0x00000000);
			Process::Write32(0x006FE3D8, 0x00000000);
			Process::Write32(0x006FE3DC, 0x00000000);
			Process::Write32(0x006FE3E0, 0x00000000);
			Process::Write32(0x006FE3E4, 0x00000000);
			Process::Write32(0x006FE3E8, 0x00000000);
        }
    }

	void YW2_FriendChance(MenuEntry *entry)
    {
        if (entry->IsActivated()) {
            Process::Write32(0x00652F44, 0xE1A00000);
			Process::Write32(0x00652F48, 0xE3A00001);
        }
        else {
            Process::Write32(0x00652F44, 0x0A000003);
			Process::Write32(0x00652F48, 0xE3A00000);
        }
    }

	int select_npc;

	void YW2_NPC_Selector(MenuEntry *entry)
	{
		float npc_coord_x, npc_coord_y, npc_coord_z;
		u32 npc_model;
		u8 all_npc;

		Process::Read8(0x08001304, all_npc);

		if (Controller::IsKeysPressed(L + DPadRight)) {
			if (select_npc != all_npc) {
				select_npc++;
			}
		}
		else if (Controller::IsKeysPressed(L + DPadLeft)) {
			if (select_npc != 1) {
				select_npc--;
			}
		}

		Process::Read32(select_npc * 0x860 + 0x0880A700, npc_model);
		Process::ReadFloat(select_npc * 0x860 + 0x0880A2FC, npc_coord_x);
		Process::ReadFloat(select_npc * 0x860 + 0x0880A2F4, npc_coord_y);
		Process::ReadFloat(select_npc * 0x860 + 0x0880A2F8, npc_coord_z);

		OSDManager.Lock();
        const Screen &scr = OSD::GetTopScreen();
        scr.Draw(Utils::Format("Selected NPC:%d/%d", select_npc, all_npc), 10, 10);
        scr.Draw(Utils::Format("NPC Model: %x", npc_model), 10, 20);
        scr.Draw("---NPC Coordinate---", 10, 30);
		scr.Draw(Utils::Format("X = %f", npc_coord_x), 10, 40);
		scr.Draw(Utils::Format("Y = %f", npc_coord_y), 10, 50);
		scr.Draw(Utils::Format("Z = %f", npc_coord_z), 10, 60);
		scr.Draw("--------------------", 10, 70);
        OSDManager.Unlock();
	}

	void YW2_NPC_CoordinateMovement(MenuEntry *entry)
	{
		float coord_x, coord_y;
		if (Controller::IsKeysDown(B + DPadUp)) {
			Process::ReadFloat(select_npc * 0x860 + 0x0880A2FC, coord_x);
			coord_x = coord_x - 5;
			Process::WriteFloat(select_npc * 0x860 + 0x0880A2FC, coord_x);
		}
		if (Controller::IsKeysDown(B + DPadDown)) {
			Process::ReadFloat(select_npc * 0x860 + 0x0880A2FC, coord_x);
			coord_x = coord_x + 5;
			Process::WriteFloat(select_npc * 0x860 + 0x0880A2FC, coord_x);
		}
		if (Controller::IsKeysDown(B + DPadLeft)) {
			Process::ReadFloat(select_npc * 0x860 + 0x0880A2F4, coord_y);
			coord_y = coord_y - 5;
			Process::WriteFloat(select_npc * 0x860 + 0x0880A2F4, coord_y);
		}
		if (Controller::IsKeysDown(B + DPadRight)) {
			Process::ReadFloat(select_npc * 0x860 + 0x0880A2F4, coord_y);
			coord_y = coord_y + 5;
			Process::WriteFloat(select_npc * 0x860 + 0x0880A2F4, coord_y);
		}
	}

	void YW2_NPC_Stalker(MenuEntry *entry)
	{
		float coord_x, coord_y;
		if (Controller::IsKeysDown(L + A)) {
			Process::ReadFloat(select_npc * 0x860 + 0x0880A2FC, coord_x);
			Process::WriteFloat(0x08852E18, coord_x);
			Process::ReadFloat(select_npc * 0x860 + 0x0880A2F4, coord_y);
			Process::WriteFloat(0x08852E10, coord_y);
		}
	}

	void YW2_NPC_Teleport(MenuEntry *entry)
	{
		float coord_x, coord_y;
		if (Controller::IsKeysDown(L + B)) {
			Process::ReadFloat(0x08852E18, coord_x);
			Process::WriteFloat(select_npc * 0x860 + 0x0880A2FC, coord_x);
			Process::ReadFloat(0x08852E10, coord_y);
			Process::WriteFloat(select_npc * 0x860 + 0x0880A2F4, coord_y);
		}
	}

	void YW2_SaveCoordinate(MenuEntry *entry)
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
            Process::Read32(0x08852E10, coord_x);
            Process::Read32(0x08852E18, coord_y);
            Process::Read32(0x08852E14, coord_z);
		}
		if (userchoice == 1) {
            Process::Write32(0x08852E10, coord_x);
            Process::Write32(0x08852E18, coord_y);
            Process::Write32(0x08852E14, coord_z);
		}
	}
}
