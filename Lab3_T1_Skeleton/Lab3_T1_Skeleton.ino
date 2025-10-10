/*Chnage all the ? in the code to read the value touchRead(GPIO pin) returned.*/

#define TOUCHPIN ?                  // ***Replace the ? with the GPIO pin you selected 
#define THRESHOLD 100               // ***Observe the reading when the pin is touched. Then modify this threshold.***



void setup() {
  Serial.begin(?);               // ***Start the serial communication (baud rate as 9600).***
  pinMode(LED_BUILTIN, ?);       // Set pin D2 for built-in LED as an output pin
  Serial.println("ISDN2601 Lab 3: Task 1");
}

void loop() {
  
  int touch_reading = touchRead(?); // Read the touch sensor
  Serial.println(?);       // print touch_reading to the Serial monitor

  // The built-in LED can be turned on when the pin is touched.
  if (touch_reading < THRESHOLD)
    digitalWrite(LED_BUILTIN, ?);   // turn on built-in LED
  else
    digitalWrite(LED_BUILTIN, ?);    // turn off built-in LED
    
  delay(100);
}
