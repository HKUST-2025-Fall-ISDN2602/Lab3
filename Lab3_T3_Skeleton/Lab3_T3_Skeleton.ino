/*Chnage all the ? in the code to read the value.*/

#define HEART_PIN ? // ***Replace the ? with the GPIO pin you selected 

void setup() {
    Serial.begin(?); // ***Start the serial communication (baud rate as 9600).***
    pinMode(HEART_PIN, ?); // Set HEART_PIN as an input pin
    Serial.println("ISDN2601 Lab 3: Task 3");
}

void loop() {
    int heartValue = analogRead(?); // Read the value 
    Serial.println(?); // send the value to serial plotter 
    delay(10);
}
