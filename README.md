**Microcontroller Code for Temperature-Based Motor Control**

This repository contains a microcontroller code written for an ESP32 that simulates a temperature-based motor control system. The code uses the AccelStepper library to control a stepper motor based on a simulated temperature value. Below is an explanation of the code and the procedure to set it up.

**Code Overview**
The code simulates a temperature sensor and controls a stepper motor based on the temperature value. The motor rotates clockwise, counter-clockwise, or stops depending on the simulated temperature range.

**Key Features:**
Simulated Temperature: The temperature starts at 83°C and increases by 5°C every 2 minutes.

**Motor Control:**
If the temperature is below 85°C, the motor rotates clockwise.

If the temperature is between 85°C and 105°C, the motor rotates counter-clockwise.

If the temperature exceeds 105°C, the motor stops.

**Hardware connections**
![IMG_20250317_150034 (1)](https://github.com/user-attachments/assets/8ec006bc-73a6-404d-9680-50bafce658d3)

The Motor with driver is connected to the ESP 32 to the pin GPIO 18, GPIO19, GPIO 21, and GPIO 22 and the data is temperature data is simulated.

**Please note:** You can also connect the DHT sensor to naturally collect the data 
