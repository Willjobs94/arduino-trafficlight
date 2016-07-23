#include "Arduino.h"
#include "TrafficLight.h"

TrafficLight::TrafficLight(int greenLightPin, int yellowLightPin, int redLightPin) {
    pinMode(greenLightPin, OUTPUT);
    pinMode(yellowLightPin, OUTPUT);
    pinMode(redLightPin, OUTPUT);
    _greenLightPin = greenLightPin;
    _yellowLightPin = yellowLightPin;
    _redLightPin = redLightPin;
}

void TrafficLight::TurnRedLightOn() {
    digitalWrite(_yellowLightPin, LOW);
    digitalWrite(_redLightPin, HIGH);
    digitalWrite(_greenLightPin, LOW);
}

void TrafficLight::TurnYellowLightOn() {
    digitalWrite(_redLightPin, LOW);
    digitalWrite(_yellowLightPin, HIGH);
    digitalWrite(_greenLightPin, LOW);
}

void TrafficLight::TurnGreenLightOn() {
    digitalWrite(_redLightPin, LOW);
    digitalWrite(_greenLightPin, HIGH);
    digitalWrite(_yellowLightPin, LOW);
}

void TrafficLight::ShutDown() {
    digitalWrite(_redLightPin, LOW);
    digitalWrite(_greenLightPin, LOW);
    digitalWrite(_yellowLightPin, LOW);
}