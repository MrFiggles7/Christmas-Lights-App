

//Access Firebase Configuration
unsigned long fireBasePreviousMillis = 0;
const long fireBaseInterval = 10000;
String path = "/glow-status/" + WiFi.macAddress(); //this has to change

//Set LED Configuration
unsigned long ledPreviousMillis = 0;
const long ledInterval = 10000;
String email = "";
String lastStatus = "";
String color = "";
int brightness = 50;
