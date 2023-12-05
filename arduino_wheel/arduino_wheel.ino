int pwm_L=2;      //PWM for motor Left in pin tidle 2
int pwm_R=3;      //PWM for motor Left in pin tidle 3
int dir_L=6;      //Positive output to Motor Left in pin digital 6
int re_dir_L=7;   //Negative output to Motor Left in pin digital 7
int dir_R=8;      //Positive output to Motor Right in pin digital 8
int re_dir_R=9;   //Negative output to Motor Right in pin digital 9
int mSpeedA=0;    //Speed for motor Left controlled by pwm_L
int mSpeedB=0;    //Speed for motor Left controlled by pwm_R
void setup() {
  pinMode(pwm_L,OUTPUT); 
  pinMode(pwm_R, OUTPUT);
  pinMode(dir_L,OUTPUT);
  pinMode(re_dir_L,OUTPUT);
  pinMode(dir_R,OUTPUT);
  pinMode(re_dir_R,OUTPUT);
  Serial.begin(9600); // Initialize Serial port with baud rate 9600

}

void loop() {
  int X = analogRead(A5); // Read analog value from A5
  int Y = analogRead(A6); // Read analog value from A6
  Serial.print("X:");
  Serial.println(X,DEC);
  Serial.print("Y:");
  Serial.println(Y,DEC);
  delay(1000);
  //X Axis to move forward or backward
  if(X<513){ // Move Forward
    digitalWrite(dir_L,HIGH);
    digitalWrite(re_dir_L,LOW);
    digitalWrite(dir_R,HIGH);
    digitalWrite(re_dir_R,LOW);
    mSpeedA=map(X,513,255,0,255);
    mSpeedB=map(X,513,255,0,255);
  }
  else if(X>516){ //Move backward
    digitalWrite(dir_L,LOW);
    digitalWrite(re_dir_L,HIGH);
    digitalWrite(dir_R,LOW);
    digitalWrite(re_dir_R,HIGH);
    mSpeedA=map(X,516,777,0,255);
    mSpeedB=map(X,513,777,0,255); 
  }
  else{ // Middle Stop
    digitalWrite(dir_L,LOW);
    digitalWrite(re_dir_L,LOW);
    digitalWrite(dir_R,LOW);
    digitalWrite(re_dir_R,LOW);
    mSpeedA=0;
    mSpeedB=0; 
  }
  // Y Axis to turn left or right
  if(Y<511){  // Turn left, Motor Right move faster than Motor Left
    int ratio = map(Y,511,260,0,255);
    mSpeedA=mSpeedA-ratio;
    mSpeedB=mSpeedB+ratio;
    if(mSpeedA<0){
    digitalWrite(dir_L,LOW);
    digitalWrite(re_dir_L,HIGH);
    digitalWrite(dir_R,HIGH);
    digitalWrite(re_dir_R,LOW);
    }
  }
  if(Y>514){  // Turn right, Motor Left move faster than Motor Right
    int ratio = map(Y,514,773,0,255);
    mSpeedA=mSpeedA+ratio;
    mSpeedB=mSpeedB-ratio;
    if(mSpeedB<0){
    digitalWrite(dir_L,HIGH);
    digitalWrite(re_dir_L,LOW);
    digitalWrite(dir_R,LOW);
    digitalWrite(re_dir_R,HIGH);
    }
  }
  /*if(mSpeedA<50 && mSpeedB<50){   //Prevent low voltage for motors
    mSpeedA=0;
    mSpeedB=0;
  }*/
  analogWrite(pwm_L,mSpeedA);
  analogWrite(pwm_L,mSpeedB);
}
