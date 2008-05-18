/* No multiple include protection - this file is parsed multiple times */


/* 
 * Actions
 */
ACTION(Action0)
ACTION(Action1)
ACTION(Action2)
ACTION(Action3)
ACTION(Action4)
ACTION(Action5)
ACTION(Action6)
ACTION(Action7)

/* 
 * Events
 */
EVENT(Event0)
EVENT(Event1)
EVENT(Event2)
EVENT(Event3)

/*
 * Guards
 */
GUARD(Guard0)
GUARD(Guard1)

/* 
 * States
 *
 * There must be one (and only one) TOP state for this statechart
 *
 * All other states must be child states of the TOP state, or of other composite
 * states
 *
 * Because of how we do the pre-processing, the parent of the TOP state cannot
 * be NULL, so make the TOP state be its own parent; we'll reset this to NULL
 * when initialising the statechart
 * 
 * The TOP state must have one INITIAL transition to the desired initial state,
 * which is implicitly followed upon initialisation of this statechart
 *
 * All COMPOSITE states must have one INITIAL transition to the desired initial
 * state, which is implicitly followed upon entering the COMPOSITE state
 */
STATE(TOP, StateTop, StateTop)
	TRANS(INITIAL, TransInit, NO_EVENT, State0, NO_GUARD, NO_ACTION)	
STATE_END
 
STATE(SIMPLE, State0, StateTop)
	ENTRY(Action0)
	ENTRY(Action1)
	
	TRANS(NORMAL, Trans0, Event0, State1, NO_GUARD, NO_ACTION)
	TRANS(NORMAL, Trans3, Event3, State2, Guard0,   NO_ACTION)
STATE_END

STATE(SIMPLE, State1, StateTop)
	ENTRY(Action2)

	TRANS(NORMAL, Trans1, Event1, State0, NO_GUARD,	Action3)
	TRANS(NORMAL, Trans2, Event2, State2, Guard1,	Action4)

	EXIT(Action5)
STATE_END

STATE(SIMPLE, State2, StateTop)
	EXIT(Action6)
	EXIT(Action7)
STATE_END
