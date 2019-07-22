
from serial import Serial

arduino = Serial(
    port="COM3",
    baudrate=9600,
    timeout=1
)

while True:
    # Write to serial and check what the arduino returns.
    data = arduino.readline().decode('utf-8')
    print(repr(data))
