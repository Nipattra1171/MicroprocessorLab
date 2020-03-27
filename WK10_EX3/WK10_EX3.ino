#define INT_PIN1 2 //Ch A
#define INT_PIN2 3 //Ch B
#define PWM 5
#define IN1 A1
#define IN2 A2

int count = 0;
int i,j;

void setup()
{
  pinMode(INT_PIN1,INPUT_PULLUP);
  pinMode(INT_PIN2,INPUT_PULLUP);
  pinMode(PWM,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(INT_PIN1),encoder_A,RISING);
  //attachInterrupt(digitalPinToInterrupt(INT_PIN1),encoder_B,RISING);
  Serial.begin(9600);
  direction(1);  //<3
  speed(1); //<3
}

void loop()
{
  if(Serial.available()>0)
  {
    String a = Serial.readString();
    speed(a.toInt());
    direction(a.toInt());
  }
  
}

void direction(int a)
{
  if(a<0)
  {
    digitalWrite(A1,LOW);
    digitalWrite(A2,HIGH);
  }
  else
  {
    digitalWrite(A1,HIGH);
    digitalWrite(A2,LOW);
  }
}

void speed(int b)
{
  analogWrite(PWM,absolute(b));
}

int absolute(int t)
{
  if(t<0)
  {
    return t*-1;
  }
  else
  {
    return t;
  }
}

void encoder_A()
{
  if(digitalRead(INT_PIN1) == 1 && digitalRead(INT_PIN2) == 0) //Ch A is HIGH. Ch B is LOW.
  {
    Serial.println("Left");
  }
  else
  {
    Serial.println("Right");
  }
  count++;
}
