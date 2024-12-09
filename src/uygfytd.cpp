#include <Arduino.h>

// Association des entrées du L298N aux sorties utilisées sur notre Arduino Uno
#define borneENA 10
#define borneIN1 9
#define borneIN2 8
#define borneIN3 7
#define borneIN4 6
#define borneENB 5

// Constantes du programme
#define delaiChangementVitesse 20
#define vitesseMinimale 60
#define vitesseMaximale 255

const char MARCHE_AVANT = 'V';
const char MARCHE_ARRIERE = 'R';

// Variables du programme
int vitesse;
void configurerSensDeRotationPontA(char sensDeRotation);
void changeVitesseMoteurPontA(int nouvelleVitesse);


void setup() {
  pinMode(borneENA, OUTPUT);
  pinMode(borneIN1, OUTPUT);
  pinMode(borneIN2, OUTPUT);
  pinMode(borneIN3, OUTPUT);
  pinMode(borneIN4, OUTPUT);
  pinMode(borneENB, OUTPUT);
}

void loop() {
  configurerSensDeRotationPontA(MARCHE_AVANT);
  for (vitesse = vitesseMinimale; vitesse < vitesseMaximale; vitesse++) {
    changeVitesseMoteurPontA(vitesse);
    delay(delaiChangementVitesse);
  }
  for (vitesse = vitesseMaximale; vitesse > vitesseMinimale; vitesse--) {
    changeVitesseMoteurPontA(vitesse);
    delay(delaiChangementVitesse);
  }
  changeVitesseMoteurPontA(0);
  delay(1000);

  configurerSensDeRotationPontA(MARCHE_ARRIERE);
  for (vitesse = vitesseMinimale; vitesse < vitesseMaximale; vitesse++) {
    changeVitesseMoteurPontA(vitesse);
    delay(delaiChangementVitesse);
  }
  for (vitesse = vitesseMaximale; vitesse > vitesseMinimale; vitesse--) {
    changeVitesseMoteurPontA(vitesse);
    delay(delaiChangementVitesse);
  }
  changeVitesseMoteurPontA(0);
  delay(1000);
}

void configurerSensDeRotationPontA(char sensDeRotation) {
  if (sensDeRotation == MARCHE_AVANT) {
    digitalWrite(borneIN1, HIGH);
    digitalWrite(borneIN2, LOW);
  } else if (sensDeRotation == MARCHE_ARRIERE) {
    digitalWrite(borneIN1, LOW);
    digitalWrite(borneIN2, HIGH);
  }
}

void changeVitesseMoteurPontA(int nouvelleVitesse) {
  analogWrite(borneENA, nouvelleVitesse);
}