unsigned int b=0b00000001;
void setup() {
  //pinmode 
  DDRD = 0xFF;
  DDRB = 0xFF;
}

void loop() {
  PORTD = b;
  int d = analogRead(A0);
  delay(d);
  if(PINB==0x01&&b!=0b10000000)
  b=b<<1;
  if(PINB==0x02&&b!=0b00000001)
  b=b>>1;
}
