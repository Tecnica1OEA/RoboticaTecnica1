#include <SoftwareSerial.h>// libreria serial
SoftwareSerial BT(10,11);   //asigna pines a usar para receptor y transmisor 10 rx y 11 tx
// ULTIMA VERSION
int x;
int y;
int pot;
char dir;

void setup() {
  Serial.begin(9600);  //comunica consola con mibt  
  Serial.println("Joystick transmitiendo...");
  BT.begin(115200);    //velocidad de comunicacion 
  while(!Serial){
    ;
  }
}

void loop() {

  dir = 'Z'; // Iniciamos el joystick en 'Z' para que ejecute la función detener()
  x = analogRead(A0); // Capturamos los valores de los ejes del joystick analogico
  y = analogRead(A1); // basados en dos potenciometros en eje X y eje Y. 
  Serial.print("X: ");
  Serial.println(x);
  Serial.print("Y: ");
  Serial.println(y);
 
  if (x >= 0 && x < 480){ // avanzar
    pot = map(x,480,0,0,100);
    Serial.println("Avanzar");
    if(pot > 0 && pot < 20)
      dir = 'A';  
    else if(pot > 20 && pot < 40)
      dir = 'B';
    else if(pot > 40 && pot < 60)
      dir = 'C';
    else if(pot > 60 && pot < 80)
      dir = 'D';
    else
      dir = 'E';
    BT.write(dir);
    Serial.println(dir);
  }
  
  if (x > 540 && x <= 1023){ // retroceder
    Serial.println("Retroceder");
    pot = map(x,540,1023,0,100);
    if(pot > 0 && pot < 20)
      dir = 'F';  
    else if(pot > 20 && pot < 40)
      dir = 'G';
    else if(pot > 40 && pot < 60)
      dir = 'H';
    else if(pot > 60 && pot < 80)
      dir = 'I';
    else
      dir = 'J';
    BT.write(dir);
    Serial.println(dir);
  }

  if (y >= 0 && y < 480){ // derecha
    Serial.println("Derecha");
    pot = map(x,480,0,0,100);
    if(pot > 0 && pot < 20)
      dir = 'K';  
    else if(pot > 20 && pot < 40)
      dir = 'L';
    else if(pot > 40 && pot < 60)
      dir = 'N';
    else if(pot > 60 && pot < 80)
      dir = 'M';
    else
      dir = 'O';
    BT.write(dir);
    Serial.println(dir);
  }
  
  if (y > 540 && y <= 1023){ // izquierda
    Serial.println("Izquierda");
    pot = map(x,540,1023,0,100);
    if(pot > 0 && pot < 20)
      dir = 'P';  
    else if(pot > 20 && pot < 40)
      dir = 'Q';
    else if(pot > 40 && pot < 60)
      dir = 'R';
    else if(pot > 60 && pot < 80)
      dir = 'S';
    else
      dir = 'T';
    BT.write(dir);
    Serial.println(dir);
  }

  if ((x > 480 && x < 540) && (y > 480 && y < 540)){
    Serial.println("Detener");
    dir = 'Z';
    BT.write(dir);
    Serial.println(dir);
  }
 
}
 
