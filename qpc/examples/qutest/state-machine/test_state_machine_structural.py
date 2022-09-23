def on_reset():
    expect_pause() # Expects QS_TEST_PAUSE() inside test fixture
    glb_filter(GRP_ALL) # Sends complete QS Global Filter to target
    continue_test()  # Continues the test after QS_TEST_PAUSE()
    expect("@timestamp TE0-Arm  Obj=l_state_machine.timeEvt,AO=l_state_machine,*") # Expected QSpy output
    expect("===RTC===> St-Init  Obj=l_state_machine,State=QHsm_top->state_machine_state_1") # initial transition
    expect("@timestamp STATE 1")
    expect("===RTC===> St-Entry Obj=l_state_machine,State=state_machine_state_1") # state was entered
    expect("@timestamp Init===> Obj=l_state_machine,State=state_machine_state_1") # the top-most initial transition was taken
    expect_run() # Expects QF_run() function inside test fixture
    current_obj(OBJ_SM_AO,"l_state_machine") # Sets current object in target
    current_obj(OBJ_TE,"l_state_machine.timeEvt")

test("Structural test STATE 1->2") # Starts a new test and gives it a name
query_curr(OBJ_SM) # Queries the state machine object in target
expect("@timestamp Query-SM Obj=l_state_machine,State=state_machine_state_1") # reports the data from state machine object query
query_curr(OBJ_AO) # Queries the active object object in target
expect("@timestamp Query-AO Obj=l_state_machine,State=state_machine_state_1")
query_curr(OBJ_TE) # Queries the time event object in target
expect("@timestamp Query-TE Obj=l_state_machine.timeEvt,Rate=0,Sig=TIMEOUT_SIG,*")
current_obj(OBJ_MP,"EvtPool1") 
query_curr(OBJ_MP) # Queries the memory pool object in target 
expect("@timestamp Query-MP Obj=EvtPool1,*")
post("TIMEOUT_SIG") # Posts a given event to the current AO object in target
expect("@timestamp MP-Get   Obj=EvtPool1,*") # a memory block was removed from a memory pool
expect("@timestamp QF-New   Sig=TIMEOUT_SIG,*") # new event creation
expect("@timestamp AO-Post  Sdr=QS_RX,Obj=l_state_machine,Evt<Sig=TIMEOUT_SIG,*") # an event was posted (FIFO) directly to AO
expect("@timestamp AO-GetL  Obj=l_state_machine,Evt<Sig=TIMEOUT_SIG,*") # AO got an event and its queue is empty
expect("@timestamp Disp===> Obj=l_state_machine,Sig=TIMEOUT_SIG,State=state_machine_state_1") # an event was dispatched (begin of RTC step)
expect("@timestamp STATE 2")
expect("===RTC===> St-Entry Obj=l_state_machine,State=state_machine_state_2") # state was entered
expect("@timestamp ===>Tran Obj=l_state_machine,Sig=TIMEOUT_SIG,State=state_machine_state_1->state_machine_state_2") # a regular transition was taken
expect("@timestamp QF-gc    Evt<Sig=TIMEOUT_SIG,*") # garbage collection performed
expect("@timestamp MP-Put   Obj=EvtPool1,*") # a memory block was returned to a memory pool
expect("@timestamp Trg-Done QS_RX_EVENT") # user callback completed

test("Structural test STATE 2->3", NORESET)
query_curr(OBJ_SM)
expect("@timestamp Query-SM Obj=l_state_machine,State=state_machine_state_2")
query_curr(OBJ_AO)
expect("@timestamp Query-AO Obj=l_state_machine,State=state_machine_state_2")
query_curr(OBJ_TE)
expect("@timestamp Query-TE Obj=l_state_machine.timeEvt,Rate=0,Sig=TIMEOUT_SIG,*")
current_obj(OBJ_MP,"EvtPool1")
query_curr(OBJ_MP)
expect("@timestamp Query-MP Obj=EvtPool1,*")
post("TIMEOUT_SIG")
expect("@timestamp MP-Get   Obj=EvtPool1,*")
expect("@timestamp QF-New   Sig=TIMEOUT_SIG,*")
expect("@timestamp AO-Post  Sdr=QS_RX,Obj=l_state_machine,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp AO-GetL  Obj=l_state_machine,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp Disp===> Obj=l_state_machine,Sig=TIMEOUT_SIG,State=state_machine_state_2")
expect("@timestamp STATE 3")
expect("===RTC===> St-Entry Obj=l_state_machine,State=state_machine_state_3")
expect("@timestamp ===>Tran Obj=l_state_machine,Sig=TIMEOUT_SIG,State=state_machine_state_2->state_machine_state_3")
expect("@timestamp QF-gc    Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp MP-Put   Obj=EvtPool1,*")
expect("@timestamp Trg-Done QS_RX_EVENT")

