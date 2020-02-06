int sensorPin = A0;
int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
  //pinMode(13, OUTPUT);

  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(ledPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
//  digitalWrite(13,HIGH); //on
//  delay(200);
//  digitalWrite(13,LOW); //off
//  delay(200);

  int sensorValue = analogRead(A0);
  float voltage = sensorValue/1023.0*5;
  Serial.println(voltage);
  if(voltage>2.5)
  { digitalWrite(ledPin, HIGH);
  
  }
  else
  {
    digitalWrite(ledPin, LOW);
    }

}
