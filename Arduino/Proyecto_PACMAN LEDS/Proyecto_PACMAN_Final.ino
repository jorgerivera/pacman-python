#define LED1 7
#define LED2 8 
#define LED3 9
#define LED4 10
#define LED5 11
#define LED6 12

unsigned long proximoCambio=0;
unsigned long intervalo=500;
void setup () {
  Serial.begin(9600);
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
}

int estadoME=1;
char data = '\0';

int estadoMP=1;

// La variable personaje indica cual personaje se ha seleccionado
// - si es 0, no se ha seleccionado ningun personaje
// - si es 1, 2, 3 o 4, se ha seleccionado uno de los fantasmas
// - si es 9 o 10, se ha selecionado un Pacman
int personaje = 0;
int patron = 0;

int estadoP=1;



void loop(){
  MPatrones();
  if(Serial.available()>0){
    data=Serial.read();
    switch (data) {
    case '1':
      personaje = 1;
      digitalWrite(LED1, HIGH);
      digitalWrite(LED6, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);

      break;
    case '2':
      personaje = 2;
      digitalWrite(LED2, HIGH);
      digitalWrite(LED1, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);

      break;
    case '3':
      personaje = 3;
      digitalWrite(LED3, HIGH);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);

      break;
    case '4':
      personaje = 4;
      digitalWrite(LED4, HIGH);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED6, LOW);
      digitalWrite(LED5, LOW);

      break;

    case '5':
      patron = 1;
      estadoME = 1;
      break;
    case '6':
      patron = 2;
      estadoME = 1;
      break;
    case '7':
      patron = 3;
      estadoME = 1;
      break;
    case '8':
      patron = 4;
      estadoME = 1;
      break;

    case '9':
      personaje = 9;
      digitalWrite(LED5, HIGH);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED6, LOW);
      break;
    case '0':
      personaje = 10;
      digitalWrite(LED6, HIGH);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      break;


    default:
      estadoME = 1;
      break;
    }
  }
}

