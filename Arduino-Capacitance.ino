LiquidCrystal_I2C lcd(0x27, 16, 2); // import I2C LCD library
//LiquidCrystal lcd(6, 7, 2, 3, 4, 5);
int R1 = 13; //Initialize pin 13 to connect resistor R1
int R2 = 11; //Initialize pin 11 to connect resistor R2
int analogPin = A0; //Initialize Analog A0
unsigned long start_timer = 0;
unsigned long stop_timer = 0;
unsigned long duration = 0;
float voltage = 3;
float Capacitance = 0.0;
int solution (void);

void setup()
{
  Serial.begin(9600); //Start Arduino Serial monitor at baud rate 9600
  lcd.backlight();
  //lcd.begin(16, 2);
  lcd.print(” Measurment”);
  lcd.setCursor(0, 1);
  lcd.print(“of capacitor “);
  pinMode(R2, INPUT); // Define Resistor R2 as input
  pinMode(R1, OUTPUT);//Define Resisot R1 as output
  digitalWrite(R1, HIGH);
}
//1021 1022 1023
void loop()
{
  while (solution() >= 1010 && solution() <= 1030) {

    lcd.setCursor(0, 1); lcd.print(“place capacitor “);

    delay(200); lcd.setCursor(0, 1); lcd.print(” “);

    delay(200);
  } delay(2000);

  lcd.setCursor(0, 1);

  lcd.print(” “);

  while (1) {
    pinMode(R1, INPUT); // Reversing polarity for Resistor pin for discharging

    pinMode(R2, OUTPUT);

    digitalWrite(R2, LOW);

    lcd.setCursor(0, 1);

    lcd.print(“Discharging - “);

    while (voltage > 2.0)
    {
      voltage = solution();
      delay(100);
      lcd.setCursor(12, 1);
      Capacitance = voltage * (99.0 / 1023.0); // Calulate the capacitace
      lcd.print((99 - Capacitance), 0);
      lcd.setCursor(14, 1);
      lcd.print(“ % ”);
    }

    // lcd.setCursor(0,1);
    // lcd.print(” “);
    lcd.setCursor(0, 0);
    lcd.print(“value = “);//Print Capacitance value on LCD
    lcd.print(Capacitance);
    lcd.print(“uF”);
    delay(3000);
    while (1)
    {
      lcd.setCursor(0, 1);
      lcd.print(” Restart “);
      delay(200);
      lcd.setCursor(0, 1);
      lcd.print(” “);
      delay(200);
    }

  }
}

int solution (void)
{
  int value;
  value = analogRead(analogPin);
  return value;
}
