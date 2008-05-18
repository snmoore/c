/* *************************************************************************** */
/* ****************************** DEFINE MACROS ****************************** */
/* *************************************************************************** */
#define GEN_DEFINE_MACROS
#include "TiGenericInt.m"

/* *************************************************************************** */
/* ******************************** CLASS NAME ******************************* */
/* *************************************************************************** */
GEN_DECLARE_CLASS( C_MUI_EMERGENCY_CALL )

/* *************************************************************************** */
/* ********************************** STATES ********************************* */
/* *************************************************************************** */
GEN_STA_START              ( Initial, s_ROOT, Start, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_TRA        ( NoSimPresent, e_Start, g_WithNoSimScreen, TRUE, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( WaitInputNnumber, e_Start, g_WithNoSimScreen, FALSE, A_NULL, 0 )
GEN_STA_END


GEN_STA_START              ( Final, s_ROOT, Exit, s_NULL )
    GEN_STA_ADD_ENTRY      ( a_Entry, UNLOAD )
    GEN_STA_COMMENT        ((<please add description here >))
GEN_STA_END

GEN_STA_START              ( Normal, s_ROOT, NoSimPresent, s_NULL )
    GEN_STA_ADD_ENTRY      ( a_LoadNoSimPresentScreen, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadNoSimPresentScreen, UNLOAD )
    GEN_STA_ADD_TRA        ( WaitInputNnumber, e_GotoSos, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( Exit, e_End, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, s_ROOT, EmergencyCallStatus, s_NULL )
    GEN_STA_ADD_ENTRY      ( a_SetEmergencyNumber, LOAD )
    GEN_STA_ADD_EXIT       ( a_SetEmergencyNumber, UNLOAD )
    GEN_STA_ADD_TRA        ( NoSimPresent, E_DONE, g_WithNoSimScreen, TRUE, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( Exit, E_DONE, g_WithNoSimScreen, FALSE, A_NULL, 0 )
GEN_STA_END

GEN_STA_START              ( Normal, EmergencyCallStatus, WaitInputNnumber, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_StartEmergencyTimer, LOAD )
    GEN_STA_ADD_EXIT       ( a_StartEmergencyTimer, UNLOAD )
    GEN_STA_ADD_TRA        ( ConfirmDefaultEmergencyCall, e_StartDefaultEmergency, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END


GEN_STA_START              ( Normal, EmergencyCallStatus, ConfirmDefaultEmergencyCall, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_DialLockEmergencyCnfDlg, LOAD )
    GEN_STA_ADD_EXIT       ( a_DialLockEmergencyCnfDlg, UNLOAD )
    GEN_STA_ADD_ENTRY      ( a_StartEmergencyTimer, LOAD )
    GEN_STA_ADD_EXIT       ( a_StartEmergencyTimer, UNLOAD )
    GEN_STA_ADD_INT        ( e_StartDefaultEmergency, G_TRUE, 0, a_StartDefaultEmergency, 0)
    GEN_STA_ADD_TRA        ( WaitInputNnumber, E_CANCEL, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END


/* *************************************************************************** */
/* ***************************** INTERNAL EVENTS ***************************** */
/* *************************************************************************** */
GEN_DECLARE_EVENT ( e_Start )
GEN_DECLARE_EVENT ( e_End )
GEN_DECLARE_EVENT ( e_StartDefaultEmergency )
GEN_DECLARE_EVENT ( e_GotoSos )
/* *************************************************************************** */
/* ****************************** USER DEFINED ******************************* */
/* *************************************************************************** */
/*$User$*/

#define GEN_DEFINE_MACROS
#include "MuiApplicationDlg.m"

MTWS_START_DIALOG ( DLG_EMERGENCY_CALL )

    MTWS_DLG_TEXT( RIGHT, TXT_IDLE_KEY_CANCEL )
	MTWS_DLG_POP_UP( )

	MTWS_DLG_EVENT( XtTMAny, XtTEKey, 0, mtws_EmergencyCall )
    
    MTWS_START_WIDGET( TextEdit, WIG_EMERGENCY_NUMBER )
#ifdef ATOMBUILD
        MTWS_SET_ARG( XmNx, 68 )
        MTWS_SET_ARG( XmNy, 130 )
#else
        MTWS_SET_ARG( XmNx, 68 )
        MTWS_SET_ARG( XmNy, 150 )
#endif
        MTWS_SET_ARG( XmNwidth, 40 )
        MTWS_SET_ARG( XmNheight, 20 )
        MTWS_SET_ARG( XmNshadowThickness, 0 )
        MTWS_SET_ARG( XmNmarginWidth, 4 )
        MTWS_SET_ARG( XmNmarginHeight, 1 )
        MTWS_SET_ARG( XmNruledLine, False )
        MTWS_SET_ARG( XmNforeground, 0x0000 )
        MTWS_SET_ARG( XmNhighlightColor, MUI_HIGHLIGHTCOLOR )
        MTWS_SET_ARG( XmNtopShadowColor, MUI_TOPSHADOWCOLOR )
        MTWS_SET_ARG( XmNbottomShadowColor, MUI_BOTTOMSHADOWCOLOR )
        MTWS_SET_ARG( XmNhighlightStyle, MUI_HIGHLIGHTSTYLE )
        MTWS_SET_ARG( XmNeditMode, XmSINGLE_LINE_EDIT )
        MTWS_SET_ARG( XmNmaxLength, 3 )
        MTWS_SET_ARG( XmNcharMode, XmCHAR_DIGITONLY )
		MTWS_ADD_BACK(XmNvalueChangedCallback, mtws_EmergencyStringChange )
    MTWS_END_WIDGET
    
    MTWS_START_WIDGET( BulletinBoard, WIG_EMERGENCY_HEADER )
        
        MTWS_SET_ARG( XmNx, 0 )
        MTWS_SET_ARG( XmNy, 0 )
        MTWS_SET_ARG( XmNwidth, 176 )
        MTWS_SET_ARG( XmNheight, MUI_APP_LINE_HEIGHT*2 )
        MTWS_SET_ARG( XmNrecomputeSize, False )

        MTWS_START_WIDGET( Label, WIG_EMERGENCY_ICON )
            
            MTWS_SET_ARG( XmNx, 15 )
            MTWS_SET_ARG( XmNy, 10 )
            MTWS_SET_ARG( XmNwidth, 20 )
            MTWS_SET_ARG( XmNheight, 20 )
            MTWS_SET_ARG( XmNmarginWidth, 0 )
            MTWS_SET_ARG( XmNmarginHeight, 0 )
            MTWS_SET_ARG( XmNtransparent, True )
            MTWS_SET_ARG( XmNrecomputeSize, False )
            MTWS_SET_ARG( XmNimageId, IMG_CMN_DLG_Q_3 )
        MTWS_END_WIDGET

        MTWS_START_WIDGET( Label, WIG_EMERGENCY_TEXT )
            
            MTWS_SET_ARG( XmNx, 50 )
            MTWS_SET_ARG( XmNy, 12 )
            MTWS_SET_ARG( XmNwidth, 122 )
            MTWS_SET_ARG( XmNheight, 16 )
            MTWS_SET_ARG( XmNalignment, XmALIGNMENT_BEGINNING )
            MTWS_SET_ARG( XmNforeground, 0xffff )
            MTWS_SET_ARG( XmNmarginWidth, 0 )
            MTWS_SET_ARG( XmNmarginHeight, 0 )
            MTWS_SET_ARG( XmNtransparent, True )
            MTWS_SET_ARG( XmNrecomputeSize, False )
	        MTWS_SET_ARG( XmNtextId, TXT_CSV_EMERGENCY )
        MTWS_END_WIDGET
    MTWS_END_WIDGET

    MTWS_START_WIDGET( Label, WIG_MAIN_EMERGENCY_TEXT )
#ifdef ATOMBUILD
        MTWS_SET_ARG( XmNx, 2 )
        MTWS_SET_ARG( XmNy, 45 )
#else
        MTWS_SET_ARG( XmNx, 2 )
        MTWS_SET_ARG( XmNy, 60 )
#endif
        MTWS_SET_ARG( XmNwidth, 172 )
        MTWS_SET_ARG( XmNheight, 80 )
		MTWS_SET_ARG( XmNlineSpace, 4 )
		MTWS_SET_ARG( XmNtransparent, TRUE )
        MTWS_SET_ARG( XmNtextId, TXT_IDLE_DLG_EMG )
    MTWS_END_WIDGET

MTWS_END_DIALOG


MTWS_START_DIALOG( DLG_SIM_MALFUNCTION )

    MTWS_DLG_TEXT( RIGHT, TXT_WUP_SOS )

    MTWS_DLG_EVENT( XtTMAny, XtTEKey, 0, mtws_StartEmergencyCall )

    MTWS_START_WIDGET( Label, WIG_TEXT )
        MTWS_SET_ARG( XmNx, 0 )
        MTWS_SET_ARG( XmNy, 2 )
        MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH )
        MTWS_SET_ARG( XmNheight, 110 )
        MTWS_SET_ARG( XmNrecomputeSize, False )
        MTWS_SET_ARG( XmNwordWrap, True )
    MTWS_END_WIDGET
MTWS_END_DIALOG

#define GEN_UNDEFINE_MACROS
#include "MuiApplicationDlg.m"

/*$end$*/

/* *************************************************************************** */
/* ***************************** UNDEFINE MACROS ***************************** */
/* *************************************************************************** */
#define GEN_UNDEFINE_MACROS
#include "TiGenericInt.m"

/* *************************************************************************** */
/* *********************************** END *********************************** */
/* *************************************************************************** */

