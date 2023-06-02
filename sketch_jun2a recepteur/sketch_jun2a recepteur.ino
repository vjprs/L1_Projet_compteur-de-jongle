#include <LoRa.h>

const int ledPin = 13; // Pin de la LED

void setup() {
  LoRa.begin(433E6); // Initialisation du module LoRa avec la fréquence de communication
  pinMode(ledPin, OUTPUT); // Configuration de la pin de la LED en sortie
}

void loop() {
  if (LoRa.available()) { // Si des données sont disponibles
    String message = "";
    while (LoRa.available()) {
      message += (char)LoRa.read(); // Lecture du message reçu
    }
    digitalWrite(ledPin, HIGH); // Allumage de la LED
    delay(1000); // Délai d'une seconde pour afficher l'information
    digitalWrite(ledPin, LOW); // Extinction de la LED
    Serial.println(message); // Affichage du message sur le moniteur série
  }
}
