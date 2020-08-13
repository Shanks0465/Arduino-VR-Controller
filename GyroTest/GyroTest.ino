/*
ADXL335
note:vcc-->5v ,but ADXL335 Vs is 3.3V
The circuit:
      5V: VCC
analog 1: x-axis
analog 2: y-axis
analog 3: z-axis
*/
#define xpin A3 // z-axis (only on 3-axis models)
#define ypin A4
#define zpin A5
#define joyX A0
#define joyY A1


void setup()
{
 // initialize the serial communications:
 Serial.begin(9600);
}
void loop()
{
 int x = analogRead(xpin);  //read from xpin
 
 int y = analogRead(ypin);  //read from ypin
 
 int z = analogRead(zpin);  //read from zpin
 int xValue = analogRead(joyX);
 int yValue = analogRead(joyY);

 
float zero_G = 512.0; //ADC is 0~1023  the zero g output equal to Vs/2
                      //ADXL335 power supply by Vs 3.3V
float scale = 102.3;  //ADXL335330 Sensitivity is 330mv/g
                       //330 * 1024/3.3/1000 

float xval=((float)x - 331.5)/65*9.8;
float yval=((float)y - 329.5)/68.5*9.8;
int move;
int cur;
if(xval>2.5){
  move=1;
}
else if(xval<-2.5){
  move=5;
  }
else if(yval<-2.5){
move=3;
}
else if(yval>2.5){
move=4;
}
else if ((yval>-2.5 && yval<2.5)&&(xval<2.5 && xval>-2.5) ){
  move=2;
}
if(xValue==0){
    cur=1;
  }
  else if(xValue>670){
    cur=0;
    }
  else if(yValue==0){
  cur=3;
  }
  else if(yValue>670){
  cur=4;
  }
  else{
    cur=2;
  }
Serial.write(move*10+cur);
Serial.flush();
 delay(20);
}
