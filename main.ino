const int trigPin = 2;
const int echoPin = 3;
long duration;
int Jarak;
int LED = 8;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode (LED, OUTPUT);
  Serial.begin(9600); 
}

void loop() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  Jarak = duration * 0.034 / 2;
  delay(100);

  if (Jarak >= 0 && Jarak <= 15) {
    Serial.println("Dekat ");
    Serial.print("Jarak: ");
    Serial.print(Jarak);
    Serial.println("  cm");
    digitalWrite(LED, HIGH);
    Serial.println();
    delay(1000);
  }
  else {
    Serial.println("Jauh");
    Serial.print("Jarak: ");
    Serial.print(Jarak);
    Serial.println("  cm");
    digitalWrite(LED, LOW);
    Serial.println();
    delay(1000);
  }
}
