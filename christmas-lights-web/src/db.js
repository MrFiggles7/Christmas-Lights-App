// Conveniently import this file anywhere to use db

import firebase from 'firebase/app'
import 'firebase/firestore'

const firebaseConfig = {
    apiKey: "AIzaSyCtoGVfq7bo0kQT700uW7mV_RK4upg-A44",
    authDomain: "christmas-lights-19083.firebaseapp.com",
    projectId: "christmas-lights-19083",
    storageBucket: "christmas-lights-19083.appspot.com",
    messagingSenderId: "591342154203",
    appId: "1:591342154203:web:c1c7d4ff00921e395177fe",
    measurementId: "${config.measurementId}"
  };

export const db = firebase
    .initializeApp(firebaseConfig)
    .firestore()


// Export types that exists in Firestore - Uncomment if you need them in your app
// const { Timestamp, GeoPoint } = firebase.firestore
// export { Timestamp, GeoPoint }
