#include <StringList.h>
#include <EventCollector.h>
#include <MainHandler.h>
#include <Container.h>
#include <Sensor.h>

// Container dimensions:
// MIN_CONTAINER_HEIGHT <- Lowest point seen from Sensor
// MAX_CONTAINER_HEIGHT <- Highest point seen from Sensor
int MIN_CONTAINER_HEIGHT = 100, MAX_CONTAINER_HEIGHT = 20; 

// Percentage values for min and max level
// used to start/stop filling the container
int MIN_CONTAINER_THRESHOLD = 10, MAX_CONTAINER_THRESHOLD = 90;

// Pin used by the ultrasonic sensor
int PIN_SENSOR_TRIG = 4, PIN_SENSOR_ECHO = 5;

// Pin used by the motor
int PIN_MOTOR = 3;

EventCollector eventCollector = EventCollector();
Container container = Container(MIN_CONTAINER_HEIGHT, MAX_CONTAINER_HEIGHT, MIN_CONTAINER_THRESHOLD, MAX_CONTAINER_THRESHOLD);
Sensor sensor = Sensor(PIN_SENSOR_TRIG, PIN_SENSOR_ECHO);
MainHandler lu = MainHandler(&container, &sensor, &eventCollector);
void setup() {
  Serial.begin(57600);
}

void loop() {
  // Run MainHandler routine and stop at errors
  lu.compute();
  Serial.println(lu.containerFillingPercentage);
  if(eventCollector.hasErrors() == 'e'){
    Serial.println(eventCollector.getLast());
    delay(10000);
  }
  eventCollector.reset();
  delay(2000);
}
