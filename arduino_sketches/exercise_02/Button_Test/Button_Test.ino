short unsigned int buttonPin = 2;

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600); //initialisation of serial monitor
}

void loop() {
  Serial.print("Button: ");
  Serial.println(digitalRead(buttonPin));
  delay(100);
}
