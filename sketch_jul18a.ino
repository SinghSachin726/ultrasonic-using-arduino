
int tonePin = 8;  
int trigPin = 6;    
int echoPin = 7;  
int duration; 
int distance; 
int E1=3; 
int I1=4; 
void setup() { 
  // put your setup code here, to run once: 

  Serial.begin(9600); 
 pinMode(trigPin, OUTPUT); 
  pinMode(echoPin, INPUT); 
  pinMode(tonePin, OUTPUT); 
  pinMode(E1, OUTPUT); 
  pinMode(I1, OUTPUT);  
}  
void loop() { 
  // put your main code here, to run repeatedly: 
 digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigPin, LOW); 
  duration = pulseIn(echoPin, HIGH); 
  distance = (duration/2) / 29.1;  
  if(distance < 30){ 
      Serial.print("Obstacle is in:  "); 
      Serial.print(distance); 
      Serial.println(" cm; "); 
      Serial.println("Warning!"); 
      analogWrite(E1, 200);  // Run in high speed 
    tone(tonePin, 200000, 300); 
}  
else{ 
      Serial.print("Obstacle is in:  "); 
      Serial.print(distance); 
      Serial.print(" cm; "); 
 
      Serial.println("You are safe!"); 
      //analogWrite(E1, 50);  // Run in low speed 
       //tone(tonePin, 1000, 200); 
}  
} 
