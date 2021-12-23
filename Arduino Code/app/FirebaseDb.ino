
void readFirebaseData() {
  unsigned long fireBaseCurrentMillis = millis();
  if (fireBaseCurrentMillis - fireBasePreviousMillis >= fireBaseInterval) {
    fireBasePreviousMillis = fireBaseCurrentMillis;
    GetDocument();   
  }
}

void GetDocument() {
  String documentPath = "animations/" + String(currentDocument);
  String mask = "";
  int brightness = 0;
  
  if (Firebase.RTDB.getJSON(&fbdo, documentPath.c_str())) {
      String temp(fbdo.payload().c_str());
      if (temp == "null") {
        currentDocument = 0;
        GetDocument();
      } else {        
        FirebaseJson payload;
        FirebaseJsonData result;        
        payload.setJsonData(temp);        
        payload.get(result, "brightness");
        if (result.success)
        {
          brightness = result.to<int>();
        }    
        payload.get(result, "frames");
        FirebaseJsonArray frames;
        result.get<FirebaseJsonArray>(frames);
        frames.get(result, 0); // Only doing this because we are not animating yet.
        String scene = result.to<String>();
        setScene(brightness, scene);
        currentDocument++;
      }
      /*
      for (size_t i = 0; i < frames.size(); i++)
      {
        frames.get(result, i);        
        //Print its value
        Serial.print("Array index: ");
        Serial.print(i);
        Serial.print(", type: ");
        Serial.print(result.type);
        Serial.print(", value: ");
        Serial.println(result.to<String>());
      }
      */
  }
  else {
    currentDocument = 0;
    Serial.println(fbdo.errorReason());
  }
}
