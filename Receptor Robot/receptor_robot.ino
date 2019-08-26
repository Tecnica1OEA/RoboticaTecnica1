#include <SoftwareSerial.h> // libreria serial
SoftwareSerial BT(10,11);
//ULTIMA VERSION
#define Ena 9
#define In1 8
#define In2 7
#define In3 6
#define In4 5
#define Enb 4
#define led1 3
#define led2 2
char dir;

void setup(){
  Serial.begin(9600);
  BT.begin(115200);
  pinMode(Ena,OUTPUT);
  pinMode(In1,OUTPUT); 
  pinMode(In2,OUTPUT); 
  pinMode(In3,OUTPUT);
  pinMode(In4,OUTPUT);
  pinMode(Enb,OUTPUT);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  analogWrite(Ena,0);
  analogWrite(Enb,0);

  for(int i = 0; i < 10; i++){
  digitalWrite(led1, HIGH);
  digitalWrite(led2, LOW);
  delay(200);
  digitalWrite(led1, LOW);
  digitalWrite(led2, HIGH);
  delay(200);
  }
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  
  while(!Serial){
    ;
  }
}

void loop(){

  if (BT.available()) {   //lee BT y envia data al arduino
    dir = BT.read();
    
    if (dir == 'Z'){
      Serial.println("Frenar");
      analogWrite(Ena,0);
      digitalWrite(In1, HIGH);
      digitalWrite(In2, LOW);
      analogWrite(Enb,0);
      digitalWrite(In3, LOW);
      digitalWrite(In4, HIGH);
    }
    
    if (dir >= 'A' && dir <= 'E'){
      Serial.println("Avanzar");
      if(dir == 'A'){
        avanzar(51); 
      } 
      else if(dir == 'B')
        avanzar(102);
      else if(dir == 'C')
        avanzar(153);
      else if(dir == 'D')
        avanzar(204);
      else
        avanzar(255);      
    }

    if (dir >= 'F' && dir <= 'J'){
      Serial.println("Retroceder");
      if(dir == 'F')
        retroceder(51);  
      else if(dir == 'G')
        retroceder(102);
      else if(dir == 'H')
        retroceder(153);
      else if(dir == 'I')
        retroceder(204);
      else
        retroceder(255);      
    }

    if (dir >= 'K' && dir <= 'O'){
      Serial.println("Derecha");
      if(dir == 'K')
        derecha(51);  
      else if(dir == 'L')
        derecha(102);
      else if(dir == 'N')
        derecha(153);
      else if(dir == 'M')
        derecha(204);
      else
        derecha(255);      
    }
    
    if (dir >= 'P' && dir <= 'T'){
      Serial.println("Izquierda");
      if(dir == 'P')
        izquierda(51);  
      else if(dir == 'Q')
        izquierda(102);
      else if(dir == 'R')
        izquierda(153);
      else if(dir == 'S')
        izquierda(204);
      else
        izquierda(255);      
    }
  } 
  Serial.println(dir);
}

void avanzar(int pot){  
  analogWrite(Ena, pot);
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(Enb, pot);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
}

void retroceder(int pot){
  analogWrite(Ena, pot);
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(Enb, pot);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}

void derecha(int pot){  
  analogWrite(Ena, pot);
  digitalWrite(In1, HIGH);
  digitalWrite(In2, LOW);
  analogWrite(Enb, pot);
  digitalWrite(In3, HIGH);
  digitalWrite(In4, LOW);
}

void izquierda(int pot){  
  analogWrite(Ena, pot);
  digitalWrite(In1, LOW);
  digitalWrite(In2, HIGH);
  analogWrite(Enb, pot);
  digitalWrite(In3, LOW);
  digitalWrite(In4, HIGH);
}
