// Biblioteca do LCD
#include <LiquidCrystal.h>
LiquidCrystal tela(8,9,10,11,12,13);
// Sensor 01
int pino_trig1 = 2;
int pino_echo1 = 3;
// Sensor 02 
int pino_trig2 = 5;
int pino_echo2 = 4;
// Sensor 03
int pino_trig3 = 7;
int pino_echo3 = 6;
// Buzzer
int pino_buzzer = A5;


void setup() {
  Serial.begin (9600);
  tela.begin(16,2);
  pinMode(pino_trig1, OUTPUT);
  pinMode(pino_echo1, INPUT);
  pinMode(pino_trig2, OUTPUT);
  pinMode(pino_echo2, INPUT);
  pinMode(pino_trig3, OUTPUT);
  pinMode(pino_echo3, INPUT);
  pinMode(pino_buzzer, OUTPUT);
}

void loop() {
  float distanciasensor1 = distancia_sensor(pino_trig1,pino_echo1);
  
  if (distanciasensor1 > 0.15){
    tela.clear();
    tela.print("Proximo!");}
  else{
    float media_distancia = ((distancia_sensor(pino_trig2, pino_echo2) + distancia_sensor(pino_trig3, pino_echo3)) / 2) + distanciasensor1 + 0.2;
    tela.clear();
    if (media_distancia <= 2){
        digitalWrite(pino_buzzer, HIGH);
        tela.setCursor(0,1);
        tela.print("fique longe!");}
    else{
      digitalWrite(pino_buzzer, LOW);}
    tela.setCursor(0,0);
    tela.print(media_distancia);
    tela.print(" metros");}
    delay(400);}
    
float distancia_sensor(int pino_trigger,int pino_echo){
  // Checagem do estado inativo do pino trigger
  digitalWrite(pino_trigger, LOW);
  delay(2);
    
  // Ativação do pino Trigger
  digitalWrite(pino_trigger, HIGH);
  delay(10);
  digitalWrite(pino_trigger, LOW);
  
  // Recebimento do Echo(tempo de contagem do pulso)
  float tempo_do_ping = pulseIn(pino_echo, HIGH); 
  float distancia = (tempo_do_ping / 2) * 0.000344;
  return distancia;
  }
 
