#ifndef TrafficLight_h
#define TrafficLight_h
#include "Arduino.h"

class TrafficLight{
    public:
        TrafficLight(int, int, int);
        void TurnRedLightOn();
        void TurnYellowLightOn();
        void TurnGreenLightOn();
        void ShutDown();

    private:
        int _greenLightPin;
        int _yellowLightPin;
        int _redLightPin;
};

#endif