/*
 * WiiChuckDemo -- 
 *
 * 2008 Tod E. Kurt, http://thingm.com/
 *
 */

#include <Wire.h>
#include "nunchuck_funcs.h"

int loop_cnt=0;

byte accx,accy,zbut,cbut;
int ledPin = 13;


void setup()
{
    Serial.begin(9600);
    nunchuck_setpowerpins();
    nunchuck_init(); // send the initilization handshake
    
    Serial.print("WiiChuckDemo ready\n");
}

void loop()
{
        loop_cnt = 0;

        nunchuck_get_data();

        accx  = nunchuck_joyx(); // ranges from approx 70 - 182
         
          if (accx>222){
              Serial.println('d');
  
          }
          if (accx<37){
          Serial.println('a');
          }
        accy  = nunchuck_joyy(); // ranges from approx 65 - 173
        
        if (accy>224){
         Serial.println('w');
        }
        
        if(accy<38){
        Serial.println('s');
        }
        zbut = nunchuck_zbutton();
        cbut = nunchuck_cbutton(); 
            
    
    loop_cnt++;
    delay(10);
}

