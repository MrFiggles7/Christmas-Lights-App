void setAll(byte red, byte green, byte blue) {
  for (int i = 0; i < PIXEL_COUNT; i++ ) {
    setPixel(i, red, green, blue);
  }
  strip.show();
}


void setPixel(int Pixel, byte red, byte green, byte blue) {
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
}
