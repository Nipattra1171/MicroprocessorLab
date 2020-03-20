#define LED_PIN 9
#define INT_PIN 2

int timer1_counter;
int toggle =1;
int mode = 1;
int count = 0;

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(INT_PIN, INPUT);
  
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  
  timer1_counter = 1;   //62500 = delay(0);
  TCNT1 = timer1_counter; 
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << TOIE1);
  
  interrupts();
  
  attachInterrupt(digitalPinToInterrupt(INT_PIN),ISR_Callback,RISING);
  //external interrupt = use switch to change the speed of LED
}

void loop()
{
  
}

ISR(TIMER1_OVF_vect)
{
  TCNT1 = timer1_counter;
  if(count%mode==0)
  {
    digitalWrite(LED_PIN, toggle);
    toggle = !toggle;
  }
  count++;
  
}


//for external interrupt
void ISR_Callback()
{
  if(mode<3)
  {
    mode = mode + 1;
  }
  else
  {
    mode = 1;
  }
}
