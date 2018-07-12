#include <Arduino.h>
int motorA1 = 3;
int motorA2 = 5;
int motorB1 = 6;
int motorB2 = 9;

int bluetooth = 2;
int estado_rec;
int velocidade = 200;
char estado;

void setup() {
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  pinMode(bluetooth, INPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(bluetooth) == LOW) {
    estado_rec = 'S';
  }

    if (Serial.available() > 0) {
      estado_rec = Serial.read();
      estado = estado_rec;
    }

      if (estado != 'S') {
        Serial.print(estado);
      }

  //MOVIMENTAÇÃO

  // frente.
  if (estado == 'F') {
    digitalWrite(motorB1, velocidade);
    digitalWrite(motorA1, velocidade);
    digitalWrite(motorA2, 0);
    digitalWrite(motorB2, 0);
  }

  else if (estado == 'I') {  // Frente Esquerda.
    digitalWrite(motorA1, 0);
    digitalWrite(motorA2, 0);
    digitalWrite(motorB1, velocidade);
    digitalWrite(motorB2, 0);
  }

  else if (estado == 'G') {   // Frente Direita.
    digitalWrite(motorA1, velocidade);
    digitalWrite(motorA2, 0);
    digitalWrite(motorB1, 0);
    digitalWrite(motorB2, 0);
  }

  else if (estado == 'B') { //trás.
    digitalWrite(motorA1, 0);
    digitalWrite(motorB1, 0);
    digitalWrite(motorB2, velocidade);
    digitalWrite(motorA2, velocidade);
  }

  else if (estado == 'H') {  //Trás Esquerda.
    digitalWrite(motorA1, 0);
    digitalWrite(motorA2, velocidade);
    digitalWrite(motorB1, 0);
    digitalWrite(motorB2, 0);
  }

  else if (estado == 'J') {  // Trás Direita.
    digitalWrite(motorA1, 0);
    digitalWrite(motorA2, 0);
    digitalWrite(motorB1, 0);
    digitalWrite(motorB2, velocidade);
  }

  else if (estado == 'L') {   // esquerda.
    digitalWrite(motorA1, velocidade);
    digitalWrite(motorA2, 0);
    digitalWrite(motorB1, 0);
    digitalWrite(motorB2, velocidade);
  }
  else if (estado == 'R') {   // Direita.
    digitalWrite(motorA1, 0);
    digitalWrite(motorA2, velocidade);
    digitalWrite(motorB1, velocidade);
    digitalWrite(motorB2, 0);
  }
  else if (estado == 'S') {   // parado.
    digitalWrite(motorA1, 0);
    digitalWrite(motorA2, 0);
    digitalWrite(motorB1, 0);
    digitalWrite(motorB2, 0);
  }

}
