#include <ESP8266WiFi.h>;

#include <WiFiClient.h>;

#include <ThingSpeak.h>;
#include<DHT.h>
#define DHTTYPE DHT11

const char* ssid = "BsrQ-UmVkbWk1QQ"; //Your Network SSID

const char* password = "Himanshu"; //Your Network Password

int val;
int irpin = 0;
int trackpin = 13;
int dhtpin = 14;
int firepin = 10;
int shockpin = 4;
int tiltpin =12;

int LDRpin = A0; //LDR Pin Connected at A0 Pin



WiFiClient client;

unsigned long myChannelNumber = 1377104; //Your Channel Number (Without Brackets)

const char * myWriteAPIKey = "W3XXIQ5O1PXYQQWY"; //Your Write API Key

void setup()
{

  pinMode(irpin,INPUT);
  pinMode(trackpin,INPUT);
  pinMode(firepin,INPUT); 
  pinMode(shockpin,INPUT);
  pinMode(tiltpin, INPUT);
//  DHT dht(dhtpin,DHTTYPE);
//  dht.begin();
  Serial.begin(115200);

delay(10);

// Connect to WiFi network

WiFi.begin(ssid, password);



ThingSpeak.begin(client);

}void obstacle(){
  int obstacle_val = digitalRead(irpin);
  ThingSpeak.writeField(myChannelNumber, 1,fire_val, myWriteAPIKey); //Update in ThingSpeak
  delay(100);
}

void temp_hum(){
  DHT dht(dhtpin,DHTTYPE);
  dht.begin();
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  Serial.print("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(t); 
  Serial.println("C  ");
  delay(800);
  ThingSpeak.writeField(myChannelNumber, 2,h, myWriteAPIKey); //Update in ThingSpeak
  delay(100);
  ThingSpeak.writeField(myChannelNumber, 3,t, myWriteAPIKey); //Update in ThingSpeak
  delay(100);
}
void tracking(){
  int track_val = digitalRead(trackpin);
  ThingSpeak.writeField(myChannelNumber, 4,track_val, myWriteAPIKey); //Update in ThingSpeak
  delay(100);
  if (track_val==HIGH){
    //tracker is on the black route  
  }
  else{
    //tracker is off the route
  }
}
void firecheck(){
  int fire_val = digitalRead(firepin);
  ThingSpeak.writeField(myChannelNumber, 5,fire_val, myWriteAPIKey); //Update in ThingSpeak
  delay(100);
  if (fire_val==HIGH){
    //fire detected
  }
  else{
    //no fire    
}
}
void shock_check(){
  int shock_val = digitalRead(shockpin);
  ThingSpeak.writeField(myChannelNumber, 6,shock_val, myWriteAPIKey); //Update in ThingSpeak
  delay(100);
  if (shock_val==HIGH){
    //shock detected
  }
  else{
    //NO shock
  }
}
void tilt(){
  int tilt_val = digitalRead(tiltpin);
  ThingSpeak.writeField(myChannelNumber, 7,tilt_val, myWriteAPIKey); //Update in ThingSpeak
  delay(100);
  if (tilt_val==HIGH){
    //not tilted
  }
  else{
    //tilted
  }
}
//void Move()
//{
//   long temp = ThingSpeak.readLongField(counterChannelNumber, FieldNumber1, myCounterReadAPIKey);
//  statusCode = ThingSpeak.getLastReadStatus();
//  if (statusCode == 200)
//  {
//    if(temp==1)
//    {
//      // Function to run Motor forward
//    }
//    else if(temp==2)
//    {
//      //Function to run Motor backward
//    }
//    else
//    {
//      //Stop Motor
//    }
//  }
//  else
//  {
//    Serial.println("Unable to read");
//    Serial.println("or No internet!");
//  }
//  delay(100);
//}




void loop()

{

//val = digitalRead(); //Read Analog values and Store in val variable
obstacle();
temp_hum();
tracking();
firecheck();
shock_check();
tilt();
//Move();
Serial.print(val); //Print on Serial Monitor

delay(1000);

ThingSpeak.writeField(myChannelNumber, 1,val, myWriteAPIKey); //Update in ThingSpeak
delay(100);

}
