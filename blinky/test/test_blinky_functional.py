def on_reset():
    expect_pause()
    glb_filter(GRP_UA)
    continue_test()
    expect("@timestamp LED 0")
    expect_run()
    current_obj(OBJ_SM_AO,"l_blinky")
    current_obj(OBJ_TE,"l_blinky.timeEvt")

# State LED OFF -> ON by posting TIMEOUT_SIG
test("post TIMEOUT_SIG LED 0 -> LED 1")
post("TIMEOUT_SIG")
expect("@timestamp LED 1")
expect("@timestamp Trg-Done QS_RX_EVENT")

# State LED ON -> OFF by posting TIMEOUT_SIG
test("post TIMEOUT_SIG LED 1 -> LED 0", NORESET)
post("TIMEOUT_SIG")
expect("@timestamp LED 0")
expect("@timestamp Trg-Done QS_RX_EVENT")

# Test states transtions with tick()
test("tick()")
tick()
expect("@timestamp LED 1")
expect("@timestamp Trg-Done QS_RX_TICK")
tick()
expect("@timestamp LED 0")
expect("@timestamp Trg-Done QS_RX_TICK")
