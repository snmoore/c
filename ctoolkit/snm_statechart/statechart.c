#include <assert.h>         /* For assert */
#include <stdio.h>          /* For printf */

#include "statechart_types.h"

#if 0
static int FindInitialState(statechart_t *Statechart)
{
    int Found   = FALSE;
    int Result  = FALSE;
    
    int i;

    printf("Finding the initial state...\n");
    assert(NULL != Statechart);

    for(i = 0; i < Statechart->NumStates; i++)
    {
        /* Look for states that appear to be initial states */
        if(STATE_TYPE_TOP == Statechart->States[i].Type)
        {
            /* Check it is a valid state */
            if(Statechart->InvalidState != i)
            {
                /* Check for multiple initial states */
                if(FALSE == Found)
                {
                    Statechart->InitialState = i;
                    
                    Found  = TRUE;
                    Result = TRUE;    
                }
                else
                {
                    printf("\tERROR: found multiple initial states; %d\n", i);
                
                    Result = FALSE;
                    break;  
                }
            }
            else
            {
                printf("\tERROR: encountered an invalid state; %d\n", i);
                
                Result = FALSE;
                break;               
            }
        }
    }
    
    if(TRUE == Result)
    {
        printf("\tInitial state is %s\n",
               Statechart->States[Statechart->InitialState].Name);     
    }    

    printf("Finding the initial state...done\n");
    return Result;    
}

static int FindFinalState(statechart_t *Statechart)
{
    int Found   = FALSE;
    int Result  = FALSE;
    
    int i;

    printf("Finding the final state...\n");
    assert(NULL != Statechart);
    
    for(i = 0; i < Statechart->NumStates; i++)
    {
        /* Look for states that appear to be final states */
        if(STATE_TYPE_TOP == Statechart->States[i].Type)
        {
            /* Check it is a valid state */
            if(Statechart->InvalidState != i)
            {
                /* Check for multiple initial states */
                if(FALSE == Found)
                {
                    Statechart->FinalState = i;
                    
                    Found  = TRUE;
                    Result = TRUE;    
                }
                else
                {
                    printf("\tERROR: found multiple final states; %d\n", i);
                
                    Result = FALSE;
                    break;  
                }
            }
            else
            {
                printf("\tERROR: encountered an invalid state; %d\n", i);
                
                Result = FALSE;
                break;               
            }
        }
    }
    
    if(TRUE == Result)
    {
        printf("\tFinal state is %s\n",
               Statechart->States[Statechart->FinalState].Name);     
    }    

    printf("Finding the final state...done\n");
    return Result;    
}

static int RunEntryActions(statechart_t *Statechart)
{
    int Result = FALSE;
    const state_t *Current = NULL;
    int i;    

    printf("Running entry actions...\n");
    assert(NULL != Statechart);   

    /* Use a temporary variable for convenience */
    Current = &Statechart->States[Statechart->CurrentState];
    if(NULL != Current)
    {
        /* Run all entry actions in order */
        for(i = 0; i < Current->NumEntryActions; i++)
        {
            /* TODO: return events and push them onto the event queue */
            Statechart->Actions[Current->EntryActions[i]](NO_QUAL);
        }        

        Result = TRUE;
    }
    else
    {
        printf("\tERROR: encountered a bad current state; %d\n", Statechart->CurrentState);         
    }
     
    printf("Running entry actions...done\n");
    return Result;
}

static int GoToInitialState(statechart_t *Statechart)
{
    int Result = FALSE;
        
    printf("Going to the initial state...\n");
    assert(NULL != Statechart);
           
    /* Go to the initial state and run its entry actions */
    if(Statechart->InvalidState != Statechart->InitialState)
    {
        Statechart->CurrentState = Statechart->InitialState;
        RunEntryActions(Statechart);
        Result = TRUE;
    }
    else
    {
        printf("\tERROR: encountered an invalid state; %d\n", Statechart->InitialState);        
    }
    
    printf("Going to the initial state...done\n");
    return Result;  
}

static int ChangeState(statechart_t *Statechart, int ToState)
{
    int Result = FALSE;
        
    printf("Changing state...\n");
    assert(NULL != Statechart);
        
    /* Run any exit actions */
    
    /* Run any transition actions */
    
    /* Change the state */
    
    /* Run any entry actions */
    
    printf("Changing state...done\n");
    return Result;  
}

int InitialiseStatechart(statechart_t *Statechart)
{
    int Result = FALSE;
    
    printf("Initialising the statechart...\n");
    assert(NULL != Statechart);
    
    if(TRUE == FindInitialState(Statechart))
    {
        if(TRUE == FindFinalState(Statechart))
        {
            if(TRUE == GoToInitialState(Statechart))
            {
                /* TODO: start processing the event queue */
                Result = TRUE;
            }
            else
            {
                printf("\tERROR: could not go to the initial state\n");                 
            }    
        }
        else
        {
            printf("\tERROR: could not find the final state\n");        
        }    
    }
    else
    {
        printf("\tERROR: could not find the initial state\n");        
    }   
    
    printf("Initialising the statechart...done\n");
    return Result;   
}
#endif

