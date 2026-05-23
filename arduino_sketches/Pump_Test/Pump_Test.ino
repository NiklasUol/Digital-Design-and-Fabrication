const int ventile = 13;
const int upperPump = 12;
const int sidePump = 11;

void setup() {
  pinMode(ventile, OUTPUT);
  pinMode(upperPump, OUTPUT);
  pinMode(sidePump, OUTPUT);

  digitalWrite(ventile, LOW);
  digitalWrite(upperPump, LOW);
  digitalWrite(sidePump, LOW);
}

void loop() {
  digitalWrite(sidePump, HIGH);
  delay(5000);
  digitalWrite(sidePump,LOW);
  delay(1000);
  
  digitalWrite(ventile, HIGH);
  delay(1000);
  digitalWrite(upperPump, HIGH);
  delay(5000);
  digitalWrite(upperPump, LOW);
  delay(1000);
  digitalWrite(ventile, LOW);
  delay(1000);
}
