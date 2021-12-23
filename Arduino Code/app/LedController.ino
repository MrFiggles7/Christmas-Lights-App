void setAll(byte red, byte green, byte blue) {
  for (int i = 0; i < PIXEL_COUNT; i++ ) {
    setPixel(i, red, green, blue);
  }
  strip.show();
}

void setScene(int brightness, String scene) {
  strip.clear();
  strip.setBrightness(brightness);
  int ledNumber = 0;
  while(scene.indexOf('|') > 0){
    String led = scene.substring(0, scene.indexOf('|'));
    scene = scene.substring(scene.indexOf('|')+1, scene.length());
    setPixel(ledNumber, led);
    ledNumber++;
  }
  setPixel(ledNumber++, scene);
  strip.show();
}

void setPixel(int led, String rgb) {
  String r = rgb.substring(0, rgb.indexOf(','));
  String g = rgb.substring(r.length()+1, rgb.lastIndexOf(','));
  String b = rgb.substring(rgb.lastIndexOf(',')+1, rgb.length()); 
  strip.setPixelColor(led, strip.Color(r.toInt(), g.toInt(), b.toInt()));
}

void setPixel(int led, byte red, byte green, byte blue) {
  strip.setPixelColor(led, strip.Color(red, green, blue));
}
