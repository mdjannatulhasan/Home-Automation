
int LED = D4;
int timer = 0;
char data_received;
void setup() {
       pinMode(LED, OUTPUT);
       Serial.begin(9600);
}
void loop() {
      if (Serial.available())  /* If data is available on serial port */
    {
      data_received = Serial.read();  /* Data received from bluetooth */
      if (data_received == 'a')
      {
       digitalWrite(LED, HIGH);
       Serial.println("Pump turned ON\n"); 
      }
//      else if (data_received == 's')
//      {
//      Serial.println("Enter Minute");
//       
//       delay(1000);
//       Serial.println("timer value = "+ timer2);
//       timer = timer2;
//       timer = timer * 1000 * 60;
//       delay(timer);
//       Serial.println("Leaving..........");
//       }
       
       else if (data_received == 'b')
      {
       digitalWrite(LED, LOW);
       Serial.println("Pump turned OFF\n");
      }
      else if (data_received == 'c')
      {
       digitalWrite(LED, HIGH);
       Serial.println("Pump turned ON\n"); 
       delay(300000);
       digitalWrite(LED, LOW);
       Serial.println("Pump turned OFF\n");data_received = 'z';
      }else if (data_received == 'd')
      {
       digitalWrite(LED, HIGH);
       Serial.println("Pump turned ON\n"); 
       delay(600000);
       digitalWrite(LED, LOW);
       Serial.println("Pump turned OFF\n");
       data_received = 'z';
      }
      else if (data_received == 'e')
      {
       digitalWrite(LED, HIGH);
       Serial.println("Pump turned ON\n"); 
       delay(780000);
       digitalWrite(LED, LOW);
       Serial.println("Pump turned OFF\n");
       data_received = 'z';
      }
      else if (data_received == 'f')
      {
       digitalWrite(LED, HIGH);
       Serial.println("Pump turned ON\n"); 
       delay(900000);
       digitalWrite(LED, LOW);
       Serial.println("Pump turned OFF\n");
       data_received = 'z';
      }
      else if (data_received == 'g')
      {
       digitalWrite(LED, HIGH);
       Serial.println("Pump turned ON\n"); 
       delay(1080000);
       digitalWrite(LED, LOW);
       Serial.println("Pump turned OFF\n");
       data_received = 'z';
      }
      else if (data_received == 'h')
      {
       digitalWrite(LED, HIGH);
       Serial.println("Pump turned ON\n"); 
       delay(1200000);
       digitalWrite(LED, LOW);
       Serial.println("Pump turned OFF\n");
       data_received = 'z';
      }
      else if (data_received == 'i')
      {
       digitalWrite(LED, HIGH);
       Serial.println("Pump turned ON\n"); 
       delay(1260000);
       digitalWrite(LED, LOW);
       Serial.println("Pump turned OFF\n");
       data_received = 'z';
      }
      else if (data_received == 'j')
      {
       digitalWrite(LED, HIGH);
       Serial.println("Pump turned ON\n"); 
       delay(1380000);
       digitalWrite(LED, LOW);
       Serial.println("Pump turned OFF\n");
       data_received = 'z';
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
  
}
