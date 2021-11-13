#include <Arduino.h>
#include <Servo.h>

Servo servo1;      
int angulo = 0;
int Eje_X = A1;//con solo un eje nos vale, usamos el que queramos, en este caso VRx al pin A1, eje x
int boton = 3; //al pin 3 conectar el SW del servo para el boton

void setup()
{
    servo1.attach(7); // Conectar servo1 al pin 7
    pinMode(boton, INPUT);
    digitalWrite(boton, HIGH);
    Serial.begin(9600);
}

void loop()
{
    angulo = map(analogRead(A1), 0, 1024, 0, 180);
    servo1.write(angulo);

    if (digitalRead(boton) == LOW)
    {
        Serial.println("Boton pulsado");
    }

    delay(100);
}