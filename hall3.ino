//this code measures the difference between two rising edges of the digitalised signal coming from hall sensor and then prints the rpm.
//pin A0 is the signal pin
 int refsig=200;//for converting the analog signal coming from hall sensor to digital through arduino code
 int val;//the digital value of the incoming analog signals
 int prev_val=0;
 unsigned long t,cur_t;//time variables
 void setup()
 {
   Serial.begin(115200);
   pinMode(A0,INPUT);
 }
 void loop()//Measure RPM
 {
  int sig=analogRead(A0);//read raw value of hall sensor
  if(sig>refsig) val=HIGH;//convert it to digital 0,1 form
  else val=LOW;
  if(prev_val==0 && val==1) {//check for rising edge
    cur_t=micros();
    Serial.println(1000000*60/(cur_t-t));//print the rpm
    t=micros();
  }
   prev_val=val;
   
 }