test("Structural test STATE 3->1", NORESET)
query_curr(OBJ_SM)
expect("@timestamp Query-SM Obj=l_state_machine,State=state_machine_state_3")
query_curr(OBJ_AO)
expect("@timestamp Query-AO Obj=l_state_machine,State=state_machine_state_3")
query_curr(OBJ_TE)
expect("@timestamp Query-TE Obj=l_state_machine.timeEvt,Rate=0,Sig=TIMEOUT_SIG,*")
current_obj(OBJ_MP,"EvtPool1")
query_curr(OBJ_MP)
expect("@timestamp Query-MP Obj=EvtPool1,*")
post("TIMEOUT_SIG")
expect("@timestamp MP-Get   Obj=EvtPool1,*")
expect("@timestamp QF-New   Sig=TIMEOUT_SIG,*")
expect("@timestamp AO-Post  Sdr=QS_RX,Obj=l_state_machine,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp AO-GetL  Obj=l_state_machine,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp Disp===> Obj=l_state_machine,Sig=TIMEOUT_SIG,State=state_machine_state_3")
expect("@timestamp STATE 1")
expect("===RTC===> St-Entry Obj=l_state_machine,State=state_machine_state_1")
expect("@timestamp ===>Tran Obj=l_state_machine,Sig=TIMEOUT_SIG,State=state_machine_state_3->state_machine_state_1")
expect("@timestamp QF-gc    Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp MP-Put   Obj=EvtPool1,*")
expect("@timestamp Trg-Done QS_RX_EVENT")

test("Structural test tick() STATE 1->2")
tick()
expect("           Tick<0>  Ctr=*")
expect("@timestamp TE0-Post Obj=l_state_machine.timeEvt,Sig=TIMEOUT_SIG,AO=l_state_machine")
expect("@timestamp AO-Post  Sdr=QS_RX,Obj=l_state_machine,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp AO-GetL  Obj=l_state_machine,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp Disp===> Obj=l_state_machine,Sig=TIMEOUT_SIG,State=state_machine_state_1")
expect("@timestamp STATE 2")
expect("===RTC===> St-Entry Obj=l_state_machine,State=state_machine_state_2")
expect("@timestamp ===>Tran Obj=l_state_machine,Sig=TIMEOUT_SIG,State=state_machine_state_1->state_machine_state_2")
expect("@timestamp Trg-Done QS_RX_TICK")

test("Structural test tick() STATE 2->3", NORESET)
tick()
expect("           Tick<0>  Ctr=*")
expect("@timestamp TE0-Post Obj=l_state_machine.timeEvt,Sig=TIMEOUT_SIG,AO=l_state_machine")
expect("@timestamp AO-Post  Sdr=QS_RX,Obj=l_state_machine,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp AO-GetL  Obj=l_state_machine,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp Disp===> Obj=l_state_machine,Sig=TIMEOUT_SIG,State=state_machine_state_2")
expect("@timestamp STATE 3")
expect("===RTC===> St-Entry Obj=l_state_machine,State=state_machine_state_3")
expect("@timestamp ===>Tran Obj=l_state_machine,Sig=TIMEOUT_SIG,State=state_machine_state_2->state_machine_state_3")
expect("@timestamp Trg-Done QS_RX_TICK")

test("Structural test tick() STATE 3->1", NORESET)
tick()
expect("           Tick<0>  Ctr=*")
expect("@timestamp TE0-Post Obj=l_state_machine.timeEvt,Sig=TIMEOUT_SIG,AO=l_state_machine")
expect("@timestamp AO-Post  Sdr=QS_RX,Obj=l_state_machine,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp AO-GetL  Obj=l_state_machine,Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp Disp===> Obj=l_state_machine,Sig=TIMEOUT_SIG,State=state_machine_state_3")
expect("@timestamp STATE 1")
expect("===RTC===> St-Entry Obj=l_state_machine,State=state_machine_state_1")
expect("@timestamp ===>Tran Obj=l_state_machine,Sig=TIMEOUT_SIG,State=state_machine_state_3->state_machine_state_1")
expect("@timestamp Trg-Done QS_RX_TICK")
