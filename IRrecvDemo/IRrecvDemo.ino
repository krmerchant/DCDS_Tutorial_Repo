/*
 * IRremote: IRrecvDemo - demonstrates receiving IR codes with IRrecv
 * An IR detector/demodulator must be connected to the input RECV_PIN.
 * Version 0.1 July, 2009
 * Copyright 2009 Ken Shirriff
 * http://arcfn.com
 */

#include <IRremote.h>
#include <Servo.h>
#include <Stepper.h>
#define TURN_TIME 100
#define STEPS 100


int RECV_PIN =3;
int led_pin = 13;
IRrecv irrecv(RECV_PIN);
//boolean flag = true;

//importtnat objets
decode_results results;
Servo myservo;

Stepper stepper(STEPS , 8,9,10,11);
int pos = 0;


void  counter_clock() {
    
     
       
    
     delay(TURN_TIME); 
     myservo.write(150);
    
 
    
  
 
  
}

void clock() {
  
  
  
   delay(TURN_TIME);
   myservo.write(50);
 
    
  
  
  
}



void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(13,OUTPUT);
  myservo.attach(5);
  stepper.setSpeed(30);
}

void loop() {
//  
//  if(flag) {
//     counter_clock();
//     flag = false; 
//    
//  }
  
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    
    int result = results.value;


     //BEGIN STATE MACHINE
     
    switch(results) {      
         case 16761405: 
             counter_clock();
            break; 
        case  16720605:
             clock();
             break;
        default:  
    }
      
    irrecv.resume(); // Receive the next value
   
  }
  
  
  
}
