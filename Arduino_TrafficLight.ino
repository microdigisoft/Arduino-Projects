int GREEN = 0; // Initialize Pin0 for Green Light
int YELLOW = 1;// Initialize Pin1 for Yellow Light
int RED = 2; // Initialize Pin2 for Red Light
int DELAY_GREEN = 1000; //Delay for Green Light
int DELAY_YELLOW = 1000;//Delay for Yellow Light
int DELAY_RED = 1000;//Delay for Red Light
const int rs = 12, en = 11, d4 = 4, d5 = 5, d6 = 6, d7 = 7;// Initialize pins for interfacing LCD
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup()
{
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD
  lcd.print("");
  pinMode(GREEN, OUTPUT);//Define Green LED in as output
  pinMode(YELLOW, OUTPUT);//Define Yellow LED in as output
  pinMode(RED, OUTPUT);//Define RED LED in as output
}
void loop()
{
  no_light(); //Call no light function turn off lights initially
  delay(1000); // 1sec delay
  lcd.display(); //initialize LCD display
  lcd.clear();//Clear the LCD
  red_light(); // Call red light function
  delay(DELAY_RED); // Delay for RED traffic light
  lcd.print("STOP"); // Print STOP for RED signal
  delay(1000);// Wait for 1sec delay
  lcd.clear();// Clear LCD
  yellow_light();// Call Yellow light function
  delay(DELAY_YELLOW);// Delay for Yellow traffic light
  lcd.print("WAIT"); // Print wait on LCD with yellow singal
  delay(1000);// Wait for 1 sec
  lcd.clear();// Clear LCD
  green_light();//call for green traffic light
  delay(DELAY_GREEN);//Delay for Green signal
  lcd.clear();//clear LCD display

  lcd.print("GO");//Print Go for Green singal
  delay(1000);//1 sec delay
  lcd.clear();//clear LCD
}

// Function to make all singal light low
void no_light() {
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);

}
//Function to control light for RED singnal
void red_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, HIGH);
}
//Function to control light for Yellow singnal
void yellow_light()
{
  digitalWrite(GREEN, LOW);
  digitalWrite(YELLOW, HIGH);
  digitalWrite(RED, LOW);
}
//Function to control light for Green singnal
void green_light()
{
  digitalWrite(GREEN, HIGH);
  digitalWrite(YELLOW, LOW);
  digitalWrite(RED, LOW);
}
