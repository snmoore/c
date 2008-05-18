/* *************************************************************************** */
/* ****************************** HEADER FILES ******************************* */
/* *************************************************************************** */
/*$Include$*/

/* ANSI include files.    */

/* Global include files.  */
#include <x11/keysymdef.h>
#include "SysConnectionNumberPub.h"
#include "SysPhonebookPub.h"
#include "SysCommonPub.h"
/* Lisa Types*/
#include "MsApiEventNtfPub.h"
#include "SysSessionPub.h"
#include "HTT_LisaStub.h"
/* Local include files.   */

#include "MuiApplicationPub.h"
#include "MuiDisplayMessagePub.h"
//#include "SysTypesPub.h"
//
#include "LibImagePub.h"

/* Private include files. */
#include "Srv_SS.h"
#include "Srv_WDC.h"

/*$end$*/

/* *************************************************************************** */
/* **************************** CLASS HEADER FILE **************************** */
/* *************************************************************************** */
#include "MuiModePub.h"

/* *************************************************************************** */
/* **************************** CLASS INFORMATION **************************** */
/* *************************************************************************** */
#define STEREOTYPE          DYNAMIC_CLASS_TYPE
#define MACRO_FILE          "MuiModeInt.m"
#define CLASS_INFO          C_MUI_MODE_CLASS_INFO
#define CLASS_ID            C_MUI_MODE_ID
#define CLASS_TYPE          C_MUI_MODE
#define CLASS_NAME          "C_MUI_MODE"
#define ENTRY_STATE         Start
#define EXIT_STATE          Exit
#define SIZE_OF_PUBLIC      0
#define SIZE_OF_PROTECTED   0
#define SIZE_OF_PRIVATE     SIZE_OF_INT(C_MUI_MODE_PRIVATE)
#define MAXS_NUM_INSTANCES  1

/* *************************************************************************** */
/* ************************ MACRO FUNCTION PROTOTYPES ************************ */
/* *************************************************************************** */
DECLARE_PRIVATE_ACTION( a_Entry )
DECLARE_PRIVATE_ACTION( a_LoadModeMenu )
DECLARE_PRIVATE_ACTION( a_LoadConfirm )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_CancelKey )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_EndKey )
DECLARE_PRIVATE_MTWS_CALLBACK( mtws_ModeFunc )

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
struct _C_MUI_MODE_PRIVATE
{
/*$InstStruct$*/
   TL_MUI_APP_DIALOG*        m_Dlg;
   C_MUI_DISPLAY_MESSAGE*    m_DisplayMessage;
   TS_TEXT_ID                m_ConfMessage;
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
* <C_MUI_MODE* This>
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
}
END_CLASS_NEW

/*******************************************************************************
*                       D O   N O T   R E M O V E
* MACRO: START_CLASS_DELETE
*
* <C_MUI_MODE* This>
* This is a pointer to a newly created instance of this class type.
*
* Description
* This macro is called when an instance of this class is deleted. This
* function is used to deallocated and free any resource which it might have
* required
*******************************************************************************/
START_CLASS_DELETE
{
   /* Enter instance De-initialisation here... */
}
END_CLASS_DELETE

/*******************************************************************************
*                       D O   N O T   R E M O V E
* MACRO: START_CLASS_PROCESS_SIGNAL
*
* <C_MUI_MODE* This>
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
* <C_MUI_MODE* This>
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
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadModeMenu
*
* <C_MUI_MODE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $end$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadModeMenu )
{
    if(Qual==LOAD)
    {
        MuiAppLoadDialog( This, &This->Private->m_Dlg, MuiAppGetRootWidget(This), DLG_MODE_MENU );
    }
    else
    {
        MuiAppUnloadDialog( &This->Private->m_Dlg );
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: a_LoadConfirm
*
* <C_MUI_MODE* This>
* This is a pointer to an instance of this class type.
* 
* <UINT8 Qual>
* This is the qualify value
*
* $Description$
* <please add description here >
* $end$
*******************************************************************************/
START_PRIVATE_ACTION ( a_LoadConfirm )
{
	if(Qual)
	{
		This->Private->m_DisplayMessage = FsmIfCreateInstance( This, C_MUI_DISPLAY_MESSAGE );
        MuiDisMsgSetStyle (This->Private->m_DisplayMessage, DLG_INF_3);
        This->Private->m_DisplayMessage->Public->m_TextId = This->Private->m_ConfMessage;
    }
    else
    {
    	FsmIfDeleteInstance( This->Private->m_DisplayMessage );
    	FsmIfAddEvent (GetThisParent(This), E_DONE);
    }
}
END_PRIVATE_ACTION

/*******************************************************************************
*
* MACRO: mtws_CancelKey
*
* <C_MUI_MODE* This>
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
START_PRIVATE_MTWS_CALLBACK ( mtws_CancelKey )
{
   FsmIfAddEvent(This, e_End);
   FsmIfAddEvent(GetThisParent(This), E_CANCEL );
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_EndKey
*
* <C_MUI_MODE* This>
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
START_PRIVATE_MTWS_CALLBACK ( mtws_EndKey )
{
   FsmIfAddEvent(This, e_End);
   FsmIfAddEvent(GetThisParent(This), E_DONE );
}
END_PRIVATE_MTWS_CALLBACK

/*******************************************************************************
*
* MACRO: mtws_ModeFunc
*
* <C_MUI_MODE* This>
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
START_PRIVATE_MTWS_CALLBACK ( mtws_ModeFunc )
{
    C_MUI_MODE *This = (C_MUI_MODE*)client_data;
    XmTreeNodeCallbackStruct *Data = (XmTreeNodeCallbackStruct *)call_data;
    
    if (Data->reason & XmTREE_NODE_ITEM_IS_SET)
    {
	    /* Since we're displaying the select menu, the current mode should be one of these four:Normal,Pocket,Meeting,Noisy */
		TS_PHONE_MODE Mode;

		Mode = Elib_WDC_Get_PhoneMode( MuiAppGetApId (This));
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
        
        Elib_WDC_Set_PhoneMode (MuiAppGetApId(This), Data->qual);
        
        FsmIfAddEvent(This, e_End);
        /* Send event when phone mode changed */
        {
        	TI_EVID_NULL_STRUCT EventData;
			EventData.Id   = EVID_MFN_SETTING_IND;
			EventData.Ptr  = NULL;
			EventData.Size = 0;
			MsApiEvBroadcastEventInd(NULL, &EventData);
        }
		FsmIfAddEvent (GetThisParent(This), E_DONE);
    }
}
END_PRIVATE_MTWS_CALLBACK

/* *************************************************************************** */
/* *********************************** END *********************************** */
/* *************************************************************************** */

