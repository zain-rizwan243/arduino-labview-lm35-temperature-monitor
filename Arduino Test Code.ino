//pinout
int Temp_pin=A0;
//int LED_blue =2;
//int LED_green =3;
//int LED_yellow=4;
//int LED_red=5;

void setup() {
  // put your setup code here, to run once:
  pinMode(Temp_pin,INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensor_value=analogRead(Temp_pin);
  float mv=(sensor_value/1024.0)*5000;
  float cel=mv/10;
  Serial.print("Temperature = ");
  Serial.print(cel);
  Serial.print("C");

  if(cel<=15){
    //digitalWrite(LED_blue,HIGH); 
    Serial.println("  (Temp. is Cool)");
  }
  else if(cel<=25){
    //digitalWrite(LED_green,HIGH);
    Serial.println("  (Temp. is Moderate)");
  }
  else if(cel<=40){
    //digitalWrite(LED_yellow,HIGH);
    Serial.println("  (Temp. is Hot)");
  }
  else if(cel>40){
    //digitalWrite(LED_red,HIGH);
    Serial.println("  (Temp. is Very Hot)");
  }
  delay(3000);

}
