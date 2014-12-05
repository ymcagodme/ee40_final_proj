#define trigPin 12
#define echoPin 13
#define leftMotor 15
#define rightMotor 11
#define leftPhoto 4
#define rightPhoto 6

int g = GREEN_LED;
int r = RED_LED;
int t = 200;
int turnDelay = 3000;
int threshold = 20;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(g, OUTPUT);
  pinMode(r, OUTPUT);
  
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
  
  pinMode(leftPhoto, INPUT);
  pinMode(rightPhoto, INPUT);
  
  
  motorSwitch(0, 0);
}

void loop() {
  int leftPhotoVal = analogRead(leftPhoto);
  int rightPhotoVal = analogRead(rightPhoto);
  Serial.print("left value");
  Serial.println(leftPhotoVal);
  Serial.print("right value");
  Serial.println(rightPhotoVal);
  
  
//  // int freq;
//  float distance = 0.0;
//  distance = calDistance();
  
//  if (distance <= 5) {
////    motorSwitch(0, 0);
//    digitalWrite(leftMotor, LOW);
//    digitalWrite(rightMotor, LOW);    
//    setROn();
//    setGOff();
//  }
//  else if (distance <= threshold) {
//    doTurn();
//  }
//  else {
//    setGOn();
//    setROff();
////    motorSwitch(1, 1);
//    digitalWrite(leftMotor, HIGH);
//    digitalWrite(rightMotor, HIGH);
//  }
//  
  delay(100);
  
}

float calDistance() {
  int duration;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(12);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(100);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  float distance = duration / 29 / 2;
  Serial.print(distance);
  Serial.println(" cm");
  return distance;
}

void doTurn() {
  setROff();
  motorSwitch(0, 0);
  setGOn();
  delay(turnDelay);
  setGOff();
  motorSwitch(1, 0);
  delay(turnDelay);
}

void motorSwitch(int v1, int v2) {
  digitalWrite(leftMotor, v1);
  digitalWrite(rightMotor, v2);
}

void doBlink() {
  digitalWrite(g, HIGH);
  delay(t);
  digitalWrite(g, LOW);
  delay(t);
}

void setGOn() {
  digitalWrite(g, HIGH);
}

void setGOff() {
  digitalWrite(g, LOW);
}

void setROn() {
  digitalWrite(r, HIGH);
}

void setROff() {
  digitalWrite(r, LOW);
}
