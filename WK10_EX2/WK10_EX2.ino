#define INT_PIN 2
#define PWM 3
#define IN1 A1
#define IN2 A2

int count = 0;
int i,j;

void setup()
{
  pinMode(INT_PIN,INPUT_PULLUP);
  pinMode(PWM,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  
  attachInterrupt(digitalPinToInterrupt(INT_PIN),encoder,RISING);
  Serial.begin(9600);
  direction(1);
  speed(1);
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

void encoder()
{
  count++;
  Serial.println(count);
}
