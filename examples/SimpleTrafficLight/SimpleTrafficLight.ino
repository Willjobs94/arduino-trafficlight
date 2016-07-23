#include <TrafficLight.h>

TrafficLight trafficLight(2, 3, 4);

void setup() {}

void loop()
{
    trafficLight.TurnGreenLightOn();
    delay(500);
    trafficLight.TurnYellowLightOn();
    delay(500);
    trafficLight.TurnRedLightOn();
    delay(500);
}