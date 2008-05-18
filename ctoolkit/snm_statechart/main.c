#include <stdio.h>          /* For printf */


/* Build the test statechart */
#define STATECHART_FILE "test.sc"
#include "statechart.h"

/* Action functions */
static void Action0(unsigned int Qual)
{
    if(Qual)
    {
        printf("\t\tRunning action 0: qualifier is TRUE\n");
    }
    else
    {
        printf("\t\tRunning action 0: qualifier is FALSE\n");        
    }  
}

static void Action1(unsigned int Qual)
{
    if(Qual)
    {
        printf("\t\tRunning action 1: qualifier is TRUE\n");
    }
    else
    {
        printf("\t\tRunning action 1: qualifier is FALSE\n");        
    }  
}

static void Action2(unsigned int Qual)
{
    if(Qual)
    {
        printf("\t\tRunning action 2: qualifier is TRUE\n");
    }
    else
    {
        printf("\t\tRunning action 2: qualifier is FALSE\n");        
    }  
}

static void Action3(unsigned int Qual)
{
    if(Qual)
    {
        printf("\t\tRunning action 3: qualifier is TRUE\n");
    }
    else
    {
        printf("\t\tRunning action 3: qualifier is FALSE\n");        
    }   
}

static void Action4(unsigned int Qual)
{
    if(Qual)
    {
        printf("\t\tRunning action 4: qualifier is TRUE\n");
    }
    else
    {
        printf("\t\tRunning action 4: qualifier is FALSE\n");        
    }  
}

static void Action5(unsigned int Qual)
{
    if(Qual)
    {
        printf("\t\tRunning action 5: qualifier is TRUE\n");
    }
    else
    {
        printf("\t\tRunning action 5: qualifier is FALSE\n");        
    }  
}

static void Action6(unsigned int Qual)
{
    if(Qual)
    {
        printf("\t\tRunning action 6: qualifier is TRUE\n");
    }
    else
    {
        printf("\t\tRunning action 6: qualifier is FALSE\n");        
    } 
}

static void Action7(unsigned int Qual)
{
    if(Qual)
    {
        printf("\t\tRunning action 7: qualifier is TRUE\n");
    }
    else
    {
        printf("\t\tRunning action 7: qualifier is FALSE\n");        
    } 
}

/* Guard functions */
static void Guard0(unsigned int Qual)
{
    if(Qual)
    {
        printf("\t\tRunning guard 0: qualifier is TRUE\n");
    }
    else
    {
        printf("\t\tRunning guard 0: qualifier is FALSE\n");        
    }
}

static void Guard1(unsigned int Qual)
{
    if(Qual)
    {
        printf("\t\tRunning guard 1: qualifier is TRUE\n");
    }
    else
    {
        printf("\t\tRunning guard 1: qualifier is FALSE\n");        
    }  
}

int main(void)
{
    int i, j;
 
#if 0    
    /* Actions */
    printf("\nActions:\n");
    printf("\tFirst:\t%d\n", ACTION_FIRST);
    printf("\tLast :\t%d\n", ACTION_LAST);
    printf("\tTotal:\t%d\n", ACTION_TOTAL);

    printf("\n");
    for(i = ACTION_FIRST; i < ACTION_TOTAL; i++)
    {
        Actions[i](i % 2);
    }
#endif
    
    /* Events */
    printf("\nEvents:\n");
    printf("\tFirst:\t%d\n", EVENT_FIRST);
    printf("\tLast :\t%d\n", EVENT_LAST);
    printf("\tTotal:\t%d\n", EVENT_TOTAL);

#if 0
    /* Guards */
    printf("\nGuards:\n");
    printf("\tFirst:\t%d\n", GUARD_FIRST);
    printf("\tLast :\t%d\n", GUARD_LAST);
    printf("\tTotal:\t%d\n", GUARD_TOTAL);

    printf("\n");
    for(i = GUARD_FIRST; i < GUARD_TOTAL; i++)
    {
        Guards[i](i);
    }
#endif

    /* States */
    printf("\nStates:\n");
    printf("\tFirst:\t%d\n", STATE_FIRST);
    printf("\tLast :\t%d\n", STATE_LAST);
    printf("\tTotal:\t%d\n", STATE_TOTAL);

    printf("\n");
    for(i = STATE_FIRST; i < STATE_TOTAL; i++)
    {
        printf("\tState:\t%s\tType:\t%d"
               "\tEntry Actions:\t%d"
               "\tExit Actions:\t%d"
               "\tTransitions:\t%d\n",
               States[i].Name,
               States[i].Type,
               States[i].EntryTable.Total,
               States[i].ExitTable.Total,
               States[i].TranTable.Total);
    }

    printf("\n");
    for(i = STATE_FIRST; i < STATE_TOTAL; i++)
    {
        printf("\t%s:\n", States[i].Name);
        
        for(j = 0; j < States[i].TranTable.Total; j++)
        {
            printf("\t\tTransition:\t%s\tUpon Event:\t%d\tTo State:\t%d\n",
                   States[i].TranTable.Array[j].Name,
                   States[i].TranTable.Array[j].Event,
                   States[i].TranTable.Array[j].TargetState);
        }
    }    

#if 0
    /* Transitions */
    printf("\nTransitions:\n");
    printf("\tFirst:\t%d\n", TRANS_FIRST);
    printf("\tLast :\t%d\n", TRANS_LAST);
    printf("\tTotal:\t%d\n", TRANS_TOTAL);
#endif

#if 0    
    printf("\n");
    for(i = TRANS_FIRST; i < TRANS_TOTAL; i++)
    {
        printf("\tTransition:\t%s\tUpon Event:\t%d\tTo State:\t%d\n",
               Transitions[i].Name,
               Transitions[i].Event,
               Transitions[i].ToState);
    }
#endif

#if 0
    if(InitialiseStatechart(&Statechart) != TRUE)
    {
        printf("Statechart initialisation failed!\n");   
    }
#endif

    Validate(&Statechart);
    Initialise(&Statechart);    
  
    return 0;    
}
