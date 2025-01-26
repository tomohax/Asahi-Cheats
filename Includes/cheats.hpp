#ifndef CHEATS_H
#define CHEATS_H

#include <Helpers.hpp>
#include <csvc.h>

namespace CTRPluginFramework
{
    using StringVector = std::vector<std::string>;
	
	struct	U8_VALUE_TEXT
	{
		const u8	id;
		const char	*name;
	};
	
	struct	U16_VALUE_TEXT
	{
		const u16	id;
		const char	*name;
	};
	
	struct	U32_VALUE_TEXT
	{
		const u32	id;
		const char	*name;
	};
	
	struct	U8_TEXT_VALUE
	{
		const char	*name;
		const u8	id;
	};
	
	struct	U16_TEXT_VALUE
	{
		const char	*name;
		const u16	id;
	};
	
	struct	U32_TEXT_VALUE
	{
		const char	*name;
		const u32	id;
	};

	bool IsNew3DS();
	void PointerWrite32(u32 baseaddress, u32 add_value, u32 value);
	void PointerWrite16(u32 baseaddress, u32 add_value, u16 value);
	void PointerWrite8(u32 baseaddress, u32 add_value, u8 value);
	void PointerWriteFloat(u32 baseaddress, u32 add_value, float value);
	u32 PointerRead32(u32 baseaddress, u32 add_value);
	u16 PointerRead16(u32 baseaddress, u32 add_value);
	u8 PointerRead8(u32 baseaddress, u32 add_value);
	float PointerReadFloat(u32 baseaddress, u32 add_value);

	void SubMenu(MenuEntry *entry);

	//マリオカート7
	//0004000000030600
	bool MARIOKAR_IsInRange(u32 value, u32 lowerbound, u32 upperbound);
	bool MARIOKAR_IsInRace();
	u32 MARIOKAR_GetRacePointer();
	u32 MARIOKAR_GetFNsPointer();
	u32 MARIOKAR_GetOldPointer5CC();
	u32 MARIOKAR_GetOldPointer5D0();
	u32 MARIOKAR_GetItemPointer();
	u16 MARIOKAR_GetTime();
	u16 MARIOKAR_GetMinutes();
	u16 MARIOKAR_GetSeconds();
	void MARIOKAR_SubToTime(u16 seconds);
	void MARIOKAR_WriteItem(u32 item);
	void MARIOKAR_WriteSpeed(u32 speed);
	void MARIOKAR_WriteVR(u32 vr);
	void MARIOKAR_WriteLocation(u32 location);
	void MARIOKAR_WriteFlag(u8 flag);
	void MARIOKAR_Invincible(MenuEntry *entry);
	void MARIOKAR_AlwaysStarPower(MenuEntry *entry);
	void MARIOKAR_TrickAnywhere(MenuEntry *entry);
	void MARIOKAR_AlwaysBlackKart(MenuEntry *entry);
	void MARIOKAR_AlwaysShocked(MenuEntry *entry);
	void MARIOKAR_AlwaysCrushed(MenuEntry *entry);
	void MARIOKAR_InstantMT(MenuEntry *entry);
	void MARIOKAR_HugeBunnyhop(MenuEntry *entry);
	void MARIOKAR_FastReverse(MenuEntry *entry);
	void MARIOKAR_NoCountdown(MenuEntry *entry);
	void MARIOKAR_MoonJump(MenuEntry *entry);
	void MARIOKAR_SaveSlotTeleporter(MenuEntry *entry);
	void MARIOKAR_MaxTimer(MenuEntry *entry);
	void MARIOKAR_ZeroTimer(MenuEntry *entry);
	void MARIOKAR_WaterEverywhere(MenuEntry *entry);
	void MARIOKAR_DriveAnywhere(MenuEntry *entry);
	void MARIOKAR_Stalking(MenuEntry *entry);
	void MARIOKAR_CpuBrawl(MenuEntry *entry);
	void MARIOKAR_TouchCode(MenuEntry *entry);
	void MARIOKAR_FastBlueShell(MenuEntry *entry);
	void MARIOKAR_StoppedBlueShell(MenuEntry *entry);
	void MARIOKAR_FastGreenShell(MenuEntry *entry);
	void MARIOKAR_StoppedGreenShell(MenuEntry *entry);
	void MARIOKAR_DropMushrooms(MenuEntry *entry);
	void MARIOKAR_BulletControl(MenuEntry *entry);
	void MARIOKAR_DisableStarMusic(MenuEntry *entry);
	void MARIOKAR_BulletSpeed(MenuEntry *entry);
	void MARIOKAR_BlueShellRide(MenuEntry *entry);
	void MARIOKAR_ItemWheel(MenuEntry *entry);
	void MARIOKAR_SetItem(MenuEntry *entry);
	void MARIOKAR_InstantAcceleration(MenuEntry *entry);
	void MARIOKAR_InstantBackAcceleration(MenuEntry *entry);
	void MARIOKAR_InstantStop(MenuEntry *entry);
	void MARIOKAR_TwoHundredCC(MenuEntry *entry);
	void MARIOKAR_FiveHundredCC(MenuEntry *entry);
	void MARIOKAR_EliminationMode(MenuEntry *entry);
	void MARIOKAR_DisableFirstPersonView(MenuEntry *entry);
	void MARIOKAR_VRExtender(MenuEntry *entry);
	void MARIOKAR_SetVR(MenuEntry *entry);
	void MARIOKAR_RandomVR(MenuEntry *entry);
	void MARIOKAR_UnlockEverything(MenuEntry *entry);
	void MARIOKAR_NoDC(MenuEntry *entry);
	void MARIOKAR_FastGame(MenuEntry *entry);
	void MARIOKAR_SetFlag(MenuEntry *entry);
	void MARIOKAR_SetCoordinates(MenuEntry *entry);
	void MARIOKAR_SizeChanger(MenuEntry *entry);
	void MARIOKAR_CountdownMode(MenuEntry *entry);
	void MARIOKAR_TimeTrialGhost(MenuEntry *entry);
	void MARIOKAR_CustomMessage(MenuEntry *entry);
	void MARIOKAR_SmartSteering(MenuEntry *entry);
	void MARIOKAR_InsideDrift(MenuEntry *entry);
	void MARIOKAR_RandomItems(MenuEntry *entry);
	void MARIOKAR_TrulyRandomItems(MenuEntry *entry);
	void MARIOKAR_TwoHundredCCStable(MenuEntry *entry);
	void MARIOKAR_FiveHundredCCStable(MenuEntry *entry);
	void MARIOKAR_Aimbot(MenuEntry *entry);
	void MARIOKAR_SpeedMeter(MenuEntry *entry);
	void MARIOKAR_MiiDumper(MenuEntry *entry);
	void MARIOKAR_MaxTimer(MenuEntry *entry);

