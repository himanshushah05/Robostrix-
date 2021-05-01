int firepin = 6;
int obstaclepin = 8;
int buzzpin = 5;
int relaypin = 2;
void setup() {
  // put your setup code here, to run once:
pinMode(buzzpin, OUTPUT);
pinMode(firepin,INPUT);
pinMode(obstaclepin,INPUT);
pinMode(relaypin,OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int fire_val = digitalRead(firepin);
int obstacle_val = digitalRead(obstaclepin);
Serial.println(fire_val);
Serial.println(obstacle_val);
delay(100);

if (fire_val==HIGH || obstacle_val==LOW){
  digitalWrite(buzzpin,HIGH);
  delay(100);
  digitalWrite(buzzpin,LOW);
  delay(100);
  digitalWrite(relaypin,LOW);
  
  delay(1000);
}
else{
     //NO fire and no obstacle
     digitalWrite(relaypin,HIGH);
     digitalWrite(buzzpin,LOW);
     
}

}
