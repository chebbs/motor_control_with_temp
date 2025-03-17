**ESP32-Based Temperature-Controlled Motor System**

This repository contains code for an ESP32 that controls a stepper motor based on temperature input. The system can use either simulated temperature values or real data from a DHT sensor. A FastAPI web server allows users to manually enter temperature values, and the entire setup can be containerized using Docker.

******How It Works**
****
Users enter a temperature via a web interface.
The ESP32 receives the temperature value and controls the motor as follows:
Below 85°C: Motor rotates clockwise ⏩
85°C – 105°C: Motor rotates counterclockwise ⏪
Above 105°C: Motor stops 🛑

**Web Interface:**

![image](https://github.com/user-attachments/assets/fe2209f6-5285-45cd-8aa6-0631b2bdd0c6)


****Hardware Setup**
**
The stepper motor is connected to the ESP32 as follows:

ESP32 Pin	Motor Driver

GPIO 18	IN1;

GPIO 19	IN2;

GPIO 21	IN3;

GPIO 22	IN4;

**Hardware Setup:**

![image](https://github.com/user-attachments/assets/a6207c3f-392f-4051-bc4c-024d451ee05f)


Optional: Connect a DHT sensor for real temperature input instead of simulated data or manual user entry data.

**DHT Sensor Setup:**

![Screenshot from 2025-03-17 23-11-42](https://github.com/user-attachments/assets/e4469bde-c518-4ca1-b281-0471945045d0)



