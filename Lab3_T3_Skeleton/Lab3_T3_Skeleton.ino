/*Chnage all the ? in the code to read the value.*/

#define HEART_PIN ? // ***Replace the ? with the GPIO pin you selected 

void setup() {
    Serial.begin(?); // ***Start the serial communication (baud rate as 9600).***
    pinMode(HEART_PIN, ?); // Set HEART_PIN as an input pin
    Serial.println("ISDN2601 Lab 3: Task 3");
}

void loop() {
    int heartSum=0; // Initialize a variable to hold the sum of heart readings
    float heartAverage;  // Declare a variable to hold the average heart reading

    // Loop to read heart sensor values 20 times
    for (int i=0; i< 20; i++) }
       heartSum += analogRead(?); // Read the value from the heartbeat sensor and add it to heartSum 
       }

    heartAverage = ?; // Divide the heartSum by 20 to get the average

    Serial.println(?); // send the value to serial plotter
     
    delay(?); // read the value every 100 ms
}
