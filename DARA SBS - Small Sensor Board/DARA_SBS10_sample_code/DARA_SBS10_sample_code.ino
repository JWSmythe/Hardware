/*
 Sample DARA SBS v1.0 code
 File:  Sample_DARA_SBS_10.ino

 (c) 2022 JWSmythe https://jwsmythe.com and D.A.R.A. 

 This sample code demonstrates how to use the DARA SBS 1.0 on microcontroller
 platforms.  Please reference the datasheet for more specs and details. 

 // This version is viewable in the Arduino IDE with both the Serial Monitor for text, and Serial Plotter for graphing.
*/

    #include<Arduino.h> // as applicable for your platform.
    
    // ESP8266 / ESP32
    #define s0_pin D0      // D0 
    #define s1_pin D1      // D1
    #define s2_pin D2      // D2
    #define s3_pin D3      // D3
    #define ena_pin D4     // D4
    #define signal_pin A0  // A0

/*
    // Arduino Nano/Uno 
    #define s0_pin 6       // D6
    #define s1_pin 5       // D5
    #define s2_pin 4       // D4 
    #define s3_pin 3       // D3
    #define ena_pin 2      // D2
    #define signal_pin 0   // A0
*/

    int sensor_pause = 1; // This is a short pause, after the channel has been 
                          // selected, before the input is actually read.  
                          // This may not be necessary on your hardware.  
                          // If so, set to 0.
    int loop_pause = 10; // Pause at the end of the loop, after all sensors 
                          // were read and data posted. Slow down the pace, 
                          // there's no reason to overrun the MCU. 
    int sensor_data[16];  // Store all the sensor data in this array.
                          // The results will be numbered like 
                          // sensor_data[0]  is channel 0.
                          // sensor_data[1]  is channel 1. 
                          // ... 
                          // sensor_data[15] is channel 15.

void setup() {                                
    Serial.begin(115200);
    Serial.print("+++ Serial Init Complete\n");
    Serial.println("... BEGIN Pin Init\n");
    pinMode(s0_pin,OUTPUT);
    pinMode(s1_pin,OUTPUT);
    pinMode(s2_pin,OUTPUT);
    pinMode(s3_pin,OUTPUT);
    pinMode(ena_pin, OUTPUT);
    pinMode(signal_pin, INPUT);
    digitalWrite(ena_pin, HIGH);
    Serial.println("... END Pin Init\n");
    Serial.print("... END SETUP\n");    
}

