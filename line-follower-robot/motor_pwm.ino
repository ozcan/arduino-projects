
int speed = 200;
void setup () {
pinMode(5,OUTPUT);
pinMode(6,OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
}



void loop () {
boolean left=false,right=false,mid=false;

if (analogRead(0)> 700) left = true;
if (analogRead(1)> 700) mid = true;
if (analogRead(2)> 700) right= true;

if (left == true && mid == true && right == true)
{
  analogWrite(10,0);
  analogWrite(11,0);
  
  analogWrite(5,0);
  analogWrite(6,0);
}  
else if (left == false && mid == true && right == false)
{
  analogWrite(10,speed);
  analogWrite(11,0);
  
  analogWrite(5,speed);
  analogWrite(6,0);
}  
else if (left == true && mid == false && right == false)
{
  analogWrite(10,0);
  analogWrite(11,0);
  
  analogWrite(5,speed);
  analogWrite(6,0);
}    
else if (left == false && mid == false && right == true)
{
  analogWrite(10,speed);
  analogWrite(11,0);
  
  analogWrite(5,0);
  analogWrite(6,0);
}    
  
//  delay(50);
//  analogWrite(10,0);
//  analogWrite(11,0);
//  
//  analogWrite(5,0);
//  analogWrite(6,0);
//  analogWrite(10,speed);
//  analogWrite(11,0);
//
//  analogWrite(5,speed);
//  analogWrite(6,0);

}
