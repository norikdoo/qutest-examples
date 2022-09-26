def on_reset():
    expect_pause() # Expects QS_TEST_PAUSE() inside test fixture
    glb_filter(GRP_UA) # Sends QS Global Filter to target - user records only
    continue_test() # Continues the test after QS_TEST_PAUSE()
    expect("@timestamp STATE 1") # Expected QSpy output
    expect_run() # Expects QF_run() function inside test fixture
    current_obj(OBJ_SM_AO,"l_state_machine") # Sets current object in target
    current_obj(OBJ_TE,"l_state_machine.timeEvt")

test("Functional test STATE all") # Starts a new test and gives it a name
post("TIMEOUT_SIG") # Posts TIMEOUT_SIG event to the current AO object in target
expect("@timestamp STATE 2")
expect("@timestamp Trg-Done QS_RX_EVENT") # user callback completed
post("TIMEOUT_SIG")
expect("@timestamp STATE 3")
expect("@timestamp Trg-Done QS_RX_EVENT")
post("TIMEOUT_SIG")
expect("@timestamp STATE 1")
expect("@timestamp Trg-Done QS_RX_EVENT")
#if(expect("@timestamp Trg-Done QS_RX_EVENT")):
#    skip(3) # skips 3 tests

test("Functional test STATE 1->2")
post("TIMEOUT_SIG")
expect("@timestamp STATE 2")
expect("@timestamp Trg-Done QS_RX_EVENT")

test("Functional test STATE 2->3", NORESET)
post("TIMEOUT_SIG")
expect("@timestamp STATE 3")
expect("@timestamp Trg-Done QS_RX_EVENT")

test("Functional test STATE 3->1", NORESET)
post("TIMEOUT_SIG")
expect("@timestamp STATE 1")
expect("@timestamp Trg-Done QS_RX_EVENT")

test("Functional test tick() STATE 1->2")
tick()
expect("@timestamp STATE 2")
expect("@timestamp Trg-Done QS_RX_TICK")

test("Functional test tick() STATE 2->3", NORESET)
tick()
expect("@timestamp STATE 3")
if(expect("@timestamp Trg-Done QS_RX_TICK")):
    skip() # skips the rest of the tests in this group

test("Functional test tick() STATE 3->1", NORESET)
tick()
expect("@timestamp STATE 1")
expect("@timestamp Trg-Done QS_RX_TICK")
