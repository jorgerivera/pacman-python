
int x;
int y;

int x_cero;
int y_cero;

int Sensibilidadx=400;
int Sensibilidady=200;

void evaluarjoystick(){

   
  y= analogRead(A0);
    
  x= analogRead(A1);
    
  if (x>x_cero+Sensibilidadx){

    Serial.print('d');
    
  } else if (x<x_cero-Sensibilidadx){

    Serial.print('a');

  } else

  if (y>y_cero+Sensibilidady){

    Serial.print('w');

  } else if (y<y_cero-Sensibilidady){

    Serial.print('s');

  }
}

void evaluarBotones(){

   if (digitalRead(3)==LOW){
    Serial.print("Start");
  }
  if (digitalRead(4)==LOW){
    Serial.print("Pausa");
  }
if (digitalRead(5)==LOW){
    Serial.print('L');
  }
if (digitalRead(6)==LOW){
    Serial.print('K');
  }
if (digitalRead(7)==LOW){
    Serial.print("J");
  }  
  if (digitalRead(8)==LOW){
    Serial.print('I');
  }
  if (digitalRead(9)==LOW){
    Serial.print('O');
  }
}

void setup (){

  y_cero= analogRead(A0);
  
  x_cero= analogRead(A1);
  
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
  
  evaluarBotones();
}