	//TITLE: 妖怪ウォッチ2 真打
	//TITLEID: 0004000000155100
	//PROCESSNAME: YW2
	void YW2_Luminous(MenuEntry *entry);
	void YW2_Motion(MenuEntry *entry);
	void YW2_ChangeTime(MenuEntry *entry);
	void YW2_RunSpeed(MenuEntry *entry);
    void YW2_DownSpeed(MenuEntry *entry);
	void YW2_CoordinateMovement(MenuEntry *entry);
	void YW2_BicycleStairs(MenuEntry *entry);
	void YW2_MoonJump(MenuEntry *entry);
	void YW2_WalkOver(MenuEntry *entry);
    void YW2_SkyWalk(MenuEntry *entry);
    void YW2_WazaInfinity(MenuEntry *entry);
	void YW2_GameSpeed(MenuEntry *entry);
	void YW2_AreaWarp(MenuEntry *entry);
	void YW2_WeatherChanger(MenuEntry *entry);
	void YW2_Daijiten(MenuEntry *entry);
	void YW2_Trophy(MenuEntry *entry);
	void YW2_YokaiSpot(MenuEntry *entry);
	void YW2_Quest(MenuEntry *entry);
	void YW2_Otetsudai(MenuEntry *entry);
	void YW2_Story(MenuEntry *entry);
	void YW2_HPInfinity(MenuEntry *entry);
	void YW2_OneHitKill(MenuEntry *entry);
	void YW2_AllAvoidance(MenuEntry *entry);
	void YW2_AttackCritical(MenuEntry *entry);
	void YW2_Damage65535(MenuEntry *entry);
	void YW2_LRCamera(MenuEntry *entry);
	void YW2_YokaiEditor1(MenuEntry *entry);
	void YW2_YokaiEditor2(MenuEntry *entry);
	void YW2_YokaiEditor3(MenuEntry *entry);
	void YW2_YokaiEditor4(MenuEntry *entry);
	void YW2_YokaiEditor5(MenuEntry *entry);
	void YW2_YokaiEditor6(MenuEntry *entry);
	void YW2_VersionChange(MenuEntry *entry);
	void YW2_GenderChange(MenuEntry *entry);
	void YW2_TextureBug(MenuEntry *entry);
	void YW2_MoneyChange(MenuEntry *entry);
	void YW2_InfinityStamina(MenuEntry *entry);
	void YW2_TalkMessageThrough(MenuEntry *entry);
	void YW2_CameraMod(MenuEntry *entry);
	void YW2_Onijikan(MenuEntry *entry);
	void YW2_PlayerModel(MenuEntry *entry);
	void YW2_Profile_FaceIcon(MenuEntry *entry);
	void YW2_Profile_Daijiten(MenuEntry *entry);
	void YW2_Profile_GoldTrophy(MenuEntry *entry);
	void YW2_Profile_SilverTrophy(MenuEntry *entry);
	void YW2_Profile_BronzTrophy(MenuEntry *entry);
	void YW2_Profile_PlayTime(MenuEntry *entry);
	void YW2_Profile_Suretigai(MenuEntry *entry);
	void YW2_Profile_Tanomigoto(MenuEntry *entry);
	void YW2_Profile_FushigiRenz(MenuEntry *entry);
	void YW2_Profile_Shimeitehai(MenuEntry *entry);
	void YW2_Profile_Bug(MenuEntry *entry);
	void YW2_Profile_Fish(MenuEntry *entry);
	void YW2_Profile_Syougou(MenuEntry *entry);
	void YW2_Profile_FriendBattle(MenuEntry *entry);
	void YW2_Profile_RandomBattle(MenuEntry *entry);
	void YW2_Profile_FavoriteYokai1(MenuEntry *entry);
	void YW2_Profile_FavoriteYokai2(MenuEntry *entry);
	void YW2_Profile_FavoriteYokai3(MenuEntry *entry);
	void YW2_Profile_FavoriteYokai4(MenuEntry *entry);
	void YW2_Profile_FavoriteYokai5(MenuEntry *entry);
	void YW2_Profile_FavoriteYokai6(MenuEntry *entry);
	void YW2_Fishing_Success(MenuEntry *entry);
	void YW2_ToritsukiDisable(MenuEntry *entry);
	void YW2_FriendChance(MenuEntry *entry);
	void YW2_NPC_Selector(MenuEntry *entry);
	void YW2_NPC_CoordinateMovement(MenuEntry *entry);
	void YW2_NPC_Stalker(MenuEntry *entry);
	void YW2_NPC_Teleport(MenuEntry *entry);
	void YW2_SaveCoordinate(MenuEntry *entry);
	
