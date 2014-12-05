#define trigPin 12
#define echoPin 13
#define leftMotor 14
#define rightMotor 2
#define leftPhoto 4
#define rightPhoto 6

int g = GREEN_LED;
int r = RED_LED;
int t = 200;
int turnDelay = 3000;

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
  int leftPhotoVal = digitalRead(leftPhoto);
  int rightPhotoVal = digitalRead(rightPhoto);
  Serial.println("left value");
  Serial.println(leftPhotoVal);
  Serial.println("right value");
  Serial.println(rightPhotoVal);
  
  
  // int freq;
  float distance = calDistance();


  if (distance >= 80) {
    setGOn();
    setROff();
    motorSwitch(leftPhotoVal, rightPhotoVal);
//    turnOnMotor();
  }
  else {
    setROn();
    setGOff();
    doTurn();
    delay(turnDelay);
  }
  
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
  Serial.println(distance);
  Serial.println(" cm");
  return distance;
}

void doTurn() {
  digitalWrite(leftMotor, LOW);
  delay(turnDelay);
  motorSwitch(1, 1);
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