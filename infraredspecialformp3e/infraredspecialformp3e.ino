/* YourDuino.com Example Software Sketch
 IR Remote Kit Test
 Uses YourDuino.com IR Infrared Remote Control Kit 2
 http://arduino-direct.com/sunshop/index.php?l=product_detail&p=153
 based on code by Ken Shirriff - http://arcfn.com
 Get Library at: https://github.com/shirriff/Arduino-IRremote
 Unzip folder into Libraries. RENAME folder IRremote
 terry@yourduino.com 
 1838t infrared recever data is lugged into 11
RGB leds have resistors 22ohm's
 editied by mumbles - john.edmondson-uk.com* 
 */

/*-----( Import needed libraries )-----*/

#include "IRremote.h"

/*-----( Declare Constants )-----*/
int receiver = 11; // pin 1 of IR receiver to Arduino digital pin 11
int redPin = 5; // red channel of rgb common annod led
int greenPin = 6;// green channel of rgb common annod led
int bluePin = 7;// blue channel of rgb common annod led
int val=0;   

/*-----( Declare objects )-----*/
IRrecv irrecv(receiver);           // create instance of 'irrecv'
decode_results results;            // create instance of 'decode_results'
/*-----( Declare Variables )-----*/


void setup()   /*----( SETUP: RUNS ONCE )----*/

 
{
  Serial.begin(9600);
  Serial.println("IR Receiver Raw Data + Button Decode Test");
  irrecv.enableIRIn(); // Start the receiver
  
}/*--(end setup )---*/


void loop()   /*----( LOOP: RUNS CONSTANTLY )----*/
{
  if (irrecv.decode(&results)) // have we received an IR signal?

  {
//    Serial.println(results.value, HEX);  UN Comment to see raw values
    translateIR(); 
    irrecv.resume(); // receive the next value
  }  
}/* --(end main loop )-- */

/*-----( Declare User-written Functions )-----*/
void setColor(int red, int green, int blue)
{
  
  analogWrite(redPin, 255-red);
  analogWrite(greenPin, 255-green);
  analogWrite(bluePin, 255-blue);  
}

void translateIR() // takes action based on IR code received

// describing Car MP3 IR codes 

{

  switch(results.value)

  {

 case 0xFFA25D:   
 setColor(0, 0, 0);  // OFF
Serial.println(" OFF            "); 
   break;

  case 0xFF629D:  
   Serial.println(" MODE            "); 
   setColor(255, 255, 0);// yellow
  break;
 
 case 0xFFE21D:  
   Serial.println(" MUTE           "); 
 setColor(255, 0, 255); // purple

break;

 case 0xFF22DD:  
   Serial.println(" blue      "); 
    setColor(0, 255, 255);// aqua

 break;
 
   
 case 0xFF02FD:  
  Serial.println(" BACK          "); 
{ 
  // fade in from min to max in increments of 5 points:
  for(int fadeValue = 0 ; fadeValue <= 255; fadeValue +=5) { 
    // sets the value (range from 0 to 255):
    analogWrite(redPin, fadeValue); 
 analogWrite(greenPin, fadeValue); 
 analogWrite(bluePin, fadeValue);  
    // wait for 30 milliseconds to see the dimming effect    
    delay(30);                            
  } 
 break;
    

case 0xFFC23D:  
Serial.println(" FORWAD     "); 
 break;

 case 0xFFE01F:  
   Serial.println(" EQ         ");
   
    break;

case 0xFFA857:  
    Serial.println(" VOL-           "); 
    break;

 case 0xFF906F:  
   Serial.println(" VOL+             "); 
   break;

 case 0xFF6897:  
  Serial.println(" 0          "); 

  break;

 case 0xFF9867:  
   Serial.println(" Shuffle     aqua     "); 
   setColor(0, 255, 255);// aqua
   break;

 case 0xFFB04F:  
   Serial.println(" U/SD          "); 
   break;

  case 0xFF30CF:  
 Serial.println(" red             "); 
 setColor(255, 0, 0);
    break;

 case 0xFF18E7:  
   Serial.println("Green            "); 
  setColor(0, 255, 0); // green
   break;

case 0xFF7A85:  
  Serial.println(" 3              "); 
setColor(0, 0, 255); // blue
   break;

  case 0xFF10EF:  
    Serial.println(" 4              "); 
    break;

 case 0xFF38C7:  
    Serial.println(" 5              "); 
   break;

  case 0xFF5AA5:  
    Serial.println(" 6              "); 
    break;

case 0xFF42BD:  
Serial.println(" 7              "); 
break;

 case 0xFF4AB5:  
  Serial.println(" 8              "); 
  break;

 case 0xFF52AD:  
 Serial.println(" 9              "); 
 break;

  default: 
    Serial.println(" other button   ");

  }

   // irrecv.resume(); // Receive the next value

  }
} //END translateIR



/* ( THE END ) */

