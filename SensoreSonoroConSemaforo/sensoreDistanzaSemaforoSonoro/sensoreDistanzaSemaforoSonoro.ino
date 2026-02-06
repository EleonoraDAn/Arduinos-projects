const int triggerPin = 13;
const int ecoPin = 12;
const int buzzerPin = 11;
float distance, duration;
const int soglia = 15;
const int ledRosso = 10;
const int ledGiallo = 9;
const int ledVerde = 8;

void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(ecoPin, INPUT);
  pinMode(ledRosso, OUTPUT);
  Serial.begin(9600);
  Serial.println("Avvio sensore ... ");
}

void loop() {
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  duration = pulseIn(ecoPin, HIGH, 30000);
  
  distance = (duration * .0343)/2;
  if(distance > 0) {
    if(distance <= soglia) {
    tone(buzzerPin, 3000);
    analogWrite(ledRosso, 255);
    analogWrite(ledGiallo, 0);
    analogWrite(ledVerde, 0);
  } else if (distance > soglia && distance <= 50){
    tone(buzzerPin, 100);
    analogWrite(ledRosso, 0);
    analogWrite(ledGiallo, 255);
    analogWrite(ledVerde, 0);
    } else if ( distance > 50 ) {
    noTone(buzzerPin);
    analogWrite(ledRosso, 0);
    analogWrite(ledGiallo, 0);
    analogWrite(ledVerde, 255);
    }
  }
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}