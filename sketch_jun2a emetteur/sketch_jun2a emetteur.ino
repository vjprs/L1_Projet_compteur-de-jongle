#include <LoRa.h>

const int forcePin = A0; // Pin du capteur de force
int threshold = 300; // Seuil de détection de la force
int count = 0; // Compteur de force détectée

void setup() {
  LoRa.begin(433E6); // Initialisation du module LoRa avec la fréquence de communication
}

void loop() {
  int forceValue = analogRead(forcePin); // Lecture de la valeur du capteur de force
  if (forceValue > threshold) { // Si la force détectée est supérieure au seuil
    count++; // Incrémentation du compteur
    String message = String(count); // Conversion du compteur en chaîne de caractères
    LoRa.beginPacket(); // Début de l'envoi du paquet
    LoRa.print(message); // Envoi du message
    LoRa.endPacket(); // Fin de l'envoi du paquet
    delay(1000); // Délai d'une seconde avant de détecter une nouvelle force
  }
}
