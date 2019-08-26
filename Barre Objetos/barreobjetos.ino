//#include <SoftwareSerial.h> // libreria serial
#include <NewPing.h>
//SoftwareSerial miBT(10,11);

#define led 13
#define TRIGGER_PIN  33
#define ECHO_PIN     32
#define MAX_DISTANCE 200
#define S1 35
#define S2 34
#define Ena 9
#define In1 8
#define In2 7
#define In3 6
#define In4 5
#define Enb 4

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  //miBT.begin(115200);
  Serial.begin(9600);
  
  pinMode(S1, INPUT);
  pinMode(S2, INPUT);
  pinMode(Ena,OUTPUT);
  pinMode(In1,OUTPUT); 
  pinMode(In2,OUTPUT); 
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
  pinMode(Enb,OUTPUT);
  analogWrite(Ena,0);
  analogWrite(Enb,0);

  //Leds de encendido
  for(int i = 0; i < 10; i++){
    digitalWrite(led, HIGH);
    delay(200);
    digitalWrite(led, LOW);
    delay(200);
  }
  while(!Serial){
    ;
  }
  analogWrite(Ena, 60);
  analogWrite(Enb, 60);
}
void loop() {
  int v1 = digitalRead(S1);// Derecha
  int v2 = digitalRead(S2);// Izquierda

  if(v1 == 1 && v2 == 1){ // Detecta Blanco
    Serial.println("Blanco");
    adelante(60);
    int distancia = sonar.ping_cm();
    if (distancia < 5){
      adelante(80);
    }
  }else if(v1 == 0 && v2 == 0){ // Detecta Negro 
    Serial.println("Negro");
    atras();
    delay(750);
    girar();
    delay(2000);
  } else if(v2 == 1 && v1 == 0){ // Detecta sensor der Negro
    reversaIzq();
    delay(1000);
    girar();
    delay(2000);
  } else if(v2 == 0 && v1 == 1){ // Detecta sensor izq Negro
    reversaDer();
    delay(1000);
    girar();
    delay(2000);
   }
}

void reversaIzq(){
  analogWrite(Ena, 30);
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(Enb, 60);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}

void reversaDer(){
  analogWrite(Ena, 60);
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(Enb, 30);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}

   // ENA IZQ ENB DER
// adelante
void adelante(int pot){  
  analogWrite(Ena, pot);
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(Enb, pot);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
}

void atras(){
  analogWrite(Ena, 200);
  digitalWrite(In2, HIGH);
  digitalWrite(In1, LOW);
  analogWrite(Enb, 200);
  digitalWrite(In4, LOW);
  digitalWrite(In3, HIGH);
}

void izquierda(){
analogWrite(Ena, 30);
digitalWrite(In1, HIGH);
digitalWrite(In2, LOW);
analogWrite(Enb, 60);
digitalWrite(In3, HIGH);
digitalWrite(In4, LOW);
}

void derecha(){
      analogWrite(Ena, 60);
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
      analogWrite(Enb, 30);
      digitalWrite(In3, LOW);
      digitalWrite(In4, HIGH);

}

void frenar(){
  analogWrite(Ena, 0);
  digitalWrite(In2, HIGH);
  digitalWrite(In1, LOW);
  analogWrite(Enb, 0);
  digitalWrite(In4, HIGH);
  digitalWrite(In3, LOW);
}

void girar(){  
  analogWrite(Ena, 80);
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(Enb, 0);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}
