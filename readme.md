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

## different motor types
there are different motor types:
- DC motor:
  - stepper motor [link](https://en.wikipedia.org/wiki/Stepper_motor)
  - Servo motor

## drive for servo motor: L298N
- it has MOSFEST:
  - it is a transistor-bridge circut [link](https://en.wikipedia.org/wiki/H-bridge)

# TODO:
- Anssi's suggestion:
  - the PWM is running by arduino
  - Arduino is generating `V_max`
  - we need to find the frequency of the main board on the vacuum cleaner
    - connect it to an oscilloscope
    - read the period using a cursor
    - this period is the cycle to which the wheel encoder is matched
  - then, we have to do PWM on the arduino code:
    - possibly setting the frequency
    - from which we can get the period
    - then we set the width which is the duty cycle
    - using this duty cycle and the PWM module of the drive, we can control the output voltage which is connected to the motor