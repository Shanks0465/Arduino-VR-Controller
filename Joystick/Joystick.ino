#define joyX A0
#define joyY A1
 
void setup() {
  Serial.begin(9600);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  int xValue = analogRead(joyX);
  int yValue = analogRead(joyY);

  //write the values with to plot or view
  if(xValue==0){
    Serial.write(1);
    Serial.flush();
    delay(20);
  }
  else if(xValue>670){
    Serial.write(0);
    Serial.flush();
    delay(20);
    }
  else if(yValue==0){
  Serial.write(3);
  Serial.flush();
  delay(20);
  }
  else if(yValue>670){
  Serial.write(4);
  Serial.flush();
  delay(20);
  }
  else{
    Serial.write(2);
    Serial.flush();
    delay(20);
  }
  }
