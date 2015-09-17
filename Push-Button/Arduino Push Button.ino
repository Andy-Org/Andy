/*
 * Arduino Push Button Sketch
 * Using a Momentary Switch on Pin7, we
 * detect when button is pressed!
 * 
 * Using a momentary button, we are shorting Pin7 to Gnd with a 10KOhm Resistor between switch
 * and Gnd. Pin7 is HIGH by default, but once button is pressed, it is pulled LOW. Our counter
 * therefore counts the number of clicks on the button, using the xCount variable.
 */


int ledPin = 13; // choose the pin for the LED
int inPin = 7;   // choose the input pin (for a pushbutton)
int val = 0;     // variable for reading the pin status

int xCount = 0;  // Set the counter

void setup() {
  pinMode(ledPin, OUTPUT);  // declare LED as output
  pinMode(inPin, INPUT);    // declare pushbutton as input
  digitalWrite(inPin, HIGH);  // put inPin Low by default
  Serial.begin(9600);      // start the Serial monitor 
}

void loop(){
  val = digitalRead(inPin);  // read input value


  if (val == HIGH) {         // check if the input is HIGH (button pushed)
    // DO NOTHING HERE
  } else if (val == LOW) {
    xCount = xCount + 1;
    Serial.print("xCount = ");    // debug xCount
    Serial.println(xCount);       // debug xCount
  }


  
    // delay(250);                 // slow it down for debug
}
