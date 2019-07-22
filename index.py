from serial import Serial
from flask import Flask, render_template, request
import atexit
from time import sleep

app = Flask(__name__)


@app.route('/', methods=['POST', 'GET'])
def index():
    if request.method == 'POST':
        # if we press the turn on button
        if request.form['submit'] == 'Turn On':
            arduino.write(b"led_on")
            response = arduino.readline().decode('utf-8')
            print(response)

        # if we press the turn off button
        elif request.form['submit'] == 'Turn Off':
            arduino.write(b"led_off")
            response = arduino.readline().decode('utf-8')
            print(response)

    arduino.write(b"get")
    data = arduino.readline().decode('utf-8')
    return render_template("home.html", sensor_value=data)


@app.before_first_request
def openArduinoConnection():
    print("Opening Arduino Connection!")
    global arduino
    arduino = Serial(
        port="COM3",
        baudrate=9600,
        timeout=1
    )
    sleep(3)


@atexit.register
def closeArduinoConnection():
    if arduino and arduino.isOpen():
        print("Closing Arduino Connection!")
        arduino.close()


if __name__ == '__main__':
    app.run(debug=True)
