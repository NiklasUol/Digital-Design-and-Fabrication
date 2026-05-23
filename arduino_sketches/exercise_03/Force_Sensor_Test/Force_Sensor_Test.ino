const int forceSensorPin = A0;

void setup() {
  Serial.begin(9600);
  pinMode(forceSensorPin, INPUT);
}

void loop() {
  int force = analogRead(forceSensorPin);
  Serial.print("Force value: ");
  Serial.println(force);
  delay(1000);
}
