****Microcontroller Code for Temperature-Based Motor Control**
**
This repository contains a microcontroller code written for an ESP32 that simulates a temperature-based motor control system. The code uses the AccelStepper library to control a stepper motor based on a simulated temperature value. Below is an explanation of the code and the procedure to set it up.

the repository also container server code developed using FastAPI in python and also can be run as a docker container with Dockerfile & docker-compose.yml

**Code Overview**
The code simulates a temperature sensor and controls a stepper motor based on the temperature value. The motor rotates clockwise, counter-clockwise, or stops depending on the simulated temperature range.

**Key Features:**
Web App: Consists of input field where user gives the input for temperature in degree celsius

**Motor Control:**
If the temperature is below 85°C, the motor rotates clockwise.

If the temperature is between 85°C and 105°C, the motor rotates counter-clockwise.

If the temperature exceeds 105°C, the motor stops.

**Hardware connections**
![WhatsApp Image 2025-03-17 at 10 57 50 PM](https://github.com/user-attachments/assets/81788352-3fa4-4c95-97c2-1088fd428071)


The Motor with driver is connected to the ESP 32 to the pin GPIO 18, GPIO19, GPIO 21, and GPIO 22 and the data is temperature data is simulated.

**Please note:** You can also connect the DHT sensor to naturally collect the data 


**Output from Web based server 
**![Screenshot from 2025-03-17 22-55-22](https://github.com/user-attachments/assets/b6226332-3f9c-456d-8eb6-9a453520451b)




**Hardware connection with actual DHT Sensor 
**![IMG_20250317_150034 (1)](https://github.com/user-attachments/assets/8ec006bc-73a6-404d-9680-50bafce658d3)
