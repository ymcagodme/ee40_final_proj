#define trigPin 12
#define echoPin 13
#define leftMotor 15
#define rightMotor 11
#define leftPhoto 4
#define rightPhoto 6

int g = GREEN_LED;
int r = RED_LED;
int turnDelay = 1000;
int threshold = 20;
int cycle = 100;

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(g, OUTPUT);
  pinMode(r, OUTPUT);
//  
  pinMode(leftMotor, OUTPUT);
  pinMode(rightMotor, OUTPUT);
//  
//  pinMode(leftPhoto, INPUT);
//  pinMode(rightPhoto, INPUT);
  
  
  motorSwitch(0, 0);
}

void loop() {
//  int leftPhotoVal = 0;
//  leftPhotoVal = analogRead(leftPhoto);
//  int rightPhotoVal = 0;
//  rightPhotoVal = analogRead(rightPhoto);
//  Serial.print("left value:  ");
//  Serial.println(leftPhotoVal);
//  Serial.print("right value: ");
//  Serial.println(rightPhotoVal);
//  Serial.println();
//  
  
//  // int freq;
  float distance = 0.0;
  distance = calDistance();
  
  if (distance <= 10) {
    motorSwitch(LOW, LOW);
    setROn();
    setGOff();
  }
  else if (distance <= threshold) {
    doTurn();
  }
  else {
    setGOn();
    setROff();
    motorSwitch(HIGH, HIGH);
  }
  
  delay(cycle);
  
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
  Serial.println("Turning...");
  setROff();
  motorSwitch(0, 0);
  setGOn();
  delay(12);
  setGOff();
  motorSwitch(0, 1);
  delay(turnDelay);
}

void motorSwitch(int v1, int v2) {
  digitalWrite(leftMotor, v1);
  digitalWrite(rightMotor, v2);
}

void doBlink() {
  digitalWrite(g, HIGH);
  delay(cycle);
  digitalWrite(g, LOW);
  delay(cycle);
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
