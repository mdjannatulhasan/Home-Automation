#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#define WIFI_SSID "Connecting"
#define WIFI_PASS "moon0179"

#define MQTT_SERV "io.adafruit.com"
#define MQTT_PORT 1883
#define MQTT_NAME "mahfuj15"
#define MQTT_PASS "aio_kMkc12idkr4hXRR4CSeTn1BcDClK"

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, MQTT_SERV, MQTT_PORT, MQTT_NAME, MQTT_PASS);

Adafruit_MQTT_Subscribe onoff = Adafruit_MQTT_Subscribe(&mqtt, MQTT_NAME "/f/onoff");





int LED = D4;
int timer = 0;
char data_received;
void setup() {
       pinMode(LED, OUTPUT);
       Serial.begin(9600);
       Serial.begin(9600);

  //Connect to WiFi
  Serial.print("\n\nConnecting Wifi... ");
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
  }

  Serial.println("OK!");

  //Subscribe to the onoff feed
  mqtt.subscribe(&onoff);
}
int value = 0;
void loop() {
  if (Serial.available())  /* If data is available on serial port */
    {
      data_received = Serial.read();  /* Data received from bluetooth */
      Serial.print("Data Received: ");
      Serial.println(data_received);
        if (data_received == 'a')
        {
         pumpOn();
         Serial.println("Pump turned ON\n"); 
        }
         
         else if (data_received == 'b')
        {
         pumpOff();
         Serial.println("Pump turned OFF\n");
        }
        else if (data_received == 'c')
        {
         pumpOn5Min();
        }else if (data_received == 'd')
        {
         pumpOn10Min();
        }
        else if (data_received == 'e')
        {
          pumpOn13Min();
        }
        else if (data_received == 'f')
        {
          pumpOn15Min();
        }
        else if (data_received == 'g')
        {
          pumpOn18Min();
        }
        else if (data_received == 'h')
        {
          pumpOn20Min();
        }
        else if (data_received == 'i')
        {
          pumpOn21Min();
        }
        else if (data_received == 'j')
        {
          pumpOn23Min();
        }
        else if (data_received == 't')
        {
         digitalWrite(LED, HIGH);
         Serial.println("Pump turned ON\n"); 
         delay(30000);
         digitalWrite(LED, LOW);
         Serial.println("Pump turned OFF\n");
         data_received = 'z';
        }
    }
//Connect/Reconnect to MQTT
  MQTT_connect();

  //Read from our subscription queue until we run out, or
  //wait up to 5 seconds for subscription to update
  Adafruit_MQTT_Subscribe * subscription;
    while ((subscription = mqtt.readSubscription(5000)))
    {
      //If we're in here, a subscription updated...
      if (subscription == &onoff)
      {
        //Print the new value to the serial monitor
        Serial.print("onoff: ");
        Serial.println((char*) onoff.lastread);
  
        //If the new value is  "ON", turn the light on.
        //Otherwise, turn it off.
        if (!strcmp((char*) onoff.lastread, "ON"))
        {
          //active low logic
          pumpOn();
        }
        else if (!strcmp((char*) onoff.lastread, "OFF"))
        {
          pumpOff();
        }
        else if (!strcmp((char*) onoff.lastread, "ONTest"))
        {
          pumpOnTest();
        }
      }
  }
  if (!mqtt.ping())
  {
    mqtt.disconnect();
  }
  
}
void MQTT_connect() 
{
  int8_t ret;
  // Stop if already connected
  if (mqtt.connected())
  {
    return;
  }

  Serial.print("Connecting to MQTT... ");
  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) // connect will return 0 for connected
  { 
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000);  // wait 5 seconds
    retries--;
    if (retries == 0) 
    {
      // basically die and wait for WDT to reset me
      while (1);
    }
  }
  Serial.println("MQTT Connected!");
}
void pumpOn(){
  digitalWrite(LED, HIGH);
  }
void pumpOff(){
  digitalWrite(LED, LOW);
}
void pumpOn5Min(){
  digitalWrite(LED, HIGH);
  Serial.println("Pump turned ON for 5 min\n"); 
  delay(300000);
  digitalWrite(LED, LOW);
  Serial.println("Pump turned OFF\n");
  data_received = 'z';
}
void pumpOn10Min(){
  digitalWrite(LED, HIGH);
  Serial.println("Pump turned ON\n"); 
  delay(600000);
  digitalWrite(LED, LOW);
  Serial.println("Pump turned OFF\n");
  data_received = 'z';
}
void pumpOn13Min(){
  digitalWrite(LED, HIGH);
  Serial.println("Pump turned ON\n"); 
  delay(780000);
  digitalWrite(LED, LOW);
  Serial.println("Pump turned OFF\n");
  data_received = 'z';
}
void pumpOn15Min(){
  digitalWrite(LED, HIGH);
  Serial.println("Pump turned ON\n"); 
  delay(900000);
  digitalWrite(LED, LOW);
  Serial.println("Pump turned OFF\n");
  data_received = 'z';
}
void pumpOn18Min(){
  digitalWrite(LED, HIGH);
  Serial.println("Pump turned ON\n"); 
  delay(1080000);
  digitalWrite(LED, LOW);
  Serial.println("Pump turned OFF\n");
  data_received = 'z';
}
void pumpOn20Min(){
  digitalWrite(LED, HIGH);
  Serial.println("Pump turned ON\n"); 
  delay(1200000);
  digitalWrite(LED, LOW);
  Serial.println("Pump turned OFF\n");
  data_received = 'z';
}
void pumpOn21Min(){
  digitalWrite(LED, HIGH);
  Serial.println("Pump turned ON\n"); 
  delay(1260000);
  digitalWrite(LED, LOW);
  Serial.println("Pump turned OFF\n");
  data_received = 'z';
}
void pumpOn23Min(){
  digitalWrite(LED, HIGH);
  Serial.println("Pump turned ON\n"); 
  delay(1380000);
  digitalWrite(LED, LOW);
  Serial.println("Pump turned OFF\n");
  data_received = 'z';
}
void pumpOnTest(){
  digitalWrite(LED, HIGH);
  Serial.println("Pump turned ON\n"); 
  delay(10000);
  digitalWrite(LED, LOW);
  Serial.println("Pump turned OFF\n");
  data_received = 'z';
}
