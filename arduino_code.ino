#include <AccelStepper.h>

#define IN1 18
#define IN2 19
#define IN3 21
#define IN4 22

AccelStepper stepper(AccelStepper::HALF4WIRE, IN1, IN3, IN2, IN4);

float manualTemperature = 80.0;  
unsigned long lastMotorUpdate = 0;

void setup() {
    Serial.begin(115200);
    stepper.setMaxSpeed(1000);
    stepper.setAcceleration(100);
}

void loop() {
    unsigned long currentTime = millis();

    
    if (Serial.available() > 0) {                           // API check
        String inputString = Serial.readStringUntil('\n');  // Read input until newline
        inputString.trim();  

        if (inputString.length() > 0) {
            manualTemperature = inputString.toFloat();  // float coversion

            Serial.print("Received Temperature: ");
            Serial.println(manualTemperature);
        }
    }

    // Update motor behavior every 100ms
    if (currentTime - lastMotorUpdate >= 100) {
        lastMotorUpdate = currentTime;

        Serial.print("Current Temperature: ");
        Serial.println(manualTemperature);

        if (manualTemperature < 85.0) {
            rotateMotor(1000);  // Rotate clockwise (RIGHT)
        } else if (manualTemperature < 105.0) {
            rotateMotor(-1000); // Rotate counter-clockwise (LEFT)
        } else {
            stopMotor();        // Stop motor
        }
    }
}

void rotateMotor(int speed) {
    stepper.setSpeed(speed);
    stepper.runSpeed();
    Serial.print("Motor rotating ");
    Serial.println(speed > 0 ? "RIGHT (Clockwise)" : "LEFT (Counter-clockwise)");
}

void stopMotor() {
    stepper.setSpeed(0);
    Serial.println("Motor STOPPED");
}
