# Esp32_based_medicine_dispenser_controlledByMobileApplication

## Overview:
This project involves the development of an automated medicine dispenser using an ESP32 microcontroller that is controlled via a mobile application created using Kodular. The system ensures timely dispensing of medicine, which is particularly useful for elderly patients or people with strict medication schedules. The mobile app allows users to set the dispensing time, and the system uses Google Firebase for storing and retrieving the dispensing schedule in real-time. When it's time to dispense, a servo motor is triggered to release the medicine, and a buzzer sounds to alert the user.

## Hardware Connection 

### ESP32 Pin Connections:
### Servo Motor:
-Signal Pin (from Servo) → GPIO 13 (or servoPin)
-  VCC Pin (from Servo) → 5V Pin on ESP32
- GND Pin (from Servo) → GND Pin on ESP32
### Buzzer:
- Positive Pin (from Buzzer) → GPIO 12 (or buzzerPin)
- Negative Pin (from Buzzer) → GND Pin on ESP32
### RTC (DS1307 Module):
- VCC Pin → 3.3V Pin on ESP32
- GND Pin → GND Pin on ESP32
- SDA Pin → GPIO 21 (I2C Data Line)
- SCL Pin → GPIO 22 (I2C Clock Line)

## Key Features:
- Automated Dispensing: The ESP32 controls the servo motor, which operates a mechanism to dispense medicine at the scheduled time.
- Mobile Application (Kodular): The user-friendly mobile app built with Kodular allows users to set and modify the medicine dispensing time.
- Real-time Firebase Integration: Dispensing schedules are stored in Google Firebase. The ESP32 retrieves this data to ensure the medicine is dispensed at the right time.
- RTC for Accurate Timing: The system uses an RTC (Real-Time Clock) to maintain an accurate time for dispensing, even in case of power loss.
- Servo Motor Control: A servo motor attached to the ESP32 is used to control the physical dispensing mechanism.
- Buzzer for Alerts: A buzzer is activated when it's time to dispense the medicine, providing an auditory alert to the user.
## Components:
- ESP32 Microcontroller: The core of the system, responsible for fetching data from Firebase, controlling the servo motor, and activating the buzzer.
- Servo Motor: Controls the dispensing mechanism that releases medicine at scheduled times.
- Real-Time Clock (RTC): Ensures accurate timing, independent of power cycles.
- Buzzer: Alerts the user when it's time to take medicine.
- Firebase: Cloud-based database used to store dispensing schedules and manage data exchange between the ESP32 and the mobile app.
- Kodular Mobile App: The mobile interface allows users to input and update the dispensing time, which is sent to Firebase.
## Workflow:
- User Interaction: The user sets the desired medicine dispensing time via the mobile app created using Kodular.
- Data Storage in Firebase: The dispensing time is saved in Firebase, where the ESP32 constantly monitors the data.
- Real-Time Clock: The ESP32 uses the RTC to keep track of the current time.
- Medicine Dispensing: When the current time matches the dispensing time stored in Firebase, the servo motor is activated to release the medicine, and the buzzer sounds as an alert.
- User Notification: The buzzer continues to sound until the medicine is taken, ensuring the user is aware of the dispensing event.
- Mobile Application (Kodular):
The mobile app is designed with a user-friendly interface for setting and adjusting medicine schedules.
Users can input the dispensing time, which is stored in Firebase for real-time access by the ESP32.
The app communicates directly with Firebase, making it convenient for users to manage their schedules without needing to interact directly with the hardware.
## Advantages:
- Automation: Reduces the burden of manual medication management, especially for elderly or forgetful individuals.
- Remote Control: The mobile app allows users or caregivers to control and monitor the dispensing system remotely.
- Real-time Functionality: Firebase integration ensures that the ESP32 has up-to-date information for dispensing.
- Alert System: The buzzer serves as a simple but effective reminder, ensuring users don’t miss their medication.
- 
This project provides a highly customizable, scalable, and reliable solution for automating medicine dispensing tasks, improving the quality of life for users who need regular medication assistance.
