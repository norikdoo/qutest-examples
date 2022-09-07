# test-script for QUTest unit testing harness
# see https://www.state-machine.com/qtools/qutest.html/qutest.html

# preamble...
def on_reset():
    expect_pause()
    continue_test()
    expect_run()
    glb_filter(GRP_ALL)
    loc_filter(IDS_ALL)
    current_obj(OBJ_SM, "Philo::inst[2]")
    current_obj(OBJ_TE, "Philo::inst[2].m_timeEvt")

# tests...
test("Philo-thinking TIMEOUT")
dispatch("TIMEOUT_SIG")
expect("@timestamp MP-Get   Obj=EvtPool1,*")
expect("@timestamp QF-New   Sig=TIMEOUT_SIG,*")
expect("@timestamp Disp===> Obj=Philo::inst[2],Sig=TIMEOUT_SIG,State=Philo::thinking")
expect("@timestamp TE0-Dis  Obj=Philo::inst[2].m_timeEvt,AO=Table::inst,Tim=*,Int=0")
expect("===RTC===> St-Exit  Obj=Philo::inst[2],State=Philo::thinking")
expect("@timestamp MP-Get   Obj=EvtPool1,*")
expect("@timestamp QF-New   Sig=HUNGRY_SIG,*")
expect("@timestamp AO-LIFO  Obj=Table::inst,Evt<Sig=HUNGRY_SIG,*")
expect("@timestamp QUTEST_ON_POST HUNGRY_SIG,Obj=Table::inst 2")
expect("@timestamp QF-gc    Evt<Sig=HUNGRY_SIG,*")
expect("@timestamp MP-Put   Obj=EvtPool1,*")
expect("===RTC===> St-Entry Obj=Philo::inst[2],State=Philo::hungry")
expect("@timestamp ===>Tran Obj=Philo::inst[2],Sig=TIMEOUT_SIG,State=Philo::thinking->Philo::hungry")
expect("@timestamp QF-gc    Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp MP-Put   Obj=EvtPool1,*")
expect("@timestamp Trg-Done QS_RX_EVENT")

test("Philo-hungry EAT", NORESET)
dispatch("EAT_SIG", pack("<B", 2))
expect("@timestamp MP-Get   Obj=EvtPool1,*")
expect("@timestamp QF-New   Sig=EAT_SIG,*")
expect("@timestamp Disp===> Obj=Philo::inst[2],Sig=EAT_SIG,State=Philo::hungry")
expect("@timestamp BSP_CALL BSP::random *")
expect("@timestamp TE0-Arm  Obj=Philo::inst[2].m_timeEvt,AO=Table::inst,Tim=*,Int=0")
expect("===RTC===> St-Entry Obj=Philo::inst[2],State=Philo::eating")
expect("@timestamp ===>Tran Obj=Philo::inst[2],Sig=EAT_SIG,State=Philo::hungry->Philo::eating")
expect("@timestamp QF-gc    Evt<Sig=EAT_SIG,*")
expect("@timestamp MP-Put   Obj=EvtPool1,*")
expect("@timestamp Trg-Done QS_RX_EVENT")

test("Philo-eating TIMEOUT", NORESET)
dispatch("TIMEOUT_SIG")
expect("@timestamp MP-Get   Obj=EvtPool1,*")
expect("@timestamp QF-New   Sig=TIMEOUT_SIG,*")
expect("@timestamp Disp===> Obj=Philo::inst[2],Sig=TIMEOUT_SIG,State=Philo::eating")
expect("@timestamp TE0-Dis  Obj=Philo::inst[2].m_timeEvt,AO=Table::inst,Tim=*,Int=0")
expect("@timestamp MP-Get   Obj=EvtPool1,*")
expect("@timestamp QF-New   Sig=DONE_SIG,*")
expect("@timestamp AO-LIFO  Obj=Table::inst,Evt<Sig=DONE_SIG,*")
expect("@timestamp QUTEST_ON_POST DONE_SIG,Obj=Table::inst 2")
expect("@timestamp QF-gc    Evt<Sig=DONE_SIG,*")
expect("@timestamp MP-Put   Obj=EvtPool1,*")
expect("===RTC===> St-Exit  Obj=Philo::inst[2],State=Philo::eating")
expect("@timestamp BSP_CALL BSP::random *")
expect("@timestamp TE0-Arm  Obj=Philo::inst[2].m_timeEvt,AO=Table::inst,Tim=*,Int=0")
expect("===RTC===> St-Entry Obj=Philo::inst[2],State=Philo::thinking")
expect("@timestamp ===>Tran Obj=Philo::inst[2],Sig=TIMEOUT_SIG,State=Philo::eating->Philo::thinking")
expect("@timestamp QF-gc    Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp MP-Put   Obj=EvtPool1,*")
expect("@timestamp Trg-Done QS_RX_EVENT")

test("Philo-thinking TIMEOUT(2)", NORESET)
dispatch("TIMEOUT_SIG")
expect("@timestamp MP-Get   Obj=EvtPool1,*")
expect("@timestamp QF-New   Sig=TIMEOUT_SIG,*")
expect("@timestamp Disp===> Obj=Philo::inst[2],Sig=TIMEOUT_SIG,State=Philo::thinking")
expect("@timestamp TE0-Dis  Obj=Philo::inst[2].m_timeEvt,AO=Table::inst,Tim=*,Int=0")
expect("===RTC===> St-Exit  Obj=Philo::inst[2],State=Philo::thinking")
expect("@timestamp MP-Get   Obj=EvtPool1,*")
expect("@timestamp QF-New   Sig=HUNGRY_SIG,*")
expect("@timestamp AO-LIFO  Obj=Table::inst,Evt<Sig=HUNGRY_SIG,*")
expect("@timestamp QUTEST_ON_POST HUNGRY_SIG,Obj=Table::inst 2")
expect("@timestamp QF-gc    Evt<Sig=HUNGRY_SIG,*")
expect("@timestamp MP-Put   Obj=EvtPool1,*")
expect("===RTC===> St-Entry Obj=Philo::inst[2],State=Philo::hungry")
expect("@timestamp ===>Tran Obj=Philo::inst[2],Sig=TIMEOUT_SIG,State=Philo::thinking->Philo::hungry")
expect("@timestamp QF-gc    Evt<Sig=TIMEOUT_SIG,*")
expect("@timestamp MP-Put   Obj=EvtPool1,*")
expect("@timestamp Trg-Done QS_RX_EVENT")
