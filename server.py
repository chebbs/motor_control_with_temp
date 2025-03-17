from fastapi import FastAPI, Form
from fastapi.responses import HTMLResponse
import serial
import time

app = FastAPI()

# Define Serial Port
SERIAL_PORT = "/dev/ttyUSB0"  # Update if different
BAUD_RATE = 115200

# Try to open serial connection
try:
    ser = serial.Serial(SERIAL_PORT, BAUD_RATE, timeout=1)
    time.sleep(2)  # Wait for Arduino to initialize
    print(f"Connected to {SERIAL_PORT} successfully!")
except serial.SerialException:
    ser = None
    print(f"Error: Could not open serial port {SERIAL_PORT}")

# Webpage for manual temperature entry
html_content = """
<!DOCTYPE html>
<html>
<head>
    <title>Temperature Control</title>
</head>
<body>
    <h2>Enter Temperature</h2>
    <form action="/set_temperature" method="post">
        <label for="temperature">Temperature (°C):</label>
        <input type="number" step="0.1" id="temperature" name="temperature" required>
        <button type="submit">Send</button>
    </form>
</body>
</html>
"""

@app.get("/", response_class=HTMLResponse)
async def homepage():
    return html_content

@app.post("/set_temperature")
async def set_temperature(temperature: float = Form(...)):
    """ Sends temperature value to Arduino via Serial """
    if ser and ser.is_open:
        message = f"{temperature:.2f}\n"
        ser.write(message.encode('utf-8'))
        ser.flush()
        return f"Temperature {temperature}°C sent to Arduino!"
    else:
        return "Error: Serial port not available!"

