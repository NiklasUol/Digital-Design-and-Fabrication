const int ventile = 13;
const int upperPump = 12;
const int sidePump = 11;
const int forceSensorPin = A0;
const int buttonPin = 8;

void setup() {
  Serial.begin(9600);

  pinMode(ventile, OUTPUT);
  pinMode(upperPump, OUTPUT);
  pinMode(sidePump, OUTPUT);
  pinMode(forceSensorPin, INPUT);
  pinMode(buttonPin, INPUT);

  digitalWrite(ventile, LOW);
  digitalWrite(upperPump, LOW);
  digitalWrite(sidePump, LOW);
}

void loop() {
  int appliedForce = analogRead(forceSensorPin);
  int buttonValue = digitalRead(buttonPin);
  Serial.print("Applied Force: " );
  Serial.println(appliedForce);
  Serial.print("Button Value: ");
  Serial.println(buttonValue);

  if(buttonValue == 1){
    digitalWrite(ventile, LOW);
    digitalWrite(upperPump, LOW);
    digitalWrite(sidePump, HIGH);
  }
  else if(appliedForce > 1020) {
    digitalWrite(ventile, HIGH);
    digitalWrite(upperPump, HIGH);
    digitalWrite(sidePump, LOW);
  }
  else {
    digitalWrite(upperPump, LOW);
    digitalWrite(sidePump, LOW);
  }
  delay(500);
}
