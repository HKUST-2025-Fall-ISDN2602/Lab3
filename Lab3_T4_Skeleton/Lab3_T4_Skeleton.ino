/*Replace ? in the code */
#include <DHT.h> 

#define TOUCHPIN ?    // ***Replace the ? with the GPIO pin you selected 
#define THRESHOLD_Touch 100 // ***Observe the reading when the pin is touched. Then modify this threshold.***
#define THRESHOLD_Heart 100 // ***Observe the Plotter when your Heart beats. Then modify this threshold.***

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

  /*Do not change below code*/
  // read humidity
  float humi  = dht11.readHumidity();
  // read temperature in Celsius
  float tempC = dht11.readTemperature();
  // read temperature in Fahrenheit
  float tempF = dht11.readTemperature(true);

  // check whether the reading is successful or not
  if ( isnan(tempC) || isnan(tempF) || isnan(humi)) //nan "Not-a-Number" (NaN) value 
  {
    Serial.println("Failed to read from DHT11 sensor!");
  } else {
    Serial.print("Humidity: ");
    Serial.print(humi);
    Serial.print("%");

    Serial.print("  |  ");

    Serial.print("Temperature: ");
    Serial.print(tempC);
    Serial.print("°C  ~  ");
    Serial.print(tempF);
    Serial.println("°F");
  }
 /*Do not change above code*/

 // DHT sensor is very slow getting the readings (the sensor readings may take up to 2 seconds) 
  delay(?);  // wait 2 seconds between readings. delay(ms) The function admits a number of milliseconds to pause
 
 int heartValue = analogRead(?); // Read the value of Heart Beat 
 Serial.print("heart:");       // print heartValue to the Serial monitor
 Serial.println(?); // print heartValue to the Serial monitor
 delay(10);
 
 // The built-in LED can be turned on when the touch pin is touched, temperature is beyond 30 ℃, humidity is over 60% and your heart beats.
  if (touch_reading < THRESHOLD_Touch && tempC > 30 && humi > 60 &&  heartValue > THRESHOLD_Heart )
    digitalWrite(LED_BUILTIN, ?);   // turn on built-in LED
  else
    digitalWrite(LED_BUILTIN, ?);    // turn off built-in LED
    
  delay(100);
}
