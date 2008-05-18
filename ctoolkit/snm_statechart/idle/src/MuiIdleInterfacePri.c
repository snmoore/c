/* *************************************************************************** */
/* ****************************** HEADER FILES ******************************* */
/* *************************************************************************** */
/*$Include$*/

/* ANSI include files.    */
#include <stdio.h>
#include <string.h>
#include <math.h>

/* Global include files.  */
#include "scttypes.h"
#include "ms.h"
#include "LibImagePub.h"
#include "SafeStringPub.h"
#include "Wmui_mltw.h"
#include "LnctInterfacePub.h"

/* System types include files */
#include "SysResponsePub.h"
#include "SysNwrkDataPub.h"
#include "SysSessionPub.h"
#include "SysSsUssdPub.h"
#include "SysEventPub.h"
#include "SysGndPub.h"
#include "SysCommonPub.h"
#include "SysCsvtPub.h"
#include "SysModeControlPub.h"

/* MS API include files */
#include "MsApiEventNtfPub.h"
#include "MsApiNwrkRegPub.h"
#include "MsApiSessionPub.h"
#include "MsApiLanguagePub.h"
#include "MsApiSystemConfigurationPub.h"
#include "MsApiCsvtPub.h"
#include "MsApiSecurityPub.h"
#include "MsApiCsvPub.h"
#include "MsapiNwrkRegPub.h"

/* MTWS include files.  */
#include <x11/keysymdef.h>
#include <xm/label.h>
#include <xm/pushb.h>
#include <xm/bulletinb.h>
#include "textedit.h"
#include "xm/text.h"
#include <xm/separator.h>

/* NEC-J Include files */
#include "Srv_SCH.h"
#include "Srv_SS.h"
#include "SRV_LMP.h"
#include "Srv_DSP_BL.h"
#include "ECWDCEXT.h"
#include "Srv_img.h"
#include "CLM_API.h"
#include "mmg_inc.h"
#include "mmps_ex.h"
#include "mmp_ex.h"
#include "simm_global.h"

/* Local include files.   */
#include "MuiAppTypesPub.h"
#include "EmInterfacePub.h"
#include "ApmInterfacePub.h"
#include "NumDecoder.h"
#include "MuiApplicationPub.h"
#include "MuiApplicationPro.h"
#include "MuiDisplayMessagePub.h"
#include "MuiPhoneBookInterfacePub.h"
#include "PhoneBookInterfacePub.h"
#include "CpmTypesPub.h"
#include "MuiSsInterfacePub.h"
#include "MuiSsLibPub.h"
#include "MuiAppCallTimerPub.h"
#include "MuiEmergencyCallPub.h"
#include "MuiVoiceCallsInterfacePub.h"
#include "MuiNwrkRegInterfacePub.h"
#include "MuiPssPub.h"
#include "CpmInterfacePub.h"
#include "NwrkInterfacePub.h"
#include "CallLogsInterfacePub.h"
#include "MuiBarringPub.h"
#include "MuiCallInfoPub.h"
#include "MuiClirPub.h"
#include "MuiCwPub.h"
#include "MuiDivertPub.h"
#include "MuiUnsolicitedSsParentPub.h"
#include "MuiAutoCheckPub.h"
#include "MuiSecurityPinInterfacePub.h"
#include "MuiAppMenuPub.h"
#include "SysCapabilityPub.h"
#include "MuiVideoCallPub.h"
#include "MuiSecurityInterfacePub.h"
#include "SataPerformCmdsPub.h"

/* Private include files. */
#include "srv_sip.h"
#include "Push.h"
#include "RpdMui_iface.h"
#include "RpdMui_camera.h" 
#include "mail_mui_iface.h" 
#include "brw_iface.h"
#include "HTT_LisaStub.h"
#include "MsApiDatabasePub.h"
#include "MuiCallLogsInterfacePub.h"
#include "MuigendisplayinterfacePub.h"

/*$End$*/

/* *************************************************************************** */
/* **************************** CLASS HEADER FILE **************************** */
/* *************************************************************************** */
#include "MuiIdleInterfacePub.h"
/*$RealizeRel:MuiIdle$*/

/* *************************************************************************** */
/* **************************** CLASS INFORMATION **************************** */
/* *************************************************************************** */
#define STEREOTYPE          DYNAMIC_CLASS_TYPE
#define MACRO_FILE          "MuiIdleInterfaceInt.m"
#define CLASS_INFO          TI_MUI_IDLE_INTERFACE_CLASS_INFO
#define CLASS_ID            TI_MUI_IDLE_INTERFACE_ID
#define CLASS_TYPE          TI_MUI_IDLE_INTERFACE
#define CLASS_NAME          "TI_MUI_IDLE_INTERFACE"
#define ENTRY_STATE         Start
#define EXIT_STATE          Exit
#define SIZE_OF_PUBLIC      0
#define SIZE_OF_PROTECTED   0
#define SIZE_OF_PRIVATE     SIZE_OF_INT(TI_MUI_IDLE_INTERFACE_PRIVATE)
#define MAXS_NUM_INSTANCES  1

/* *************************************************************************** */
/* ************************ MACRO FUNCTION PROTOTYPES ************************ */
/* *************************************************************************** */
DECLARE_PRIVATE_ACTION( a_Entry )
DECLARE_PRIVATE_ACTION( a_LoadIdleScreen )
DECLARE_PRIVATE_ACTION( a_LoadService )
DECLARE_PRIVATE_ACTION( a_LoadIdleMenu )
DECLARE_PRIVATE_ACTION( a_LoadDialMenu )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_DownKeyPressed )
DECLARE_PRIVATE_ACTION( a_LoadDigitsScreen )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_LeftKey )
DECLARE_PRIVATE_ACTION( a_ShowNextSIMsg )
DECLARE_PRIVATE_ACTION( a_KillFocus )
DECLARE_PRIVATE_ACTION( a_ShowPreviousSIMsg )
DECLARE_PRIVATE_ACTION( a_LoadPSSClass )
DECLARE_PRIVATE_ACTION( a_RetrieveVoiceCallString )
DECLARE_PRIVATE_ACTION( a_CreatePhonebook )
DECLARE_PRIVATE_ACTION( a_StartVideoCall )
DECLARE_PRIVATE_ACTION( a_LoadDialLockVerify )
DECLARE_PRIVATE_ACTION( a_LoadUnlockKeyPad )
DECLARE_PRIVATE_ACTION( a_FocusThisApplication )
DECLARE_PRIVATE_ACTION( a_RefreshService )
DECLARE_PRIVATE_ACTION( a_DeleteSIMsg )
DECLARE_PRIVATE_ACTION( a_SetDefaultFocus )
DECLARE_PRIVATE_ACTION( a_CreateCallLogClass )
DECLARE_PRIVATE_ACTION( a_ShowDelShortcutCnfDlg )
DECLARE_PRIVATE_ACTION( a_DeleteShortcut )
DECLARE_PRIVATE_ACTION( a_RefreshDesktop )
DECLARE_PRIVATE_ACTION( a_MoveFocusUp )
DECLARE_PRIVATE_ACTION( a_MoveFocusDown )
DECLARE_PRIVATE_ACTION( a_MoveFocusLeft )
DECLARE_PRIVATE_ACTION( a_MoveFocusRight )
DECLARE_PRIVATE_ACTION( a_ClearBuffer )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_MenuKey )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_CancelKey )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_TickKey )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_FocusOnDial )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_EndKeyPressed )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_SendKeyPressed )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_IdleDigitsStrChange )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_SKIdleAction )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_MyMenu )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_UpKeyPressed )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_AlsSwitchLine )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_ProcessKeysForOtd )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_ScreenTypeMenu )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_PasteNumber )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_LeftKey )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_RightKey )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_ProcessExpansionEvent )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_Shortcut_ItemCallback )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_Shortcut_TopLevelCallback )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_DialMenu )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_Cancel )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_ModeControl )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_SwitchKeyPressed )
DECLARE_PRIVATE_ACTION( a_HideVolume )
DECLARE_PRIVATE_ACTION( a_SetVolumeUp )
DECLARE_PRIVATE_ACTION( a_SetVolumeLow )
DECLARE_PRIVATE_GUARD( g_SIPaneActive )
DECLARE_PRIVATE_GUARD( g_CallALSSupported )
DECLARE_PRIVATE_GUARD( g_SIMRemoved )
DECLARE_PRIVATE_ACTION( a_LoadModeControl )
DECLARE_PRIVATE_ACTION( a_ModeChangeRequest )
DECLARE_PRIVATE_ACTION( a_ConfirmModeChange )
DECLARE_PRIVATE_ACTION( a_LoadModeChangeNotice )
DECLARE_PRIVATE_ACTION( a_CellSearch )
DECLARE_PRIVATE_ACTION( a_MCExit )
DECLARE_PRIVATE_ACTION( a_LoadMessage )
DECLARE_PRIVATE_ACTION( a_Cancel_DeleteShortcut )
DECLARE_PRIVATE_ACTION( a_SetEmergencyNumber )
DECLARE_PRIVATE_ACTION( a_LaunchSIPaneError )
DECLARE_PRIVATE_ACTION( a_LaunchRedialError )
DECLARE_PRIVATE_ACTION( a_LoadNoSimPresentScreen )
DECLARE_PRIVATE_ACTION( a_LoadNoSimWarning )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_ChangeMode )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_ProcessKeysInService )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_SendEndKey_pressed )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_OneTouchDial )

DECLARE_PRIVATE_ACTION( a_LoadWaitMainMenu )
#ifdef CHW_SIDEKEY
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_SetVolumeHigh )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_SetVolumeLow )
#endif
#ifdef CSW_SUPPORTKEYLOCK
DECLARE_PRIVATE_ACTION( a_LoadKeyLockScreen )
DECLARE_PRIVATE_ACTION( a_LoadUnlockScreen )
DECLARE_PRIVATE_ACTION( a_RestartTimer )
DECLARE_PRIVATE_ACTION( a_LoadKeyPressedScreen )
DECLARE_PRIVATE_ACTION( a_UnlockKeyPad )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_AnyKeyPress )
DECLARE_PRIVATE_ACTION( a_KeyLockEmergencyCnfDlg )
DECLARE_PRIVATE_ACTION( a_StartKeyLockEmergency )
#endif
DECLARE_PRIVATE_ACTION( a_LoadAttachFailMessage )
DECLARE_PRIVATE_ACTION( a_RunShortcut )
DECLARE_PRIVATE_ACTION( a_JudgeMCAction )
DECLARE_PRIVATE_ACTION( a_StartVoiceCall )
DECLARE_PRIVATE_ACTION( a_LoadVideoCallControl )
DECLARE_PRIVATE_ACTION( a_LoadUrlVideoCallControl )
DECLARE_PRIVATE_ACTION( a_LoadFdnRestricted )
DECLARE_PRIVATE_ACTION( a_LoadVerifyPIN2 )
DECLARE_PRIVATE_ACTION( a_SwitchAlsLine )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_SideKeyLockReq )


/* *************************************************************************** */
/* ******************** CLASS STATE INFORMATION GENERATION ******************* */
/* *************************************************************************** */
#define GEN_STATE_CODE_ENUM
#include "TiGenericInt.m"

/* *************************************************************************** */
/* ********************************** DEBUG ********************************** */
/* *************************************************************************** */
/*$Debug$*/
/* the following lines are in a specific order and must not be changed                    */
#define  FILE_LOG_LEVEL 0               /* 1) define the logging level for this file      */
#include "os_debug.h"                 /* 2) include all the asserts and logging externs */
/* your program can now use os_debug_l1/2/3, os_assert and os_except                      */
/*$End$*/

/* *************************************************************************** */
/* ********************** PRE CODE GENERATOR DEFINITIONS ********************* */
/* *************************************************************************** */
/*$PreCodeGen$*/
/* *************************************************************************** */
/* ********************************** MACROS ********************************* */
/* *************************************************************************** */
#ifdef ATOMBUILD    /* Cosmobic Dana Liu COS_ATOM_0037 */
    /*  CAUSION from Cosmobic Dana Liu: For ATOM, Power Up / Power Down / Idle screen
     *	are exception, MUI_APP_BASE_HEIGHT of these screens should be 180, against
     *  other application's screen are 182. So redefine it here.
     */
    #undef MUI_APP_BASE_HEIGHT
    #define MUI_APP_BASE_HEIGHT         180
#else   /* Cosmobic Dana Liu COS_ATOM_0037 */
#endif  /* Cosmobic Dana Liu COS_ATOM_0037 */

#define CLOCK_CENTER_X                  (MUI_APP_WIDTH/2)
#define CLOCK_CENTER_Y                  (MUI_APP_HEIGHT/2)
#define CLK_MINUTE_HAND_LENGTH          39
#define CLK_HOUR_HAND_LENGTH            30
#define SI_MAX_DISPLAY_LEN	        	170
#define TL_CALENDAR_ROWS                6
#define TL_CALENDAR_COLS                7

/* *************************************************************************** */
/* ************************** CONSTANT DECLARATIONS ************************** */
/* *************************************************************************** */
#define GEN_DIALOG_INFO
#include "MuiApplicationDlg.m"

typedef enum
{
	IDLE_NORMAL_STATUS,
	IDLE_DIAL_STATUS,
	IDLE_CALL_STATUS
} IDLE_STATUS;

typedef enum
{
	NORMAL_SCREEN_1,
	NORMAL_SCREEN_2,
	DIAL_SCREEN_1,
	DIAL_SCREEN_2,
	DIAL_LOCK_1,
	DIAL_LOCK_2,
	KEYPAD_LOCK_1,
	KEYPAD_LOCK_2,
	NONE_ACTION
} SOFTKEY_STATUS;

typedef enum
{
    ACT_NONE,
    ACT_MSG_VIEW,
    ACT_MSG_CREATE,
	ACT_CAMERA,
	ACT_SOS,
	ACT_UNLOCK,
	ACT_STORE,
	ACT_VIDEOCALL
} TL_IDLE_SK_ACTION;

typedef enum
{
	MISSED_CALL_NORMAL,
	MISSED_CALL_DETAIL,
	MISSED_CALL_REMOVE,
	MISSED_CALL_UNKNOWN
} MISSED_CALL_STATUS;

typedef enum
{
    IDLE_TYPE_NORMAL,
    IDLE_TYPE_CALENDAR
} TL_IDLE_SCREENTYPE;


typedef enum
{
    IDLE_ACTION_OPEN,
    IDLE_ACTION_HIDE
} TL_IDLE_CALBANNER_ACTION;

typedef enum
{
    ACTION_MC_NULL,
    ACTION_MC_CELL_SEARCH,
    ACTION_MC_MODE_CHANGE,
    ACTION_MC_MODE_IND,
    ACTION_MC_DONE
} TL_IDLE_MC_ACTION;

struct
{
    TS_TEXT_ID        SkText;
    TL_IDLE_SK_ACTION Action;
} SoftKeyData[] = {
	{ TXT_IDLE_KEY_CAMERA,	ACT_CAMERA },
	{ TXT_PBK_MESSAGE,		ACT_MSG_VIEW },		
	{ TXT_IDLE_KEY_VIDEO,	ACT_VIDEOCALL },
	{ TXT_IDLE_KEY_STORE,	ACT_STORE },
	{ TXT_IDLE_KEY_UNLOCK,	ACT_UNLOCK },
	{ TXT_IDLE_KEY_SOS,		ACT_SOS },
	{ TXT_BLANK,			ACT_NONE },
	{ TXT_BLANK,			ACT_NONE },
	{ TXT_BLANK,			ACT_NONE }
};


static const TS_TEXT_ID MonthNames[] = {
    WORD_GEN_CMN_JANUARY,
    WORD_GEN_CMN_FEBRUARY,
    WORD_GEN_CMN_MARCH,
    WORD_GEN_CMN_APRIL,
    WORD_GEN_CMN_MAY,
    WORD_GEN_CMN_JUNE,
    WORD_GEN_CMN_JULY,
    WORD_GEN_CMN_AUGUST,
    WORD_GEN_CMN_SEPTEMBER,
    WORD_GEN_CMN_OCTOBER,
    WORD_GEN_CMN_NOVEMBER,
    WORD_GEN_CMN_DECEMBER,
};


static const TS_TEXT_ID ShortDayNames[] = {
    TXT_WEEK_SUN,
    TXT_WEEK_MON,
    TXT_WEEK_TUE,
    TXT_WEEK_WED,
    TXT_WEEK_THU,
    TXT_WEEK_FRI,
    TXT_WEEK_SAT,
};

static const TS_TEXT_ID IdleMenuState[] = {
    TXT_SVC_OTD_OFF,
    TXT_SVC_OTD_ON,
    TXT_SVC_FAST_DIAL_1_9,
    TXT_SVC_FAST_DIAL_1_99,
};

static const TS_IMAGE_ID VolumeImageId[] = {
	IMG_CMN_VOL_0,
	IMG_CMN_VOL_1,
	IMG_CMN_VOL_2,
	IMG_CMN_VOL_3,
	IMG_CMN_VOL_4,
	IMG_CMN_VOL_5,
	IMG_CMN_VOL_6,
};

/* volume text */
static const TS_TEXT_ID VolumeTextId[] = {
	WORD_LBL_CMN_LEVEL0,
	WORD_LBL_CMN_LEVEL1,
	WORD_LBL_CMN_LEVEL2,
	WORD_LBL_CMN_LEVEL3,
	WORD_LBL_CMN_LEVEL4,
	WORD_LBL_CMN_LEVEL5,
	WORD_LBL_CMN_LEVEL6,
};

typedef enum
{
    REQ_PBK_VIEW,
    REQ_PBK_SEARCH,
    REQ_PBK_CREATE,
    REQ_PBK_FAST_VIEW,
    REQ_PBK_FAST_DIAL,
    REQ_PBK_FAST_VT
} TL_PBK_START_REASONS;

typedef enum
{
	SI_ACT_EXPIRATION,
	SI_ACT_DELETION,
	SI_ACT_NEWARRIVAL
} SI_ACTION_OPTIONS;

static const TS_TEXT_ID MCMode[3][2]=
{
    {WORD_MSG_MC_AUTO_2G, WORD_MSG_MC_AUTO_3G},
    {WORD_MSG_MC_MANUAL_2G, WORD_MSG_MC_MANUAL_3G},
    {WORD_MSG_MC_EMERGENCY_2G, WORD_MSG_MC_EMERGENCY_3G}
};

/* *************************************************************************** */
/* ******************************** TYPEDEFS ********************************* */
/* *************************************************************************** */
enum
{
    IDLE_MENU_LOG,
    IDLE_REDIAL_LOG,
    IDLE_INCOMING_LOG,
    IDLE_UNANSWERED_LOG,
    IDLE_UNLOAD_LOG
}; 
/* Enter user defined types here... */


/* *************************************************************************** */
/* ************************** VARIABLE DECLARATIONS ************************** */
/* *************************************************************************** */

/* Enter variable declarations here... */

/*$End$*/

/* *************************************************************************** */
/* **************************** PRIVATE STRUCTURES *************************** */
/* *************************************************************************** */
/* PrivateAccess Attributes */
typedef struct TI_MUI_IDLE_INTERFACE_PRIVATE_s
{
/*$InstStruct$*/
    TL_MUI_APP_DIALOG*               m_Dlg;
    TL_MUI_APP_DIALOG*               m_MenuDlg;
    TL_MUI_APP_DIALOG*               m_VerifyDlg;
    C_MUI_DISPLAY_MESSAGE*           m_DisplayMessage;
	C_MUI_VIDEO_CALL*				 m_VideoCallClass;
    Widget                           m_SIPane;
    Widget                           m_SATPane;
    C_MUI_DISPLAY_MESSAGE*           m_CnfDelSIDlg;
    int                              m_SIMsgListNo;
    TI_MUI_VOICE_CALLS_INTERFACE*    m_VoiceCallsClass;
    C_MUI_PSS*                       m_PssClass;
    TS_UTF_PHONENUMBER               m_IdleString;
    TS_NWRK_STATUS_NTF_DATA          m_CsInfo;
    TI_MUI_SECURITY_INTERFACE*		 m_SecurityInterface;
    Widget                           m_PlmnLabel;
    Widget                           m_TADLabel;
    Widget                           m_BltStateLabel;
    Widget                           m_ParallelPlmnLabel;
    Widget                           m_MfnLabel;
    Widget							 m_CfdLabel;
    Widget                           m_KeyLockStateLabel;
    Widget                           m_WallpaperLabel;
	Widget							 m_ShortcutTree;
	Widget							 m_SetVolumeLabel;
	Widget							 m_VolumeLabel;
	Widget							 m_TextLabel;
	Widget							 m_HelpLineLabel;
    Pixmap                           m_Wallpaper;
	Pixmap							 m_VolumeWallpaper;
    TS_SESSION_DETAILS               m_Session;
    BOOLEAN                          m_SIPaneShowed;
	BOOLEAN							 m_VolumeShowed;
    char                             m_SIMsg[ELIB_SIP_TEXT_MAX+1];
    TL_TAG_TEXT                      m_SATText;
    TS_IMAGE_ID                      m_SATIcon;
    TS_NWRK_STATUS_NTF_DATA          m_PsInfo;
    UINT8							 m_KeyPadLocked;
    TS_MUI_APP_TIMER                 m_Timer;
    TS_MUI_APP_TIMER				 m_SubLcdTimer;
    char                             m_DaysArray[TL_CALENDAR_ROWS][TL_CALENDAR_COLS];
    BOOLEAN                          m_CalendarDisplayed;
    Widget                           m_CalendarDayLabel[TL_CALENDAR_ROWS];
	Widget							 m_TodayLabel;
    TS_DATE                          m_CalendarDate;
    TL_IDLE_SCREENTYPE               m_IdleScreenType;
	int								 m_CurrentSelectedItem;
	int								 m_FormerSelectedItem;
	TS_DATABASE_USER_DISPLAY_RECORD  m_DesktopShortcutsArray[MAX_SHORTCUTS_NUM];
	TS_DATABASE_USER_DISPLAY_RECORD* m_DesktopShortcutsPointer[MAX_SHORTCUTS_NUM];
	TS_DATABASE_USER_DISPLAY_RECORD* m_DesktopShortcutsTempPointer[MAX_SHORTCUTS_NUM];
    BOOLEAN                          m_MissedCallShortcut;
	int								 m_ItemToDelete;
	int								 m_ItemToMove;
    BOOLEAN                          m_ShortcutMoving;
    int								 m_MenuHighLightItem;
    BOOLEAN							 m_bDialLockEnable;
    BOOLEAN							 m_bAlarmEnable;
#ifdef CHW_MOBILELIGHT
    BOOLEAN							 m_bMobileLight;
#endif
    int								 m_MissedCallDisplayed;
	C_MUI_UNSOLICITED_SS_PARENT*     m_UnsolicitedSsParent;
	TI_MUI_SS_INTERFACE*             m_SsInterfaceClass;
	UINT8							 m_AlsStatus;
    TI_MUI_SECURITY_PIN_INTERFACE*   m_PinControlClass;
    UINT8                            m_CalendarHide;
	TS_TEXT_ID                       m_MCOldMode;
	TS_TEXT_ID                       m_MCNewMode;
	UINT8                            m_MCAction;
	BOOLEAN							 m_bRaiseIdle;
	BOOLEAN							 m_bTelNumberAdress;
	int								 m_RowHeight;
	int								 m_IdleStatus;
#ifdef CSW_SUPPORTKEYLOCK
	BOOLEAN							 m_bKeyLockStatus;
	Widget							 m_KeyLockLabel;
	TS_MUI_APP_TIMER				 m_KeyLockTimer;
	char							 m_SosString[4];
#endif
	BOOLEAN							 m_IsSpecialUnlock;
	C_MUI_EMERGENCY_CALL*			 m_EmergencyCallInterface;
	BOOLEAN							 m_bSimRemoved;
    Widget                           m_SIPaneBG;
    BOOLEAN                          m_bAttachFailDisplaying;
/*$end$*/
} TI_MUI_IDLE_INTERFACE_PRIVATE;


/* *************************************************************************** */
/* ********************** CLASS INFORMATION GENERATION *********************** */
/* *************************************************************************** */
#define GEN_STATE_CODE
#include "TiGenericInt.m"

#define GEN_CLASS_INFO
#include "TiGenericInt.m"

/* *************************************************************************** */
/* *************************** FUNCTION PROTOTYPES *************************** */
/* *************************************************************************** */
static void DisplayMsgOnSIPane( TI_MUI_IDLE_INTERFACE* This, char* Msg, int ListNo );
static void CalculateClockPoints(  int*x,  int*y, int value, int length );
static UINT8 QueryIdleScreenType( TI_MUI_IDLE_INTERFACE* This );
static BOOLEAN QueryDialLockStatus( TI_MUI_IDLE_INTERFACE* This );
static void UpdateIdleScreenType( TI_MUI_IDLE_INTERFACE* This, 
                                  TL_IDLE_SCREENTYPE ScreenType );
static void UpdatePlmnInfo( TI_MUI_IDLE_INTERFACE* This, TS_NWRK_STATUS_NTF_DATA* CsInfo );
static void UpdateTimeDate( TI_MUI_IDLE_INTERFACE* This );
static void UpdateBacklightSetting( TI_MUI_IDLE_INTERFACE* This );
static void UpdateAlsSetting( TI_MUI_IDLE_INTERFACE* This );
static void UpdateModeFunctionSetting( TI_MUI_IDLE_INTERFACE* This, 
                                       int MfnSetting );
static void UpdateKeypadLockIcon( TI_MUI_IDLE_INTERFACE* This );
static void ProcessPushOTAEvent( TI_MUI_IDLE_INTERFACE* This, void* Data );
static void ProcessELibSINotification( TI_MUI_IDLE_INTERFACE* This );
static Pixmap PrepareWallpaper(Widget widget, Pixmap src_pixmap);
static void UpdateWallpaper( TI_MUI_IDLE_INTERFACE* This );
static void DestroyCalendar( TI_MUI_IDLE_INTERFACE* This );
static void CreateCalendar( TI_MUI_IDLE_INTERFACE* This, TS_TIME_DATE* TimeDate );
static void UpdateCalendar( TI_MUI_IDLE_INTERFACE* This );
static void PerformSoftKeyAction( TI_MUI_IDLE_INTERFACE* This, TL_IDLE_SK_ACTION Action );
static void UpdateServiceScreen( TI_MUI_IDLE_INTERFACE* This );
static void UpdateSIPane( TI_MUI_IDLE_INTERFACE* This );
static BOOLEAN SetSelectedShortcut( TI_MUI_IDLE_INTERFACE* This, int ShortcutNo );
static int GetShortcutNum( TI_MUI_IDLE_INTERFACE* This );
static void UpdateShortcuts(TI_MUI_IDLE_INTERFACE* This);
static void SwapUserDisplayRecord (TI_MUI_IDLE_INTERFACE* This, int a, int b);
static TS_DATABASE_USER_DISPLAY_RECORD * GetShortcutRecord (TI_MUI_IDLE_INTERFACE* This, int TreeItemIdx);
static int GetTreeIndexFromShortcutNo (int ShortcutNo);
static BOOLEAN ItIsMissedCallTreeIndexShortcut (TI_MUI_IDLE_INTERFACE* This, int index);
static BOOLEAN ItIsMissedCallShortcut (TI_MUI_IDLE_INTERFACE* This, int index);
static int GetMissedCallShortcutIndex (TI_MUI_IDLE_INTERFACE* This);
static int GetRightMostShortcutIndex (TI_MUI_IDLE_INTERFACE* This, int LineNo);
static void MuiAppIdleSetDlgTextId (TL_MUI_APP_DIALOG* Dialog, TS_TEXT_ID TextId, 
									TS_MUI_DLG_TEXT Mode);
static void MissedCallTimerExpired( TS_MUI_APP_TIMER * Timer, TI_GENERIC * This, int Value );								
static UINT8 QueryIdleMissedCall( TI_MUI_IDLE_INTERFACE* This );
static void UpdateIdleMissedCall( TI_MUI_IDLE_INTERFACE* This );
static void CreateTodayLabel(TI_MUI_IDLE_INTERFACE* This, UINT8 row, UINT8 column);
static BOOLEAN AreDesktopDataValid (TI_MUI_IDLE_INTERFACE* This);
static void FormatDesktopQuickMenuData (TI_MUI_IDLE_INTERFACE* This);
static TS_TEXT_ID GetNoNumberReasonTextID (T_CAUSE_OF_NOCLI_VAL reason );
static void GetSystemProfile (TI_MUI_IDLE_INTERFACE* This, TS_SYSTEM_PROFILE_ID ProfileId, size_t Size, void* Data);
static void DisplayMissedCallDetail(TI_MUI_IDLE_INTERFACE* This);
static void LaunchVideoCall(TI_MUI_IDLE_INTERFACE* This);
static void LaunchVoiceCall(TI_MUI_IDLE_INTERFACE* This);
static void MuiMtwsCallBackFunction( TI_GENERIC* This, void* DataPtr );
static void UpdateSATPane(TI_MUI_IDLE_INTERFACE* This);
static BOOLEAN IsValidPhoneNum(_IM_CLIPBOARD * ClipBoadData);
#ifdef CSW_SUPPORTKEYLOCK
static BOOLEAN IsEmergencyNum( TI_MUI_IDLE_INTERFACE* This, int Lastkey );
#endif

/* *************************************************************************** */
/* ********************* POST CODE GENERATOR DEFINITIONS ********************* */
/* *************************************************************************** */
/*$PostCodeGen$*/

/* For half transparent effect, we cannot access the MTWS directly */
#define TwmWidthOfDrawable(x) (*((unsigned short*)x+6))
#define TwmHeightOfDrawable(x)	(*((unsigned short*)x+7))
#define PIXMAP_GET_POINT_ADDR(x,i,j) ((unsigned short*)(*(unsigned long*)((unsigned short*)x+0x0a))+j*TwmWidthOfDrawable(x)+i)
#define PIXMAP_GET_POINT(x,i,j) (*(PIXMAP_GET_POINT_ADDR(x,i,j)))

#define RED_MASK 0xF800
#define GREEN_MASK 0x07E0
#define BLUE_MASK 0x001F

/* For quick menu multi-national personalization */
#define QUICK_MENU_FIX_ITEM_INIT(ITEM, NameProfile, URLProfile, AppIdProfile, StartModeProfile) \
        {\
            char Name[21], URL[71];\
            memset(Name, 0x00, 21);\
            memset(URL, 0x00, 71);\
            GetSystemProfile(This, NameProfile, 20, (void *)Name);\
            GetSystemProfile(This, URLProfile, 70, (void *)URL);\
            utfcpy(&((ITEM).AlphaTag.utf), Name);\
	        memcpy((ITEM).DataShortcutObjectHandle, URL, 70);\
            GetSystemProfile(This, AppIdProfile, 1, (void *)(&((ITEM).ApplicationId)));\
            (ITEM).FixedTextId = INVALID_WORD_ID;\
            (ITEM).bIsBuildIn = TRUE;\
            GetSystemProfile(This, StartModeProfile, 1, (void *)(&((ITEM).StartMode)));\
        }

/*$End$*/

/* *************************************************************************** */
/* **************************** GENERIC FUNCTIONS **************************** */
/* *************************************************************************** */

/*******************************************************************************
*                       D O   N O T   R E M O V E
* MACRO: START_CLASS_CONFIGURE
*
* <UINT8 Mode>
* This specifies the power up mode of the HHP
*   Mode = 0 normal power up
*   Mode = 1 warn power up (NOT SUPPORTED)
*
* Description
* This macro is used to initialise all class data. This is called once only at
* power up.
*******************************************************************************/
START_CLASS_CONFIGURE
{
   /* Enter class configuration here... */
}
END_CLASS_CONFIGURE

/*******************************************************************************
*                       D O   N O T   R E M O V E
* MACRO: START_CLASS_DECONFIGURE
*
* Description
* This macro is used to deallocate any memory are system resources that are
* still attached to this class. This is only called once during power down
*******************************************************************************/
START_CLASS_DECONFIGURE
{
   /* Enter class Deconfiguration here... */
}
END_CLASS_DECONFIGURE

/*******************************************************************************
*                       D O   N O T   R E M O V E
* MACRO: START_CLASS_NEW
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to a newly created instance of this class type.
*
* <void* ParentData>
* This is a pointer to data that the parent wants to initialise the child with
*
* Description
* This macro is called when a new instance of this class is created. This
* function is used to initialise all instance data. The parent can also pass a
* pointer to a block of data. This new instance can then use this data to help
* initialise itself. This pointer should only be used with polymorphism
*******************************************************************************/
START_CLASS_NEW
	ULONG   ulAppID_AAC;
    CHAR	cpAppID_URI[30];
{
	int i;

    /* Start VoiceCalls App */
    This->Private->m_VoiceCallsClass = FsmIfCreateInstance( This, TI_MUI_VOICE_CALLS_INTERFACE );

    /* Generate UI Session Details and Client ID */
    MuiAppCreateSessionDetails(&This->Private->m_Session, This, API_MuiIdleEventCallback, 0 );

    /* register for events */
    MuiAppEvRegisterInterestReq( &This->Private->m_Session, EVAOI_NWRK_MEASUREMENT );
    MuiAppEvRegisterInterestReq( &This->Private->m_Session, EVAOI_NWRK_REG );
    MuiAppEvRegisterInterestReq( &This->Private->m_Session, EVAOI_CSV_SERVICE );
    MuiAppEvRegisterInterestReq( &This->Private->m_Session, EVAOI_CSVT_SERVICE );
    MuiAppEvRegisterInterestReq( &This->Private->m_Session, EVAOI_RM_CMD_STATUS );
    MuiAppEvRegisterInterestReq( &This->Private->m_Session, EVAOI_CPM_SERVICE );
	MuiAppEvRegisterInterestReq( &This->Private->m_Session, EVAOI_EXTRACTION_SERVICE );
	MuiAppEvRegisterInterestReq( &This->Private->m_Session, EVAOI_LNG_SERVICE );	

    // all Lisa events routined by bridge app will be within EVAOI_KRUSTY_TEMP (by Jerry)
	MuiAppEvRegisterInterestReq( &This->Private->m_Session, EVAOI_KRUSTY_TEMP );
	MuiAppEvRegisterInterestReq( &This->Private->m_Session, SipaneNotify );

#ifdef CHW_SUBLCD
    MuiAppEvRegisterInterestReq( &This->Private->m_Session, DispNotify );
#else
#endif 

	MuiAppEvRegisterInterestReq( &This->Private->m_Session, EVAOI_SECURITY_STATUS );
	MuiAppEvRegisterInterestReq( &This->Private->m_Session, ScheduleNotify );
    /* (Bridge app) register for XExpansionEvent from NEC-J app for all Krusty app using Idle app's Infor*/
	ulAppID_AAC = 0x02;
    strcpy(cpAppID_URI, "x-wap-application:wml.ua");
	
	/* register XEvent from PushOTA app */
    PUSH_Registration(MuiAppGetDisplay(This), MuiAppGetWindow(This), ulAppID_AAC, cpAppID_URI);

#ifdef CHW_SUBLCD
	i = Elib_DSP_Request( MuiAppGetApId(This), DispNotify_NonDisp );
	os_assert((i == ELIB_DSP_STS_OK), ("Elib_DSP_Request failed" ));
#else
#endif 

	Elib_SCH_Request(APM_APP_IDLE_ID, ScheduleNotify_Interval);
	Elib_SCH_Request(APM_APP_IDLE_ID, ScheduleNotify_ChgCal);
	
    /* Register in Grab event */
    MuiAppRegisterGrabEvent( This, (unsigned char)PUSHArrivedEvent, Expansion, 0, mtws_ProcessExpansionEvent );

#ifdef CHW_SUBLCD
    MuiAppRegisterGrabEvent( This, XtTMAny, Expansion, DispNotify, mtws_ProcessExpansionEvent );
#else
#endif 

	MuiAppRegisterGrabEvent( This, XtTMAny, Expansion, SipaneNotify, mtws_ProcessExpansionEvent );
	MuiAppRegisterGrabEvent( This, XtTMAny, Expansion, ScheduleNotify, mtws_ProcessExpansionEvent );
	MuiAppRegisterGrabEvent( This, XtTMAny, Expansion, PUSHArrivedEvent, mtws_ProcessExpansionEvent );
	MuiAppRegisterGrabEvent( This, 0, Expansion, ApplicationEvent, mtws_ProcessExpansionEvent );

    This->Private->m_IdleScreenType = QueryIdleScreenType(This);
    This->Private->m_SIPaneShowed = FALSE;    
	
	This->Private->m_bDialLockEnable = QueryDialLockStatus(This);
	if(This->Private->m_bDialLockEnable)
	{
		wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKSTOP );
	}

    INIT_UTF(This->Private->m_IdleString);
    INIT_UTF(This->Private->m_SATText);

    This->Private->m_SATIcon = IMG_BLANK;

    This->Private->m_TADLabel               = NULL;
    This->Private->m_BltStateLabel          = NULL;
    This->Private->m_MfnLabel               = NULL;
    This->Private->m_CfdLabel				= NULL;
    This->Private->m_Wallpaper              = NULL;
    This->Private->m_WallpaperLabel         = NULL;
    This->Private->m_KeyLockStateLabel      = NULL;
	This->Private->m_ShortcutTree			= NULL;
    This->Private->m_SIPane                 = NULL;
    This->Private->m_SIPaneBG               = NULL;
    This->Private->m_SATPane                = NULL;
    This->Private->m_TextLabel				= NULL;
	This->Private->m_HelpLineLabel			= NULL;
	This->Private->m_VolumeShowed			= FALSE;
	This->Private->m_SIMsgListNo			= 0;
	This->Private->m_CurrentSelectedItem    = -1;
	This->Private->m_FormerSelectedItem		= -1;
    This->Private->m_ItemToDelete           = -1;
    This->Private->m_ShortcutMoving         = FALSE;
	This->Private->m_VolumeLabel			= NULL;
	This->Private->m_MenuHighLightItem		= 0;
    This->Private->m_MissedCallShortcut     = QueryIdleMissedCall(This);
    This->Private->m_bAlarmEnable			= ( Elib_SCH_ActiveEvent_Get(APM_APP_IDLE_ID) == ELIB_SCH_24H );
    This->Private->m_SubLcdTimer.InstancePtr = NULL;
    This->Private->m_bSimRemoved			= FALSE;
    This->Private->m_bAttachFailDisplaying  = FALSE;    
#ifdef CHW_MOBILELIGHT 
    This->Private->m_bMobileLight			= FALSE;
#endif
    This->Private->m_SsInterfaceClass = NULL;
    This->Private->m_CalendarHide           = FALSE;
#ifdef CHW_SIDEKEY
	Elib_KEY_Get_SideKeyLockMode( APM_APP_IDLE_ID, &This->Private->m_KeyPadLocked );
#endif
    This->Private->m_MissedCallDisplayed	= MISSED_CALL_NORMAL;
    This->Private->m_bRaiseIdle				= FALSE;
	This->Private->m_bTelNumberAdress		= FALSE;
	This->Private->m_IdleStatus				= IDLE_NORMAL_STATUS;

#ifdef CSW_SUPPORTKEYLOCK
    This->Private->m_KeyLockTimer.InstancePtr = NULL;
	This->Private->m_bKeyLockStatus			= MsApiGetKeyLockStatus( &This->Private->m_Session.Session );
	This->Private->m_KeyLockLabel			= NULL;
#endif
	
	for( i = 0; i < TL_CALENDAR_ROWS; i++)
	{
		This->Private->m_CalendarDayLabel[0] = NULL;
	}
	This->Private->m_TodayLabel		= NULL;

	if( !MuiSSIfIsExistDivert( &This->Private->m_Session.Session, &This->Private->m_AlsStatus ) )
	{
		This->Private->m_AlsStatus = 0xFF;
	}
	
	if(MuiSSIfNeedAutoCheckWhenPowerOn(&This->Private->m_Session.Session))
	{
	    This->Private->m_SsInterfaceClass = FsmIfCreateInstance( This, TI_MUI_SS_INTERFACE );
        MuiSsIfSelectMoClass( This->Private->m_SsInterfaceClass, IDLE_AUTOCHECK );
	}

	This->Private->m_MCOldMode              = 0;
	This->Private->m_MCNewMode              = 0;
	This->Private->m_MCAction                 = ACTION_MC_NULL;
	This->Private->m_IsSpecialUnlock		= FALSE;
	/* Wood 2003/09/04 register the Hutchison Long key in IDLE screen */
	Elib_KEY_LongHook_Set (MuiAppGetApId (This), XK_KEY_HUTCHISON, 10, XK_KEY_HUTCHISON, 0);    
	MuiAppRegisterGrabEvent( This, XtTMAny, Expansion, KeyNotify, mtws_ModeControl );

    /* init mode control manual 2g menu unavailable */
    {
        UINT8 bGet = 0;
        TS_PROFILE_DATA ProfileData;
        
        ProfileData.Data = &bGet;
        ProfileData.Size = 1;
        ProfileData.Id = SYSPRF_SYSGDISP_MANUAL2G_MENU_AVAILABLE;
        ProfileData.Entry = 0;
        
        MsApiSysCfgUpdateProfile (&This->Private->m_Session.Session, &ProfileData); /* Jodie 2003/09/14 in Kamoi */
    }

	for (i = 0; i < MAX_SHORTCUTS_NUM; i++)
	{
		This->Private->m_DesktopShortcutsPointer[i] = &This->Private->m_DesktopShortcutsArray[i];
	}
	/* Update desktop shortcuts */
	memset( This->Private->m_DesktopShortcutsArray, 0, sizeof(TS_DATABASE_USER_DISPLAY_RECORD)*MAX_SHORTCUTS_NUM);
	
	for (i = 0; i < MAX_SHORTCUTS_NUM; i++)
	{
		This->Private->m_DesktopShortcutsPointer[i]->Icon = IMG_IDL_TRANSPARENT_TEMP;
		INIT_UTF(This->Private->m_DesktopShortcutsPointer[i]->AlphaTag);
		memset(This->Private->m_DesktopShortcutsPointer[i]->DataShortcutObjectHandle, 0xFF, 1025);
	}

	/* If it is FTE, or the data in NAND is corrupt, we must format the database first */
	if( CpmIfCheckFirstTimeEverFlag() || !AreDesktopDataValid(This) )
	{
		FormatDesktopQuickMenuData (This);
	}

	MsApiReadDesktopShortcuts (This->Private->m_DesktopShortcutsPointer);
#ifdef CHW_SUBLCD
	Elib_DSP_BL_Dsp( APM_APP_IDLE_ID, ELIB_DSP_BL_CLOCK, NULL, NULL, 0);
	if(This->Private->m_MissedCallShortcut)
	{
		Elib_DSP_BL_Dsp( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF, NULL, NULL, 0);
	}
#else
#endif 

	/* Richard fix conflict bug temporarily */
	Clm_Conflict_Inquire( APM_APP_IDLE_ID, CLM_RET_INSTANT, CLM_INQ_START_ITEM, CLM_ITEM_DESKTOP, CLM_FIRST_INSTRUCTIONS_ACTION );
	MuiAppRegisterGrabEvent( This, XtTMAny, XtTEKey, XK_KEY_OFF_HOOK, mtws_SendEndKey_pressed );
	MuiAppRegisterGrabEvent( This, XtTMAny, XtTEKey, XK_KEY_ON_HOOK, mtws_SendEndKey_pressed );
	/* Receive data from other app.*/
	MuiAppRegisterDataCallBackFunction( This, MuiMtwsCallBackFunction );
}
END_CLASS_NEW

/*******************************************************************************
*                       D O   N O T   R E M O V E
* MACRO: START_CLASS_DELETE
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to a newly created instance of this class type.
*
* Description
* This macro is called when an instance of this class is deleted. This
* function is used to deallocated and free any resource which it might have
* required
*******************************************************************************/
START_CLASS_DELETE
{
    TS_CMD_STATUS CmdStatus;

    if(This->Private->m_Wallpaper != NULL)
    {
        XFreePixmap( XtDisplay(MuiAppGetRootWidget(This)), This->Private->m_Wallpaper);
    }
    UpdateIdleMissedCall(This);
    FsmIfDeleteInstance(This->Private->m_VoiceCallsClass);
	if( This->Private->m_SsInterfaceClass != NULL )
	{
		FsmIfDeleteInstance(This->Private->m_SsInterfaceClass);
	}

    /* deregister all area of interests */
    CmdStatus = MuiAppEvDeRegisterAllInterestReq( This );
    os_assert((CmdStatus == CMST_OK), ("AOI Rejected by Lisa" ));


#ifdef CHW_SUBLCD
    Elib_DSP_Cancel( MuiAppGetApId(This), DispNotify_NonDisp );
#else
#endif 

	Elib_SCH_Cancel(APM_APP_IDLE_ID, ScheduleNotify_Interval);
	Elib_SCH_Cancel(APM_APP_IDLE_ID, ScheduleNotify_ChgCal);

    MuiAppDeleteSessionDetails(&This->Private->m_Session);

    /* Deregister all Grab events */
    MuiAppDeRegisterGrabEvent( This, NULL );
    
    MuiAppTimerDestroy(&This->Private->m_SubLcdTimer);
    MuiAppTimerDestroy(&This->Private->m_Timer);

#ifdef CSW_SUPPORTKEYLOCK
    MuiAppTimerDestroy(&This->Private->m_KeyLockTimer);
#endif    
    /* Richard fix conflict bug temporarily */
	Clm_Conflict_Inquire( APM_APP_IDLE_ID, CLM_RET_INSTANT, CLM_INQ_END_ITEM, CLM_ITEM_DESKTOP, CLM_FIRST_RESULT_CONFLICT );
}
END_CLASS_DELETE

/*******************************************************************************
*                       D O   N O T   R E M O V E
* MACRO: START_CLASS_PROCESS_SIGNAL
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to the instance of this class type
*
* <void* Signal>
* This is a user defined void pointer
*
* <int Mode>
* This is a user defined value
*
* Description
* This macro is called when a signal is posted to this intance. The definitions
* of Signal and Mode is definable, as long as the sender and this class use
* the same definitions
* 
*******************************************************************************/
START_CLASS_PROCESS_SIGNAL
{
    return(0);
}
END_CLASS_PROCESS_SIGNAL

/* *************************************************************************** */
/* **************************** USER'S FUNCTIONS ***************************** */
/* *************************************************************************** */

/*******************************************************************************
*
* FUNCTION: DisplayMsgOnSIPane
*
* $UniqueID:3E75835A0221$
*
* $Parm:char* Msg$
* <please add parmeter description here >
* $End$
*
* $Parm:int ListNo$
* <please add parmeter description here >
* $End$
*
* $Description$
* the interface for display a string in SI pane. If the msg is null, or list no is zero,
* it will hide the SI pane.
* $End$
*******************************************************************************/
/*$Function$*/
static void DisplayMsgOnSIPane( TI_MUI_IDLE_INTERFACE* This, char* Msg, int ListNo )
{
    unsigned int MsgLen;

    /* if no newer msg is set, use the current */
    if (Msg == NULL || strlen(Msg) == 0 || ListNo == 0)
    {
        Msg = This->Private->m_SIMsg;
        ListNo = This->Private->m_SIMsgListNo;
    }

    {
        char* LFPtr;

        /* copy the new message and truncate it if it's too long */
        MsgLen = (strlen(Msg) > ELIB_SIP_TEXT_MAX) ? ELIB_SIP_TEXT_MAX : strlen(Msg);       
        memcpy (This->Private->m_SIMsg, Msg, MsgLen);

         /* Remove the line feed character */
        if (LFPtr = strchr (This->Private->m_SIMsg, '\n'))
        {
            *LFPtr = '\0';
        }

        /* Empty the following characters */
        memset (This->Private->m_SIMsg+MsgLen, 0, ELIB_SIP_TEXT_MAX+1-MsgLen);
      
        /* keep the list no */
        This->Private->m_SIMsgListNo = ListNo;
    }

    /* Show it on the pane */
    if (This->Private->m_SIPane && This->Private->m_SIPaneShowed)
    {
        MuiAppSetText (This->Private->m_SIPane, This->Private->m_SIMsg);
    }
}

/*******************************************************************************
*
* FUNCTION: CalculateClockPoints
*
* $UniqueID:3CC7D7060307$
*
* $Parm: int*x$
* <Please enter description here>
* $End$
*
* $Parm: int*y$
* <Please enter description here>
* $End$
*
* $Parm:int value$
* <Please enter description here>
* $End$
*
* $Parm:int length$
* <Please enter description here>
* $End$
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
/*$Function$*/
static void CalculateClockPoints(  int*x,  int*y, int value, int length )
{
    double temp_x, temp_y;
    float angle = (float)((2*3.1415926535) / 60)*value;
    double a = angle;

    temp_x = sin(a)*length;
    temp_y = cos(a)*length;
    temp_y = (-temp_y);

    *x = (int)temp_x;
    *y = (int)temp_y;
}

/*******************************************************************************
*
* FUNCTION: CountDays
*
* $UniqueID:3E8097DE0333$
*
* $Parm:TS_DATE date$
* <please add parmeter description here >
* $End$
*
* $Description$
* A function used when calculating the day of the week.
* $End$
*******************************************************************************/
/*$Function$*/
UINT32 CountDays( TS_DATE date )
{
    UINT32 aux1 = date.Year;
    UINT32 aux2 = date.Month + 1;

    if( date.Month <= 2 )
    {
        aux1 -= 1;
        aux2 = date.Month + 13;
    }

    return( 1461*aux1/4 + 153*aux2/5 + date.Day );
}

/*******************************************************************************
*
* FUNCTION: QueryIdleScreenType
*
* $UniqueID:3E846C9400D0$
*
* $Description$
* This function queries the middleware to determine the setting for the Idle screen type.
* $End$
*******************************************************************************/
/*$Function$*/
static UINT8 QueryIdleScreenType( TI_MUI_IDLE_INTERFACE* This )
{
    TS_PROFILE_DATA ProfileData;
    TS_CMD_STATUS CmdStatus = CMST_OK;
    UINT8 ScreenType = IDLE_TYPE_NORMAL;

    /* Read the current screen type preference from NVD */
    ProfileData.Data = &(ScreenType);
    ProfileData.Size = 1;
    ProfileData.Id = SYSPRF_SYSGDISP_CURRENT_IDLE_SCREEN;
    ProfileData.Entry = 1;
    CmdStatus = MsApiSysCfgQueryProfile (&(This->Private->m_Session.Session), &ProfileData);
    os_assert((CmdStatus == CMST_OK), ("Profile query failed" ));

    return(ScreenType);
}

/*******************************************************************************
*
* FUNCTION: QueryDialLockStatus
*
* $UniqueID:3E846C9400D0$
*
* $Description$
* This function queries dial lock status.
* $End$
*******************************************************************************/
/*$Function$*/
static BOOLEAN QueryDialLockStatus( TI_MUI_IDLE_INTERFACE* This )
{
	TS_PROFILE_DATA Profile;
	TS_CMD_STATUS result;
	BOOLEAN DialLock = FALSE;
	
	Profile.Id = SYSPR_SYSSC_DIAL_LOCK_ENABLED;
	Profile.Data = &DialLock;
	Profile.Size = sizeof(DialLock);
	Profile.Entry = 0;
	
	result = MsApiSysCfgQueryProfile( MuiAppGetSessionId(This), &Profile );
	MSAPI_ASSERT_RESPONSE_VALID( result );
	return DialLock;
}

/*******************************************************************************
*
* FUNCTION: UpdateIdleScreenType
*
* $UniqueID:3EAFAA0802D6$
*
* $Parm:TL_IDLE_SCREENTYPE ScreenType$
* The new value for the Sceen type setting.
* $End$
*
* $Description$
* This function updates the setting for the Idle screen type stored in NV.
* $End$
*******************************************************************************/
/*$Function$*/
static void UpdateIdleScreenType( TI_MUI_IDLE_INTERFACE* This, 
                                  TL_IDLE_SCREENTYPE ScreenType )
{
    TS_PROFILE_DATA ProfileData;
    TS_CMD_STATUS CmdStatus = CMST_OK;

    if((IDLE_TYPE_NORMAL <= ScreenType) && (ScreenType <= IDLE_TYPE_CALENDAR))
    {
        /* Copy the current screen type preference to NVD */
        ProfileData.Data = &(ScreenType);
        ProfileData.Size = 1;
        ProfileData.Id = SYSPRF_SYSGDISP_CURRENT_IDLE_SCREEN;
        ProfileData.Entry = 1;
        CmdStatus = MsApiSysCfgUpdateProfile (&This->Private->m_Session.Session, &ProfileData);
        os_assert((CmdStatus == CMST_OK), ("Profile update failed" ));
    }
}

/*******************************************************************************
*
* FUNCTION: UpdatePlmnInfo
*
* $UniqueID:3CC7D705016B$
*
* $Parm:TS_NWRK_STATUS_NTF_DATA* CsInfo$
* <Please enter description here>
* $End$
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
/*$Function$*/
static void UpdatePlmnInfo( TI_MUI_IDLE_INTERFACE* This, TS_NWRK_STATUS_NTF_DATA* CsInfo )
{
    TS_IMAGE_ID  Image;
    UTF_PLMN_LONGFORM   PlmnBuf1;
    UTF_PLMN_SHORTFORM  PlmnBuf2;
    UTF_SPN_NAME        SpnBuf;
    TS_PLMN_DATA Plmn;
    TS_NWRK_STATUS_NTF_DATA CsData;
    
    INIT_UTF(PlmnBuf1);
    INIT_UTF(PlmnBuf2);
    INIT_UTF(SpnBuf);
    
    if(This->Private->m_ParallelPlmnLabel)
    {
        XtUnmapWidget( This->Private->m_ParallelPlmnLabel );
    }
    
    if(This->Private->m_PlmnLabel)
    {
        XtUnmapWidget(This->Private->m_PlmnLabel);
        MuiAppSetText( This->Private->m_PlmnLabel, "" );
        
        MsApiNwrkQueryCsRegStatus(NULL,&CsData);
        /* If CS is "CS normal", display operator name. */
        if (CsData.RegStatusData == NORMAL_SERVICE) 
        {
            MsApiNwrkQueryRegisteredPlmn(NULL,&Plmn);
            
            switch(NwrkIfGetSpnDisplayMode())
            {
            case SYPLMN_SPN_NOTHING:
                {
                    MuiAppSetText(This->Private->m_PlmnLabel, "");
                    MuiAppSetText(This->Private->m_ParallelPlmnLabel, "");
                }
                break;
                
            case SYPLMN_SPN_DISABLED:
                NwrkIfPlmnGetDispInfo( &PlmnBuf1.utf, &PlmnBuf2.utf, &Image,&Plmn );
                if(Image != IMG_BLANK)
                {
                    MuiAppSetImageIdTransparent( This->Private->m_PlmnLabel, Image, 0xFFE0 );
                    XtVaSetValues( This->Private->m_PlmnLabel, XmNtransparentGrid, False, NULL );
                    XtMapWidget(This->Private->m_PlmnLabel);
                }
                else
                {
                    if(utflen(&PlmnBuf1.utf) <=16 && utflen(&PlmnBuf1.utf) > 0)
                    {
                        MuiAppSetText( This->Private->m_PlmnLabel, PlmnBuf1.buf );
                        XtMapWidget(This->Private->m_PlmnLabel);
                    }
                    else if( utflen(&PlmnBuf2.utf) > 0 )
                    {
                        MuiAppSetText( This->Private->m_PlmnLabel, PlmnBuf2.buf );
                        XtMapWidget(This->Private->m_PlmnLabel);
                    }
                }
                break;

            case SYPLMN_SPN_SERIAL:
                NwrkIfSpnGetInfo( &SpnBuf.utf, &Image);
                if(Image != IMG_BLANK)
                {
                    MuiAppSetImageIdTransparent( This->Private->m_PlmnLabel, Image, 0xFFE0 );
                    XtVaSetValues( This->Private->m_PlmnLabel, XmNtransparentGrid, False, NULL );
                    XtMapWidget(This->Private->m_PlmnLabel);
                }
                else if(utflen(&SpnBuf.utf) > 0)
                {
                    MuiAppSetText( This->Private->m_PlmnLabel, SpnBuf.buf );
                    XtMapWidget(This->Private->m_PlmnLabel);
                }
                break;
                
            case SYPLMN_SPN_PARALLEL:
                NwrkIfPlmnGetDispInfo( &PlmnBuf1.utf, &PlmnBuf2.utf, &Image, &Plmn);
                NwrkIfSpnGetInfo( &SpnBuf.utf, &Image);
                
                if(Image == IMG_BLANK)
                {
                    MuiAppSetText( This->Private->m_PlmnLabel, SpnBuf.buf );
                    if(utflen(&SpnBuf.utf) > 0)
                    {
                        XtMapWidget(This->Private->m_PlmnLabel);
                    }
                }
                else
                {
                    MuiAppSetImageIdTransparent( This->Private->m_PlmnLabel, Image, 0xFFE0 );
                    XtVaSetValues( This->Private->m_PlmnLabel, XmNtransparentGrid, False, NULL );
                    XtMapWidget(This->Private->m_PlmnLabel);
                }
                if(utflen(&PlmnBuf1.utf) <=16 && utflen(&PlmnBuf1.utf) > 0)
                {
                    MuiAppSetText( This->Private->m_ParallelPlmnLabel, PlmnBuf1.buf );
                    XtMapWidget(This->Private->m_ParallelPlmnLabel);
                }
                else if(utflen(&PlmnBuf2.utf) > 0)
                {
                    MuiAppSetText( This->Private->m_ParallelPlmnLabel, PlmnBuf2.buf );
                    XtMapWidget(This->Private->m_ParallelPlmnLabel);
                }
                break;
            }
        }
    }
}

/*******************************************************************************
*
* FUNCTION: UpdateTimeDate
*
* $UniqueID:3CC7D705039C$
*
* $Parm:TS_TIME_DATE* TimeDate$
* <Please enter description here>
* $End$
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
/*$Function$*/
static void UpdateTimeDate( TI_MUI_IDLE_INTERFACE* This )
{
    char Buffer[30];
    int DayStyle;
	TS_TIME_DATE TimeDate;
	
	memset( &TimeDate, 0, sizeof(TS_TIME_DATE) ) ;
	MsApiGetCurrentTimeAndDate(&TimeDate);
	
	if( This->Private->m_TADLabel != NULL )
    {
        if(MsApiIsClockShownInIdle())
        {
            XtManageChild(This->Private->m_TADLabel);

			DayStyle = Elib_SCH_StsRead( APM_APP_IDLE_ID, ELIB_SCH_DATA_CLOCK_FORMAT );

			switch(DayStyle)
			{
				case ELIB_SCH_MM_DD :
					sprintf(Buffer, "%02d/%02d/%04d",TimeDate.month, TimeDate.day, TimeDate.year);
					break;
				
				case ELIB_SCH_DD_MM :
					sprintf(Buffer, "%02d/%02d/%04d", TimeDate.day, TimeDate.month, TimeDate.year);
					break;
				case ELIB_SCH_YYYY:
					sprintf(Buffer, "%04d/%02d/%02d", TimeDate.year, TimeDate.month, TimeDate.day);
					break;
				case ELIB_SCH_NG:
				case ELIB_SCH_PARAM_NG:
				default:
					
					break;
			}

			/* Format the date */
            MuiAppSetText(This->Private->m_TADLabel, Buffer);
        }
        else
        {
            XtUnmanageChild(This->Private->m_TADLabel);
        }
    }
}

/*******************************************************************************
*
* FUNCTION: UpdateBacklightSetting
*
* $UniqueID:3CC7D706013A$
*
* $Parm:const TS_BLT_STATE_PARAMS* BltSetting$
* <Please enter description here>
* $End$
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
/*$Function$*/
static void UpdateBacklightSetting( TI_MUI_IDLE_INTERFACE* This )
{
	int VibMode = 0;
	int BltSetting = 0;
	
    if(This->Private->m_BltStateLabel!=NULL)
    {
        /* Check Vibrate mode */
        VibMode = Elib_WDC_Get_VibMode(MuiAppGetApId(This), ELIB_WDC_PHONEMODE_CURRENT);
        if(VibMode != ELIB_WDC_VIB_OFF)
        {
            MuiAppSetImageIdTransparent( This->Private->m_BltStateLabel, IMG_IDL_VIB, 0xFFE0 );
        }
        else
        {
            BltSetting = Elib_LMP_GetBKLTMode(MuiAppGetApId(This), ELIB_SS_PHONEMODE_CURRENT, ELIB_LMP_BKLTSET);
			if (BltSetting == ELIB_LMP_BKLTSET_OFF)
            {
                MuiAppSetImageIdTransparent( This->Private->m_BltStateLabel, IMG_IDL_BLT_OFF, 0xFFE0 );
            }
            else
            {
                MuiAppSetImageIdTransparent( This->Private->m_BltStateLabel, IMG_IDL_BLT, 0xFFE0 );
            }
        }

		XtMapWidget(This->Private->m_BltStateLabel);
    }
}


/*******************************************************************************
*
* FUNCTION: UpdateAlsSetting
*
* $UniqueID:3CC7D706013A$
*
* $Parm:const TS_BLT_STATE_PARAMS* BltSetting$
* <Please enter description here>
* $End$
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
/*$Function$*/
static void UpdateAlsSetting( TI_MUI_IDLE_INTERFACE* This )
{
	if( This->Private->m_CfdLabel != NULL )
	{
		switch(This->Private->m_AlsStatus)
		{
			case ALS_LINE_1:
				MuiAppSetImageIdTransparent( This->Private->m_CfdLabel, IMG_SS_2, 0xFFE0 );				
				XtManageChild( This->Private->m_CfdLabel );
				break;
				
			case ALS_LINE_2:
                            MuiAppSetImageIdTransparent( This->Private->m_CfdLabel, IMG_SS_3, 0xFFE0 );
                            XtManageChild( This->Private->m_CfdLabel );
				break;
			
			case ALS_LINE_12:
                            MuiAppSetImageIdTransparent( This->Private->m_CfdLabel, IMG_SS_4, 0xFFE0 );
                            XtManageChild( This->Private->m_CfdLabel );
				break;

			case ALS_LINE_VOICE:
                            MuiAppSetImageIdTransparent( This->Private->m_CfdLabel, IMG_SS_1, 0xFFE0 );
                            XtManageChild( This->Private->m_CfdLabel );
				break;
				
			default:
				XtUnmanageChild( This->Private->m_CfdLabel );
				break;
		}
	}
}

/*******************************************************************************
*
* FUNCTION: UpdateModeFunctionSetting
*
* $UniqueID:3CC7D706020C$
*
* $Parm:TS_MFN_SETTING MfnSetting$
* <Please enter description here>
* $End$
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
/*$Function$*/
static void UpdateModeFunctionSetting( TI_MUI_IDLE_INTERFACE* This, 
                                       int MfnSetting )
{
    TS_IMAGE_ID Image = IMG_BLANK;
    if(This->Private->m_MfnLabel!=NULL)
    {
        switch(MfnSetting)
        {
            case ELIB_WDC_PHONEMODE_NOMAL:
				Image = IMG_IDL_MODE_NORMAL;
                break;
            case ELIB_WDC_PHONEMODE_MEETING:
                Image = IMG_IDL_MODE_MEETING;
                break;
            case ELIB_WDC_PHONEMODE_POCKET:
                Image = IMG_IDL_MODE_POCKET;
                break;
            case ELIB_WDC_PHONEMODE_CAR:
                Image = IMG_IDL_MODE_CAR;
                break;
            default:
                os_assert(FALSE, ("Invalid mode setting"));
                break;

        }
        if(Image != IMG_BLANK)
        {
            MuiAppSetImageIdTransparent( This->Private->m_MfnLabel, Image, 0xFFE0 );
            XtManageChild(This->Private->m_MfnLabel);
        }
        else
        {
            XtUnmanageChild(This->Private->m_MfnLabel);
        }
    }
}

/*******************************************************************************
*
* FUNCTION: UpdateKeypadLockIcon
*
* $UniqueID:3CC7D707020E$
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
/*$Function$*/
static void UpdateKeypadLockIcon( TI_MUI_IDLE_INTERFACE* This )
{
    if(This->Private->m_KeyLockStateLabel!=NULL)
    {
        if(This->Private->m_bDialLockEnable)
        {
            /* Check dial lock status */
            MuiAppSetImageIdTransparent( This->Private->m_KeyLockStateLabel, IMG_IDL_KEYLOCK, 0xFFE0 );
            XtManageChild(This->Private->m_KeyLockStateLabel);
        }        	
#ifdef CSW_SUPPORTKEYLOCK
		else if( This->Private->m_bKeyLockStatus )
		{
			/* Check key lock status */
			MuiAppSetImageId(This->Private->m_KeyLockStateLabel, IMG_IDL_KEYLOCK_2);
			XtManageChild(This->Private->m_KeyLockStateLabel);
		}
#endif
        else if(This->Private->m_bAlarmEnable)
        {
            MuiAppSetImageIdTransparent(This->Private->m_KeyLockStateLabel, IMG_IDL_ALARM, 0xFFE0);
            XtManageChild(This->Private->m_KeyLockStateLabel);
        }
#ifdef CHW_SIDEKEY
        /* Check key lock status */
        else if(This->Private->m_KeyPadLocked == ELIB_KEY_SIDEKEYCLOSE_OFF)
        {
            MuiAppSetImageIdTransparent( This->Private->m_KeyLockStateLabel, IMG_IDL_SIDELOCK, 0xFFE0 );
            XtManageChild(This->Private->m_KeyLockStateLabel);
        }
#endif
        else
        {
        	XtUnmanageChild(This->Private->m_KeyLockStateLabel);
        }
    }
}

/*******************************************************************************
*
* FUNCTION: ProcessPushOTAEvent
*
* $UniqueID:3E8166CA017F$
*
* $Parm:void* Data$
* <please add parmeter description here >
* $End$
*
* $Description$
* Process Push OTA event
* $End$
*******************************************************************************/
/*$Function$*/
static void ProcessPushOTAEvent( TI_MUI_IDLE_INTERFACE* This, void* Data )
{
	PUSH_COMMON_ARG	*pPush_Com_Arg;
	pPush_Com_Arg = (PUSH_COMMON_ARG *)(Data);
	
    Elib_SIP_Set (MuiAppGetApId(This), pPush_Com_Arg->iSize, (unsigned char *)pPush_Com_Arg->cData,
                 pPush_Com_Arg->cContent_type);
}

/*******************************************************************************
*
* FUNCTION: ProcessELibSINotification
*
* $UniqueID:3E8166E802F5$
*
* $Description$
* Process ELIB notification SIPane_Update
* $End$
*******************************************************************************/
/*$Function$*/
static void ProcessELibSINotification( TI_MUI_IDLE_INTERFACE* This )
{
    UpdateSIPane (This);
}

/*******************************************************************************
*
* FUNCTION: PrepareWallpaper
*
* $UniqueID:$
*
* $Description$
* Prepare wallpaper
* $End$
*******************************************************************************/
/*$Function$*/
static Pixmap PrepareWallpaper(Widget widget, Pixmap src_pixmap)
{
    Pixmap dst_pixmap = NULL;
    GC  tmp_gc = NULL;

    /*create background pixmap (200*176)*/
    dst_pixmap = XCreatePixmap(XtDisplay(widget),
                                   RootWindowOfScreen(XtScreen(widget)),
                                   MUI_APP_WIDTH,
                                   MUI_APP_BASE_HEIGHT,
                                   PlanesOfScreen(XtScreen(widget)));
    if(dst_pixmap == NULL)
    {
        return NULL;
    }

    /*create GC structure*/
    if ((tmp_gc = XCreateGC(XtDisplay(widget), dst_pixmap, 0, NULL)) == NULL)
    {
        XFreePixmap(XtDisplay(widget), dst_pixmap);
        return NULL;
    }

    /*set foreground colour as white*/
    XSetForeground(XtDisplay(widget), tmp_gc, 0xffff);

    /*fill the whole background pixmap with white colour */
    XFillRectangle(XtDisplay(widget),
                   dst_pixmap,
                   tmp_gc,
                   0,
                   0,
                   MUI_APP_WIDTH,
                   MUI_APP_BASE_HEIGHT);

    /*copy wallpaper data into background pixmap*/
    if(!XCopyArea(XtDisplay(widget), src_pixmap, dst_pixmap, tmp_gc, 
                 0, 0, TwmWidthOfDrawable(src_pixmap), 
                 TwmHeightOfDrawable(src_pixmap), 
                 (MUI_APP_WIDTH - TwmWidthOfDrawable(src_pixmap))/2, 
                 (MUI_APP_BASE_HEIGHT-TwmHeightOfDrawable(src_pixmap))/2))
    {
        XFreePixmap(XtDisplay(widget), dst_pixmap);
        XFreeGC(XtDisplay(widget), tmp_gc);
        return NULL;
    }
    /*free GC structure*/
    XFreeGC(XtDisplay(widget), tmp_gc);
    /*prepare wallpaer is ok, return pixmap*/
    return dst_pixmap;
}

/*******************************************************************************
*
* FUNCTION: UpdateWallpaper
*
* $UniqueID:3CC7D70700AF$
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
/*$Function$*/
static void UpdateWallpaper( TI_MUI_IDLE_INTERFACE* This )
{
    TS_IMAGE_ID Image = IMG_DSP_WALLPAPER_THREE;
    /* How to handle the wallpaper style? */
    TS_GEN_WALLPAPER_STYLE Style = WLP_IMAGE;
    XSetWindowAttributes attr;
    TI_ANIMATION         Anim;
    int depth;
    GC gc;
    TS_TIME_DATE TimeDate;
    int mx,my;
    int hx,hy;
    Display * display;
    _ELIB_IMG_TAGETLOC_GETINFO    WallpaperInfo;
    char* FileName[7]= { WALLPAPER_IMAGE,    WALLPAPER_IMAGE2,
                            WALLPAPER_IMAGE3,   WALLPAPER_IMAGE4,
                            WALLPAPER_IMAGE5,   WALLPAPER_IMAGE6,
                            WALLPAPER_IMAGE7 };

    TS_PROFILE_DATA Profile;
    char  WallpaperCPMValue;
    TS_CMD_STATUS Status = CMST_FAILED_NOT_RECOGNISED;
    Pixmap TempDataPixmap = NULL;
  
    if(This->Private->m_WallpaperLabel != NULL)
    {
        display = XtDisplay(This->Private->m_WallpaperLabel);
	}

    if(This->Private->m_Wallpaper != NULL)
    {
        XFreePixmap( XtDisplay(MuiAppGetRootWidget(This)), This->Private->m_Wallpaper);
        This->Private->m_Wallpaper = NULL;
    }

    switch(Style)
    {
        case WLP_NONE:
            attr.background_pixmap = NULL;
            XChangeWindowAttributes(XtDisplay(This->Private->m_WallpaperLabel),XtWindow(This->Private->m_WallpaperLabel),CWBackPixmap, &attr);
            break;
        case WLP_IMAGE:
            depth = PlanesOfScreen(XtScreen(This->Private->m_WallpaperLabel));
            //cosmobic comment because info from elib function can't get the related pixmap.
		    Profile.Id = SYSPRF_SYSGDISP_BUILDIN_WALLPAPER;        
		    Profile.Data = &WallpaperCPMValue;
		    Profile.Size = sizeof( 1 );
		    Profile.Entry = 0;
		    MsApiSysCfgQueryProfile( &This->Private->m_Session.Session, &Profile );
		    if(WallpaperCPMValue == 0)
		    {
		        WallpaperInfo.TagetLoc = ELIB_IMG_TAGETLOC_WAITDSP;
		        Elib_IMG_TagetLoc_GetInfo( APM_APP_CONFIG_ID,&WallpaperInfo );
		        if(WallpaperInfo.ImgNo != 0)
		        {
					TempDataPixmap = MuiAppCreatePixmapFromFileID(APM_APP_IDLE_ID,
									XtDisplay(This->Private->m_WallpaperLabel),
									RootWindowOfScreen(XtScreen(This->Private->m_WallpaperLabel)),
									WallpaperInfo.ImgNo, (unsigned short)WallpaperInfo.Kind, 
									/*ProfileItem.MemType*/1, 0, MUI_APP_WIDTH, MUI_APP_BASE_HEIGHT, 0);
				}
		    }

			if( TempDataPixmap == NULL ) //use default image as wallpaper
			{
                WallpaperCPMValue = (WallpaperCPMValue == 0) ? 1 : WallpaperCPMValue;

				TempDataPixmap = MuiAppCreatePixmapFromFile(APM_APP_IDLE_ID,
								XtDisplay(This->Private->m_WallpaperLabel),
								RootWindowOfScreen(XtScreen(This->Private->m_WallpaperLabel)),
								FileName[WallpaperCPMValue-1], 0, MUI_APP_WIDTH, MUI_APP_BASE_HEIGHT, 0);

				if(TempDataPixmap == NULL)
				{
                    /* Create wallpaper from first image of animator */
					LibImgGetAnimation( &Anim, Image);
					/*  CAUSION from Cosmobic Dana Liu: stupid LibImgGetSize(...) function returns swapped bitmap
					 *  width and height. It is said that actually Anim.Width is bitmap height, and Anim.Height is
					 *  bitmap width. Take care of it. Maybe we need to repair this issue later.
					 *  Oh, my god...
					 */
#ifdef ATOMBUILD    /* Cosmobic Dana Liu COS_ATOM_0040 */
                    /*  For ATOM, the screen height is changed from 200(ultimo) to 180, but till now the size of build-in
                     *  image is still 200. So temporary solution is cut redundant bitmap here.
                     */
                    TempDataPixmap = XCreatePixmapFrom12BitData (XtDisplay(This->Private->m_WallpaperLabel),
                        RootWindowOfScreen(XtScreen(This->Private->m_WallpaperLabel)),
                        LibImgGetBitMap( Anim.Frames[0].BitmapId ),
                        Anim.Height, (Anim.Width > MUI_APP_BASE_HEIGHT ? MUI_APP_BASE_HEIGHT : Anim.Width), depth );
#else               /* Cosmobic Dana Liu COS_ATOM_0040 */
                    TempDataPixmap = XCreatePixmapFrom12BitData (XtDisplay(This->Private->m_WallpaperLabel),
                        RootWindowOfScreen(XtScreen(This->Private->m_WallpaperLabel)),
                        LibImgGetBitMap( Anim.Frames[0].BitmapId ),
                        Anim.Height, Anim.Width, depth );
#endif              /* Cosmobic Dana Liu COS_ATOM_0040 */
				}
			}

            if((TwmWidthOfDrawable(TempDataPixmap) == MUI_APP_WIDTH) && 
               (TwmHeightOfDrawable(TempDataPixmap) == MUI_APP_BASE_HEIGHT))
            {
                This->Private->m_Wallpaper = TempDataPixmap;
            }
            else
            {
                This->Private->m_Wallpaper = PrepareWallpaper(This->Private->m_WallpaperLabel, TempDataPixmap);
                if( This->Private->m_Wallpaper != NULL )
                {
                    XFreePixmap(XtDisplay(This->Private->m_WallpaperLabel), TempDataPixmap);
                }
                else
                {
                    This->Private->m_Wallpaper = TempDataPixmap;
                }
            }
            
            os_assert(This->Private->m_Wallpaper != NULL, ("create pixmap failure during update wallpaper!"));
            
			/* Rewrite the bitmap data to get the semi-transparent effect */
			{
				Pixmap org = This->Private->m_Wallpaper;
                /* Make help line of wallpaper to semi-transparent color if dimension is enough. */
				if (TwmHeightOfDrawable(org) >= MUI_APP_BASE_HEIGHT)
				{
                    unsigned short *pPixel_org;
                    INT32 nBitmapWidth;
                    INT32 nTimeStart;
                    INT32 nTimeEnd;
                    UINT16 R, G, B;
                    INT32 i, j;

                    /* calc time zone area in bitmap coordition */
                    nBitmapWidth = TwmWidthOfDrawable(org);
                    nTimeStart   = 50 - (MUI_APP_WIDTH - nBitmapWidth) / 2;
                    nTimeEnd     = nBitmapWidth - nTimeStart;

                    /*  Rewrite the helpline area on the wallpaper. Here we semi-transparent 20 pixels
                     *  no matter current is ATOM or Ultimo, because in ATOM Idle help line is an exception.
                     */
					for (j = MUI_APP_BASE_HEIGHT-20; j < MUI_APP_BASE_HEIGHT; j++)
					{
						for (i = 0; i < nBitmapWidth; i++)
						{
							pPixel_org = PIXMAP_GET_POINT_ADDR(org, i, j);

							R = G = B = *pPixel_org;

							R = R & RED_MASK;
							G = G & GREEN_MASK;
							B = B & BLUE_MASK;

                            /* it is the time zone and now in inactive mode */
							if ( i >= nTimeStart && i < nTimeEnd && This->Private->m_CurrentSelectedItem < 0 )
							{
                                /* double darken the date zone */
								R = (R >> 2) & RED_MASK;
								G = (G >> 2) & GREEN_MASK;
								B = (B >> 2) & BLUE_MASK;
							}
							else
							{
                                /* darken the helpline */
								R = (R >> 1) & RED_MASK;
								G = (G >> 1) & GREEN_MASK;
								B = (B >> 1) & BLUE_MASK;
							}

							*pPixel_org = R | G | B;
						}
					}
				}
			}

            attr.background_pixmap = This->Private->m_Wallpaper;
            attr.background_style  = CWBackStylePixmapCenter;
            XChangeWindowAttributes(XtDisplay(This->Private->m_WallpaperLabel),
                                    XtWindow(This->Private->m_WallpaperLabel),
                                    CWBackPixmap | CWBackStyle, &attr);
            break;
        case WLP_CLOCK:
            depth = PlanesOfScreen(XtScreen(This->Private->m_WallpaperLabel));
            LibImgGetAnimation( &Anim, Image);
            /*cosmobic fix ULT-CR1-02380*/
            This->Private->m_Wallpaper = XCreatePixmapRom (XtDisplay(This->Private->m_WallpaperLabel),
                                                                     RootWindowOfScreen(XtScreen(This->Private->m_WallpaperLabel)),
                                                                     LibImgGetBitMap( Anim.Frames[0].BitmapId  ),
                                                                     Anim.Height, Anim.Width, depth );
            /* draw the hands on the clock */
            MsApiGetCurrentTimeAndDate(&TimeDate);
            CalculateClockPoints( &mx, &my, TimeDate.minutes, CLK_MINUTE_HAND_LENGTH );
            CalculateClockPoints( &hx, &hy, ((TimeDate.hours % 12)*5)+(TimeDate.minutes/12), CLK_HOUR_HAND_LENGTH );
            gc = XCreateGC(display, This->Private->m_Wallpaper, 0, NULL);
            XDrawLine(display, This->Private->m_Wallpaper, gc,
                      CLOCK_CENTER_X,CLOCK_CENTER_Y,CLOCK_CENTER_X+mx,CLOCK_CENTER_Y+my);
            XDrawLine(display, This->Private->m_Wallpaper, gc,
                      (CLOCK_CENTER_X+1),(CLOCK_CENTER_Y+1),(CLOCK_CENTER_X+1+mx),(CLOCK_CENTER_Y+1+my));
            XDrawLine(display, This->Private->m_Wallpaper, gc,
                      (CLOCK_CENTER_X+1),CLOCK_CENTER_Y,(CLOCK_CENTER_X+1+mx),CLOCK_CENTER_Y+my);
            XDrawLine(display, This->Private->m_Wallpaper, gc,
                      CLOCK_CENTER_X,(CLOCK_CENTER_Y+1),CLOCK_CENTER_X+mx,(CLOCK_CENTER_Y+1+my));
            XDrawLine(display, This->Private->m_Wallpaper, gc,
                      CLOCK_CENTER_X,CLOCK_CENTER_Y,CLOCK_CENTER_X+hx,CLOCK_CENTER_Y+hy);
            XDrawLine(display, This->Private->m_Wallpaper, gc,
                      (CLOCK_CENTER_X+1),(CLOCK_CENTER_Y+1),(CLOCK_CENTER_X+1+hx),(CLOCK_CENTER_Y+1+hy));
            XDrawLine(display, This->Private->m_Wallpaper, gc,
                      (CLOCK_CENTER_X+1),CLOCK_CENTER_Y,(CLOCK_CENTER_X+1+hx),CLOCK_CENTER_Y+hy);
            XDrawLine(display, This->Private->m_Wallpaper, gc,
                      CLOCK_CENTER_X,(CLOCK_CENTER_Y+1),CLOCK_CENTER_X+hx,(CLOCK_CENTER_Y+1+hy));
            XFreeGC(display,gc);
            attr.background_pixmap = This->Private->m_Wallpaper;
            attr.background_style  = CWBackStylePixmapTile;
            XChangeWindowAttributes(display, XtWindow(This->Private->m_WallpaperLabel),
                                    CWBackPixmap | CWBackStyle, &attr);
            break;
        default:
            os_assert(FALSE,("Unknown wallpaper style"));
            break;
    }

    /* Force a wallpaper redraw by unmapping and mapping the main BBoard widget of the dialog */
    XtUnmapWidget( This->Private->m_WallpaperLabel );
    XtMapWidget( This->Private->m_WallpaperLabel );
}

/*******************************************************************************
*
* FUNCTION: DestroyCalendar
*
* $UniqueID:3E80935E00E8$
*
* $Description$
* Function to ensure that all dynamically created widgets used in the creation of the
* calendar are destroyed when the Dialog is unloaded.
* $End$
*******************************************************************************/
/*$Function$*/
static void DestroyCalendar( TI_MUI_IDLE_INTERFACE* This )
{
    UINT8 row, column;

    for (column = 0; column < TL_CALENDAR_COLS; column++)
    {
        for (row = 0; row < TL_CALENDAR_ROWS; row++)
        {
            if (This->Private->m_CalendarDayLabel[row] != NULL)
            {
                XtDestroyWidget(This->Private->m_CalendarDayLabel[row]);
                This->Private->m_CalendarDayLabel[row] = NULL;
            }
        }
    }
	if(This->Private->m_TodayLabel)
	{
		XtDestroyWidget(This->Private->m_TodayLabel);
		This->Private->m_TodayLabel = NULL;
	}
    This->Private->m_CalendarDisplayed = FALSE;
}

/*******************************************************************************
*
* FUNCTION: CreateCalendar
*
* $UniqueID:3E88496C02CE$
*
* $Parm:TS_TIME_DATE* TimeDate$
* <Please enter description here>
* $End$
*
* $Description$
* Function for constructing the Calendar in Idle.
* $End$
*******************************************************************************/
/*$Function$*/
static void CreateCalendar( TI_MUI_IDLE_INTERFACE* This, TS_TIME_DATE* TimeDate )
{
    UINT8 startWeekDay;
    UINT8 row, column;
    TS_DAY currDay;
    TS_DATE aux;
    UINT8 MaxDays = 31;
    Widget Header;
    int i, n = 0;
    Arg args[16];
	char CalendarBuffer[82];
	int length = 0;
   
    /* Modify the font of week day header to small */
    n = 0;
    XtSetArg(args[n], XmNfontList, **(XmFontList**)MUI_REDUCED_FONT ); n++;

    for (i = 0; i < 9; i++)
    {
        Header = MuiAppGetDlgItem (This->Private->m_Dlg, WIG_CAL_HEADER+i);        
        XtSetValues (Header, args, n);
    }        
	
	/* If current time is changed, recalculate the day array */
	if (This->Private->m_CalendarDate.Year != TimeDate->year ||
        This->Private->m_CalendarDate.Month != TimeDate->month)
    {
		/* Reset m_DaysArray */
		for( row = 0; row < 6; row++)
		{
			for( column = 0; column < 7; column++ )
			{
				This->Private->m_DaysArray[row][column] = 0;
			}
		}

		/* Calculate the maximum number of days in the current month */
		if( TimeDate->month == FEBRUARY )
		{
			MaxDays = 28;

			if(( TimeDate->year%4 == 0 ) && ( TimeDate->year%100 != 0 || TimeDate->year%400 == 0 ))
			{
				MaxDays = 29;
			}
		}
		else if( TimeDate->month == APRIL || TimeDate->month == JUNE || TimeDate->month == SEPTEMBER || TimeDate->month == NOVEMBER )
		{
			MaxDays = 30;
		}

		/* Calculate the day of the week for the first day of the month */
		aux.Year = TimeDate->year;
		aux.Month = TimeDate->month;
		aux.Day = 1;

		startWeekDay = ( CountDays( aux ) - 621049 )%7; /* 0 = Sunday */

		if( startWeekDay == 0 )
		{
			column = 6;
		}
		else
		{
			column = startWeekDay - 1;
		}
		
		/* populate the Days array */
		currDay = 1;
		for( row = 0; row < 6; row++ )
		{
			for( column; column < 7; column++ )
			{
				if( currDay > MaxDays )
				{
					break;
				}
				This->Private->m_DaysArray[row][column] = currDay;
				currDay++;
			}
			column = 0;
		}
		/* if the row is 6, reduce the row height */
		if(This->Private->m_DaysArray[5][0])
		{
			This->Private->m_RowHeight = 10;
		}
		else
		{
			This->Private->m_RowHeight = 12;
		}
	}

    n = 0;
    /* Write the days information to the widgets */
    for (row = 0; row < TL_CALENDAR_ROWS; row++)
    {
        /* if row 6 is null */
		if(row == 5 && This->Private->m_DaysArray[row][0] == 0)
        {
        	break;
        }
        length = 0;
		for(column = 0; column < 7; column++)
		{
			if(This->Private->m_DaysArray[row][column] == 0)
			{
				if(row == 0)
				{
					/* fill with 12 space, 2 pixels each space */
					memset(CalendarBuffer+length, 32, 12);
					length = length+12;
				}
				else
				{
					break;
				}
			}
			else if(This->Private->m_DaysArray[row][column] > 9)
			{
				/* 7 space and 2 digit, it is 24 pixels */
				sprintf(CalendarBuffer+length, "%8d", This->Private->m_DaysArray[row][column]);
				length = length+8;
			}
			else
			{
				/* 9 space and 1 digit, it is 24 pixels */
				sprintf(CalendarBuffer+length, "%10d", This->Private->m_DaysArray[row][column]);
				length = length+10;
			}
		}

		/*Create day label widget*/
		n = 0;
		XtSetArg(args[n], XmNx,                 3); n++;
		XtSetArg(args[n], XmNy,                 3*CALENDAR_BORDER + CALENDAR_HDR_HEIGHT + CALENDAR_ROW_HEIGHT + row * This->Private->m_RowHeight + CALENDAR_SPR_HEIGHT ); n++;
		XtSetArg(args[n], XmNwidth,             170 ); n++;
		XtSetArg(args[n], XmNheight,            This->Private->m_RowHeight ); n++;
		XtSetArg(args[n], XmNmarginWidth,       0 ); n++;
		XtSetArg(args[n], XmNmarginHeight,      0 ); n++;
		XtSetArg(args[n], XmNalignment,         XmALIGNMENT_BEGINNING ); n++;
		XtSetArg(args[n], XmNalignmentVertical, XmALIGNMENT_MIDDLE ); n++;
		XtSetArg(args[n], XmNtransparent,		TRUE ); n++;
		XtSetArg(args[n], XmNfontList,          **(XmFontList**)MUI_REDUCED_FONT ); n++;
		/* if the label is not exist */
		if(This->Private->m_CalendarDayLabel[row] == NULL)
		{
			This->Private->m_CalendarDayLabel[row] = XtCreateManagedWidget(NULL, xmLabelWidgetClass, MuiAppGetDlgItem( This->Private->m_Dlg, WIG_CAL_BBOARD ), args, n);
		}
		else
		{
		    XtUnmapWidget( This->Private->m_CalendarDayLabel[row] );
		    XtMapWidget( This->Private->m_CalendarDayLabel[row] );
		}
		MuiAppSetText(This->Private->m_CalendarDayLabel[row], CalendarBuffer+2);
    }
    This->Private->m_CalendarDisplayed = TRUE;
}

/*******************************************************************************
*
* FUNCTION: UpdateCalendar
*
* $UniqueID:3E7B4D5F026E$
*
* $Parm:TS_TIME_DATE* TimeDate$
* <Please enter description here>
* $End$
*
* $Description$
* Called when creating or updating the Calendar, this function will decide if the
* calendar needs to be created, recreated or updated depending on the current Calendar
* state and the current date.
* $End$
*******************************************************************************/
/*$Function$*/
static void UpdateCalendar( TI_MUI_IDLE_INTERFACE* This )
{
    UINT8 row, column;
    Widget CalendarBBoard;
	Widget Header;
    TS_TIME_DATE TimeDate;
    char Buffer[20];
	char MonthStr[15];
	
	memset( &TimeDate, 0, sizeof(TS_TIME_DATE) );
	MsApiGetCurrentTimeAndDate(&TimeDate);

    if ( This->Private->m_IdleScreenType == IDLE_TYPE_CALENDAR )
    {
        CalendarBBoard = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_CAL_BBOARD );
        if( CalendarBBoard == NULL )
        {
			return;
        }

       	/* Now SI Pane is showing, just hide the calendar */
		if(This->Private->m_SIPaneShowed)
		{
			This->Private->m_CalendarHide = TRUE;
			This->Private->m_IdleScreenType = IDLE_TYPE_NORMAL;
			XtUnmapWidget(CalendarBBoard);
			return;
		}

		XtManageChild( CalendarBBoard );

        /* First check to see if the Calendar is shown but the month or year has changed.
           This will require a complete redraw (destroy the current calendar) */

        if ((This->Private->m_CalendarDisplayed == TRUE) &&
            ((This->Private->m_CalendarDate.Month != TimeDate.month) ||
             (This->Private->m_CalendarDate.Year != TimeDate.year)))
        {
            DestroyCalendar(This);
        }

        if (This->Private->m_CalendarDisplayed != TRUE) /* Complete Calendar creation */
        {
            CreateCalendar(This, &TimeDate);
            for (column = 0; column < TL_CALENDAR_COLS; column++)
            {
                for (row = 0; row < TL_CALENDAR_ROWS; row++)
                {
					if (This->Private->m_DaysArray[row][column] == TimeDate.day )
					{
						CreateTodayLabel(This, row, column);
						break;
					}
                }
            }
        }
        else if (This->Private->m_CalendarDate.Day != TimeDate.day) /* Day change only */
        {
            for (column = 0; column < TL_CALENDAR_COLS; column++)
            {
                for (row = 0; row < TL_CALENDAR_ROWS; row++)
                {
					if (This->Private->m_DaysArray[row][column] == TimeDate.day )
					{
						CreateTodayLabel(This, row, column);
						break;
					}
                }
            }
        }

        This->Private->m_CalendarDate.Year = TimeDate.year;
        This->Private->m_CalendarDate.Month = TimeDate.month;
        This->Private->m_CalendarDate.Day = TimeDate.day;
	    
	    /* show the calendar header July 2003 */
	    Header = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_CAL_HEADER );
	    if(MsApiLngQueryCurrent(&This->Private->m_Session.Session) == LNG_CHINESE_SIMPLIFIED)
	    {
	    	sprintf(Buffer, "%d %02d", TimeDate.year, TimeDate.month);
	    }
	    else
	    {
		    MsApiLngQueryGetCharString( NULL, MonthStr, 15, MonthNames[(TimeDate.month) - 1], LNG_AUTO);
		    sprintf(Buffer, "%s %d", MonthStr, TimeDate.year);
		}
	    MuiAppSetText(Header, Buffer);
    }
    else
    {
        CalendarBBoard = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_CAL_BBOARD );
        if( CalendarBBoard != NULL )
        {
        	XtUnmanageChild(CalendarBBoard);
			DestroyCalendar(This);
        }
    }

    UpdateSATPane (This);
}

/*******************************************************************************
*
* FUNCTION: PerformSoftKeyAction
*
* $UniqueID:3CC7D7070132$
*
* $Parm:TL_IDLE_SK_ACTION Action$
* <please add parmeter description here >
* $End$
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
/*$Function$*/
static void PerformSoftKeyAction( TI_MUI_IDLE_INTERFACE* This, TL_IDLE_SK_ACTION Action )
{
	switch(Action)
    {
	case ACT_NONE:
		break;
	case ACT_MSG_VIEW:
		if( MuiConflictInquire(APM_APP_IDLE_ID, AM_AP_ID_MAIL_MAIN, 0) == CLM_RESULT_PERMIT)
		{
			_AM_CONTROL_REQ req_param;
			
			req_param.src_ap      = MuiAppGetApId(This);
			req_param.param       = NULL;
			req_param.dst_ap	  = AM_AP_ID_MAIL_MAIN;
			req_param.info        = Mailer_Start_Normal;
			req_param.return_mode = AM_RETURN_MODE_WAIT;		
			req_param.watch_time  = AM_WATCH_MODE_MAX_TIME;
			
			wMui_MLTW_Control_StartReq( &req_param );
		}
		break;
	case ACT_MSG_CREATE:
		if( MuiConflictInquire(APM_APP_IDLE_ID, AM_AP_ID_MAIL_MAIN, 0) == CLM_RESULT_PERMIT)
		{
			_AM_CONTROL_REQ req_param;
			MailToInfo *pMailToInf = NULL;
			pMailToInf = (MailToInfo *)MM_malloc( sizeof(MailToInfo) );
			
			if( NULL == pMailToInf )
			{
				return;
			}
			memset( pMailToInf, 0x00, sizeof(MailToInfo) );
			pMailToInf->sFunctionNo = (SHORT)EML_NEWMAIL_DESKTOP;
			memset( &req_param, 0x00, sizeof(_AM_CONTROL_REQ) );

			req_param.src_ap      = MuiAppGetApId(This);
			req_param.param       = pMailToInf;
			req_param.dst_ap	  = AM_AP_ID_MAIL_MAIN;
			req_param.info        = Mailer_New_Mail_Text;
			req_param.return_mode = AM_RETURN_MODE_WAIT;		
			req_param.watch_time  = AM_WATCH_MODE_MAX_TIME;
			
			wMui_MLTW_Control_StartReq( &req_param );
		}
		break;
	case ACT_CAMERA:
		if( MuiConflictInquire(APM_APP_IDLE_ID, AM_AP_ID_CAPTURE_MAIN, MUI_CAM_VIDEO_START) == CLM_RESULT_PERMIT)
		{
			_AM_CONTROL_REQ req_param;
				
			req_param.src_ap      = MuiAppGetApId(This);
			req_param.info        = 0;
			req_param.param       = NULL;
			req_param.return_mode = AM_RETURN_MODE_NOWAIT_ACT;
			req_param.watch_time  = 0;
			
			req_param.dst_ap	  = AM_AP_ID_CAPTURE_MAIN;
			req_param.info        = MUI_CAM_VIDEO_START;
			req_param.return_mode = AM_RETURN_MODE_NOWAIT;		
			
			wMui_MLTW_Control_StartReq( &req_param );
		}
		break;
	case ACT_SOS:
		FsmIfAddEvent(This, e_StartDialLockEmergency);
		break;
	case ACT_UNLOCK:
		FsmIfAddEvent(This, e_GotoUnlockDial);
		break;
	case ACT_VIDEOCALL:
		LaunchVideoCall(This);
		break;
	case ACT_STORE:
	    if(utflen(&This->Private->m_IdleString.utf) > 0)
		{
			FsmIfAddEvent(This, e_PbkCreate);
		}
		break;
	default:
		break;
    }	
}

/*******************************************************************************
*
* FUNCTION: UpdateServiceScreen
*
* $UniqueID:3E848064030E$
*
* $Description$
* Update the service screen. This function is called whenever the Idle option menu is
* exited or whenever notification is received to indicate that something on the screen
* has been updated (eg. indication that the wallpaper has changed).
* $End$
*******************************************************************************/
/*$Function$*/
static void UpdateServiceScreen( TI_MUI_IDLE_INTERFACE* This )
{
    int                  ModeSetting;
			
    if (This->Private->m_Dlg != NULL)
    {	
        UpdateWallpaper(This);

        UpdatePlmnInfo( This, &This->Private->m_CsInfo);

        UpdateTimeDate(This );

        UpdateCalendar(This);
	    UpdateSIPane (This);

        UpdateSATPane (This);

        ModeSetting = Elib_WDC_Get_PhoneMode (MuiAppGetApId(This));
        UpdateModeFunctionSetting( This, ModeSetting );

        UpdateBacklightSetting(This);

        UpdateKeypadLockIcon( This );

		UpdateShortcuts (This);
		
        UpdateAlsSetting( This );
    }
}

/*******************************************************************************
*
* FUNCTION: UpdateSATPane
*
* $UniqueID:$
*
* $Description$
* Update the SAT message display.
* $End$
*******************************************************************************/
/*$Function$*/
static void UpdateSATPane( TI_MUI_IDLE_INTERFACE* This )
{
    if ((This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL) &&
        (This->Private->m_SATPane != NULL) &&
        (!This->Private->m_SIPaneShowed) &&
        (utflen(&This->Private->m_SATText.utf) > 0))
    {
        if (This->Private->m_SATPane != NULL)
        {
        	XtMapWidget (This->Private->m_SATPane);
        	MuiAppSetText (This->Private->m_SATPane, This->Private->m_SATText.buf);
        }
    }
    else
    {
        if (This->Private->m_SATPane != NULL)
        {
        	XtUnmapWidget (This->Private->m_SATPane);
        }
    }
}

/*******************************************************************************
*
* FUNCTION: UpdateSIPane
*
* $UniqueID:3E76B22A008C$
*
* $Description$
* Update the SI pane display.
* $End$
*******************************************************************************/
/*$Function$*/
static void UpdateSIPane( TI_MUI_IDLE_INTERFACE* This )
{
    /*  show the SI pane */
	/* with the newest messsage if it exists */
	int ret;
	_ELIB_SIP_DATA data;
    
    /* Get the newest SI message from Elib   */
    ret = Elib_SIP_Listdata_Get (MuiAppGetApId (This), 0, &data);
    
    if (ret >= ELIB_SIP_DATA_MIN)
    {
        /* There are SI data */
        ret = Elib_SIP_Listdata_Get (MuiAppGetApId (This), ELIB_SIP_DATA_MIN, &data);

        if (ret >= ELIB_SIP_DATA_MIN)
        {
            This->Private->m_SIMsgListNo = ELIB_SIP_DATA_MIN;
            strcpy (This->Private->m_SIMsg, data.Text);
			if(!This->Private->m_SIPaneShowed)
			{
	            This->Private->m_SIPaneShowed = TRUE;
				/* Hide the calendar when SI Pane is showing */
				if (This->Private->m_IdleScreenType == IDLE_TYPE_CALENDAR)
				{
					/* If now calendar is not selected, return to normal screen */
					if(This->Private->m_CurrentSelectedItem != 0)
					{
						This->Private->m_CalendarHide = TRUE;
						This->Private->m_IdleScreenType = IDLE_TYPE_NORMAL;
						UpdateCalendar(This);
						UpdateShortcuts(This);
					}
				}
				else if(This->Private->m_CurrentSelectedItem != -1)
				{
					if(This->Private->m_ShortcutMoving)
					{
						This->Private->m_ItemToMove++;
					}
					This->Private->m_CurrentSelectedItem++;
				}
			}
        }
        else
        {
            os_assert (FALSE, ("out of Elib SIP service"));
        }
    }
    else if(This->Private->m_SIPaneShowed)
    {
        /* Hide the SI pane, No message Left */
        strcpy (This->Private->m_SIMsg, "");
        This->Private->m_SIMsgListNo = 0;
        
        /* if now it's in SI active state, we should go back one more */
        if (This->Private->m_CurrentSelectedItem == 0)
        {
            /* unselect si pane first */
            SetSelectedShortcut(This, -1);
            
            /* SI Pane disappear, select the first shortcut, 
             * If no shortcut now, change to normal screen
             */
            if(!SetSelectedShortcut(This, 1))
            {
                FsmIfAddEvent(This, E_DONE);
            }
            else
            {
                /* SI Pane disappear, change index */
                This->Private->m_CurrentSelectedItem--;
            }
        }
        else if(This->Private->m_CurrentSelectedItem >= 1)
        {
        	This->Private->m_CurrentSelectedItem--;
			if(This->Private->m_ShortcutMoving)
			{
				This->Private->m_ItemToMove--;
			}
        }
        
        This->Private->m_SIPaneShowed = FALSE;
		
		/* Calendar is hide for SI Pane, Now show calendar again */
		if(This->Private->m_CalendarHide)
		{
			This->Private->m_CalendarHide = FALSE;
			This->Private->m_IdleScreenType = IDLE_TYPE_CALENDAR;
			UpdateCalendar(This);
			UpdateShortcuts(This);
		}
    }

    if (This->Private->m_SIPaneShowed)
	{
		if (This->Private->m_SIPane != NULL)
		{
			XtMapWidget (This->Private->m_SIPane);
			DisplayMsgOnSIPane (This, This->Private->m_SIMsg, This->Private->m_SIMsgListNo);
		}
	}
	else
	{
		if (This->Private->m_SIPane != NULL)
		{
			XtUnmapWidget (This->Private->m_SIPane);
		}
	}

    /* Remove the selecting rectangle if it exist */
    if (g_SIPaneActive ((TI_GENERIC*)This, FALSE))
    {
        if (This->Private->m_SIPaneBG != NULL)
	    {
		    XtUnmapWidget (This->Private->m_SIPaneBG);
	    }
    }

    UpdateSATPane (This);
}

/*******************************************************************************
*
* MACRO: a_Entry
*
* $UniqueID:3CC7D702024D$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_Entry )
{
    if(Qual)
    {
        FsmIfAddEvent(This, e_Start);
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadService
*
* $UniqueID:3CC7D7020293$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadService )
{
	Widget CalendarBBoard;
    if(Qual)
    {
        /* check to see if there are still digits in the string */
        if(utflen(&This->Private->m_IdleString.utf))
        {
            XmTextEditSetString(This->Private->m_TextLabel, This->Private->m_IdleString.buf);
            XtVaSetValues( This->Private->m_TextLabel, XmNcursorPosition, utflen(&This->Private->m_IdleString.utf), NULL);
            FsmIfAddEvent(This, e_DigitsPresent);
        }
        else
        {
            /* This dialog has option menu */
            MuiAppIfOptionMenuShow( This, TRUE );

		    This->Private->m_IdleStatus = IDLE_NORMAL_STATUS;
		    if ( This->Private->m_IdleScreenType == IDLE_TYPE_CALENDAR )
		    {
        		CalendarBBoard = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_CAL_BBOARD );
		       	XtMapWidget( CalendarBBoard );
		    }

			UpdateSIPane(This);
			XtMapWidget(This->Private->m_ShortcutTree);
			
			XmTextEditSetString(This->Private->m_TextLabel, "");

			/* Idle need to check the dial lock enable or
			 * disable here, because Idle may just come
			 * back from call state and user set the dial
			 * lock during the call
			 */
			 
            if(This->Private->m_bDialLockEnable == TRUE )
            {				
				wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKSTOP );
				UpdateKeypadLockIcon( This );
				
            	MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[DIAL_LOCK_1].SkText, MUI_DLG_TEXT_LEFT );
            	MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[DIAL_LOCK_2].SkText, MUI_DLG_TEXT_RIGHT );
            }

#ifdef CSW_SUPPORTKEYLOCK
            else if( This->Private->m_bKeyLockStatus )
            {
           		MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[KEYPAD_LOCK_1].SkText, MUI_DLG_TEXT_LEFT );
           		MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[KEYPAD_LOCK_2].SkText, MUI_DLG_TEXT_RIGHT );
           	}
#endif
            else
            {
				UpdateKeypadLockIcon( This );
				
            	MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[NORMAL_SCREEN_1].SkText, MUI_DLG_TEXT_LEFT );
            	MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[NORMAL_SCREEN_2].SkText, MUI_DLG_TEXT_RIGHT );
			}
		}
    }
    else
    {
		if ( This->Private->m_IdleScreenType == IDLE_TYPE_CALENDAR )
		{
        	CalendarBBoard = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_CAL_BBOARD );
		    XtUnmapWidget( CalendarBBoard );
		}
    	XtUnmapWidget(This->Private->m_SIPane);
        XtUnmapWidget(This->Private->m_SIPaneBG);
    	XtUnmapWidget(This->Private->m_ShortcutTree);
		XtUnmapWidget( MuiAppGetDlgItem( This->Private->m_Dlg, WIG_SET_VOLUME_BOARD ) );
        XtUnmapWidget(This->Private->m_SATPane);
		This->Private->m_VolumeShowed = FALSE;
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadIdleScreen
*
* $UniqueID:3CC7D7020293$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadIdleScreen )
{
    if(Qual)
    {
		XSetWindowAttributes attr;

		MsApiNwrkQueryCsRegStatus( &This->Private->m_Session.Session, &This->Private->m_CsInfo );

        /* Load service dialog */
        MuiAppLoadDialog( This, &This->Private->m_Dlg, MuiAppGetRootWidget(This), DLG_SERVICE );
            
#ifdef ATOMBUILD    /* Cosmobic Dana Liu COS_ATOM_0037 */
		This->Private->m_WallpaperLabel = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_SERVICE_WALLPAPER );
#else   /* Cosmobic Dana Liu COS_ATOM_0037 */
		This->Private->m_WallpaperLabel = MuiAppGetDlgItem( This->Private->m_Dlg, THIS_DIALOG );
#endif  /* Cosmobic Dana Liu COS_ATOM_0037 */

		This->Private->m_PlmnLabel         = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_PLMN );
		This->Private->m_ParallelPlmnLabel = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_PARALLEL_PLMN );
		This->Private->m_TADLabel          = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_TIME_DATE );
		This->Private->m_BltStateLabel     = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_BLT_IND );
		This->Private->m_MfnLabel          = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_MFN_IND );
		This->Private->m_CfdLabel          = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_CFD_IND );
		This->Private->m_KeyLockStateLabel = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_KPL_IND );
		This->Private->m_SIPane            = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_SI_MSG );
        This->Private->m_SIPaneBG          = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_SI_MSG_BG );
        This->Private->m_SATPane           = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_SAT_MSG );
		This->Private->m_ShortcutTree	   = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_TREE_SHORTCUT );
		This->Private->m_SetVolumeLabel	   = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_SET_VOLUME_IMG );
		This->Private->m_VolumeLabel	   = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_VOLUME_SLIDE );
		This->Private->m_TextLabel		   = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_IDLE_STRING );
		This->Private->m_HelpLineLabel	   = MuiAppGetDlgItem(This->Private->m_Dlg, WIG_SI_CAL_HELPLINE);

#ifdef CSW_SUPPORTKEYLOCK
		This->Private->m_KeyLockLabel	   = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_KEY_LOCK_STATUS );
		XtUnmapWidget(This->Private->m_KeyLockLabel);
#endif
		/* Set volume bar wallpaper */
		{
			XSetWindowAttributes Attr;
			TI_ANIMATION Anim;
			UINT depth;
						
			depth = PlanesOfScreen( XtScreen( This->Private->m_SetVolumeLabel ) );
			LibImgGetAnimation( &Anim, IMG_CMN_WIDGET );
			This->Private->m_VolumeWallpaper = XCreatePixmapRom(
												   XtDisplay( This->Private->m_SetVolumeLabel ),
												   RootWindowOfScreen( XtScreen( This->Private->m_SetVolumeLabel ) ),
												   LibImgGetBitMap( Anim.Frames[0].BitmapId  ),
												   Anim.Height, Anim.Width, depth );
			
			Attr.background_pixmap = This->Private->m_VolumeWallpaper;
			Attr.background_style  = CWBackStylePixmapTile;
			XChangeWindowAttributes( XtDisplay( This->Private->m_SetVolumeLabel ),
									XtWindow( This->Private->m_SetVolumeLabel ),
									CWBackPixmap, &Attr);
		}
		/* set the transparent attribute of shortcut tree widget */
		attr.do_not_fill_expose_area = True;
		attr.transparent_window = True;

		XChangeWindowAttributes (XtDisplay(This->Private->m_ShortcutTree),
					XtWindow(This->Private->m_ShortcutTree),
					CWDontFillExposeArea|CWTransparentWindow,
					&attr);

		XChangeWindowAttributes (XtDisplay(This->Private->m_HelpLineLabel),
                    XtWindow(This->Private->m_HelpLineLabel),
                    CWDontFillExposeArea|CWTransparentWindow,
                    &attr);

		XChangeWindowAttributes (XtDisplay(This->Private->m_TADLabel),
                    XtWindow(This->Private->m_TADLabel),
                    CWDontFillExposeArea|CWTransparentWindow,
                    &attr);

		XChangeWindowAttributes (XtDisplay(This->Private->m_BltStateLabel),
                    XtWindow(This->Private->m_BltStateLabel),
                    CWDontFillExposeArea|CWTransparentWindow,
                    &attr);

		XChangeWindowAttributes (XtDisplay(This->Private->m_MfnLabel),
                    XtWindow(This->Private->m_MfnLabel),
                    CWDontFillExposeArea|CWTransparentWindow,
                    &attr);

		XChangeWindowAttributes (XtDisplay(This->Private->m_CfdLabel),
                    XtWindow(This->Private->m_CfdLabel),
                    CWDontFillExposeArea|CWTransparentWindow,
                    &attr);
		XChangeWindowAttributes (XtDisplay(This->Private->m_KeyLockStateLabel),
                    XtWindow(This->Private->m_KeyLockStateLabel),
                    CWDontFillExposeArea|CWTransparentWindow,
                    &attr);
			
		UpdateServiceScreen(This);

		/* Disable shortcut tree selecting rectangle */
		SetSelectedShortcut(This, -1);

		/* Hide the volume label */
		XtUnmapWidget( MuiAppGetDlgItem( This->Private->m_Dlg, WIG_SET_VOLUME_BOARD ) );
		This->Private->m_VolumeShowed = FALSE;

		{
			Arg args[1];
						
			/* Modify the font of week day header to small */
			XtSetArg(args[0], XmNfontList, **(XmFontList**)MUI_REDUCED_FONT );
			XtSetValues (This->Private->m_SIPane, args, 1);
			XtSetValues (This->Private->m_TADLabel, args, 1);
            XtSetValues (This->Private->m_SATPane, args, 1);
			XtSetArg(args[0], XmNfontList, **(XmFontList**)MUI_LARGE_FONT );
			XtSetValues (This->Private->m_TextLabel, args, 1);
		}
    }
    else
    {
        if(This->Private->m_Dlg)
        {
            if (This->Private->m_CalendarDisplayed)
            {
                DestroyCalendar(This);
            }
	        
	        if ( This->Private->m_VolumeWallpaper != NULL )
	        {
	            /* Free the loaded wallpaper from the Volume bar */
	            XFreePixmap( XtDisplay( This->Private->m_SetVolumeLabel ), This->Private->m_VolumeWallpaper );
	        }

            MuiAppUnloadDialog( &This->Private->m_Dlg );
            This->Private->m_Dlg               = NULL;
            This->Private->m_PlmnLabel         = NULL;
            This->Private->m_ParallelPlmnLabel = NULL;
            This->Private->m_TADLabel          = NULL;
            This->Private->m_BltStateLabel     = NULL;
            This->Private->m_MfnLabel          = NULL;
            This->Private->m_CfdLabel          = NULL;
            This->Private->m_WallpaperLabel    = NULL;
            This->Private->m_KeyLockStateLabel = NULL;
			This->Private->m_SIPane			   = NULL;
            This->Private->m_SIPaneBG		   = NULL;            
            This->Private->m_SATPane           = NULL;
			This->Private->m_ShortcutTree	   = NULL;
			This->Private->m_SetVolumeLabel	   = NULL;
			This->Private->m_TextLabel		   = NULL;
			This->Private->m_HelpLineLabel	   = NULL;
#ifdef CSW_SUPPORTKEYLOCK
            This->Private->m_KeyLockLabel	   = NULL;
#endif
        }
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadIdleMenu
*
* $UniqueID:3CC7D70202E3$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadIdleMenu )
{
    if(Qual)
    {
		if( This->Private->m_MenuDlg == NULL)
		{
			MuiAppLoadDialog( This, &This->Private->m_MenuDlg, MuiAppGetRootWidget(This), DLG_IDLE_MENU );

			/* Back from quick menu or call log, set highlight*/
			MuiAppIfSetHightLight( This->Private->m_MenuDlg, WIG_LIST, This->Private->m_MenuHighLightItem );
			This->Private->m_MenuHighLightItem = 0;
		}
    }
    else
    {
       	if(This->Private->m_MenuDlg != NULL)
		{
			MuiAppUnloadDialog( &This->Private->m_MenuDlg );
       		This->Private->m_MenuDlg = NULL;
		}
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadDialMenu
*
* $UniqueID:3F0147C201A1$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadDialMenu )
{
   if(Qual==LOAD)
   {
        MuiAppLoadDialog( This, &This->Private->m_MenuDlg, MuiAppGetRootWidget(This), DLG_DIAL_MENU );
   }
   else
   {
        MuiAppUnloadDialog( &This->Private->m_MenuDlg );
        This->Private->m_MenuDlg = NULL;
   }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadDigitsScreen
*
* $UniqueID:3CC7D7020397$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadDigitsScreen )
{
    Arg args[1];

    if(Qual)
    {
		XtSetArg(args[0], XmNx, 0 );
		XtSetValues (This->Private->m_TextLabel, args, 1);
		
		This->Private->m_IdleStatus = IDLE_DIAL_STATUS;
		
		if(utflen(&This->Private->m_IdleString.utf) == 0)
		{
			/* dial screen is NULL, Disable Soft key */
			MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[NONE_ACTION].SkText, MUI_DLG_TEXT_LEFT );
			MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[NONE_ACTION].SkText, MUI_DLG_TEXT_RIGHT );
			MuiAppIfOptionMenuShow( This, FALSE );
		}
		else
		{
			MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[DIAL_SCREEN_1].SkText, MUI_DLG_TEXT_LEFT );
			MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[DIAL_SCREEN_2].SkText, MUI_DLG_TEXT_RIGHT );
			MuiAppIfOptionMenuShow( This, TRUE );
		}
		Clm_Conflict_Inquire( APM_APP_IDLE_ID, CLM_RET_INSTANT, CLM_INQ_START_ITEM, CLM_ITEM_INPUT_DIAL, CLM_FIRST_INSTRUCTIONS_ACTION );

		/* In Dial lock status, enter dial screen, menu key should be enabled*/
		if(This->Private->m_bDialLockEnable)
		{
			wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKRESTART );
		}
		
#ifdef CSW_SUPPORTKEYLOCK
		/* In keypad lock status, enter dial screen, menu key should be enabled*/
		if(This->Private->m_bKeyLockStatus)
		{
			wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKRESTART );
		}
#endif
    }
    else
    {
		XtSetArg(args[0], XmNx, MUI_APP_WIDTH );
		XtSetValues (This->Private->m_TextLabel, args, 1);
        Clm_Conflict_Inquire( APM_APP_IDLE_ID, CLM_RET_INSTANT, CLM_INQ_END_ITEM, CLM_ITEM_INPUT_DIAL, CLM_FIRST_RESULT_CONFLICT );

		/* In Dial lock status, enter dial screen, menu key should be disabled */
		if(This->Private->m_bDialLockEnable)
		{
			wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKSTOP );
		}
		
#ifdef CSW_SUPPORTKEYLOCK
		/* In keypad lock status, enter dial screen, menu key should be disabled*/
		if(This->Private->m_bKeyLockStatus)
		{
			wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKSTOP );
		}
#endif

        /* Update the calendar if the time is changed during dial screen */
        if (This->Private->m_IdleScreenType == IDLE_TYPE_CALENDAR)
        {
            UpdateCalendar (This);
        }
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_ShowNextSIMsg
*
* $UniqueID:3E757D2E0113$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the next message in SI pane in SI active mode.
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_ShowNextSIMsg )
{
	_ELIB_SIP_DATA data;
	int ret;
	int MsgListNo = This->Private->m_SIMsgListNo;

	if ((This->Private->m_SIMsgListNo >= ELIB_SIP_DATA_MIN) && (This->Private->m_SIMsgListNo < ELIB_SIP_DATA_MAX))
	{
        /* ULT-PR1-08456, ULT-PR1-8457 SI Pane feature modification in Kamoi */
		MsgListNo++;

        ret = Elib_SIP_Listdata_Get (MuiAppGetApId (This), MsgListNo, &data);
		
		if ((ret >= ELIB_SIP_DATA_MIN) && (ret <= ELIB_SIP_DATA_MAX))
		{
            DisplayMsgOnSIPane (This, data.Text, MsgListNo);
		}
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_KillFocus
*
* $UniqueID:3E757CE50058$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* action taken when leave the SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_KillFocus )
{
	if (This->Private->m_CurrentSelectedItem != -1)
    {
		/* press other keys expect tick and softkey2, cancel the moving */
		if (This->Private->m_ShortcutMoving)
		{
			int count;

			/*Resume the shortcuts*/
			for(count = 0; count < MAX_SHORTCUTS_NUM; count++)
			{
				This->Private->m_DesktopShortcutsPointer[count] = This->Private->m_DesktopShortcutsTempPointer[count];
			}
			
//			UpdateShortcuts(This);
			This->Private->m_ShortcutMoving = FALSE;
//			SetSelectedShortcut (This, This->Private->m_ItemToMove);
		}

        {
            /* when the focus is moving out of calendar, check if there are new SI msgs */
            if ((This->Private->m_IdleScreenType == IDLE_TYPE_CALENDAR) &&
                (This->Private->m_CurrentSelectedItem))
            {
                UpdateSIPane (This);
            }

            /* Change the state variable */
            This->Private->m_ItemToDelete = This->Private->m_CurrentSelectedItem;	
            SetSelectedShortcut (This, -1);	
        }
    }
	/* Update the wallpaper to get the non-active semi-transparent helpline effect */
	UpdateWallpaper (This);
	MuiAppIfOptionMenuShow( This, TRUE );
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_ShowPreviousSIMsg
*
* $UniqueID:3E757D0803B3$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_ShowPreviousSIMsg )
{
    _ELIB_SIP_DATA data;
   int			   ret;
   int MsgListNo = This->Private->m_SIMsgListNo;
	
	if ((This->Private->m_SIMsgListNo > ELIB_SIP_DATA_MIN) && \
		(This->Private->m_SIMsgListNo <= ELIB_SIP_DATA_MAX))
   {
        /* ULT-PR1-08456, ULT-PR1-8457 SI Pane feature modification in Kamoi */
	   MsgListNo--;

       ret = Elib_SIP_Listdata_Get (MuiAppGetApId (This), MsgListNo, &data);
	
	   if ((ret >= ELIB_SIP_DATA_MIN) && (ret <= ELIB_SIP_DATA_MAX))
	   {
		   DisplayMsgOnSIPane (This, data.Text, MsgListNo);
	   }
   }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadPSSClass
*
* $UniqueID:3CC7D703017C$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadPSSClass )
{
    if(Qual==LOAD)
    {
        This->Private->m_PssClass = FsmIfCreateInstance( This, C_MUI_PSS );
        strcpy(This->Private->m_PssClass->Public->m_PSSDialString,This->Private->m_IdleString.buf);
        utfsetlen(&This->Private->m_IdleString.utf,0);
    }
    else
    {
        FsmIfDeleteInstance(This->Private->m_PssClass);
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_RetrieveVoiceCallString
*
* $UniqueID:3CC7D703028A$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_RetrieveVoiceCallString )
{
    utfcpy(&This->Private->m_IdleString.utf, This->Private->m_VoiceCallsClass->Public->m_InCallString.buf);
	This->Private->m_IdleStatus = IDLE_NORMAL_STATUS;

#ifdef CSW_SUPPORTKEYLOCK
	/* CSV incoming, Disable menu key */
	if(This->Private->m_bKeyLockStatus)
	{
		/* If Idle do get focus, disable menu key */
		if(FMui_Mltw_ActiveInfoReq(NULL) == APM_APP_IDLE_ID)
		{
			wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKSTOP );
		}
	}
#endif

	if(This->Private->m_bDialLockEnable)
	{
		/* If Idle do get focus, disable menu key */
		if(FMui_Mltw_ActiveInfoReq(NULL) == APM_APP_IDLE_ID)
		{
			wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKSTOP );
		}
	}
	
	/* Richard Fix ULT-PR1-13471, We should always lower the IDLE histroy
	 * after all CSV end. if any app is active, then the app screen will display.
	 * It will break the histroy, But it's very difficult for us to keep the 
	 * histroy with current architecture. We only can fix the issue temporarily.
	*/
#if 0
	if(This->Private->m_bRaiseIdle)
#endif
	{
		_AM_HISTORY_REQ AmHistoryReq;
	    AmHistoryReq.ap_ID = APM_APP_IDLE_ID;
	    Am_History_LowerReq(&AmHistoryReq);
	    This->Private->m_bRaiseIdle = FALSE;
	}

    /* Idle active */
	{
		TI_EVID_NULL_STRUCT	Event;
		BOOLEAN IdleStatus = TRUE;
		Event.Id	= EVID_IDLE_STATUS_CHANGED;
		Event.Size	= sizeof(BOOLEAN);
		Event.Ptr	= &IdleStatus;
		MsApiEvBroadcastEventInd( NULL, &Event );
	}
	/* start request from csv to IDLE */
	Clm_Conflict_Inquire( APM_APP_IDLE_ID, CLM_RET_INSTANT, CLM_INQ_START_ITEM, CLM_ITEM_DESKTOP, CLM_FIRST_INSTRUCTIONS_ACTION );
	
	if(mltw_CheckExecute(AM_AP_ID_VPH_MAIN) )
	{
		_AM_HISTORY_REQ AmHistoryReq;
	    AmHistoryReq.ap_ID = AM_AP_ID_VPH_MAIN;
	    Am_History_RaiseReq(&AmHistoryReq);
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_CreatePhonebook
*
* $UniqueID:3CC7D70302D0$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_CreatePhonebook )
{
    TS_PHONE_NUMBER           PhoneNumber;
    TS_UTF_PHONENUMBER        TempIdleString;
    TS_DATABASE_RECORD_NUMBER  RecordNumber;

	if(MuiConflictInquire(APM_APP_IDLE_ID, APM_APP_PBOOK_ID, 0)!=CLM_RESULT_PERMIT)
	{
		utfsetlen( &This->Private->m_IdleString.utf, 0 );
		FsmIfAddEvent(This, E_DONE);
		return;
	}

    INIT_UTF(TempIdleString);
    switch(Qual)
    {
        case REQ_PBK_VIEW:
            MuiPbkIfStartDefaultPhonebook( APM_APP_IDLE_ID );
            break;
        case REQ_PBK_SEARCH:
            MuiPbkIfStartSearchingPhonebook( APM_APP_IDLE_ID );
            break;
        case REQ_PBK_CREATE:
            LibPhoneNumFromUtf8( &PhoneNumber, This->Private->m_IdleString.buf );
            MuiPbkIfCreateNumberRecord( &PhoneNumber, APM_APP_IDLE_ID );
            break;
        case REQ_PBK_FAST_VIEW:
            RecordNumber = atoi(This->Private->m_IdleString.buf);
            MuiPbkIfFastView( RecordNumber, APM_APP_IDLE_ID );
            break;
        case REQ_PBK_FAST_DIAL:
			{
				RecordNumber = atoi(This->Private->m_IdleString.buf);
	            if( RecordNumber == 1 )
	            {
	            	TI_EVID_NULL_STRUCT EventData;
			        EventData.Id   = EVID_IDLE_LOAD_VOICE_MAIL;
			        EventData.Ptr  = NULL;
			        EventData.Size = 0;
			        MsApiEvBroadcastEventInd (NULL, &EventData);
			    }
			    else
			    {
	            	MuiPbkIfFastDial( RecordNumber, APM_APP_IDLE_ID );
	            }
			}
            break;
		case REQ_PBK_FAST_VT:
			{
	            RecordNumber = atoi(This->Private->m_IdleString.buf);
				MuiPbkIfFastDial_VT( RecordNumber, APM_APP_IDLE_ID );
			}
			break;
		default:
			break;
    }

	utfsetlen( &This->Private->m_IdleString.utf, 0 );
	FsmIfAddEvent(This, E_DONE);
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_StartVideoCall
*
* $UniqueID:
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_StartVideoCall )
{
    if (Qual)
    {
    	This->Private->m_VideoCallClass = FsmIfCreateInstance (This, C_MUI_VIDEO_CALL);
    	MuiVTInitSetupData (This->Private->m_VideoCallClass, This->Private->m_IdleString.buf, &This->Private->m_Session);
    }
    else
    {
    	if (This->Private->m_VideoCallClass)
    	{
    		FsmIfDeleteInstance (This->Private->m_VideoCallClass);    		
    		This->Private->m_VideoCallClass = NULL;
    	}

		utfsetlen( &This->Private->m_IdleString.utf, 0 );
    }
}
END_PRIVATE_ACTION


/*******************************************************************************
*
* MACRO: a_LoadDialLockVerify
*
* $UniqueID:3CC7D7040079$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadDialLockVerify )
{
    if(Qual)
    {
		MuiAppIfTitleBarSetText( This, TXT_SC_DIAL_LOCK );
		MuiAppIfTitleBarSetIcon( This, IMG_STG_0 );
		MuiAppIfTitleBarShow( This, TRUE );

		This->Private->m_SecurityInterface = FsmIfCreateInstance( This, TI_MUI_SECURITY_INTERFACE );
		if(This->Private->m_bDialLockEnable)
		{
			MuiSecIfDialLock(This->Private->m_SecurityInterface, MUI_DIAL_LOCK, FALSE, TRUE);
		}
		else
		{
			MuiSecIfDialLock(This->Private->m_SecurityInterface, MUI_DIAL_LOCK, TRUE, FALSE);
		}
	}
	else
	{
		FsmIfDeleteInstance(This->Private->m_SecurityInterface);
		MuiAppIfTitleBarShow( This, FALSE );
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadUnlockKeyPad
*
* $UniqueID:3CC7D7040105$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadUnlockKeyPad )
{

    if(Qual==LOAD)
    {
		/* Display key side lock info */
		This->Private->m_DisplayMessage = FsmIfCreateInstance( This, C_MUI_DISPLAY_MESSAGE );
        MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_WAR_2);
        This->Private->m_DisplayMessage->Public->m_TextId = TXT_SVC_MENU_0_UNLOCK_ACK;
    }
    else
    {
	    FsmIfDeleteInstance(This->Private->m_DisplayMessage);
        This->Private->m_DisplayMessage = NULL;
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_FocusThisApplication
*
* $UniqueID:3DB6B95F038F$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_FocusThisApplication )
{
	This->Private->m_IdleStatus = IDLE_CALL_STATUS;
	if(FMui_Mltw_ActiveInfoReq(NULL) != APM_APP_IDLE_ID)
	{
		_AM_HISTORY_REQ AmHistoryReq;
		AmHistoryReq.ap_ID = MuiAppGenericGetApId(GetThis(This));
		Am_History_RaiseReq(&AmHistoryReq);
		This->Private->m_bRaiseIdle = TRUE;
	}

#ifdef CHW_MOBILELIGHT    
    /* if mobile light is on, turn it off */
    if(This->Private->m_bMobileLight)
    {
		Elib_LMP_Mobilelight_Off(APM_APP_IDLE_ID, ELIB_LMP_MBLT_POCKET);
	}
#endif	

#ifdef CSW_SUPPORTKEYLOCK
	/* CSV incoming, enable menu key */
	if(This->Private->m_bKeyLockStatus)
	{
		wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKRESTART );

		/* Start a CSV, clear the sos buffer */
		This->Private->m_SosString[0] = '\0';
	}
#endif

	/* CSV incoming, enable menu key */
	if(This->Private->m_bDialLockEnable)
	{
		wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKRESTART );
	}
    
    /* Idle inactive */
	{
		TI_EVID_NULL_STRUCT	Event;
		BOOLEAN IdleStatus = FALSE;
		Event.Id	= EVID_IDLE_STATUS_CHANGED;
		Event.Size	= sizeof(BOOLEAN);
		Event.Ptr	= &IdleStatus;
		MsApiEvBroadcastEventInd( NULL, &Event );
	}
	
	/* end request from IDLE to CSV */
	Clm_Conflict_Inquire( APM_APP_IDLE_ID, CLM_RET_INSTANT, CLM_INQ_END_ITEM, CLM_ITEM_DESKTOP, CLM_FIRST_RESULT_CONFLICT );
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_RefreshService
*
* $UniqueID:3E84811503B2$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_RefreshService )
{
	UpdateServiceScreen(This);

    /* Disable shortcut tree selecting rectangle */
	SetSelectedShortcut(This, -1);
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_RefreshDesktop
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_RefreshDesktop )
{
	UpdateShortcuts(This);
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_DeleteSIMsg
*
* $UniqueID:3E7A849E00C5$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_DeleteSIMsg )
{
	/* Get the registration number */
	_ELIB_SIP_DATA sip_data;
	int ret = Elib_SIP_Listdata_Get (MuiAppGetApId(This), This->Private->m_SIMsgListNo, &sip_data);
	
	if ( ret >= ELIB_SIP_DATA_MIN && ret <= ELIB_SIP_DATA_MAX )
        {
        	/* Delete the message */
		if (ELIB_SCH_OK != Elib_SIP_Reset (MuiAppGetApId (This), sip_data.No))
		{
			os_assert (FALSE, ("SI Msg delete error"));
		}
	}
	else
        {
        	os_assert (FALSE, ("SI Msg delete error"));
        }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_DeleteShortcut
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_DeleteShortcut )
{
	int i;
    int ItemToDelete;
    TS_DATABASE_USER_DISPLAY_RECORD* tmp = NULL;
    
    /* the item is missing call */
    if(ItIsMissedCallShortcut (This, This->Private->m_ItemToDelete))
    {
		This->Private->m_MissedCallShortcut = FALSE;
		This->Private->m_MissedCallDisplayed = MISSED_CALL_NORMAL;
		UpdateShortcuts (This);
		UpdateIdleMissedCall(This); 
#ifdef CHW_SUBLCD
		/* Erase missing call display in sub led */
		Elib_DSP_BL_Erase( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF_DSP );
		Elib_DSP_BL_Erase( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF );
#else
#endif 

		return;
    }

    if ( (This->Private->m_IdleScreenType != IDLE_TYPE_NORMAL) ||
         (This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL) &&
         (This->Private->m_SIPaneShowed) )
    {
        ItemToDelete = This->Private->m_ItemToDelete - 1;
    }
    else
    {
        ItemToDelete = This->Private->m_ItemToDelete;
    }

    /* Delete the record */
	tmp = This->Private->m_DesktopShortcutsPointer[ItemToDelete];
	tmp->ApplicationId = 0;
	tmp->FixedTextId = 0;
	tmp->Icon = IMG_IDL_TRANSPARENT_TEMP;
	INIT_UTF( tmp->AlphaTag );
	memset( tmp->DataShortcutObjectHandle, 0xFF, 1025 );

	for (i = ItemToDelete; i < MAX_SHORTCUTS_NUM-1; i++)
	{
		This->Private->m_DesktopShortcutsPointer[i] = This->Private->m_DesktopShortcutsPointer[i+1];
	}

	/* Delete the last icon */	
	This->Private->m_DesktopShortcutsPointer[i] = tmp;

	/* Save it to database */
	MsApiWriteDesktopShortcuts (This->Private->m_DesktopShortcutsPointer);

    This->Private->m_ItemToDelete = -1;
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_SetDefaultFocus
*
* $UniqueID:3E757CC000A6$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_SetDefaultFocus )
{
	BOOLEAN Selected = FALSE;
    int MissedCallIndex = GetMissedCallShortcutIndex(This);
	int ShortcutNum = GetShortcutNum(This);
    /* if it came back from SI Pane deletion action, 
     * or cancel from shortcut deletion, 
     * set the focus to SI Pane or shortcut againg
     */
    if (This->Private->m_FormerSelectedItem != -1)
    {
        Selected = SetSelectedShortcut(This, This->Private->m_FormerSelectedItem);
        This->Private->m_FormerSelectedItem = -1;
    }

    /*Set select focus to missed call */
    if (!Selected && -1 != MissedCallIndex)
    {
        Selected = SetSelectedShortcut (This, MissedCallIndex);
    }

    /* Check the validity */
    if (!Selected && 
		ShortcutNum == 0 && 
		This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL && 
		!This->Private->m_SIPaneShowed)
    {
        SetSelectedShortcut (This, -1);
        FsmIfAddEvent (This, E_DONE);
        return;
    }

    /* Set selected to the first shortcut */    
    if (!Selected)
    {
		/* The first selected shortcut should be calandar or SiPane */
        if (This->Private->m_IdleScreenType != IDLE_TYPE_CALENDAR && 
            !This->Private->m_SIPaneShowed )
        {
            SetSelectedShortcut (This, 0);
        }
        else
        {
            if (!SetSelectedShortcut (This, 1))
            {
            	SetSelectedShortcut (This, 0);
            }
        }

        Selected = TRUE;
    }

    /* Update the wallpaper to get the active semi-transparent helpline effect */
    if (Selected)
    {
        UpdateWallpaper (This);
    }
	MuiAppIfOptionMenuShow( This, FALSE );
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_ShowDelShortcutCnfDlg
*
* $UniqueID:3E7A7807026E$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the confirm dialog when prompting user whether or not to delete the current SI
* message.
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_ShowDelShortcutCnfDlg )
{
	if(Qual)
    {
        int ItemToDelete;

        if ( (This->Private->m_IdleScreenType != IDLE_TYPE_NORMAL) ||
             (This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL) && (This->Private->m_SIPaneShowed) )
        {
            ItemToDelete = This->Private->m_ItemToDelete - 1;
        }
        else
        {
            ItemToDelete = This->Private->m_ItemToDelete;
        }
		
		os_assert (This->Private->m_ItemToDelete>=0, ("Error to delete idle desktop shortcuts"));
		
		/* Display the message */
		This->Private->m_CnfDelSIDlg = FsmIfCreateInstance( This, C_MUI_DISPLAY_MESSAGE );
		MuiDisMsgSetStyle (This->Private->m_CnfDelSIDlg, DLG_CNF_1);
		This->Private->m_CnfDelSIDlg->Public->m_TextId = WORD_MSG_CMN_SHORTCUT_DEL_CNF;
		MuiDisMsgSetClearKey(This->Private->m_CnfDelSIDlg, E_CANCEL);
    }
    else
    {
		FsmIfDeleteInstance (This->Private->m_CnfDelSIDlg);
		This->Private->m_CnfDelSIDlg = NULL;
		/* delete the display message*/
		if( This->Private->m_DisplayMessage )
		{
			FsmIfDeleteInstance(This->Private->m_DisplayMessage);
			This->Private->m_DisplayMessage = NULL;
		}
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_Cancel_DeleteShortcut
*
* $UniqueID:$
*
* <TI_MUI_VOICE_CALLS_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_Cancel_DeleteShortcut )
{
	This->Private->m_FormerSelectedItem = This->Private->m_ItemToDelete;
}
END_PRIVATE_ACTION


/*******************************************************************************
*
* MACRO: a_CreateCallLogClass
*
* $UniqueID:$
*
* <TI_MUI_VOICE_CALLS_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_CreateCallLogClass )
{

	/* Philip Kamoi for CLM */
	/* Richard changed for verify call logs 2004.3.26*/
#if 0
	if(g_SIMM_PBK_READY_FLG == 0)
	{
		FsmIfAddEvent(This, e_WaitMainMenu);
	}
	else if (MuiConflictInquire(APM_APP_IDLE_ID, APM_APP_CALL_LOGS_ID, CL_MISSED_CALLS) == CLM_RESULT_PERMIT)
#else
	if (MuiConflictInquire(APM_APP_IDLE_ID, APM_APP_CALL_LOGS_ID, CL_MISSED_CALLS) == CLM_RESULT_PERMIT)
#endif
	{
		switch (Qual)
	    {
	        case IDLE_REDIAL_LOG:
				MuiCallLogsAccessRedialList((TI_GENERIC *)This);
	        break;

	        case IDLE_INCOMING_LOG:
				MuiCallLogsAccessIncomingHistory((TI_GENERIC *)This);
	        break;

	        case IDLE_UNANSWERED_LOG:
				MuiCallLogsAccessMissedCalls((TI_GENERIC *)This);
				if(This->Private->m_MissedCallShortcut)
				{
					This->Private->m_MissedCallShortcut = FALSE;
					UpdateIdleMissedCall(This); 
					This->Private->m_MissedCallDisplayed = MISSED_CALL_NORMAL;
					UpdateShortcuts (This);
#ifdef CHW_SUBLCD
					/* Erase missing call display in sub led */
					Elib_DSP_BL_Erase( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF );
					Elib_DSP_BL_Erase( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF_DSP );
#else 
#endif
				}
	        break;
	        
	        case IDLE_MENU_LOG:
	        	MuiCallLogsAccessCallLogsApp((TI_GENERIC *)This);
	        break;

	        case IDLE_UNLOAD_LOG:
	        
	        break;

	        default:
	            os_assert(FALSE, ("Unknown call logs category"));
	        break;    

	    }
	
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: mtws_MenuKey
*
* $UniqueID:3CC7D7040191$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_MenuKey )
{
	if(This->Private->m_IdleStatus == IDLE_NORMAL_STATUS || utflen(&This->Private->m_IdleString.utf) != 0 )
	{
		FsmIfAddEvent(This, e_GotoMenu);
	}
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_CancelKey
*
* $UniqueID:3CC7D70401C3$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_CancelKey )
{
   FsmIfAddEvent(This, E_DONE);
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_CancelKey
*
* $UniqueID:3CC7D70401C3$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_Shortcut_ItemCallback )
{
	XmTreeNodeCallbackStruct *Data = (XmTreeNodeCallbackStruct *)call_data;
	char TextBuffer[256] = "";
	
    if ( Data->reason & XmTREE_NODE_NUM_ITEMS)
    {
        Data->num_of_items = 8;
    }
	
	if ( Data->reason & XmTREE_NODE_IMAGE )
    {
		/* Get Image */
        TS_DATABASE_USER_DISPLAY_RECORD* tmp;
        
        /* Missed call */
        if (ItIsMissedCallTreeIndexShortcut(This, Data->index))
        {
            Data->ImageId = IMG_IDL_DI_NMC;
        }
        else
        {
            tmp = GetShortcutRecord(This, Data->index);
            
            if (tmp)
            {
                Data->ImageId = tmp->Icon;
            }
        }
    } 
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_Shortcut_TopLevelCallback
*
* $UniqueID:$
*
* <C_MUI_APP_MENU* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_Shortcut_TopLevelCallback )
{
    XmTreeLevelCallbackStruct *Data = (XmTreeLevelCallbackStruct *)call_data;

    if ( Data->reason & XmTREE_LEVEL_STYLE )
    {
        Data->tree_style = XmTREE_STYLE_GRID;
		Data->GridPosOffsetX = 0;
		Data->GridPosOffsetY = 0;
		Data->GridNumColumns = 4;

        /* Display the shortcut text in the help area */
        Data->GridItemTextLocation = XmTREE_ITEM_TEXT_OUTSIDE; 

        if (This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL)
        {
            Data->GridCellHeight = SHORTCUT_ROW_HEIGHT;
        }
        else
        {
            Data->GridCellHeight = SHORTCUT_ROW_HEIGHT_CAL;
        }

        Data->GridCellWidth = SHORTCUT_COLUMN_WIDTH;
	}
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_TickKey
*
* $UniqueID:3E7B4D24029B$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_TickKey )
{
	TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;
	if(This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
	{
		if(Data->event->type == KeyPress && Data->event->xkey.state != XtTMLong)
		{
			FsmIfAddEvent(This, e_Active);
		}
	}
	else
	{
		if(utflen(&This->Private->m_IdleString.utf) != 0)
		{
            /* launch voice call */
            LaunchVoiceCall(This);

            /* reset the keypad, After we handle the press event in dial screen
			** the release key event should be discard.
			*/
			MuiAppMtwsReleaseKey( This->Private->m_Dlg->App->Protected->m_pKeyPad );
		}
	}
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_SendKeyPressed
*
* $UniqueID:3E7B4D24029B$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_SendKeyPressed )
{
	TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;
	
	/* Long press send key event should be discard */
	if(Data->event->xkey.state == XtTMLong)
	{
		return;
	}
	if(This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
	{
		if(This->Private->m_CurrentSelectedItem >= 0)
		{
			/* Moving shortcut, Press send key, save the 
			 * moving and return to normal screen.
			*/
			if(This->Private->m_ShortcutMoving)
			{
				This->Private->m_ShortcutMoving = FALSE;
				MsApiWriteDesktopShortcuts(This->Private->m_DesktopShortcutsPointer);
			}
			FsmIfAddEvent(This, E_DONE);
		}
		else
		{
			FsmIfAddEvent(This, e_SendKeyPressed);
		}
	}
	else
	{
		if(utflen(&This->Private->m_IdleString.utf) != 0)
		{
            /* launch voice call */
            LaunchVoiceCall(This);

            /* reset the keypad, After we handle the press event in dial screen
			** the release key event should be discard.
			*/
			MuiAppMtwsReleaseKey( This->Private->m_Dlg->App->Protected->m_pKeyPad );
		}
	}
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_FocusOnDial
*
* $UniqueID:3E7B4D240350$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_FocusOnDial )
{
	TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;

	/* if now it is in shortcut moving state, cancel the shortcut moving */
	if(This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
	{
		/* Only handle the shortcut press event. */
		if(Data->event->xkey.state == 0 && Data->event->type==KeyPress)
		{
			if (This->Private->m_ShortcutMoving)
			{
				int count;
		
				/*Resume the shortcuts*/
				for(count = 0; count < MAX_SHORTCUTS_NUM; count++)
				{
					This->Private->m_DesktopShortcutsPointer[count] = This->Private->m_DesktopShortcutsTempPointer[count];
				}
		
				UpdateShortcuts(This);
				This->Private->m_ShortcutMoving = FALSE;
				SetSelectedShortcut(This, This->Private->m_ItemToMove);
			}
			else
			{
				/* return to not active Idle */
				FsmIfAddEvent (This, E_DONE);
			}
		}
	}
	else
	{
		if(Data->event->xkey.state == XtTMLong && utflen(&This->Private->m_IdleString.utf) == 0)
		{
			FsmIfAddEvent(This, E_DONE);
		}
		else if(Data->event->type==KeyRelease && Data->event->xclient.data.l[0] == 0 
				&& utflen(&This->Private->m_IdleString.utf)<2 )
		{
			utfsetlen(&This->Private->m_IdleString.utf, 0);
			FsmIfAddEvent(This, E_DONE);
		}
		else
		{
			Data->processed = FALSE;
		}
	}		
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_EndKeyPressed
*
* $UniqueID:3E7B4D240350$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_EndKeyPressed )
{
	TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;

	/* Press END key when dial lock */
	if(This->Private->m_bDialLockEnable && This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
	{
		if(Data->event->type == KeyRelease && Data->event->xclient.data.l[0] == 0)
		{
			FsmIfAddEvent(This, e_KeyPressed);
		}
	}
#ifdef CSW_SUPPORTKEYLOCK
	else if( This->Private->m_bKeyLockStatus && This->Private->m_IdleStatus == IDLE_NORMAL_STATUS )
	{
		FsmIfAddEvent(This, e_AnyKeyPressed);
		This->Private->m_SosString[0] = '\0';
	}
#endif
	else if(Data->event->type == KeyPress)
	{
		if(This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
		{
			FsmIfAddEvent (This, E_DONE);
		}
		else
		{
			utfsetlen(&This->Private->m_IdleString.utf, 0);
			FsmIfAddEvent (This, E_DONE);

            /* reset the keypad, After we handle the press event in dial screen
			** the release key event should be discard.
			*/
			MuiAppMtwsReleaseKey( This->Private->m_Dlg->App->Protected->m_pKeyPad );
		}
	}
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_IdleDigitsStrChange
*
* $UniqueID:3CC7D7040232$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_IdleDigitsStrChange )
{
    TS_UTF_PHONENUMBER NewIdleString;
    /* Store the digits */
    char * str = XmTextEditGetString( w );
	
	if(This->Private->m_IdleStatus == IDLE_NORMAL_STATUS && strlen(str) > 0)
    {
        FsmIfAddEvent(This, e_DigitsPresent);
    }
	
	if(utflen(&This->Private->m_IdleString.utf) == 0 && strlen(str) > 0 && This->Private->m_IdleStatus == IDLE_DIAL_STATUS)
	{
		MuiAppIfOptionMenuShow( This, TRUE );
		MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[DIAL_SCREEN_1].SkText, MUI_DLG_TEXT_LEFT );
		MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[DIAL_SCREEN_2].SkText, MUI_DLG_TEXT_RIGHT );
	}
	else if(strlen(str) == 0 && utflen(&This->Private->m_IdleString.utf) > 0)
	{
		MuiAppIfOptionMenuShow( This, FALSE );
		MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[NONE_ACTION].SkText, MUI_DLG_TEXT_LEFT );
		MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[NONE_ACTION].SkText, MUI_DLG_TEXT_RIGHT );
	}

    INIT_UTF(NewIdleString);
    utfcpy( &NewIdleString.utf, str );
    XtFree( str );
    /* if the string has changed copy it and process it. If it hasn't changed,
       then the function has been called incorrectly, so do nothing */
    /* copy the string from the widget into our local buffer */
    if(strcmp(This->Private->m_IdleString.buf, NewIdleString.buf))
    {
        utfcpy(&This->Private->m_IdleString.utf, NewIdleString.buf);
		
		if( This->Private->m_IdleString.buf[
                      strlen( This->Private->m_IdleString.buf ) - 1 ] == '#' )
        {
            switch(NdIfReportDialType(This->Private->m_IdleString.buf, 0))
            {
                case SYGND_SIM_FAST_VIEW_STRING:
					{
			            /* strip the # from the end of the string */
						utfncpy(&This->Private->m_IdleString.utf, NewIdleString.buf, utflen(&NewIdleString.utf)-1);
                   		FsmIfAddEvent(This, e_PbkFastView);
                    }
                    break;
                case SYGND_SS_IMEI_STRING:
                case SYGND_MANUFACTURER_PSEUDO_SS_STRING:
                	{
            		     FsmIfAddEvent(This, e_GotoPss);
                    }
                    break;

                /* Ignore these ones as they are only processed when the tick
                   key is pressed rather than when they appear in the buffer */
                case SYGND_GSM_SS_STRING:
                case SYGND_SIM_CONTROL_STRING:
                case SYGND_CPHS_LANGUAGE_SET_STRING:
                case SYGND_MANUFACTURER_FAST_DIAL_STRING:
                case SYGND_USSD_STRING:                
                case SYGND_CALL_SETUP_STRING:
                case SYGND_UNSUPPORTED_STRING:
                    break;
                default:
                    os_assert(FALSE, ("Unknown string type"));
                    break;
            }
        }
    }
}
END_PRIVATE_MTWS_CALLBACK

static void LaunchVoiceCall(TI_MUI_IDLE_INTERFACE* This)
{
    switch(NdIfReportDialType(This->Private->m_IdleString.buf, 0))
    {
		case SYGND_CALL_SETUP_STRING:
		{
			TS_CMD_STATUS CmdStatus = CMST_OK;
			CmdStatus = MuiCsvSetDialString( This->Private->m_VoiceCallsClass, This->Private->m_IdleString.buf );
			if(This->Private->m_MissedCallShortcut)
			{
				char NumberBuffer[TS_PHONE_NUMBER_LEN];
				TS_DATABASE_CALL_LOG_RECORD* TempPtr = MM_malloc( sizeof(TS_DATABASE_CALL_LOG_RECORD) );
				MuiGetlatestCall( TempPtr, SYSDM_UNANSWERED_LOG );
				if(TempPtr->PhoneNum.Number.Ton == TON_INTERNATIONAL)
				{
					NumberBuffer[0] = '+';
					LibPhoneNumToUtf8( &TempPtr->PhoneNum.Number, NumberBuffer+1, sizeof(NumberBuffer)-1, TS_PHONE_DIS_CALL );
				}
				else
				{
					LibPhoneNumToUtf8( &TempPtr->PhoneNum.Number, NumberBuffer, sizeof(NumberBuffer), TS_PHONE_DIS_CALL );
				}
				if(strcmp(NumberBuffer, This->Private->m_IdleString.buf) == 0)
				{
					This->Private->m_MissedCallShortcut = FALSE;
					This->Private->m_MissedCallDisplayed = MISSED_CALL_NORMAL;
					UpdateShortcuts (This);
					UpdateIdleMissedCall(This); 
#ifdef CHW_SUBLCD
					/* Erase missing call display in sub led */
					Elib_DSP_BL_Erase( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF );
					Elib_DSP_BL_Erase( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF_DSP );
#else
#endif
				}
				MM_free(TempPtr);
			}
			utfsetlen(&This->Private->m_IdleString.utf,0);
			break;
		}
		case SYGND_MANUFACTURER_FAST_DIAL_STRING:
			FsmIfAddEvent(This, e_PbkFastDial);
			break;
		case SYGND_CPHS_LANGUAGE_SET_STRING:
        case SYGND_SS_IMEI_STRING:
        case SYGND_MANUFACTURER_PSEUDO_SS_STRING:
            break;
        case SYGND_GSM_SS_STRING:
			MuiSsSendSsCs(&This->Private->m_Session,  &This->Private->m_IdleString.utf);
			utfsetlen(&This->Private->m_IdleString.utf,0);
			FsmIfAddEvent(This, E_DONE);        	
            break;
        case SYGND_SIM_CONTROL_STRING:
        case SYGND_SIM_FAST_VIEW_STRING:
            break;
        case SYGND_USSD_STRING:
			MuiSsSendUssdCs(&This->Private->m_Session,  &This->Private->m_IdleString.utf);
			utfsetlen(&This->Private->m_IdleString.utf,0);
			FsmIfAddEvent(This, E_DONE);    	
            break;
        case SYGND_UNSUPPORTED_STRING:
			utfsetlen(&This->Private->m_IdleString.utf,0);
			FsmIfAddEvent(This, E_DONE);    	
            /* os_assert(FALSE, ("Idle does not currently support this type of string"));*/
            break;
        default:
            os_assert(FALSE, ("Unknown string type"));
            break;
    }
}

/*******************************************************************************
*
* MACRO: mtws_SKIdleAction
*
* $UniqueID:3CC7D70402E6$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_SKIdleAction )
{
    TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;
    int ActionId = NONE_ACTION;
    static BOOLEAN IgnoreSK2Release = FALSE;

	/* short press event, handle all softkey action except softkey2 press event in normal screen.*/
	if(Data->event->type == KeyPress && Data->event->xkey.state != XtTMLong)
	{
		/* Current select is SI Pane */
		if(This->Private->m_CurrentSelectedItem == 0 && This->Private->m_SIPaneShowed)
		{
			if(Data->event->xkey.keycode==XK_KEY_SOFT2)
			{
				FsmIfAddEvent (This, e_PreDelete);
                IgnoreSK2Release = TRUE;
			}
		}
		else if(This->Private->m_CurrentSelectedItem == 0 && This->Private->m_IdleScreenType == IDLE_TYPE_CALENDAR)
		{
			/* current select item is calendar, do nothing */
		}
		else if(This->Private->m_CurrentSelectedItem >= 0)
		{
			/* Current select item is tree shortcut */
			if (Data->event->xkey.keycode==XK_KEY_SOFT1)
			{
				if( This->Private->m_ShortcutMoving )
				{
					This->Private->m_ShortcutMoving = FALSE;
	
					/* restore the softkey */
					MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_IDLE_KEY_MOVE, MUI_DLG_TEXT_LEFT );
					MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_IDLE_KEY_REMOVE, MUI_DLG_TEXT_RIGHT );
					/* Save the moving to DB*/
					MsApiWriteDesktopShortcuts(This->Private->m_DesktopShortcutsPointer);
				}
				else if(!ItIsMissedCallShortcut (This, This->Private->m_CurrentSelectedItem))
				{
					int count;

	                This->Private->m_ShortcutMoving = TRUE;
					MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_IDLE_KEY_PLACE, MUI_DLG_TEXT_LEFT );
					MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_BLANK, MUI_DLG_TEXT_RIGHT );
					/*Backup befor moving*/
					This->Private->m_ItemToMove = This->Private->m_CurrentSelectedItem;
					for(count = 0; count < MAX_SHORTCUTS_NUM; count++)
					{
						This->Private->m_DesktopShortcutsTempPointer[count] = This->Private->m_DesktopShortcutsPointer[count];
					}
				}
			}
			else
			{
				/* softkey2 do nothing when moving*/
				if(!This->Private->m_ShortcutMoving)
				{
					FsmIfAddEvent (This, e_PreDelete);
				}
			}
		}
		else
		{
		    /* Dial screen softkey action */
		    if(This->Private->m_IdleStatus == IDLE_DIAL_STATUS)
		    {
		    	if(utflen(&This->Private->m_IdleString.utf) != 0)
		    	{
		    		ActionId = Data->event->xkey.keycode==XK_KEY_SOFT1 ? DIAL_SCREEN_1 : DIAL_SCREEN_2;
		    	}
		    	else
		    	{
		    		ActionId = NONE_ACTION;
		    	}
		    }
#ifdef CSW_SUPPORTKEYLOCK
		    else if( This->Private->m_bKeyLockStatus == TRUE )
		    {
		   		FsmIfAddEvent(This, e_AnyKeyPressed);
		   		This->Private->m_SosString[0] = '\0';
				return;
		    }
#endif
		    else if( This->Private->m_bDialLockEnable == TRUE )
		    {
		    	ActionId = Data->event->xkey.keycode==XK_KEY_SOFT1 ? DIAL_LOCK_1 : DIAL_LOCK_2;
		    }
		    else
		    {
		    	ActionId = Data->event->xkey.keycode==XK_KEY_SOFT1 ? NORMAL_SCREEN_1 : NONE_ACTION;
			}
		
		    if(Data->event->type == KeyPress && SoftKeyData[ActionId].Action != ACT_NONE)
		    {
			   PerformSoftKeyAction( This, SoftKeyData[ActionId].Action );
		    }
		}
	}
	/* softkey2 long press or short release event in normal screen.*/
	else if(Data->event->xkey.keycode == XK_KEY_SOFT2 && 
            This->Private->m_CurrentSelectedItem == -1)
	{
        /* The SK2 release will go here if we are deleting si-pane by sk2 */
        if (IgnoreSK2Release == FALSE)
        {    
		    /* long press event*/
		    if(Data->event->type == KeyPress)
		    {
			    PerformSoftKeyAction( This, ACT_MSG_CREATE );
		    }
		    /* short release event */
		    else if(Data->event->xclient.data.l[0] == 0)
		    {
			    PerformSoftKeyAction( This, ACT_MSG_VIEW );
		    }
        }
        else
        {
            IgnoreSK2Release = FALSE;
        }
    }
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_AlsSwitchLine
*
* $UniqueID:3CC7D70500AC$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_AlsSwitchLine )
{
    TS_ALS_LINE AlsLine;
    TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;

	if(This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
	{
		if(Data->event->type == KeyPress && FsmIfGuard(This, g_CallALSSupported, TRUE))
		{
            TS_CMD_STATUS CmdStatus;
	    
	        TS_ALS_LOCK_RESULT AlsLockSetting;
    	    MsApiSysCfgQueryAlsLock(&AlsLockSetting);
			if(AlsLockSetting == SYSIM_ALS_LOCK_ON)
			{
				FsmIfAddEvent(This, e_VerifyPIN2);
			}
			else
			{
	            CmdStatus = MsApiSysCfgQueryAls(&AlsLine);
	            os_assert((CmdStatus == CMST_OK), ("ALS query failed" ));
	            CmdStatus = MsApiSysCfgSetLine( &This->Private->m_Session, (AlsLine == ALS_LINE_1 ? ALS_LINE_2 : ALS_LINE_1) );
	            
	            os_assert((CmdStatus == CMST_OK), ("ALS query failed" ));
	        }
	    }
	    else if(Data->event->xclient.data.l[0] == 0)
	    {
			Data->processed = FALSE;
	    }
	}
	else
	{
		Data->processed = FALSE;
	}
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_ProcessKeysForOtd
*
* $UniqueID:3CC7D70500E9$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_ProcessKeysForOtd )
{
	TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;
    Data->processed=FALSE;
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_ScreenTypeMenu
*
* $UniqueID:3E84451F020C$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_ScreenTypeMenu )
{
    XmTreeNodeCallbackStruct *Data = (XmTreeNodeCallbackStruct *)call_data;

    if ( Data->reason & XmTREE_GREY_OUT )
	{
		if(Data->qual == 1 && This->Private->m_SIPaneShowed)
		{
			Data->grey_out = TRUE;
		}
	}

	if ( (Data->reason & XmTREE_NODE_ITEM_IS_SET) )
	{
		Data->SelectionIndicator = ( Data->qual == QueryIdleScreenType(This));
	}
    
    if ( Data->reason & XmTREE_NODE_CR_BROWSE_SELECT )
    {
        if(QueryIdleScreenType(This) != Data->qual)
        {
            /* Copy the current screen type preference to NVD */
            UpdateIdleScreenType( This, Data->qual );
        }
        FsmIfAddEvent(This, E_DONE);
    }
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_PasteNumber
*
* $UniqueID:3E84451F020C$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_PasteNumber )
{
    XmTreeNodeCallbackStruct *Data = (XmTreeNodeCallbackStruct *)call_data;
	_IM_CLIPBOARD *ClipBoadData;
	
    if ( Data->reason & XmTREE_GREY_OUT )
    {
		/* Get data from clipboard */
		ClipBoadData = IM_GetClipboardData();
		
		if( ClipBoadData == NULL || ClipBoadData->wSize == 0 || !IsValidPhoneNum(ClipBoadData))
		{
			Data->grey_out = TRUE;
		}
		IM_FinClipboardData();
    }
    if ( Data->reason & XmTREE_NODE_CR_BROWSE_SELECT )
    {
    	ClipBoadData = (_IM_CLIPBOARD*)IM_GetClipboardData();
    	/* paste clipboard data to dial screen */
		if( ClipBoadData != NULL && ClipBoadData->wSize > 0 && IsValidPhoneNum(ClipBoadData))
    	{
			int count = 0;
			char buffer[38];
			
			/* If the ClipBoard Data is longer than 37, we just get the first 37 data */
			for(count = 0; count < ClipBoadData->wSize && count < 37 ; count++)
			{
				buffer[count] = (char) ClipBoadData->pwText[count];
			}
			buffer[count] = '\0';
			utfcpy( &This->Private->m_IdleString.utf, buffer);
			XmTextEditSetString(This->Private->m_TextLabel, buffer);
			XtVaSetValues( This->Private->m_TextLabel, XmNcursorPosition, count, NULL);
			FsmIfAddEvent(This, e_DigitsPresent);
    	}
		IM_FinClipboardData();
    }
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_LeftKey
*
* $UniqueID:3E757D9A01ED$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* mtws call back function for left key
* 
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_LeftKey )
{
	TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;

	if(This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
	{
		FsmIfAddEvent (This, e_Left);
	}
	else
	{
		Data->processed=FALSE;
	}
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_RightKey
*
* $UniqueID:3E757DBC025A$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_RightKey )
{
	TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;

	if(This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
	{
		FsmIfAddEvent (This, e_Right);
	}
	else
	{
		Data->processed=FALSE;
	}
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: g_SIPaneActive
*
* $UniqueID:$
*
* <C_MUI_PBK_VIEW* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
* 
* RETURN: BOOLEAN
* returns true if the guard condition is valid
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_GUARD ( g_SIPaneActive )
{
    BOOLEAN ret;
    
    ret = ((This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL) && \
        (This->Private->m_SIPaneShowed) && \
        (This->Private->m_CurrentSelectedItem == 0));
    
    if (Qual)
    {
        return ret;
    }
    else
    {
        return !ret;
    }
}
END_PRIVATE_GUARD

/*******************************************************************************
*
* MACRO: g_SIMRemoved
*
* $UniqueID:$
*
* <C_MUI_PBK_VIEW* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
* 
* RETURN: BOOLEAN
* returns true if the guard condition is valid
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_GUARD ( g_SIMRemoved )
{
	return (Qual == This->Private->m_bSimRemoved);
}
END_PRIVATE_GUARD

/*******************************************************************************
*
* MACRO: g_CallALSSupported
*
* $UniqueID:$
*
* <TI_MUI_VOICE_CALLS_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
* 
* RETURN: BOOLEAN
* returns true if the guard condition is valid
*
* $Description$
* Guard to determine if Alternate Line Selection (ALS) is supported.
* $End$
*******************************************************************************/
START_PRIVATE_GUARD ( g_CallALSSupported )
{
    BOOLEAN ALSVal;
    ALSVal = MsApiSysCfgAlsSupported(&This->Private->m_Session.Session);

    return (ALSVal == Qual);
}
END_PRIVATE_GUARD

static void LaunchVideoCall(TI_MUI_IDLE_INTERFACE* This)
{
	/* Store the digits */
	switch(NdIfReportDialType(This->Private->m_IdleString.buf, 0))
	{
		case SYGND_MANUFACTURER_FAST_DIAL_STRING:
			FsmIfAddEvent(This, e_PbkFastVt);
			break;

		case SYGND_CALL_SETUP_STRING:
			FsmIfAddEvent (This, e_VideoCall);
			break;
		default:
			/* illegal string */
			utfsetlen( &This->Private->m_IdleString.utf, 0 );
			FsmIfAddEvent(This, E_DONE);
	}			
}

/*******************************************************************************
*
* MACRO: mtws_ProcessExpansionEvent
*
* $UniqueID:3E844FB1008B$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_ProcessExpansionEvent )
{
    TL_MUI_GRAB_DATA*  Data = ( TL_MUI_GRAB_DATA* ) call_data;
    TI_EVID_NULL_STRUCT event;  // Lisa event rountined to Krusty/Lisa destination from NEC-J app

	/* date fortmat changed */
	if(Data->event->xexpansion.category == ScheduleNotify)
	 {
	 	switch(Data->event->xexpansion.subtype)
	 	{
			case ScheduleNotify_Bell_icon :
	 		case ScheduleNotify_Interval :
				/* update date if date is changed */
				{
					TS_TIME_DATE TimeDate;
					memset( &TimeDate, 0, sizeof(TS_TIME_DATE) ) ;
	 				MsApiGetCurrentTimeAndDate(&TimeDate);
	 				if(TimeDate.hours == 0)
	 				{
	 					UpdateTimeDate(This);
                        if (This->Private->m_IdleScreenType == IDLE_TYPE_CALENDAR &&
                            This->Private->m_IdleStatus     == IDLE_NORMAL_STATUS)
                        {
                            UpdateCalendar(This);
                        }
                    }
				}
	 			
	 			if( Elib_SCH_ActiveEvent_Get(APM_APP_IDLE_ID) == ELIB_SCH_24H )
	 			{
 					/* Alarm status changed, update the icon area */
 					if( This->Private->m_bAlarmEnable == FALSE )
 					{
 						This->Private->m_bAlarmEnable = TRUE;
 						UpdateKeypadLockIcon( This );
 					}
	 			}
	 			else
	 			{
	 				/* Alarm status changed, update the icon area */
	 				if( This->Private->m_bAlarmEnable == TRUE )
	 				{
	 					This->Private->m_bAlarmEnable = FALSE;
	 					UpdateKeypadLockIcon( This );
	 				}
	 			}
	 			break;
	 		
	 		case ScheduleNotify_ChgCal :
	 			{
	 				UpdateTimeDate(This);
	 				if(This->Private->m_IdleScreenType == IDLE_TYPE_CALENDAR &&
					   This->Private->m_IdleStatus     == IDLE_NORMAL_STATUS)
	 				{
	 					UpdateCalendar(This);
	 				}
	 			}
	 			break;
	 			
	 		case ScheduleNotify_Clockformat :
				{
		            UpdateTimeDate(This);
		        }
	 			break;
			
			default :
	 			break;
	 	}
	 	return;
	 }
	 
    if ( Data->event->type == Expansion && Data->event->xexpansion.category == PUSHArrivedEvent
            && Data->event->xexpansion.subtype	== PUSHEvent)
    {
        event.Id   = EVID_PUSHEVENT_NTF;
        event.Size = sizeof(PUSH_COMMON_ARG);	// tpArg->iSize, see typedef PUSH_COMMON_ARG
        event.Ptr  = Data->event->xexpansion.data;
        EmIfEventNotificationInd( NULL, &event );
        return;
    }

	if ( Data->event->type == Expansion && Data->event->xexpansion.category == SipaneNotify
		&& Data->event->xexpansion.subtype == SipaneNotify_Update)
    {
		ProcessELibSINotification(This);
		return;
    }

	if ( Data->event->type == Expansion && Data->event->xexpansion.category == PUSHArrivedEvent
		&& Data->event->xexpansion.subtype == PUSHEvent)
    {
        ProcessPushOTAEvent (This, Data->event->xexpansion.data);
        return;
    }

#ifdef CHW_SUBLCD
    /* Display sub lcd */
	if( Data->event->xexpansion.category == DispNotify )
    {
	 	switch(Data->event->xexpansion.subtype)
	 	{
	 		case DispNotify_NonDisp :
	 			Elib_DSP_BL_Dsp(MuiAppGetApId(This), ELIB_DSP_BL_CLOCK, NULL, NULL, 0);
	 			break;
			default :
	 			break;
	 	}
	 	return;
	}
#else
#endif 

	if( Data->event->xexpansion.category == ApplicationEvent )
	{
		/* keypad lock is enabled only in IDLE normal screen */
		if ( Data->event->xexpansion.subtype == InActiveEvent )
		{
			if(This->Private->m_bDialLockEnable && This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
			{
				/* In dial lock status, When any app is launched
				 * such as alarm, message and so on, we must enable
				 * menu key.
				*/
				wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKRESTART );
			}
#ifdef CSW_SUPPORTKEYLOCK
			if(This->Private->m_bKeyLockStatus && This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
			{
				/* In keypad lock status, When any app is launched
				 * such as alarm, message and so on, we must enable
				 * menu key.
				*/
				wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKRESTART );
				
				/* When idle is inactive, clear the sos buffer */
				This->Private->m_SosString[0] = '\0';
			}
#endif
			if(This->Private->m_MenuDlg)
			{
				FsmIfAddEvent(This, e_CloseOptionMenu);
			}
			/* Auto close */
			if(Data->event->xexpansion.subinfo != AM_AP_ID_WMLTW_MAIN)
			{
				FsmIfAddEvent(This, e_AutoClose);
			}
		}
		else if( Data->event->xexpansion.subtype == ActiveEvent )
		{
			if(This->Private->m_bDialLockEnable && This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
			{
				/* In keypad lock status, when focus is set on IDLE, menu key should be disabled*/
				wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKSTOP );
			}
#ifdef CSW_SUPPORTKEYLOCK
			if(This->Private->m_bKeyLockStatus && This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
			{
				/* In dial lock status, when focus is set on IDLE, menu key should be disabled*/
				wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKSTOP );
			}
#endif
		}
		Data->processed = FALSE;
	}
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: API_MuiIdleEventCallback
*
* $UniqueID:3CC7D704014B$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT TransactionId>
* this is a client generated id for each api call
*
* <TS_EV_EVID EventId>
* this is the event id enum, use to decode EventData
*
* <TS_EV_DATA_TYPE EventData>
* this is a pointer to the Event Data. This data is only valid for the duration
* of this function call
*
* $Description$
* This was called api_EventCallback, but since we want to use this on class diagrams we
* need to make it public
* $End$
*******************************************************************************/
START_PUBLIC_API_CALLBACK ( API_MuiIdleEventCallback )
{
    switch(EventId)
    {
#ifdef CSW_SUPPORTKEYLOCK			
		case EVID_CPM_SYSPRF_SYSSC_GROUP_UPDATE_NTF:
			{
				TS_PROFILE_EVENT_DATA * Data = EVM_GET_DATA_PTR( EVID_CPM_SYSPRF_SYSSC_GROUP_UPDATE_NTF, EventPtr);
				
				if(Data->SystemProfileId == SYSPR_SYSSC_KEY_LOCK_ENABLED)
				{
					/* Receive the event from Main Menu, enable key lock */
					This->Private->m_bKeyLockStatus = MsApiGetKeyLockStatus( &This->Private->m_Session.Session );
					if(This->Private->m_bKeyLockStatus == TRUE)
					{
						if(This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
						{
							UpdateKeypadLockIcon(This);
	           				MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[KEYPAD_LOCK_1].SkText, MUI_DLG_TEXT_LEFT );
	           				MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[KEYPAD_LOCK_2].SkText, MUI_DLG_TEXT_RIGHT );
	           				/* Disable menu key */
							if(FMui_Mltw_ActiveInfoReq(NULL) == APM_APP_IDLE_ID)
							{
								wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKSTOP );
							}
						}
	           			/* grab the long pressing menu key event */
	           			Elib_KEY_LongHook_Set (APM_APP_IDLE_ID, XK_KEY_FUNCTION, 10, XK_KEY_FUNCTION, 0);
					}
					else
					{
						MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[NORMAL_SCREEN_1].SkText, MUI_DLG_TEXT_LEFT );
						MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[NORMAL_SCREEN_2].SkText, MUI_DLG_TEXT_RIGHT );
						/* enable menu key */
						wMui_MLTW_ControlTaskChange( APM_APP_IDLE_ID, WMLTW_TASKRESTART );
						/* Remove the menu key hook */
						Elib_KEY_LongHook_Clr(APM_APP_IDLE_ID, XK_KEY_FUNCTION);
						/* update keypad lock icon */
						UpdateKeypadLockIcon(This);
					}
				}
			}
			break;
#endif
        case EVID_RM_SERVICE_HANDOVER_IND:      /* RM event to indicate that the request has been passed to another application */
           break;
        case EVID_NWRK_CS_STATUS_NTF:
            This->Private->m_CsInfo = *EVM_GET_DATA_PTR( EVID_NWRK_CS_STATUS_NTF, EventPtr);
            UpdatePlmnInfo( This, NULL);
            break;
        case EVID_NWRK_PS_STATUS_NTF:
            This->Private->m_PsInfo = *EVM_GET_DATA_PTR( EVID_NWRK_PS_STATUS_NTF, EventPtr);
            break;
        case EVID_CLK_TIME_DATE_IND:
        {
            TS_IMAGE_ID Image;
            TS_GEN_WALLPAPER_STYLE Style;

            MsApiGetWallpaperSetting(&Image, &Style);

            if(Style == WLP_CLOCK)
            {
                UpdateWallpaper(This);
            }

            /* Update any other Time-related screen areas that may be displayed */
            UpdateTimeDate(This);
            UpdateCalendar(This);
            break;
        }
        case EVID_SPN_INFO_UPDATE_IND:
            UpdatePlmnInfo( This, &This->Private->m_CsInfo);
            break;
        case EVID_BLT_SETTING_IND:
        	UpdateBacklightSetting(This);
        	break;
        	
        case EVID_MFN_SETTING_IND:
        case EVID_WLP_WALLPAPER_UPDATE_IND:
            UpdateServiceScreen(This);
            break;
        case EVID_SipaneNotify_Update_NTF:
            ProcessELibSINotification (This);
            break;
        case EVID_PUSHEVENT_NTF:
            ProcessPushOTAEvent (This, (void*)EventPtr->DataPtr.NullData);
            break;
        case EVID_CPM_SYSPRF_SYSGDISP_GROUP_UPDATE_NTF:
            {
                /* Notification that one of the Gen display settings in NV has been updated */
                TS_PROFILE_EVENT_DATA * Data = EVM_GET_DATA_PTR( EVID_CPM_SYSPRF_SYSGDISP_GROUP_UPDATE_NTF, EventPtr);
                /* Check if Idle screen type has been updated */
                if ( Data->SystemProfileId == SYSPRF_SYSGDISP_CURRENT_IDLE_SCREEN)
                {
                    This->Private->m_IdleScreenType = QueryIdleScreenType(This);
					if(This->Private->m_IdleScreenType == IDLE_TYPE_CALENDAR)
					{
						/* Now SI Pane is showing, hide the calendar */
						if(This->Private->m_SIPaneShowed == TRUE)
						{
							This->Private->m_CalendarHide = TRUE;
							This->Private->m_IdleScreenType = IDLE_TYPE_NORMAL;
						}
						else
						{
							UpdateCalendar(This);
							UpdateShortcuts(This);
						}
					}
					else
					{
						/* Destroy calendar */
						This->Private->m_CalendarHide = FALSE;
						UpdateCalendar(This);
						UpdateShortcuts(This);
					}
                }
            }
            break;
		case EVID_ADD_DESKTOP_SHORTCUT_REQ:
			{
				MsApiReadDesktopShortcuts (This->Private->m_DesktopShortcutsPointer);				
				/* 3G desktop changed */
				FsmIfAddEvent (This, e_Refresh);
			}
			break;

        case EVID_NWRK_CELL_SEARCH_CNF:
            /* MC Cell search confirm */
            {
                TS_MC_CELL_SEARCH_CNF_DATA* data = EVM_GET_DATA_PTR( EVID_NWRK_CELL_SEARCH_CNF, EventPtr);

                if (data->data.enResult == AMC_CELL_FOUND)
                {
                    FsmIfAddEvent (This, e_3GCellFound);
                }
                else if (data->data.enResult == AMC_CELL_NOT_FOUND)
                {
                    FsmIfAddEvent (This, e_3GCellNotFound);
                }
                else if (data->data.enResult == AMC_CELL_SEARCH_NG_DI)
                {
                    FsmIfAddEvent (This, e_ModeChangeFailure);
                }
                else
                {
                    /* AMC_CELL_SEARCH_NG_NO */
                    /* Go back directly without warning */
                    FsmIfAddEvent (This, E_CANCEL);
                }
            }
            break;
        
        case EVID_NWRK_ATTACH_FAIL_NTF:
            if(!This->Private->m_bAttachFailDisplaying)
                FsmIfAddEvent (This, e_NwrkAttachFail);
            break;
            
        case EVID_NWRK_AREA_MODE_CHG_CNF:
            /* MC mode change confirm */
            {
                TS_MC_MODE_CHG_CNF_DATA* data = EVM_GET_DATA_PTR( EVID_NWRK_AREA_MODE_CHG_CNF, EventPtr);

                if (data->data.wResult == AMC_MODE_CHG_OK)
                {
                    /* do nothing */                  
                }
                else if (data->data.wResult == AMC_MODE_CHG_NG_DISP)
                {
                    FsmIfAddEvent (This, e_ModeChangeFailure);
                }
                else
                {
                    /* AMC_MODE_CHG_NG_NONDISP */
                    FsmIfAddEvent (This, E_CANCEL);
                }
            }
            break;
                   
        case EVID_NWRK_AREA_MODE_IND:
            /* MC mode change indication */
            {
                TS_MC_MODE_IND_DATA* data = EVM_GET_DATA_PTR( EVID_NWRK_AREA_MODE_IND, EventPtr);
                
                /* Jodie modify begin for ULT-PR1-8115 */
                if (data->ModeData.enType == 0xff && data->ModeData.enMode == 0xff)
                    FsmIfAddEvent (This, e_ModeChangeFailure);
                else
                {                                
                    /* Write down the current new mode and old mode */
                    This->Private->m_MCOldMode = MCMode[data->OldData.enType-1][data->OldData.enMode-1];
                    This->Private->m_MCNewMode = MCMode[data->ModeData.enType-1][data->ModeData.enMode-1];

                    /* Show the message box */
                    FsmIfAddEvent (This, e_ModeChangeSuccess);
                }                    
                /* Jodie modify end for ULT-PR1-8115 */
            }
			break;

			
		case EVID_IDLE_LOAD_DIGITS_SCREEN:
			FsmIfAddEvent (This, e_DigitsPresent);
			break;
		case EVID_EXTRACT_NUMBER_NTF:
			{
				_AM_HISTORY_REQ req_param;
				TS_PHONE_NUMBER PhoneNumber;

				/* Init phone number */
				LibPhoneNumInit( &PhoneNumber );
				/*Get phone number from call logs*/
				PhoneNumber = *EVM_GET_DATA_PTR( EVID_EXTRACT_NUMBER_NTF, EventPtr);		
				/* Goto input screen */
				LibPhoneNumToUtf( &PhoneNumber, &This->Private->m_IdleString.utf, TS_PHONE_DIS_ALL );

				/* Make sure only in the normal status to make the idle SM change */
				if (This->Private->m_IdleStatus != IDLE_CALL_STATUS)
				{
					XmTextEditSetString(This->Private->m_TextLabel, This->Private->m_IdleString.buf);
					XtVaSetValues( This->Private->m_TextLabel, XmNcursorPosition, utflen(&This->Private->m_IdleString.utf), NULL);
					FsmIfAddEvent(This, e_DigitsPresent);		

					/* Raise Idle*/
					req_param.ap_ID = APM_APP_IDLE_ID ;
					req_param.pos = 0;
					Am_History_RaiseReq (&req_param) ;
				}
			}				
			break;

        case EVID_CPM_ALS_UPDATE_IND:
            {
                ELIB_ICON_DATA icon_data;
                TS_ALS_LINE_DATA * Data = EVM_GET_DATA_PTR( EVID_CPM_ALS_UPDATE_IND, EventPtr);
                //TODO: update the icon
	          	MuiSSIfNotifyIdleChangeDivertIcon();
                if(Data->AlsLine == ALS_LINE_2)
                {
                    icon_data.icon_no = ELIB_DSP_ICON_ALS_2;
                }
                else
                {
                    icon_data.icon_no = ELIB_DSP_ICON_ALS_1;
                }

                icon_data.select = ELIB_DSP_ICON_ON;
                icon_data.color = NULL;
                Elib_DSP_System_Icon(MuiAppGetApId(This), &icon_data);
            }
            break;
            
		case EVID_IDLE_LOAD_MENU_SCREEN:
			{
				This->Private->m_MenuHighLightItem = *(UINT*)EVM_GET_DATA_PTR( EVID_IDLE_LOAD_MENU_SCREEN, EventPtr);
				FsmIfAddEvent(This, e_GotoMenu);
			}
            break;

        case EVID_IDLE_ADD_MISSED_CALL_SHORTCUT:
            {
                This->Private->m_MissedCallShortcut = TRUE;
                This->Private->m_MissedCallDisplayed = MISSED_CALL_NORMAL;
                This->Private->m_ItemToDelete = -1;
                UpdateShortcuts (This);
                UpdateIdleMissedCall(This); 

#ifdef CHW_SUBLCD
    			Elib_DSP_BL_Dsp( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF, NULL, NULL, 0);
#else
#endif 

            }
			break;

		case EVID_IDLE_LOAD_DIVERT_ICON:
			{
				

				if( !MuiSSIfIsExistDivert( &This->Private->m_Session.Session, &This->Private->m_AlsStatus ) )
				{
					This->Private->m_AlsStatus = 0xFF;
				}

				UpdateAlsSetting( This );
			}
			break;
		case EVID_IDLE_AUTOCHECK_FINISHED:
			{
				if( This->Private->m_SsInterfaceClass != NULL )
				{
					FsmIfDeleteInstance(This->Private->m_SsInterfaceClass);
					This->Private->m_SsInterfaceClass = NULL;
				}
				
			}	
			break;
		case EVID_LNG_CURRENT_CHANGED_NTF:
			{
				UpdateServiceScreen(This);
			}
			break;

		case EVID_SCM_ENABLE_DIAL_LOCK_CNF: 
			/* Dial lock */
			This->Private->m_bDialLockEnable = TRUE;
           	/* grab the long pressing menu key event */
           	Elib_KEY_LongHook_Set (APM_APP_IDLE_ID, XK_KEY_FUNCTION, 10, XK_KEY_FUNCTION, 0);
			if(This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
			{
				UpdateKeypadLockIcon( This );
	           	MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[DIAL_LOCK_1].SkText, MUI_DLG_TEXT_LEFT );
	           	MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[DIAL_LOCK_2].SkText, MUI_DLG_TEXT_RIGHT );
           		/* Disable menu key */
				if(FMui_Mltw_ActiveInfoReq(NULL) == APM_APP_IDLE_ID)
				{
					wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKSTOP );
				}
	        }
			break;

		case EVID_SCM_DISABLE_DIAL_LOCK_CNF:
			/* Dial unlock */
			This->Private->m_bDialLockEnable = FALSE;
			Elib_KEY_LongHook_Clr(APM_APP_IDLE_ID, XK_KEY_FUNCTION);
			wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKRESTART );
			if(This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
			{
				UpdateKeypadLockIcon( This );
	           	MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[NORMAL_SCREEN_1].SkText, MUI_DLG_TEXT_LEFT );
	           	MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[NORMAL_SCREEN_2].SkText, MUI_DLG_TEXT_RIGHT );
	        }
			break;

#ifdef CHW_SIDEKEY		
		case EVID_IDLE_SIDE_KEY_LOCK:
			/* Side key lock status changed */
			Elib_KEY_Get_SideKeyLockMode( MuiAppGetApId(This), &This->Private->m_KeyPadLocked );
			UpdateKeypadLockIcon(This);
			break;
#endif

		case EVID_CALL_LOG_VOICE_CALL:
			if( This->Private->m_MissedCallShortcut)
			{
				This->Private->m_MissedCallShortcut = FALSE;
				This->Private->m_MissedCallDisplayed = MISSED_CALL_NORMAL;
				UpdateShortcuts (This);
				UpdateIdleMissedCall(This); 
#ifdef CHW_SUBLCD
				/* Erase missing call display in sub led */
				Elib_DSP_BL_Erase( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF );
				Elib_DSP_BL_Erase( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF_DSP );
#else
#endif
			}
			break;
			
		case EVID_CPM_EMERGENCY_CALL_STATE_NTF:
			{
				TS_CPM_EMERGENCY_STATE_DATA* data = EVM_GET_DATA_PTR (EVID_CPM_EMERGENCY_CALL_STATE_NTF, EventPtr);
				if (data->InEmerState)
				{
					Clm_Conflict_Inquire( MuiAppGetApId(This), CLM_RET_INSTANT, CLM_INQ_START_ITEM, 
											CLM_ITEM_EMERGENCY, CLM_FIRST_INSTRUCTIONS_ACTION );
				}
				else
				{
					Clm_Conflict_Inquire( MuiAppGetApId(This), CLM_RET_INSTANT, CLM_INQ_END_ITEM, 
											CLM_ITEM_EMERGENCY, CLM_FIRST_RESULT_CONFLICT );
				}
			}
			break;
	
		case EVID_RM_REQ_REJ:
		case EVID_RM_REQ_REJ_NTF:
			/*VT is rejected */
			{
				TS_RESOURCE_REJ_RESULT* data;
				if(EventId == EVID_RM_REQ_REJ)
				{
					data = EVM_GET_DATA_PTR (EVID_RM_REQ_REJ, EventPtr);
				}
				else
				{
					data = EVM_GET_DATA_PTR (EVID_RM_REQ_REJ_NTF, EventPtr);
				}

                /* Philip Kamoi 2003-10-29, add call to end request of VT call request */
                if(data->Data.ServiceId == SYSSR_CSVT_CREATE_MO_CONNECTION)
                {
                    /* end the CLM Transmit for MO CSVT request */
                    Clm_Conflict_Inquire( MuiAppGetApId(This),
                        CLM_RET_INSTANT,
                        CLM_INQ_END_ITEM,
                        CLM_ITEM_AV_TRANSMIT_P,
                        CLM_FIRST_RESULT_CONFLICT );
                }           

				if( SYSRM_SVC_NOT_SUPPORTED_BY_2G == data->Cause )
				{
					TS_PHONE_NUMBER PhoneNumber;
					LibPhoneNumInit( &PhoneNumber );
					if(data->Info.CsvtResultInfo.IsTelNumber)
					{
						This->Private->m_bTelNumberAdress = TRUE;
						PhoneNumber = data->Info.CsvtResultInfo.PhoneNumber;
						LibPhoneNumToUtf( &PhoneNumber, &This->Private->m_IdleString.utf, TS_PHONE_DIS_ALL );
					}
					else
					{
						This->Private->m_bTelNumberAdress = FALSE;
					}

					if(FMui_Mltw_ActiveInfoReq(NULL) != APM_APP_IDLE_ID)
					{
						_AM_HISTORY_REQ AmHistoryReq;
						AmHistoryReq.ap_ID = APM_APP_IDLE_ID;
						Am_History_RaiseReq(&AmHistoryReq);
						This->Private->m_bRaiseIdle = TRUE;
					}
					if(This->Private->m_bTelNumberAdress)
					{
						FsmIfAddEvent(This, e_VideoControl);
					}
					else
					{
						FsmIfAddEvent(This, e_UrlVideoControl);
					}
				}
				
				/* Show error message when receive fdn restricted event.*/
				if(data->Cause == SYSRM_SVC_FDN_RESTRICTED 
					&& data->Data.ServiceId == SYSSR_CSVT_CREATE_MO_CONNECTION)
				{
					FsmIfAddEvent(This, e_FdnRestricted);
				}
			}
			break;
		
		case EVID_RESET_ALL:
			FormatDesktopQuickMenuData( This );
			This->Private->m_MissedCallShortcut = QueryIdleMissedCall(This);
			This->Private->m_bDialLockEnable = QueryDialLockStatus(This);
			Elib_KEY_Get_SideKeyLockMode( APM_APP_IDLE_ID, &This->Private->m_KeyPadLocked );
			This->Private->m_IdleScreenType = QueryIdleScreenType(This);
			UpdateServiceScreen(This);
			break;
			
		case EVID_RESET_DEFAULT:
			This->Private->m_MissedCallShortcut = QueryIdleMissedCall(This);
			This->Private->m_bDialLockEnable = QueryDialLockStatus(This);
			Elib_KEY_Get_SideKeyLockMode( APM_APP_IDLE_ID, &This->Private->m_KeyPadLocked );
			This->Private->m_IdleScreenType = QueryIdleScreenType(This);
			UpdateServiceScreen(This);
			break;
        case EVID_RM_REQUEST_UPDATE_NTF:
        //A VT/VC call has been morphed to Emergency call
            {
                TS_RESOURCE_REQ_STATUS_DATA *data =EVM_GET_DATA_PTR (EVID_RM_REQUEST_UPDATE_NTF, EventPtr);
                if(data->Data == SYSRM_CLASSIFIED_EMGNCY_CSV 
					&& data->ServiceId == SYSSR_CSVT_CREATE_MO_CONNECTION)
                {//just for VT was morphed to Emergency call. The VC case has been handled before App call interface to setup EC.
                	
                    /* end the CLM Transmit for MO CSVT request */
                    Clm_Conflict_Inquire( MuiAppGetApId(This),
                        CLM_RET_INSTANT,
                        CLM_INQ_END_ITEM,
                        CLM_ITEM_AV_TRANSMIT_P,
                        CLM_FIRST_RESULT_CONFLICT );

			/* Start the CLM Transmit for Emergency call setup request*/
                    Clm_Conflict_Inquire( MuiAppGetApId (This),
                        CLM_RET_INSTANT, 
                        CLM_INQ_START_ITEM,
                        CLM_ITEM_TRANSMIT_EMERGENCY_SETUP,
                        CLM_FIRST_INSTRUCTIONS_ACTION );


                }
            }
            break;
		case EVID_CPM_SIM_REMOVED_NTF:
			FsmIfAddEvent(This, e_SimRemoved);
			This->Private->m_bSimRemoved = TRUE;
			break;

        /* SAT text is coming */
        case EVID_IDLE_USAT_IDLE_MODE_TEXT_CHANGE:
            {
                SataGetSATIdleText (&This->Private->m_SATText.utf, &This->Private->m_SATIcon);
                UpdateSATPane (This);
            }

		default:
			break;
    }
}
END_PUBLIC_API_CALLBACK

/*******************************************************************************
*
* FUNCTION: XxxIfLoadDigitsScreen
*
* $UniqueID:3EDAB908005E$
*
* $Parm: void$
* <Please enter description here>
* $End$
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
/*$Function:Idle Provider Interface:3D91610A024E$*/
void MuiIdleIfLoadDigitsScreen(  void )
{
#if 0 /* any app pressing send key, dial screen is displayed */
	/* Switch to Number dial screen */
	{
		TI_EVID_NULL_STRUCT A;
		A.Id = EVID_IDLE_LOAD_DIGITS_SCREEN;
		A.Size = 0;
		A.Ptr = NULL;

		MsApiEvBroadcastEventInd( NULL, &A );
	}
#endif
}

/*******************************************************************************
*
* FUNCTION: XxxIfLoadDigitsScreen
*
* $UniqueID:3EDAB908005E$
*
* $Parm: void$
* <Please enter description here>
* $End$
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
/*$Function:Idle Provider Interface:3D91610A024E$*/
void MuiIdleIfAutoCloseDigitsScreen(  TS_APM_APP_ID ApplicationId )
{
	BOOLEAN flag = TRUE;
	MuiAppSendDataToAppId(APM_APP_IDLE_ID, &flag, sizeof(flag));
}

/*******************************************************************************
*
* FUNCTION: XxxIfRegisterClasses
*
* $UniqueID:3D932189014F$
*
* $Parm: void$
* <Please enter description here>
* $End$
*
* $Description$
* This registers all the Generic FSM classes used within this domain. This
* function is called by the main krusty register classes which is in turn
* called first thing during power up,
* 
* This function returns the Generic FSM class Id for the domains interface
* class. If none exists then you can return TI_CLASS_NULL_ID
* $End$
*******************************************************************************/
/*$Function:GFSM Consumer Interface:3D93201C02D1$*/
TI_GENERIC_CLASS_ID MuiIdleIfRegisterClasses(  void )
{
    REGISTER_CLASS( C_MUI_MODE );
    REGISTER_CLASS( C_MUI_EMERGENCY_CALL );
    return REGISTER_CLASS( TI_MUI_IDLE_INTERFACE );
}

/*******************************************************************************
*
* MACRO: mtws_DownKeyPressed
*
* $UniqueID:3EA3B68702CC$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_DownKeyPressed )
{
	TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;
	
	if(This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
	{
		if (This->Private->m_CurrentSelectedItem != -1)
		{
			/* Handle selecting rectangle movements here */
			FsmIfAddEvent (This, e_Down);
		}
		else
		{
			if(MuiConflictInquire(APM_APP_IDLE_ID, APM_APP_PBOOK_ID, 0)==CLM_RESULT_PERMIT)
			{
				MuiPbkIfStartSearchingPhonebook(APM_APP_IDLE_ID);
			}
		}
	}
	else
	{
		Data->processed = FALSE;
	}
}
END_PRIVATE_MTWS_CALLBACK


/*******************************************************************************
*
* MACRO: mtws_MyMenu
*
* $UniqueID:3EAC81930002$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_MyMenu )
{
	TI_EVID_NULL_STRUCT EventData;
	XmTreeNodeCallbackStruct *Data = (XmTreeNodeCallbackStruct *)call_data;
    if ( Data->reason & XmTREE_NODE_CR_BROWSE_SELECT )
    {
		if(g_SIMM_PBK_READY_FLG == 0)
		{
			FsmIfAddEvent(This, e_WaitMainMenu);
		}
		else
		{
		/* Activate Main Menu Component */
		if(MuiConflictInquire(APM_APP_IDLE_ID, APM_APP_MENU_ID, 0)==CLM_RESULT_PERMIT)
		{ 
			_AM_CONTROL_REQ req_param; 
			req_param.src_ap      = MuiAppGetApId(This); 
			req_param.info        = 0; 
			req_param.param       = NULL; 
			req_param.return_mode = AM_RETURN_MODE_WAIT_ACT; 
			req_param.watch_time  = 5; 
			req_param.dst_ap      = APM_APP_MENU_ID; 
			wMui_MLTW_Control_StartReq( &req_param ); 
		
			/* Request Main Menu to show My Menu through ENM */
			EventData.Id   = EVID_MY_MENU_REQ;
			EventData.Ptr  = NULL;
			EventData.Size = 0;
			MsApiEvBroadcastEventInd (NULL, &EventData);
		} 
		
		/* Unload the menu */
		FsmIfAddEvent (This, E_DONE);
		}
	}
}
END_PRIVATE_MTWS_CALLBACK


/*******************************************************************************
*
* MACRO: mtws_UpKeyPressed
*
* $UniqueID:
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$

  *******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_UpKeyPressed )
{
	TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;
	
	if(This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
	{
	    if (This->Private->m_CurrentSelectedItem != -1)
		{
			/* Handle selecting rectangle movements here */
			FsmIfAddEvent (This, e_Up);
		}
		else
		{
			if(MuiConflictInquire(APM_APP_IDLE_ID, APM_APP_PBOOK_ID, 0)==CLM_RESULT_PERMIT)
			{
				MuiPbkIfStartSearchingPhonebookFocusLast(APM_APP_IDLE_ID);
			}
		}
	}
	else
	{
		Data->processed = FALSE;
	}
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_SwitchKeyPressed
*
* $UniqueID:
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$

  *******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_SwitchKeyPressed )
{
	TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;
	
	if(This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
	{
	    //get the lastest outgoing call from call logs
	    TS_DATABASE_CALL_LOG_RECORD* TempPtr = xAlloc( sizeof(TS_DATABASE_CALL_LOG_RECORD) );
	    TS_CMD_STATUS  CmdStatus    = CMST_OK;
	    
	    
	    CmdStatus = MuiGetlatestCall( TempPtr, SYSDM_REDIAL_LOG );
	    
	    //make a MO call from Idle with that number
	    if(CmdStatus == CMST_OK)
	    {
            switch( TempPtr->ConnectionType )
            {
                case SYSCN_NORM_VOICE_CALL: /*CSV*/
            	case SYSCN_EMGNCY_VOICE_CALL:/*EC*/
			    case SYSCN_VIDEO_CALL: /*CSVT*/
                    if( (TempPtr->UrlOrNumber == SYSCSVT_AD_TEL_NUMBER) //There is a number in the record
                        && !LibPhoneNumIsEmpty(&TempPtr->PhoneNum.Number) )
	                    {
	                        char NumberBuffer[TS_PHONE_NUMBER_LEN];

				            if (TempPtr->PhoneNum.Number.Ton == TON_INTERNATIONAL)
				            {
					            NumberBuffer[0]='+';
					            LibPhoneNumToUtf8( &TempPtr->PhoneNum.Number,
										            NumberBuffer+1,
										            sizeof(NumberBuffer)-1,
										            TS_PHONE_DIS_CALL );
				            }
				            else
				            {
					            LibPhoneNumToUtf8( &TempPtr->PhoneNum.Number, NumberBuffer, sizeof(NumberBuffer), TS_PHONE_DIS_CALL );
				            }
				
				            CmdStatus = MuiCsvSetDialString( This->Private->m_VoiceCallsClass, NumberBuffer);//TempPtr->PhoneNum.Number.A );
	                    }
			        else
			            {
				            FsmIfAddEvent(This, e_RedialError);
			            }

			break;
                default: /*Do not redial if it's other types of call log*/
                    FsmIfAddEvent(This, e_RedialError);
                    break;
            }
	
	    }
	
	    xFree(&TempPtr);
	}
	else
	{
		Data->processed = FALSE;
	}
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* FUNCTION: SetSelectShortcut
*
* $UniqueID:$
*
* $Description$
* Set the specified shortcut selected, if failed return FALSE
* $End$
*******************************************************************************/
/*$Function$*/
static BOOLEAN SetSelectedShortcut( TI_MUI_IDLE_INTERFACE* This, int ShortcutNo )
{
    int ShortcutNum = GetShortcutNum(This);
	int ShortcutTreeIdx = -1;
	
	/* invalid shortcut no? */
	/* if is it a tree idx, record the tree index first */
	if ((This->Private->m_IdleScreenType != IDLE_TYPE_NORMAL) ||
		(This->Private->m_SIPaneShowed))
	{
		if (ShortcutNo > 0)
		{
			ShortcutTreeIdx = ShortcutNo-1;
		}
	}
	else
	{
		ShortcutTreeIdx = ShortcutNo;
	}

	/* if the tree index is outside of the current tree shortcuts number */
	if( ShortcutTreeIdx >= ShortcutNum )
	{
		/* may be it is the missed call */
		if (!ItIsMissedCallShortcut (This, ShortcutNo))
		{
			return FALSE;
		}
	}
		
    /* deselect at first */
    if (This->Private->m_CurrentSelectedItem == 0)
    {
        switch (This->Private->m_IdleScreenType)
        {
        case IDLE_TYPE_NORMAL:
            {
                /* Deselect SI Pane */
                /* The red rectangle around the SI Msg Label should be erased*/
                if (This->Private->m_SIPaneShowed)
                {
#if 0
                    int n = 0;
                    Arg args[1];
                    
                    XtSetArg (args[n], XmNshadowThickness, 0); n++;           
                    XtSetValues (This->Private->m_SIPane, args, n);
#else
                    XtUnmapWidget (This->Private->m_SIPaneBG);
#endif
                }
                else
                {
                    if (This->Private->m_ShortcutTree != NULL)
                    {
                        int n = 0;
                        Arg args[2];
                        
                        XtSetArg (args[n], XmNselectItem, -2); n++;
                        XtSetValues (This->Private->m_ShortcutTree, args, n);
                    }
                }
            }
            break;
            
        case IDLE_TYPE_CALENDAR:
            /* Deselect calendar */
            {
                int n = 0;
                Arg args[3];
                
#if 0
                /* draw the border of calendar */
                XtSetArg (args[n], XmNshadowThickness, 1); n++;
                XtSetArg (args[n], XmNtopShadowColor, 0x0000);n++;
                XtSetArg (args[n], XmNbottomShadowColor, 0x0000);n++;
#else
                XtSetArg (args[n], XmNshadowThickness, 0); n++;
#endif
                XtSetValues (MuiAppGetDlgItem(This->Private->m_Dlg, WIG_CAL_CONTAINER), args, n);
                
                if(This->Private->m_SIPaneShowed)
                {
                    UpdateWallpaper (This);
                    MuiAppIfOptionMenuShow( This, TRUE );
                    FsmIfAddEvent(This, E_DONE);
                    This->Private->m_CalendarHide = TRUE;
                    This->Private->m_IdleScreenType = IDLE_TYPE_NORMAL;
                    SetSelectedShortcut (This, -1);
                    UpdateCalendar(This);
                    UpdateShortcuts(This);
                }
                break;
            }           

        }
    }
    /* Deselect the tree widget */
    else
    {
        if (This->Private->m_ShortcutTree != NULL)
        {
            int n = 0;
            Arg args[2];
            
            XtSetArg (args[n], XmNselectItem, -2); n++;
            XtSetValues (This->Private->m_ShortcutTree, args, n);
        }
    }

    /* if shortcut is -1, it means select nothing*/
    if (ShortcutNo == -1)
    {
        This->Private->m_CurrentSelectedItem = -1;
        if(This->Private->m_bDialLockEnable == TRUE )
        {
           	MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[DIAL_LOCK_1].SkText, MUI_DLG_TEXT_LEFT );
           	MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[DIAL_LOCK_2].SkText, MUI_DLG_TEXT_RIGHT );
        }
#ifdef CSW_SUPPORTKEYLOCK
		else if( This->Private->m_bKeyLockStatus )
		{
			MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[KEYPAD_LOCK_1].SkText, MUI_DLG_TEXT_LEFT );
			MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[KEYPAD_LOCK_2].SkText, MUI_DLG_TEXT_RIGHT );
		}
#endif
        else
        {
           	MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[NORMAL_SCREEN_1].SkText, MUI_DLG_TEXT_LEFT );
           	MuiAppIdleSetDlgTextId( This->Private->m_Dlg, SoftKeyData[NORMAL_SCREEN_2].SkText, MUI_DLG_TEXT_RIGHT );
		}

		/* Hide the help line for shortcuts */
		XtUnmapWidget (This->Private->m_HelpLineLabel);
		XtMapWidget (This->Private->m_MfnLabel);
        return TRUE;
    }
	else
	{
		/* Hide the inactive state help area */
		XtUnmapWidget (This->Private->m_MfnLabel);
		XtMapWidget (This->Private->m_HelpLineLabel);
	}

    /* normal screen */
	if (This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL)
	{
		if (This->Private->m_ShortcutTree != NULL)
        {
            /* if there are SI messages and current user want to select SI Pane */
            if (This->Private->m_SIPaneShowed && ShortcutNo == 0)
            {
                /* A red rectangle should be drawn around the SI Msg Label*/
#if 0
                int n = 0;
                Arg args[3];
                
                XtSetArg (args[n], XmNshadowThickness, 1); n++;                    
                XtSetArg (args[n], XmNtopShadowColor, 0xfc20);n++;
                XtSetArg (args[n], XmNbottomShadowColor, 0xfc20);n++;
                XtSetValues (This->Private->m_SIPane, args, n);
#else
                XtMapWidget (This->Private->m_SIPaneBG);
#endif
                
                /* we Refresh the soft keys */
                MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_BLANK, MUI_DLG_TEXT_LEFT );
                MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_IDLE_KEY_REMOVE, MUI_DLG_TEXT_RIGHT );
                
                This->Private->m_CurrentSelectedItem = 0;
                
                /* Show the help line */
                MuiAppSetTextId (This->Private->m_HelpLineLabel, TXT_IDLE_SI_PANE_HELP_STRING);

                return TRUE;
            }
            /* set the focus to shortcuts */
            else
            {
                int n = 0;
                Arg args[1];
				int TreeIdx;
                
                if (This->Private->m_SIPaneShowed)
                {
                    TreeIdx = GetTreeIndexFromShortcutNo(ShortcutNo-1);
                }
                else
                {
                    TreeIdx = GetTreeIndexFromShortcutNo(ShortcutNo);
                }

				/* Set help line text */
				if (ItIsMissedCallTreeIndexShortcut(This, TreeIdx))
				{
					MuiAppSetTextId (This->Private->m_HelpLineLabel, WORD_GEN_SLC_MISSED_CALL);
				}
				else
				{
					TS_DATABASE_USER_DISPLAY_RECORD *tmp;					
					tmp = GetShortcutRecord (This, TreeIdx);
					if (tmp->FixedTextId != INVALID_WORD_ID)
                    {
                        MuiAppSetTextId (This->Private->m_HelpLineLabel, tmp->FixedTextId);
                    }
                    else
                    {
                        MuiAppSetText (This->Private->m_HelpLineLabel, tmp->AlphaTag.buf);
                    }
				}
                
				/* Set selecting rectangle */
				XtSetArg (args[n], XmNselectItem, TreeIdx); n++;
				XtSetValues (This->Private->m_ShortcutTree, args, n);
                
                This->Private->m_CurrentSelectedItem = ShortcutNo;

				/* Refresh softkeys */
				if (!This->Private->m_ShortcutMoving)
				{
					MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_IDLE_KEY_MOVE, MUI_DLG_TEXT_LEFT );
					MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_IDLE_KEY_REMOVE, MUI_DLG_TEXT_RIGHT );
				}
				else
				{
					MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_IDLE_KEY_PLACE, MUI_DLG_TEXT_LEFT );
					MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_BLANK, MUI_DLG_TEXT_RIGHT );
				}
				
                return TRUE;
            }
        }
	}
    /* The screen type is calendar*/
	else
	{
        /* select the calendar */
        if (ShortcutNo == 0)
        {
            int n = 0;
            Arg args[3];
            
            XtSetArg (args[n], XmNshadowThickness, 2); n++;
            XtSetArg (args[n], XmNtopShadowColor, 0xfc20);n++;
            XtSetArg (args[n], XmNbottomShadowColor, 0xfc20);n++;
            XtSetValues (MuiAppGetDlgItem(This->Private->m_Dlg, WIG_CAL_CONTAINER), args, n);

            This->Private->m_CurrentSelectedItem = 0;

            /* Show the help line */
            MuiAppSetTextId (This->Private->m_HelpLineLabel, TXT_IDLE_SCREENTYPE_CALENDAR);
            
			//set calendar softkey
			MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_BLANK, MUI_DLG_TEXT_LEFT );
			MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_BLANK, MUI_DLG_TEXT_RIGHT );
            return TRUE;
        }
        else
        /* set the focus to shortcuts */
        {
            int n = 0;
            Arg args[1];
            int TreeIdx = GetTreeIndexFromShortcutNo(ShortcutNo-1);
            
            XtSetArg (args[n], XmNselectItem, TreeIdx); n++;
            XtSetValues (This->Private->m_ShortcutTree, args, n);
            
            This->Private->m_CurrentSelectedItem = ShortcutNo;

			/* Refresh softkeys */
			if (!This->Private->m_ShortcutMoving)
			{
				MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_IDLE_KEY_MOVE, MUI_DLG_TEXT_LEFT );
				MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_IDLE_KEY_REMOVE, MUI_DLG_TEXT_RIGHT );
			}
			else
			{
				MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_IDLE_KEY_PLACE, MUI_DLG_TEXT_LEFT );
				MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_BLANK, MUI_DLG_TEXT_RIGHT );
			}

            /* Set help line text */
            if (ItIsMissedCallTreeIndexShortcut(This, TreeIdx))
            {
                MuiAppSetTextId (This->Private->m_HelpLineLabel, WORD_GEN_SLC_MISSED_CALL);
            }
            else
            {
                TS_DATABASE_USER_DISPLAY_RECORD *tmp;					
                tmp = GetShortcutRecord (This, TreeIdx);
                if (tmp->FixedTextId != INVALID_WORD_ID)
                {
                    MuiAppSetTextId (This->Private->m_HelpLineLabel, tmp->FixedTextId);
                }
                else
                {
                    MuiAppSetText (This->Private->m_HelpLineLabel, tmp->AlphaTag.buf);
                }
            }
			
            return TRUE;
        }
	}

	return FALSE;
}

/*******************************************************************************
*
* MACRO: a_MoveFocusUp
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_MoveFocusUp )
{
    int SelectedItem = This->Private->m_CurrentSelectedItem;
	int ShortcutNum = GetShortcutNum(This);
	int MissedCallIdx = GetMissedCallShortcutIndex(This);
	int RightMostLine0 = GetRightMostShortcutIndex(This, 0);
	int RightMostLine1 = GetRightMostShortcutIndex(This, 1);
    
    /* Normal Idle screen */
	if (This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL)
    {
        /* SI Pane showed */
        if (This->Private->m_SIPaneShowed)
        {
            /* Normal moving selecting rectangle */
			if (!This->Private->m_ShortcutMoving)
			{
				/* one of the shortcuts in the first line is selected, 
				 * move focus to SI Pane 
				 */
				if ((SelectedItem > 4) && (SelectedItem < 9))
				{
					SetSelectedShortcut (This, 0);
				}

				/* one of the shortcuts in second line is selected, move focus to upper
				 * shortcut if it is available
				 */
				if ((SelectedItem > 0) && (SelectedItem < 5))
				{
					/* can not move focus in empty cell */
/* Philip Kamoi 1028 Start */
					if (!SetSelectedShortcut (This, SelectedItem+4))
                    {
                        SetSelectedShortcut (This, 0);
                    }
/* Philip Kamoi 1028 End   */
				}
			}
			else
			{
				/* Moving shortcuts */

				/* one of the shortcuts in the first line is selected, 
				 * move focus to SI Pane 
				 */
				if ((SelectedItem > 4) && (SelectedItem < 9))
				{
					SetSelectedShortcut (This, 0);
				}
				
				/* one of the shortcuts in second line is selected, move shortcut
				 * to upper shortcut if it is available
				 */
				if ((SelectedItem > 0) && (SelectedItem < 5))
				{
					/* can not move focus in empty cell and upper 
					 * shortcut is not missed call shortcut
					 */
					if ((SelectedItem+4 <= RightMostLine1) &&
						!ItIsMissedCallShortcut (This, SelectedItem+4))
					{
						SwapUserDisplayRecord (This, SelectedItem-1, SelectedItem+3);
						SetSelectedShortcut (This, SelectedItem+4);
					}
				}
			}
        }
        else
        {
            /* Normal moving selecting rectangle */
			if (!This->Private->m_ShortcutMoving)
			{
				/* one of the shortcuts in the first line is selected, 
				 * move focus down to second line to support wrapper 
				 */
				if ((SelectedItem > 3) && (SelectedItem < 8))
				{
                    /* Do not support wrapper */
                    return;
				}

				/* one of the shortcuts in second line is selected, move focus to upper
				 * shortcut if it is available
				 */
				if ((SelectedItem >= 0) && (SelectedItem < 4))
				{
/* Philip Kamoi 1028 Start */
					if (!SetSelectedShortcut (This, SelectedItem+4))
                    {
                        SetSelectedShortcut (This, 0);
                    }
/* Philip Kamoi 1028 End   */
				}
			}
			else
			{
				/* Moving shortcuts */
			
					/* one of the shortcuts in the first line is selected, 
					 * move shortcut down to second line to support wrapper 
					 */
					if ((SelectedItem > 3) && (SelectedItem < 8))
					{
                        /* Do not support wrapper */
                        return;
					}

					/* second line shortcuts is ready to move
					 * can not move focus in empty cell and upper 
					 * shortcut if it is not missed call shortcut
					 */
					if ((SelectedItem >= 0) && (SelectedItem < 4))
					{
						if ((SelectedItem+4 <= RightMostLine1) &&
							!ItIsMissedCallShortcut (This, SelectedItem+4))
						{
							SwapUserDisplayRecord (This, SelectedItem, SelectedItem+4);
							SetSelectedShortcut (This, SelectedItem+4);
						}
					}
			}
        }
    }
    /* Calendar mode */
    else
    {
        /* only when the focus is on tree shortcuts, move focus to calendar */
		if (SelectedItem != 0)
        {
            if (!This->Private->m_ShortcutMoving)
            {
                SetSelectedShortcut (This, 0);
            }
        }
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_MoveFocusDown
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_MoveFocusDown )
{
    int SelectedItem = This->Private->m_CurrentSelectedItem;
	int ShortcutNum = GetShortcutNum(This);
	int MissedCallIdx = GetMissedCallShortcutIndex(This);
	int RightMostLine0 = GetRightMostShortcutIndex(This, 0);
	int RightMostLine1 = GetRightMostShortcutIndex(This, 1);
	
    if (This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL)
    {
		/* SI Pane showed */
        if (This->Private->m_SIPaneShowed)
        {
            /* Normal moving selecting rectangle */
			if (!This->Private->m_ShortcutMoving)
			{
				/* one of the shortcuts in the second line is selected, 
				 * move focus to SI Pane 
				 */
				if ((SelectedItem > 0) && (SelectedItem < 5))				
				{
                    /* Do not support wrapper */
                    return;
				}
				
				/* one of the shortcuts in first line is selected, move focus to lower
				 * shortcut if it is available
				 */
				if ((SelectedItem > 4) && (SelectedItem < 9))
				{
					SetSelectedShortcut (This, SelectedItem-4);
				}
				
				/* if SI Pane is selected, move focus to first of the second line 
				 * if the first of the second line is not available, move focus to
				 * first line, if first shortcut of first line is not available, do
				 * not move focus
				 */
				if (SelectedItem == 0)
				{
                    if (MissedCallIdx > 0 )
                    {
                        SetSelectedShortcut(This, MissedCallIdx);
                    }
                    else
                    {
                        if (!SetSelectedShortcut(This, 5))
                        {
                            SetSelectedShortcut (This, 1);
                        }
                    }
				}
			}
			else
			{
				/* Moving shortcuts, only selected shortcut is on the second line is legal
				 * we need not support wrapper because SI pane cannot be moved to
				 */
				if ((SelectedItem > 4) && (SelectedItem < 9))
				{
					SwapUserDisplayRecord (This, SelectedItem-1, SelectedItem-5);
					SetSelectedShortcut (This, SelectedItem-4);
				}
			}
        }
        else
        {
            /* Normal moving selecting rectangle */
			if (!This->Private->m_ShortcutMoving)
			{
				/* one of the shortcuts in the second line is selected, 
				 * move focus to first line 
				 */
				if ((SelectedItem >= 0) && (SelectedItem < 4))				
				{
                    /* Do not support wrapper */
                    return;
				}
				
				/* one of the shortcuts in first line is selected, move focus to lower
				 * shortcut if it is available
				 */
				if ((SelectedItem > 3) && (SelectedItem < 8))
				{
					SetSelectedShortcut (This, SelectedItem-4);
				}
				
			}
			else
			{
				/* Moving shortcuts, only selected shortcut is on the second line is legal */
				if ((SelectedItem > 3) && (SelectedItem < 8))
				{
					SwapUserDisplayRecord (This, SelectedItem, SelectedItem-4);
					SetSelectedShortcut (This, SelectedItem-4);
				}
				
				/* Moving shortcuts, from first line to second line to support wrapper */
				if ((SelectedItem >= 0) && (SelectedItem < 4))
				{
                    /* Do not support wrapper */
                    return;
				}
			}
		}
	}
	/* Calendar Screen */
	else
	{
		if (!This->Private->m_ShortcutMoving)
		{
			/* Calendar selected */
			if (SelectedItem == 0)
			{
                if (MissedCallIdx > 0 )
                {
                    SetSelectedShortcut(This, MissedCallIdx);
                }
                else
                {
                    SetSelectedShortcut (This, 1);
                }
			}
		}
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_MoveFocusLeft
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_MoveFocusLeft )
{
	int SelectedItem = This->Private->m_CurrentSelectedItem;
	int ShortcutNum = GetShortcutNum(This);
	int MissedCallIdx = GetMissedCallShortcutIndex(This);
	int RightMostLine0 = GetRightMostShortcutIndex(This, 0);
	int RightMostLine1 = GetRightMostShortcutIndex(This, 1);
	
	/* Normal Idle state */
	if ((This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL ) &&
		(!This->Private->m_SIPaneShowed))
	{
		if (!This->Private->m_ShortcutMoving)
		{
			/* if it is the second line left most shortcut */
			if (SelectedItem == 0)
			{
				/* Support left wrapper */
                int max = RightMostLine1>RightMostLine0? RightMostLine1:RightMostLine0;
                SetSelectedShortcut (This, max);
			}
			else
			{
				/* Normal move left */
				SetSelectedShortcut(This, SelectedItem-1);
			}
		}
		/* Shortcut Moving in Normal mode without SI Pane */
		else
		{
			/* if it is the second line left most shortcut */
			if (SelectedItem == 0)
			{
				/* first line left wrapper, if it is not missed call
				 * shortcut, support left wrapper
				 */
                int max = RightMostLine1>RightMostLine0? RightMostLine1:RightMostLine0;
                
                /* if it is missed call */
                if (max == MissedCallIdx)
                {
                    max--;
                }

                if (max >= 0)
                {
                    SwapUserDisplayRecord (This, 0, max);
                    SetSelectedShortcut (This, max);
                }
			}
			else
			{
				/* Normal move left */
				SwapUserDisplayRecord (This, SelectedItem, SelectedItem-1);
				SetSelectedShortcut(This, SelectedItem-1);
			}
		}
	}
	/* Calendar Mode or SI Pane showed */
    else
	{
        /* Not move shortcut */
		if (!This->Private->m_ShortcutMoving)
		{
            /* selecting SI Pane or Calendar, support left wrapper to first line */
            if (SelectedItem == 0)
            {
                return;
            }
            else if (SelectedItem == 1)
            {
                int max = RightMostLine1>RightMostLine0? RightMostLine1:RightMostLine0;
                SetSelectedShortcut (This, max);
            }
            /* Normal move left */
            else if ( SelectedItem != 0 )
            {
                SetSelectedShortcut (This, SelectedItem-1);
            }
		}
		else
		{
			/* Moving shortcut */
            if (SelectedItem == 1)
            {
				/* first line left wrapper, if it is not missed call
				 * shortcut, support left wrapper
				 */
				if (This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL)
				{
					int max = RightMostLine1>RightMostLine0? RightMostLine1:RightMostLine0;

                    /* if it is missed call */
                    if (max == MissedCallIdx)
                    {
                        max--;
                    }

                    if (max > 0)
                    {
                        SwapUserDisplayRecord (This, 0, max-1);
                        SetSelectedShortcut (This, max);
                    }
				}
                else
                {
                    if (MissedCallIdx == RightMostLine0)
                    {
                        if (RightMostLine0 > 0)
                        {
                            SwapUserDisplayRecord (This, 0, RightMostLine0-2);
                            SetSelectedShortcut (This, RightMostLine0-1);
                        }
                    }
                    else
                    {
                        SwapUserDisplayRecord (This, 0, RightMostLine0-1);
                        SetSelectedShortcut (This, RightMostLine0);
                    }
                }
            }
            else if ( SelectedItem != 0 )
            {
                /* Normal move left */
				SwapUserDisplayRecord (This, SelectedItem-1, SelectedItem-2);
				SetSelectedShortcut (This, SelectedItem-1);
            }
        }
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_MoveFocusRight
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_MoveFocusRight )
{
    int SelectedItem = This->Private->m_CurrentSelectedItem;
	int ShortcutNum = GetShortcutNum(This);
	int MissedCallIdx = GetMissedCallShortcutIndex(This);
	int RightMostLine0 = GetRightMostShortcutIndex(This, 0);
	int RightMostLine1 = GetRightMostShortcutIndex(This, 1);
	
	/* Normal Idle state */
	if ((This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL ) &&
		(!This->Private->m_SIPaneShowed))
	{
		/* Not move shortcut */
		if (!This->Private->m_ShortcutMoving)
		{
			/* first line support right wrapper */
			if (SelectedItem == RightMostLine0)
			{
				if (!SetSelectedShortcut(This, 4))
                {
                    SetSelectedShortcut(This, 0);
                }
			}
			/* second line support right wrapper */
			else if (SelectedItem == RightMostLine1)
			{
				SetSelectedShortcut(This, 0);
			}
			/* Normal move right */
			else
			{
				SetSelectedShortcut(This, SelectedItem+1);
			}
		}
		else
		{
			/* Moving shortcut, not move to missed call 
			 * shortcut
			 */
			/* first line support right wrapper */
			if (SelectedItem == RightMostLine0)
			{
                /* if there is shortcuts in upper line and the first is not missed call */
                if (4 != MissedCallIdx && 4 <= RightMostLine1)
                {
                    SwapUserDisplayRecord (This, RightMostLine0, 4);
                    SetSelectedShortcut(This, 4);
                }
                else
                {
                    SwapUserDisplayRecord (This, RightMostLine0, 0);
                    SetSelectedShortcut(This, 0);
                }
			}
			/* second line support right wrapper */
			else if (SelectedItem == RightMostLine1) 
            {
                SwapUserDisplayRecord (This, RightMostLine1, 0);
                SetSelectedShortcut(This, 0);
            }
			/* Normal move right */
			else if (SelectedItem+1 != MissedCallIdx)
			{
				SwapUserDisplayRecord(This, SelectedItem, SelectedItem+1);
				SetSelectedShortcut(This, SelectedItem+1);
			}
			/* Richard add move the shortcut before missed call */
			else if (SelectedItem+1 == MissedCallIdx)
			{
				SwapUserDisplayRecord (This, SelectedItem, 0);
				SetSelectedShortcut(This, 0);
			}
		}
	}
	/* Calendar Mode and SI Pane mode*/
    else
	{
		/* Not move shortcut */
		if (!This->Private->m_ShortcutMoving)
		{
			/* first line support right wrapper */
			if (SelectedItem == RightMostLine0)
			{
				if (This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL)
                {
                        /* if no shortcut in second line, wrap to first line */
                        if (!SetSelectedShortcut (This, 5))
                        {
                            SetSelectedShortcut (This, 1);
                        }
                }
                /* Calendar mode, move focus to first item when right most of first line is selected */
                else
                {
                    SetSelectedShortcut (This, 1);
                }
			}
			/* second line support right wrapper */
			else if (SelectedItem == RightMostLine1)
			{
				SetSelectedShortcut(This, 0);
			}
			/* Normal move right */
			else if (SelectedItem != 0)
			{
				SetSelectedShortcut(This, SelectedItem+1);
			}
		}
		else
		{
			/* Moving shortcut, not move to missed call 
			 * shortcut
			 */
			/* first line support right wrapper */
			if (SelectedItem == RightMostLine0)
            {
                if (This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL)
                {
                    if (5 <= RightMostLine1 && 5 != MissedCallIdx)
                    {
                        SwapUserDisplayRecord (This, RightMostLine0-1, 4);
                        SetSelectedShortcut (This, 5);
                    }
                    else if (1 != MissedCallIdx)
                    {
                        SwapUserDisplayRecord (This, RightMostLine0-1, 0);
                        SetSelectedShortcut (This, 1);
                    }
                }
                /* Calendar Mode */
                else if (1 != MissedCallIdx)
                {
                    SwapUserDisplayRecord (This, RightMostLine0-1, 0);
                    SetSelectedShortcut (This, 1);
                }
            }
			/* second line support right wrapper */
			else if ((SelectedItem == RightMostLine1))
			{
                if (1 != MissedCallIdx)
                {
                    SwapUserDisplayRecord (This, RightMostLine1-1, 0);
                    SetSelectedShortcut (This, 1);
                }
			}
			/* Normal move right */
			else if (SelectedItem+1 != MissedCallIdx)
			{
				SwapUserDisplayRecord(This, SelectedItem-1, SelectedItem);
				SetSelectedShortcut(This, SelectedItem+1);
			}
			else
			{
				SwapUserDisplayRecord (This, SelectedItem-1, 0);
				SetSelectedShortcut(This, 1);
			}
		}
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_RunShortcut
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_RunShortcut )
{
    _AM_CONTROL_REQ req_param;
    int ShortcutIdx;  
    char* TempPtr = NULL;
    
    if (This->Private->m_ShortcutMoving)
    {
        This->Private->m_ShortcutMoving = FALSE;
		MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_IDLE_KEY_MOVE, MUI_DLG_TEXT_LEFT );
		MuiAppIdleSetDlgTextId( This->Private->m_Dlg, TXT_IDLE_KEY_REMOVE, MUI_DLG_TEXT_RIGHT );
		
		/* Save it to database */
		MsApiWriteDesktopShortcuts(This->Private->m_DesktopShortcutsPointer);
        return;
    }
    
    if ( (This->Private->m_IdleScreenType != IDLE_TYPE_NORMAL) &&
         (This->Private->m_CurrentSelectedItem == 0))
    {
        if(MuiConflictInquire(APM_APP_IDLE_ID, AM_AP_ID_SCHEDULER_MAIN, 0) == CLM_RESULT_PERMIT )
        {
	        /* run calendar related program here */
	        req_param.src_ap      = MuiAppGetApId (This);
	        req_param.dst_ap	  = AM_AP_ID_SCHEDULER_MAIN;
	        req_param.info        = 1;
	        req_param.param       = NULL;
	        req_param.return_mode = AM_RETURN_MODE_WAIT;
	        req_param.watch_time  = 5;
	
	        wMui_MLTW_Control_StartReq( &req_param );
	    }
    }
    else
    {
        if (g_SIPaneActive((TI_GENERIC*)This, TRUE))
        {
			if(wMui_MLTW_GetAPLCnt() > 5)
			{
				FsmIfAddEvent(This, e_RunShortcutError);
			}
			else if (This->Private->m_SIMsgListNo >= 0)
            {
                _ELIB_SIP_DATA sip_data;
				int ret = Elib_SIP_Listdata_Get (MuiAppGetApId(This), This->Private->m_SIMsgListNo, &sip_data);

                if (sip_data.href[0] != '\0')
                {
                    if ( ret >= ELIB_SIP_DATA_MIN && ret <= ELIB_SIP_DATA_MAX 
                        && MuiConflictInquire(APM_APP_IDLE_ID, AM_AP_ID_BROW_MAIN, Browser_Start_URL) == CLM_RESULT_PERMIT )
                    {
                        _Sstring *url;
                        url = (_Sstring *)MM_malloc( sizeof(_Sstring) + ELIB_SIP_IND_HREF_MAX + 1 );
                        memset( url, 0, sizeof(_Sstring) );
                        url->_Length = ELIB_SIP_IND_HREF_MAX + 1;
                        url->_String = (char *)url + sizeof(_Sstring);
                        memcpy(url->_String, sip_data.href, ELIB_SIP_IND_HREF_MAX + 1);

                        /* run browser program here */
                        req_param.src_ap      = MuiAppGetApId (This);
                        req_param.dst_ap	  = AM_AP_ID_BROW_MAIN;
                        req_param.info        = Browser_Start_URL;
                        req_param.param       = url;
                        req_param.return_mode = AM_RETURN_MODE_WAIT;
                        req_param.watch_time  = AM_WATCH_MODE_MAX_TIME;

                        wMui_MLTW_Control_StartReq( &req_param );
                    }
                }
            }
        }
        else
        {
            if (This->Private->m_CurrentSelectedItem >= 0)
            {          
                int count = 0;
                req_param.src_ap      = MuiAppGetApId (This);
                
                /* Missed Call?*/
                if (ItIsMissedCallShortcut (This, This->Private->m_CurrentSelectedItem) )
                {
                    if(MuiConflictInquire(APM_APP_IDLE_ID, APM_APP_CALL_LOGS_ID, CL_MISSED_CALLS) == CLM_RESULT_PERMIT)
                    {
	                    req_param.dst_ap = APM_APP_CALL_LOGS_ID;
	                    req_param.info   = CL_MISSED_CALLS;
	                    req_param.param  = NULL;
			            req_param.return_mode = AM_RETURN_MODE_WAIT;
		                req_param.watch_time  = 5;
			            wMui_MLTW_Control_StartReq( &req_param );
	
	                    This->Private->m_MissedCallShortcut = FALSE;
	                    This->Private->m_MissedCallDisplayed = MISSED_CALL_NORMAL;
	                    UpdateShortcuts (This);
	                    UpdateIdleMissedCall(This); 
#ifdef CHW_SUBLCD
	                    /* Erase missing call display in sub led */
	                    Elib_DSP_BL_Erase( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF );
	                    Elib_DSP_BL_Erase( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF_DSP );
#else
#endif
	                }
					return;
                }
                /* Normal Shortcut */
                else
                {                    
                    /* distinguish the SI-Pane or Calendar mode , the shortcut index
                     * is not from 0 at that time
                     */
                    if ( (This->Private->m_IdleScreenType != IDLE_TYPE_NORMAL) ||
                        (This->Private->m_SIPaneShowed))
                    {
                        ShortcutIdx = This->Private->m_CurrentSelectedItem - 1;
                        
                    }
                    else
                    {
                        ShortcutIdx = This->Private->m_CurrentSelectedItem;
                    }
                    
                    req_param.dst_ap	  = (This->Private->m_DesktopShortcutsPointer[ShortcutIdx])->ApplicationId;
                    req_param.info        = (This->Private->m_DesktopShortcutsPointer[ShortcutIdx])->StartMode;
                    req_param.param       = (This->Private->m_DesktopShortcutsPointer[ShortcutIdx])->DataShortcutObjectHandle;
                }
				
				/* inquire conflict */
				if( MuiConflictInquire(APM_APP_IDLE_ID, req_param.dst_ap, req_param.info) != CLM_RESULT_PERMIT )
				{
					return;
				}
                
                /*Richard changed, should alloc memory as papam */
                /* Pay attention sometime shortcut index is from 1 not 0 */
				for( count = 0; count < 1025; count++ )
				{
					if( This->Private->m_DesktopShortcutsPointer[ShortcutIdx]->DataShortcutObjectHandle[count] != 0xFF )
					{
						break;
					}
				}
				
                /* Not a missed call and there is something inside the data pointer */
                if( req_param.param != NULL && count < 1025 )
                {
				    /* create the param for browse app */
				    if( req_param.dst_ap == AM_AP_ID_BROW_MAIN )
				    {
						_Sstring* url;
						url = (_Sstring *)MM_malloc( sizeof(_Sstring) + 1025 );
						memset( url, 0, sizeof(_Sstring) );
						url->_String = (char *)url + sizeof(_Sstring);
						url->_Length = 1025;
						memcpy(url->_String, req_param.param, 1025);

						req_param.param = url;
		                req_param.return_mode = AM_RETURN_MODE_WAIT;
		                req_param.watch_time  = AM_WATCH_MODE_MAX_TIME;
		                wMui_MLTW_Control_StartReq( &req_param );
		                return;
					}

                	TempPtr = (char *)MM_malloc( 1025*sizeof(char) );
					memcpy (TempPtr, req_param.param, 1025);
			    	req_param.param = TempPtr;
				}
				else
				{
					req_param.param = NULL;
				}

                if (req_param.dst_ap == APM_APP_PBOOK_ID)
                {
                    /* MuiPbkIfStartDefaultPhonebook (req_param.src_ap);deleted this asked by PhoneBook*/
					MuiPbkIfShortCutSetup ( &req_param );

                    /* because MuiPbk... doesn't free buffer past to it, so we should free it here */
                    if( TempPtr != NULL ) MM_free(TempPtr);
                }
				else
				{
					/* return mode is wait */
					req_param.return_mode = AM_RETURN_MODE_WAIT;
					req_param.watch_time  = 5;
					wMui_MLTW_Control_StartReq( &req_param );
				}
            }
        }
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* FUNCTION: GetShortcutNum
*
* $UniqueID:$
*
* $Description$
* Update the SI pane display.
* $End$
*******************************************************************************/
/*$Function$*/
static int GetShortcutNum( TI_MUI_IDLE_INTERFACE* This )
{
    int i, Count = 0;

	for (i = 0; i < MAX_SHORTCUTS_NUM; i++)
	{
		if (This->Private->m_DesktopShortcutsPointer[i]->ApplicationId != 0)
		{
			Count++;
		}
	}

	return Count;
}

/*******************************************************************************
*
* MACRO: mtws_DialMenu
*
* $UniqueID:3F014FFF0130$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* Handle Input Screen Options menu tick key.
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_DialMenu )
{
    _IM_CLIPBOARD *pCLIPBOARD = NULL;

	XmTreeNodeCallbackStruct* Data = (XmTreeNodeCallbackStruct*)call_data;
    
	if (Data->reason & XmTREE_GREY_OUT)
    {
		switch(Data->qual)
       {
		case 0:
		case 1:
			Data->grey_out = FALSE;
			break;
		case 2:
			pCLIPBOARD  = IM_GetClipboardData();
			if ((pCLIPBOARD == NULL) || (pCLIPBOARD->wSize == 0) || !IsValidPhoneNum(pCLIPBOARD))
			{
				Data->grey_out = TRUE;
			}
			else
			{
				char buffer[38];
				int len, count, NUM = 36;
				XmTextPosition	widget_pos;
				
				memset(buffer, 0, 38);
				
				widget_pos = (XmTextPosition) MuiAppGetWidgetValue(This->Private->m_TextLabel, XmNcursorPosition);
				
				if ((This->Private->m_IdleString.buf[0] == '+') || 
					(((char) pCLIPBOARD->pwText[0] == '+') && (widget_pos == 0)))
					NUM = 37;
				
				len = widget_pos;
				len = len < NUM ? len : NUM;
				for (count = 0; count < len; count++)
					buffer[count] = This->Private->m_IdleString.buf[count];
				
				len = widget_pos + pCLIPBOARD->wSize;
				len = len < NUM ? len : NUM;
				for(; count < len ; count++)
					buffer[count] = (char) pCLIPBOARD->pwText[count - widget_pos];
				
				len = strlen(This->Private->m_IdleString.buf) +  pCLIPBOARD->wSize;
				len = len < NUM ? len : NUM;
				for (; count < len; count++)
					buffer[count] = This->Private->m_IdleString.buf[count- pCLIPBOARD->wSize];
				
				Data->grey_out = (buffer[0] == 'P');
				
				if (NdIfReportDialType(buffer, 0) == SYGND_UNSUPPORTED_STRING)
					Data->grey_out = TRUE;	
					
				for (count = 1; count < len; count++)
					if (buffer[count] == '+') Data->grey_out = TRUE;
			}
			IM_FinClipboardData();
			break;					
		default:
			break;
       }
   }


    if ( Data->reason & XmTREE_NODE_CR_BROWSE_SELECT )
    {
		switch(Data->qual) {
		case 0:
			/*Launch message*/
			if(MuiConflictInquire(APM_APP_IDLE_ID, AM_AP_ID_MAIL_MAIN, 0)==CLM_RESULT_PERMIT)
			{
				_AM_CONTROL_REQ req_param;
				UINT length;
				MailToInfo *TempPtr = (MailToInfo *)MM_malloc( sizeof(MailToInfo) );
				
				//set launch param
				memset( TempPtr, 0, sizeof(MailToInfo) );
				length = utflen( &This->Private->m_IdleString.utf );
				
				//set mail address
				TempPtr->Address[0].Address_Length = length;
				TempPtr->Address[0].Mail_Address = (char *)MM_malloc( length +1 );
				strcpy( TempPtr->Address[0].Mail_Address, This->Private->m_IdleString.buf );
				TempPtr->sFunctionNo = EML_NEWMAIL_TELBOOK;
				TempPtr->tLocalParam.pMailInf = NULL;
				
				req_param.src_ap      = MuiAppGetApId(This);
				req_param.dst_ap	  = AM_AP_ID_MAIL_MAIN;
				req_param.param       = TempPtr;
				req_param.info        = Mailer_New_Mail_Text;
				req_param.return_mode = AM_RETURN_MODE_WAIT;		
				req_param.watch_time  = AM_WATCH_MODE_MAX_TIME;
				
				wMui_MLTW_Control_StartReq( &req_param );
			}
			utfsetlen( &This->Private->m_IdleString.utf, 0 );
			FsmIfAddEvent(This, E_CANCEL);			
			break;
		case 1:
			IM_SetClipboardData(This->Private->m_IdleString.buf, strlen(This->Private->m_IdleString.buf));
			FsmIfAddEvent(This, E_CANCEL);
			break;
		case 2:
			FsmIfAddEvent(This, E_CANCEL);
	
			pCLIPBOARD  = IM_GetClipboardData();
			if (pCLIPBOARD != NULL && pCLIPBOARD->wSize != 0 && IsValidPhoneNum(pCLIPBOARD))
			{
				char buffer[38];
				XmTextPosition	widget_pos;
				int count = 0, len = 0, NUM = 36;				
				
				memset(buffer, 0, 38);

				widget_pos = (XmTextPosition) MuiAppGetWidgetValue(This->Private->m_TextLabel, XmNcursorPosition);

				if ((This->Private->m_IdleString.buf[0] == '+') || 
					(((char) pCLIPBOARD->pwText[0] == '+') && (widget_pos == 0)))
					NUM = 37;

				len = widget_pos;
				len = len < NUM ? len : NUM;
				for (count = 0; count < len; count++)
					buffer[count] = This->Private->m_IdleString.buf[count];

				len = widget_pos + pCLIPBOARD->wSize;
				len = len < NUM ? len : NUM;
				for(; count < len ; count++)
					buffer[count] = (char) pCLIPBOARD->pwText[count - widget_pos];

				len = strlen(This->Private->m_IdleString.buf) +  pCLIPBOARD->wSize;
				len = len < NUM ? len : NUM;
				for (; count < len; count++)
					buffer[count] = This->Private->m_IdleString.buf[count- pCLIPBOARD->wSize];

				XmTextEditSetString(This->Private->m_TextLabel, buffer);

				XtVaSetValues( This->Private->m_TextLabel, XmNcursorPosition, widget_pos+pCLIPBOARD->wSize, NULL);
			}			
			IM_FinClipboardData();
			break;
		default: break;
		}
    }
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_Cancel
*
* $UniqueID:3F016A100243$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* Clear key pressed, return to input screen
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_Cancel )
{
	FsmIfAddEvent(This, E_CANCEL);
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************	
* 
* FUNCTION:  void UpdateShortcuts
* 
* $UniqueID:
* 
* $Description$
* <please add description here >
* 
* $End$
*******************************************************************************/
/*$Function$*/
static void UpdateShortcuts(TI_MUI_IDLE_INTERFACE* This)
{
	int n = 0;
	Arg args[3];
	
	Widget w = This->Private->m_ShortcutTree;

	if( w == NULL )
	{
		return;
	}

	XtSetArg(args[n], XmNtreeData, Tree_Empty_Data); n++;

    if (This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL)
    {
        XtSetArg(args[n], XmNy, SHORTCUT_BEGIN_Y);n++;
        XtSetArg(args[n], XmNheight, SHORTCUT_HEIGHT);n++;
    }
    else
    {
        XtSetArg(args[n], XmNy, SHORTCUT_BEGIN_Y_CAL);n++;
        XtSetArg(args[n], XmNheight, SHORTCUT_HEIGHT_CAL);n++;
    }

    XtSetValues( w, args, n );

	SetSelectedShortcut (This, This->Private->m_CurrentSelectedItem);
}

/*******************************************************************************	
* 
* FUNCTION:  void SwapUserDisplayRecord 
* 
* $UniqueID:
* 
* $Description$
* <please add description here >
* 
* $End$
*******************************************************************************/
/*$Function$*/
static void SwapUserDisplayRecord (TI_MUI_IDLE_INTERFACE* This, int a, int b)
{
    TS_DATABASE_USER_DISPLAY_RECORD *tmp;
    Arg args[1];
    int n = 0;
    
    tmp = This->Private->m_DesktopShortcutsPointer[a];
    This->Private->m_DesktopShortcutsPointer[a] = This->Private->m_DesktopShortcutsPointer[b];
    This->Private->m_DesktopShortcutsPointer[b] = tmp;

    XtSetArg (args[n], XmNtreeData, Tree_Empty_Data); n++;
    XtSetValues (This->Private->m_ShortcutTree, args, n);
}

/*******************************************************************************	
* 
* FUNCTION:  TS_DATABASE_USER_DISPLAY_RECORD * GetShortcutRecord 
* 
* $UniqueID:
* 
* $Description$
* <please add description here >
* 
* $End$
*******************************************************************************/
/*$Function$*/
static TS_DATABASE_USER_DISPLAY_RECORD * GetShortcutRecord (TI_MUI_IDLE_INTERFACE* This, int TreeItemIdx)
{
    int Idx;
    
    if (TreeItemIdx > 3 && TreeItemIdx < 8)
    {
        Idx = TreeItemIdx - 4;
    }
    else if (TreeItemIdx >= 0 && TreeItemIdx < 4)
    {
        Idx = TreeItemIdx + 4;
    }
    else
    {
        return NULL;
    }

    return This->Private->m_DesktopShortcutsPointer[Idx];
}

/*******************************************************************************	
* 
* FUNCTION:  int GetTreeIndexFromShortcutNo 
* 
* $UniqueID:
* 
* $Description$
* <please add description here >
* 
* $End$
*******************************************************************************/
/*$Function$*/
static int GetTreeIndexFromShortcutNo (int ShortcutNo)
{
    if ((ShortcutNo >= 0) && (ShortcutNo < 4))
    {
        return ShortcutNo + 4;
    }
    else
    {
        return ShortcutNo - 4;
    }
}

#ifdef CHW_SIDEKEY

/*******************************************************************************
*
* MACRO: mtws_SetVolumeHigh
*
* $UniqueID:3DF89A8603E0$
*
* <C_MUI_CNT_PANEL* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_SetVolumeHigh )
{
	TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;

	/* check side key lock status */
	if( This->Private->m_KeyPadLocked == ELIB_KEY_SIDEKEYCLOSE_OFF && Srv_WDC_Get_OpenClose() == ELIB_WDC_CLOSE)
	{
		return;
	}
	if(This->Private->m_IdleStatus == IDLE_DIAL_STATUS)
	{
		Data->processed = FALSE;
		return;
	}
	
	if(Srv_WDC_Get_OpenClose() == ELIB_WDC_OPEN)
	{
		if( (Data->event->type == KeyPress && Data->event->xkey.state != 0)
			|| (Data->event->type == KeyRelease && Data->event->xclient.data.l[0] == 0) )
		{
			FsmIfAddEvent(This, e_SetVolumeUp);
		}
	}
	else
	{
		if(Data->event->type == KeyPress)
		{
			if(Data->event->xkey.state == XtTMLong)
			{
				Elib_LMP_Mobilelight_On(APM_APP_IDLE_ID, ELIB_LMP_MBLT_POCKET, 2);
				This->Private->m_bMobileLight = TRUE;
			}
		}
		else
		{
			if(Data->event->xclient.data.l[0] !=0)
			{
				Elib_LMP_Mobilelight_Off(APM_APP_IDLE_ID, ELIB_LMP_MBLT_POCKET);
				This->Private->m_bMobileLight = FALSE;
			}
			else if(This->Private->m_MissedCallShortcut == TRUE)
			{
				DisplayMissedCallDetail(This);
			}
		}
	}
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_SetVolumeLow
*
* $UniqueID:3DF89A8603E0$
*
* <C_MUI_CNT_PANEL* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_SetVolumeLow )
{
	TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;

	/* check side key lock status */
	if( This->Private->m_KeyPadLocked == ELIB_KEY_SIDEKEYCLOSE_OFF && Srv_WDC_Get_OpenClose() == ELIB_WDC_CLOSE)
	{
		return;
	}
	if(This->Private->m_IdleStatus == IDLE_DIAL_STATUS)
	{
		Data->processed = FALSE;
		return;
	}
	
	if(Srv_WDC_Get_OpenClose() == ELIB_WDC_OPEN)
	{
		if( (Data->event->type == KeyPress && Data->event->xkey.state != 0)
			|| (Data->event->type == KeyRelease && Data->event->xclient.data.l[0] == 0) )
		{
			FsmIfAddEvent(This, e_SetVolumeLow);
		}
	}
	else
	{
		if(Data->event->type == KeyPress)
		{
			if(Data->event->xkey.state == XtTMLong)
			{
				Elib_LMP_Mobilelight_On(APM_APP_IDLE_ID, ELIB_LMP_MBLT_POCKET, 2);
				This->Private->m_bMobileLight = TRUE;
			}
		}
		else
		{
			if(Data->event->xclient.data.l[0] !=0)
			{
				Elib_LMP_Mobilelight_Off(APM_APP_IDLE_ID, ELIB_LMP_MBLT_POCKET);
				This->Private->m_bMobileLight = FALSE;
			}
			else if(This->Private->m_MissedCallShortcut == TRUE)
			{
				DisplayMissedCallDetail(This);
			}
		}
	}
}
END_PRIVATE_MTWS_CALLBACK

#endif

/*******************************************************************************
*
* MACRO: a_HideVolume
*
* $UniqueID:3ECE529D004D$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_HideVolume )
{
	/* Hide the volume label */
	if ( This->Private->m_SetVolumeLabel  != NULL)
	{
	    if ( This->Private->m_IdleScreenType == IDLE_TYPE_CALENDAR )
	    {
    	    Widget CalendarBBoard;
    	    CalendarBBoard = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_CAL_BBOARD );
    	    if(CalendarBBoard != NULL)
    	    {
    	    	XtMapWidget( CalendarBBoard );
    	    }
    	}
		XtUnmapWidget( MuiAppGetDlgItem( This->Private->m_Dlg, WIG_SET_VOLUME_BOARD ) );
	}
	MuiAppTimerDestroy ( &This->Private->m_Timer );
	This->Private->m_VolumeShowed = FALSE;
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_SetVolumeUp
*
* $UniqueID:3ECE529D004D$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_SetVolumeUp )
{
	int VolLevel;
	_ELIB_SS_SELECT_VOLUME VolumeData;
	int state = 0;
    Arg args[1];
    Widget VolumeLabel;
	_ELIB_SS_PLAY_SOUND PlaySound;
	
	VolumeData.PhoneMode = Elib_WDC_Get_PhoneMode(APM_APP_IDLE_ID);
    VolumeData.mode      = ELIB_SS_ALL;
    VolumeData.SetData   = ELIB_SS_SRAM;
	
	PlaySound.mode = ELIB_SS_OTHER | ELIB_SS_SOUND_SCENE_NORMAL;
	PlaySound.SoundID = ELIB_SS_S_ID_KEYOT;
	PlaySound.Option = ELIB_SS_PLAY_LOOP_OFF;
	PlaySound.Sound_Mode_Led = ELIB_SS_LED_NO_SET | ELIB_SS_SOUND_CROSSKEY_OFF;
	PlaySound.Loop = 0;
	PlaySound.Vibrator = 0;

	/* Get the volume talk level */
	Elib_SS_RcvVolumeGet(APM_APP_IDLE_ID, &VolumeData);
	VolLevel = VolumeData.Volume;

	if( This->Private->m_VolumeShowed )
	{
		/* volume widget showing, reset the timer*/
		MuiAppTimerDestroy ( &This->Private->m_Timer );
	}
	else
	{
		/* Move slide label */
	    XtSetArg(args[0], XmNy,		60 - VolLevel*9);
	    XtSetValues(This->Private->m_VolumeLabel, args, 1);
		VolumeLabel = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_VOLUME_ICON );
		MuiAppSetImageIdTransparent( VolumeLabel, VolumeImageId[VolLevel], 0xFFE0 );
		MuiAppSetTextId( MuiAppGetDlgItem( This->Private->m_Dlg, WIG_CURRENT_VOLUME_LEVEL ), VolumeTextId[VolLevel] );
	    if ( This->Private->m_IdleScreenType == IDLE_TYPE_CALENDAR )
	    {
    	    Widget CalendarBBoard;
    	    CalendarBBoard = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_CAL_BBOARD );
    	    XtUnmapWidget( CalendarBBoard );
    	}
		/* Show volume label */
		XtMapWidget( MuiAppGetDlgItem( This->Private->m_Dlg, WIG_SET_VOLUME_BOARD ) );
	}
	
	Elib_SS_Play_Sound(APM_APP_IDLE_ID, &PlaySound);

	if( VolLevel < 6 && This->Private->m_VolumeShowed == TRUE)
	{
		_ELIB_SS_SELECT_VOLUME VolumeData;
		VolLevel++;
		VolumeData.PhoneMode = Elib_WDC_Get_PhoneMode(APM_APP_IDLE_ID);
		VolumeData.mode      = ELIB_SS_ALL;
		VolumeData.SetData   = ELIB_SS_SETALL;
		VolumeData.Volume    = VolLevel;
		VolumeData.StepTone  = ELIB_SS_NOT_STEP;
		Elib_SS_RcvVolumeSet(APM_APP_IDLE_ID, &VolumeData);
		VolumeLabel = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_VOLUME_ICON );
		MuiAppSetImageIdTransparent( VolumeLabel, VolumeImageId[VolLevel], 0xFFE0 );
		MuiAppSetTextId( MuiAppGetDlgItem( This->Private->m_Dlg, WIG_CURRENT_VOLUME_LEVEL ), VolumeTextId[VolLevel] );

		/* Move slide label */
    	XtSetArg(args[0], XmNy,		60 - VolLevel*9);
	    XtSetValues(This->Private->m_VolumeLabel, args, 1);
	}

	/* Create a timer show volume widget*/
	MuiAppTimerCreateEvent( &This->Private->m_Timer, This, e_HideVolume, 3000, TRUE, TRUE);
	This->Private->m_VolumeShowed = TRUE;
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_SetVolumeLow
*
* $UniqueID:3ECE529D004D$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_SetVolumeLow )
{
	int VolLevel;
	_ELIB_SS_SELECT_VOLUME VolumeData;
	int state = 0;
    Arg args[1];
    Widget VolumeLabel;
	_ELIB_SS_PLAY_SOUND PlaySound;
	
	VolumeData.PhoneMode = Elib_WDC_Get_PhoneMode(APM_APP_IDLE_ID);
    VolumeData.mode      = ELIB_SS_ALL;
    VolumeData.SetData   = ELIB_SS_SRAM;
	
	PlaySound.mode = ELIB_SS_OTHER | ELIB_SS_SOUND_SCENE_NORMAL;
	PlaySound.SoundID = ELIB_SS_S_ID_KEYOT;
	PlaySound.Option = ELIB_SS_PLAY_LOOP_OFF;
	PlaySound.Sound_Mode_Led = ELIB_SS_LED_NO_SET | ELIB_SS_SOUND_CROSSKEY_OFF;
	PlaySound.Loop = 0;
	PlaySound.Vibrator = 0;

	/* Get the volume talk level */
	Elib_SS_RcvVolumeGet(APM_APP_IDLE_ID, &VolumeData);
	VolLevel = VolumeData.Volume;
	
	if( This->Private->m_VolumeShowed )
	{
		/* volume widget showing, reset the timer*/
		MuiAppTimerDestroy ( &This->Private->m_Timer );
	}
	else
	{
		/* Move slide label */
	    XtSetArg(args[0], XmNy,		60 - VolLevel*9);
	    XtSetValues(This->Private->m_VolumeLabel, args, 1);
		VolumeLabel = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_VOLUME_ICON );
		MuiAppSetImageIdTransparent( VolumeLabel, VolumeImageId[VolLevel], 0xFFE0 );
		MuiAppSetTextId( MuiAppGetDlgItem( This->Private->m_Dlg, WIG_CURRENT_VOLUME_LEVEL ), VolumeTextId[VolLevel] );
	    if ( This->Private->m_IdleScreenType == IDLE_TYPE_CALENDAR )
	    {
    	    Widget CalendarBBoard;
    	    CalendarBBoard = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_CAL_BBOARD );
    	    XtUnmapWidget( CalendarBBoard );
    	}
		/* Show volume label */
		XtMapWidget( MuiAppGetDlgItem( This->Private->m_Dlg, WIG_SET_VOLUME_BOARD ) );
	}
	
	Elib_SS_Play_Sound(APM_APP_IDLE_ID, &PlaySound);

	if( VolLevel > 0 && This->Private->m_VolumeShowed == TRUE)
	{
		_ELIB_SS_SELECT_VOLUME VolumeData;
		VolLevel--;
		VolumeData.PhoneMode = Elib_WDC_Get_PhoneMode(APM_APP_IDLE_ID);
		VolumeData.mode      = ELIB_SS_ALL;
		VolumeData.SetData   = ELIB_SS_SETALL;
		VolumeData.Volume    = VolLevel;
		VolumeData.StepTone  = ELIB_SS_NOT_STEP;
		Elib_SS_RcvVolumeSet(APM_APP_IDLE_ID, &VolumeData);
		VolumeLabel = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_VOLUME_ICON );
		MuiAppSetImageIdTransparent( VolumeLabel, VolumeImageId[VolLevel], 0xFFE0 );
		MuiAppSetTextId( MuiAppGetDlgItem( This->Private->m_Dlg, WIG_CURRENT_VOLUME_LEVEL ), VolumeTextId[VolLevel] );

		/* Move slide label */
    	XtSetArg(args[0], XmNy,		60 - VolLevel*9);
    	XtSetValues(This->Private->m_VolumeLabel, args, 1);
    }

	/* Create a timer show volume widget*/
	MuiAppTimerCreateEvent( &This->Private->m_Timer, This, e_HideVolume, 3000, TRUE, TRUE);
	This->Private->m_VolumeShowed = TRUE;
}
END_PRIVATE_ACTION

/*******************************************************************************	
* 
* FUNCTION:  BOOLEAN ItIsMissedCallTreeIndexShortcut 
* 
* $UniqueID:
* 
* $Description$
* determine whether or not it is the first available shortcut position
* by tree widget index
* 
* $End$
*******************************************************************************/
/*$Function$*/
static BOOLEAN ItIsMissedCallTreeIndexShortcut (TI_MUI_IDLE_INTERFACE* This, int index)
{
    /* determine whether or not it is the first available shortcut position */		
	if (This->Private->m_MissedCallShortcut)
    {
        int ShortcutNum = GetShortcutNum(This);

		/* Normal mode */	
		if (This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL)
        {
            /* full of shortcuts */
			if (ShortcutNum == 8 && index == 3)
			{
				return TRUE;
			}
			/* one row of shortcuts */
			else if (index > 3 && (index-4) == ShortcutNum)
			{
				return TRUE;
			}
			/* two rows of shortcuts */
			else if (index < 4 && (index+4) == ShortcutNum)
			{
				return TRUE;
			}
        }

        /* Calendar mode */
		if (This->Private->m_IdleScreenType != IDLE_TYPE_NORMAL)
        {
            /* full of shortcuts */
			if (ShortcutNum > 3 && index == 7)
			{
				return TRUE;
			}
			/* one row of shortcuts */
			else if (index > 3 && (index-4) == ShortcutNum)
			{
				return TRUE;
			}
        }
    }

    return FALSE;
}

/*******************************************************************************	
* 
* FUNCTION:  BOOLEAN ItIsMissedCallShortcut 
* 
* $UniqueID:
* 
* $Description$
* determine whether or not it is the the missed call shortcut
* 
* $End$
*******************************************************************************/
/*$Function$*/
static BOOLEAN ItIsMissedCallShortcut (TI_MUI_IDLE_INTERFACE* This, int index)
{
    if (This->Private->m_MissedCallShortcut)
    {
		int ShortcutNum = GetShortcutNum(This);

        /* normal Idle screen with SI Pane showed */
		if (This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL && 
            This->Private->m_SIPaneShowed)
        {
            /* Last shortcut is overwritten by missed call shortcut */
			if (ShortcutNum == 8 && index == 8)
			{
				return TRUE;
			}

			/* normal missed call shortcut, without overwriting */
			if (ShortcutNum < 8 && index == ShortcutNum+1)
			{
				return TRUE;
			}
        }

        /* normal Idle screen without SI Pane showed */
		if (This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL && 
            !This->Private->m_SIPaneShowed)
        {
            /* Last shortcut is overwritten by missed call shortcut */
			if (ShortcutNum == 8 && index == 7)
			{
				return TRUE;
			}
			
			/* normal missed call shortcut, without overwriting */
			if (ShortcutNum < 8 && index == ShortcutNum)
			{
				return TRUE;
			}
        }

        /* Calendar Screen */
		if (This->Private->m_IdleScreenType != IDLE_TYPE_NORMAL)
        {
            /* Last shortcut is overwritten by missed call shortcut */
			if (ShortcutNum > 2 && index == 4)
			{
				return TRUE;
			}
			
			/* normal missed call shortcut, without overwriting */
			if (ShortcutNum < 4 && index == ShortcutNum+1)
			{
				return TRUE;
			}
        }
    }

    return FALSE;
}

/*******************************************************************************	
* 
* FUNCTION:  int GetMissedCallShortcutIndex 
* 
* $UniqueID:
* 
* $Description$
* <please add description here >
* 
* $End$
*******************************************************************************/
/*$Function$*/
static int GetMissedCallShortcutIndex (TI_MUI_IDLE_INTERFACE* This)
{
    if (This->Private->m_MissedCallShortcut)
    {
		int ShortcutNum = GetShortcutNum(This);
		
        /* Normal Idle screen with SI Pane */
		if (This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL && 
            This->Private->m_SIPaneShowed)
        {
            /* Full of shortcuts */
			if (ShortcutNum == 8)
			{
				return 8;
			}
			else
			{
				return ShortcutNum+1;
			}
        }
        
        /* Normal Idle screen without SI Pane */
		if (This->Private->m_IdleScreenType == IDLE_TYPE_NORMAL && 
            !This->Private->m_SIPaneShowed)
        {
            /* Full of shortcuts */
			if (ShortcutNum == 8)
			{
				return 7;
			}
			else
			{
				return ShortcutNum;
			}
        }
        
        /* Calendar mode */
		if (This->Private->m_IdleScreenType != IDLE_TYPE_NORMAL)
        {
            /* Full of shortcuts */
			if (ShortcutNum > 2)
			{
				return 4;
			}
			else
			{
				return ShortcutNum+1;
			}
        }
    }

    /* No missed call shortcut found */
	return -1;
}

/*******************************************************************************	
* 
* FUNCTION:  int GetRightMostShortcutIndex 
* 
* $UniqueID:
* 
* $Description$
* <please add description here >
* 
* $End$
*******************************************************************************/
/*$Function$*/
static int GetRightMostShortcutIndex (TI_MUI_IDLE_INTERFACE* This, int LineNo)
{
	int ShortcutNum = GetShortcutNum(This);
	int RightMostIdxInTree = -1;

	/* First line of shortcuts */
	if (LineNo == 0)
	{
		/* There is a missed call shortcut now */
		if (This->Private->m_MissedCallShortcut)
		{
			/* Shortcuts are in 1 line mode */
			if (This->Private->m_IdleScreenType != IDLE_TYPE_NORMAL)
			{
				/* shortcuts are full in 1 line mode, missed call shortcut overwrite one */
				if (4 == ShortcutNum)
				{
					RightMostIdxInTree = ShortcutNum-1;
				}
			}

			/* Missed shortcut is in first line */
			if (4 > ShortcutNum)
			{
				RightMostIdxInTree = ShortcutNum;
			}
		}

		/* Not found yet*/
		if (RightMostIdxInTree == -1)
		{
			/* There isn't missed call shortcut or
			 * the missed call shortcut is in the 
			 * second line
			 */	
			if (ShortcutNum < 4)
			{
				/* The first line is not full */
				RightMostIdxInTree = ShortcutNum-1;
			}
			else
			{
				/* The first line is full */
				RightMostIdxInTree = 3;
			}
		}
	}

	/* Second line of shortcuts */
	if (LineNo == 1)
	{
		if (This->Private->m_IdleScreenType != IDLE_TYPE_NORMAL)
        {
            return -1;
        }

        /* There is a missed call shortcut now */
		if (This->Private->m_MissedCallShortcut)
		{
			/* shortcuts are full in 2 line mode */
			if (ShortcutNum == 8)
			{
				RightMostIdxInTree = 7;
			}
			else if (ShortcutNum >= 4)
			{
				RightMostIdxInTree = ShortcutNum;
			}
		}

		/* Not found yet */
		if (RightMostIdxInTree == -1)
		{
			if (ShortcutNum > 4)
			{
				RightMostIdxInTree = ShortcutNum-1;
			}
		}
	}

	/* If it is Calendar mode or there is SI Pane, translate the index
	 * from tree's to idle's
	 */
	if (This->Private->m_IdleScreenType != IDLE_TYPE_NORMAL ||
		This->Private->m_SIPaneShowed)
	{
		if (RightMostIdxInTree != -1)
		{
			RightMostIdxInTree++;
		}
	}

	return RightMostIdxInTree;
}

/*******************************************************************************	
* 
* FUNCTION:  MuiPasteNumberToIdle
* 
* $UniqueID:
* 
* $Description$
* <please add description here >
* 
* $End$
*******************************************************************************/
/*$Function$*/
TS_CMD_STATUS MuiPasteNumberToIdle( TS_SESSION_ID* Session, TS_PHONE_NUMBER PhoneNumber )
{
	TS_CMD_STATUS CmdStatus = CMST_OK;
	TS_PHONE_NUMBER Number = PhoneNumber;

    EVM_DECLARE_SIGNAL( EVID_EXTRACT_NUMBER_NTF, BroadcastEvent );
    BroadcastEvent.Ptr = &Number;
    CmdStatus = MsApiEvBroadcastEventInd( Session, &BroadcastEvent );
	return CmdStatus;
}

/*******************************************************************************	
* 
* FUNCTION:  void MuiAppIdleSetDlgTextId 
* 
* $UniqueID:
* 
* $Description$
* <please add description here >
* 
* $End$
*******************************************************************************/
/*$Function$*/
static void MuiAppIdleSetDlgTextId (TL_MUI_APP_DIALOG* Dialog, TS_TEXT_ID TextId, 
									TS_MUI_DLG_TEXT Mode)
{
	if (Dialog->SoftKey[Mode] != TextId)
	{
		MuiAppSetDlgTextId(Dialog, TextId, Mode);
	}
}

/*******************************************************************************
*
* MACRO: mtws_ModeControl
*
* $UniqueID:3DF89A8603E0$
*
* <C_MUI_CNT_PANEL* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_ModeControl )
{
    /*Register the Hutchison Long key in IDLE screen again*/
    TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;
    
    /* Registered long hook key, wrapper limit */
    if( ((XExpansionEvent*)(Data->event))->subtype == KeyNotify_HookPush && Data->event->xexpansion.info == XK_KEY_HUTCHISON )
    {
        Elib_KEY_LongHook_Set (MuiAppGetApId (This), XK_KEY_HUTCHISON, 10, XK_KEY_HUTCHISON, 0);    
		
		/* dial lock is enabled, Long press menu key in normal screen */
		if(This->Private->m_bDialLockEnable && FMui_Mltw_ActiveInfoReq(NULL) == APM_APP_IDLE_ID && This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
		{
			FsmIfAddEvent(This, e_KeyPressed);
			return;
		}

#ifdef CSW_SUPPORTKEYLOCK
		/* Key lock is enabled, Long press Hutchison key in normal screen */
		if(This->Private->m_bKeyLockStatus && FMui_Mltw_ActiveInfoReq(NULL) == APM_APP_IDLE_ID && This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
		{
			FsmIfAddEvent(This, e_AnyKeyPressed);
			This->Private->m_SosString[0] = '\0';
			return;
		}
#endif		
        if( CpmIfIsDuringLowBattery() == FALSE )
        {
#if 0
            BOOLEAN AnyKeyAnswer = FALSE;

            TS_PROFILE_DATA ProfData;
            TS_CMD_STATUS CmdStatus = CMST_OK;
            
            ProfData.Data = &AnyKeyAnswer;
            ProfData.Size = 1;
            ProfData.Id = SYSPRF_SYSUICP_ANY_KEY_ANSWER_ENABLED;
            ProfData.Entry = 1;
            
            MsApiSysCfgQueryProfile (&(This->Private->m_Session.Session), &ProfData);
                
            if (!AnyKeyAnswer)
#else
            /* Do not launch Mode Control when there is a incoming call */
            if (CLM_STAT_INACTIVITY == Clm_Get_ItemStatus (MuiAppGetApId(This), CLM_ITEM_ACCEPT))
#endif
            {
                FsmIfAddEvent (This, e_GotoModeControl);
            }
        }
    }

    if( ((XExpansionEvent*)(Data->event))->subtype == KeyNotify_HookPush && Data->event->xexpansion.info == XK_KEY_FUNCTION )
    {
    	Elib_KEY_LongHook_Set (APM_APP_IDLE_ID, XK_KEY_FUNCTION, 10, XK_KEY_FUNCTION, 0);
		
		/* dial lock is enabled, Long press menu key in normal screen */
		if(This->Private->m_bDialLockEnable && FMui_Mltw_ActiveInfoReq(NULL) == APM_APP_IDLE_ID && This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
		{
			FsmIfAddEvent(This, e_KeyPressed);
		}

#ifdef CSW_SUPPORTKEYLOCK
		/* Key lock is enabled, Long press menu key in normal screen */
		if(This->Private->m_bKeyLockStatus && FMui_Mltw_ActiveInfoReq(NULL) == APM_APP_IDLE_ID && This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
		{
			FsmIfAddEvent(This, e_AnyKeyPressed);
			This->Private->m_SosString[0] = '\0';
		}
#endif
	}
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: a_LoadModeControl
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadModeControl )
{
    if(Qual==LOAD)
    {
        AMC_EN_SIM_TYPE SimType;
        TS_MC_MODE Mode;
        TS_MC_TYPE Type;
        
        MsApiSysCfgGetSimType (&This->Private->m_Session.Session, &SimType);
        if (SimType != AMC_SIM_DUAL)
        {
            FsmIfAddEvent (This, E_CANCEL);
            return;
        }

        MsApiNwrkQueryCurrentMc (&Mode, &Type);
        if (Mode != AMC_MODE_2G)
        {
            FsmIfAddEvent (This, E_CANCEL);
            return;
        }

        if (CLM_RESULT_PERMIT != CLM_RESULT_CHK (Clm_Conflict_Inquire (APM_APP_IDLE_ID, CLM_RET_INSTANT, CLM_INQ_START_ITEM, CLM_ITEM_MCHANGE_TO3_FROM2, CLM_FIRST_INSTRUCTIONS_ACTION)))
        {
			This->Private->m_MCAction = ACTION_MC_DONE;//Do not launch Browser if CLM failed
        	FsmIfAddEvent (This, E_CANCEL);
        	return;
        }

 		Clm_Conflict_Inquire (APM_APP_IDLE_ID, CLM_RET_INSTANT, CLM_INQ_END_ITEM, CLM_ITEM_MCHANGE_TO3_FROM2, CLM_FIRST_RESULT_CONFLICT);       

        This->Private->m_MCAction = ACTION_MC_CELL_SEARCH;

        This->Private->m_DisplayMessage = FsmIfCreateInstance (This, C_MUI_DISPLAY_MESSAGE);
        MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_CNF_1);
        MuiDisMsgSetSoftKey( This->Private->m_DisplayMessage, MUI_DLG_TEXT_LEFT, WORD_KEY_CMN_YES, E_DONE );
        MuiDisMsgSetSoftKey( This->Private->m_DisplayMessage, MUI_DLG_TEXT_RIGHT, WORD_KEY_CMN_NO, E_CANCEL);
		MuiDisMsgSetClearKey(This->Private->m_DisplayMessage, E_CANCEL);
		This->Private->m_DisplayMessage->Public->m_TextId = WORD_MSG_MC_AREA_MODE_SETTING_CNF;

		/* Philip added for MC searching dialog raising, 2003-08-20 START */
		{
			_AM_HISTORY_REQ AmHistoryReq;
			AmHistoryReq.ap_ID = MuiAppGetApId(This);
			Am_History_RaiseReq(&AmHistoryReq);
		}
		/* Philip added for MC searching dialog raising, 2003-08-20 END   */
		MuiAppIfTitleBarSetText( This, TXT_TRE_NW_AREAMODE );
		MuiAppIfTitleBarSetIcon( This, IMG_STG_0 );
		MuiAppIfTitleBarSetWallpaper( This, IMG_CMN_LBL_2 );
		MuiAppIfTitleBarShow( This, TRUE );
    }
    else
    {
        if (This->Private->m_DisplayMessage)
        {
            FsmIfDeleteInstance (This->Private->m_DisplayMessage);
            This->Private->m_DisplayMessage = NULL;
        }
		MuiAppIfTitleBarShow( This, FALSE );
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_ModeChangeRequest
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
extern TS_CMD_STATUS MsApiNwrkAreaModeChangeReq(const TS_SESSION_DETAILS* SessionDetails,
	                        const TS_MC_MODE_CHG_REQ_DATA* ModeChgReq);
START_PRIVATE_ACTION ( a_ModeChangeRequest )
{
    TS_MC_MODE_CHG_REQ_DATA data;
	
    if (This->Private->m_MCAction == ACTION_MC_MODE_CHANGE)
    {
		if (This->Private->m_DisplayMessage)
		{
			FsmIfDeleteInstance (This->Private->m_DisplayMessage);
			This->Private->m_DisplayMessage = NULL;
		}
		
		This->Private->m_DisplayMessage = FsmIfCreateInstance (This, C_MUI_DISPLAY_MESSAGE);
		MuiDisMsgSetStyle (This->Private->m_DisplayMessage, STY_PLEASE_WAIT);
		This->Private->m_DisplayMessage->Public->m_TextId = WORD_MSG_MC_PROCESSING;
    	This->Private->m_DisplayMessage->Public->m_ValidKeys = MSG_KEY_END;
        MuiSetEndKey (This->Private->m_DisplayMessage, e_MCendkey);
    }

    data.enMode = AMC_IMMEDIATE_3G;
	MsApiNwrkAreaModeChangeReq (&This->Private->m_Session, &data);
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_ConfirmModeChange
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_ConfirmModeChange )
{
    if (This->Private->m_DisplayMessage)
    {
        FsmIfDeleteInstance (This->Private->m_DisplayMessage);
        This->Private->m_DisplayMessage = NULL;
    }

    This->Private->m_DisplayMessage = FsmIfCreateInstance (This, C_MUI_DISPLAY_MESSAGE);
    MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_WAR_5);
    This->Private->m_DisplayMessage->Public->m_TextId = WORD_MSG_MC_UMTS_OUTSIDE_CNF;

    This->Private->m_MCAction = ACTION_MC_MODE_CHANGE;
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadModeChangeNotice
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadModeChangeNotice )
{
    if (This->Private->m_DisplayMessage)
    {
        FsmIfDeleteInstance (This->Private->m_DisplayMessage);
        This->Private->m_DisplayMessage = NULL;
    }

    This->Private->m_MCAction = ACTION_MC_MODE_IND;
    
    if (Qual)
    {
        MUI_APP_UTF_BUFFER_TAG (Msg);
        INIT_UTF (Msg);
        
        This->Private->m_DisplayMessage = FsmIfCreateInstance (This, C_MUI_DISPLAY_MESSAGE);
        MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_INF_3);

        MsApiLngQueryGetUtfString (&This->Private->m_Session.Session, 
                                    &Msg.utf,
                                    TXT_MSG_NW_AREAMODE_AUTO,
                                    LNG_AUTO);

        /* Show the Message */
        MuiDisMsgLoadText( This->Private->m_DisplayMessage, Msg.buf );
    }
    else
    {
        This->Private->m_DisplayMessage = FsmIfCreateInstance (This, C_MUI_DISPLAY_MESSAGE);
        MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_WAR_2);
        This->Private->m_DisplayMessage->Public->m_TextId = WORD_MSG_MC_PROCESSING_ERR;
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_CellSearch
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_CellSearch )
{
    if (This->Private->m_DisplayMessage)
    {
        FsmIfDeleteInstance (This->Private->m_DisplayMessage);
        This->Private->m_DisplayMessage = NULL;
    }

    This->Private->m_DisplayMessage = FsmIfCreateInstance (This, C_MUI_DISPLAY_MESSAGE);
    MuiDisMsgSetStyle (This->Private->m_DisplayMessage, STY_PLEASE_WAIT);
    This->Private->m_DisplayMessage->Public->m_TextId = WORD_MSG_MC_CELL_SEARCHING;
    //Need to ask message team to support self defined image.
    //This->Private->m_DisplayMessage->Public->m_Image = ANI_COM_PLEASE_WAIT_1_F01;
	This->Private->m_DisplayMessage->Public->m_ValidKeys = MSG_KEY_END;
    MuiSetEndKey (This->Private->m_DisplayMessage, e_MCendkey);
    /* Call Mode control action */
    MsApiNwrkCellSearchReq (&This->Private->m_Session);
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_JudgeMCAction
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_JudgeMCAction )
{
    if (This->Private->m_MCAction == ACTION_MC_CELL_SEARCH)
    {
        FsmIfAddEvent (This, e_StartCellSearch);
    }

    else  if (This->Private->m_MCAction == ACTION_MC_MODE_CHANGE)
    {
         FsmIfAddEvent (This, e_3GCellFound);
    }
    else if (This->Private->m_MCAction == ACTION_MC_MODE_IND)
    {
         FsmIfAddEvent (This, E_CANCEL);
         This->Private->m_MCAction = ACTION_MC_DONE;
    }    
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadModeChangeNotice
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_MCExit )
{
    if (This->Private->m_DisplayMessage)
    {
        FsmIfDeleteInstance (This->Private->m_DisplayMessage);
        This->Private->m_DisplayMessage = NULL;
    }

    if (This->Private->m_MCAction == ACTION_MC_NULL)
    {
#if 0 /*Do not launch Browser if H key long pressed*/
        /* Launch the browser */
        if (CLM_RESULT_PERMIT == MuiConflictInquire(MuiAppGetApId(This), AM_AP_ID_BROW_MAIN, 0))
        {
            _AM_CONTROL_REQ req_param;
            req_param.src_ap      = MuiAppGetApId(This);
            req_param.info        = 0;
            req_param.param       = 0;
            req_param.return_mode = AM_RETURN_MODE_WAIT;
            req_param.watch_time  = AM_WATCH_MODE_MAX_TIME;
            req_param.dst_ap = AM_AP_ID_BROW_MAIN;
            wMui_MLTW_Control_StartReq( &req_param );
        }  
#endif /*Do not launch Browser if H key long pressed*/      
    }
    else
    {
        This->Private->m_MCAction = ACTION_MC_NULL;
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_ClearBuffer
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Clear the text buffer
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_ClearBuffer )
{
	utfsetlen(&This->Private->m_IdleString.utf,0);
}
END_PRIVATE_ACTION

#ifdef CHW_SIDEKEY

/*******************************************************************************
*
* MACRO: mtws_SideKeyLockReq
*
* $UniqueID:3F3465740076$
*
* <C_MUI_SECURITY_MENU* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_SideKeyLockReq )
{
	int					RetVal;
	BOOLEAN				IsLockOn;

	XmTreeNodeCallbackStruct* Data = (XmTreeNodeCallbackStruct*)call_data;
	

	RetVal		= Elib_KEY_Get_SideKeyLockMode( MuiAppGetApId(This), &This->Private->m_KeyPadLocked );
	IsLockOn	= (This->Private->m_KeyPadLocked == ELIB_KEY_SIDEKEYCLOSE_OFF);

	if ( (Data->reason & XmTREE_NODE_ITEM_IS_SET) )
	{
		Data->SelectionIndicator = ((UINT8)Data->qual == This->Private->m_KeyPadLocked);
	}

	if ( Data->reason & XmTREE_NODE_CR_BROWSE_SELECT )
    {
		This->Private->m_KeyPadLocked = (UINT8)Data->qual;
		Elib_KEY_Set_SideKeyLockMode( MuiAppGetApId(This), This->Private->m_KeyPadLocked );
		
		/* update the status icon */
        UpdateKeypadLockIcon(This);
        FsmIfAddEvent(This,E_DONE);
    }
}
END_PRIVATE_MTWS_CALLBACK

#endif

void MissedCallTimerExpired( TS_MUI_APP_TIMER * Timer, TI_GENERIC * This, int Value )
{
#ifdef CHW_SUBLCD
    Elib_DSP_BL_Erase( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF_DSP );
#else
#endif 
}

/*******************************************************************************
*
* MACRO: a_StartVoiceCall
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_StartVoiceCall )
{
	/* Yes is select, start a voice call */
	if(Qual)
	{
		MuiCsvSetDialString( This->Private->m_VoiceCallsClass, This->Private->m_IdleString.buf );
	}
	/* NO is select, return to the app starting the VT */
	else if(This->Private->m_bRaiseIdle)
	{
		_AM_HISTORY_REQ AmHistoryReq;
	    AmHistoryReq.ap_ID = APM_APP_IDLE_ID;
	    Am_History_LowerReq(&AmHistoryReq);
	    This->Private->m_bRaiseIdle = FALSE;
	}		
	utfsetlen(&This->Private->m_IdleString.utf, 0);
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadVideoCallControl
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadVideoCallControl )
{
	if(Qual)
	{
      	This->Private->m_DisplayMessage = FsmIfCreateInstance( This, C_MUI_DISPLAY_MESSAGE );
        MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_WAR_1);
        This->Private->m_DisplayMessage->Public->m_TextId = TXT_IDLE_OUTGOING_NOTICE;
	}
	else
	{
		FsmIfDeleteInstance(This->Private->m_DisplayMessage);
		This->Private->m_DisplayMessage = NULL;
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadUrlVideoCallControl
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadUrlVideoCallControl )
{
	if(Qual)
	{
      	This->Private->m_DisplayMessage = FsmIfCreateInstance( This, C_MUI_DISPLAY_MESSAGE );
	    MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_WAR_3);
	    This->Private->m_DisplayMessage->Public->m_TextId = WORD_MSG_MSG_CONNECTING_ERROR;
	    MuiDisMsgSetClearKey(This->Private->m_DisplayMessage, E_DONE);
	    MuiSetEndKey(This->Private->m_DisplayMessage, E_DONE);
	    MuiSetSendKey(This->Private->m_DisplayMessage, E_DONE);
	}
	else
	{
		FsmIfDeleteInstance(This->Private->m_DisplayMessage);
		This->Private->m_DisplayMessage = NULL;
	}
}
END_PRIVATE_ACTION


/*******************************************************************************
*
* MACRO: a_LoadFdnRestricted
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
*  
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadFdnRestricted )
{
	_AM_HISTORY_REQ AmHistoryReq;
	if(Qual)
	{
      	This->Private->m_DisplayMessage = FsmIfCreateInstance( This, C_MUI_DISPLAY_MESSAGE );
	    MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_WAR_2);
	    This->Private->m_DisplayMessage->Public->m_TextId = TXT_CC_NOT_FDN;
	    MuiDisMsgSetClearKey(This->Private->m_DisplayMessage, E_DONE);
	    MuiSetEndKey(This->Private->m_DisplayMessage, E_DONE);
	    MuiSetSendKey(This->Private->m_DisplayMessage, E_DONE);
		
		if(FMui_Mltw_ActiveInfoReq(NULL) != APM_APP_IDLE_ID)
		{
			AmHistoryReq.ap_ID = APM_APP_IDLE_ID;
			Am_History_RaiseReq(&AmHistoryReq);
		}
	}
	else
	{
		AmHistoryReq.ap_ID = APM_APP_IDLE_ID;
		Am_History_LowerReq(&AmHistoryReq);
		FsmIfDeleteInstance(This->Private->m_DisplayMessage);
		This->Private->m_DisplayMessage = NULL;
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadVerifyPIN2
*
* $UniqueID:3ECE529D004D$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadVerifyPIN2 )
{
	/* Hide the volume label */
	if ( Qual )
	{
       This->Private->m_PinControlClass = FsmIfCreateInstance( This, TI_MUI_SECURITY_PIN_INTERFACE  );
       This->Private->m_PinControlClass->Public->m_PinControl = MUI_PIN2_VERIFY;
	}
	else
	{
		FsmIfDeleteInstance( This->Private->m_PinControlClass );
		This->Private->m_PinControlClass = NULL;
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_SwitchAlsLine
*
* $UniqueID:3ECE529D004D$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_SwitchAlsLine )
{
	TS_CMD_STATUS CmdStatus;
	TS_ALS_LINE AlsLine;
	    
	CmdStatus = MsApiSysCfgQueryAls(&AlsLine);
	os_assert((CmdStatus == CMST_OK), ("ALS query failed" ));
	CmdStatus = MsApiSysCfgSetLine( &This->Private->m_Session, (AlsLine == ALS_LINE_1 ? ALS_LINE_2 : ALS_LINE_1) );
	os_assert((CmdStatus == CMST_OK), ("ALS query failed" ));
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: mtws_ChangeMode
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $end$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_ChangeMode )
{
    XmTreeNodeCallbackStruct *Data = (XmTreeNodeCallbackStruct *)call_data;
    
    if (Data->reason & XmTREE_NODE_ITEM_IS_SET)
    {
	    /* Since we're displaying the select menu, the current mode should be one of these four:Normal,Pocket,Meeting,Noisy */
		TS_PHONE_MODE Mode;

		Mode = Elib_WDC_Get_PhoneMode( APM_APP_IDLE_ID );
        /* We're being asked whether the option specified 'index' is the current setting */
        /* (i.e. should have a circle around the number). We need to set 'SelectionIndicator' */
        /* to TRUE or FALSE. */
        if (Data->qual == Mode)
        {
            Data->SelectionIndicator = TRUE;
        }
        else
        {
            Data->SelectionIndicator = FALSE;
        }
    }

    if ( Data->reason & XmTREE_NODE_CR_BROWSE_SELECT )
    {
        
        Elib_WDC_Set_PhoneMode (APM_APP_IDLE_ID, Data->qual);

        UpdateModeFunctionSetting( This, Data->qual );
        UpdateBacklightSetting(This);
		FsmIfAddEvent (This, E_DONE);
    }
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_ProcessKeysInService
*
* $UniqueID:3CC7D70500E9$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_ProcessKeysInService )
{
	TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;
    if(This->Private->m_bDialLockEnable && This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
    {
    	FsmIfAddEvent(This, e_KeyPressed);
    }
#ifdef CSW_SUPPORTKEYLOCK
	else if( This->Private->m_bKeyLockStatus && This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
	{
		/* Any key is pressed in key lock status */
		if(Data->event->type == KeyPress && Data->event->xkey.state == 0)
		{
			if(Data->event->xkey.keycode == XK_KEY_FUNCTION)
			{
				FsmIfAddEvent(This, e_MenuKeyPressed);
				This->Private->m_SosString[0] = '\0';
			}
			else if(Data->event->xkey.keycode == XK_KP_ASTER)
			{
				FsmIfAddEvent(This, e_AsterKeyPressed);
				This->Private->m_SosString[0] = '\0';
			}
			else if(Data->event->xkey.keycode <= XK_KP_9 && Data->event->xkey.keycode >= XK_KP_0)
			{
				if( IsEmergencyNum(This, (Data->event->xkey.keycode - XK_KP_0)) )
				{
					FsmIfAddEvent(This, e_StartKeyLockEmergency);
				}
				else
				{
					FsmIfAddEvent(This, e_AnyKeyPressed);
				}
			}
			else
			{
				FsmIfAddEvent(This, e_AnyKeyPressed);
				This->Private->m_SosString[0] = '\0';
			}
		}
	}
#endif
    else
    {
		Data->processed=FALSE;
	}
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_OneTouchDial
*
* $UniqueID:3CC7D70500E9$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_OneTouchDial )
{
	TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;
	int KeyNumber;
	TI_EVID_NULL_STRUCT EventData;

	if(Data->event->xkey.state == XtTMLong && This->Private->m_IdleStatus == IDLE_NORMAL_STATUS)
	{
		KeyNumber = Data->event->xkey.keycode-XK_KP_0;
		/* Launching voice mail */
		if( KeyNumber == 1 )
		{
	        EventData.Id   = EVID_IDLE_LOAD_VOICE_MAIL;
	        EventData.Ptr  = NULL;
	        EventData.Size = 0;
	        MsApiEvBroadcastEventInd (NULL, &EventData); 
		}
		else if( KeyNumber > 1 && KeyNumber < 10)
		{
/* Disable fast dial check temporary according to VTB 748
 * set maxlen always 1
 */
#if 0
            TS_PROFILE_DATA ProfileData;
			int maxlen = 0;
		    ProfileData.Data = &maxlen;
		    ProfileData.Size = 1;
		    ProfileData.Id = SYSPRF_SYSUICP_FAST_DIAL_MODE;
		    ProfileData.Entry = 1;
		    MsApiSysCfgQueryProfile (&This->Private->m_Session.Session, &ProfileData);
#else
            int maxlen = 1;
#endif
			/* if one touch dial is on, start a fast dial call */
			if( maxlen == 1 )
			{
				MuiPbkIfFastDial( (UINT16)KeyNumber, APM_APP_IDLE_ID );
			}
			else
			{
				Data->processed = FALSE;
			}
		}
		else
		{
			Data->processed = FALSE;
		}
	}
	else
	{
		Data->processed = FALSE;
	}
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: a_LoadMessage
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Show the previous SI message in SI pane in SI active mode.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadMessage )
{
    if(Qual)
    {
		/* Display dial lock info */
		This->Private->m_DisplayMessage = FsmIfCreateInstance( This, C_MUI_DISPLAY_MESSAGE );
        MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_WAR_2);
        This->Private->m_DisplayMessage->Public->m_TextId = TXT_IDLE_DIALLOCK_MESSAGE;
    }
    else
    {
    	FsmIfDeleteInstance (This->Private->m_DisplayMessage);
    	This->Private->m_DisplayMessage = NULL;
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* FUNCTION: QueryIdleScreenType
*
* $UniqueID:3E846C9400D0$
*
* $Description$
* This function queries the middleware to determine the setting for the Idle screen type.
* $End$
*******************************************************************************/
/*$Function$*/
static BOOLEAN QueryIdleMissedCall( TI_MUI_IDLE_INTERFACE* This )
{
    TS_PROFILE_DATA ProfileData;
    TS_CMD_STATUS CmdStatus = CMST_OK;
    BOOLEAN MissedCall = IDLE_TYPE_NORMAL;

    /* Read the current screen type preference from NVD */
    ProfileData.Data = &MissedCall;
    ProfileData.Size = 1;
    ProfileData.Id = SYSPRF_SYSGDISP_MISSED_CALL;
    ProfileData.Entry = 1;
    CmdStatus = MsApiSysCfgQueryProfile (&(This->Private->m_Session.Session), &ProfileData);
    os_assert((CmdStatus == CMST_OK), ("Profile query failed" ));

    return(MissedCall);
}

/*******************************************************************************
*
* FUNCTION: UpdateIdleScreenType
*
* $UniqueID:3EAFAA0802D6$
*
* $Parm:TL_IDLE_SCREENTYPE ScreenType$
* The new value for the Sceen type setting.
* $End$
*
* $Description$
* This function updates the setting for the Idle screen type stored in NV.
* $End$
*******************************************************************************/
/*$Function$*/
static void UpdateIdleMissedCall( TI_MUI_IDLE_INTERFACE* This )
{
    TS_PROFILE_DATA ProfileData;
    TS_CMD_STATUS CmdStatus = CMST_OK;

    /* Copy the current screen type preference to NVD */
    ProfileData.Data = &(This->Private->m_MissedCallShortcut);
    ProfileData.Size = 1;
    ProfileData.Id = SYSPRF_SYSGDISP_MISSED_CALL;
    ProfileData.Entry = 1;
    CmdStatus = MsApiSysCfgUpdateProfile (&This->Private->m_Session.Session, &ProfileData);
    os_assert((CmdStatus == CMST_OK), ("Profile update failed" ));
}

#ifdef CSW_SUPPORTKEYLOCK

/*******************************************************************************
*
* FUNCTION: IsEmergencyNum
*
* $UniqueID:3EAFAA0802D6$
*
* $Parm:TL_IDLE_SCREENTYPE ScreenType$
* The new value for the Sceen type setting.
* $End$
*
* $Description$
* This function updates the setting for the Idle screen type stored in NV.
* $End$
*******************************************************************************/
/*$Function$*/
static BOOLEAN IsEmergencyNum( TI_MUI_IDLE_INTERFACE* This, int Lastkey )
{
	TS_PHONE_NUMBER   EmergencyPhoneNoStruct;
	BOOLEAN result = FALSE;
	
	int length = strlen(This->Private->m_SosString);
	if(length > 2)
	{
		memmove(This->Private->m_SosString, &This->Private->m_SosString[1], 3);
		sprintf(&This->Private->m_SosString[2], "%d", Lastkey);
	}
	else
	{
		sprintf(&This->Private->m_SosString[length], "%d", Lastkey);
	}
	
	LibPhoneNumFromUtf8( &EmergencyPhoneNoStruct, This->Private->m_SosString );
	
	if(EMER_MATCHED == LibPhoneNumCheckPartialEmergencyNum(&EmergencyPhoneNoStruct,ALL_EMERGENCY_NUMBER_MASK))
	{
		result = TRUE;
	}
	else if(length > 1)
	{
		LibPhoneNumFromUtf8( &EmergencyPhoneNoStruct, &This->Private->m_SosString[1] );
		if(EMER_MATCHED == LibPhoneNumCheckPartialEmergencyNum(&EmergencyPhoneNoStruct,ALL_EMERGENCY_NUMBER_MASK))
		{
			memmove(This->Private->m_SosString, &This->Private->m_SosString[1], 3);
			result = TRUE;
		}
	}

	return result;
}
#endif

/*******************************************************************************
*
* FUNCTION: CreateTodayLabel
*
* $UniqueID:3EAFAA0802D6$
*
* $Parm:TI_MUI_IDLE_INTERFACE This$
* The new value for the Sceen type setting.
* $End$
*
* $Description$
* This function create a label display current date.
* $End$
*******************************************************************************/
static void CreateTodayLabel(TI_MUI_IDLE_INTERFACE* This, UINT8 row, UINT8 column)
{
	char buffer[5];
	Arg args[16];
	int n;
	int x = CALENDAR_BORDER + (CALENDAR_COLUMN_WIDTH) * column + 9;
	int y = 3*CALENDAR_BORDER + CALENDAR_HDR_HEIGHT + CALENDAR_ROW_HEIGHT + row * This->Private->m_RowHeight + CALENDAR_SPR_HEIGHT;

	/* if the today label is exist */
	if(This->Private->m_TodayLabel)
	{
		n = 0;
		XtSetArg(args[n], XmNx,                 x); n++;
		XtSetArg(args[n], XmNy,                 y); n++;
		XtSetValues(This->Private->m_TodayLabel, args, n);
		sprintf(buffer, "%d", This->Private->m_DaysArray[row][column]);
		MuiAppSetText(This->Private->m_TodayLabel, buffer);
	    XtUnmapWidget( This->Private->m_TodayLabel );
	    XtMapWidget( This->Private->m_TodayLabel );
	}
	else
	{
		n = 0;
		XtSetArg(args[n], XmNx,                 x); n++;
		XtSetArg(args[n], XmNy,                 y); n++;
		XtSetArg(args[n], XmNwidth,             13 ); n++;
		XtSetArg(args[n], XmNheight,            This->Private->m_RowHeight ); n++;
		XtSetArg(args[n], XmNmarginWidth,       0 ); n++;
		XtSetArg(args[n], XmNmarginHeight,      0 ); n++;
		XtSetArg(args[n], XmNalignment,         XmALIGNMENT_END ); n++;
		XtSetArg(args[n], XmNalignmentVertical, XmALIGNMENT_MIDDLE ); n++;
		XtSetArg(args[n], XmNfontList,          **(XmFontList**)MUI_REDUCED_FONT ); n++;
		XtSetArg(args[n], XmNbackground,		0xf000); n++;
		XtSetArg(args[n], XmNforeground,		0xffff); n++;
		XtSetArg(args[n], XmNrecomputeSize,		FALSE); n++;
		This->Private->m_TodayLabel = XtCreateManagedWidget(NULL, xmLabelWidgetClass, MuiAppGetDlgItem( This->Private->m_Dlg, WIG_CAL_BBOARD ), args, n);
		sprintf(buffer, "%d", This->Private->m_DaysArray[row][column]);
		MuiAppSetText(This->Private->m_TodayLabel, buffer);
	}

}
/*******************************************************************************
*
* MACRO: mtws_SendEndKey_pressed
*
* $UniqueID:3E662D290379$
*
* <C_MUI_PBK_PROFILES* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_SendEndKey_pressed )
{
    TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;
	if(Data->event->type == KeyPress)
    {
        if(Data->event->xkey.keycode == XK_KEY_OFF_HOOK)
        {
        	FsmIfAddEvent(This, e_SendKeyPressed);
        }
        else if(Data->event->xkey.keycode == XK_KEY_ON_HOOK)
        {
        	FsmIfAddEvent(This, e_EndKeyPressed);
        }
        else
        {
        	Data->processed = FALSE;
        }
    }
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* FUNCTION: AreDesktopQuickMenuDataValid
*
* $UniqueID:
*
* $Parm:TI_MUI_IDLE_INTERFACE This$
* 
* $End$
*
* $Description$
* This function check the validaty in DB of Desktop and QuickMenu.
* $End$
*******************************************************************************/
static BOOLEAN AreDesktopDataValid (TI_MUI_IDLE_INTERFACE* This)
{
    BOOLEAN Ret = TRUE;
    UINT8 Format = FALSE;
    UINT16 i;
    TS_DATABASE_USER_DISPLAY_RECORD* Rec;

    UINT8   getData;
    UINT8   setData;


    /* Check the personalization L3 flag first */
    TS_PROFILE_DATA Profile;
    TS_CMD_STATUS CmdStatus;
        
    Profile.Id = SYSPRF_SYSCP_QUICKMENU_FORMAT_FLAG;
    Profile.Data = &Format;
    Profile.Size = 1;
    CmdStatus = MsApiSysCfgQueryProfile( &(This->Private->m_Session.Session),&Profile );
    
      /* Refer to MSL_ACPU_CNTRLFLG_4 flag */
	getData = (UINT8)Msl_OpeACPUCntrlFlgSetRef( MSL_FUNCREF, MSL_ACPU_CNTRLFLG_4, setData );

    if (CMST_OK == CmdStatus && 
        FALSE == Format &&  getData == 0 &&
        CMST_OK == MsApiReadDesktopShortcuts (This->Private->m_DesktopShortcutsPointer))
    {
        
        for (i = 0; i < MAX_SHORTCUTS_NUM && Ret; i++)
        {
            Rec = This->Private->m_DesktopShortcutsPointer[i];
            
            Ret = Ret && 
            (Rec->ApplicationId >= 0) &&
            (Rec->ApplicationId <= APM_APP_ID_MAX) &&
            (Rec->Icon >= GOBJ_FIRST_BITMAP) &&
            (Rec->Icon <= GOBJ_LAST_BITMAP) &&
            ( ((Rec->FixedTextId >= 0) && (Rec->FixedTextId < TS_TEXT_ID_DB_MAX))
             || (Rec->FixedTextId == INVALID_WORD_ID) );
             
			if(!Ret)
			{
             	return Ret;
			}
        }
    }
    else
    {
        Ret = FALSE;
    }
    
    /* Check whether Quick menu shortcut is valid */
    if (Ret == TRUE)
    {
		Rec = MM_malloc(sizeof(TS_DATABASE_USER_DISPLAY_RECORD));
        memset( Rec, 0, sizeof(TS_DATABASE_USER_DISPLAY_RECORD));
        for( i = 0; i < MAX_MY_MENU_SIZE; i++)
        {
            INIT_UTF( Rec->AlphaTag );
            memset(Rec->DataShortcutObjectHandle, 0xFF, 1025);
            if(CMST_OK == MsApiDmQueryRecord( CONN_ID_DM_ANONYMOUS_QUERY, SYSDM_MYMENU, SYSDM_SR_BY_RECORD_NUMBER,
            					SYSDM_WR_CURRENT, &i, (TS_DATABASE_RECORD_HANDLE)Rec,
            					sizeof(TS_DATABASE_USER_DISPLAY_RECORD), ""))
			{
	            Ret = Ret && 
	            (Rec->ApplicationId >= 0) &&
	            (Rec->ApplicationId <= APM_APP_ID_MAX) &&
	            (Rec->Icon >= GOBJ_FIRST_BITMAP) &&
	            (Rec->Icon <= GOBJ_LAST_BITMAP) &&
	            ( ((Rec->FixedTextId >= 0) && (Rec->FixedTextId < TS_TEXT_ID_DB_MAX))
	             || (Rec->FixedTextId == INVALID_WORD_ID) );
	
				if(!Ret)
				{
	             	break;
				}
			}
			else
			{
				Ret = FALSE;
			}
        }
        MM_free(Rec);
    }    	
    
    return Ret;
}

/*******************************************************************************
*
* FUNCTION: FormatDesktopQuickMenuData
*
* $UniqueID:
*
* $Parm:TI_MUI_IDLE_INTERFACE This$
* 
* $End$
*
* $Description$
* This function check the validaty in DB of Desktop and QuickMenu.
* $End$
*******************************************************************************/
static void FormatDesktopQuickMenuData (TI_MUI_IDLE_INTERFACE* This)
{
	int i, LastFixedItem = 0;
	UINT8   setData = 0;
    /* First lets format desktop data files 
     */
    /*Video file */
    {
        _MUI_FILE_DATA Data;
        memset(&Data, 0, sizeof(_MUI_FILE_DATA));
        Data.mem_type = 1;
        Data.file_type = ELIB_FS_ND_VIDEO;
        This->Private->m_DesktopShortcutsPointer[0]->ApplicationId = AM_AP_ID_FILEMGR_MAIN;
        This->Private->m_DesktopShortcutsPointer[0]->Icon          = IMG_IDL_DI_FOLDERVIDEO;
        This->Private->m_DesktopShortcutsPointer[0]->FixedTextId   = TXT_IDLE_DSKTOP_F_VIDEO;
        memcpy(This->Private->m_DesktopShortcutsPointer[0]->DataShortcutObjectHandle, &Data, sizeof(_MUI_FILE_DATA));
        This->Private->m_DesktopShortcutsPointer[0]->StartMode = 0;
    }

    /*Play music*/
    {
        _MMP_NORMAL_START_REQ Data;
        memset(&Data, 0, sizeof(_MMP_NORMAL_START_REQ));
        Data.type = 1;
        This->Private->m_DesktopShortcutsPointer[1]->ApplicationId = AM_AP_ID_WMEDIA_MAIN2;//26;
        This->Private->m_DesktopShortcutsPointer[1]->Icon          = IMG_IDL_DI_MELODYPLAYER;
        This->Private->m_DesktopShortcutsPointer[1]->FixedTextId   = WORD_TRE_MNU_MMP_MUSIC;
        memcpy(This->Private->m_DesktopShortcutsPointer[1]->DataShortcutObjectHandle, &Data, sizeof(_MMP_NORMAL_START_REQ));
        This->Private->m_DesktopShortcutsPointer[1]->StartMode = 0;
    }

    /*my photo*/
    {
        _MUI_FILE_DATA Data;
        memset(&Data, 0, sizeof(_MUI_FILE_DATA));
        Data.mem_type = 1;
        Data.file_type = ELIB_FS_ND_CapIMAGE;
        This->Private->m_DesktopShortcutsPointer[2]->ApplicationId = AM_AP_ID_FILEMGR_MAIN;//14
        This->Private->m_DesktopShortcutsPointer[2]->Icon          = IMG_IDL_DI_FOLDERIMAGE;
        This->Private->m_DesktopShortcutsPointer[2]->FixedTextId   = WORD_TRE_FIL_CAPIMAGE;
        memcpy(This->Private->m_DesktopShortcutsPointer[2]->DataShortcutObjectHandle, &Data, sizeof(_MUI_FILE_DATA));
        This->Private->m_DesktopShortcutsPointer[2]->StartMode = 0;
    }

    /* ring tone */
    {
        This->Private->m_DesktopShortcutsPointer[3]->ApplicationId = APM_APP_CONFIG_ID;
        This->Private->m_DesktopShortcutsPointer[3]->Icon          = IMG_IDL_DI_SET;
        This->Private->m_DesktopShortcutsPointer[3]->FixedTextId   = WORD_TTL_SET_PH_MD_RING;
        strcpy(This->Private->m_DesktopShortcutsPointer[3]->DataShortcutObjectHandle, "M81122");
        This->Private->m_DesktopShortcutsPointer[3]->StartMode = 0;
    }
    
    /* Video call options */
    {
        This->Private->m_DesktopShortcutsPointer[4]->ApplicationId = APM_APP_CONFIG_ID;
        This->Private->m_DesktopShortcutsPointer[4]->Icon          = IMG_IDL_DI_SET;
        This->Private->m_DesktopShortcutsPointer[4]->FixedTextId   = WORD_TRE_SET_VT_OPT;
        strcpy(This->Private->m_DesktopShortcutsPointer[4]->DataShortcutObjectHandle, "M822");
        This->Private->m_DesktopShortcutsPointer[4]->StartMode = 0;
    }
    
    /*Music files in MS */
    {
        _MUI_FILE_DATA Data;
        memset(&Data, 0, sizeof(_MUI_FILE_DATA));
        Data.mem_type = 0;
        Data.file_type = ELIB_FS_MS_AUDIO;
        This->Private->m_DesktopShortcutsPointer[5]->ApplicationId = AM_AP_ID_FILEMGR_MAIN;//14
        This->Private->m_DesktopShortcutsPointer[5]->Icon          = IMG_IDL_DI_FOLDERAUDIO;
        This->Private->m_DesktopShortcutsPointer[5]->FixedTextId   = WORD_TRE_FIL_AUDIO;
        memcpy(This->Private->m_DesktopShortcutsPointer[5]->DataShortcutObjectHandle, &Data, sizeof(_MUI_FILE_DATA));
        This->Private->m_DesktopShortcutsPointer[5]->StartMode = 0;
    }

	/* calendar */
    {
        This->Private->m_DesktopShortcutsPointer[6]->ApplicationId = AM_AP_ID_SCHEDULER_MAIN;
        This->Private->m_DesktopShortcutsPointer[6]->Icon          = IMG_IDL_DI_SCHDLR;
        This->Private->m_DesktopShortcutsPointer[6]->FixedTextId   = WORD_TRE_MNU_SCHDULER;
        This->Private->m_DesktopShortcutsPointer[6]->StartMode = 1;
    }

	/* to do */
    {
        This->Private->m_DesktopShortcutsPointer[7]->ApplicationId = AM_AP_ID_TODO_MAIN;
        This->Private->m_DesktopShortcutsPointer[7]->Icon          = IMG_IDL_SHT_13;
        This->Private->m_DesktopShortcutsPointer[7]->FixedTextId   = WORD_TRE_MNU_TODO;
        This->Private->m_DesktopShortcutsPointer[7]->StartMode = 0;
    }

    MsApiWriteDesktopShortcuts(This->Private->m_DesktopShortcutsPointer);
    
    /* Then lets format quickmenu data files 
     */
    {
        TS_DATABASE_USER_DISPLAY_RECORD* MyMenuItemArray;
        TS_DATABASE_USER_DISPLAY_RECORD* MyMenuItemArrayPointer[MAX_MY_MENU_SIZE];
        
        MyMenuItemArray = MM_malloc(MAX_MY_MENU_SIZE*sizeof(TS_DATABASE_USER_DISPLAY_RECORD));
        memset( MyMenuItemArray, 0, MAX_MY_MENU_SIZE*sizeof(TS_DATABASE_USER_DISPLAY_RECORD));
        
        for( i = 0; i < MAX_MY_MENU_SIZE; i++)
        {
            INIT_UTF( MyMenuItemArray[i].AlphaTag );
            memset(MyMenuItemArray[i].DataShortcutObjectHandle, 0xFF, 1025);
            MyMenuItemArrayPointer[i] = &MyMenuItemArray[i];
            MyMenuItemArray[i].ApplicationId = 0;
        }
        
        QUICK_MENU_FIX_ITEM_INIT((MyMenuItemArray[0]), SYSPRF_SYSCP_QUICKMENU_ITEM1_NAME_STRING, SYSPRF_SYSCP_QUICKMENU_ITEM1_OBJECT, SYSPRF_SYSCP_QUICKMENU_ITEM1_APPLICATIONID, SYSPRF_SYSCP_QUICKMENU_ITEM1_STARTMODE);
        QUICK_MENU_FIX_ITEM_INIT((MyMenuItemArray[1]), SYSPRF_SYSCP_QUICKMENU_ITEM2_NAME_STRING, SYSPRF_SYSCP_QUICKMENU_ITEM2_OBJECT, SYSPRF_SYSCP_QUICKMENU_ITEM2_APPLICATIONID, SYSPRF_SYSCP_QUICKMENU_ITEM2_STARTMODE);
        QUICK_MENU_FIX_ITEM_INIT((MyMenuItemArray[2]), SYSPRF_SYSCP_QUICKMENU_ITEM3_NAME_STRING, SYSPRF_SYSCP_QUICKMENU_ITEM3_OBJECT, SYSPRF_SYSCP_QUICKMENU_ITEM3_APPLICATIONID, SYSPRF_SYSCP_QUICKMENU_ITEM3_STARTMODE);
        QUICK_MENU_FIX_ITEM_INIT((MyMenuItemArray[3]), SYSPRF_SYSCP_QUICKMENU_ITEM4_NAME_STRING, SYSPRF_SYSCP_QUICKMENU_ITEM4_OBJECT, SYSPRF_SYSCP_QUICKMENU_ITEM4_APPLICATIONID, SYSPRF_SYSCP_QUICKMENU_ITEM4_STARTMODE);
        QUICK_MENU_FIX_ITEM_INIT((MyMenuItemArray[4]), SYSPRF_SYSCP_QUICKMENU_ITEM5_NAME_STRING, SYSPRF_SYSCP_QUICKMENU_ITEM5_OBJECT, SYSPRF_SYSCP_QUICKMENU_ITEM5_APPLICATIONID, SYSPRF_SYSCP_QUICKMENU_ITEM5_STARTMODE);
        
        MsApiWriteMyMenuShortcuts(MyMenuItemArrayPointer);
        MM_free(MyMenuItemArray);
        
        /* Format L3 flag set to 0, which means format finished. */
        {
            TS_PROFILE_DATA Profile;
            TS_CMD_STATUS CmdStatus;
            UINT8 Format = 0;
            
            Profile.Id = SYSPRF_SYSCP_QUICKMENU_FORMAT_FLAG;
            Profile.Data = &Format;
            Profile.Size = 1;
            CmdStatus = MsApiSysCfgUpdateProfile( &(This->Private->m_Session.Session),&Profile );
        }
        Msl_OpeACPUCntrlFlgSetRef( MSL_FUNCSET, MSL_ACPU_CNTRLFLG_4, setData );
    }
}

/*******************************************************************************
*
* FUNCTION: GetNoNumberReasonTextID
*
* $UniqueID:
*
* $Parm:T_CAUSE_OF_NOCLI_VAL reason$
* 
* $End$
*
* $Description$
* This function check the validaty in DB of Desktop and QuickMenu.
* $End$
*******************************************************************************/

TS_TEXT_ID GetNoNumberReasonTextID (T_CAUSE_OF_NOCLI_VAL reason )
{
 TS_TEXT_ID reanofnumber;
	switch (reason)
	{
		case 0:	reanofnumber = TXT_CL_MSG_UNNUMBER_SETUP;
				break;
		case 1: reanofnumber = TXT_CL_MSG_NOTICE_IMPOSSIBLE;
				break;
		case 2: reanofnumber = TXT_CL_MSG_PUBLIC_TELEPHONE;
				break;
		case 3:	reanofnumber = TXT_CL_MSG_NOTICE_IMPOSSIBLE;
				break;
		case 4: reanofnumber = TXT_CL_MSG_UNKNOWN;
				break;
		
		default:
				reanofnumber = TXT_CL_MSG_UNKNOWN;
				break;
	}
	return reanofnumber;
}

/*******************************************************************************
*
* FUNCTION: GetSystemProfile 
*
* $UniqueID:
*
* $Parm:T_CAUSE_OF_NOCLI_VAL reason$
* 
* $End$
*
* $Description$
* This function check the validaty in DB of Desktop and QuickMenu.
* $End$
*******************************************************************************/
static void GetSystemProfile (TI_MUI_IDLE_INTERFACE* This, TS_SYSTEM_PROFILE_ID ProfileId, size_t Size, void* Data)
{
    TS_PROFILE_DATA Profile;
    
    Profile.Id = ProfileId;
    Profile.Data = Data;
    Profile.Size = Size;
    MsApiSysCfgQueryProfile( &(This->Private->m_Session.Session),&Profile );
}

/*******************************************************************************
*
* FUNCTION: IsValidPhoneNum 
*
* $UniqueID:
*
* $Parm:_IM_CLIPBOARD * ClipBoadData$
* 
* $End$
*
* $Description$
* This function check if the ClipBoadData is a valid phone Number.
* $End$
*******************************************************************************/

static BOOLEAN IsValidPhoneNum(_IM_CLIPBOARD * ClipBoadData)
{
	int len = 0;
				
	/* check every word in clip board */
	for(len = 0; len < ClipBoadData->wSize ; len++)
	{
		if((0xff00 & ClipBoadData->pwText[len])
            || (((0x00ff & ClipBoadData->pwText[len]) <= '0')
            && ((0x00ff & ClipBoadData->pwText[len]) >= '9')
            && ((0x00ff & ClipBoadData->pwText[len]) != '?')
            && ((0x00ff & ClipBoadData->pwText[len]) != 'P')
            && ((0x00ff & ClipBoadData->pwText[len]) != '*')
            && ((0x00ff & ClipBoadData->pwText[len]) != '#')
            && ((0x00ff & ClipBoadData->pwText[len]) <= '+')))
        {
            return FALSE;
        }
	}
    return TRUE;

}

/*******************************************************************************
*
* FUNCTION: DisplayMissedCallDetail 
*
* $UniqueID:
*
* $Parm:TI_MUI_IDLE_INTERFACE* This$
* 
* $End$
*
* $Description$
* This function check the validaty in DB of Desktop and QuickMenu.
* $End$
*******************************************************************************/
static void DisplayMissedCallDetail (TI_MUI_IDLE_INTERFACE* This)
{
	/* First press side key */
	if(This->Private->m_MissedCallDisplayed == MISSED_CALL_NORMAL)
	{
		TS_DATABASE_CALL_LOG_RECORD* TempPtr = MM_malloc( sizeof(TS_DATABASE_CALL_LOG_RECORD) );
		MuiGetlatestCall( TempPtr, SYSDM_UNANSWERED_LOG );
		MsApiPopulateAlphaTag( &TempPtr->PhoneNum );

#ifdef CHW_SUBLCD
		Elib_DSP_BL_Erase( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF );
#else
#endif 

		/* Missed call name in PBK */
		if( !LibPhoneNameIsEmpty(&TempPtr->PhoneNum.Name) )
		{
			char Title[50];
			LibPhoneNameToUtf8( &TempPtr->PhoneNum.Name, Title, sizeof(Title) );

#ifdef CHW_SUBLCD
			Elib_DSP_BL_Dsp( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF_DSP, NULL, Title, 0);
#else
#endif 
		}
		else
		{
			char NumberBuffer[TS_PHONE_NUMBER_LEN];
			/* Missed call is number */
			if (TempPtr->UrlOrNumber == SYSCSVT_AD_TEL_NUMBER)
			{
				if (TempPtr->PhoneNum.Number.A[0]!= 0xff )
				{
					/* International number */
					if(TempPtr->PhoneNum.Number.Ton == TON_INTERNATIONAL)
					{
						NumberBuffer[0] = '+';
						LibPhoneNumToUtf8( &TempPtr->PhoneNum.Number, NumberBuffer+1, sizeof(NumberBuffer)-1, TS_PHONE_DIS_CALL );
					}
					else
					{
						LibPhoneNumToUtf8( &TempPtr->PhoneNum.Number, NumberBuffer, sizeof(NumberBuffer), TS_PHONE_DIS_CALL );
					}
				}
				else
				{
					/* Can't get missed call number */
					MsApiLngQueryGetCharString( NULL, NumberBuffer, sizeof(NumberBuffer), 
									GetNoNumberReasonTextID(TempPtr->CauseOfNocliVal), LNG_AUTO );
				}
			}
			else
			{
				/* Missed call number is Url */
				strcpy(NumberBuffer, TempPtr->UrlAddress.buf);
			}
#ifdef CHW_SUBLCD
			Elib_DSP_BL_Dsp( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF_DSP, NULL, NumberBuffer, 0);
#else
#endif 
		}
		/* Create a timer, Erase the sub lcd in 60s */
		if(This->Private->m_SubLcdTimer.InstancePtr)
		{
			MuiAppTimerDestroy(&This->Private->m_SubLcdTimer);
		}
		MuiAppTimerCreateFunction( &This->Private->m_SubLcdTimer, This, MissedCallTimerExpired, 0, 60000, TRUE, TRUE);
		MM_free(TempPtr);
		This->Private->m_MissedCallDisplayed = MISSED_CALL_DETAIL;
	}
	else if( This->Private->m_MissedCallDisplayed == MISSED_CALL_DETAIL )
	{
		MuiAppTimerDestroy(&This->Private->m_SubLcdTimer);

#ifdef CHW_SUBLCD
		Elib_DSP_BL_Erase( APM_APP_IDLE_ID, ELIB_DSP_BL_ABSNBF_DSP );
#else
#endif 

		This->Private->m_MissedCallDisplayed = MISSED_CALL_REMOVE;
	}

}

/*******************************************************************************
*
* MACRO: a_SetEmergencyNumber
*
* $UniqueID:3CC7D70400BF$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_SetEmergencyNumber )
{
    if(Qual==LOAD)
    {
		This->Private->m_EmergencyCallInterface = FsmIfCreateInstance(This, C_MUI_EMERGENCY_CALL);
		MuiSetEmergencyType( This->Private->m_EmergencyCallInterface, FALSE, This->Private->m_VoiceCallsClass, NULL );
    }
    else
    {
		FsmIfDeleteInstance(This->Private->m_EmergencyCallInterface);
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LaunchSIPaneError
*
* $UniqueID:3CC7D70400BF$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LaunchSIPaneError )
{
	if(Qual)
	{
		This->Private->m_DisplayMessage = FsmIfCreateInstance( This, C_MUI_DISPLAY_MESSAGE );
	    MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_WAR_2);
		This->Private->m_DisplayMessage->Public->m_TextId = TXT_IDLE_MSG_SIPANE_ATT;
	}
	else
	{
		FsmIfDeleteInstance( This->Private->m_DisplayMessage );
		This->Private->m_DisplayMessage = NULL;
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LaunchRedialError
*
* $UniqueID:3CC7D70400BF$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LaunchRedialError )
{
	if(Qual)
	{
		This->Private->m_DisplayMessage = FsmIfCreateInstance( This, C_MUI_DISPLAY_MESSAGE );
	    MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_WAR_2);
		This->Private->m_DisplayMessage->Public->m_TextId = TXT_CC_NO_NUM;
	}
	else
	{
		FsmIfDeleteInstance( This->Private->m_DisplayMessage );
		This->Private->m_DisplayMessage = NULL;
	}
}
END_PRIVATE_ACTION

#ifdef CSW_SUPPORTKEYLOCK
/*******************************************************************************
*
* MACRO: a_LoadKeyPressedScreen
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Any key is pressed when keypad lock is enabled.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadKeyPressedScreen )
{
	if(Qual)
	{
		XtMapWidget(This->Private->m_KeyLockLabel);
	}
	else
	{
		XtUnmapWidget(This->Private->m_KeyLockLabel);
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadKeyLockScreen
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Any key is pressed when keypad lock is enabled.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadKeyLockScreen )
{
	if(Qual)
	{
		MuiAppSetImageId(This->Private->m_KeyLockLabel, IMG_IDL_UNLOCK2);
		MuiAppTimerCreateEvent( &This->Private->m_KeyLockTimer, This, E_DONE, 4000, TRUE, TRUE);
	}
	else
	{
		if(This->Private->m_KeyLockTimer.InstancePtr)
		{
			MuiAppTimerDestroy(&This->Private->m_KeyLockTimer);
		}
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadUnlockScreen
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Menu key is pressed when keypad lock is enabled.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadUnlockScreen )
{
	if(Qual)
	{
		MuiAppSetImageId(This->Private->m_KeyLockLabel, IMG_IDL_UNLOCK1);
		MuiAppTimerCreateEvent( &This->Private->m_KeyLockTimer, This, E_DONE, 4000, TRUE, TRUE);
	}
	else
	{
		if(This->Private->m_KeyLockTimer.InstancePtr)
		{
			MuiAppTimerDestroy(&This->Private->m_KeyLockTimer);
		}
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_RestartTimer
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Menu key is pressed when keypad lock is enabled.
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_RestartTimer )
{
	MuiAppTimerDestroy(&This->Private->m_KeyLockTimer);
	MuiAppTimerCreateEvent( &This->Private->m_KeyLockTimer, This, E_DONE, 4000, TRUE, TRUE);
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_UnlockKeyPad
*
* $UniqueID:$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Unlock key pad
* 
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_UnlockKeyPad )
{
	MsApiSetKeyLockStatus( &This->Private->m_Session.Session, FALSE );

    /* reset the keypad, After we handle the press event in dial screen
	** the release key event should be discard.
	*/
	MuiAppMtwsReleaseKey( This->Private->m_Dlg->App->Protected->m_pKeyPad );
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_KeyLockEmergencyCnfDlg
*
* $UniqueID:3CC7D70400BF$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_KeyLockEmergencyCnfDlg )
{
    if(Qual)
    {
		char buffer[50];
		/* Display dial lock info */
		This->Private->m_DisplayMessage = FsmIfCreateInstance( This, C_MUI_DISPLAY_MESSAGE );
        MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_CNF_1);
        MuiSetByPassKeyPress(This->Private->m_DisplayMessage, TRUE);
        This->Private->m_DisplayMessage->Public->m_MaxDuration = 60000;
        MuiDisMsgSetSoftKey( This->Private->m_DisplayMessage, MUI_DLG_TEXT_LEFT, WORD_KEY_CMN_YES, e_StartKeyLockEmergency);
        MuiSetSendKey( This->Private->m_DisplayMessage, e_StartKeyLockEmergency);
        MuiDisMsgSetTickKey( This->Private->m_DisplayMessage, E_CANCEL);
        MuiDisMsgSetClearKey( This->Private->m_DisplayMessage, E_CANCEL);
        MuiSetEndKey( This->Private->m_DisplayMessage, E_CANCEL);
        
        MsApiLngQueryGetCharString (NULL, buffer, 50, TXT_IDLE_SOS_EMERGENCY, LNG_AUTO);
        sprintf(&buffer[strlen(buffer)], "\n\n%s", This->Private->m_SosString);
        MuiDisMsgLoadText(This->Private->m_DisplayMessage, buffer);
        
        MuiAppRegisterGrabEvent( This, XtTMAny, XtTEKey, 0, mtws_AnyKeyPress );
    }
    else
    {
    	FsmIfDeleteInstance (This->Private->m_DisplayMessage);
    	This->Private->m_DisplayMessage = NULL;
    	
    	MuiAppDeRegisterGrabEvent( This, mtws_AnyKeyPress_FNC );
    	This->Private->m_SosString[0] = '\0';
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: mtws_AnyKeyPress
*
* $UniqueID:3E662D290379$
*
* <C_MUI_PBK_PROFILES* This>
* This is a pointer to an instance of this class type.
* 
* <Widget w>
* this is a pointer to the widget that executed the callback func
*
* <XtPointer call_data>
* this is a pointer to data passed by the widget to your function
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_AnyKeyPress )
{
    TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;
	if(Data->event->type == KeyPress)
    {
        if(Data->event->xkey.keycode == XK_KEY_FUNCTION)
        {
        	FsmIfAddEvent(This, e_MenuKeyPressed);
			This->Private->m_SosString[0] = '\0';
        }
        else
        {
        	FsmIfAddEvent(This, e_AnyKeyPressed);
        	This->Private->m_SosString[0] = '\0';
        }
    }
}
END_PRIVATE_MTWS_CALLBACK

START_PRIVATE_ACTION ( a_StartKeyLockEmergency )
{
	MuiCsvSetDialString( This->Private->m_VoiceCallsClass, This->Private->m_SosString );
}
END_PRIVATE_ACTION

#endif

/*******************************************************************************
*
* MACRO: a_LoadWaitMainMenu
*
* $UniqueID:3CF35FC401F7$
*
* <C_MUI_APP_MENU* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
*
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadWaitMainMenu )
{
	if(Qual)
	{
		This->Private->m_DisplayMessage = FsmIfCreateInstance( This, C_MUI_DISPLAY_MESSAGE );
		MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_WAR_2);
		This->Private->m_DisplayMessage->Public->m_TextId = TXT_STK_BUSY_MENU_NAK2;
	}
	else
	{
		FsmIfDeleteInstance( This->Private->m_DisplayMessage );
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadNoSimPresentScreen
*
* $UniqueID:3C75308B012E$
*
* <C_MUI_POWER_UP* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Load or unload the no sim present screen
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadNoSimPresentScreen )
{
    if(Qual)
    {
		This->Private->m_EmergencyCallInterface = FsmIfCreateInstance(This, C_MUI_EMERGENCY_CALL);
		MuiSetEmergencyType( This->Private->m_EmergencyCallInterface, TRUE, This->Private->m_VoiceCallsClass, NULL );
		wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKSTOP );
    }
    else
    {
		FsmIfDeleteInstance(This->Private->m_EmergencyCallInterface);
		wMui_MLTW_ControlTaskChange( MuiAppGetApId(This), WMLTW_TASKRESTART );
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadNoSimWarning
*
* $UniqueID:3C75308B012E$
*
* <C_MUI_POWER_UP* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* Load or unload the no sim present screen
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadNoSimWarning )
{
	if(Qual)
	{
		This->Private->m_DisplayMessage = FsmIfCreateInstance( This, C_MUI_DISPLAY_MESSAGE );
		MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_WAR_2);
		This->Private->m_DisplayMessage->Public->m_TextId = TXT_IDLE_SIM;
	    MuiSetEndKey(This->Private->m_DisplayMessage, E_DONE);
	    MuiSetSendKey(This->Private->m_DisplayMessage, E_DONE);
	}
	else
	{
		FsmIfDeleteInstance( This->Private->m_DisplayMessage );
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* FUNCTION: MuiMtwsCallBackFunction
*
* $UniqueID:3DE3B4610124$
*
* $Parm:TI_GENERIC* This$
* <please add parmeter description here >
* $End$
*
* $Parm:void* DataPtr$
* <please add parmeter description here >
* $End$
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
/*$Function$*/
static void MuiMtwsCallBackFunction( TI_GENERIC* This, void* DataPtr )
{
    BOOLEAN flag;
    TS_GFSM_HANDLE_ITEM* child;
    TL_GFSM_THREAD *Thread = This->ThisInst.Thread;
    int i, imax = Thread->m_InstanceArray.ItemCount;
    
	flag = *(BOOLEAN*)DataPtr;
	
	if(flag)
	{
		for (i = 0; i < imax; i++)
		{
			if (child = (TS_GFSM_HANDLE_ITEM*)LibArrayElementAt( &Thread->m_InstanceArray, i ))
			{
				FsmIfAddEvent (child->This, e_AutoClose);
			}
		}
	}
}

/*******************************************************************************
*
* MACRO: a_LoadAttachFailMessage
*
* $UniqueID:3CC7D704023105$
*
* <TI_MUI_IDLE_INTERFACE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $End$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadAttachFailMessage )
{

    if(Qual==LOAD)
    {
        This->Private->m_bAttachFailDisplaying = TRUE;
		/* Display network attach failure info */
		This->Private->m_DisplayMessage = FsmIfCreateInstance( This, C_MUI_DISPLAY_MESSAGE );
        MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_WAR_2);
        This->Private->m_DisplayMessage->Public->m_TextId = TXT_IDLE_DLG_MNL_PLMN;
    }
    else
    {
        This->Private->m_bAttachFailDisplaying = FALSE;
        FsmIfDeleteInstance(This->Private->m_DisplayMessage);
    }
}
END_PRIVATE_ACTION
/* *************************************************************************** */
/* *********************************** END *********************************** */
/* *************************************************************************** */

