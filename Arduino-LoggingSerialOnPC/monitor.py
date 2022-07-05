# The `serial` library might need to be installed. This can
# be done with `pip install serial`.

import serial, time, datetime

COM = "COM1"
BAUD = 9600

ser = serial.Serial(COM, BAUD, timeout=0.1)
time.sleep(3)       # wait until the Arduino has started

while True:
    val = str(ser.readline().decode().strip())
    if val:
        now = datetime.datetime.now().isoformat()
        print(f"[{now}] {val}", flush=True)

