

void readFirebaseData() {

    Serial.println("Reading...");
    String documentPath = "animations/" + String(currentDocument);
    String mask = "";
    Serial.print("Get a document... ");

    if (Firebase.RTDB.getJSON(&fbdo, documentPath.c_str())) {
        Serial.printf("ok\n%s\n\n", fbdo.payload().c_str());
        FirebaseJson payload;
        payload.setJsonData(fbdo.payload().c_str());

        size_t len = payload.iteratorBegin();
        String key, value = "";
        int type = 0;
        for (size_t i = 0; i < len; i++)
        {
          payload.iteratorGet(i, type, key, value);
          if (key == "brightness") {
            brightness = value.toInt();
          } else if(key == "frames") {
            
          }
          
          Serial.println(key);
          Serial.println(value);
        }
    }
    else {
      currentDocument = 0;
      Serial.println(fbdo.errorReason());
    }  
}
