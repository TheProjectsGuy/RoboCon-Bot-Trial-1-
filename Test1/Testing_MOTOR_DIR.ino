class MOTOR {
    int pin_DIR;
    int PWM;

  public:

    MOTOR(int pin_DIR, int PWM) {
      pinMode(pin_DIR, OUTPUT);
      pinMode(PWM, OUTPUT);
      this->pin_DIR = pin_DIR;
      this->PWM = PWM;
    }

    void turn(int state) {
      switch (state) {
        case 2:
          digitalWrite(pin_DIR, HIGH);
          analogWrite(PWM, 80);
          break;
        case 1:
          digitalWrite(pin_DIR, LOW);
          analogWrite(PWM, 80);
          break;
        case 0:
          digitalWrite(pin_DIR, LOW);
          analogWrite(PWM, 0);
          break;
        default:
          //Serial.println("INVALID STATE ENCOUNTERED.....");
          break;
      }
    }
};
MOTOR motor1(32, 2), motor2(28, 4), motor3(30, 5), motor4(34, 3);

void setup() {

  Serial.begin(9600);
  Serial2.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:

  /*
    Serial.println("Enter the motor number to run : ");
    while (!Serial.available());
    int motor_Number = Serial.parseInt();
    Serial.println("Enter State : [1 to run in STD DIR (out), 0 to turn OFF, 2 to run in OPP DIR (in)] : ");
    while (!Serial.available());
    int motorDirection = Serial.parseInt();
    Serial.println("Running motor " + String(motor_Number) + " in " + String(motorDirection) + " DIR");
    switch (motor_Number) {
    case 1:
      motor1.turn(motorDirection);
      break;
    case 2:
      motor2.turn(motorDirection);
      break;
    case 3:
      motor3.turn(motorDirection);
      break;
    case 4:
      motor4.turn(motorDirection);
      break;
    default:
      Serial.println("INVALID MOTOR NUMBER ENCOUNTERED");
      break;
    }
  */
  Serial.println("Enter the direction of the bot [W A S D control, <SPACE> to stop] : ");
  while (!Serial2.available());
  char option = Serial2.read();
  switch (option) {
    case 'W': motor1.turn(1); motor2.turn(1) ; motor3.turn(2); motor4.turn(2);
    Serial.println("Moving Forward");
    break;
    case 'A': motor1.turn(2); motor2.turn(1) ; motor3.turn(1); motor4.turn(2); 
    Serial.println("Moving Leftward");
    break;
    case 'S': motor1.turn(2); motor2.turn(2) ; motor3.turn(1); motor4.turn(1); 
    Serial.println("Moving Backward");
    break;
    case 'D':  motor1.turn(1); motor2.turn(2) ; motor3.turn(2); motor4.turn(1); 
    Serial.println("Moving Rightward");
    break;
    case ' ':
     motor1.turn(0); motor2.turn(0) ; motor3.turn(0); motor4.turn(0); break;
     Serial.println("Stopping Movement");
     default:
     Serial.println("An UNKNOWN ERROR (Code 101) ENCOUNTERED");
     break;
  }
}
