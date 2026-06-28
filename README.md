<div align="center">

# Smart Eco-House

### ESP32 Development Environment — Setup Guide

*Get your Arduino IDE configured and ready to program the EcoHouse ESP32 board, from scratch to first upload.*

---

</div>

## Overview

This guide walks you through every step needed to set up your development environment on Windows — from installing the Arduino IDE to uploading your first sketch to the ESP32. No prior experience with Arduino or ESP32 is required.

**What you'll set up:**

- Arduino IDE 2.3.7
- USB communication driver (so your PC recognises the board)
- ESP32 board support inside Arduino IDE
- ESP32Servo library (needed for motor/servo control)

**Estimated time:** 15–20 minutes

---

## Requirements

Before you begin, make sure you have:

| Item | Details |
|---|---|
| Computer | Windows 10 or later |
| ESP32 board | Any ESP32 Dev Module |
| USB cable | Matching your board (micro-USB or USB-C) |
| Internet connection | Required to download packages |

---

## Setup Steps

### Step 1 — Install Arduino IDE

Arduino IDE is the software you use to write and upload code to the ESP32.

1. Go to the official Arduino download page:  
   **https://www.arduino.cc/en/software/**

2. Download the **Windows installer** for version **2.3.7**

3. Run the installer and follow the on-screen instructions

> **Not sure which file to download?** Choose the one labelled *"Windows Win 10 and newer, 64 bits"*.

---

### Step 2 — Install the USB-to-UART Driver

This driver lets your computer communicate with the ESP32 over USB. Without it, the board will not be detected.

1. Download the **CP210x VCP driver** from Silicon Labs:  
   **https://www.silabs.com/software-and-tools/usb-to-uart-bridge-vcp-drivers**

2. Run the installer

3. **Restart your computer** once the installation finishes

> **Why is this needed?** The ESP32 uses a USB-to-serial chip (CP2102) to talk to your PC. Windows needs a special driver to understand it — similar to installing a printer driver.

---

### Step 3 — Add ESP32 Support to Arduino IDE

By default, Arduino IDE only supports Arduino boards. This step teaches it to recognise the ESP32.

1. Open Arduino IDE

2. Go to **File → Preferences** (or press `Ctrl + ,`)

3. Find the field labelled **"Additional Boards Manager URLs"** and paste this URL into it:

   ```
   https://espressif.github.io/arduino-esp32/package_esp32_index.json
   ```

4. Click **OK**

---

### Step 4 — Install the ESP32 Board Package

Now that Arduino IDE knows where to find ESP32 support, you can install it.

1. Go to **Tools → Board → Boards Manager**  
   *(or click the board icon in the left sidebar)*

2. In the search box, type: `esp32`

3. Find the package named **"esp32 by Espressif Systems"** and click **Install**

4. Wait for the download and installation to complete — this may take a few minutes

---

### Step 5 — Select the ESP32 Board

Tell Arduino IDE which specific board you're using.

1. Go to **Tools → Board → esp32**

2. Select **"ESP32 Dev Module"** from the list

---

### Step 6 — Connect Your Board and Select the Port

1. Plug your ESP32 into your PC using the USB cable

2. Go to **Tools → Port**

3. Select the port that appears in the list (it will look like `COM3` or `COM4`)

> **No port showing up?** Try the following:
> - Unplug and replug the USB cable
> - Try a different USB port on your computer
> - Your board may use a different driver chip (CH340 instead of CP2102). Download the CH340 driver from: **https://www.wch-ic.com/downloads/CH341SER_EXE.html**

---

### Step 7 — Install the ESP32Servo Library

This library is required for controlling servo motors and other actuators in the EcoHouse project.

1. Click the **Library Manager** icon in the left sidebar (it looks like a stack of books)

2. In the search box, type: `ESP32Servo`

3. Find the library by **Kevin Harrington, John K. Bennett** and click **Install**

---

## You're All Set

Your development environment is fully configured. You can now open any EcoHouse sketch and click the **Upload** button (→) to flash it to your board.

If the upload succeeds, you'll see `Done uploading.` at the bottom of the screen.

---

## Troubleshooting

| Problem | Solution |
|---|---|
| Board not detected (no COM port) | Reinstall the CP210x or CH340 driver, then restart |
| Upload fails with "port busy" error | Close any Serial Monitor windows that may be open |
| "Board not found" error | Make sure you selected **ESP32 Dev Module** in Tools → Board |
| Library not found during compilation | Re-check that ESP32Servo was installed via Library Manager |

---

## Reference Links

| Resource | URL |
|---|---|
| Arduino IDE | https://www.arduino.cc/en/software/ |
| CP210x USB Driver | https://www.silabs.com/software-and-tools/usb-to-uart-bridge-vcp-drivers |
| CH340 USB Driver | https://www.wch-ic.com/downloads/CH341SER_EXE.html |
| ESP32 Board Package Index | https://espressif.github.io/arduino-esp32/package_esp32_index.json |

---

<h3 align="center">🧑🏻‍💻 | Current Maintainer : <a href="https://github.com/t4lhawi" target="_blank">-------</a></h3>
