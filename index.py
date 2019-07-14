from serial import Serial
from flask import Flask
from threading import Thread
from time import sleep

app = Flask(__name__)
data = ''

@app.route('/')
def hello_world():
    arduino = Serial("COM3", 9600)
    data = arduino.readline().decode('utf-8')
    arduino.close()
    return data

# def poll_sensor_status():
#     arduino = None
#     while True:
#         try:
#             arduino = Serial("COM3", 9600)
#         except:
#             arduino.close()
#             arduino = Serial("COM3", 9600)
#         data = arduino.readline().decode('utf-8')
#         arduino.close()
#         print(data)
#         sleep(0.1)

if __name__ == '__main__':
    # thread = Thread(target=poll_sensor_status)
    # thread.start()
    app.run(debug=True)
    # thread.join()