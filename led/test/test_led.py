test("LED OFF")
command(0,0)
expect("@timestamp LED Led_off")
expect("@timestamp USER+000 setLed 0")
expect("@timestamp Trg-Done QS_RX_COMMAND") # command was executed, all outputs have been produced

test("LED ON")
command(0,1)
expect("@timestamp LED Led_on")
expect("@timestamp USER+000 setLed 1")
expect("@timestamp Trg-Done QS_RX_COMMAND")
