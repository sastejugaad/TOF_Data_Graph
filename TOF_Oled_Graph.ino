/*
Test code for project Cake
https://www.youtube.com/watch?v=B9ZkrByD6Pk&ab_channel=SasteJugaad
Use I2C Pins for connection.
Both Oled and TOF sensor will connect to same I2C.
Power = 3.3v
Esp32
*/
#include <Wire.h>
#include <Adafruit_VL53L0X.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET -1
Adafruit_SSD1306 display(128, 64, &Wire, OLED_RESET);

Adafruit_VL53L0X lox = Adafruit_VL53L0X();

#define MAX_POINTS 128

// Array to store sensor values for the graph
int graphData[MAX_POINTS];
int currentIndex = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("VL53L0X Test");

  // Initialize the OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  
  // Initialize the VL53L0X sensor
  if (!lox.begin()) {
    Serial.println(F("Failed to boot VL53L0X"));
    while (1);
  }
  Serial.println(F("VL53L0X ready"));
  
  // Initialize the graph data
  for (int i = 0; i < MAX_POINTS; i++) {
    graphData[i] = 0;
  }
}

void loop() {
  VL53L0X_RangingMeasurementData_t measure;

  // Read the sensor data
  lox.rangingTest(&measure, false);

  display.clearDisplay();
  display.setCursor(0, 0);
  
  if (measure.RangeStatus != 4) {  // If data is valid
    Serial.print("Distance (mm): "); 
    Serial.println(measure.RangeMilliMeter);
    
    // Display the data on the OLED
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    //display.print("DIST:");
    display.print((measure.RangeMilliMeter));
    display.print("mm");

    // Update the graph data
    graphData[currentIndex] = (measure.RangeMilliMeter-40)*10;
    currentIndex = (currentIndex + 1) % MAX_POINTS;

    // Draw the graph
    for (int i = 0; i < MAX_POINTS - 1; i++) {
      int x1 = i;
      int y1 = map(graphData[(currentIndex + i) % MAX_POINTS], 0, 2000, 64, 0);
      int x2 = i + 1;
      int y2 = map(graphData[(currentIndex + i + 1) % MAX_POINTS], 0, 2000, 64, 0);
      display.drawLine(x1, y1, x2, y2, WHITE);
    }
   
  } else {
    Serial.println("Out of range");
    
    // Display out of range message on the OLED
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("Out of range");
  }

  display.display();
  delay(100);
}
