const int analogIn = A0;
int humiditysensorOutput = 0;
int RawValue=0;
double Voltage = 0;
double tempC = 0;
double tempF = 0;
void setup(){
  Serial.begin(9600);
  pinMode(A1, INPUT);
}
void loop(){
  RawValue = analogRead(analogIn);
  Voltage = (RawValue / 1023.0) * 5000;
  tempC = (Voltage-500) * 0.1;
  tempC = (tempC * 1.8) + 32;
  Serial.print("Raw Value = ");
  Serial.print(RawValue);
  Serial.print("\t milli volts = ");
  Serial.print(Voltage,0);
  Serial.print("\t Temperature in C = ");
  Serial.print(tempC,1);
  Serial.print("\t Temperature in F = ");
  Serial.print(tempF,1);
  humiditysensorOutput = analogRead(A1);
  Serial.print("Humidity:");
  Serial.print(humiditysensorOutput);
  Serial.print("%");
  delay(5000);
}
