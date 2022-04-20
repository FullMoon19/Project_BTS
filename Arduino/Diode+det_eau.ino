int niveau_eau=0;
int Broche_EN_01 =5; 
int Broche_SN_01 =6; 
void setup() {
 Serial.begin(9600);
 pinMode(Broche_EN_01,INPUT);
 pinMode(Broche_SN_01,OUTPUT);
}

void loop() {
niveau_eau=digitalRead(Broche_EN_01);
Serial.print("niveau_eau= ");
Serial.println(niveau_eau,DEC);
delay(500);

if (digitalRead(Broche_EN_01)==0) {
  digitalWrite(Broche_SN_01,HIGH);
 /* delay(1000);
  digitalWrite(Broche_SN_01,LOW);
  delay(1000);*/
  } 

else {digitalWrite(Broche_SN_01,LOW);}
}