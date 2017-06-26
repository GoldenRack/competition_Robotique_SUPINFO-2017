int trigg = 34;
int echo = 35;

void distance() { 
  float rep;
  float dist;
  digitalWrite(trigg, LOW);
  delay(2);
  digitalWrite(trigg, HIGH);
  delay(10);
  digitalWrite(trigg, LOW);
  rep = pulseIn(echo,HIGH);
  dist = (rep/58)*10;    
  Serial.print(dist);
  Serial.println("mm");
}

void setup() {
  Serial.begin(9600);
 
  pinMode(trigg, OUTPUT);
  pinMode(echo, INPUT);

 
  digitalWrite(trigg, LOW);
}

void loop(){
  distance();    
  }
