/* *************************************************************************** */
/* ****************************** HEADER FILES ******************************* */
/* *************************************************************************** */
/*$Include$*/

/* ANSI include files.    */

/* Global include files.  */
#include <x11/keysymdef.h>
#include "textedit.h"
#include <xm/bulletinb.h>
#include <xm/label.h>
#include "xm/text.h"
#include "LibImagePub.h"

/* MS API include files */
#include "MsApiCsvPub.h"

/* Local include files.   */
#include "MuiApplicationPub.h"
#include "MuiDisplayMessagePub.h"

/* NEC-J include files. */
#include "Srv_DSP_BL.h"
/*$end$*/

/* *************************************************************************** */
/* **************************** CLASS HEADER FILE **************************** */
/* *************************************************************************** */
#include "MuiEmergencyCallPub.h"

/* *************************************************************************** */
/* **************************** CLASS INFORMATION **************************** */
/* *************************************************************************** */
#define STEREOTYPE          DYNAMIC_CLASS_TYPE
#define MACRO_FILE          "MuiEmergencyCallint.m"
#define CLASS_INFO          C_MUI_EMERGENCY_CALL_CLASS_INFO
#define CLASS_ID            C_MUI_EMERGENCY_CALL_ID
#define CLASS_TYPE          C_MUI_EMERGENCY_CALL
#define CLASS_NAME          "C_MUI_EMERGENCY_CALL"
#define ENTRY_STATE         Start
#define EXIT_STATE          Exit
#define SIZE_OF_PUBLIC      0
#define SIZE_OF_PROTECTED   0
#define SIZE_OF_PRIVATE     SIZE_OF_INT(C_MUI_EMERGENCY_CALL_PRIVATE)
#define MAXS_NUM_INSTANCES  1

/* *************************************************************************** */
/* ************************ MACRO FUNCTION PROTOTYPES ************************ */
/* *************************************************************************** */
DECLARE_PRIVATE_ACTION( a_Entry )
DECLARE_PRIVATE_ACTION( a_StartEmergencyTimer )
DECLARE_PRIVATE_ACTION( a_DialLockEmergencyCnfDlg )
DECLARE_PRIVATE_ACTION( a_StartDefaultEmergency )
DECLARE_PRIVATE_ACTION( a_LoadNoSimPresentScreen )
DECLARE_PRIVATE_ACTION( a_SetEmergencyNumber )
DECLARE_PRIVATE_GUARD( g_WithNoSimScreen )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_EmergencyCall )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_EmergencyCnfDlgKeyPressed )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_StartEmergencyCall )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_EmergencyStringChange )

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
/*$end$*/

/* *************************************************************************** */
/* ********************** PRE CODE GENERATOR DEFINITIONS ********************* */
/* *************************************************************************** */
/*$PreCodeGen$*/
/* *************************************************************************** */
/* ********************************** MACROS ********************************* */
/* *************************************************************************** */

/* Enter other macro definitions here... */

/* *************************************************************************** */
/* ************************** CONSTANT DECLARATIONS ************************** */
/* *************************************************************************** */

#define GEN_DIALOG_INFO
#include "MuiApplicationDlg.m"

/* *************************************************************************** */
/* ******************************** TYPEDEFS ********************************* */
/* *************************************************************************** */

/* Enter user defined types here... */

/* *************************************************************************** */
/* ************************** VARIABLE DECLARATIONS ************************** */
/* *************************************************************************** */

/* Enter variable declarations here... */


/*$end$*/

/* *************************************************************************** */
/* **************************** PRIVATE STRUCTURES *************************** */
/* *************************************************************************** */
/* PrivateAccess Attributes */
struct _C_MUI_EMERGENCY_CALL_PRIVATE
{
/*$InstStruct$*/
	TL_MUI_APP_DIALOG*			m_Dlg;
	C_MUI_DISPLAY_MESSAGE*		m_DisplayMessage;
	TI_MUI_VOICE_CALLS_INTERFACE* m_pVoiceCallsClass;
	Widget						m_HeaderWallpaperWidget;
	Pixmap						m_HeaderWallpaper;
	TS_MUI_APP_TIMER			m_Timer;
	TS_SESSION_DETAILS*			m_pSession;
	int							m_bNoSimScreen;
	TS_TEXT_ID					m_EmergencyTextId;
/*$end$*/
};


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

/* *************************************************************************** */
/* ********************* POST CODE GENERATOR DEFINITIONS ********************* */
/* *************************************************************************** */
/*$PostCodeGen$*/

/* add your code here */

/*$end$*/

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
* <C_MUI_EMERGENCY_CALL* This>
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
{
   /* Enter instance initialisation here... */
   This->Private->m_EmergencyTextId = TXT_POW_NO_SIM_PRESENT;
}
END_CLASS_NEW

