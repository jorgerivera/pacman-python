
#include "WiiChuck.h"
#include <Wire.h>


int X;
int Y;

int Xo;
int Yo;

int sens=1000;



void ParaJoystick(){
  
  Serial.println();
  
  X=analogRead

void Evento(int ?){
  
  if(Wire.available()>0){    //Para leer el buffer
    byte rec=Wire.read();  //Para almacenar el byte
    Serial.print(rec,HEX); //Para mostrarlo en la pantalla
  }
  Serial.println();
}

void setup(){
 
 Wire.begin(); //inicia el bus I2C 
 Wire.onReceive(Evento);
 Serial.begin(9600) 
}
