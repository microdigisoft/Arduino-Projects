 int LedPin = 2;   // Connect RED LED to pin number 2
     int counter = 0;

      void setup() {
      pinMode(LedPin, OUTPUT);   //declare LED pin as a output
      Serial.begin(9600); //Set serial to the 9600 band
      while (! Serial); 
      Serial.println("Enter Yes to turn on the LED:");
      }
      void loop(){
     if (Serial.available())
     {
     char ch = Serial.read();
     if (ch == 'yes' || ch == 'YES')
     {
     digitalWrite(LedPin, HIGH);
     Serial.println("LED TURN ON!!");
     Serial.print("The LED switched off for : ");
     Serial.print(counter);
     Serial.println(" Seconds");
     Serial.println("Do you want to switch off LED, Enter NO or no!");
      counter = 0;
     }
        if (ch == 'no' || ch == 'NO')
     {
       digitalWrite(LedPin, LOW);
       Serial.println("LED TURN OFF!!");
       Serial.print("The LED Switched ON for : ");
       Serial.print(counter);
       Serial.println(" Seconds");
       Serial.println("Do you want to switch ON, Enter YES or yes!");
       counter = 0;
     }
     }
     delay(1000);
     counter += 1;
     }
