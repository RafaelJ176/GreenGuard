const int blue25 = 6;    
const int green50 = 2;   
const int yellow75 = 3;  
const int red100 = 5;    
const int Pump = 8;      
const int SoilSensor = A0; // Analog pin connected to the soil moisture sensor

// Moisture level thresholds
const int threshold25 = 500;  // Below 500 
const int threshold50 = 700;  // Between 500-700 
const int threshold75 = 900;  

void setup()
{
  Serial.begin(9600);  // Initialize serial communication for debugging
  pinMode(blue25, OUTPUT);   // Set LED pins as output
  pinMode(green50, OUTPUT);
  pinMode(yellow75, OUTPUT);
  pinMode(red100, OUTPUT);
  pinMode(Pump, OUTPUT);  // Set pump pin as output
}

void ledReset() {
  // Turn off all LEDs before setting the new state
  digitalWrite(blue25, LOW);
  digitalWrite(green50, LOW);
  digitalWrite(red100, LOW);
  digitalWrite(yellow75, LOW);
}

void loop()
{
  int SensorValue = analogRead(SoilSensor);  // Read soil moisture level from sensor
  delay(3000);  // Wait for stable sensor reading
  Serial.print("value is\n");
  Serial.println(SensorValue);  // Print sensor value for debugging

  if (SensorValue < threshold25) {  // If soil is too wet (below 25% moisture)
    ledReset();
    digitalWrite(blue25, HIGH);  // Turn on blue LED to indicate wet soil
  }

  else if ((SensorValue > threshold25) && (SensorValue < threshold50)) { // 25%-50% moisture level
    ledReset();
    digitalWrite(green50, HIGH);  // Turn on green LED
    digitalWrite(Pump, HIGH);  // Activate pump
    Serial.println("Pump State : On\n");
    delay(400);  // Run pump for 0.4 seconds
    digitalWrite(Pump, LOW);  // Turn off pump
    Serial.println("0.4 Sec\n");
    Serial.println("Pump State : Off\n");
  }

  else if ((SensorValue > threshold50) && (SensorValue < threshold75)) { // 50%-75% moisture level
    ledReset();
    digitalWrite(yellow75, HIGH);  // Turn on yellow LED
    digitalWrite(Pump, HIGH);  // Activate pump
    Serial.println("Pump State : On\n");
    delay(600);  // Run pump for 0.6 seconds
    digitalWrite(Pump, LOW);  // Turn off pump
    Serial.println("0.6 Sec\n");
    Serial.println("Pump State : Off\n");
  }

  else if (SensorValue > threshold75) {  // If soil is too dry (above 75%)
    ledReset();
    digitalWrite(red100, HIGH);  // Turn on red LED
    digitalWrite(Pump, HIGH);  // Activate pump
    Serial.println("Pump State : On\n");
    delay(800);  // Run pump for 0.8 seconds
    digitalWrite(Pump, LOW);  // Turn off pump
    Serial.println("0.8 Sec\n");
    Serial.println("Pump State : Off\n");
  }

  delay(300000);  // Wait for 5 minutes before the next reading
}
