import processing.serial.*;


import ddf.minim.*;

Minim minim;
AudioSample kick;
AudioSample snare;
AudioSample Cymbal;
AudioSample drum;

Serial port;
String myString = null;
int valor=0;

void setup()
{
  port = new Serial(this, Serial.list()[0], 9600);
  size(512, 200, P3D);
  minim = new Minim(this);
  if (port.available() > 0)
  {
     myString = port.readStringUntil(10);
  }
  kick = minim.loadSample( "drum.wav", 512);
  
  snare = minim.loadSample("SD.wav", 512);
  
  Cymbal = minim.loadSample("Cymbal.wav",512);

  drum = minim.loadSample("kick.wav",512);
    
}

void draw() {
  // check if there is something new on the serial port
  while (port.available() > 0) {
    // store the data in myString 
    myString = port.readStringUntil(10);
    // check if we really have something
    if (myString != null) {
      myString = myString.trim(); // let's remove whitespace characters
      // if we have at least one character...
      if(myString.length() > 0) {
        println(myString); // print out the data we just received
        
        int x = parseInt(myString);
        
        if(x>10 && x<50){
          Cymbal.trigger();
          delay(50);
          myString=null;
          x =0;
        }
        if(x>50 && x<100){
          snare.trigger();
          x =0;
          myString=null;
          delay(50);
          
        }
        if(x>150 && x<200){
          drum.trigger();
          x =0;
          myString=null;
          delay(150);
          
        }
        if(x>100 && x<150){
          kick.trigger();
          x =0;
          myString=null;
          delay(150);
         
        }
    
      }
    }
  }
}
