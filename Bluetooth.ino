char value='0'; // Variable of type "Character"
void setup() {
  Serial.begin(9600); // Choosing baud rate 
}
void loop() {
  if(Serial.available() > 0) // If any data is available then enter if stmt
  {
    value=Serial.read(); // Store the data in 'value' variable
    Serial.print(value); // prints content of 'value' variable 
    Serial.print("\n"); // prints a new line
  }
}
