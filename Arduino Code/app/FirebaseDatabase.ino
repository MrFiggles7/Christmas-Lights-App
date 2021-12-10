FirebaseData firebaseData;

void readFirebaseData() {
  unsigned long fireBaseCurrentMillis = millis();
  if (fireBaseCurrentMillis - fireBasePreviousMillis >= fireBaseInterval) {
    fireBasePreviousMillis = fireBaseCurrentMillis;
    Serial.println("Reading...");

    if (Firebase.get(firebaseData, path))
    {
      Serial.println("PASSED");
      Serial.println("PATH: " + firebaseData.dataPath());
      Serial.println("TYPE: " + firebaseData.dataType());
      Serial.print("VALUE: ");
      if (firebaseData.dataType() == "json")
      {
        FirebaseJson &json = firebaseData.jsonObject();
        size_t len = json.iteratorBegin();
        String key, value = "";
        int type = 0;
        for (size_t i = 0; i < len; i++)
        {
          json.iteratorGet(i, type, key, value);
          if (key == "Color") {
            color = value;
          }
          else if (key == "Email") {
            email = value;
          }
          else if (key == "LastStatus") {
            lastStatus = value;
          }
          else if (key == "Brightness") {
            brightness = value.toInt();
          }
        }
        json.iteratorEnd();
      }
      setMasterColor(color);
      Serial.println("------------------------------------");
      Serial.println();
      Serial.println(color);
      Serial.println(email);
      Serial.println(lastStatus);
    }
    else
    {
      Serial.println("FAILED");
      Serial.println("REASON: " + firebaseData.errorReason());
      Serial.println("------------------------------------");
      Serial.println();
    }
  }
}

void setMasterColor(String hexstring) {
  if (color == "offline") {
    brightness = 0;
  }
  long long number = strtoll( &hexstring[1], NULL, 16);
  // Split them up into r, g, b values
  r = number >> 16;
  g = number >> 8 & 0xFF;
  b = number & 0xFF;
}
