#define DATA 2 //interrupt
#define CLK 10
#define LATCH 11

int timer1_counter;
int toggle = 1;
long data[10] = {111111101, 101100000, 111011010, 111110010, 101100111, 110110111
                , 110111111, 111100001, 111111111 , 111110111
               };
long temp;
int count=0;

void setLed(int a)
{
  digitalWrite(LATCH,LOW);
  temp=data[a];
  for(int i=0;i<8;i++)
  {
    digitalWrite(DATA,temp%10);
    digitalWrite(CLK,HIGH);
    digitalWrite(CLK,LOW);
    temp=temp/10;
  }
  digitalWrite(LATCH,HIGH);
}

void setup()
{
  pinMode(DATA,INPUT);
  pinMode(CLK,OUTPUT);
  pinMode(LATCH,OUTPUT);
  setLed(count);
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  
  timer1_counter = 1;   //62500 = delay(0);
  TCNT1 = timer1_counter; 
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << TOIE1);
  
  interrupts();
  
}

void loop()
{
  
}

ISR(TIMER1_OVF_vect)
{
  TCNT1 = timer1_counter;
  count++;
  if(count<=9)
  {
    setLed(count);
  }
  else
  {
    count = 0;
    setLed(count);
  }
}
