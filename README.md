#  License Plate Recognition System (LPR) using ESP32

##  Project Overview

This project presents a **License Plate Recognition System prototype** designed for vehicle monitoring, parking management, and security applications. The system focuses on creating a **real-time alert interface using the ESP32 microcontroller**.

The ESP32 controls an **LCD display, LEDs, buzzer, and push button** to simulate vehicle detection alerts. When a detection event occurs, the system provides **visual and audible notifications**.

This prototype forms the **hardware alert module** of a larger License Plate Recognition system. In future development, a **camera-based recognition module** can be integrated to automatically detect and read vehicle license plates.

---

##  Objectives

* Develop a **real-time monitoring and alert system** using ESP32.
* Display system messages using a **16x2 I2C LCD display**.
* Provide **visual alerts using LEDs**.
* Provide **audio alerts using a buzzer**.
* Simulate vehicle detection using a **push button**.
* Build a base system that can later integrate **automatic license plate recognition**.

---

##  Hardware Components

| Component               | Quantity |
| ----------------------- | -------- |
| ESP32 Development Board | 1        |
| 16x2 I2C LCD Display    | 1        |
| Buzzer                  | 1        |
| Red LED                 | 1        |
| Green LED               | 1        |
| Push Button             | 1        |
| 220Ω Resistors          | 2        |
| Breadboard              | 1        |
| Jumper Wires            | Multiple |

---

##  Software Used

* Arduino IDE
* ESP32 Board Package
* Wokwi Simulator (for circuit simulation)

---

##  Circuit Description

The **ESP32 microcontroller** acts as the central controller for the system.

The **16x2 LCD display (I2C)** is used to display system messages such as system status and alerts. The **green LED** indicates that the system is active and ready, while the **red LED** indicates an alert condition.

A **buzzer** provides an audible alert whenever a detection event occurs. A **push button** is used to simulate the detection of a vehicle entering the monitored area.

---

## Pin Configuration

| Component   | ESP32 Pin |
| ----------- | --------- |
| LCD SDA     | GPIO 21   |
| LCD SCL     | GPIO 22   |
| Buzzer      | GPIO 25   |
| Green LED   | GPIO 26   |
| Red LED     | GPIO 27   |
| Push Button | GPIO 14   |

---

##  Working Principle

1. When the system starts, the ESP32 initializes the LCD display and hardware components.
2. The **green LED turns ON**, indicating that the system is ready.
3. When the **push button is pressed**, the system simulates a vehicle detection event.
4. During the detection event:

   * The **red LED turns ON**
   * The **buzzer produces an alert sound**
   * The **LCD displays an alert message**
5. After the alert, the system returns to standby mode.

---

##  Simulation

The system circuit was designed and tested using the **Wokwi simulator** before hardware implementation.

Simulation Link:
https://wokwi.com/projects/458009695548266497

---

##  Applications

* Smart parking management
* Vehicle entry monitoring
* Security alert systems
* Access control systems
* Smart transportation systems

---

##  Future Scope

This project can be extended by integrating:

* Camera module for vehicle detection
* Image processing techniques
* Optical Character Recognition (OCR) for license plate reading
* Database storage for vehicle records
* Automated gate control systems

---

##  Author

Haran

---

##  License

This project is developed for **educational purposes**.

