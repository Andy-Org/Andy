/*
 * Remember to MODIFY BAUD RATES
 */


#include <SoftwareSerial.h>

// Define the Rx and Tx Pins
#define rxPin 10
#define txPin 11

// Define the BAUD Rate for hardware (hUart) and software (sUart) ports
#define hUart 9600
#define sUart 115200

// Define the LED Pin - no longer used!
#define ledPin 13

// Define dDelay 
#define dDelay 100

String xString, yString;

// set up a new serial port
SoftwareSerial mySerial =  SoftwareSerial(rxPin, txPin);
byte pinState = 0;



void setup()  {
  // define pin modes for tx, rx, led pins:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  pinMode(ledPin, OUTPUT);

// Get ready to send data
  Serial.begin(hUart);
    
// set the data rate for the SoftwareSerial port
mySerial.begin(sUart);


// Add to the drama and excitement by delaying 3 seconds
// And then let'em know you're ready!
delay(dDelay);
Serial.println("System Ready to Rock: ");

}

void loop() {


  //  READ FROM SERIAL MONITOR, and
  //  SEND TO SW SERIAL

  yString = Serial.readString();
  if (yString != ""){
    mySerial.print(yString);
  }


  xString = mySerial.readString();
  if (xString != ""){
    Serial.println(xString);
  }

}


// *************************************************************************************************
// *************************************************************************************************
//
//
// SO... About this Toggle() Function... //
// When I started on this Sketch, I re-used some code from the original SerialSoftware sample sketch.
// I then re-mixed it with some stuff I found online... and long story short, there was a function that
// would toggle the LED (Pin 13) on/off as bits came into UART buffer and were written to the Serial Monitor.
// It was a good debugging tool, but since the Sketch is working bug-free (fingers crossed), we no longer 
// have a need for the visual debug feedback. So I'm keeping it here, completely empty, for two reasons. 
// First, because I do want to start writing functions and since I'm unfamiliar with them, this here serves
// to be a starting point for me. Secondly, it reminds me how difficult it was at first to make sense of this
// stuff, but now, overall, I'm doing fairly well with reading and understanding other people's sketches, AND,
// even writing my own sketches - its a marker to remind me how far I've come :-)
//
// Now - was this really necessary? 
//
// Absolutely NOT!
//
// With Love,
// /F
//
//

void toggle(int pinNum) {
 
}

// ***************************************************************************************
// ***************************************************************************************