	//TITLE: とびだす! にゃんこ大戦争
	//TITLEID: 000400000015DA00
	//PROCESSNAME: NYANKO-R
	void NYANKOR_touitu(MenuEntry *entry);
	void NYANKOR_rapidnyankohou(MenuEntry *entry);
	void NYANKOR_speedup_max(MenuEntry *entry);
	void NYANKOR_treasurerader_max(MenuEntry *entry);
	void NYANKOR_nekobon_max(MenuEntry *entry);
	void NYANKOR_nyanputer_max(MenuEntry *entry);
	void NYANKOR_xpup_max(MenuEntry *entry);
	void NYANKOR_sunyaiper_max(MenuEntry *entry);
	void NYANKOR_hp_max(MenuEntry *entry);
	void NYANKOR_aitehp_0(MenuEntry *entry);
	void NYANKOR_MoneyMax(MenuEntry *entry);
	
	//TITLE: 妖怪ウォッチバスターズ 白犬隊
	//TITLEID: 000400000016C600
	//TITLE: 妖怪ウォッチバスターズ 赤猫団
	//TITLEID: 000400000016C700
	//PROCESSNAME: YW-B
	void YWB_VipLink(MenuEntry *entry);
	void YWB_EnemyStop(MenuEntry *entry);
	void YWB_GameSpeed(MenuEntry *entry);
	void YWB_DayOnlyEventReset(MenuEntry *entry);
	void YWB_DistanceFriend(MenuEntry *entry);
	void YWB_TreasureHackYokai(MenuEntry *entry);
	void YWB_TreasureHackYokaiSettings(MenuEntry *entry);
	void YWB_TreasureHackItem(MenuEntry *entry);
	void YWB_TreasureHackItemSettings(MenuEntry *entry);
	void YWB_TreasureAtari(MenuEntry *entry);
	void YWB_TreasureAtariSettings(MenuEntry *entry);
	void YWB_PatrolSakura(MenuEntry *entry);
	void YWB_PatrolSakuraSettings(MenuEntry *entry);
	void YWB_PatrolDandan(MenuEntry *entry);
	void YWB_PatrolDandanSettings(MenuEntry *entry);
	void YWB_PatrolSoyokaze(MenuEntry *entry);
	void YWB_PatrolSoyokazeSettings(MenuEntry *entry);
	void YWB_PatrolOtsukai(MenuEntry *entry);
	void YWB_PatrolOtsukaiSettings(MenuEntry *entry);
	void YWB_PatrolSakuracity(MenuEntry *entry);
	void YWB_PatrolSakuracitySettings(MenuEntry *entry);
	void YWB_PatrolKemamoto(MenuEntry *entry);
	void YWB_PatrolKemamotoSettings(MenuEntry *entry);
	void YWB_PatrolNagisaki(MenuEntry *entry);
	void YWB_PatrolNagisakiSettings(MenuEntry *entry);
	void YWB_PatrolSakuramachi(MenuEntry *entry);
	void YWB_PatrolSakuramachiSettings(MenuEntry *entry);
	void YWB_PatrolHiragama(MenuEntry *entry);
	void YWB_PatrolHiragamaSettings(MenuEntry *entry);
	void YWB_EveryRecovery65535(MenuEntry *entry);
	void YWB_Recoilless(MenuEntry *entry);
	void YWB_InfStamina(MenuEntry *entry);
	void YWB_ImmediateTechnique(MenuEntry *entry);
	void YWB_AbsolutelyFriend(MenuEntry *entry);
	void YWB_WallThrough(MenuEntry *entry);
	void YWB_Onidama2(MenuEntry *entry);
	void YWB_WalkSpeed(MenuEntry *entry);
	void YWB_StartupLevel255(MenuEntry *entry);
	void YWB_InfTechnique(MenuEntry *entry);
	void YWB_RapidABXY(MenuEntry *entry);
	void YWB_SkyWalk(MenuEntry *entry);
	void YWB_CoordinateMovement(MenuEntry *entry);
	void YWB_MoonJump(MenuEntry *entry);
	void YWB_GetKickAuthority(MenuEntry *entry);
	void YWB_NoDown(MenuEntry *entry);
	void YWB_NoDamageLimit(MenuEntry *entry);
	void YWB_TPose(MenuEntry *entry);
	void YWB_ImmediateEscape(MenuEntry *entry);
	void YWB_PlayerStalk(MenuEntry *entry);
	void YWB_ItemDropSettings(MenuEntry *entry);
	void YWB_ItemDrop(MenuEntry *entry);
	void YWB_Daijiten(MenuEntry *entry);
	void YWB_EnterRoomError(MenuEntry *entry);
	void YWB_EnterRoomTransparentV1(MenuEntry *entry);
	void YWB_EnterRoomTransparentV2(MenuEntry *entry);
	void YWB_NoKick(MenuEntry *entry);
	void YWB_YokaiPad(MenuEntry *entry);
	void YWB_Onidama(MenuEntry *entry);
	void YWB_Kisho(MenuEntry *entry);
	void YWB_MissionSelectPlayer(MenuEntry *entry);
	void YWB_LRCamera(MenuEntry *entry);
	void YWB_AllAvoidance(MenuEntry *entry);
	void YWB_Rank100Match(MenuEntry *entry);
	void YWB_PlayerJack(MenuEntry *entry);
	void YWB_KeyboardRegulationInvalid(MenuEntry *entry);
	void YWB_AllAvoidance(MenuEntry *entry);
	void YWB_ChangeRank(MenuEntry *entry);
	void YWB_MessageDrawType(MenuEntry *entry);
	void YWB_PlayerStateChange(MenuEntry *entry);
	void YWB_AutoTechnique(MenuEntry *entry);
	void YWB_DamageRecoveryDecision(MenuEntry *entry);
	void YWB_YokaiPadChange(MenuEntry *entry);
	void YWB_MessageSpeed(MenuEntry *entry);
	void YWB_TalkMessageThrough(MenuEntry *entry);
	void YWB_DamageBoost(MenuEntry *entry);
	void YWB_TechniqueCancel(MenuEntry *entry);
	void YWB_Status65535(MenuEntry *entry);
	void YWB_FriendChanceLimit(MenuEntry *entry);
	void YWB_HukidashiSize(MenuEntry *entry);
	void YWB_DrawPlayerID(MenuEntry *entry);
	void YWB_DrawPlayerIDFriend(MenuEntry *entry);
	void YWB_DrawPlayerIDBlock(MenuEntry *entry);
	void YWB_YokaiEditor1(MenuEntry *entry);
	void YWB_YokaiEditor2(MenuEntry *entry);
	void YWB_YokaiEditor3(MenuEntry *entry);
	void YWB_YokaiEditor4(MenuEntry *entry);
	void YWB_NoAttack(MenuEntry *entry);
	void YWB_TechniqueRange(MenuEntry *entry);
	void YWB_MissionTimeStop(MenuEntry *entry);
	void YWB_EnterRoomErrorAvoidance(MenuEntry *entry);
	void YWB_WaitError(MenuEntry *entry);
	void YWB_NGWord(MenuEntry *entry);
	void YWB_BossYokaiSave(MenuEntry *entry);
	void YWB_InfinityHP(MenuEntry *entry);
	void YWB_DokodemoError(MenuEntry *entry);
	void YWB_InfinityRoom(MenuEntry *entry);
	void YWB_ModelColor(MenuEntry *entry);
	void YWB_ModelColorSettings(MenuEntry *entry);
	void YWB_DrawPlayerIP(MenuEntry *entry);
	void YWB_DrawMugenheyaIP(MenuEntry *entry);
	void YWB_RapidChat(MenuEntry *entry);
	void YWB_DummyPlayer1(MenuEntry *entry);
	void YWB_DummyPlayer1_Settings(MenuEntry *entry);
	void YWB_DummyPlayer2(MenuEntry *entry);
	void YWB_DummyPlayer2_Settings(MenuEntry *entry);
	void YWB_DummyPlayer3(MenuEntry *entry);
	void YWB_DummyPlayer3_Settings(MenuEntry *entry);
	void YWB_DummyPlayer4(MenuEntry *entry);
	void YWB_DummyPlayer4_Settings(MenuEntry *entry);
	void YWB_LRCameraSeigen(MenuEntry *entry);
	void YWB_Profile_FaceIcon(MenuEntry *entry);
	void YWB_Profile_Version(MenuEntry *entry);
	void YWB_Profile_PlayTime(MenuEntry *entry);
	void YWB_Profile_Daijiten(MenuEntry *entry);
	void YWB_Profile_BronzeTrophy(MenuEntry *entry);
	void YWB_Profile_SilverTrophy(MenuEntry *entry);
	void YWB_Profile_GoldTrophy(MenuEntry *entry);
	void YWB_Profile_Attacker(MenuEntry *entry);
	void YWB_Profile_Tank(MenuEntry *entry);
	void YWB_Profile_Heeler(MenuEntry *entry);
	void YWB_Profile_Ranger(MenuEntry *entry);
	void YWB_Profile_ClearMission(MenuEntry *entry);
	void YWB_Profile_AkanekoKyouryoku(MenuEntry *entry);
	void YWB_Profile_ShiroinuKyouryoku(MenuEntry *entry);
	void YWB_Profile_AkanekoSuretigai(MenuEntry *entry);
	void YWB_Profile_ShiroinuSuretigai(MenuEntry *entry);
	void YWB_Profile_YokainoWa(MenuEntry *entry);
	void YWB_Profile_CollectSoubi(MenuEntry *entry);
	void YWB_Profile_Dondoro(MenuEntry *entry);
	void YWB_Profile_RedJ(MenuEntry *entry);
	void YWB_Profile_MityDog(MenuEntry *entry);
	void YWB_Profile_Kurooni(MenuEntry *entry);
	void YWB_Profile_PrisonBreaker(MenuEntry *entry);
	void YWB_Profile_GBabaan(MenuEntry *entry);
	void YWB_Profile_Hinoshin(MenuEntry *entry);
	void YWB_Profile_Ayatori(MenuEntry *entry);
	void YWB_Profile_FavoriteYokai1(MenuEntry *entry);
	void YWB_Profile_FavoriteYokai2(MenuEntry *entry);
	void YWB_Profile_FavoriteYokai3(MenuEntry *entry);
	void YWB_Profile_FavoriteYokai4(MenuEntry *entry);
	void YWB_Profile_FavoriteYokai5(MenuEntry *entry);
	void YWB_Profile_FavoriteYokai6(MenuEntry *entry);
	void YWB_SaveCoordinate(MenuEntry *entry);