void loop() {                               
    // Serial.print("... Begin LOOP\n");  

    /* Each channel line below, has 8 steps.  I collapsed these to two lines, so they'd be easier to read.
     * 
     * digitalWrite(ena_pin, HIGH);    // Set enable HIGH.  This disables the multiplexer, so we don't have channel switching noise
     * digitalWrite(s0_pin,LOW);       // Set S0 for the channel we want. The chart is in the datasheet.
     * digitalWrite(s1_pin,LOW);       // Set S1
     * digitalWrite(s2_pin,LOW);       // Set S2
     * digitalWrite(s3_pin,LOW);       // Set S3
     * digitalWrite(ena_pin, LOW);     // Set enable LOW.  Re-enable the multiplexer
     * delay(sensor_pause);            // A short delay, to avoid noise from changing channels.  This may not be necessary.
     * sensor_data[0] = analogRead(signal_pin);  // Read this pin's data, and save it to the data array, to display at the end of the loop.
    */
    
    // Channel 0 [0,0,0,0]
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,LOW);  digitalWrite(s1_pin,LOW);  digitalWrite(s2_pin,LOW);  digitalWrite(s3_pin,LOW);  digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[0] = analogRead(signal_pin);
    
    // Channel 1 [1,0,0,0]
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,HIGH); digitalWrite(s1_pin,LOW);  digitalWrite(s2_pin,LOW);  digitalWrite(s3_pin,LOW);  digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[1] = analogRead(signal_pin);
    
    // Channel 2 [0,1,0,0]
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,LOW);  digitalWrite(s1_pin,HIGH); digitalWrite(s2_pin,LOW);  digitalWrite(s3_pin,LOW);  digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[2] = analogRead(signal_pin);
    
    // Channel 3 [1,1,0,0]
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,HIGH); digitalWrite(s1_pin,HIGH); digitalWrite(s2_pin,LOW);  digitalWrite(s3_pin,LOW);  digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[3] = analogRead(signal_pin);
    
    // Channel 4 [0,0,1,0]
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,LOW);  digitalWrite(s1_pin,LOW);  digitalWrite(s2_pin,HIGH); digitalWrite(s3_pin,LOW);  digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[4] = analogRead(signal_pin);
    
    // Channel 5 [1,0,1,0]
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,HIGH); digitalWrite(s1_pin,LOW);  digitalWrite(s2_pin,HIGH); digitalWrite(s3_pin,LOW);  digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[5] = analogRead(signal_pin);
    
    // Channel 6 [0,1,1,0]
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,LOW);  digitalWrite(s1_pin,HIGH); digitalWrite(s2_pin,HIGH); digitalWrite(s3_pin,LOW);  digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[6] = analogRead(signal_pin);
    
    // Channel 7 [1,1,1,0]
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,HIGH); digitalWrite(s1_pin,HIGH); digitalWrite(s2_pin,HIGH); digitalWrite(s3_pin,LOW);  digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[7] = analogRead(signal_pin);
    
    // Channel 8 [0,0,0,1]
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,LOW);  digitalWrite(s1_pin,LOW);  digitalWrite(s2_pin,LOW);  digitalWrite(s3_pin,HIGH); digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[8] = analogRead(signal_pin);
    
    // Channel 9 [1,0,0,1] 
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,HIGH); digitalWrite(s1_pin,LOW);  digitalWrite(s2_pin,LOW);  digitalWrite(s3_pin,HIGH); digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[9] = analogRead(signal_pin);
    
    // Channel 10 [0,1,0,1]
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,LOW);  digitalWrite(s1_pin,HIGH); digitalWrite(s2_pin,LOW);  digitalWrite(s3_pin,HIGH); digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[10] = analogRead(signal_pin);
    
    // Channel 11 [1,1,0,1]
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,HIGH); digitalWrite(s1_pin,HIGH); digitalWrite(s2_pin,LOW);  digitalWrite(s3_pin,HIGH); digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[11] = analogRead(signal_pin);
    
    // Channel 12 [0,0,1,1] 
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,LOW);  digitalWrite(s1_pin,LOW);  digitalWrite(s2_pin,HIGH); digitalWrite(s3_pin,HIGH); digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[12] = analogRead(signal_pin);
    
    // Channel 13 [1,0,1,1]
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,HIGH); digitalWrite(s1_pin,LOW);  digitalWrite(s2_pin,HIGH); digitalWrite(s3_pin,HIGH); digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[13] = analogRead(signal_pin);
    
    // Channel 14 [0,1,1,1] 
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,LOW);  digitalWrite(s1_pin,HIGH); digitalWrite(s2_pin,HIGH); digitalWrite(s3_pin,HIGH); digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[14] = analogRead(signal_pin);
    
    // Channel 15 [1,1,1,1]
    digitalWrite(ena_pin, HIGH); digitalWrite(s0_pin,HIGH); digitalWrite(s1_pin,HIGH); digitalWrite(s2_pin,HIGH); digitalWrite(s3_pin,HIGH); digitalWrite(ena_pin, LOW); delay(sensor_pause);
    sensor_data[15] = analogRead(signal_pin);

// ----- Show all records with a foreach. -----
    for (int i = 0; i < (sizeof(sensor_data)/sizeof(int)); i++){

      // This would just show each element's data.
      // Serial.print("Sensor ") ; Serial.print(i); Serial.print(" : "); Serial.print(sensor_data[i]); Serial.print ("\n");
      // For the serial plotter with multiple lines, we'll just print them out in order in a tab delimited string.
      
      if (i > 0){
        Serial.print("\t");
      }
      Serial.print(sensor_data[i]);
    };
    Serial.print("\r\n");

    delay(loop_pause);  // Slow down the pace, to reduce MCU load.
    //Serial.print("... END LOOP\n");  
}
