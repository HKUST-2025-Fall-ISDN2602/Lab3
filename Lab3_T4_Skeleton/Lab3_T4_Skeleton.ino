/*Replace ? in the code */
#include <DHT.h> 

#define TOUCHPIN ?    // ***Replace the ? with the GPIO pin you selected 
#define THRESHOLD_Touch 100 // ***Observe the reading when the pin is touched. Then modify this threshold.***

int state = 0; // Initial state
unsigned long lastTouchTime = 0; // To avoid multiple transitions on a single touch

#define THRESHOLD_Heart 100 // ***Observe the Plotter when your Heart beats. Then modify this threshold.***
bool heartBeatDetected = false; // Flag to check if heartbeat is detected 

#define DHT11_PIN  ? // Select a ESP32 pin connected to DHT11 sensor Signal 

#define HEART_PIN ? // ***Replace the ? with the GPIO pin you selected 

DHT dht11(DHT11_PIN, DHT11);

void setup() { 
  Serial.begin(?); // ***Start the serial communication (baud rate as 9600).*** 
  
  pinMode(LED_BUILTIN, ?); // Set pin D2 for built-in LED as an output pin
  
  dht11.begin(); // initialize the DHT11 sensor 

  pinMode(HEART_PIN, ?); // Set HEART_PIN as an input pin

  Serial.println("ISDN2601 Lab 3: Task 4");
}

void loop() {

  int touch_reading = touchRead(?); // Read the touch sensor
  Serial.print("touch:");       // print touch_reading to the Serial monitor
  Serial.println(?);       // print touch_reading to the Serial monitor 

  // Finite State Machine Logic
  if (touch_reading < THRESHOLD_Touch) { // Check if touched
    state = (state + 1) % 3; // Transition to the next state
  }
  
  int heartSum=0; // Initialize a variable to hold the sum of heart readings
  float heartAverage;  // Declare a variable to hold the average heart reading
    // Loop to read heart sensor values 20 times
    for (int i=0; i< 20; i++) {
       heartSum += analogRead(?); // Read the value from the heartbeat sensor and add it to heartSum 
       }
    heartAverage = ?; // Divide the heartSum by 20 to get the average
  // Check if the heart average exceeds the threshold indicating a heartbeat
  if (heartAverage > THRESHOLD_Heart) {
    heartBeatDetected = true; // Set the flag to true if heartbeat is detected
  } else {
    heartBeatDetected = false; // Reset the flag if no heartbeat is detected
  } 
  // Display output based on the current state and heartbeat detection
  if (heartBeatDetected) {
    switch (state) {
      case 0:
      // read temperature in Celsius
        float tempC = dht11.readTemperature(); 
        if (isnan(tempC)) //nan "Not-a-Number" (NaN) value 
          { Serial.println("Failed to read from DHT11 sensor!");} 
          else
          {Serial.print("Current State: 0 (Temperature in °C): ");
           Serial.println(tempC);} 
        break;
      case 1:
         if (isnan(tempF)) //nan "Not-a-Number" (NaN) value 
          { Serial.println("Failed to read from DHT11 sensor!");} 
          else {
        float tempF = dht11.readTemperature(true);
        Serial.println(tempF);}
        break;
      case 2:
        float humi  = dht11.readHumidity();
         if (isnan(tempF)) //nan "Not-a-Number" (NaN) value 
          { Serial.println("Failed to read from DHT11 sensor!");} 
          else {
        Serial.print("Current State: 2 (Humidity): ");
        Serial.println(humi);
        Serial.print("%");
          }
        break;
    } 
    delay(2000); // wait 2 seconds between readings. delay(ms) The function admits a number of milliseconds to pause
  }
   

   
 
}
