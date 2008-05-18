/* *************************************************************************** */
/* ****************************** DEFINE MACROS ****************************** */
/* *************************************************************************** */
#define GEN_DEFINE_MACROS
#include "TiGenericInt.m"

/* *************************************************************************** */
/* ******************************** CLASS NAME ******************************* */
/* *************************************************************************** */
GEN_DECLARE_CLASS( C_MUI_MODE )

/* *************************************************************************** */
/* ********************************** STATES ********************************* */
/* *************************************************************************** */
GEN_STA_START              ( Initial, s_ROOT, Start, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_Entry, TRUE )
    GEN_STA_ADD_TRA        ( ModeMenu, e_Start, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END


GEN_STA_START              ( Final, s_ROOT, Exit, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
GEN_STA_END


GEN_STA_START              ( Normal, s_ROOT, ModeMenu, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadModeMenu, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadModeMenu, UNLOAD )
    GEN_STA_ADD_TRA        ( Exit, e_End, G_TRUE, 0, A_NULL, 0 )
    GEN_STA_ADD_TRA        ( Confimation, e_Confirm, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END


GEN_STA_START              ( Normal, s_ROOT, Confimation, s_NULL )
    GEN_STA_COMMENT        ((<please add description here >))
    GEN_STA_ADD_ENTRY      ( a_LoadConfirm, LOAD )
    GEN_STA_ADD_EXIT       ( a_LoadConfirm, UNLOAD )
    GEN_STA_ADD_TRA        ( Exit, E_DONE, G_TRUE, 0, A_NULL, 0 )
GEN_STA_END


/* *************************************************************************** */
/* ***************************** INTERNAL EVENTS ***************************** */
/* *************************************************************************** */
GEN_DECLARE_EVENT ( e_Start )
GEN_DECLARE_EVENT ( e_End )
GEN_DECLARE_EVENT ( e_Confirm )

/* *************************************************************************** */
/* ****************************** USER DEFINED ******************************* */
/* *************************************************************************** */
/*$User$*/

#define GEN_DEFINE_MACROS
#include "MuiApplicationDlg.m"

MTWS_START_DIALOG ( DLG_MODE_MENU )

	MTWS_DLG_EVENT( XtTMAny,  XtTEKey,   XK_KEY_ON_HOOK, mtws_EndKey )
    
    MTWS_START_WIDGET ( Tree, WIG_LIST )
        MTWS_SET_ARG( XmNx, 0 )
        MTWS_SET_ARG( XmNy, MUI_APP_LINE_HEIGHT )
		MTWS_SET_ARG( XmNwidth, MUI_APP_WIDTH )
        MTWS_SET_ARG( XmNheight, MUI_APP_HEIGHT )
        MTWS_SET_ARG( XmNforeground, 0x0000 )
        MTWS_SET_ARG( XmNbackground, 0xce79 )
		MTWS_SET_ARG( XmNlistScrollPolicy,   XmSCROLL_ROTATE)
		MTWS_SET_ARG( XmNstyle,   XmSTYLE_SELECTBOX)
		MTWS_SET_ARG( XmNlistPageScroll,   XmPAGE_SCROLL_LRONLY)
		MTWS_SET_ARG( XmNtreeData,   mode_menu)
		MTWS_ADD_BACK( XmNtreeCancel,   mtws_CancelKey)
    MTWS_END_WIDGET

MTWS_END_DIALOG

LST_START_DESC          ( mode_menu )

    LST_ADD_HEADER_TEXT     ( WORD_TTL_SET_PH_MD )
    LST_ADD_HEADER_ICON( IMG_CMN_OPT_1 )
    LST_ADD_HEADER_IMAGE   ( IMG_CMN_LBL_2 )

    LST_ADD_ITEM            ( '1', TXT_MFN_NORMAL_MODE, IMG_BLANK )
    LST_ADD_COMMENT         ( <Please add a comment> )
    LST_ADD_CALLBACK        ( mtws_ModeFunc, ELIB_SS_PHONEMODE_NORMAL )
    LST_ADD_STYLE           ( NODE_STYLE )

    LST_ADD_ITEM            ( '2', TXT_MFN_MEETING_MODE, IMG_BLANK )
    LST_ADD_COMMENT         ( <Please add a comment> )
    LST_ADD_CALLBACK        ( mtws_ModeFunc, ELIB_SS_PHONEMODE_MEETING )
    LST_ADD_STYLE           ( NODE_STYLE )

    LST_ADD_ITEM            ( '3', TXT_MFN_POCKET_MODE, IMG_BLANK )
    LST_ADD_COMMENT         ( <Please add a comment> )
    LST_ADD_CALLBACK        ( mtws_ModeFunc, ELIB_SS_PHONEMODE_POCKET )
    LST_ADD_STYLE           ( NODE_STYLE )

    LST_ADD_ITEM            ( '4', TXT_MFN_CAR_MODE, IMG_BLANK )
    LST_ADD_COMMENT         ( <Please add a comment> )
    LST_ADD_CALLBACK        ( mtws_ModeFunc, ELIB_SS_PHONEMODE_CAR )
    LST_ADD_STYLE           ( NODE_STYLE )

LST_END_DESC

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

