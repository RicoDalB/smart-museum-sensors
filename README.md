# Smart Museum Sensors

This project was developed as part of the **Object-Oriented Programming** course at the **University of Padua**.  
It models and manages a network of environmental sensors used to monitor different conditions inside a museum environment.

---

## Project Goal

The goal of the project is to demonstrate object-oriented design principles (inheritance, polymorphism, abstraction, and the Visitor pattern) by simulating a flexible and extensible system for sensor data collection.

---

## Core Features

- **Abstract Sensor Architecture**: A base `AbstractSensor` class defines a common interface for all sensors.
- **Sensor Types Implemented**:
  - `TemperatureSensor`: tracks temperature values.
  - `HumiditySensor`: tracks air humidity.
  - `CO2Sensor`: tracks carbon dioxide levels.
- **SensorList**: a container class for storing, managing, and iterating over multiple sensors.
- **Visitor Pattern**: supports separation of data collection/operation logic via `SVisitor` and `SConstVisitor` interfaces.
- **Data Simulation**: some methods generate random or static sample data to simulate real sensor behavior.

---

## Project Structure

src/
├── main.cpp # Program entry point
├── Engine/
│ └── sensorlist.* # Manages the list of sensors
├── Sensor/
├── abstractsensor.* # Base sensor interface
├── temperaturesensor.* # Temperature sensor
├── humiditysensor.* # Humidity sensor
├── co2sensor.* # CO2 sensor
├── SVisitor.h # Visitor interface
└── SConstVisitor.h # Const visitor interface

---

## 🧠 OOP Concepts Used

- **Inheritance**: All sensors inherit from a shared abstract class.
- **Polymorphism**: Sensor behavior is accessed through base class pointers.
- **Abstraction**: Core functionality is hidden behind interfaces.
- **Visitor Pattern**: Enables clean separation between operations and sensor structure.

---

## 🚀 How to Compile (Example with g++)

```bash
g++ src/main.cpp src/Engine/sensorlist.cpp src/Sensor/*.cpp -o MuseoSensors
./MuseoSensors
```
You might need to adjust paths depending on your build environment.

## Educational Context
Bachelor’s degree in Computer Science
University of Padua
Academic Year: 2023–2024
Course: Object-Oriented Programming (Programmazione ad Oggetti)