/*******************************************************************************
*                       D O   N O T   R E M O V E
* MACRO: START_CLASS_DELETE
*
* <C_MUI_EMERGENCY_CALL* This>
* This is a pointer to a newly created instance of this class type.
*
* Description
* This macro is called when an instance of this class is deleted. This
* function is used to deallocated and free any resource which it might have
* required
*******************************************************************************/
START_CLASS_DELETE
{
   MuiAppTimerDestroy(&This->Private->m_Timer);
}
END_CLASS_DELETE

/*******************************************************************************
*                       D O   N O T   R E M O V E
* MACRO: START_CLASS_PROCESS_SIGNAL
*
* <C_MUI_EMERGENCY_CALL* This>
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
* MACRO: a_Entry
*
* <C_MUI_EMERGENCY_CALL* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $end$
*******************************************************************************/
START_PRIVATE_ACTION ( a_Entry )
{
    if(Qual)
    {
        FsmIfAddEvent(This, e_Start);
    }
    else
    {
    	FsmIfAddEvent (GetThisParent(This), E_DONE);
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_SetEmergencyNumber
*
* <C_MUI_EMERGENCY_CALL* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $end$
*******************************************************************************/
START_PRIVATE_ACTION ( a_SetEmergencyNumber )
{
    XSetWindowAttributes Attr;
    TI_ANIMATION Anim;
    UINT depth;

    if(Qual==LOAD)
    {
        MuiAppLoadDialog( This, &This->Private->m_Dlg, MuiAppGetRootWidget(This), DLG_EMERGENCY_CALL );
        This->Private->m_HeaderWallpaperWidget = MuiAppGetDlgItem(This->Private->m_Dlg, WIG_EMERGENCY_HEADER);
        
        if ( This->Private->m_HeaderWallpaperWidget != NULL )
        {
            /* Load a smooth wallpaper into the header bar */
            depth = PlanesOfScreen( XtScreen( This->Private->m_HeaderWallpaperWidget ) );
            LibImgGetAnimation( &Anim, IMG_CMN_LBL_5 );
		/*cosmobic fix ULT-CR1-02380*/
            This->Private->m_HeaderWallpaper = XCreatePixmapRom(
                                                   XtDisplay( This->Private->m_HeaderWallpaperWidget ),
                                                   RootWindowOfScreen( XtScreen( This->Private->m_HeaderWallpaperWidget ) ),
                                                   LibImgGetBitMap( Anim.Frames[0].BitmapId  ),
                                                   Anim.Height, Anim.Width, depth );

            Attr.background_pixmap = This->Private->m_HeaderWallpaper;

            XChangeWindowAttributes( XtDisplay( This->Private->m_HeaderWallpaperWidget ),
                                        XtWindow( This->Private->m_HeaderWallpaperWidget ),
                                        CWBackPixmap, &Attr);
        }
    }
    else
    {
        if ( This->Private->m_HeaderWallpaperWidget != NULL )
        {
            /* Free the loaded wallpaper from the header bar */
            XFreePixmap( XtDisplay( This->Private->m_HeaderWallpaperWidget ), This->Private->m_HeaderWallpaper );
        }
        MuiAppUnloadDialog( &This->Private->m_Dlg );
        This->Private->m_Dlg = NULL;
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: mtws_EmergencyCall
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
START_PRIVATE_MTWS_CALLBACK ( mtws_EmergencyCall )
{
	TL_MUI_GRAB_DATA* Data = ( TL_MUI_GRAB_DATA* )call_data;

	if(Data->event->xkey.keycode <= XK_KP_9 && Data->event->xkey.keycode >= XK_KP_0)
    {
    	Data->processed=FALSE;
	}
	else
	{
		switch( Data->event->xkey.keycode )
		{
			case XK_KEY_SOFT2:
				FsmIfAddEvent(This, E_DONE);
				break;
			case XK_KEY_NAVI_ETR:
				FsmIfAddEvent(This, e_StartDefaultEmergency);
				break;
			case XK_KEY_SOFT1:
				{
					TS_PHONE_NUMBER   EmergencyPhoneNoStruct;
					Widget wiget = MuiAppGetDlgItem(This->Private->m_Dlg, WIG_EMERGENCY_NUMBER);
					char* EmergencyNo = XmTextGetString( wiget );
					LibPhoneNumFromUtf8( &EmergencyPhoneNoStruct, EmergencyNo );
					if(EMER_MATCHED == LibPhoneNumCheckPartialEmergencyNum(&EmergencyPhoneNoStruct,ALL_EMERGENCY_NUMBER_MASK))
					{
						if(This->Private->m_pVoiceCallsClass)
						{
							MuiCsvSetDialString(This->Private->m_pVoiceCallsClass, EmergencyNo);
						}
						else
						{
							MsApiCsvCreateConnectionReq(This->Private->m_pSession, &EmergencyPhoneNoStruct);
						}
						FsmIfAddEvent(This, E_DONE);
					}
					XtFree( EmergencyNo );
				}
				break;
			case XK_KEY_ON_HOOK:
			case XK_KEY_OFF_HOOK:
				FsmIfAddEvent(This, E_DONE);
				break;
			case XK_KEY_CLEAR:
				{
					Widget wiget = MuiAppGetDlgItem(This->Private->m_Dlg, WIG_EMERGENCY_NUMBER);
					char* str = XmTextGetString( wiget );
					if(strlen(str) == 0)
					{
						FsmIfAddEvent(This, E_DONE);
					}
					else
					{
						Data->processed=FALSE;
					}
					XtFree( str );
				}
				break;
			default:
				Data->processed=FALSE;
				break;
		}
	}

	/* Restart the timer */
	MuiAppTimerDestroy(&This->Private->m_Timer);
	MuiAppTimerCreateEvent( &This->Private->m_Timer, This, E_DONE, 4000, TRUE, TRUE);
}
END_PRIVATE_MTWS_CALLBACK


/*******************************************************************************
*
* MACRO: mtws_EmergencyStringChange
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
* The emergency number is changed.
* $End$
*******************************************************************************/
START_PRIVATE_MTWS_CALLBACK ( mtws_EmergencyStringChange )
{
    char * str = XmTextEditGetString( w );
    TS_PHONE_NUMBER   EmergencyPhoneNoStruct;
    if(strlen(str) >= 2)
    {
    	LibPhoneNumFromUtf8( &EmergencyPhoneNoStruct, str );
    	if(EMER_MATCHED == LibPhoneNumCheckPartialEmergencyNum(&EmergencyPhoneNoStruct,ALL_EMERGENCY_NUMBER_MASK))
    	{
    		MuiAppSetDlgTextId( This->Private->m_Dlg, TXT_TEL_KEY_SEND, MUI_DLG_TEXT_LEFT );
    	}
    	else
    	{
    		MuiAppSetDlgTextId( This->Private->m_Dlg, TXT_BLANK, MUI_DLG_TEXT_LEFT );
    		
    		/* If the three inputed number is not emergency number, return to IDLE.*/
    		if(strlen(str) == 3)
    		{
    			FsmIfAddEvent(This, E_DONE);
    		}
    	}
    }
    else
    {
    	MuiAppSetDlgTextId( This->Private->m_Dlg, TXT_BLANK, MUI_DLG_TEXT_LEFT );
    }
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: a_StartEmergencyTimer
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
START_PRIVATE_ACTION ( a_StartEmergencyTimer )
{
    if(Qual)
    {
		MuiAppTimerCreateEvent( &This->Private->m_Timer, This, E_DONE, 4000, TRUE, TRUE);
	}
	else
	{
		MuiAppTimerDestroy(&This->Private->m_Timer);
	}
}
END_PRIVATE_ACTION


/*******************************************************************************
*
* MACRO: a_DialLockEmergencyCnfDlg
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
START_PRIVATE_ACTION ( a_DialLockEmergencyCnfDlg )
{
	if(Qual)
	{
		This->Private->m_DisplayMessage = FsmIfCreateInstance( This, C_MUI_DISPLAY_MESSAGE );
	    MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_CNF_1);
		This->Private->m_DisplayMessage->Public->m_TextId = TXT_IDLE_SOS_EMERGENCY;
		MuiSetByPassKeyPress(This->Private->m_DisplayMessage, TRUE);
		MuiDisMsgSetSoftKey( This->Private->m_DisplayMessage, MUI_DLG_TEXT_LEFT, WORD_KEY_CMN_YES, e_StartDefaultEmergency);
		MuiDisMsgSetSoftKey( This->Private->m_DisplayMessage, MUI_DLG_TEXT_RIGHT, WORD_KEY_CMN_NO, E_DONE);
		This->Private->m_DisplayMessage->Public->m_MaxDuration = 4000;
        MuiSetSendKey( This->Private->m_DisplayMessage, E_DONE);
        MuiDisMsgSetTickKey( This->Private->m_DisplayMessage, E_DONE);
        MuiDisMsgSetClearKey( This->Private->m_DisplayMessage, E_DONE);
        MuiSetEndKey( This->Private->m_DisplayMessage, E_DONE);
        
        MuiAppRegisterGrabEvent( This, XtTMAny, XtTEKey, 0, mtws_EmergencyCnfDlgKeyPressed );
	}
	else
	{
		FsmIfDeleteInstance( This->Private->m_DisplayMessage );
		This->Private->m_DisplayMessage = NULL;
		MuiAppDeRegisterGrabEvent( This, mtws_EmergencyCnfDlgKeyPressed_FNC );
	}
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: mtws_EmergencyCnfDlgKeyPressed
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
START_PRIVATE_MTWS_CALLBACK ( mtws_EmergencyCnfDlgKeyPressed )
{
    TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;
	if(Data->event->type == KeyPress)
    {
        if(Data->event->xkey.keycode <= XK_KP_9 && Data->event->xkey.keycode >= XK_KP_0)
        {
        	char buffer[5];
        	Widget StrWidget = MuiAppGetDlgItem(This->Private->m_Dlg, WIG_EMERGENCY_NUMBER);
        	sprintf(buffer, "%d", Data->event->xkey.keycode - XK_KP_0);
        	XmTextEditSetString(StrWidget, buffer);
        	XtVaSetValues( StrWidget, XmNcursorPosition, strlen(buffer), NULL);
        	FsmIfAddEvent(This, E_CANCEL);
        }
        else
        {
        	FsmIfAddEvent(This, E_DONE);
        }
    }
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: a_StartDefaultEmergency
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
START_PRIVATE_ACTION ( a_StartDefaultEmergency )
{
	if(This->Private->m_pVoiceCallsClass)
	{
		MuiCsvSetDialString(This->Private->m_pVoiceCallsClass, "112");
	}
	else
	{
		TS_PHONE_NUMBER	PhoneNumber;
		LibPhoneNumFromUtf8( &PhoneNumber, "112" );
		MsApiCsvCreateConnectionReq(This->Private->m_pSession, &PhoneNumber);
	}
	FsmIfAddEvent(This, E_DONE);
}
END_PRIVATE_ACTION


/*******************************************************************************
*
* MACRO: g_WithNoSimScreen
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
START_PRIVATE_GUARD ( g_WithNoSimScreen )
{
	return (This->Private->m_bNoSimScreen == Qual);
}
END_PRIVATE_GUARD


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
    Widget TextWidget;

    if ( Qual )
    {
        MuiAppLoadDialog( This, &This->Private->m_Dlg, MuiAppGetRootWidget(This), DLG_SIM_MALFUNCTION );
        TextWidget = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_TEXT );
        MuiAppSetTextId( TextWidget, This->Private->m_EmergencyTextId );
#ifdef CHW_SUBLCD
		/* Show No SIM prompt on the sublcd. */
		Elib_DSP_BL_Dsp( MuiAppGetApId(This), ELIB_DSP_BL_NO_CARD, NULL, NULL, 0 );
#else
#endif 
    }
    else
    {
        MuiAppUnloadDialog( &This->Private->m_Dlg );

#ifdef CHW_SUBLCD
    	Elib_DSP_BL_Erase( MuiAppGetApId(This), ELIB_DSP_BL_NO_CARD );
#else
#endif 
    }
}
END_PRIVATE_ACTION


/*******************************************************************************
*
* MACRO: mtws_StartEmergencyCall
*
* $UniqueID:3F28DCB4015B$
*
* <C_MUI_POWER_UP* This>
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
START_PRIVATE_MTWS_CALLBACK ( mtws_StartEmergencyCall )
{
	TL_MUI_GRAB_DATA* Data = (TL_MUI_GRAB_DATA*)call_data;
	if(Data->event->xkey.keycode == XK_KEY_SOFT2)
	{
		FsmIfAddEvent(This, e_GotoSos);
	}
}
END_PRIVATE_MTWS_CALLBACK


void MuiSetEmergencyType( C_MUI_EMERGENCY_CALL* This, BOOLEAN flag, TI_MUI_VOICE_CALLS_INTERFACE* pVoiceCallsClass, TS_SESSION_DETAILS* pSession )
{
	This->Private->m_pVoiceCallsClass = pVoiceCallsClass;
	This->Private->m_pSession = pSession;
	This->Private->m_bNoSimScreen = flag;
	FsmIfAddEvent(This, e_Start);
}
void MuiSetEmergencyTextId( C_MUI_EMERGENCY_CALL* This, TS_TEXT_ID TextId )
{
	Widget TextWidget;
	This->Private->m_EmergencyTextId = TextId;
	TextWidget = MuiAppGetDlgItem( This->Private->m_Dlg, WIG_TEXT );
	if(TextWidget)
	{
		MuiAppSetTextId( TextWidget, This->Private->m_EmergencyTextId );
	}
}
/* *************************************************************************** */
/* *********************************** END *********************************** */
/* *************************************************************************** */

