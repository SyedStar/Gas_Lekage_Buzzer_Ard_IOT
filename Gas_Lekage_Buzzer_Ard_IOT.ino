int Buzzer = 32;        // used for ESP32
int Gas_analog = 4;    // used for ESP32
int Gas_digital = 2;   // used for ESP32

void setup() {
  Serial.begin(115200);
  pinMode(Buzzer, OUTPUT);  
  pinMode(Gas_analog, INPUT);    
  pinMode(Gas_digital, INPUT);

   // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

    /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
  */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  int gassensorAnalog = analogRead(Gas_analog);
  int gassensorDigital = digitalRead(Gas_digital);

  Serial.print("Gas Sensor: ");
  Serial.print(gassensorAnalog);
  Serial.print("\t");
  if(gassensorDigital == 1){
  Serial.print("Gas Class: ");
  Serial.print(0);
  }
  else{
  Serial.print("Gas Class: ");
  Serial.print(1);
  }
  Serial.print("\t");
  Serial.print("\t");
  
  if (gassensorAnalog > 1000) {
    Serial.println("Gas");
    digitalWrite (Buzzer, HIGH) ; //send tone
    delay(1000);
    digitalWrite (Buzzer, LOW) ;  //no tone
  }
  else {
    Serial.println("No Gas");
  }
  delay(100);
}
