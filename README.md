<div align="center">

# Maison Écologique Intelligente

### Environnement de développement ESP32 — Guide d'installation

*Configurez votre Arduino IDE et préparez-vous à programmer la carte ESP32 du projet, de zéro jusqu'au premier téléversement.*

---

</div>

## Aperçu

Ce guide vous accompagne pas à pas dans la configuration de votre environnement de développement sur Windows — de l'installation de l'Arduino IDE jusqu'au téléversement de votre premier programme sur l'ESP32. Aucune expérience préalable avec Arduino ou l'ESP32 n'est requise.

**Ce que vous allez installer :**

- Arduino IDE 2.3.7
- Pilote de communication USB (pour que votre PC reconnaisse la carte)
- Support de la carte ESP32 dans Arduino IDE
- Bibliothèque ESP32Servo (nécessaire pour le contrôle des moteurs et servomoteurs)

**Durée estimée :** 15 à 20 minutes

---

## Prérequis

Avant de commencer, assurez-vous de disposer des éléments suivants :

| Élément | Détails |
|---|---|
| Ordinateur | Windows 10 ou version ultérieure |
| Carte ESP32 | N'importe quel module ESP32 Dev Module |
| Câble USB | Compatible avec votre carte (micro-USB ou USB-C) |
| Connexion internet | Nécessaire pour télécharger les paquets |

---

## Étapes d'installation

### Étape 1 — Installer Arduino IDE

Arduino IDE est le logiciel utilisé pour écrire et téléverser du code sur l'ESP32.

1. Rendez-vous sur la page de téléchargement officielle d'Arduino :  
   **https://www.arduino.cc/en/software/**

2. Téléchargez le **programme d'installation Windows** pour la version **2.3.7**

3. Lancez le programme d'installation et suivez les instructions à l'écran

> **Vous ne savez pas quel fichier choisir ?** Sélectionnez celui intitulé *"Windows Win 10 and newer, 64 bits"*.

---

### Étape 2 — Installer le pilote USB-vers-UART

Ce pilote permet à votre ordinateur de communiquer avec l'ESP32 via USB. Sans lui, la carte ne sera pas détectée.

1. Téléchargez le **pilote CP210x VCP** depuis Silicon Labs :  
   **https://www.silabs.com/software-and-tools/usb-to-uart-bridge-vcp-drivers**

2. Lancez le programme d'installation

3. **Redémarrez votre ordinateur** une fois l'installation terminée

> **Pourquoi est-ce nécessaire ?** L'ESP32 utilise une puce USB-série (CP2102) pour communiquer avec votre PC. Windows a besoin d'un pilote spécial pour l'interpréter — à l'image de l'installation d'un pilote d'imprimante.

---

### Étape 3 — Ajouter le support ESP32 à Arduino IDE

Par défaut, Arduino IDE ne prend en charge que les cartes Arduino. Cette étape lui permet de reconnaître l'ESP32.

1. Ouvrez Arduino IDE

2. Allez dans **Fichier → Préférences** (ou appuyez sur `Ctrl + ,`)

3. Dans le champ **"URL de gestionnaire de cartes supplémentaires"**, collez l'URL suivante :

   ```
   https://espressif.github.io/arduino-esp32/package_esp32_index.json
   ```

4. Cliquez sur **OK**

---

### Étape 4 — Installer le paquet ESP32

Maintenant qu'Arduino IDE sait où trouver le support ESP32, vous pouvez l'installer.

1. Allez dans **Outils → Type de carte → Gestionnaire de cartes**  
   *(ou cliquez sur l'icône de carte dans la barre latérale gauche)*

2. Dans la barre de recherche, tapez : `esp32`

3. Trouvez le paquet **"esp32 by Espressif Systems"** et cliquez sur **Installer**

4. Attendez la fin du téléchargement et de l'installation — cela peut prendre quelques minutes

---

### Étape 5 — Sélectionner la carte ESP32

Indiquez à Arduino IDE quelle carte vous utilisez.

1. Allez dans **Outils → Type de carte → esp32**

2. Sélectionnez **"ESP32 Dev Module"** dans la liste

---

### Étape 6 — Connecter la carte et sélectionner le port

1. Branchez votre ESP32 à votre PC via le câble USB

2. Allez dans **Outils → Port**

3. Sélectionnez le port qui apparaît dans la liste (il ressemblera à `COM3` ou `COM4`)

> **Aucun port ne s'affiche ?** Essayez les solutions suivantes :
> - Débranchez puis rebranchez le câble USB
> - Essayez un autre port USB sur votre ordinateur
> - Votre carte utilise peut-être une puce différente (CH340 au lieu de CP2102). Téléchargez le pilote CH340 depuis : **https://www.wch-ic.com/downloads/CH341SER_EXE.html**

---

### Étape 7 — Installer la bibliothèque ESP32Servo

Cette bibliothèque est nécessaire pour contrôler les servomoteurs et autres actionneurs du projet Smart Eco-House.

1. Cliquez sur l'icône **Gestionnaire de bibliothèques** dans la barre latérale gauche (icône en forme de livres empilés)

2. Dans la barre de recherche, tapez : `ESP32Servo`

3. Trouvez la bibliothèque de **Kevin Harrington, John K. Bennett** et cliquez sur **Installer**

---

## Vous êtes prêt !

Votre environnement de développement est entièrement configuré. Vous pouvez maintenant ouvrir n'importe quel programme du projet Smart Eco-House et cliquer sur le bouton **Téléverser** (→) pour flasher votre carte.

Si le téléversement réussit, vous verrez le message `Téléversement terminé.` en bas de l'écran.

---

## Résolution des problèmes

| Problème | Solution |
|---|---|
| Carte non détectée (aucun port COM) | Réinstallez le pilote CP210x ou CH340, puis redémarrez |
| Échec du téléversement — erreur "port occupé" | Fermez les fenêtres du Moniteur Série ouvertes |
| Erreur "carte introuvable" | Vérifiez que **ESP32 Dev Module** est sélectionné dans Outils → Type de carte |
| Bibliothèque introuvable lors de la compilation | Vérifiez qu'ESP32Servo a bien été installée via le Gestionnaire de bibliothèques |

---

## Liens utiles

| Ressource | URL |
|---|---|
| Arduino IDE | https://www.arduino.cc/en/software/ |
| Pilote CP210x USB | https://www.silabs.com/software-and-tools/usb-to-uart-bridge-vcp-drivers |
| Pilote CH340 USB | https://www.wch-ic.com/downloads/CH341SER_EXE.html |
| Index du paquet ESP32 | https://espressif.github.io/arduino-esp32/package_esp32_index.json |

---

<h3 align="center">🧑🏻‍💻 | Responsable actuel : <a href="https://github.com/mohamedtalhaouii" target="_blank">----</a></h3>
