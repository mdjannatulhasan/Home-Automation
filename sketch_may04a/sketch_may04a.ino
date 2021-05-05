int LED = D4;
int timer = 0;
void setup() {
 pinMode(LED, OUTPUT);
 Serial.begin(9600); /* Define baud rate for serial communication */
}

void loop() {

 if (Serial.available())  /* If data is available on serial port */
    {
      char data_received; 
      data_received = Serial.read();  /* Data received from bluetooth */
      if (data_received == 'a')
      {
       digitalWrite(LED, HIGH);
       Serial.write("LED turned ON\n");        
      }
      else if (data_received == 's')
      {
      Serial.println("Enter Minute");
       int timer2 = Serial.parseInt();
       delay(1000);
       Serial.println("timer value = "+ timer2);
       timer = timer2;
       timer = timer * 1000 * 60;
       delay(timer);
       Serial.println("Leaving..........");
       }
       
       else if (data_received == '2')
      {
       digitalWrite(LED, LOW);
       Serial.write("LED turned OFF\n");
      }
      else
      {
       Serial.write("Select either 1 or 2");
      }
    }
}
