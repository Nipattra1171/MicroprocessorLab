unsigned int b=0b00000001;
void setup() {
  //pinmode 
  DDRD = 0xFF;
  DDRB = 0xFF;
  
  
}

void loop() {
  PORTD = b;
  if(b==0b10000000)
  {
    b=0b00000001;
    delay(500);
    PORTD = b;
    
  }
delay(500);
b=b<<1;
}
