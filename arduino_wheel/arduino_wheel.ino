int motor_L=2;
int motor_R=3;
int dir_L=6;
int re_dir_L=7;
int dir_R=8;
int re_dir_R=9;
int mSpeed=2000;
void setup() {
  // put your setup code here, to run once:
  
  pinMode(motor_L,OUTPUT);
  pinMode(motor_R, OUTPUT);
  pinMode(dir_L,OUTPUT);
  pinMode(re_dir_L,OUTPUT);
  pinMode(dir_R,OUTPUT);
  pinMode(re_dir_R,OUTPUT);
  Serial.begin(9600); // Khởi tạo cổng Serial với tốc độ baud rate là 9600
}

void loop() {
int sensorValueX = analogRead(A0); // Đọc giá trị analog từ chân A0
int sensorValueY = analogRead(A1); // Đọc giá trị analog từ chân A1  // put your main code here, to run repeatedly:
int motor_L1  = digitalRead(13);
int motor_L2  = digitalRead(12);
//int motor_R  = digitalRead(12);
Serial.print("x:");
Serial.println(sensorValueX,DEC);
Serial.print("y:");
Serial.println(sensorValueY,DEC);
Serial.print("M_L:");
Serial.println(motor_L1*5,DEC);
Serial.println(motor_L2*5,DEC);
//Serial.print("M_R:");
//Serial.println(motor_R*5,DEC);
delay(1000);
if (sensorValueX >= 770 && sensorValueX <= 792){
    mSpeed=0;
    digitalWrite(dir_L,LOW);
    digitalWrite(re_dir_L,LOW);
    digitalWrite(dir_R,LOW);
    digitalWrite(re_dir_R,LOW);
    
  }
  if (sensorValueX==1023){
    mSpeed=80;
    digitalWrite(dir_L,HIGH);
    digitalWrite(re_dir_L,LOW);
    digitalWrite(dir_R,HIGH);
    digitalWrite(re_dir_R,LOW);
    analogWrite(motor_L,mSpeed);
    analogWrite(motor_R,mSpeed);
  }
  if (sensorValueX<=410){
    mSpeed=80;
    digitalWrite(dir_L,LOW);
    digitalWrite(re_dir_L,HIGH);
    digitalWrite(dir_R,LOW);
    digitalWrite(re_dir_R,HIGH);
    analogWrite(motor_L,mSpeed);
    analogWrite(motor_R,mSpeed);
  }
 // Đợi 200 milliseconds trước khi đọc lại giá trị

}
