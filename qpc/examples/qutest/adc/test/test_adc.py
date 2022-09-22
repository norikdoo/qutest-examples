# preamble...
def on_setup():
    #This is ran before EACH TEST
    command(0)
    expect("@timestamp ADC ADC_init 0")
    expect("@timestamp Trg-Done QS_RX_COMMAND")

# Tests
test("Read ADC channel 0 for raw value 100")
current_obj(OBJ_AP, "raw_value")
poke(0, 4, pack('<L', 100))
command(1, 0)
expect("@timestamp ADC ADC_read 0 100")
expect("@timestamp Trg-Done QS_RX_COMMAND")


test("Read ADC channel 1 for raw value 200", NORESET)
current_obj(OBJ_AP, "raw_value")
poke(4, 4, pack('<L', 200))
command(1, 1)
expect("@timestamp ADC ADC_read 1 200")
expect("@timestamp Trg-Done QS_RX_COMMAND")

test("Test ASSERT -> ADC channel out-of-range", NORESET)
command(1, 2)
expect("@timestamp =ASSERT= Mod=ADC,Loc=54")

# Target was reset due to ASSERT
test("Read ADC channel 0 after RESET (default value of 255)")
command(1, 0)
expect("@timestamp ADC ADC_read 0 255")
expect("@timestamp Trg-Done QS_RX_COMMAND")

test("Read ADC channel 1 after RESET (default value of 255)", NORESET)
command(1, 1)
expect("@timestamp ADC ADC_read 1 255")
expect("@timestamp Trg-Done QS_RX_COMMAND")
