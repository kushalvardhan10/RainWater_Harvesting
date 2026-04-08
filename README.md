# RainWater_Harvesting
# 🌧️ Smart Rainwater Harvesting System using Arduino

## 📌 Overview
This project is an automated rainwater harvesting system that detects rainfall and monitors water levels in a storage tank. Based on real-time conditions, it intelligently controls a valve using a servo motor.

## 🚀 Features
- 🌧️ Rain detection using rain sensor
- 📏 Water level measurement using ultrasonic sensor
- ⚙️ Automatic valve control using servo motor
- 🖥️ Real-time display on 16x2 LCD
- 🔄 Fully automated decision-making system

## 🛠️ Components Used
- Arduino Uno
- Rain Sensor
- Ultrasonic Sensor (HC-SR04)
- 16x2 LCD Display
- Servo Motor
- Breadboard & Jumper Wires

## 🔌 Circuit Connections
### Rain Sensor
- VCC → 5V  
- GND → GND  
- Signal → A0  

### Ultrasonic Sensor
- VCC → 5V  
- GND → GND  
- Trig → Pin 9  
- Echo → Pin 10  

### LCD Display
- RS → Pin 12  
- E → Pin 11  
- D4 → Pin 5  
- D5 → Pin 4  
- D6 → Pin 3  
- D7 → Pin 2  

### Servo Motor
- Signal → Pin 6  
- VCC → 5V  
- GND → GND  

## 🧠 Working Principle
- Detects rainfall using sensor
- Measures tank water level using ultrasonic sensor
- If rain is detected and tank is not full:
  → Valve opens automatically  
- Else:
  → Valve remains closed  

## 📸 Project Images
(Add images in /images folder)

## 🔮 Future Enhancements
- IoT integration (ESP32)
- Mobile app monitoring
- Data logging & analytics
- Smart irrigation integration

## 👨‍💻 Author
Kushal Vardhan Naidu
