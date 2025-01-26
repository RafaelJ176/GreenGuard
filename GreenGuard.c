const int blue25=6;
const int green50 = 2;
const int yellow75 = 3;
const int red100 = 5;
const int Pump = 8;
const int SoilSensor = A0;
const int threshold25 = 500;  
const int threshold50= 700;
const int threshold75 = 900;

void setup()
{
  Serial.begin(9600);
  pinMode(blue25,OUTPUT);
  pinMode(green50,OUTPUT);
  pinMode(yellow75,OUTPUT);
  pinMode(red100,OUTPUT);
  pinMode(Pump,OUTPUT);
}

void loop()
{
  int SensorValue = analogRead(SoilSensor);
  delay(3000);
  Serial.print("value is\n");
  Serial.println(SensorValue);

  if(SensorValue<threshold25){
    digitalWrite(blue25,HIGH);
    digitalWrite(green50,LOW);
    digitalWrite(red100,LOW);
    digitalWrite(yellow75,LOW);
  }

  else if ((SensorValue >threshold25) && (SensorValue<threshold50)){
    digitalWrite(green50,HIGH);
    digitalWrite(blue25,LOW);
    digitalWrite(red100,LOW);
    digitalWrite(yellow75,LOW);
    digitalWrite(Pump,HIGH);
    Serial.println("Pump State : On\n");
    delay(100);
    digitalWrite(Pump,LOW); 
    Serial.println("0.1 Sec\n");
    Serial.println("Pump State : Off\n");
  }
  else if((SensorValue >threshold50) && (SensorValue<threshold75)){
    digitalWrite(yellow75,HIGH);
    digitalWrite(green50,LOW);
    digitalWrite(red100,LOW);
    digitalWrite(blue25,LOW);
    Serial.println("Pump State : On\n");
    delay(200);
    digitalWrite(Pump,LOW); 
    Serial.println("0.2 Sec\n");
    Serial.println("Pump State : Off\n");
  }
  else if(SensorValue >threshold75){
    digitalWrite(red100,HIGH);
    digitalWrite(green50,LOW);
    digitalWrite(blue25,LOW);
    digitalWrite(yellow75,LOW);
    Serial.println("Pump State : On\n");
    delay(300);
    digitalWrite(Pump,LOW); 
    Serial.println("0.3 Sec\n");
    Serial.println("Pump State : Off\n");
  }


  delay(100000);
}