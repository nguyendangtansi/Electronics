# mobile base
this is a project for controlling mobile base consisting of two wheels and joystick

## joystick controller
@Si please explain what you have done here

```ino
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

```

- @si for example, what does this variable do:
    - `int sensorValueX = analogRead(A0)`