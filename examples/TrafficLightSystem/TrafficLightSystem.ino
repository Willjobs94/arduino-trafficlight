#include <TrafficLight.h>

TrafficLight _frontLight(2, 3, 4);
TrafficLight _backLight(5, 6, 7);
TrafficLight _leftLight(8, 9, 10);
TrafficLight _rightLight(11, 12, 13);

TrafficLight _trafficLightArray[4] = {
  _frontLight,
  _backLight,
  _leftLight,
  _rightLight
};

unsigned long _currentMillis = 0;
unsigned long _previousMillis = 0;

long inputCode = 0;

bool _isStarting = true;

const int _greenLightDelay = 3000;
const int _yellowLightDelay = 2000;
const int _redLightDelay = 5000;

void setup()
{
  Serial.begin(9600);

}

void loop()
{
  if (Serial.available() > 0)
  {
    long inptutCode = Serial.parseInt();
    int stage = (int) inputCode; // convert long to int
    if (IsValidInput(stage)) { // validate if intput is equal or higher than 0 and equal or less than four
      DoLightSequenceFromStage(stage); // do light sequence from the
    }
  }
  else
  {
    DoLightSequence();
  }
}

bool IsValidInput(int input)
{
  return ((input >= 0) && (input <= 4));
}
void DoLightSequence()
{
  for (int i = 0; i < 4; i++) {
    DoLightCycle(_trafficLightArray[i]);
  }
}

// we use millis because we have to avoid the use of delays in production code
void DoLightCycle(TrafficLight trafficLight)
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

void DoLightSequenceFromStage(int stage)
{
  for (int i = stage; i < 4; i++)
  {
    DoLightCycle(_trafficLightArray[i]);
  }
}

void ShutDownAllLight()
{
  for (int i = 0; i < 4; i++)
  {
    ShutDownLight(_trafficLightArray[i]);
  }
}

void ShutDownLight(TrafficLight trafficLight)
{
  trafficLight.ShutDown();
}
