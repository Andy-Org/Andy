/*
* My First Attempt at a fully automated wifi Connect and Sending of Data...
* TO: ThingSpeak, sending 560
*/

#include <SoftwareSerial.h>

#define dFlag 1   // Debug Flag: 1 for Verbose, 0 for None

int tenmpF = 5000;  // MODIFY (FOR TESTING ONLY)

#define rxPin 10  // Arduino Mini RX Pin
#define txPin 11  // Arduino Mini TX Pin

#define SSID "Farshad"  // AP Name MODIFY
#define PASS "afafafafaf" // AP Password MODIFY
#define IP "184.106.153.149" // thingspeak.com
String GET = "GET /update?key=JNK02OQHDJ5U1UIK&field1="; // Modify ThingSpeak UPDATE KEY

SoftwareSerial wifi = SoftwareSerial(rxPin, txPin); // RX, TX

void setup()
{

  wifi.begin(9600); // Setup the BUAD Rate and Reset the ESP

 // Setup Serial Monitor, if dFlag is Set to 1
 if (dFlag == 1){
  Serial.begin(9600);
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

  // NOTHING IN HERE

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
  tone(5, 600, 1000);
  noTone(5);

   return true;
 }else{
  if (dFlag == 1){
    Serial.println("Failed to get OK from WiFi Connect");
  }
   return false;
 }
 
}
