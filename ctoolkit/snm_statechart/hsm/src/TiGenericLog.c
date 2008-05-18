/* *************************************************************************** */
/* ****************************** HEADER FILES ******************************* */
/* *************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "conio.h"
#include "assert.h"

#include "string.h"
#include "TiGenericPub.h"

/* ***************************************************************************************
EXAMPLE OF EXPORT FILE FOR SDIGNALS

MMI:STA                             0
MMI:ENT                             1
MMI:INT                             2
MMI:EXT                             3
MMI:TRA                             4

STA:s_Entry s_ROOT                                  ClassId + s_Entry_ID
STA:s_Exit s_ROOT                                   ClassId + s_Exit_ID

ENT:a_Entry(0)                                  ClassId + entry index
ENT:a_Entry(1)                                  ClassId + entry index

INT:E_KEY_PRESS g_TRUE(0) a_Exit(0)             ClassId + int trans index
INT:E_KEY_PRESS g_ValidateKey('s') a_NULL(0)    ClassId + int trans index

EXT:a_Exit(0)                                   ClassId + exit index
EXT:a_Exit(1)                                   ClassId + exit index

TRA:E_KEY_PRESS s_Main g_ValidateKey('s') a_DisplayNumber(4)    ClassId + trans index
TRA:E_KEY_ANY s_Exit g_NULL(0) a_NULL(0)                        ClassId + trans index


EXAMPLE OF MACRO FILE

GEN_STA_START           ( Initial, s_ROOT, s_Entry, s_NULL )
    GEN_STA_ADD_ENTRY   ( a_Entry, 0)
    GEN_STA_ADD_INT     ( E_KEY_PRESS, g_TRUE, 0, a_DisplayNumber, 2  )
    GEN_STA_ADD_EXIT    ( a_DisplayNumber, 3 )
    GEN_STA_ADD_TRA     ( s_Main, E_KEY_PRESS, g_ValidateKey,'s', a_DisplayNumber, 4  )
GEN_STA_END

****************************************************************************************/
int id;
static char str[5048];
static char tmp[5048];
char *className;
int StateId, EntryId, ExitId, IntId, TransId;
FILE *stream = NULL;


void WriteLine( const char* Str, FILE * stream )
{
    if ( stream )
    {
        fprintf( stream, "%s\n", Str );
    }
    else
    {
        printf ( "%s\n", Str );
    }
}



// generate a list of logging types
const char *LogTypeName[CLASS_LOG_TYPE_MAX+1] =
{
    #define DEFINE_LOG_TYPE(a) #a,
    #include "TiGenericDef.m"
    NULL
};

//generate a list of class names
const char * ClassNames[] = 
{
    #define DEFINE_CLASS(a) #a,
    #include "TiGenericDef.m"
    ""
};

unsigned long Crc16( const char * CrcName )
{
    int i;
    unsigned long crc = 0xFFFF;
    unsigned char byte;
    unsigned short index;

    for ( i = 0; CrcName[i]; i++ )
    {
        byte = (unsigned char)CrcName[i];
    
        crc ^= byte << 8;
        for(index = 0; index <= 7; index++)
        {
            crc = crc & 0x8000 ? (crc << 1) ^ 0x8005 : crc << 1;
        } 
    
    }

    return crc & 0xFFFF;
}


int NameToClassID( const char * Name )
{
    int i;

    for ( i = (sizeof(ClassNames)/sizeof(ClassNames[0]))-1 ; i>= 0 && strcmp(ClassNames[i],Name) != 0  ; i-- )
    {
        //do nothing
    }

    if ( i < 0 )
    {
        /* if we didn't find it in our list then it should be a CRC generated value */
        i = Crc16(Name);
    }


    return i;
}




void ReplaceSpaceWithDot( char * str )
{
    int i;

    for ( i = 0; str[i] ; i++ )
    {
        if ( str[i] == ' ' )
        {
            str[i] = '.';
        }
    }
}


GenStaStart(char * s_ParentState, char * s_State, char * s_ChildState)
{	
    sprintf( tmp, "%s/%s (%s)", className, s_State, s_ParentState );
    ReplaceSpaceWithDot( tmp);
    sprintf( str, "%s:%-40s %X",LogTypeName[STA_LOG_ID], tmp, id + StateId++ );
    WriteLine( str, stream );
}

