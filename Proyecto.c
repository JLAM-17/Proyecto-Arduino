#include <Servo.h>
#include <NewPing.h>
Servo servoMotor;
bool switch1;
int tiempo_medicion;
int distancia;
#define TRIGGER_PIN 9
#define ECHO_PIN 8
NewPing sonar(TRIGGER_PIN, ECHO_PIN);
void setup() {
  pinMode(9,OUTPUT);  //Sensor ultrasonido por donde se manda el pulso
  pinMode(8,INPUT);   //Sensor de ultrasonido, donde se recibe el rebote
  pinMode(13,OUTPUT); //Enable del L293
  pinMode(12,OUTPUT); //Input 1 del L293
  pinMode(11,OUTPUT); //Input 2 del L293
  servoMotor.attach(5);  //Salida para el Servo
  pinMode(4,INPUT);  //Entrada del switch
  
}

void loop() {
  switch1 = digitalRead(4);
  tiempo_medicion=sonar.ping_median();
  distancia = sonar.convert_cm(tiempo_medicion);
  if (switch1 == LOW){
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    servoMotor.write(90);
  }
  else if ((switch1 == HIGH) and distancia <=  8){
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    servoMotor.write(90);
  }
  else if ((switch1 == HIGH) and distancia > 8){
    digitalWrite(13,HIGH);
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    servoMotor.write(0);
  }
}
