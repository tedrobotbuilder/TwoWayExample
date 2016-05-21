float battVolts = 0;

void setup() {
  delay(100); //wait for everythign to power up 
  Serial.begin(9600);

  battVolts = 8.01;
}

void loop() {  
  Serial.print("bv");
  Serial.print(battVolts);
  Serial.println("#");
  delay(300);
}

// Get incoming data from USB
void serialEvent() {
  delay(1);
  static String  s_USBDataString = "";
  
  while (Serial.available()) {
    // get the new byte:
    char inChar = (char)Serial.read();
    s_USBDataString += inChar;
    s_USBDataString.trim();
    if(inChar=='#'){ // we got to the end of the string
      USBRead(s_USBDataString);
      s_USBDataString = "";
    }
  }
}


// Parse and put data from USB Serial 
void USBRead(String p_USBDataString) {
  String stringParsedData = p_USBDataString;
  
  stringParsedData = stringParsedData.substring(2, stringParsedData.indexOf("#"));
  char charParsedData[stringParsedData.length()+1];
  stringParsedData.toCharArray(charParsedData, stringParsedData.length()+1);
  float floatParsedData = atof(charParsedData);
  
  if (p_USBDataString.startsWith("bv")) { // change robot's linefollow speed
    
    battVolts=(floatParsedData);
  }
}
