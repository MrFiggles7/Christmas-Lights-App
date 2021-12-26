
void readFirebaseData() {
  unsigned long fireBaseCurrentMillis = millis();
  if (fireBaseCurrentMillis - fireBasePreviousMillis >= fireBaseInterval) {
    fireBasePreviousMillis = fireBaseCurrentMillis;
    GetDocument();   
  }
}

bool DocumentExists(String documentPath) {
  documentPath = documentPath+ "/name";
  if (Firebase.RTDB.getJSON(&fbdo, documentPath.c_str())) {
      String temp(fbdo.payload().c_str());      
      if (temp == "null") {
        currentDocument = 0;
        return false;
      } else {
        return true;
      }
  }  
}

void GetDocument() {
  String documentPath = "animations/" + String(currentDocument);
  String scene;
  if(DocumentExists(documentPath)) {
    
      if (Firebase.RTDB.getJSON(&fbdo, documentPath+ "/frames/0")) {
        scene = scene + fbdo.payload().c_str();
      }      
      if (Firebase.RTDB.getJSON(&fbdo, documentPath+ "/frames/1")) {
        scene = scene + fbdo.payload().c_str();
      }
      
      if (Firebase.RTDB.getJSON(&fbdo, documentPath+ "/frames/2")) {
        scene = scene + fbdo.payload().c_str();
      }
      
      if (Firebase.RTDB.getJSON(&fbdo, documentPath+ "/frames/3")) {
        scene = scene + fbdo.payload().c_str();
      }
      
      if (Firebase.RTDB.getJSON(&fbdo, documentPath+ "/frames/4")) {
        scene = scene + fbdo.payload().c_str();
      }
      if (Firebase.RTDB.getJSON(&fbdo, documentPath+ "/frames/5")) {
        scene = scene + fbdo.payload().c_str();
      }
      
      if (Firebase.RTDB.getJSON(&fbdo, documentPath+ "/frames/6")) {
        scene = scene + fbdo.payload().c_str();
      }
      if (Firebase.RTDB.getJSON(&fbdo, documentPath+ "/frames/7")) {
        scene = scene + fbdo.payload().c_str();
      }
            
      scene.replace("\"","");
      setScene(scene);
      currentDocument++;
    
  } else {
    GetDocument();
  }
}
