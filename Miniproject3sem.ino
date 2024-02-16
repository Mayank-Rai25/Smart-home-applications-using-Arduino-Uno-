#include <EEPROM.h>
#include <SoftwareSerial.h>
String inputs;
#define relay1 2 //Connect relay1 to pin 6
#define relay2 3 //Connect relay2 to pin 5
#define relay3 4 //Connect relay3 to pin 4
#define relay4 5 //Connect relay4 to pin 3

void setup()
{
Serial.begin(9600); //Set rate for communicating with phone
pinMode(relay1, OUTPUT); 
pinMode(relay2, OUTPUT); 
pinMode(relay3, OUTPUT); 
pinMode(relay4, OUTPUT); 

digitalWrite(relay1, LOW); 
digitalWrite(relay2, LOW); 
digitalWrite(relay3, LOW); 
digitalWrite(relay4, LOW); 

}
void loop()
{
while(Serial.available()) //Check if there are available bytes to read
{
delay(10); //Delay to make it stable
char c = Serial.read(); //Conduct a serial read
if (c == '#'){
break; //Stop the loop once # is detected after a word
}
inputs += c; //Means inputs = inputs + c
}
if (inputs.length() >0)
{
Serial.println(inputs);

if(inputs == "A")          // suppose 1st is BULB in the application and if ONN button is press then 'a' command goes to arduino and then BULB is onn otherwise if push OFF button the 'A' command goes to arduino and BULB is off
{ 
digitalWrite(relay1, LOW);   
}
else if(inputs == "a")
{
digitalWrite(relay1, HIGH);   
}
else if(inputs == "B")      // suppose 2nd is LED in the application and if ONN button is press then 'b' command goes to arduino and then LED is onn otherwise if push OFF button the 'B' command goes to arduino and LED is off 
{
digitalWrite(relay2, LOW);  
}  
else if(inputs == "b")
{
digitalWrite(relay2, HIGH);   
}
else if(inputs == "C")    // suppose 3rd is FAN in the application and if ONN button is press then 'c' command goes to arduino and then FAN is onn otherwise if push OFF button the 'C' command goes to arduino and FAN is off
{ 
digitalWrite(relay3, LOW);
}
else if(inputs == "c")
{
digitalWrite(relay3, HIGH);
}
else if(inputs == "D")
{
digitalWrite(relay4, LOW);   // suppose 4th is AC in the application and if ONN button is press then 'd' command goes to arduino and then AC is onn otherwise if push OFF button the 'D command goes to arduino and AC is off
}
else if(inputs == "d")
{
digitalWrite(relay4, HIGH);
}

inputs="";
}
}
