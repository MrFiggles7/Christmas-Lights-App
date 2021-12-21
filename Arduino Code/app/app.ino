#include <ESP8266WiFi.h> 
#include <Adafruit_NeoPixel.h>
#include <Firebase_ESP_Client.h>

#define PIXEL_COUNT 200
#define PIXEL_PIN D6
const char* ssid     = "Metropolis";
const char* password = "cryptkeeper4us";
#define FIREBASE_HOST "christmas-lights-19083-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "RF26mOPXlLTwMqBLtKSKvthlwOK6fpz2oxb2yZHD" // secret (40 chars)
#define USER_EMAIL "fingersmagoo+christmas@gmail.com"
#define USER_PASSWORD "ou812ic"
#define API_KEY "AIzaSyCtoGVfq7bo0kQT700uW7mV_RK4upg-A44"
#define FIREBASE_PROJECT_ID "christmas-lights-19083"

#define DELAYVAL 10000

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_RGB + NEO_KHZ800);
FirebaseData fbdo;
FirebaseAuth auth;
FirebaseConfig config;

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting Sketch...");
  setupWiFi();
  config.api_key = API_KEY;
  config.database_url = FIREBASE_HOST;
  auth.user.email = USER_EMAIL;
  auth.user.password = USER_PASSWORD;  
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  strip.begin();
}

void setupWiFi () {
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }  
  Serial.println("");
  Serial.println("WiFi connected");  
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  delay(100);
}

void loop()
{
  readFirebaseData();
  
  strip.clear();
  strip.setBrightness(255);
  //strip.setPixelColor(0, strip.Color(255, 255, 255));
  //strip.setPixelColor(1, strip.Color(255, 0, 0));
  for(int i=0; i<PIXEL_COUNT; i++) { // For each pixel...
    strip.setPixelColor(i, strip.Color(0, 150, 0));

    strip.show();   // Send the updated pixel colors to the hardware.

    delay(DELAYVAL); // Pause before next pass through loop
  }
  //setPixel(0, 255,0,0);
  //setPixel(1, 0,255,0);
  //setPixel(2, 0,0,255);
  ////strip.setPixelColor(2, strip.Color(0, 255, 0));
  //strip.setPixelColor(3, strip.Color(0, 0, 255));
  //strip.setPixelColor(4, strip.Color(255, 0, 255));
  //strip.setPixelColor(5, strip.Color(255, 255, 0));
  //strip.setPixelColor(6, strip.Color(0, 255, 255));
  //strip.setPixelColor(7, strip.Color(0, 255, 255));
  //strip.setPixelColor(8, strip.Color(255, 0, 255));
  //strip.show();
}
