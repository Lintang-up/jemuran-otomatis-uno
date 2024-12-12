// Sensor Hujan
int sensor_hujan = A0;
int nilai_sensor;

// Servo
#include <Servo.h>
Servo myServo;
#define pin_servo 3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Sensor Hujan  
  pinMode(sensor_hujan, INPUT);
  // Servo
  myServo.attach(pin_servo); 
}

void loop() {
  // put your main code here, to run repeatedly:
  nilai_sensor = analogRead(sensor_hujan);
  Serial.print("Nilai Sensor Hujan: ");
  Serial.println(nilai_sensor);

  if (nilai_sensor > 800){
      Serial.println("Sensor Mendeteksi Terang\n");
      // servo keluar teras
      myServo.write(0);
  }
  else{
      Serial.println("Sensor Mendeteksi Hujan\n");
      // servo masuk ke teras
      myServo.write(90);
  }
  delay(100);
}
