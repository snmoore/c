#ifndef STATECHART_ENUM_ACTION_H_
#define STATECHART_ENUM_ACTION_H_


/* Statechart build pass 1: build an enum of all actions */
#ifdef STATECHART_BUILD_ENUMS

#include "statechart_undef.h"   /* Ignore unused statechart macros */

#undef  ACTION
#define ACTION(action)  ACTION_##action,

typedef enum
{
    #include STATECHART_FILE
    ACTION_DUMMY
} action_id_t;

#define ACTION_FIRST    (0)
#define ACTION_LAST     (ACTION_DUMMY - 1)
#define ACTION_TOTAL    (ACTION_LAST - ACTION_FIRST + 1)

#endif /* STATECHART_BUILD_ENUMS */


#endif /*STATECHART_ENUM_ACTION_H_*/
