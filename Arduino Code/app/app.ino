#include <ESP8266WiFi.h> 
#include <Adafruit_NeoPixel.h>
#include <WiFiManager.h>
#include <FirebaseESP8266.h>
#include <FirebaseESP8266HTTPClient.h>
#include <FirebaseFS.h>
#include <FirebaseJson.h>

#define PIXEL_COUNT 13
#define PIXEL_PIN D6
const char* ssid     = "Metropolis";
const char* password = "cryptkeeper4us";
extern long long r = 0;
extern long long g = 0;
extern long long b = 0;

#define FIREBASE_HOST "glownameplate-default-rtdb.firebaseio.com/" //change this to not my nameplate stuff :)
#define FIREBASE_AUTH "G1KSHjZ8Y3rxaoau8wpIrs1Xv8WS4RhBqO0dopmW" // secret (40 chars)

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800); //Riley, this might need to be NEO_RGB, not sure yet

void setup()
{
  Serial.begin(115200);
  Serial.println("Starting Sketch...");
  pinMode(PIXEL_PIN, OUTPUT);
  setupWiFi(); 
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true); 
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
	
}
