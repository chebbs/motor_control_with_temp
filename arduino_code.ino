#include <AccelStepper.h>

#define IN1 18
#define IN2 19
#define IN3 21
#define IN4 22

AccelStepper stepper(AccelStepper::HALF4WIRE, IN1, IN3, IN2, IN4);

float simulatedTemperature = 83.0;   
unsigned long lastMotorUpdate = 0;   
unsigned long lastTempUpdate = 0;    

void setup() {
    Serial.begin(115200);
    stepper.setMaxSpeed(1000);  
    stepper.setAcceleration(100); 
}

void loop() {
    unsigned long currentTime = millis();

    if (currentTime - lastTempUpdate >= 120000) {                   // Increment temperature by 5°C every 2 minutes (120,000 ms)
        lastTempUpdate = currentTime;
        simulatedTemperature += 5.0;

        if (simulatedTemperature > 110.0) {                         // Reset temperature to 80°C if it exceeds 110°C
            simulatedTemperature = 80.0;
        }

        Serial.print("Temperature increased: ");
        Serial.println(simulatedTemperature);
    }

    if (currentTime - lastMotorUpdate >= 100) {                     // Update motor behavior every 100ms
        lastMotorUpdate = currentTime;

        Serial.print("Simulated Temperature: ");
        Serial.println(simulatedTemperature);

        if (simulatedTemperature < 85.0) {
            rotateMotor(1000);                                      // Rotate clockwise(+1000)
        } else if (simulatedTemperature < 105.0) {
            rotateMotor(-1000);                                     // Rotate counter-clockwise (-1000)
        } else {
            stopMotor();                                            // Stop motor
        }
    }
}

void rotateMotor(int speed) {
    stepper.setSpeed(speed);
    stepper.runSpeed();
    Serial.print("Motor rotating ");
    Serial.println(speed > 0 ? "RIGHT (Clockwise)" : "LEFT (Counter)");
}

void stopMotor() {
    stepper.setSpeed(0);
    Serial.println("Motor STOPPED");
}
