#pragma once

struct _MAGIC_TABLE
{
	uint32	iNum;
	uint8	bBeforeAction;
	uint8	bTargetAction;
	uint8	bSelfEffect;
	uint8	bFlyingEffect;
	uint32	iTargetEffect;
	uint8	bMoral;
	uint16	sSkillLevel;	
	uint16	sSkill;
	uint16	sMsp;
	uint16	sHP;
	uint8	bItemGroup;
	uint32	iUseItem;
	uint8	bCastTime;
	uint16	sReCastTime;
	uint8	bSuccessRate;
	uint8	bType[2];
	uint16	sRange;
	uint8	bEtc;
};

struct _MAGIC_TYPE1
{
	uint32	iNum;
	uint8	bHitType;
	uint16	sHitRate;
	uint16	sHit;
	uint8	bDelay;
	uint8	bComboType;
	uint8	bComboCount;
	uint16	sComboDamage;
	uint16	sRange;
};

struct _MAGIC_TYPE2
{
	uint32	iNum;
	uint8	bHitType;
	uint16	sHitRate;
	uint16	sAddDamage;
	uint16	sAddRange;
	uint8	bNeedArrow;
};

struct _MAGIC_TYPE3
{
	uint32	iNum;
	uint8	bDirectType;
	uint16	sAngle;
	int16	sFirstDamage;
	int16	sEndDamage;
	int16	sTimeDamage;
	uint8	bRadius;
	uint8	bDuration;  // duration, in seconds
	uint8	bAttribute;
};

struct _MAGIC_TYPE4
{
	uint32	iNum;
	uint8	bBuffType;
	uint8	bRadius;
	uint16	sDuration;  // duration, in seconds
	uint8	bAttackSpeed;
	uint8	bSpeed;
	uint16	sAC;
	uint16	sACPct;
	uint8	bAttack;
	uint8	bMagicAttack;
	uint16	sMaxHP;
	uint16	sMaxHPPct;
	uint16	sMaxMP;
	uint16	sMaxMPPct;
	uint8	bHitRate;
	uint16	sAvoidRate;
	int8	bStr;
	int8	bSta;
	int8	bDex;
	int8	bIntel;
	int8	bCha;
	uint8	bFireR;
	uint8	bColdR;
	uint8	bLightningR;
	uint8	bMagicR;
	uint8	bDiseaseR;
	uint8	bPoisonR;
	uint8	bExpPct;
};

struct _MAGIC_TYPE5
{
	uint32	iNum;
	uint8	bType;
	uint8	bExpRecover;
	uint16	sNeedStone;
};

struct _MAGIC_TYPE6
{
	uint32	iNum;
	uint16	sSize;
	uint16	sTransformID;
	uint16	sDuration; // duration, in seconds
	uint16	sMaxHp;
	uint16	sMaxMp;
	uint8	bSpeed;
	uint16	sAttackSpeed;
	uint16	sTotalHit;
	uint16	sTotalAc;
	uint16	sTotalHitRate;
	uint16	sTotalEvasionRate;
	uint16	sTotalFireR;
	uint16	sTotalColdR;
	uint16	sTotalLightningR;
	uint16	sTotalMagicR;
	uint16	sTotalDiseaseR;
	uint16	sTotalPoisonR;
	uint16	sClass;
	uint8	bUserSkillUse;
	uint8	bNeedItem;
	uint8	bSkillSuccessRate;
	uint8	bMonsterFriendly;
};

struct _MAGIC_TYPE7
{
	uint32	iNum;
	uint8	bValidGroup;
	uint8	bNationChange;
	uint16	sMonsterNum;
	uint8	bTargetChange;
	uint8	bStateChange;
	uint8	bRadius;
	uint16	sHitRate;
	uint16	sDuration;
	uint16	sDamage;
	uint8	bVision;
	uint32	nNeedItem;
};

struct _MAGIC_TYPE8
{
	uint32	iNum;
	uint8	bTarget;
	uint16	sRadius;
	uint8	bWarpType;
	uint16	sExpRecover;
};

struct _MAGIC_TYPE9
{
	uint32	iNum;
	uint8	bValidGroup;
	uint8	bNationChange;
	uint16	sMonsterNum;
	uint8	bTargetChange;
	uint8	bStateChange;
	uint16	sRadius;
	uint16	sHitRate;
	uint16	sDuration;
	uint16	sDamage;
	uint16	sVision;
	uint32	nNeedItem;
};

struct _SERVER_RESOURCE
{
	uint32 nResourceID;
	std::string strResource;
};

#pragma pack(push, 1)
struct _OBJECT_EVENT
{
	int sBelong;
	short sIndex;
	short sType;
	short sControlNpcID;
	short sStatus;
	float fPosX;
	float fPosY;
	float fPosZ;
	uint8 byLife;
};

struct _REGENE_EVENT
{
	float fRegenePosX;
	float fRegenePosY;
	float fRegenePosZ;
	float fRegeneAreaZ;
	float fRegeneAreaX;
	int	  sRegenePoint;
};

struct _WARP_INFO
{
	short	sWarpID;
	char	strWarpName[32];
	char	strAnnounce[256];
	uint16	sUnk0; // padding?
	uint32	dwPay;
	short	sZone;
	uint16	sUnk1; // padding?
	float	fX;
	float	fY;
	float	fZ;
	float	fR;
	short	sNation;
	uint16	sUnk2; // padding?

	_WARP_INFO() { memset(this, 0, sizeof(_WARP_INFO)); };
};
#pragma pack(pop)

struct _ZONE_INFO
{
	uint16	m_nServerNo;
	uint16	m_nZoneNumber;
	std::string	m_MapName;

#if defined(AI_SERVER)
	uint8	m_byRoomEvent;
#else
	float m_fInitX, m_fInitY, m_fInitZ;
	uint8 m_bType, isAttackZone;
#endif
};

#define MAX_PARTY_USERS		8
struct	_PARTY_GROUP
{
	WORD	wIndex;
	short	uid		[MAX_PARTY_USERS];

#ifdef EBENEZER
	uint8	bItemRouting;
	std::string	WantedMessage;
	uint16	sWantedClass;
#endif

	_PARTY_GROUP()
	{
		for (int i = 0; i < MAX_PARTY_USERS; i++)
			uid[i] = -1; 

#ifdef EBENEZER
		bItemRouting = 0;
#endif
	}
};

struct _BUFF_TYPE4_INFO
{
	bool	m_bIsBuff; // Is it a buff or a debuff?
	bool	m_bDurationExtended;
	time_t	m_tEndTime;

	INLINE bool isBuff() { return m_bIsBuff; }
	INLINE bool isDebuff() { return !m_bIsBuff; }
};