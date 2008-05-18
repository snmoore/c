/* *************************************************************************** */
/* ****************************** DEFINE MACROS ****************************** */
/* *************************************************************************** */
#define GEN_DEFINE_MACROS
#include "TiGenericInt.m"

/* *************************************************************************** */
/* ******************************** CLASS NAME ******************************* */
/* *************************************************************************** */
GEN_DECLARE_CLASS( TI_MUI_IDLE_INTERFACE )

/* *************************************************************************** */
/* ********************************** STATES ********************************* */
/* *************************************************************************** */
GEN_STA_START              ( Initial, s_ROOT, Start, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_Entry, TRUE )
    GEN_STA_ADD_TRA        ( InService, e_Start, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, ClassContainer, PseudoSSActive, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadPSSClass, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadPSSClass, UNLOAD )
GEN_STA_END


GEN_STA_START              ( Normal, ClassContainer, NumberEntry, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadDigitsScreen, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadDigitsScreen, UNLOAD )
    GEN_STA_ADD_TRA        ( PseudoSSActive, e_GotoPss, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( DialMenu, e_GotoMenu, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, VoiceCallsInactive, StartVideoCall, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))   
	GEN_STA_ADD_ENTRY	   ( a_StartVideoCall, LOAD )
	GEN_STA_ADD_EXIT	   ( a_StartVideoCall, UNLOAD )
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( InService, E_CANCEL, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, ClassContainer, StartPhonebook, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
GEN_STA_END

GEN_STA_START              ( Normal, ClassContainer, DialMenu, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadDialMenu, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadDialMenu, UNLOAD )
    GEN_STA_ADD_TRA        ( NumberEntry, e_CloseOptionMenu, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( NumberEntry, E_CANCEL, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( InService, e_SendKeyPressed, G_TRUE, 0, a_ClearBuffer, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, VoiceCallsInactive, ClassContainer, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_TRA        ( InService, E_CANCEL, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( StartPhonebook, e_PbkCreate, G_TRUE, 0, a_CreatePhonebook, REQ_PBK_CREATE )
    GEN_STA_ADD_TRA        ( StartPhonebook, e_PbkFastView, G_TRUE, 0, a_CreatePhonebook, REQ_PBK_FAST_VIEW )
    GEN_STA_ADD_TRA        ( StartPhonebook, e_PbkFastDial, G_TRUE, 0, a_CreatePhonebook, REQ_PBK_FAST_DIAL )
    GEN_STA_ADD_TRA        ( StartPhonebook, e_PbkFastVt, G_TRUE, 0, a_CreatePhonebook, REQ_PBK_FAST_VT )
    GEN_STA_ADD_TRA        ( StartVideoCall, e_VideoCall, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( InService, e_AutoClose, G_TRUE, 0, a_ClearBuffer, 0 )
    GEN_STA_ADD_TRA        ( InService, e_EndKeyPressed, G_TRUE, 0, a_ClearBuffer, 0 )
    GEN_STA_ADD_TRA        ( VideoCallControl, e_VideoControl, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( UrlVideoCallControl, e_UrlVideoControl, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, BaseService, ModeControl, s_NULL )
	GEN_STA_COMMENT            ((<please add description here >))
	GEN_STA_ADD_ENTRY          ( a_LoadModeControl, LOAD )
	GEN_STA_ADD_EXIT           ( a_LoadModeControl, UNLOAD )
	GEN_STA_ADD_INT            ( E_DONE, G_TRUE, 0, a_JudgeMCAction, 0)
	GEN_STA_ADD_INT            ( e_StartCellSearch, G_TRUE, 0, a_CellSearch, 0)
	GEN_STA_ADD_INT            ( e_3GCellFound, G_TRUE, 0, a_ModeChangeRequest, 0 )
	GEN_STA_ADD_INT            ( e_3GCellNotFound, G_TRUE, 0, a_ConfirmModeChange, 0 )
	GEN_STA_ADD_INT            ( e_ModeChangeSuccess, G_TRUE, 0, a_LoadModeChangeNotice, TRUE)
	GEN_STA_ADD_INT            ( e_ModeChangeFailure, G_TRUE, 0, a_LoadModeChangeNotice, FALSE)
	GEN_STA_ADD_TRA            ( InService, E_CANCEL, G_TRUE, 0, a_MCExit, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, Service, InService, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
	GEN_STA_ADD_INT		   ( e_Refresh, G_TRUE, 0, a_RefreshService, 0)
	GEN_STA_ADD_INT		   ( e_Left, G_TRUE, 0, a_CreateCallLogClass, IDLE_INCOMING_LOG)
	GEN_STA_ADD_INT		   ( e_Right, G_TRUE, 0, a_CreateCallLogClass, IDLE_UNANSWERED_LOG)
	GEN_STA_ADD_INT		   ( e_SendKeyPressed, G_TRUE, 0, a_CreateCallLogClass, IDLE_REDIAL_LOG)
    GEN_STA_ADD_TRA        ( IdleMenu, e_GotoMenu, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( ActiveMode, e_Active, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( DialLockEmergencyCall, e_StartDialLockEmergency, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( UnDialLock, e_GotoUnlockDial, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( KeyPressedWhenLocked, e_KeyPressedWhenLocked, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( DialLockStatus, e_KeyPressed, G_TRUE, 0, A_NULL, 0 )
	GEN_STA_ADD_TRA        ( PleaseWait, e_WaitMainMenu, G_TRUE, 0, A_NULL, 0 )
	GEN_STA_ADD_TRA        ( RedialError, e_RedialError, G_TRUE, 0, A_NULL, 0 )
#ifdef CSW_SUPPORTKEYLOCK
    GEN_STA_ADD_TRA        ( MenuKeyPressed, e_MenuKeyPressed, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( AnyKeyPressed, e_AnyKeyPressed, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( AnyKeyPressed, e_AsterKeyPressed, G_TRUE, 0, A_NULL, 0 )
#endif
GEN_STA_END

GEN_STA_START              ( Normal, VoiceCallsInactive, NoSimPresent, s_NULL )
	GEN_STA_ADD_ENTRY      ( a_LoadNoSimPresentScreen, LOAD )
	GEN_STA_ADD_EXIT       ( a_LoadNoSimPresentScreen, UNLOAD )
GEN_STA_END

GEN_STA_START              ( Normal, Service, SimEscapedWarning, s_NULL )
	GEN_STA_ADD_ENTRY      ( a_LoadNoSimWarning, LOAD )
	GEN_STA_ADD_EXIT       ( a_LoadNoSimWarning, UNLOAD )
    GEN_STA_ADD_TRA        ( NoSimPresent, E_DONE, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, Service, KeyPressedWhenLocked, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadUnlockKeyPad, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadUnlockKeyPad, UNLOAD )
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( KeyPressedWhenLocked, e_KeyPressedWhenLocked, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, Service, ActiveMode, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_SetDefaultFocus, 0 )
    GEN_STA_ADD_EXIT       ( a_KillFocus, 0 )
    GEN_STA_ADD_INT        ( e_Left, g_SIPaneActive, TRUE, a_ShowPreviousSIMsg, 0 )
    GEN_STA_ADD_INT        ( e_Right, g_SIPaneActive, TRUE, a_ShowNextSIMsg, 0 )
	GEN_STA_ADD_INT        ( e_Left, g_SIPaneActive, FALSE, a_MoveFocusLeft, 0 )
    GEN_STA_ADD_INT        ( e_Right, g_SIPaneActive, FALSE, a_MoveFocusRight, 0 )
	GEN_STA_ADD_INT        ( e_Up, G_TRUE, 0, a_MoveFocusUp, 0)
	GEN_STA_ADD_INT        ( e_Down, G_TRUE, 0, a_MoveFocusDown, 0)
	GEN_STA_ADD_INT		   ( e_Active, G_TRUE, 0, a_RunShortcut, 0)
	GEN_STA_ADD_INT		   ( e_Refresh, G_TRUE, 0, a_RefreshDesktop, 0)
    GEN_STA_ADD_TRA        ( LaunchSIPaneError, e_RunShortcutError, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( Service, E_CANCEL, G_TRUE, 0, A_NULL, 0 )
	GEN_STA_ADD_TRA        ( ConfirmShortcutDelete, e_PreDelete, g_SIPaneActive, FALSE, A_NULL, 0 )
	GEN_STA_ADD_INT        ( e_PreDelete, g_SIPaneActive, TRUE, a_DeleteSIMsg, 0)
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( InService, e_AutoClose, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, Service, LaunchSIPaneError, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LaunchSIPaneError, LOAD )
    GEN_STA_ADD_EXIT       ( a_LaunchSIPaneError, UNLOAD )
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, Service, RedialError, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LaunchRedialError, LOAD )
    GEN_STA_ADD_EXIT       ( a_LaunchRedialError, UNLOAD )
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, Service, ConfirmShortcutDelete, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_ShowDelShortcutCnfDlg, TRUE )
    GEN_STA_ADD_EXIT       ( a_ShowDelShortcutCnfDlg, FALSE )
    GEN_STA_ADD_TRA        ( ActiveMode, E_CANCEL, G_TRUE, 0, a_Cancel_DeleteShortcut, 0 )
    GEN_STA_ADD_TRA        ( ActiveMode, E_DONE, G_TRUE, 0, a_DeleteShortcut, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, Service, SwapAlsLine, s_NULL )
   GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadVerifyPIN2, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadVerifyPIN2, UNLOAD )
    GEN_STA_ADD_TRA        ( InService, E_CANCEL, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, a_SwitchAlsLine, 0 )
    GEN_STA_ADD_TRA        ( InService, E_Blocked, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, MenuState, DialLock, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadDialLockVerify, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadDialLockVerify, UNLOAD )
    GEN_STA_ADD_TRA        ( IdleMenu, E_CANCEL, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( InService, E_Blocked, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, BaseService, UnDialLock, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadDialLockVerify, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadDialLockVerify, UNLOAD )
    GEN_STA_ADD_TRA        ( InService, E_CANCEL, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( InService, E_Blocked, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, BaseService, DialLockEmergencyCall, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_SetEmergencyNumber, LOAD )
    GEN_STA_ADD_EXIT       ( a_SetEmergencyNumber, UNLOAD )
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, MenuState, IdleMenu, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
	GEN_STA_ADD_INT			( e_CallLogsMenu, G_TRUE, 0, a_CreateCallLogClass, IDLE_MENU_LOG)
    GEN_STA_ADD_TRA        ( DialLock, e_EnableDialLock, G_TRUE, FALSE, A_NULL, 0 )
	GEN_STA_ADD_TRA        ( PleaseWait, e_WaitMainMenu, G_TRUE, 0, A_NULL, 0 )
	GEN_STA_ADD_TRA        ( InService, e_AutoClose, G_TRUE, 0, A_NULL, 0 )
	GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, MenuState, PleaseWait, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadWaitMainMenu, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadWaitMainMenu, UNLOAD )
	GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, BaseService, MenuState, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadIdleMenu, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadIdleMenu, UNLOAD )
    GEN_STA_ADD_TRA        ( InService, e_Refresh, G_TRUE, 0, a_RefreshService, 0 )
    GEN_STA_ADD_TRA        ( InService, e_CloseOptionMenu, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( ModeControl, e_GotoModeControl, G_TRUE, 0, A_NULL, 0)
GEN_STA_END

#ifdef CSW_SUPPORTKEYLOCK

GEN_STA_START              ( Normal, BaseService, KeyPressed, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadKeyPressedScreen, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadKeyPressedScreen, UNLOAD )
GEN_STA_END

GEN_STA_START              ( Normal, KeyPressed, AnyKeyPressed, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadKeyLockScreen, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadKeyLockScreen, UNLOAD )
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( MenuKeyPressed, e_MenuKeyPressed, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( KeyLockEmergencyCall, e_StartKeyLockEmergency, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_INT		   ( e_AnyKeyPressed, G_TRUE, 0, a_RestartTimer, 0)
GEN_STA_END

GEN_STA_START              ( Normal, KeyPressed, MenuKeyPressed, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadUnlockScreen, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadUnlockScreen, UNLOAD )
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( InService, e_AsterKeyPressed, G_TRUE, 0, a_UnlockKeyPad, 0 )
    GEN_STA_ADD_TRA        ( AnyKeyPressed, e_AnyKeyPressed, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_INT		   ( e_MenuKeyPressed, G_TRUE, 0, a_RestartTimer, 0)
GEN_STA_END

GEN_STA_START              ( Normal, Service, KeyLockEmergencyCall, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_KeyLockEmergencyCnfDlg, LOAD )
    GEN_STA_ADD_EXIT       ( a_KeyLockEmergencyCnfDlg, UNLOAD )
    GEN_STA_ADD_INT        ( e_StartKeyLockEmergency, G_TRUE, 0, a_StartKeyLockEmergency, 0)
    GEN_STA_ADD_TRA        ( MenuKeyPressed, e_MenuKeyPressed, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( AnyKeyPressed, e_AnyKeyPressed, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( InService, E_CANCEL, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END
#endif

GEN_STA_START              ( Normal, BaseService, Service, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_TRA        ( StartPhonebook, e_GotoPhonebookView, G_TRUE, 0, a_CreatePhonebook, REQ_PBK_VIEW )
    GEN_STA_ADD_TRA        ( StartPhonebook, e_GotoPhonebookSearch, G_TRUE, 0, a_CreatePhonebook, REQ_PBK_SEARCH )
    GEN_STA_ADD_TRA        ( ModeControl, e_GotoModeControl, G_TRUE, 0, A_NULL, 0)
    GEN_STA_ADD_TRA        ( SwapAlsLine, e_VerifyPIN2, G_TRUE, 0, A_NULL, 0 )
#ifdef CSW_SUPPORTKEYLOCK
    GEN_STA_ADD_TRA        ( KeyLockEmergencyCall, e_StartKeyLockEmergency, G_TRUE, 0, A_NULL, 0 )
#endif
GEN_STA_END

GEN_STA_START              ( Normal, VoiceCallsInactive, BaseService, s_NULL )
    GEN_STA_ADD_ENTRY      ( a_LoadService, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadService, UNLOAD )
	GEN_STA_ADD_INT		   ( e_SetVolumeUp, G_TRUE, 0, a_SetVolumeUp, 0)
	GEN_STA_ADD_INT		   ( e_SetVolumeLow, G_TRUE, 0, a_SetVolumeLow, 0)
	GEN_STA_ADD_TRA        ( InService, e_SendKeyPressed, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( NumberEntry, e_DigitsPresent, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( InService, e_EndKeyPressed, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( VideoCallControl, e_VideoControl, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( UrlVideoCallControl, e_UrlVideoControl, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( FdnRestricted, e_FdnRestricted, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, s_ROOT, VoiceCallsInactive, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadIdleScreen, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadIdleScreen, UNLOAD )
    GEN_STA_ADD_TRA        ( VoiceCallsActive, E_VoiceCallsActive, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( SimEscapedWarning, e_SimRemoved, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( NwrkAttachFail, e_NwrkAttachFail, G_TRUE, 0, A_NULL, 0 )
	GEN_STA_ADD_INT		   ( e_HideVolume, G_TRUE, 0, a_HideVolume, 0)
GEN_STA_END

GEN_STA_START              ( Normal, VoiceCallsInactive, NwrkAttachFail, s_NULL )
	GEN_STA_COMMENT        ((<please add description here >))
	GEN_STA_ADD_ENTRY      ( a_LoadAttachFailMessage, LOAD )
	GEN_STA_ADD_EXIT       ( a_LoadAttachFailMessage, UNLOAD )
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0)
GEN_STA_END

GEN_STA_START              ( Final, s_ROOT, Exit, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_EXIT       ( a_Entry, FALSE )
GEN_STA_END


GEN_STA_START              ( Normal, s_ROOT, VoiceCallsActive, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_FocusThisApplication, 0 )
    GEN_STA_ADD_EXIT       ( a_RetrieveVoiceCallString, 0 )
	GEN_STA_ADD_INT		   ( e_HideVolume, G_TRUE, 0, a_HideVolume, 0)
    GEN_STA_ADD_TRA        ( InService, E_VoiceCallsInactive, g_SIMRemoved, FALSE, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( NoSimPresent, E_VoiceCallsInactive, g_SIMRemoved, TRUE, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, VoiceCallsInactive, VideoCallControl, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadVideoCallControl, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadVideoCallControl, UNLOAD )
    GEN_STA_ADD_TRA        ( InService, E_CANCEL, G_TRUE, 0, a_StartVoiceCall, FALSE )
    GEN_STA_ADD_INT        ( E_DONE, G_TRUE, 0, a_StartVoiceCall, TRUE)
GEN_STA_END

GEN_STA_START              ( Normal, VoiceCallsInactive, UrlVideoCallControl, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadUrlVideoCallControl, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadUrlVideoCallControl, UNLOAD )
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, FALSE )
GEN_STA_END

GEN_STA_START              ( Normal, VoiceCallsInactive, FdnRestricted, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadFdnRestricted, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadFdnRestricted, UNLOAD )
    GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, FALSE )
GEN_STA_END

GEN_STA_START              ( Normal, BaseService, DialLockStatus, s_NULL )
	GEN_STA_COMMENT        ((<please add description here >))
	GEN_STA_ADD_ENTRY      ( a_LoadMessage, LOAD )
	GEN_STA_ADD_EXIT       ( a_LoadMessage, UNLOAD )
	GEN_STA_ADD_TRA        ( InService, E_DONE, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( ModeControl, e_GotoModeControl, G_TRUE, 0, A_NULL, 0)
GEN_STA_END
/* *************************************************************************** */
/* ***************************** INTERNAL EVENTS ***************************** */
/* *************************************************************************** */
GEN_DECLARE_EVENT ( e_Start )
GEN_DECLARE_EVENT ( e_PbkCreate )
GEN_DECLARE_EVENT ( e_PbkFastView )
GEN_DECLARE_EVENT ( e_PbkFastDial )
GEN_DECLARE_EVENT ( e_VideoCall )
GEN_DECLARE_EVENT ( e_PbkFastVt )
GEN_DECLARE_EVENT ( e_DigitsPresent )
GEN_DECLARE_EVENT ( e_GotoPhonebookView )
GEN_DECLARE_EVENT ( e_GotoPhonebookSearch )
GEN_DECLARE_EVENT ( e_KeyPressedWhenLocked )
GEN_DECLARE_EVENT ( e_DisableKeyLock )
GEN_DECLARE_EVENT ( e_GotoPss )
GEN_DECLARE_EVENT ( e_GotoMenu )
GEN_DECLARE_EVENT ( e_Active )
GEN_DECLARE_EVENT ( e_PreDelete )
GEN_DECLARE_EVENT ( e_Refresh )
GEN_DECLARE_EVENT ( e_CallLogsMenu )
GEN_DECLARE_EVENT ( e_EnableDialLock )
GEN_DECLARE_EVENT ( e_Delete )
GEN_DECLARE_EVENT ( e_Left )
GEN_DECLARE_EVENT ( e_Right )
GEN_DECLARE_EVENT ( e_Up )
GEN_DECLARE_EVENT ( e_Down )
GEN_DECLARE_EVENT ( e_HideVolume )
GEN_DECLARE_EVENT ( e_SetVolumeUp )
GEN_DECLARE_EVENT ( e_SetVolumeLow )
GEN_DECLARE_EVENT ( e_3GCellFound )
GEN_DECLARE_EVENT ( e_3GCellNotFound )
GEN_DECLARE_EVENT ( e_ModeChangeSuccess )
GEN_DECLARE_EVENT ( e_ModeChangeFailure )
GEN_DECLARE_EVENT ( e_StartCellSearch )
GEN_DECLARE_EVENT ( e_GotoModeControl )
GEN_DECLARE_EVENT ( e_GotoUnlockDial )
GEN_DECLARE_EVENT ( e_StartDialLockEmergency )
GEN_DECLARE_EVENT ( e_StartDefaultEmergency )
GEN_DECLARE_EVENT ( e_VideoControl )
GEN_DECLARE_EVENT ( e_UrlVideoControl )
GEN_DECLARE_EVENT ( e_FdnRestricted )
GEN_DECLARE_EVENT ( e_VerifyPIN2 )
GEN_DECLARE_EVENT ( e_KeyPressed )
GEN_DECLARE_EVENT ( e_EndKeyPressed )
GEN_DECLARE_EVENT ( e_SendKeyPressed )
GEN_DECLARE_EVENT ( e_CloseOptionMenu )
GEN_DECLARE_EVENT ( e_AutoClose )
GEN_DECLARE_EVENT ( e_RunShortcutError )
GEN_DECLARE_EVENT ( e_WaitMainMenu )
GEN_DECLARE_EVENT ( e_SimRemoved )
GEN_DECLARE_EVENT ( e_RedialError )
#ifdef CSW_SUPPORTKEYLOCK
GEN_DECLARE_EVENT ( e_AnyKeyPressed )
GEN_DECLARE_EVENT ( e_MenuKeyPressed )
GEN_DECLARE_EVENT ( e_AsterKeyPressed )
GEN_DECLARE_EVENT ( e_StartKeyLockEmergency )
#endif
GEN_DECLARE_EVENT ( e_NwrkAttachFail )
GEN_DECLARE_EVENT ( e_MCendkey )
/* *************************************************************************** */
/* ****************************** USER DEFINED ******************************* */
/* *************************************************************************** */
/*$User$*/

#define GEN_DEFINE_MACROS
#include "MuiApplicationDlg.m"

#ifdef ATOMBUILD
    #define CALENDAR_ROW_HEIGHT             12
    #define CALENDAR_HDR_HEIGHT             15
    #define CALENDAR_HEIGHT                 96
    #define CALENDAR_COLUMN_WIDTH           24
    #define CALENDAR_BORDER                 1
    #define CALENDAR_SPR_HEIGHT             1
    #define CALENDAR_COLUMN_START			6

    #define SHORTCUT_ROW_HEIGHT             38
    #define SHORTCUT_ROW_HEIGHT_CAL         38
    #define SHORTCUT_BEGIN_Y                84
    #define SHORTCUT_BEGIN_X                0
    #define SHORTCUT_BEGIN_Y_CAL            84
    #define SHORTCUT_WIDTH                  MUI_APP_WIDTH
    #define SHORTCUT_COLUMN_WIDTH           (SHORTCUT_WIDTH / 4)
    #define SHORTCUT_HEIGHT                 (2 * SHORTCUT_ROW_HEIGHT)
    #define SHORTCUT_HEIGHT_CAL             (2 * SHORTCUT_ROW_HEIGHT_CAL)

    #define SAT_PANE_BEGIN_X                0
    #define SAT_PANE_BEGIN_Y                40
    #define SAT_PANE_WIDTH                  MUI_APP_WIDTH
    #define SAT_PANE_HEIGHT                 44
#else
    #define CALENDAR_ROW_HEIGHT             12
    #define CALENDAR_HDR_HEIGHT             15
    #define CALENDAR_HEIGHT                 96
    #define CALENDAR_COLUMN_WIDTH           24
    #define CALENDAR_BORDER                 1
    #define CALENDAR_SPR_HEIGHT             1
    #define CALENDAR_COLUMN_START			6

    #define SHORTCUT_ROW_HEIGHT             38
    #define SHORTCUT_ROW_HEIGHT_CAL         44
    #define SHORTCUT_BEGIN_Y                104
    #define SHORTCUT_BEGIN_X                0
    #define SHORTCUT_BEGIN_Y_CAL            92
    #define SHORTCUT_WIDTH                  MUI_APP_WIDTH
    #define SHORTCUT_COLUMN_WIDTH           (SHORTCUT_WIDTH / 4)
    #define SHORTCUT_HEIGHT                 (2 * SHORTCUT_ROW_HEIGHT)
    #define SHORTCUT_HEIGHT_CAL             (2 * SHORTCUT_ROW_HEIGHT_CAL)

    #define SAT_PANE_BEGIN_X                0
    #define SAT_PANE_BEGIN_Y                48
    #define SAT_PANE_WIDTH                  MUI_APP_WIDTH
    #define SAT_PANE_HEIGHT                 48
#endif

MTWS_START_DIALOG ( DLG_SERVICE )
    MTWS_DLG_EVENT( XtTMAny,  XtTEKey,   XK_KEY_SOFT1, mtws_SKIdleAction)
    MTWS_DLG_EVENT( XtTMAny,  XtTEKey,   XK_KEY_SOFT2, mtws_SKIdleAction)
    MTWS_DLG_EVENT( XtTMAny,  XtTEKeyUp, XK_KEY_SOFT2, mtws_SKIdleAction)
    MTWS_DLG_EVENT( XtTMAny,  XtTEKey,   XK_KEY_ON_HOOK, mtws_EndKeyPressed )
	MTWS_DLG_EVENT( XtTMAny, XtTEKey, 0, mtws_ProcessKeysInService )
#ifdef CSW_SUPPORTKEYLOCK
	MTWS_DLG_EVENT( XtTMAny, XtTEKeyUp, 0, mtws_ProcessKeysInService )
#endif
    MTWS_DLG_EVENT( XtTMAny, XtTEKey, XK_KEY_NAVI_ETR, mtws_TickKey )
   	MTWS_DLG_EVENT( XtTMAny, XtTEKey, XK_KEY_OFF_HOOK, mtws_SendKeyPressed )
    MTWS_DLG_EVENT( XtTMAny, XtTEKey, XK_Left, mtws_LeftKey )
    MTWS_DLG_EVENT( XtTMAny, XtTEKey, XK_Right, mtws_RightKey )

    MTWS_DLG_EVENT( 0,        XtTEKey,   XK_KEY_OPTION,  mtws_MenuKey)
    MTWS_DLG_EVENT( XtTMLong,  XtTEKey,   XK_KP_SHARP,  mtws_AlsSwitchLine)
    MTWS_DLG_EVENT( XtTMAny,  XtTEKeyUp,   XK_KP_SHARP,  mtws_AlsSwitchLine)
    MTWS_DLG_EVENT( 0,        XtTEKey,   XK_Up,        mtws_UpKeyPressed)
    MTWS_DLG_EVENT( 0,        XtTEKey,   XK_Down,      mtws_DownKeyPressed)
    MTWS_DLG_EVENT( XtTMAny,  XtTEKey,   XK_KEY_CLEAR, mtws_FocusOnDial)
    MTWS_DLG_EVENT( XtTMAny,  XtTEKeyUp,   XK_KEY_CLEAR, mtws_FocusOnDial)
    MTWS_DLG_EVENT( 0,        XtTEKey,    XK_EAR_SW,   mtws_SwitchKeyPressed)

#ifdef CHW_SIDEKEY
    MTWS_DLG_EVENT( XtTMAny,  XtTEKey,   XK_KEY_Page_Down, mtws_SetVolumeLow )
    MTWS_DLG_EVENT( XtTMAny,  XtTEKey,   XK_KEY_Page_Up, mtws_SetVolumeHigh )
    MTWS_DLG_EVENT( XtTMAny,  XtTEKeyUp,   XK_KEY_Page_Down, mtws_SetVolumeLow )
    MTWS_DLG_EVENT( XtTMAny,  XtTEKeyUp,   XK_KEY_Page_Up, mtws_SetVolumeHigh )
#endif
	MTWS_DLG_EVENT( XtTMAny, XtTEKey, 0, mtws_OneTouchDial )

#ifdef ATOMBUILD    /* Cosmobic Dana Liu COS_ATOM_0037 */
    MTWS_START_WIDGET( BulletinBoard, WIG_SERVICE_WALLPAPER )
        MTWS_SET_ARG( XmNx, 0 )
        MTWS_SET_ARG( XmNy, 2 )
        MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH )
        MTWS_SET_ARG( XmNheight, MUI_APP_BASE_HEIGHT )
#else   /* Cosmobic Dana Liu COS_ATOM_0037 */
#endif  /* Cosmobic Dana Liu COS_ATOM_0037 */

    MTWS_START_WIDGET ( TextEdit, WIG_IDLE_STRING )
        MTWS_SET_ARG( XmNx, MUI_APP_WIDTH )
        MTWS_SET_ARG( XmNy, MUI_APP_BASE_HEIGHT-80 )
        MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH )
        MTWS_SET_ARG( XmNheight, 60 )
        MTWS_SET_ARG( XmNrows,3 )
        MTWS_SET_ARG( XmNrecomputeSize, False )
        MTWS_SET_ARG( XmNmaxLength, 37 )
		MTWS_SET_ARG( XmNcharMode, XmCHAR_DIALDIG )
        MTWS_SET_ARG( XmNactivate, TRUE )
        MTWS_ADD_BACK(XmNvalueChangedCallback, mtws_IdleDigitsStrChange )
    MTWS_END_WIDGET

    MTWS_START_WIDGET ( Label, WIG_PLMN )
#ifdef ATOMBUILD
        MTWS_SET_ARG( XmNx, 0 )
        MTWS_SET_ARG( XmNy, 0 )
        MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH )
        MTWS_SET_ARG( XmNheight, 20 )
#else
        MTWS_SET_ARG( XmNx, 0 )
        MTWS_SET_ARG( XmNy, 0 )
        MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH )
	MTWS_SET_ARG( XmNheight, MUI_APP_LINE_HEIGHT )
#endif
		MTWS_SET_ARG( XmNrecomputeSize, TRUE )
        MTWS_SET_ARG( XmNmarginWidth, 0 )
        MTWS_SET_ARG( XmNmarginHeight, 0 )
        MTWS_SET_ARG( XmNalignment, XmALIGNMENT_CENTER )
        MTWS_SET_ARG( XmNalignmentVertical, XmALIGNMENT_MIDDLE )
    MTWS_END_WIDGET

    MTWS_START_WIDGET ( Label, WIG_PARALLEL_PLMN )
#ifdef ATOMBUILD
        MTWS_SET_ARG( XmNx, 0 )
        MTWS_SET_ARG( XmNy, 20 )
        MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH )
        MTWS_SET_ARG( XmNheight, 20 )
#else
        MTWS_SET_ARG( XmNx, 0 )
		MTWS_SET_ARG( XmNy, MUI_APP_LINE_HEIGHT )
        MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH )
        MTWS_SET_ARG( XmNheight,MUI_APP_LINE_HEIGHT )
#endif
        MTWS_SET_ARG( XmNmarginWidth, 0 )
        MTWS_SET_ARG( XmNmarginHeight, 0 )
        MTWS_SET_ARG( XmNrecomputeSize, True )
        MTWS_SET_ARG( XmNalignment, XmALIGNMENT_CENTER )
        MTWS_SET_ARG( XmNalignmentVertical, XmALIGNMENT_MIDDLE )
    MTWS_END_WIDGET

    MTWS_START_WIDGET( PushButton, WIG_SAT_MSG )
        MTWS_SET_ARG( XmNx, SAT_PANE_BEGIN_X )
        MTWS_SET_ARG( XmNy, SAT_PANE_BEGIN_Y )
        MTWS_SET_ARG( XmNwidth, SAT_PANE_WIDTH )
        MTWS_SET_ARG( XmNheight, SAT_PANE_HEIGHT )
        MTWS_SET_ARG( XmNhighlightColor, 0xf000 )
        MTWS_SET_ARG( XmNshadowThickness, 0 )
        MTWS_SET_ARG( XmNrecomputeSize, False )
        MTWS_SET_ARG( XmNalignment, XmALIGNMENT_CENTER )
        MTWS_SET_ARG( XmNalignmentVertical, XmALIGNMENT_MIDDLE )
        MTWS_SET_ARG( XmNwordWrap, True )
        MTWS_ADD_BACK( XmNdisarmCallback, mtws_NULL )
    MTWS_END_WIDGET

    /* This widget is for selecting rectangle of SI Pane*/
    MTWS_START_WIDGET( PushButton, WIG_SI_MSG_BG )
#ifdef ATOMBUILD
    MTWS_SET_ARG( XmNx, 0 )
    MTWS_SET_ARG( XmNy, 42-3 )
    MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH )
    MTWS_SET_ARG( XmNheight, 24+6 )
#else
    MTWS_SET_ARG( XmNx, 0 )
    MTWS_SET_ARG( XmNy, MUI_APP_LINE_HEIGHT * 3 - 3 )
    MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH )
    MTWS_SET_ARG( XmNheight, MUI_APP_LINE_HEIGHT + 6 )
#endif
    MTWS_SET_ARG( XmNhighlightColor, 0xf000 )
    MTWS_SET_ARG( XmNshadowThickness, 0 )
    MTWS_SET_ARG( XmNrecomputeSize, False )
    MTWS_SET_ARG( XmNbackground, 0xFC20 )
    MTWS_ADD_BACK( XmNdisarmCallback, mtws_NULL )
    MTWS_END_WIDGET

    MTWS_START_WIDGET( PushButton, WIG_SI_MSG )
#ifdef ATOMBUILD
    MTWS_SET_ARG( XmNx, 3 )
    MTWS_SET_ARG( XmNy, 42 )
    MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH - 6 )
    MTWS_SET_ARG( XmNheight, 20 )
#else
    MTWS_SET_ARG( XmNx, 3 )
    MTWS_SET_ARG( XmNy, MUI_APP_LINE_HEIGHT * 3 )
    MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH - 6 )
    MTWS_SET_ARG( XmNheight, MUI_APP_LINE_HEIGHT )
#endif
    MTWS_SET_ARG( XmNhighlightColor, 0xf000 )
    MTWS_SET_ARG( XmNshadowThickness, 0 )
    MTWS_SET_ARG( XmNrecomputeSize, False )
    MTWS_SET_ARG( XmNwordWrap, FALSE)
    MTWS_SET_ARG( XmNdisplayType, XmDISPLAY_TYPE_NEWLINE_ON )
    MTWS_SET_ARG( XmNalignmentVertical, XmALIGNMENT_TOP ) 
    MTWS_SET_ARG( XmNalignment, XmALIGNMENT_CENTER )
    MTWS_SET_ARG( XmNlineSpace, 2)
    MTWS_ADD_BACK( XmNdisarmCallback, mtws_NULL )
    MTWS_END_WIDGET
    
    MTWS_START_WIDGET( Tree, WIG_TREE_SHORTCUT )
    MTWS_SET_ARG( XmNx, SHORTCUT_BEGIN_X )
    MTWS_SET_ARG( XmNy, SHORTCUT_BEGIN_Y )
    MTWS_SET_ARG( XmNwidth, SHORTCUT_WIDTH )
    MTWS_SET_ARG( XmNheight, SHORTCUT_HEIGHT) /* inlcuding the help line at the bottom*/
    MTWS_SET_ARG( XmNstyle, XmSTYLE_SELECTBOX )
    MTWS_SET_ARG( XmNtreeData, Tree_Empty_Data )
    MTWS_SET_ARG( XmNfontId, MUI_STANDARD_FONT )
    MTWS_SET_ARG( XmNnumColumns, 4 )
    MTWS_SET_ARG( XmNtransparent, True )
    MTWS_SET_ARG (XmNlistSpacing, 0)
    MTWS_SET_ARG( XmNtreeHighlightIcon,  IMG_IDL_DI_SELECT )
    MTWS_SET_ARG( XmNhelpForeground, 0xFCC0 )
    MTWS_END_WIDGET
    MTWS_START_WIDGET( BulletinBoard, WIG_CAL_BBOARD )
#ifdef ATOMBUILD
        MTWS_SET_ARG( XmNx,                 0 )
        MTWS_SET_ARG( XmNy,                 23) /* move it up for not enough room for calendar */
        MTWS_SET_ARG( XmNwidth,             MUI_APP_WIDTH )
        MTWS_SET_ARG( XmNheight,            CALENDAR_HEIGHT )
        MTWS_SET_ARG( XmNrecomputeSize,     False )
#else
        MTWS_SET_ARG( XmNx,                 0 )
        MTWS_SET_ARG( XmNy,                 MUI_APP_LINE_HEIGHT * 2) /* move it up for not enough room for calendar */
        MTWS_SET_ARG( XmNwidth,             MUI_APP_WIDTH )
        MTWS_SET_ARG( XmNheight,            CALENDAR_HEIGHT )
        MTWS_SET_ARG( XmNrecomputeSize,     False )
		MTWS_SET_ARG( XmNtransparent, TRUE )
#endif
        MTWS_START_WIDGET ( PushButton, WIG_CAL_CONTAINER )
            MTWS_SET_ARG( XmNx, 0 )
            MTWS_SET_ARG( XmNy, 0 )
            MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH )
            MTWS_SET_ARG( XmNheight, CALENDAR_HEIGHT )
            MTWS_SET_ARG( XmNshadowThickness, 0 )
            MTWS_SET_ARG( XmNhighlightColor, 0xf000 )
            MTWS_SET_ARG( XmNrecomputeSize, False )
            MTWS_SET_ARG( XmNmarginWidth, 0 )
            MTWS_SET_ARG( XmNmarginHeight, 0 )
            MTWS_SET_ARG( XmNtransparent, TRUE )
        MTWS_END_WIDGET

        MTWS_START_WIDGET( Label, WIG_CAL_HEADER )
        MTWS_SET_ARG( XmNx, CALENDAR_BORDER )
        MTWS_SET_ARG( XmNy, CALENDAR_BORDER + 3 )
        MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH-2*CALENDAR_BORDER)
        MTWS_SET_ARG( XmNheight, CALENDAR_HDR_HEIGHT-2*CALENDAR_BORDER )
        MTWS_SET_ARG( XmNalignment, XmALIGNMENT_CENTER )
        MTWS_SET_ARG( XmNalignmentVertical, XmALIGNMENT_MIDDLE )
        MTWS_SET_ARG( XmNforeground, 0x000f )
        MTWS_SET_ARG( XmNtransparent, TRUE )
        MTWS_END_WIDGET

        MTWS_START_WIDGET( Label, WIG_CAL_COL1 )
        MTWS_SET_ARG( XmNx, CALENDAR_COLUMN_START )  /* add 3 to avoid the overlap on the selecting rectangle */
        MTWS_SET_ARG( XmNy, CALENDAR_BORDER + CALENDAR_HDR_HEIGHT)
        MTWS_SET_ARG( XmNwidth, CALENDAR_COLUMN_WIDTH )
        MTWS_SET_ARG( XmNheight, CALENDAR_ROW_HEIGHT )
        MTWS_SET_ARG( XmNalignment, XmALIGNMENT_CENTER )
        MTWS_SET_ARG( XmNalignmentVertical, XmALIGNMENT_TOP )
        MTWS_SET_ARG( XmNtransparent, TRUE )
        MTWS_SET_ARG( XmNtextId, WORD_GEN_CMN_MONDAY_3CHR )
        MTWS_END_WIDGET
        
        MTWS_START_WIDGET( Label, WIG_CAL_COL2 )
        MTWS_SET_ARG( XmNx, CALENDAR_COLUMN_START + CALENDAR_COLUMN_WIDTH )
        MTWS_SET_ARG( XmNy, CALENDAR_BORDER + CALENDAR_HDR_HEIGHT )
        MTWS_SET_ARG( XmNwidth, CALENDAR_COLUMN_WIDTH )
        MTWS_SET_ARG( XmNheight, CALENDAR_ROW_HEIGHT )
        MTWS_SET_ARG( XmNalignment, XmALIGNMENT_CENTER )
        MTWS_SET_ARG( XmNalignmentVertical, XmALIGNMENT_TOP )
        MTWS_SET_ARG( XmNtransparent, TRUE )
        MTWS_SET_ARG( XmNtextId, WORD_GEN_CMN_TUESDAY_3CHR )
        MTWS_END_WIDGET
        
        MTWS_START_WIDGET( Label, WIG_CAL_COL3 )
        MTWS_SET_ARG( XmNx, CALENDAR_COLUMN_START + CALENDAR_COLUMN_WIDTH * 2 )
        MTWS_SET_ARG( XmNy, CALENDAR_BORDER + CALENDAR_HDR_HEIGHT )
        MTWS_SET_ARG( XmNwidth, CALENDAR_COLUMN_WIDTH )
        MTWS_SET_ARG( XmNheight, CALENDAR_ROW_HEIGHT )
        MTWS_SET_ARG( XmNalignment, XmALIGNMENT_CENTER )
        MTWS_SET_ARG( XmNalignmentVertical, XmALIGNMENT_TOP )
        MTWS_SET_ARG( XmNtransparent, TRUE )
        MTWS_SET_ARG( XmNtextId, WORD_GEN_CMN_WEDNESDAY_3CHR )
        MTWS_END_WIDGET
        
        MTWS_START_WIDGET( Label, WIG_CAL_COL4 )
        MTWS_SET_ARG( XmNx, CALENDAR_COLUMN_START + CALENDAR_COLUMN_WIDTH * 3 )
        MTWS_SET_ARG( XmNy, CALENDAR_BORDER + CALENDAR_HDR_HEIGHT )
        MTWS_SET_ARG( XmNwidth, CALENDAR_COLUMN_WIDTH )
        MTWS_SET_ARG( XmNheight, CALENDAR_ROW_HEIGHT )
        MTWS_SET_ARG( XmNalignment, XmALIGNMENT_CENTER )
        MTWS_SET_ARG( XmNalignmentVertical, XmALIGNMENT_TOP )
        MTWS_SET_ARG( XmNtransparent, TRUE )
        MTWS_SET_ARG( XmNtextId, WORD_GEN_CMN_THURSDAY_3CHR )
        MTWS_END_WIDGET
        
        MTWS_START_WIDGET( Label, WIG_CAL_COL5 )
        MTWS_SET_ARG( XmNx, CALENDAR_COLUMN_START + CALENDAR_COLUMN_WIDTH * 4 )
        MTWS_SET_ARG( XmNy, CALENDAR_BORDER + CALENDAR_HDR_HEIGHT )
        MTWS_SET_ARG( XmNwidth, CALENDAR_COLUMN_WIDTH )
        MTWS_SET_ARG( XmNheight, CALENDAR_ROW_HEIGHT )
        MTWS_SET_ARG( XmNalignment, XmALIGNMENT_CENTER )
        MTWS_SET_ARG( XmNalignmentVertical, XmALIGNMENT_TOP )
        MTWS_SET_ARG( XmNtransparent, TRUE )
        MTWS_SET_ARG( XmNtextId, WORD_GEN_CMN_FRIDAY_3CHR )
        MTWS_END_WIDGET
        
        MTWS_START_WIDGET( Label, WIG_CAL_COL6 )
        MTWS_SET_ARG( XmNx, CALENDAR_COLUMN_START + CALENDAR_COLUMN_WIDTH * 5 )
        MTWS_SET_ARG( XmNy, CALENDAR_BORDER + CALENDAR_HDR_HEIGHT )
        MTWS_SET_ARG( XmNwidth, CALENDAR_COLUMN_WIDTH )
        MTWS_SET_ARG( XmNheight, CALENDAR_ROW_HEIGHT )
        MTWS_SET_ARG( XmNalignment, XmALIGNMENT_CENTER )
        MTWS_SET_ARG( XmNalignmentVertical, XmALIGNMENT_TOP )
        MTWS_SET_ARG( XmNtransparent, TRUE )
        MTWS_SET_ARG( XmNtextId, WORD_GEN_CMN_SATURDAY_3CHR )
        MTWS_END_WIDGET
        
        MTWS_START_WIDGET( Label, WIG_CAL_COL7 )
        MTWS_SET_ARG( XmNx, CALENDAR_COLUMN_START + CALENDAR_COLUMN_WIDTH * 6 )
        MTWS_SET_ARG( XmNy, CALENDAR_BORDER + CALENDAR_HDR_HEIGHT )
        MTWS_SET_ARG( XmNwidth, CALENDAR_COLUMN_WIDTH )
        MTWS_SET_ARG( XmNheight, CALENDAR_ROW_HEIGHT )
        MTWS_SET_ARG( XmNalignment, XmALIGNMENT_CENTER )
        MTWS_SET_ARG( XmNalignmentVertical, XmALIGNMENT_TOP )
        MTWS_SET_ARG( XmNtransparent, TRUE )
        MTWS_SET_ARG( XmNtextId, WORD_GEN_CMN_SUNDAY_3CHR )
        MTWS_END_WIDGET

        MTWS_START_WIDGET (Separator, WIG_CAL_SPR)
        MTWS_SET_ARG( XmNx, 3*CALENDAR_BORDER )
        MTWS_SET_ARG( XmNy, 2*CALENDAR_BORDER + CALENDAR_HDR_HEIGHT+CALENDAR_ROW_HEIGHT )
        MTWS_SET_ARG( XmNwidth,  MUI_APP_WIDTH-6*CALENDAR_BORDER)
        MTWS_SET_ARG( XmNheight, CALENDAR_SPR_HEIGHT )
        MTWS_SET_ARG( XmNbackground, 0xa514) /* Gray*/
        MTWS_SET_ARG( XmNtransparent, TRUE )
        MTWS_END_WIDGET
    MTWS_END_WIDGET
        
        MTWS_START_WIDGET ( Label, WIG_TIME_DATE )
            MTWS_SET_ARG( XmNx, 50 )
            MTWS_SET_ARG( XmNy, MUI_APP_BASE_HEIGHT-19 )
            MTWS_SET_ARG( XmNwidth, 76 )
            MTWS_SET_ARG( XmNheight,MUI_APP_LINE_HEIGHT )
            MTWS_SET_ARG( XmNmarginWidth, 0 )
            MTWS_SET_ARG( XmNmarginHeight, 0 )
            MTWS_SET_ARG( XmNwordWrap, True )
            MTWS_SET_ARG( XmNrecomputeSize, True )
            MTWS_SET_ARG( XmNalignment, XmALIGNMENT_CENTER )
            MTWS_SET_ARG( XmNalignmentVertical, XmALIGNMENT_MIDDLE )
            MTWS_SET_ARG( XmNtransparent, True )
			MTWS_SET_ARG( XmNforeground, 0xFC20)
        MTWS_END_WIDGET

        MTWS_START_WIDGET ( Label, WIG_BLT_IND )
            MTWS_SET_ARG( XmNx, 129 )
            MTWS_SET_ARG( XmNy, MUI_APP_BASE_HEIGHT-19 )
            MTWS_SET_ARG( XmNwidth, 20 )
            MTWS_SET_ARG( XmNheight,18 )
            MTWS_SET_ARG( XmNwordWrap, True )
            MTWS_SET_ARG( XmNrecomputeSize, True )
            MTWS_SET_ARG( XmNmarginWidth, 0 )
            MTWS_SET_ARG( XmNmarginHeight, 0 )
            MTWS_SET_ARG( XmNimageId, IMG_IDL_BLT)
            MTWS_SET_ARG( XmNtransparent, True )
        MTWS_END_WIDGET

        MTWS_START_WIDGET ( Label, WIG_MFN_IND )
            MTWS_SET_ARG( XmNx, 4 )
            MTWS_SET_ARG( XmNy, MUI_APP_BASE_HEIGHT-19 )
            MTWS_SET_ARG( XmNwidth, 20 )
            MTWS_SET_ARG( XmNheight,18 )
            MTWS_SET_ARG( XmNwordWrap, True )
            MTWS_SET_ARG( XmNmarginWidth, 0 )
            MTWS_SET_ARG( XmNmarginHeight, 0 )
            MTWS_SET_ARG( XmNrecomputeSize, True )
            MTWS_SET_ARG( XmNtransparent, True )
        MTWS_END_WIDGET

        MTWS_START_WIDGET ( Label, WIG_CFD_IND )
            MTWS_SET_ARG( XmNx, 27 )
            MTWS_SET_ARG( XmNy, MUI_APP_BASE_HEIGHT-19 )
            MTWS_SET_ARG( XmNwidth, 18 )
            MTWS_SET_ARG( XmNheight,18 )
            MTWS_SET_ARG( XmNwordWrap, True )
            MTWS_SET_ARG( XmNmarginWidth, 0 )
            MTWS_SET_ARG( XmNmarginHeight, 0 )
            MTWS_SET_ARG( XmNrecomputeSize, True )
            MTWS_SET_ARG( XmNtransparent, True )
        MTWS_END_WIDGET
        MTWS_START_WIDGET ( Label, WIG_KPL_IND )
            MTWS_SET_ARG( XmNx, 152 )
            MTWS_SET_ARG( XmNy, MUI_APP_BASE_HEIGHT-19 )
            MTWS_SET_ARG( XmNwidth, 20 )
            MTWS_SET_ARG( XmNheight,18 )
            MTWS_SET_ARG( XmNwordWrap, True )
            MTWS_SET_ARG( XmNmarginWidth, 0 )
            MTWS_SET_ARG( XmNmarginHeight, 0 )
            MTWS_SET_ARG( XmNrecomputeSize, True )
            MTWS_SET_ARG( XmNtransparent, True )
         MTWS_END_WIDGET

    MTWS_START_WIDGET( Label, WIG_SI_CAL_HELPLINE)
        MTWS_SET_ARG( XmNx, SHORTCUT_BEGIN_X+9 )
        MTWS_SET_ARG( XmNy, MUI_APP_BASE_HEIGHT - 20)
        MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH )
        MTWS_SET_ARG( XmNheight, 20) /*  the help line for calendar/SI*/
        MTWS_SET_ARG( XmNalignment, XmALIGNMENT_BEGINNING)
	MTWS_SET_ARG( XmNalignmentVertical, XmALIGNMENT_MIDDLE )
        MTWS_SET_ARG( XmNfontId, MUI_REDUCED_FONT )
        MTWS_SET_ARG( XmNrecomputeSize, FALSE )
        MTWS_SET_ARG( XmNtransparent, TRUE )
	MTWS_SET_ARG( XmNforeground, 0xFC20)
        MTWS_SET_ARG( XmNmarginWidth, 0 )
        MTWS_SET_ARG( XmNmarginHeight, 0 )
    MTWS_END_WIDGET
    
    /* Adjust receive volume */
    MTWS_START_WIDGET ( BulletinBoard, WIG_SET_VOLUME_BOARD )
        MTWS_SET_ARG( XmNx, 0 )
        MTWS_SET_ARG( XmNy, 20 )
        MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH )
        MTWS_SET_ARG( XmNheight, 120 )
        MTWS_SET_ARG( XmNrecomputeSize, FALSE )

	    MTWS_START_WIDGET ( BulletinBoard, WIG_SET_VOLUME_IMG )
	        MTWS_SET_ARG( XmNx, 37 )
	        MTWS_SET_ARG( XmNy, 0 )
	        MTWS_SET_ARG( XmNwidth, 102 ) 
	        MTWS_SET_ARG( XmNheight, 74 )
	        MTWS_SET_ARG( XmNrecomputeSize, FALSE  )
	
			MTWS_START_WIDGET( Label, WIG_VOLUME_ICON )
	            MTWS_SET_ARG( XmNx,                 30 )
	            MTWS_SET_ARG( XmNy,                 5 )
	            MTWS_SET_ARG( XmNwidth,             62 )
	            MTWS_SET_ARG( XmNheight,            60 )
	            MTWS_SET_ARG( XmNmarginWidth,       0 )
	            MTWS_SET_ARG( XmNmarginHeight,      0 )
	            MTWS_SET_ARG( XmNtransparent,       True )
	            MTWS_SET_ARG( XmNrecomputeSize,     False )
	        MTWS_END_WIDGET
			MTWS_START_WIDGET( Label, WIG_VOLUME_SLIDE )
	            MTWS_SET_ARG( XmNx,                 8 )
	            MTWS_SET_ARG( XmNwidth,             14 )
	            MTWS_SET_ARG( XmNheight,            8 )
	            MTWS_SET_ARG( XmNmarginWidth,       0 )
	            MTWS_SET_ARG( XmNmarginHeight,      0 )
	            MTWS_SET_ARG( XmNtransparent,       True )
	            MTWS_SET_ARG( XmNrecomputeSize,     False )
	            MTWS_SET_ARG( XmNimageId, IMG_CMN_SLIDER3)
	        MTWS_END_WIDGET
	    MTWS_END_WIDGET

		MTWS_START_WIDGET ( Label, WIG_ADJUST_VOLUME )
	        MTWS_SET_ARG( XmNx, 0 )
	        MTWS_SET_ARG( XmNy, 80 )
	        MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH ) 
	        MTWS_SET_ARG( XmNheight, 20 )
	        MTWS_SET_ARG( XmNrecomputeSize, FALSE  )
	        MTWS_SET_ARG( XmNalignment, XmALIGNMENT_CENTER )
	        MTWS_SET_ARG( XmNtextId, WORD_LBL_CMN_ADJVOL_MSG)
		MTWS_END_WIDGET
		MTWS_START_WIDGET ( Label, WIG_CURRENT_VOLUME_LEVEL )
	        MTWS_SET_ARG( XmNx, 0 )
	        MTWS_SET_ARG( XmNy, 100 )
	        MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH ) 
	        MTWS_SET_ARG( XmNheight, 20 )
	        MTWS_SET_ARG( XmNrecomputeSize, FALSE )
	        MTWS_SET_ARG( XmNalignment, XmALIGNMENT_CENTER )
		MTWS_END_WIDGET
    MTWS_END_WIDGET

#ifdef CSW_SUPPORTKEYLOCK
		MTWS_START_WIDGET ( Label, WIG_KEY_LOCK_STATUS )
	        MTWS_SET_ARG( XmNx, 0 )
	        MTWS_SET_ARG( XmNy, MUI_APP_BASE_HEIGHT - 54 )
	        MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH ) 
	        MTWS_SET_ARG( XmNheight, 54 )
            MTWS_SET_ARG( XmNmarginWidth, 0 )
            MTWS_SET_ARG( XmNmarginHeight, 0 )
		MTWS_END_WIDGET
#endif

#ifdef ATOMBUILD    /* Cosmobic Dana Liu COS_ATOM_0037 */
    MTWS_END_WIDGET
#else   /* Cosmobic Dana Liu COS_ATOM_0037 */
#endif  /* Cosmobic Dana Liu COS_ATOM_0037 */

MTWS_END_DIALOG

LST_START_DESC( Tree_Empty_Data )

	LST_ADD_LEVEL_CALLBACK( mtws_Shortcut_TopLevelCallback, 0 )
 
    LST_ADD_ITEM            ( ' ', TXT_BLANK, IMG_BLANK )
    LST_ADD_COMMENT         ( <Please add a comment> )
    LST_ADD_CALLBACK        ( mtws_Shortcut_ItemCallback, 0 )
    LST_ADD_STYLE           ( NODE_STYLE )
LST_END_DESC

MTWS_START_DIALOG ( DLG_IDLE_MENU )

	MTWS_DLG_POP_UP( )

    MTWS_DLG_EVENT( 0, XtTEKey, XK_KEY_OPTION, mtws_CancelKey )
    
    MTWS_START_WIDGET ( Tree, WIG_LIST )
        MTWS_SET_ARG( XmNx, 0 )
        MTWS_SET_ARG( XmNy, 0 )
        MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH )
        MTWS_SET_ARG( XmNheight, MUI_APP_HEIGHT )
        MTWS_SET_ARG( XmNforeground, 0x0000 )
        MTWS_SET_ARG( XmNbackground, 0xce79 )
        MTWS_SET_ARG( XmNlistScrollPolicy,   XmSCROLL_ROTATE)
        MTWS_SET_ARG( XmNstyle,   XmSTYLE_SELECTBOX)
        MTWS_SET_ARG( XmNlistPageScroll,   XmPAGE_SCROLL_LRONLY)
        MTWS_SET_ARG( XmNtreeData,   idle_menu)
        MTWS_ADD_BACK( XmNtreeCancel,   mtws_CancelKey)
    MTWS_END_WIDGET

MTWS_END_DIALOG


LST_START_DESC          ( idle_menu )

    LST_ADD_HEADER_TEXT     ( TXT_IDLE_OPTIONS )
    LST_ADD_HEADER_ICON( IMG_CMN_OPT_1 )
	LST_ADD_HEADER_IMAGE   ( IMG_CMN_LBL_2 )

	LST_ADD_ITEM    ( '1', TXT_UC_PHONE_MODE, IMG_BLANK )
    LST_ADD_COMMENT ( <Please add a comment> )
    LST_ADD_CALLBACK( mtws_NULL, 0 )
    LST_ADD_STYLE   ( NODE_STYLE )
	LST_START_NODES
		LST_ADD_HEADER_TEXT     ( WORD_TTL_SET_PH_MD )
	    LST_ADD_ITEM            ( '1', TXT_MFN_NORMAL_MODE, IMG_BLANK )
	    LST_ADD_COMMENT         ( <Please add a comment> )
	    LST_ADD_CALLBACK        ( mtws_ChangeMode, ELIB_SS_PHONEMODE_NORMAL )
	    LST_ADD_STYLE           ( NODE_STYLE )
	
	    LST_ADD_ITEM            ( '2', TXT_MFN_MEETING_MODE, IMG_BLANK )
	    LST_ADD_COMMENT         ( <Please add a comment> )
	    LST_ADD_CALLBACK        ( mtws_ChangeMode, ELIB_SS_PHONEMODE_MEETING )
	    LST_ADD_STYLE           ( NODE_STYLE )
	
	    LST_ADD_ITEM            ( '3', TXT_MFN_POCKET_MODE, IMG_BLANK )
	    LST_ADD_COMMENT         ( <Please add a comment> )
	    LST_ADD_CALLBACK        ( mtws_ChangeMode, ELIB_SS_PHONEMODE_POCKET )
	    LST_ADD_STYLE           ( NODE_STYLE )
	
	    LST_ADD_ITEM            ( '4', TXT_MFN_CAR_MODE, IMG_BLANK )
	    LST_ADD_COMMENT         ( <Please add a comment> )
	    LST_ADD_CALLBACK        ( mtws_ChangeMode, ELIB_SS_PHONEMODE_CAR )
	    LST_ADD_STYLE           ( NODE_STYLE )
	LST_END_NODES
	
	LST_ADD_ITEM    ( '2', TXT_IDLE_TRE_QUICK_MENU, IMG_BLANK )
    LST_ADD_COMMENT ( <Please add a comment> )
    LST_ADD_CALLBACK( mtws_MyMenu, 0 )
    LST_ADD_STYLE   ( NODE_STYLE )

    LST_ADD_ITEM            ( '3', TXT_IDLE_OPT_SCREENTYPE, IMG_BLANK )
    LST_ADD_COMMENT         ( <Please add a comment> )
    LST_ADD_CALLBACK        ( mtws_NULL, 0 )
    LST_ADD_STYLE           ( NODE_STYLE )
    LST_START_NODES
        LST_ADD_HEADER_TEXT     ( TXT_IDLE_OPT_SCREENTYPE )
        LST_ADD_ITEM            ( '1', TXT_IDLE_SCREENTYPE_NORMAL, IMG_BLANK )
        LST_ADD_COMMENT         ( <Please add a comment> )
        LST_ADD_CALLBACK        ( mtws_ScreenTypeMenu, 0 )
        LST_ADD_STYLE           ( NODE_STYLE )

        LST_ADD_ITEM            ( '2', TXT_IDLE_SCREENTYPE_CALENDAR, IMG_BLANK )
        LST_ADD_COMMENT         ( <Please add a comment> )
        LST_ADD_CALLBACK        ( mtws_ScreenTypeMenu, 1 )
        LST_ADD_STYLE           ( NODE_STYLE )
    LST_END_NODES

    LST_ADD_ITEM    ( '4', TXT_SVC_PASTE, IMG_BLANK )
    LST_ADD_COMMENT         ( <Please add a comment> )
    LST_ADD_CALLBACK        ( mtws_PasteNumber, 0 )
    LST_ADD_STYLE           ( NODE_STYLE )

    LST_ADD_ITEM    ( '5', TXT_SVC_LOGS, IMG_BLANK )
    LST_ADD_COMMENT         ( <Please add a comment> )
    LST_ADD_CALLBACK        ( mtws_AddEvent, e_CallLogsMenu )
    LST_ADD_STYLE           ( NODE_STYLE )

#ifdef CHW_SIDEKEY
    LST_ADD_ITEM    ( '6', TXT_IDLE_TRE_PHONE_LOCKS, IMG_BLANK )
    LST_ADD_COMMENT         ( <Please add a comment> )
    LST_ADD_CALLBACK        ( mtws_NULL, 0 )
    LST_ADD_STYLE           ( NODE_STYLE )
    LST_START_NODES
		LST_ADD_HEADER_TEXT     ( TXT_IDLE_TRE_PHONE_LOCKS )
	    LST_ADD_HEADER_ICON( IMG_CMN_OPT_1 )
		LST_ADD_HEADER_IMAGE   ( IMG_CMN_LBL_2 )
        LST_ADD_ITEM            ( '1', WORD_TRE_SET_SEC_LOCK_SIDE, IMG_BLANK )
        LST_ADD_COMMENT         ( <Please add a comment> )
        LST_ADD_CALLBACK        ( mtws_NULL, 0 )
        LST_ADD_STYLE           ( NODE_STYLE )
        
	        LST_START_NODES
		        LST_ADD_HEADER_TEXT     ( WORD_TRE_SET_SEC_LOCK_SIDE )
	            LST_ADD_ITEM    ( '1', TXT_SC_ON, IMG_BLANK )
	            LST_ADD_COMMENT ( Enable Side key lock )
	            LST_ADD_CALLBACK( mtws_SideKeyLockReq, ELIB_KEY_SIDEKEYCLOSE_OFF )
	            LST_ADD_STYLE   ( NODE_STYLE )
	
	            LST_ADD_ITEM    ( '2', TXT_SC_OFF, IMG_BLANK )
	            LST_ADD_COMMENT ( Disable Side key lock )
	            LST_ADD_CALLBACK( mtws_SideKeyLockReq, ELIB_KEY_SIDEKEYCLOSE_ON )
	            LST_ADD_STYLE   ( NODE_STYLE )
	        LST_END_NODES
	        
        LST_ADD_ITEM            ( '2', TXT_SVC_DIAL_LOCK, IMG_BLANK )
        LST_ADD_COMMENT         ( <Please add a comment> )
        LST_ADD_CALLBACK        ( mtws_AddEvent, e_EnableDialLock )
        LST_ADD_STYLE           ( NODE_STYLE )
    LST_END_NODES
#else
    LST_ADD_ITEM    ( '6', TXT_SVC_DIAL_LOCK, IMG_BLANK )
    LST_ADD_COMMENT         ( <Please add a comment> )
    LST_ADD_CALLBACK        ( mtws_AddEvent, e_EnableDialLock )
    LST_ADD_STYLE           ( NODE_STYLE )
#endif

LST_END_DESC

MTWS_START_DIALOG( DLG_DIAL_MENU )

    MTWS_DLG_POP_UP( )

	MTWS_DLG_EVENT( 0, XtTEKey, XK_KEY_OPTION, mtws_Cancel )

    MTWS_START_WIDGET( Tree, WIG_OPTIONS_LIST )
        MTWS_SET_ARG( XmNx, 0 )
        MTWS_SET_ARG( XmNy, 0 )
        MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH )
        MTWS_SET_ARG( XmNheight, MUI_APP_HEIGHT )
        MTWS_SET_ARG( XmNforeground, 0x0000 )
        MTWS_SET_ARG( XmNbackground, 0xce79 )
        MTWS_SET_ARG( XmNlistScrollPolicy,   XmSCROLL_ROTATE)
        MTWS_SET_ARG( XmNstyle,   XmSTYLE_SELECTBOX)
        MTWS_SET_ARG( XmNlistPageScroll,   XmPAGE_SCROLL_LRONLY)
        MTWS_SET_ARG( XmNtreeData,   dial_menu)
        MTWS_ADD_BACK( XmNtreeCancel,   mtws_Cancel)
	MTWS_END_WIDGET
MTWS_END_DIALOG

LST_START_DESC( dial_menu )
	LST_ADD_HEADER_TEXT     ( TXT_IDLE_OPTIONS )
    LST_ADD_HEADER_ICON( IMG_CMN_OPT_1 )
    LST_ADD_HEADER_IMAGE   ( IMG_CMN_LBL_2 )

    LST_ADD_ITEM    ( '1', TXT_IDLE_OPT_SENDMSG, IMG_BLANK )
    LST_ADD_COMMENT ( <Please add a comment> )
    LST_ADD_CALLBACK( mtws_DialMenu, 0)
    LST_ADD_STYLE   ( NODE_STYLE )

    LST_ADD_ITEM    ( '2', TXT_ED_MNU_COPY , IMG_BLANK )
    LST_ADD_COMMENT ( <Please add a comment> )
    LST_ADD_CALLBACK( mtws_DialMenu, 1)
    LST_ADD_STYLE   ( NODE_STYLE )

    LST_ADD_ITEM    ( '3', WORD_TRE_CMN_PASTE, IMG_BLANK )
    LST_ADD_COMMENT ( <Please add a comment> )
    LST_ADD_CALLBACK( mtws_DialMenu, 2)
    LST_ADD_STYLE   ( NODE_STYLE )


LST_END_DESC
#define GEN_UNDEFINE_MACROS
#include "MuiApplicationDlg.m"

/*$End$*/

/* *************************************************************************** */
/* ***************************** UNDEFINE MACROS ***************************** */
/* *************************************************************************** */
#define GEN_UNDEFINE_MACROS
#include "TiGenericInt.m"

/* *************************************************************************** */
/* *********************************** END *********************************** */
/* *************************************************************************** */

