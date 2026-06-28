// =====================================================
// PROJET MAISON ECOLOGIQUE INTELLIGENTE - CODE FINAL (4 modules fusionnes)
// =====================================================
#include <ESP32Servo.h>

// --- Objets Servo ---
Servo servoLDR;
Servo servoRain;

// --- Broches capteurs et actionneurs ---
// Suivi lumiere
const int LDRPin1 = 35;  // LDR gauche (ADC1)
const int LDRPin2 = 33;  // LDR droite (ADC1)

// PIR + LED
const int PIR_PIN = 18;  // Detection mouvement
const int LED_PIN = 25;  // Indicateur LED

// Niveau d'eau + relais pompe
const int capteurEauPin = 34; // Capteur eau (ADC1)
const int relaisPin     = 15; // Sortie relais
const int seuilBas      = 600; // Seuil niveau bas

// Capteur pluie
const int PluiePin       = 32; // Entree capteur pluie
const int SERVO_RAIN_PIN = 19; // Servo pluie (deplace pour eviter conflit avec PIR_PIN)

// Variables de mesure
int valeurLDR1, valeurLDR2;
int angleConverti;
int valeurPluie;
int currentAngle;
int valeurEau;
int pirState;

void setup() {
  Serial.begin(115200);

  // Initialisation des servos
  servoLDR.attach(13);
  servoRain.attach(SERVO_RAIN_PIN);
  servoLDR.write(90);
  currentAngle = 90;
  servoRain.write(currentAngle);

  // Configuration PIR + LED
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Configuration relais pompe
  pinMode(relaisPin, OUTPUT);
  digitalWrite(relaisPin, LOW);

  // Configuration capteur pluie
  pinMode(PluiePin, INPUT);

  Serial.println("Systeme pret");
}

void loop() {
  // 1) Suivi de la lumiere (LDR)
  valeurLDR1 = analogRead(LDRPin1);
  valeurLDR2 = analogRead(LDRPin2);
  Serial.print("LDR1: "); Serial.print(valeurLDR1);
  Serial.print("  LDR2: "); Serial.println(valeurLDR2);

  int diffLDR = valeurLDR1 - valeurLDR2;
  angleConverti = map(diffLDR, -150, 150, 70, 110);
  servoLDR.write(angleConverti);
  Serial.print("Servo LDR angle: "); Serial.println(angleConverti);

  // 2) Detection de mouvement (PIR) + LED
  pirState = digitalRead(PIR_PIN);
  if (pirState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println("Mouvement detecte -> LED ON");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println("Pas de mouvement -> LED OFF");
  }

  // 3) Niveau d'eau + pompe
  valeurEau = analogRead(capteurEauPin);
  Serial.print("Niveau eau: "); Serial.println(valeurEau);
  if (valeurEau > seuilBas) {
    digitalWrite(relaisPin, HIGH);
    Serial.println("Niveau bas -> Pompe ON");
  } else {
    digitalWrite(relaisPin, LOW);
    Serial.println("Niveau OK -> Pompe OFF");
  }

  // 4) Capteur pluie + servo
  valeurPluie = digitalRead(PluiePin);
  Serial.print("Pluie: "); Serial.println(valeurPluie);
  if (valeurPluie == HIGH) {
    currentAngle = 0;
    Serial.println("Pluie detectee -> Fermeture");
  } else {
    currentAngle = 120;
    Serial.println("Pas de pluie -> Ouverture");
  }
  servoRain.write(currentAngle);
  Serial.print("Servo pluie angle: "); Serial.println(currentAngle);

  delay(500);
}
