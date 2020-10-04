//A반 41615064 이준호
#include <SOSsignal.h>

SOSsignal SOSsignal(7);

void setup()
{
}

void loop()
{
   SOSsignal.dot();
    SOSsignal.dash();
    SOSsignal.dot();
    delay(3000);
}
