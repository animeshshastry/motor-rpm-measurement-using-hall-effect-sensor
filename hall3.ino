/*
Arduino Hall Effect Sensor Project
by Arvind Sanjeev
Please check out  http://diyhacking.com for the tutorial of this project.
DIY Hacking
*/


 volatile byte half_revolutions;
 unsigned int rpm;
 int refsig=200;
 unsigned long timeold;
 int val;
 int prev_val=0;
 int t,cur_t,count=0;
 void setup()
 {
   Serial.begin(115200);
   digitalWrite(0,HIGH);
   pinMode(A0,INPUT);
 }
 void loop()//Measure RPM
 {
  int sig=analogRead(A0);
  if(sig>refsig) val=HIGH;
  else val=LOW;
  if(prev_val==0 && val==1) {
    cur_t=micros();
    Serial.println(1000000*60/(cur_t-t));
    t=micros();
  }
   prev_val=val;
   
 }
