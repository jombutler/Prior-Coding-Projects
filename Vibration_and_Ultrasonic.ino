int trigPin = 5;
int echoPin = 3;
int buzzer = 10;

float duration;
float distance;

void intensity(int lowerIntensity, int upperIntensity, double maxDist, double curDistance){
  int difference = upperIntensity - lowerIntensity;
  double fraction = 1.0 - curDistance / maxDist;
  double fractionAmount = fraction * difference;
  int totalIntensity = lowerIntensity + (int) fractionAmount;

  if (curDistance < maxDist){
    analogWrite(buzzer, totalIntensity);
  } else{
    analogWrite(buzzer,0);
  }
}


void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  digitalWrite(buzzer,HIGH);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  //Speed of sound is 0.0343 cm per microsecond
  distance = (duration*.0343)/2;
  Serial.print("Distance: cm");
  Serial.println(distance);

  intensity(130,255,30,distance);

  delay(100);
}

