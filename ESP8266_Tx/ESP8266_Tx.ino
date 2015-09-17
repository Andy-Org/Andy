
/*
* My First Attempt at a fully automated wifi Connect and Sending of Data...
* TO: ThingSpeak, sending 560
*/

#include <SoftwareSerial.h>

#define rxPin 10
#define txPin 11

#define SSID "Catch Herpies"
#define PASS "afafafafaf"
#define IP "184.106.153.149" // thingspeak.com
String GET = "GET /update?key=JNK02OQHDJ5U1UIK&field1=";

SoftwareSerial wifi = SoftwareSerial(rxPin, txPin); // RX, TX

void setup()
{
 // Setup Serial Monitor
 Serial.begin(9600);
 
 // Setup the BUAD Rate and Reset the ESP
 wifi.begin(9600);
 wifi.println("AT+RST");
 // Debug Reset - Waiting
 Serial.println("AT+RST (5K ms)");
 delay(5000);

 // Connect to AP
 connectwifi();

 // Setup the Actual Data to send
 int tenmpF = 3100;

 // Ping the Server and Send the damn Data
 String cmd = "AT+CIPSTART=\"TCP\",\"";
 cmd += IP;
 cmd += "\",80";
 wifi.println(cmd);
 delay(2000);
 if(Serial.find("Error")){
   // Debug we fucked up
   Serial.println("FAILED TO SEND");
   return;
 }
 cmd = GET;
 cmd += tenmpF;
 cmd += "\r\n";
 wifi.print("AT+CIPSEND=");
 wifi.println(cmd.length());
 if(wifi.find(">")){
   wifi.print(cmd);
   // Debug URL Sent
   Serial.println("URL Sent");
 }else{
   wifi.println("AT+CIPCLOSE");
   // Debug Conn Closing
   Serial.println("Closing WiFi Connection Now!");
 }  

 
}

void loop(){



}

void updateTemp(String tenmpF){
 String cmd = "AT+CIPSTART=\"TCP\",\"";
 cmd += IP;
 cmd += "\",80";
 wifi.println(cmd);
 delay(2000);
 if(Serial.find("Error")){
   return;
 }
 cmd = GET;
 cmd += tenmpF;
 cmd += "\r\n";
 wifi.print("AT+CIPSEND=");
 wifi.println(cmd.length());
 if(wifi.find(">")){
   wifi.print(cmd);
 }else{
   wifi.println("AT+CIPCLOSE");
 }
}


boolean connectwifi(){
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
   // Debug Successfully Connected
   Serial.println("Connected to AP");
   return true;
 }else{
   return false;
 }
}
