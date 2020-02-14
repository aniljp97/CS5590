int led = 6;

void setup() {
  
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  
}

void loop() {
  
  int CDS = analogRead(A0);
  Serial.println(CDS);
  if (CDS > 50){
    
    digitalWrite(led, LOW);
    delay(5000);
    
  }
  
  else {
   
    digitalWrite(led, HIGH);
    delay(5000);
    
  }
}
