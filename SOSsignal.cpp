//SOSsignal.cpp

#include<Arduino.h>
#include<SOSsignal.h>

SOSsignal::SOSsignal(int pin)
{
    _pin=pin;
    pinMode(_pin,OUTPUT);
}
void SOSsignal::dot()
{
    for(i=0;i<3;i++){
    digitalWrite(_pin,HIGH);
    delay(250);
    digitalWrite(_pin,LOW);
    delay(250);
    }
}
void SOSsignal::dash()
{   
    for(i=0;i<3;i++){
    digitalWrite(_pin,HIGH);
    delay(1000);
    digitalWrite(_pin,LOW);
    delay(250);
    }
}