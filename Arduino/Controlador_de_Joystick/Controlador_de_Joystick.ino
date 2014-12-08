


int x;
int y;

int x_cero;
int y_cero;

int Sensibilidad=100;

void evaluarjoystick(){

  Serial.println();
  
  y= analogRead(A0);
  Serial.println(y);
  
  x= analogRead(A1);
  Serial.println(x);  
  
  if (x>x_cero+Sensibilidad){

    Serial.println('d');
    
  }

  if (x<x_cero-Sensibilidad){

    Serial.println('a');

  }

  if (y>y_cero+Sensibilidad){

    Serial.println('w');

  }

  if (y<y_cero-Sensibilidad){

    Serial.println('s');

  }




}

void setup (){

  Serial.println();
  
  y_cero= analogRead(A0);
  Serial.println(y_cero);
  
  x_cero= analogRead(A1);
  Serial.println(x_cero);
  
  Serial.begin(9200);


}

void loop (){
  
  evaluarjoystick();
  
  delay (1000);

}

