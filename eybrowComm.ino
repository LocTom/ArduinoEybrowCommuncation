int hallPin = A0; // linear Hall analog interface
int analogVal;      // analog readings
int led = 13 ;       // LED
int potPin = A5;    // select the input pin for the potentiometer
int val = 0;       // variable to store the value coming from the sensor
int buzzer = 7; // set the buzzer control digital IO pin
//int analogT = A3;
//int ana=0;
void setup ()
{
  pinMode(hallPin, INPUT);
  pinMode(potPin, INPUT);
  pinMode(led,OUTPUT); 
  pinMode(buzzer,OUTPUT);
  


  Serial.begin(9600);
}
 

void loop ()
{
  val = analogRead(potPin)/2+100;    // read the value from the potentionmeter
  // Read the analog interface
  analogVal = analogRead(hallPin); // read the value from the sensor
  //ana=analogRead(analogT);
  Serial.println(val); 
 Serial.print(",");
  Serial.println(analogVal);
  //Serial.print(",");
  //Serial.println(ana);
  
  if(analogVal<val)
  {
    delay(50);
    analogVal = analogRead(hallPin); //checks to see if it still is raised
     // ana=analogRead(analogT);
  if(analogVal<val){
      digitalWrite(led,HIGH);
      digitalWrite(buzzer,HIGH);
      //delay(20);
    }
  }
  else
  {
    digitalWrite(led,LOW);
    digitalWrite(buzzer,LOW);
   // delay(100);
   // digitalWrite(buzzer,HIGH);
  }

  delay(100);
}
