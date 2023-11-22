
int speedPin1=2;
int speedPin2=3;
int dir1=6;
int re_dir1=7;
int dir2=8;
int re_dir2=9;
int mSpeed=80;
void setup() {
  pinMode(speedPin1, OUTPUT);
  pinMode(speedPin2, OUTPUT);
  pinMode(dir1,OUTPUT);
  pinMode(re_dir1,OUTPUT);
  pinMode(dir2,OUTPUT);
  pinMode(re_dir2,OUTPUT);
  Serial.begin(9600); // Khởi tạo cổng Serial với tốc độ baud rate là 9600
}

void loop() {
  int sensorValueX = analogRead(A0); // Đọc giá trị analog từ chân A0
  int sensorValueY = analogRead(A1); // Đọc giá trị analog từ chân A1
  
  // In ra Serial Monitor giá trị đọc được từ cảm biến
  if (sensorValueX==791 || sensorValueX==792){
    mSpeed=0;
    digitalWrite(dir1,LOW);
    digitalWrite(re_dir1,LOW);
    digitalWrite(dir2,LOW);
    digitalWrite(re_dir2,LOW);
    
  }
  if (sensorValueX==1023){
    mSpeed=60;
    digitalWrite(dir1,HIGH);
    digitalWrite(re_dir1,LOW);
    digitalWrite(dir2,HIGH);
    digitalWrite(re_dir2,LOW);
    analogWrite(speedPin1,mSpeed);
    analogWrite(speedPin2,mSpeed);
  }
 // Đợi 200 milliseconds trước khi đọc lại giá trị
}
