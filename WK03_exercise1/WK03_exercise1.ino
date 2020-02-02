int clk_pin=9;
int latch_pin=10;
int data_pin=8;
int b=0b000000001;
int i;

void setup()
{
  pinMode(clk_pin,OUTPUT);
  pinMode(latch_pin,OUTPUT);
  pinMode(data_pin,OUTPUT);
}

void loop()
{
for (i=0;i<16;i++)
{
  
  digitalWrite(data_pin,(b>>(i)&0x01));
  delay(100);
  digitalWrite(clk_pin, HIGH);
  delay(100);
  digitalWrite(clk_pin, LOW);
  digitalWrite(latch_pin,HIGH);
  delay(10);
  digitalWrite(latch_pin,LOW);
  delay(10);
}

}