	//TITLE: IRONFALL Invasion
	//TITLEID: 000400000017D000
	//PROCESSNAME: Ironfall
	void Ironfall_InfinityBullet(MenuEntry *entry);
	void Ironfall_WallThrough(MenuEntry *entry);
	void Ironfall_FishEye_Lens(MenuEntry *entry);
	void Ironfall_CoordinateMovement(MenuEntry *entry);
	void Ironfall_MoonJump(MenuEntry *entry);

	//TITLE: 太鼓の達人 ドコドン! ミステリーアドベンチャー
	//TITLEID: 0004000000190E00
	//PROCESSNAME: TAIKO
	void TAIKO_ResultAllGood(MenuEntry *entry);
	void TAIKO_AllCombo(MenuEntry *entry);
	void TAIKO_Soulfullafterchange(MenuEntry *entry);
	void TAIKO_AllStump(MenuEntry *entry);
	void TAIKO_AllTrimble(MenuEntry *entry);

	//TITLE: 妖怪ウォッチ3 スシ
	//TITLEID: 0004000000191000
	//PROCESSNAME: YW3
	//TITLE: 妖怪ウォッチ3 テンプラ
	//TITLEID: 0004000000191100
	//PROCESSNAME: YW3
	//TITLE: 妖怪ウォッチ3 スキヤキ
	//TITLEID: 00040000001AF400
	//PROCESSNAME: YW3
	void YW3_CoordinateMovement(MenuEntry *entry);
	void YW3_MoonJump(MenuEntry *entry);
	void YW3_SpeedHack(MenuEntry *entry);
	void YW3_WallThrough(MenuEntry *entry);
	void YW3_DamageLimitUnlock_forBattle(MenuEntry *entry);
	void YW3_GiveItemFriend_forBattle(MenuEntry *entry);
	void YW3_MoveNoWait_forBattle(MenuEntry *entry);
	void YW3_InfinityHP_forBattle(MenuEntry *entry);
	void YW3_InfinityTechnique_forBattle(MenuEntry *entry);
	void YW3_InstantKill_forBattle(MenuEntry *entry);
	void YW3_DamageMax_forBattle(MenuEntry *entry);
	void YW3_AllAvoidance_forBattle(MenuEntry *entry);
	void YW3_TPose(MenuEntry *entry);
	void YW3_GameSpeed(MenuEntry *entry);
	void YW3_MessageThrough(MenuEntry *entry);
	void YW3_PlayerModel(MenuEntry *entry);
	void YW3_OtomoModel(MenuEntry *entry);
	void YW3_NameChanger(MenuEntry *entry);
	void YW3_DisableCameraControl(MenuEntry *entry);
	void YW3_InstantFishing(MenuEntry *entry);
	void YW3_MoneyChanger(MenuEntry *entry);
	void YW3_DokodemoError(MenuEntry *entry);
	void YW3_InvisibleInRoom(MenuEntry *entry);
	void YW3_NoKick(MenuEntry *entry);
	void YW3_InRoomError(MenuEntry *entry);
	void YW3_InRoomErrorDisable(MenuEntry *entry);
	void YW3_GetKickPermission(MenuEntry *entry);
	void YW3_RapidChat(MenuEntry *entry);
	void YW3_InstantFriendChance_forTBusters(MenuEntry *entry);
	void YW3_InfHissatuTech_forTBusters(MenuEntry *entry);
	void YW3_SkillNoCooldown(MenuEntry *entry);
	void YW3_CustomCombo(MenuEntry *entry);
	void YW3_RapidABXY(MenuEntry *entry);
	void YW3_InstantKill_forTBusters(MenuEntry *entry);
	void YW3_InfHP_forTBusters(MenuEntry *entry);
	void YW3_3RenzokuAttack(MenuEntry *entry);
	void YW3_InfHP_forZombie(MenuEntry *entry);
	void YW3_InfStamina(MenuEntry *entry);
	void YW3_ModelColorSettings(MenuEntry *entry);
	void YW3_ModelColor(MenuEntry *entry);
	void YW3_DokodemoSave(MenuEntry *entry);
	void YW3_LRSeigenUnlock(MenuEntry *entry);
	void YW3_MapEvent(MenuEntry *entry);
	void YW3_CleanerRobotEnd(MenuEntry *entry);
	void YW3_MyNyanTrainingEnd(MenuEntry *entry);
	void YW3_KuruKuru(MenuEntry *entry);
	void YW3_WorldColorSettings(MenuEntry *entry);
	void YW3_WorldColor(MenuEntry *entry);
	void YW3_YokaiEditor(MenuEntry *entry);
	void YW3_InstantYokaiCatch(MenuEntry *entry);
	void YW3_BossYokaiSave(MenuEntry *entry);
	void YW3_BossYokaiBattle(MenuEntry *entry);
	void YW3_InstantKill_forZombieNight(MenuEntry *entry);
	void YW3_UngaiFlag(MenuEntry *entry);
	void YW3_DaijitenFlag(MenuEntry *entry);
	void YW3_CrossWalkNoYokai(MenuEntry *entry);
	void YW3_AlwaysBright(MenuEntry *entry);
	void YW3_1Day1EventReset(MenuEntry *entry);
	void YW3_FloorThrough(MenuEntry *entry);
	void YW3_Profile_PlayTime(MenuEntry *entry);
	void YW3_Profile_FaceIcon(MenuEntry *entry);
	void YW3_Profile_Daijiten(MenuEntry *entry);
	void YW3_Profile_BronzeTrophy(MenuEntry *entry);
	void YW3_Profile_SilverTrophy(MenuEntry *entry);
	void YW3_Profile_GoldTrophy(MenuEntry *entry);
	void YW3_Profile_Suretigai(MenuEntry *entry);
	void YW3_Profile_KeitaQuest(MenuEntry *entry);
	void YW3_Profile_InahoQuest(MenuEntry *entry);
	void YW3_Profile_Arrestyokai(MenuEntry *entry);
	void YW3_Profile_YokainoWa(MenuEntry *entry);
	void YW3_Profile_CollectBug(MenuEntry *entry);
	void YW3_Profile_CollectFish(MenuEntry *entry);
	void YW3_Profile_KatinukiBattleRensyou(MenuEntry *entry);
	void YW3_Profile_KatinukiKoushikiBattleRensyou(MenuEntry *entry);
	void YW3_Profile_ClearMission(MenuEntry *entry);
	void YW3_Profile_Unknown1(MenuEntry *entry);
	void YW3_Profile_TreasureSearchClear(MenuEntry *entry);
	void YW3_Profile_CollectMyNyan(MenuEntry *entry);
	void YW3_Profile_Unknown2(MenuEntry *entry);
	void YW3_Profile_Sakura(MenuEntry *entry);
	void YW3_Profile_Aohabara(MenuEntry *entry);
	void YW3_Profile_Unknown3(MenuEntry *entry);
	void YW3_Profile_Unknown4(MenuEntry *entry);
	void YW3_Profile_Unknown5(MenuEntry *entry);
	void YW3_Profile_Unknown6(MenuEntry *entry);
	void YW3_Profile_Unknown7(MenuEntry *entry);
	void YW3_Profile_Unknown8(MenuEntry *entry);
	void YW3_Profile_NyaKBLive(MenuEntry *entry);
	void YW3_Profile_Unknown9(MenuEntry *entry);
	void YW3_Profile_Unknown10(MenuEntry *entry);
	void YW3_Profile_Poltergeist(MenuEntry *entry);
	void YW3_Profile_FavoriteYokai1(MenuEntry *entry);
	void YW3_Profile_FavoriteYokai2(MenuEntry *entry);
	void YW3_Profile_FavoriteYokai3(MenuEntry *entry);
	void YW3_RedBoxEvent(MenuEntry *entry);
	void YW3_YokaiBrusterMax(MenuEntry *entry);
	void YW3_AreaWarp(MenuEntry *entry);
	void YW3_ZombieNightFlag(MenuEntry *entry);
	void YW3_KabegamiFlag(MenuEntry *entry);
	void YW3_BattleResultXP(MenuEntry *entry);
	void YW3_BattleResultXP_Settings(MenuEntry *entry);
	void YW3_BattleResultMoney(MenuEntry *entry);
	void YW3_BattleResultMoney_Settings(MenuEntry *entry);
	void YW3_Gasha(MenuEntry *entry);
	void YW3_DownSpeed(MenuEntry *entry);
	void YW3_SkyWalk(MenuEntry *entry);
	void YW3_Item98(MenuEntry *entry);
	void YW3_Minigame9999Point_treasure(MenuEntry *entry);
	void YW3_Coin100_treasure(MenuEntry *entry);
	void YW3_TreasureRank(MenuEntry *entry);
	void YW3_KoshikiRank(MenuEntry *entry);
	void YW3_KoshikiLate(MenuEntry *entry);
	void YW3_KoshikiRenshou(MenuEntry *entry);
	void YW3_WideCamera(MenuEntry *entry);
	void YW3_TPSCameraMove(MenuEntry *entry);
	void YW3_SaveCoordinate(MenuEntry *entry);
	void YW3_CameraZoom(MenuEntry *entry);

