import smbus

bus = smbus.SMBus(1)
address = 0x04

def writeNumber(value):
	bus.write_byte(address, value)
	
for i in range(0, len(barcode)):
	number=ord(barcode[i])
	writeNumber(number)
	time.sleep(0.025)
writeNumber(10) #LF