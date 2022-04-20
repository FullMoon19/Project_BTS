#include "DHT.h"  
#define DHT_Broche 2  
#define DHTTYPE DHT22  

DHT dht(DHT_Broche, DHTTYPE);  

int sensor_pin = A0;
int sensor_pin1 = A1;
int output_value0;
int output_value1;
int Num_A_acq =5;
int niveau_eau=0;
int Broche_EN_01 =5; 
int Broche_SN_01 =6;
int Broche_SN_02 =3;
float Temperature;
int Broche_Action = 13;
int Broche_Action1 = 12;
int Seuil = 20;

//Parameters
const int aihPin  = A0;
const int aihMargin  = 0;
const int aihThresh  = 306;

//Variables
int aihVal  = 0;
bool aihHystOn  = 0;

//******* SETUP **************  
void setup() {  
 Serial.begin(9600); 
 Serial.println("DHT22 test!");  dht.begin();  
Serial.begin(9600);
   Serial.println("Reading From the Sensor ...");
   delay(2000);
   Serial.print(String(Temperature)); 
   Serial.println(" °C");
   delay(2000);
   
    Serial.begin(9600);
 pinMode(Broche_EN_01,INPUT);
 pinMode(Broche_SN_01,OUTPUT);
 pinMode(Broche_SN_02,OUTPUT);
 pinMode(Broche_Action , OUTPUT);    // configure la broche 13 en SORTIE
 pinMode(Broche_Action1 , OUTPUT);    // configure la broche 12 en SORTIE

  //Init Serial USB
  Serial.begin(9600);
  Serial.println(F("Initialize System"));
  //Init AnalogHyst
  pinMode(aihPin, INPUT);
}  
// ******* LOOP *************  
void loop() {  
 digitalWrite(Broche_SN_02,HIGH);
 
 delay(300); // Remarque : la lecture de la température et humidité nécessite 250 ms  
 float Humidite = dht.readHumidity();  
 float Temperature = dht.readTemperature();  
 if (isnan(Humidite) || isnan(Temperature)) // isnan : nombre ? || : OU 
 {  
 Serial.println(" Echec de lecture des données du capteur DHT !");  
 return;  
 }  
// Facultatif : commande d’une action par relais si Humidité > 60% ou Température > 40°C   
 
 Serial.print("Humidité air: ");  
 Serial.print(Humidite);  
 Serial.print(" %\t");  
 Serial.print("Température: ");  
 Serial.print(Temperature);  
 Serial.println(" *C ");  
 output_value0= analogRead(sensor_pin);
   output_value0 = map(output_value0,1023,0,0,100);
   Serial.print("Humidité : ");
   Serial.print(output_value0);
   Serial.print("%          Humidité :");
   Serial.print(output_value1);
   Serial.println("%");
   delay(2000);
   output_value1= analogRead(sensor_pin1);
   output_value1 = map(output_value1,1023,0,0,100);
   
  
   niveau_eau=digitalRead(Broche_EN_01);
Serial.print("niveau_eau= ");
Serial.println(niveau_eau,DEC);
digitalWrite(Broche_SN_02,LOW);
delay(500);

if (digitalRead(Broche_EN_01)==0) {
  digitalWrite(Broche_SN_01,HIGH);
  digitalWrite(Broche_Action1 , LOW);
  digitalWrite(Broche_Action , LOW);
  } 
else {digitalWrite(Broche_SN_01,LOW);
  if (output_value0 <= Seuil){
    digitalWrite(Broche_Action , HIGH);} 
  if (output_value1 <= Seuil){
    digitalWrite(Broche_Action1 , HIGH);}  
  delay(2000);         
  if (output_value0 <= Seuil){
    digitalWrite(Broche_Action , LOW);}
  if (output_value1 <= Seuil){
    digitalWrite(Broche_Action1 , LOW);}       
  delay(2000); }

Serial.println("   ");
delay(100);

  }

