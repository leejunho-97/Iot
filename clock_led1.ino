//41615064 이준호
#include <ESP8266WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>

// Replace with your network credentials
const char *ssid     = "-";                               
const char *password = "-";                             
#define LED D5
// Define NTP Client to get time
WiFiUDP udp;
NTPClient timeClient(udp, "kr.pool.ntp.org");//32400

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  
  // Connect to Wi-Fi
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

// Initialize a NTPClient to get time
  timeClient.begin();
  timeClient.setTimeOffset(32400);//kr
}

void loop() {
  static unsigned long loopCnt = 0;
  static unsigned long nextMil = millis() + 1000;
  
  if(millis() > nextMil){
    nextMil = millis() + 1000;
    loopCnt++;
    
    timeClient.update(); 
    unsigned long epochTime = timeClient.getEpochTime();
    struct tm *ptm = gmtime ((time_t *)&epochTime);

    int CD = ptm->tm_mday;
    int CM = ptm->tm_mon+1;
    int CY = ptm->tm_year+1900;
  
    int HH = ptm->tm_hour;
    int MM = ptm->tm_min;
    int SS = ptm->tm_sec;
    Serial.println(loopCnt);
    Serial.printf("%04d:%02d.%02d\n",CY,CM,CD);
    Serial.printf("%02d:%02d.%02d\n",HH,MM,SS);
         
  }
  delay(1);
  digitalWrite(LED, HIGH);
  delay(500);
  digitalWrite(LED, LOW);
  delay(500);
  }
