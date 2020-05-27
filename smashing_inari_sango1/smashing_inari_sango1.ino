#include <LiquidCrystal.h>

//Declaraciones de variables globales
int trig=6;
int echo=7;
int buz=9;
int rojo=10;
int verde=13;
float tiempo,distancia;


LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
  lcd.begin(16, 2); // Configurar el número de columnas y filas de la pantalla LCD
  
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buz, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(verde, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  
  digitalWrite(trig,LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  tiempo=pulseIn(echo,HIGH);//mide el ancho del echo en us
  //distancia = 340m/s x tiempo/2  porque el tiempo es ida y vuelta
  distancia=tiempo/58.2;//Distancia en cm
  lcd.setCursor(0, 1);
  lcd.print("DISTANCIA");
  
  
  if(distancia < 10)
  {
    Serial.println(distancia);
    digitalWrite(buz,1);
    
    lcd.setCursor(0, 0);
    lcd.print(distancia);
    lcd.print(" cm");
    
    lcd.setCursor(0, 1);
    lcd.print("OBSTACULO");
    digitalWrite(verde, LOW);
    digitalWrite(rojo, HIGH); //encendemos el led rojo como advertencia
    
    delay(500);
    lcd.clear();
  }
  else
  {
    
    Serial.println(distancia);
    
    digitalWrite(buz,0);
    
    lcd.setCursor(0, 0);
    lcd.print(distancia);
    lcd.print(" cm");
    digitalWrite(verde, HIGH); //encendemos el led verde para decir que es una distancia segura
    digitalWrite(rojo, LOW);  //apagamos el led rojo 
    
    delay(500);
    lcd.clear();
  }
}
 