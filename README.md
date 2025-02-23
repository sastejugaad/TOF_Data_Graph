# Project TOF Graph

This project is part for "CAKE" and demonstrates how to use an ESP32 microcontroller with an OLED display and a VL53L0X Time-of-Flight (TOF) sensor. The code reads distance measurements from the TOF sensor and displays the data on the OLED screen. Additionally, it graphs the distance measurements in real-time.

## Objective

To measure distances using a VL53L0X TOF sensor and display the measurements on an OLED screen connected to an ESP32 microcontroller. The project also includes a graphical representation of the distance measurements.

## Electronics Required

- **ESP32** microcontroller
- **VL53L0X TOF Sensor**
- **OLED Display (128x64)**

## Circuit Connection

- **Power:** Connect the 3.3V and GND pins of the ESP32 to the 3.3V and GND pins of the OLED display and the VL53L0X sensor.
- **I2C:** Connect the SCL and SDA pins of the OLED display and VL53L0X sensor to the SCL and SDA pins of the ESP32. Both the OLED and TOF sensor will share the same I2C bus.

## How the Code Works

1. **Initialization:**
    - The code initializes the OLED display and VL53L0X sensor.
    - It sets up the OLED display with a text size of 1 and a white color for the text.
    - The VL53L0X sensor is initialized, and if it fails to boot, the code prints an error message to the Serial Monitor.

2. **Loop:**
    - The code continuously reads distance measurements from the VL53L0X sensor.
    - If the measurement data is valid, it prints the distance in millimeters to the Serial Monitor and displays the distance on the OLED screen.
    - The distance measurements are stored in an array to update the graphical representation.
    - The code draws a graph of the distance measurements on the OLED screen, plotting the data points in real-time.

For more details, watch this video: [Test Code for Project Cake](https://www.youtube.com/watch?v=B9ZkrByD6Pk&ab_channel=SasteJugaad)

## What is CAKE

For a detailed video tutorial, check out the link below:

[![Test Code for Project Cake](https://img.youtube.com/vi/B9ZkrByD6Pk/0.jpg)](https://www.youtube.com/watch?v=B9ZkrByD6Pk&ab_channel=SasteJugaad)

Click the image above to watch the video

**CAD**
[Cake CAD](https://grabcad.com/library/cake-esp32-robot-with-encoders-and-slam-1)

Feel free to add more details or adjust the content as needed!
