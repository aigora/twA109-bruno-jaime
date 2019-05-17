

//inputs del Arduino
const int Pad1 = A0;
const int Pad2 = A1;
const int Pad3 = A2;
const int Pad4 = A3;

const int valorumbral = 380;// valor a partir del cual el programa 
                           //detectara que el sensor envía información

//variables par los datos de cada sensor
int Tam1_val = 0;
int Tam2_val = 0;
int Tam3_val = 0;
int Tam4_val = 0;


int signalTest2 = 0;
int signalTest1 = 0;
int signalTest3 = 0;
int signalTest4 = 0;





void setup()
{

  //empieza la comunicación con arduino
  Serial.begin(9600); 
}

void loop()
{ 
  /sensor 1/
  if(analogRead(Pad1) >=valorumbral) 
  {
  signalTest1 = 1;
  }

  if(signalTest1 == 1 && analogRead(Pad1) <= (valorumbral-100))
  {
    Tam1_val= 145;      //se le asigna un valor al sensor 1 para que 
                        //processing sepa que el sonido le corresponde al sensor 1
    Serial.println(Tam1_val);
    signalTest1 = 0;
  }
  //sensor 2
  if(analogRead(Pad2) >= valorumbral) 
  {
  signalTest2 = 1;
  } 
  Tam2_val = analogRead(Pad2);
  if(signalTest2 == 1 && analogRead(Pad2) <= (valorumbral-95))
  {
   Tam2_val= 195;

    Serial.println(Tam2_val);  
    signalTest2 = 0;
  }

  //sensor 3
  if(analogRead(Pad3) >= valorumbral) 
  {
  signalTest3 = 1; 
  }
  Tam3_val = analogRead(Pad3);
  if(signalTest3 == 1 && analogRead(Pad3) <= (valorumbral-95))
  {
   Tam3_val= 95;
   
    Serial.println(Tam3_val);
    signalTest3 = 0;
  }

  //Sensor 4
  if(analogRead(Pad4) >= valorumbral) 
  {
  signalTest4 = 1; 
  }
  if(signalTest4 == 1 && analogRead(Pad4) <= (valorumbral-95))
  {
   Tam4_val= 45;
      
    Serial.println(Tam4_val);  
    signalTest4 = 0;
  }
  delay(1);    
}