/*ENT:a_Entry(0)            000*/
/* formerly #define GEN_STA_ADD_ENTRY( ActionFn, ActionQual ) */
GenStaAddEntry( char * ActionFn, char * ActionQual )
{
    sprintf( tmp, "%s/%s(%s)", className, ActionFn, ActionQual );
    ReplaceSpaceWithDot( tmp);
    sprintf( str, "%s:%-40s %X",LogTypeName[ENT_LOG_ID], tmp, id + EntryId++ );
    WriteLine( str, stream );
}

/*EXT:a_Exit(0)            000*/
/* formerly #define GEN_STA_ADD_EXIT( ActionFn, ActionQual ) */
GenStaAddExit(char * ActionFn, char * ActionQual )
{
    sprintf( tmp, "%s/%s(%s)", className, ActionFn, ActionQual );
    ReplaceSpaceWithDot( tmp);
    sprintf( str, "%s:%-40s %X",LogTypeName[EXT_LOG_ID], tmp, id + ExitId++ );
    WriteLine( str, stream );
}

/*INT:E_KEY_PRESS g_TRUE(0) a_Exit(0)         000*/
/* formerly #define GEN_STA_ADD_INT( Event, GuardFn, GuardQual, ActionFn, ActionQual ) */
GenStaAddInt(char * Event, char * GuardFn, char * GuardQual, char * ActionFn, char * ActionQual)
{
    sprintf( tmp, "%s/%s %s(%s) %s(%s)", className, Event, GuardFn, GuardQual, ActionFn, ActionQual );
    ReplaceSpaceWithDot( tmp);
    sprintf( str, "%s:%-40s %X",LogTypeName[INT_LOG_ID], tmp, id + IntId++ );
    WriteLine( str, stream );
}

/*TRA:E_KEY_PRESS s_Main g_ValidateKey('s') a_DisplayNumber(4)          000*/
/*formerly #define GEN_STA_ADD_TRA( TrgState, Event, GuardFn, GuardQual, ActionFn, ActionQual ) */
GenStaAddTra(char * TrgState, char *  Event, char *  GuardFn, char *  GuardQual, char *  ActionFn, char *  ActionQual)
{
    sprintf( tmp, "%s/%s %s %s(%s) %s(%s)", className, TrgState, Event, GuardFn, GuardQual, ActionFn, ActionQual );
    ReplaceSpaceWithDot( tmp);
    sprintf( str, "%s:%-40s %X",LogTypeName[TRA_LOG_ID], tmp, id + TransId++ );
    WriteLine( str, stream );
}


void CreateExportFile( const char * FileName )
{
    int x;

    if ( *FileName == 0 )
    {
        //assert( 0 /* invlaid file name */ );
        return;
    }

    stream = fopen( FileName, "w+" );
    if ( !stream )
    {
        //assert( 0 /* can't open file */ );
        return;
    }


    for ( x = 0 ; x < CLASS_LOG_TYPE_MAX; x++ )
    {
        sprintf( str, "MMI:%-40s %X", LogTypeName[x], x );
        WriteLine( str, stream );
    }


    #define GEN_DECLARE_CLASS( c_Class ) \
        className = #c_Class; \
        id      = NameToClassID( className ) << 8; \
        StateId = 0; \
        EntryId = 0; \
        ExitId  = 0; \
        IntId   = 0; \
        TransId = 0; 

	#define GEN_STA_START( type, s_ParentState, s_State, s_ChildState ) {\
		GenStaStart(#s_ParentState, #s_State, #s_ChildState); }

	#define GEN_STA_ADD_ENTRY( ActionFn, ActionQual ) {\
		GenStaAddEntry(#ActionFn, #ActionQual);	}

	#define GEN_STA_ADD_EXIT( ActionFn, ActionQual ) {\
		GenStaAddExit(#ActionFn, #ActionQual); }

	#define GEN_STA_ADD_INT( Event, GuardFn, GuardQual, ActionFn, ActionQual ) {\
	    GenStaAddInt(#Event, #GuardFn, #GuardQual, #ActionFn, #ActionQual);	}

	#define GEN_STA_ADD_TRA( TrgState, Event, GuardFn, GuardQual, ActionFn, ActionQual ) {\
		GenStaAddTra(#TrgState, #Event, #GuardFn, #GuardQual, #ActionFn, #ActionQual); }


    #define GEN_ABORT_UNDEFINE_MACROS
    #include "TiGenericAll.m"

    if ( *FileName )
    {
        assert( fclose( stream ) == 0 /* can't close file */ );
    }

}
