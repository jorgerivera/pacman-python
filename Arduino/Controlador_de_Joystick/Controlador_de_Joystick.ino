


int x;
int y;

int x_cero;
int y_cero;

int Sensibilidadx=400;
int Sensibilidady=200;

void evaluarjoystick(){

  //Serial.println();
  
  y= analogRead(A0);
  //Serial.println(y);
  
  x= analogRead(A1);
  //Serial.println(x);  
  
  if (x>x_cero+Sensibilidadx){

    Serial.println('d');
    
  } else if (x<x_cero-Sensibilidadx){

    Serial.println('a');

  } else

  if (y>y_cero+Sensibilidady){

    Serial.println('w');

  } else if (y<y_cero-Sensibilidady){

    Serial.println('s');

  }
}

void evaluarBotones(){

  //Serial.println(); 

  if (digitalRead(3)==LOW){
    Serial.println("Start");
  }
  if (digitalRead(4)==LOW){
    Serial.println("Pausa");
  }
if (digitalRead(5)==LOW){
    Serial.println('L');
  }
if (digitalRead(6)==LOW){
    Serial.println('K');
  }
if (digitalRead(7)==LOW){
    Serial.println("J");
  }  
  if (digitalRead(8)==LOW){
    Serial.println('I');
  }
  if (digitalRead(9)==LOW){
    Serial.println('O');
  }
}





void setup (){

  //Serial.println();
  
  y_cero= analogRead(A0);
  //Serial.println(y_cero);
  
  x_cero= analogRead(A1);
  //Serial.println(x_cero);
  
  Serial.begin(9600);
  
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  
}

void loop (){
  
  evaluarjoystick();
  
  //delay (1000);
  
  evaluarBotones();
}

