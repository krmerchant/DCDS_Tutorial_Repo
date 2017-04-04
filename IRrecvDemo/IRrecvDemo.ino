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
#define TURN_TIME 10
#define STEPS 200
#define MAX_ANGLE 180
#define MIN_ANGLE 20

#define LEFT 16720605
#define RIGHT 16761405


int RECV_PIN =3;
int led_pin = 13;
IRrecv irrecv(RECV_PIN);
//boolean flag = true;

//importtnat objets
decode_results results;
Servo myservo;

Stepper stepper(STEPS , 8,9,10,11);
int pos = 0;

//turn counterclockwise
void  counter_clock() {
    
     
       
     int i;
     for(i = MIN_ANGLE; i < MAX_ANGLE; i++ ) {

             delay(TURN_TIME); 
     	     myservo.write(i);
    
      } 
  
  
}

void stepper_init() {
  
  stepper.step(STEPS);
  delay(500);

  // step one revolution in the other direction:
 
   
  
  
}


//turn clockwise 
void clock() {
  
   int i;	
   for(i = MAX_ANGLE; i > MIN_ANGLE; i--) {

   	delay(TURN_TIME);
        myservo.write(i);


   }  
}



void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
  pinMode(13,OUTPUT);
  myservo.attach(5);
  stepper.setSpeed(60);
}

void loop() {

  
  //stepper_init();
  
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, DEC);
    
    int result = results.value;

    switch(result) {      
         case RIGHT: 
             counter_clock();
            break; 
        case  LEFT:
             clock();
             break;
        
        default:
             stepper_init();
             
             break;   
    }
      
    irrecv.resume(); // Receive the next value
   
  }
  //irrecv.resume();
  
  
  
}
