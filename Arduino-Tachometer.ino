#include <LiquidCrystal_I2C.h>//import I2C LCD library
LiquidCrystal_I2C lcd(0x27, 16, 2); // Initlize the i2C LCD
#define sensor 9 // Define pin 9 for IR Sensor
#define start 12 // Define pin 12 for Start Push button
int enA = 5;  // Define pin 5 for Enable pin H-Bridge Motor Driver
int in1 = 6; // Define pin 6 for Input1 pin H-Bridge Motor Driver
int in2 = 7; // Define pin 67 for Input12 pin H-Bridge Motor Driver

//Delay function to handle tachometer readings
int delay1()
{
  //unsigned int long k;
  int i, j;

  unsigned int count = 0;
  for (i = 0; i < 100; i++)
  {
    for (j = 0; j < 100; j++)
    {
      if (digitalRead(sensor)) // Read IR senosr pulses
      {
        count++;
        while (digitalRead(sensor)); // Read IR senosr pulses
      }
    }
  }
  return count;
}
void setup()
{
  pinMode(enA, OUTPUT); // Defined Enable pin as output
  pinMode(in1, OUTPUT);// Defined Input1 pin as output
  pinMode(in2, OUTPUT);// Defined Input2 pin as output
  //Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  pinMode(sensor, INPUT);// Define Sensor pin as input
  pinMode(start, INPUT);// Define Start push button pin as input

  lcd.init();// Start LCD
  lcd.backlight();// Start LCD backlight
  lcd.begin(16, 2);
  lcd.print(" Microdigisoft");
  delay(2000);
  digitalWrite(start, HIGH);
}

void loop()
{

  unsigned int time = 0, RPM = 0;
  delay(5000);
  lcd.clear();

  lcd.setCursor(1, 0);
  lcd.print(" Please Press ");
  lcd.setCursor(0, 1);
  lcd.print("Button to Start ");
  while (digitalRead(start)); // Press push button to start motor Rotation
  lcd.clear();
  lcd.print("Reading RPM ");
  lcd.setCursor(0, 1);
  lcd.print("Please Wait"); // Wait to read the IR sensor pulses
  // Turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  // Accelerate  speed
  analogWrite(enA, 40); // Speed up the motor
  delay(20);
  time = delay1(); // Find a time for rotation
  delay(2000);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  lcd.clear();
  RPM = (time * 12) / 1; // Calculate the RPM
  lcd.clear();
  lcd.print("RPM=");
  lcd.print(RPM); // Print the RPM value on LCD
  delay(1000);
}