void MPatrones(){
  switch(estadoP){
  case 1:
    if (personaje>0){
      Serial.println(personaje,DEC);
      digitalWrite(LED6, LOW);
      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      
      switch(personaje){
      case 1:
      digitalWrite(LED1, HIGH);
      break;
      
      case 2:
      digitalWrite(LED2, HIGH);
      break;
      
      case 3:
      digitalWrite(LED3, HIGH);
      break;
      
      case 4:
      digitalWrite(LED4, HIGH);
      break;
      
      case 9:
      digitalWrite(LED5, HIGH);
      break;
      
      case 0:
      digitalWrite(LED6, HIGH);
      break;
      
    }
    estadoP=2;
    break;
    }
  case 2:
    if (patron!=0){
      switch(patron){
      case 1:
        estadoP=3;
        break;
      case 2:
        estadoP=4;
        break;
      case 3:
        estadoP=5;
        break;
      case 4:
        estadoP=6;
        break;
      }

      break;

    case 3:
      //Patrón de inicializaación del juego.

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);


      proximoCambio=millis()+intervalo; 
      estadoP=30;

    case 30:
      if(millis()>proximoCambio){
        estadoP = 31;
      }
      break;

    case 31:

      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      proximoCambio=millis()+intervalo; 
      estadoP=32;
      break;

    case 32:

      if(millis()>proximoCambio){
        estadoP = 33;
      }
      break;

    case 33: 

      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
      proximoCambio=millis()+intervalo; 
      estadoP=34;
      break;

    case 34:

      if(millis()>proximoCambio){
        estadoP = 35;
      }
      break;
    case 35:

      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
      proximoCambio=millis()+intervalo; 
      estadoP=36;
      break;
    case 36:

      if(millis()>proximoCambio){
        estadoP = 37;
      }
      break;

    case 37:

      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      proximoCambio=millis()+intervalo; 
      estadoP=38;
      break;
    case 38:      
      if(millis()>proximoCambio){
        estadoP = 39;
      }
      break;
    case 39:

      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      proximoCambio=millis()+intervalo; 
      estadoP=391;
      break;
    case 391:
      if(millis()>proximoCambio){
        estadoP = 392;
      }
      break;
    case 392:

      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      proximoCambio=millis()+intervalo; 
      estadoP=1;
      patron = 0;
      break;



    case 4:
      //Patrón aplicado al perder Pacman.

      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);


      proximoCambio=millis()+intervalo; 
      estadoP=40;

    case 40:
      if(millis()>proximoCambio){
        estadoP = 41;
      }
      break;
    case 41:

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      proximoCambio=millis()+intervalo; 
      estadoP=42;
      break;
    case 42:

      if(millis()>proximoCambio){
        estadoP = 43;
      }
      break;

    case 43:

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, LOW);
      proximoCambio=millis()+intervalo; 
      estadoP=44;
      break;
    case 44:

      if(millis()>proximoCambio){
        estadoP = 45;
      }
      break;
    case 45:

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, LOW);
      proximoCambio=millis()+intervalo; 
      estadoP=46;
      break;
    case 46:

      if(millis()>proximoCambio){
        estadoP = 47;
      }
      break;
    case 47:

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      proximoCambio=millis()+intervalo; 
      estadoP=48;
      break;
    case 48:      
      if(millis()>proximoCambio){
        estadoP = 49;
      }
      break;
    case 49:

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      proximoCambio=millis()+intervalo; 
      estadoP=491;
      break;
    case 491:
      if(millis()>proximoCambio){
        estadoP = 492;
      }
      break;
    case 492:

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      proximoCambio=millis()+intervalo; 
      estadoP=1;
      patron=0;
      break;




    case 5:
      //Partón de reconocimiento del joystick o nunchuck.

      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);


      proximoCambio=millis()+intervalo; 
      estadoP=50;

    case 50:
      if(millis()>proximoCambio){
        estadoP = 51;
      }
      break;
    case 51:

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      proximoCambio=millis()+intervalo; 
      estadoP=52;
      break;
    case 52:

      if(millis()>proximoCambio){
        estadoP = 53;
      }
      break;

    case 53:

      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      proximoCambio=millis()+intervalo; 
      estadoP=54;
      break;
    case 54:

      if(millis()>proximoCambio){
        estadoP = 55;
      }
      break;
    case 55:

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      proximoCambio=millis()+intervalo; 
      estadoP=56;
      break;
    case 56:

      if(millis()>proximoCambio){
        estadoP = 57;
      }
      break;
    case 57:

      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, HIGH);
      proximoCambio=millis()+intervalo; 
      estadoP=58;
      break;
    case 58:      
      if(millis()>proximoCambio){
        estadoP = 59;
      }
      break;
    case 59:

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);

      proximoCambio=millis()+intervalo; 
      estadoP=1;
      patron=0;
      break;


    case 6:
      //

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);


      proximoCambio=millis()+intervalo; 
      estadoP=60;

    case 60:
      if(millis()>proximoCambio){
        estadoP = 61;
      }
      break;
    case 61:

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
      proximoCambio=millis()+intervalo; 
      estadoP=62;
      break;
    case 62:

      if(millis()>proximoCambio){
        estadoP = 63;
      }
      break;

    case 63:

      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, LOW);
      proximoCambio=millis()+intervalo; 
      estadoP=64;
      break;
    case 64:

      if(millis()>proximoCambio){
        estadoP = 65;
      }
      break;
    case 65:

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, HIGH);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, HIGH);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, HIGH);
      proximoCambio=millis()+intervalo; 
      estadoP=66;
      break;
    case 66:

      if(millis()>proximoCambio){
        estadoP = 67;
      }
      break;
    case 67:

      digitalWrite(LED1, HIGH);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, HIGH);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, HIGH);
      digitalWrite(LED6, LOW);
      proximoCambio=millis()+intervalo; 
      estadoP=68;
      break;
    case 68:      
      if(millis()>proximoCambio){
        estadoP = 69;
      }
      break;
    case 69:

      digitalWrite(LED1, LOW);
      digitalWrite(LED2, LOW);
      digitalWrite(LED3, LOW);
      digitalWrite(LED4, LOW);
      digitalWrite(LED5, LOW);
      digitalWrite(LED6, LOW);
      proximoCambio=millis()+intervalo; 
      estadoP=1;
      patron=0;
      break;

    }
  }
}


