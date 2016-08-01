#include <TrafficLight.h>

TrafficLight trafficLight(2, 3, 4);

unsigned long _currentMillis = 0;
unsigned long _previousMillis = 0;

const int _greenLightDelay = 3000;
const int _yellowLightDelay = 2000;
const int _redLightDelay = 5000;

bool _isStarting = true;

void setup() {}

void loop()
{
  _currentMillis = millis();
  if (_isStarting == true)
  {
    trafficLight.TurnGreenLightOn();
  }

  if (_currentMillis - _previousMillis >= _greenLightDelay)
  {
    _isStarting = false;
    _previousMillis = _currentMillis;
  }

  if (_currentMillis - _previousMillis >= (_yellowLightDelay + _greenLightDelay))
  {
    trafficLight.TurnYellowLightOn();
    _previousMillis = _currentMillis;
  }

  if (_currentMillis - _previousMillis >= (_redLightDelay + _yellowLightDelay + _greenLightDelay))
  {
    trafficLight.TurnRedLightOn();
    _isStarting  = true;
    _previousMillis = _currentMillis;
  }
}