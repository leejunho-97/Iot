//SOSsignal.h

#ifndef SOSsignal_h
#define SOSsignal_h

#include<Arduino.h>

class SOSsignal
{
    public:
        SOSsignal(int pin);
        void dot();
        void dash();
    private:
        int _pin;
        int i;
};

#endif