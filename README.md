# Wokwi Sensor Reading Examples

## Overview

This repository contains embedded C/C++ examples developed for sensor simulation using the **Wokwi online simulator** and the ESP32 platform.

The project demonstrates how to initialize simulated sensors, acquire measurements, process readings, apply moving-average filters, estimate gas concentration, classify operating conditions, and display results through the Wokwi Serial Monitor.

The examples are intended for learning, prototyping, testing, and validating embedded-system logic without requiring physical hardware.

## Simulated Sensors

| Sensor  | Measured Variable           | Communication Interface     |
| ------- | --------------------------- | --------------------------- |
| BMP180  | Atmospheric pressure        | I²C                         |
| HC-SR04 | Distance                    | Digital GPIO — Trigger/Echo |
| DS18B20 | Temperature                 | 1-Wire                      |
| MQ-2    | Estimated gas concentration | Analog Input — ADC          |

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

Each directory contains an independent Wokwi example for a specific sensor.

## Simulation Platform

The examples were designed to run on:

* Wokwi online simulator
* ESP32 development board simulation
* Arduino framework
* Wokwi Serial Monitor

No physical sensors are required to execute the simulations.

## Wokwi Project Configuration

Each simulation generally contains:

* ESP32 development board
* Simulated sensor
* Virtual wiring
* Arduino source code
* `diagram.json` circuit configuration
* `libraries.txt`, when external libraries are required

A complete example directory may use the following structure:

```text
MQ2/
├── MQ2.ino
├── diagram.json
└── libraries.txt
```

## ESP32 Pin Configuration

| Component          | ESP32 Pin |
| ------------------ | --------: |
| DS18B20 data       |    GPIO 4 |
| BMP180 SDA         |   GPIO 21 |
| BMP180 SCL         |   GPIO 22 |
| HC-SR04 Trigger    |   GPIO 18 |
| HC-SR04 Echo       |    GPIO 5 |
| MQ-2 analog output |   GPIO 33 |

The pin configuration must match the connections defined in the Wokwi `diagram.json` file.

## Requirements

### Software

* Modern web browser
* Internet connection
* Wokwi account, optionally
* Arduino framework
* ESP32 board configuration

### Required Libraries

Depending on the selected example, the following libraries may be required:

* `Wire`
* `Adafruit Unified Sensor`
* `Adafruit BMP085 Unified`
* `OneWire`
* `DallasTemperature`

The required external libraries can be declared in the `libraries.txt` file of each Wokwi project.

Example:

```text
Adafruit Unified Sensor
Adafruit BMP085 Unified
OneWire
DallasTemperature
```

## Running the Simulations

1. Open Wokwi.
2. Create or import an ESP32 project.
3. Add the source code from the desired sensor directory.
4. Configure the simulated components in `diagram.json`.
5. Add the required libraries.
6. Start the simulation.
7. Open the Serial Monitor to view the measurements.

## Functionality

The examples demonstrate:

* Sensor initialization
* ESP32 GPIO configuration
* I²C communication
* 1-Wire communication
* Analog-to-digital conversion
* Ultrasonic distance measurement
* Sensor-data acquisition
* Measurement processing
* Moving-average filtering
* Gas-concentration estimation
* Operational-state classification
* Serial output for monitoring and debugging

## Measured Variables

| Sensor  | Simulated Output                   |
| ------- | ---------------------------------- |
| BMP180  | Atmospheric pressure in kPa        |
| HC-SR04 | Distance in centimeters            |
| DS18B20 | Temperature in degrees Celsius     |
| MQ-2    | Estimated gas concentration in ppm |

## Moving-Average Filter

Some measurements are processed using a moving average containing up to 15 readings.

```cpp
struct MediaMovel {
  float leituras[15];
  int quantidade = 0;
  int indice = 0;
};
```

The filter reduces abrupt variations and produces more stable values in the Serial Monitor.

It is applied to:

* Temperature
* Atmospheric pressure
* Gas concentration

The HC-SR04 distance reading may be used without filtering to preserve a faster response to simulated obstacles.

