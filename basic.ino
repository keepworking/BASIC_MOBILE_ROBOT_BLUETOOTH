/*
 * 16.01.18 mechasolution mobile robot bluetooth basic code
 * 
 * 
 */


#include <SoftwareSerial.h> // 소프트웨어 시리얼
SoftwareSerial mySerial(4, 5); // RX, TX
int speedPinA = 3;
int speedPinB = 9;
int dir1PinA = 6;
int dir2PinA = 7;
int dir1PinB = 10;
int dir2PinB = 11;
int MODE = 0;
byte incomingByte;

int speed_value_motorA;
int speed_value_motorB;
void setup() {
  mySerial.begin(9600);
  // set digital i/o pins as outputs:
  pinMode(speedPinA, OUTPUT);
  pinMode(speedPinB, OUTPUT);
  pinMode(dir1PinA, OUTPUT);
  pinMode(dir2PinA, OUTPUT);
  pinMode(dir1PinB, OUTPUT);
  pinMode(dir2PinB, OUTPUT);

  //Initial status
  digitalWrite(dir1PinA, LOW);
  digitalWrite(dir2PinA, LOW);
  digitalWrite(dir1PinB, LOW);
  digitalWrite(dir2PinB, LOW);

  
  // control the speed 0- 255
  speed_value_motorA = 255; // half speed
  speed_value_motorB = 255; // half speed
  analogWrite(speedPinA, speed_value_motorA);
  analogWrite(speedPinB, speed_value_motorB);
}

void loop() {
  while(MODE){//모드가 참일때, 오토드라이빙 모드 실행. 
    /*
     * 이곳에 아두이노 미로찾기 소스코드를 작성해주시면 됩니다.
     * 
     * 기본 모드는 거짓으로 되어있기때문에, 처음부터 동작하지 않습니다.
     * 
     */

     MODE = 0;
     //미로찾기가끝나면, 오토드라이빙 모드를 끝내줍시다.
  }
  if (mySerial.available() > 0) {
    switch(mySerial.read()){
      case 'a': Left(); break;
      case 'd': Right(); break;
      case 's': Stop(); break;
      case 'w': Forward(); break;
      case 'x': Back(); break;
      case '1': MODE = 1; break;//오토드라이빙 모드를 실행합니다.
      case '2':  break; //break와 : 사이에 원하는 명령을 넣으셔도 됩니다.
    }
  }
}


//motor control functions -----------
void Left(){
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, LOW);
      digitalWrite(dir1PinB, LOW);
      digitalWrite(dir2PinB, HIGH);
}
void Right(){
  
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, HIGH);
      digitalWrite(dir1PinB, LOW);
      digitalWrite(dir2PinB, LOW);
}
void Forward(){
  
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, HIGH);
      digitalWrite(dir1PinB, LOW);
      digitalWrite(dir2PinB, HIGH);
}

void Back(){

  
      digitalWrite(dir1PinA, HIGH);
      digitalWrite(dir2PinA, LOW);
      digitalWrite(dir1PinB, HIGH);
      digitalWrite(dir2PinB, LOW);
}

void Stop(){
  
      digitalWrite(dir1PinA, LOW);
      digitalWrite(dir2PinA, LOW);
      digitalWrite(dir1PinB, LOW);
      digitalWrite(dir2PinB, LOW);
}
