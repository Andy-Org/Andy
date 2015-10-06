
/*
* My First Attempt at a fully automated wifi Connect and Sending of Data...
* TO: ThingSpeak, sending 560
*/

#include <SoftwareSerial.h>

#define rxPin 10
#define txPin 11
#define SerialBAUD 9600
#define WiFiBAUD 9600

int inPin = 7;   // choose the input pin (for a pushbutton)
int inPin2 = 8;   // choose the 2nd input pin (for a pushbutton)

#define dFlag 1   // DEBUG OUTPUT - Set 0 for None, 1 for Verbose

#define SSID "Farshad"
#define PASS "afafafafaf"
#define IP "184.106.153.149" // thingspeak.com
String GET = "GET /update?key=JNK02OQHDJ5U1UIK&field1="; // Modify ThingSpeak UPDATE KEY


// Setup Values to be Sent via URL

int tenmpC = 9000;
int tenmpD = 8000;
int tenmpF = 100;

SoftwareSerial wifi = SoftwareSerial(rxPin, txPin); // RX, TX

void setup()
{

  pinMode(inPin, INPUT);    // declare pushbutton as input
  pinMode(inPin2, INPUT);   // declare 2nd PB as input
  digitalWrite(inPin, HIGH);  // put inPin Low by default
  digitalWrite(inPin2, HIGH);  // put inPin2 Low by default
 
  wifi.begin(WiFiBAUD); // Setup the BUAD Rate and Reset the ESP
  
  // Setup Serial Monitor, if dFlag is Set to 1
  if (dFlag == 1){
  Serial.begin(SerialBAUD);
  Serial.println("");
  Serial.println("**********************************************");
  Serial.println("System Initializing."); 
  // Small delay to send RESET
  delay(2000); 



}
 

   
wifi.println("AT+RST");   // Send the RESET Command to ESP
if (dFlag == 1){
  Serial.println("AT+RST Sent... 5sec to Reset");
}

delay(5000);    // Wait for RESET to execute


connectwifi();    // Connect to AP



// Ping the Server and Send the damn Data
String cmd = "AT+CIPSTART=\"TCP\",\"";
cmd += IP;
cmd += "\",80";
wifi.println(cmd);

delay(2000);

if(Serial.find("Error")){

  if (dFlag == 1){
    Serial.println("FAILED TO SEND");
  }

return;
}
 
cmd = GET;
cmd += tenmpF;
cmd += "\r\n";

wifi.print("AT+CIPSEND=");
wifi.println(cmd.length());

if(wifi.find(">")){
  wifi.print(cmd);

  if (dFlag == 1){
    Serial.println("URL Sent");
  }
  
  }else{
  
  wifi.println("AT+CIPCLOSE");
  
  if (dFlag == 1){
    Serial.println("Closing WiFi Connection Now - which means you probably FAILED!");
  }

}  

 
}

void loop(){


  int val = digitalRead(inPin);  // read input value
  int val2 = digitalRead(inPin2);  // read input value


  if (val == HIGH) {         // check if the input is HIGH (button pushed)
    // DO NOTHING HERE
  } else if (val == LOW) {
    sendUrl1();
    Serial.println("Send URL #1");       // debug xCount
  }

  if (val2 == HIGH) {
    // DO NOTHING HERE
  } else if (val2 == LOW) {
    sendUrl2();
    Serial.println("Send URL #2");
  }

  
    delay(250);                 // slow it down for debug



}


boolean connectwifi(){
  if (dFlag == 1){
    Serial.println("Begin Connection to WiFi");
  }
 wifi.println("AT+CWMODE=1");
 delay(2000);
 String cmd="AT+CWJAP=\"";
 cmd+=SSID;
 cmd+="\",\"";
 cmd+=PASS;
 cmd+="\"";
 wifi.println(cmd);
 delay(5000);

 if(wifi.find("OK")){
   if (dFlag == 1){
    Serial.print("Now Connected to ");
    Serial.println(SSID);
   }

   return true;
 }else{
  if (dFlag == 1){
    Serial.println("Failed to get OK from WiFi Connect");
  }
   return false;
 }
 
}


void sendUrl(){
 String cmd = "AT+CIPSTART=\"TCP\",\"";
 cmd += IP;
 cmd += "\",80";
 wifi.println(cmd);
 delay(2000);
 if(Serial.find("Error")){
   return;
 }
 cmd = GET;
 cmd += tenmpC;
 cmd += "\r\n";
 wifi.print("AT+CIPSEND=");
 wifi.println(cmd.length());
 if(wifi.find(">")){
   wifi.print(cmd);
 }else{
   wifi.println("AT+CIPCLOSE");
   Serial.println("Done! SendUrl() Function");
 }
}

void sendUrl1(){
 String cmd = "AT+CIPSTART=\"TCP\",\"";
 cmd += IP;
 cmd += "\",80";
 wifi.println(cmd);
 delay(2000);
 if(Serial.find("Error")){
   return;
 }
 cmd = GET;
 cmd += tenmpC;
 cmd += "\r\n";
 wifi.print("AT+CIPSEND=");
 wifi.println(cmd.length());
 if(wifi.find(">")){
   wifi.print(cmd);
 }else{
   wifi.println("AT+CIPCLOSE");
   Serial.println("Done! SendUrl1() Function");
 }
}

void sendUrl2(){
 String cmd = "AT+CIPSTART=\"TCP\",\"";
 cmd += IP;
 cmd += "\",80";
 wifi.println(cmd);
 delay(2000);
 if(Serial.find("Error")){
   return;
 }
 cmd = GET;
 cmd += tenmpD;
 cmd += "\r\n";
 wifi.print("AT+CIPSEND=");
 wifi.println(cmd.length());
 if(wifi.find(">")){
   wifi.print(cmd);
 }else{
   wifi.println("AT+CIPCLOSE");
   Serial.println("Done! SendUrl2() Function");
 }
}