## MQ-2 Gas Estimation

The Wokwi MQ-2 simulation provides an analog output that varies according to the gas concentration configured in the simulator.

Because the sensor response is nonlinear, the project uses a logarithmic function to estimate the gas concentration in ppm from the ESP32 ADC reading.

The calculation includes:

1. Reading the ESP32 ADC value
2. Normalizing the analog reading
3. Applying a nonlinear conversion curve
4. Applying a calibration correction
5. Filtering the resulting ppm value

The calibration curve was adjusted using values configured and measured during sequential Wokwi simulations.

Therefore, the ppm conversion is specifically intended for this Wokwi project and may not produce equivalent results with a physical MQ-2 sensor.

## Important MQ-2 Limitation

The calculated ppm value represents an approximation based on the simulated Wokwi response.

It should not be interpreted as:

* A certified gas measurement
* A calibrated physical MQ-2 reading
* A reliable industrial-safety measurement
* Identification of a specific gas

A physical MQ-2 sensor requires calibration using known gas concentrations, sensor resistance, load resistance, temperature, humidity, and an appropriate reference gas.

## Operational States

The project can classify the simulated environment into three states:

* `NORMAL`
* `ATENÇÃO`
* `CRÍTICO`

When multiple variables exceed their configured limits, all affected measurements can be displayed.

Example:

```text
CRÍTICO: GÁS, DISTÂNCIA | ATENÇÃO: TEMPERATURA
```

## Default Thresholds

### Temperature

|          Temperature | State     |
| -------------------: | --------- |
|         Below -20 °C | Critical  |
| -20 °C to below 0 °C | Attention |
|        0 °C to 35 °C | Normal    |
| Above 35 °C to 45 °C | Attention |
|          Above 45 °C | Critical  |

### Atmospheric Pressure

|                 Pressure | State     |
| -----------------------: | --------- |
|             Below 70 kPa | Critical  |
|   70 kPa to below 80 kPa | Attention |
|        80 kPa to 120 kPa | Normal    |
| Above 120 kPa to 150 kPa | Attention |
|            Above 150 kPa | Critical  |

### Distance

|              Distance | State     |
| --------------------: | --------- |
|           Below 50 cm | Critical  |
| 50 cm to below 100 cm | Attention |
|     100 cm or greater | Normal    |

### Gas Concentration

The gas thresholds depend on the reference gas and the purpose of the simulation.

The values used in the project are intended to demonstrate alert logic inside Wokwi and should not be treated as official industrial exposure limits.

## Serial Monitor Output

Example of normal operation:

```text
Temperature: 26.40 °C
Pressure: 101.32 kPa
Distance: 145.00 cm
Gas: 198.42 ppm
State: NORMAL
```

Example containing alerts:

```text
Temperature: 39.20 °C
Pressure: 101.10 kPa
Distance: 42.00 cm
Gas: 2300.00 ppm
State: CRÍTICO: DISTÂNCIA, GÁS | ATENÇÃO: TEMPERATURA
```

## Adjusting Sensor Values in Wokwi

During the simulation, the sensor values can be changed through the Wokwi interface.

This allows the user to test:

* Normal operating conditions
* Temperature alerts
* Pressure alerts
* Gas-concentration alerts
* Obstacle proximity
* Multiple simultaneous alerts
* Moving-average response
* State transitions

## Applications

This repository can be used as a reference for:

* Learning embedded programming
* ESP32 simulations
* Sensor-reading exercises
* Robotics simulations
* Environmental-monitoring prototypes
* Industrial inspection robot simulations
* Alert-logic validation
* Data-processing experiments
* Moving-average filter testing
* Wokwi project demonstrations

## Simulation Limitations

* Wokwi measurements do not perfectly represent physical sensors.
* The MQ-2 ppm conversion is calibrated for the simulated response.
* ADC behavior may differ from a real ESP32.
* Simulated sensors do not reproduce every environmental interference.
* Temperature, humidity, noise, aging, and physical calibration are simplified.
* The project must not be used as certified industrial safety equipment.

## License

This project is released under the MIT License.