int Validate(statechart_t *Statechart)
{
    int Result = TRUE;
    int i, j;
    int Count;
    state_t *State;
    tran_t  *Tran;
    
    printf("Validating the statechart...\n");
    assert(Statechart);
           
    /* Validate the top state */
    Count = 0;
    for(i = 0; i < Statechart->StateTable.Total; i++)
    {
        if(STATE_TYPE_TOP == Statechart->StateTable.Array[i].Type) 
        {
            /* There shall be only one top state */
            Count++;
            if(Count > 1)
            {
                Result = FALSE;
                printf("\tERROR: duplicate top state, index: %d\n", i);
            }
            
            /* The top state shall have no parent state (other than itself) */
            if( Statechart->StateTable.Array[i].Parent != 
               &Statechart->StateTable.Array[i]          )
            {
                Result = FALSE;
                printf("\tERROR: top state has a parent, index: %d\n", i);
            }
            
            /* TODO: The top state shall have only one initial transition */
        }
        printf("\tFound state, index: %d, name: %s\n", i, Statechart->StateTable.Array[i].Name); 
    }
    
    if(Count == 0)  /* There shall be one top state */
    {
        Result = FALSE;
        printf("\tERROR: no top state found\n");
    }

    /* Validate the other states */
    for(i = 0; i < Statechart->StateTable.Total; i++)
    {
        if(STATE_TYPE_TOP != Statechart->StateTable.Array[i].Type) 
        {
            /* All non-top states shall have a valid parent state */
            if(!((Statechart->StateTable.Array[i].Parent >=
                  &Statechart->StateTable.Array[0]) 
                    &&
                 (Statechart->StateTable.Array[i].Parent <=
                  &Statechart->StateTable.Array[Statechart->StateTable.Total]))) 
            {
                Result = FALSE;
                printf("\tERROR: state has no parent, index: %d\n", i);
            }
            
            /* TODO: All composite states shall have only one initial transition */        
        }
        printf("\tFound state, index: %d, parent: %s\n", i, Statechart->StateTable.Array[i].Parent->Name); 
    }
    
    /* Per state; validate the entry actions */
    for(i = 0; i < Statechart->StateTable.Total; i++)
    {
        State = &Statechart->StateTable.Array[i];
        
        for(j = 0; j < State->EntryTable.Total; j++)
        {
            if(!State->EntryTable.Array[j])
            {
                Result = FALSE;
                printf("\tERROR: invalid entry action function, state: %s, index: %d\n", State->Name, j);
            }
            printf("\tFound entry action function, state: %s, index: %d, function: %p\n", State->Name, j, State->EntryTable.Array[j]);      
        }
    }
    
    /* Per state; validate the exit actions */
    for(i = 0; i < Statechart->StateTable.Total; i++)
    {
        State = &Statechart->StateTable.Array[i];
        
        for(j = 0; j < State->ExitTable.Total; j++)
        {
            if(!State->ExitTable.Array[j])
            {
                Result = FALSE;
                printf("\tERROR: invalid exit action function, state: %s, index: %d\n", State->Name, j);
            }
            printf("\tFound exit action function, state: %s, index: %d, function: %p\n", State->Name, j, State->ExitTable.Array[j]);      
        }
    }
    
    /* Per state; validate the transitions */
    for(i = 0; i < Statechart->StateTable.Total; i++)
    {
        State = &Statechart->StateTable.Array[i];
        
        for(j = 0; j < State->TranTable.Total; j++)
        {
            Tran = &State->TranTable.Array[j];
            
            /* Target state is valid */
            if((Tran->TargetState == STATE_NO_STATE) ||
               (Tran->TargetState >= Statechart->StateTable.Total))
            {
                Result = FALSE;
                printf("\tERROR: invalid target state, state: %s, transition: %s, target: %d\n", State->Name, Tran->Name, Tran->TargetState);               
            }           
            printf("\tFound transition, state: %s, transition: %s, target: %s\n", State->Name, Tran->Name, Statechart->StateTable.Array[Tran->TargetState].Name);      
        }
    }                     
   
    /*
     * TODO: replace state ids with pointers to structures
     * 
     * Statechart.Top -> the top state
     * State.Current  -> the current state
     */
         
    printf("Validating the statechart...done\n");
    return Result;      
}

int Initialise(statechart_t *Statechart)
{
    int Result = FALSE;
    int i;

    printf("Initialising the statechart...\n");
    assert(Statechart);    
    
    /* Find the top state */
    for(i = 0; i < Statechart->StateTable.Total; i++)
    {
        if(STATE_TYPE_TOP == Statechart->StateTable.Array[i].Type) 
        {
            /* Remember the top state */
            Statechart->Top = &Statechart->StateTable.Array[i];
            Result = TRUE;
    
            /* For safety, we'll reset the top state's parent (was itself) */
            Statechart->Top->Parent = NULL;
            
            printf("\tFound top state, index: %d, name: %s\n", i, Statechart->Top->Name);             
            break;
        }
    }
       
    /* Perform the initial transitions */
        
    printf("Initialising the statechart...done\n");
    return Result;     
}