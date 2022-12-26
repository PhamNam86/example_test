  
  int LED1 = 13;
  int LED2 = 12;
  int LED3 = 11;

#define LM35 A0


float lm_value;
float tempc;

void setup() 
{ 
  Serial.begin(9600);
  pinMode(13,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
 
 }

 void loop()
 { 
  

  lm_value = analogRead(LM35);//Reading data from the sensor. This voltage is stored as a 10 bit number
  //tempc = (5.0 * lm_value * 1000.0)/(1024*10);
    tempc = lm_value/2.046;

 
    Serial.print("Temperature = ");
    Serial.print(tempc);
    Serial.print("*C");
    //Serial.print(tempc);
    Serial.println("");
    delay(1000);

 
  if(tempc >= 40)
  {
digitalWrite(LED1,HIGH);
digitalWrite(LED2,LOW);
digitalWrite(LED3,LOW);
}
if(20 < tempc && tempc < 40)
{
digitalWrite(LED2,HIGH);
digitalWrite(LED1,LOW);
digitalWrite(LED3,LOW);
 }
  if(tempc <= 20)
  {
digitalWrite(LED3,HIGH);
digitalWrite(LED1,LOW);
digitalWrite(LED2,LOW);

}
}
