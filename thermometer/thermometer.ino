// numbers -> pins
int number[10][8] = 
{
  {0,1,2,5,6,7,-1,-1},
  {2,7,-1,-1,-1,-1,-1,-1},
  {6,7,4,0,1,-1,-1,-1},
  {6,7,4,2,1,-1,-1,-1},
  {5,4,7,2,-1,-1,-1,-1},
  {6,5,4,2,1,-1,-1,-1},
  {6,5,4,2,1,0,-1,-1},
  {6,7,2,-1,-1,-1,-1,-1},
  {0,1,2,5,6,7,4,-1},
  {1,2,4,5,6,7,-1,-1}
};
// 
boolean screen[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
float tempC;
int temp;
void setup(){
  pinMode(2,OUTPUT);
  pinMode(3, OUTPUT);    // s0
  pinMode(4, OUTPUT);    // s1
  pinMode(5, OUTPUT);    // s2
  pinMode(9, OUTPUT);    // s2
  analogWrite(10,160);
  Serial.begin(9600);
}

void sync()
{
   for (int i=0; i < 16; i++)
   {
           
           
           digitalWrite(2, i % 2);
           digitalWrite(3, (i/2) % 2);
           digitalWrite(4, (i/4) % 2); 
           digitalWrite(5, (i/8) % 2); 
           
           if (screen[i])
           {
             
             digitalWrite(9,LOW);
             delay(1);
           }
           digitalWrite(9,HIGH);
           
           
   }
}

void loop () {
  
 if (millis() % 1000 == 0)
 {
  tempC = (5.220*analogRead(5)*100/1024);
  temp = (int)tempC;
  Serial.println(tempC);
  Serial.println(temp);
  
  int one = temp % 10;
  int ten = (temp - one) /10;
  for (int i=0; i < 16; i++)
    screen[i] = 0;
  for (int i=0; i <8; i++)
  {
      screen[number[one][i]+8] =1;
      screen[number[ten][i]] =1;
      
  }
 }
   sync();
 
    
}
