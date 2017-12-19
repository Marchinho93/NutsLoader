#include <LogicUnit.h>
#include <Container.h>
#include <Sensor.h>

// Container dimensions:
// minHeight <- Lowest point seen from Sensor
// maxHeight <- Highest point seen from Sensor
int minHeight = 100, maxHeight = 20; 

// Percentage values for min and max level
// used to start/stop filling the container
int minThreshold = 10, maxThreshold = 90;

// Pin used by the ultrasonic sensor
int pinTrig = 4, pinEcho = 5;

// Pin used by the motor
int pinMotor = 3;


Container container = Container(minHeight, maxHeight, minThreshold, maxThreshold);
Sensor sensor = Sensor(pinTrig, pinEcho);
LogicUnit lu = LogicUnit(&container, &sensor);
void setup() {
  Serial.begin(1200);
}

void loop() {
  // Run LogicUnit routine and stop at errors
  int error = lu.compute();
  if(error == -1)
    exit(0);
  Serial.println(lu.containerFillingPercentage);
}