	//オプション
	void DecCalculator(MenuEntry *entry);
	void HexCalculator(MenuEntry *entry);
	void DecToHex(MenuEntry *entry);
	void HexToDec(MenuEntry *entry);
	//void DrawRegInfo(MenuEntry *entry);
	void DrawInfo(MenuEntry *entry);
	void plugin_exit(MenuEntry *entry);
	void GameStop(MenuEntry *entry);
	//void RangeWrite_4Byte(MenuEntry *entry);
	//void RangeWrite_2Byte(MenuEntry *entry);
	//void RangeWrite_1Byte(MenuEntry *entry);
	void GameInfo(MenuEntry *entry);
	void PointerCodeAddress(MenuEntry *entry);

	//設定
	void Setting_MainTextColor(MenuEntry *entry);
	void Setting_WindowTitleColor(MenuEntry *entry);
	void Setting_MenuSelectedItemColor(MenuEntry *entry);
	void Setting_MenuUnselectedItemColor(MenuEntry *entry);
	void Setting_BackgroundMainColor(MenuEntry *entry);
	void Setting_BackgroundSecondaryColor(MenuEntry *entry);
	void Setting_BackgroundBorderColor(MenuEntry *entry);
	void Setting_Keyboard_Background(MenuEntry *entry);
	void Setting_Keyboard_KeyBackground(MenuEntry *entry);
	void Setting_Keyboard_KeyBackgroundPressed(MenuEntry *entry);
	void Setting_Keyboard_KeyText(MenuEntry *entry);
	void Setting_Keyboard_KeyTextPressed(MenuEntry *entry);
	void Setting_Keyboard_Cursor(MenuEntry *entry);
	void Setting_Keyboard_Input(MenuEntry *entry);
	void Setting_CustomKeyboard_BackgroundMain(MenuEntry *entry);
	void Setting_CustomKeyboard_BackgroundSecondary(MenuEntry *entry);
	void Setting_CustomKeyboard_BackgroundBorder(MenuEntry *entry);
	void Setting_CustomKeyboard_KeyBackground(MenuEntry *entry);
	void Setting_CustomKeyboard_KeyBackgroundPressed(MenuEntry *entry);
	void Setting_CustomKeyboard_KeyText(MenuEntry *entry);
	void Setting_CustomKeyboard_KeyTextPressed(MenuEntry *entry);
	void Setting_CustomKeyboard_ScrollBarBackground(MenuEntry *entry);
	void Setting_CustomKeyboard_ScrollBarThumb(MenuEntry *entry);
	void Setting_Reset(MenuEntry *entry);
}

#endif