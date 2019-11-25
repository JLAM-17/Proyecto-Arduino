bool switch;

void setup() {
  pinMode(9,OUTPUT);  //Sensor ultrasonido por donde se manda el pulso
  pinMode(8,INPUT);   //Sensor de ultrasonido, donde se recibe el rebote
  pinMode(13,OUTPUT); //Enable del L293
  pinMode(12,OUTPUT); //Input 1 del L293
  pinMode(11,OUTPUT); //Input 2 del L293
  pinMode(5,OUTPUT);  //Salida para el Servo
  pinMode(4,INPUT);  //Entrada del switch
  
}

void loop() {
  switch = digitalRead(4);
  if (switch == HIGH){
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    
  }

}
