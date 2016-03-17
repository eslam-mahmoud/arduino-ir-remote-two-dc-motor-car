#include <IRremoteInt.h>
#include <IRremote.h>

//Motor 1 Right
const int m1_pwm = 2;
const int m1_1 = 8;
const int m1_2 = 9;

//Motor 2 Left
const int m2_pwm = 3;
const int m2_1 = 10;
const int m2_2 = 11;

//IR
int LED = 12;

//IR
int RECV_PIN = 13;
IRrecv irrecv(RECV_PIN);
decode_results results;
long ir_value = 16726215;
//up => 16718055
//down => 16730805
//right => 16734885
//left => 16716015
//stop => 16726215

void setup()
{
    pinMode(LED,OUTPUT);

    pinMode(m1_pwm,OUTPUT);
    pinMode(m1_1,OUTPUT);
    pinMode(m1_2,OUTPUT);
    analogWrite(m1_pwm,255);
    
    pinMode(m2_pwm,OUTPUT);
    pinMode(m2_1,OUTPUT);
    pinMode(m2_2,OUTPUT);
    analogWrite(m2_pwm,255);

    //start the serial output
    //Serial.begin(9600);

    // Start the receiver
    irrecv.enableIRIn();
}
void loop()
{
  if (irrecv.decode(&results)) {
    digitalWrite(LED,HIGH);
    delay(100);
    digitalWrite(LED,LOW);
    
    ir_value = results.value;
//    Serial.print("ir_value ");
//    Serial.println(ir_value);
    
    //press up
    if (ir_value == 16718055) {    
//      Serial.println("up");
      goForward();
    } else if (ir_value == 16730805) {
      //press down    
//      Serial.println("down");
      goBackward();
    } else if (ir_value == 16734885) {
      //press right    
//      Serial.println("right");
      goRight();
    } else if (ir_value == 16716015) {
      //press left    
//      Serial.println("left");
      goLeft();
    } else if (ir_value == 16726215) {
      //press stop    
//      Serial.println("stop");
      stopBoth();
    } else {
      //press any other button
    }

    delay(100);    
    //Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value 
  } else {
    delay(10);
  }
}


void goForward(){
  digitalWrite(m1_1,LOW);
  digitalWrite(m1_2,HIGH);
  
  digitalWrite(m2_1,LOW);
  digitalWrite(m2_2,HIGH);
}

void goBackward(){
  digitalWrite(m1_1,HIGH);
  digitalWrite(m1_2,LOW);

  digitalWrite(m2_1,HIGH);
  digitalWrite(m2_2,LOW);
}


void goRight(){
  digitalWrite(m1_1,LOW);
  digitalWrite(m1_2,LOW);
  
  digitalWrite(m2_1,LOW);
  digitalWrite(m2_2,HIGH);
}


void goLeft(){
  digitalWrite(m1_1,LOW);
  digitalWrite(m1_2,HIGH);
  
  digitalWrite(m2_1,LOW);
  digitalWrite(m2_2,LOW);
}

void stopBoth(){
  digitalWrite(m1_1,LOW);
  digitalWrite(m1_2,LOW);
  
  digitalWrite(m2_1,LOW);
  digitalWrite(m2_2,LOW);
}
