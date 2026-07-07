# Sensor Reading Examples

## Overview

This repository contains embedded C/C++ examples for interfacing with multiple sensors using Arduino and ESP32 platforms. Each example demonstrates sensor initialization, data acquisition, and serial output, providing a reference for embedded systems development and hardware integration.

## Implemented Sensors

| Sensor  | Measured Variable                 | Communication Interface     |
| ------- | --------------------------------- | --------------------------- |
| BMP180  | Atmospheric pressure              | I²C                         |
| HC-SR04 | Distance                          | Digital GPIO (Trigger/Echo) |
| DS18B20 | Temperature                       | 1-Wire                      |
| MQ-2    | Gas concentration (analog output) | Analog Input (ADC)          |

## Repository Structure

```text
.
├── BMP180/
│   └── BMP180.ino
├── HC-SR04/
│   └── HC-SR04.ino
├── DS18B20/
│   └── DS18B20.ino
└── MQ2/
    └── MQ2.ino
```

Each directory contains an independent implementation for a specific sensor.

## Requirements

### Hardware

* Arduino or ESP32 development board
* BMP180 pressure sensor
* HC-SR04 ultrasonic distance sensor
* DS18B20 digital temperature sensor
* MQ-2 gas sensor

### Software

* Arduino IDE 2.x or PlatformIO
* Required libraries:

  * Wire
  * Adafruit Unified Sensor
  * Adafruit BMP085 Unified
  * OneWire
  * DallasTemperature

## Functionality

The examples implement:

* Sensor initialization
* Peripheral configuration
* Data acquisition
* Measurement processing
* Serial communication for monitoring and debugging

## Measured Variables

| Sensor  | Output                                       |
| ------- | -------------------------------------------- |
| BMP180  | Atmospheric pressure (Pa or hPa)             |
| HC-SR04 | Distance (cm)                                |
| DS18B20 | Temperature (°C)                             |
| MQ-2    | Analog gas concentration reading (ADC value) |

## Applications

These examples can be used as a starting point for:

* Embedded systems development
* Robotics
* Environmental monitoring
* Sensor validation and calibration
* Data acquisition systems

## License

This project is released under the MIT License.
