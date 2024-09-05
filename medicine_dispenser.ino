#include <WiFi.h>
#include <FirebaseESP32.h>
#include <Wire.h>
#include <RTClib.h>
#include <ESP32Servo.h>  // Include the ESP32Servo library

// Firebase and Wi-Fi configuration
#define FIREBASE_HOST "https://med-disp-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "E9CXZUzoZgBnbfC3nS5cnuntpvjQz1PAVI34I5gG"
#define WIFI_SSID "Khushi"
#define WIFI_PASSWORD "khushi1702"

// Define your Firebase database paths
String dispenseTimePath = "/pill_info/Time";

// Firebase objects
FirebaseData firebaseData;
FirebaseConfig config;
FirebaseAuth auth;

// RTC object
RTC_DS1307 rtc;

// Servo object
const int servoPin = 13;
Servo myServo;  // Create a Servo object

// Buzzer pin
const int buzzerPin = 12;

void setup() 
{
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println(" connected.");

  // Initialize RTC
  if (!rtc.begin()) 
  {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (!rtc.isrunning()) 
  {
    Serial.println("RTC is NOT running!");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }

  // Set up Firebase configuration
  config.host = FIREBASE_HOST;
  config.signer.tokens.legacy_token = FIREBASE_AUTH;

  // Initialize Firebase
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);

  // Attach the servo to the specified pin
  myServo.attach(servoPin); 
  Serial.println("Servo is attached.");

  // Initialize buzzer pin as output
  pinMode(buzzerPin, OUTPUT);
  digitalWrite(buzzerPin, LOW); // Ensure buzzer is off initially
}

void loop() 
{
  // Fetch the time from Firebase
  String dispenseTime; 

  if (Firebase.getString(firebaseData, dispenseTimePath)) 
  {
    dispenseTime = firebaseData.stringData();
    // Remove extra quotes and backslashes from dispenseTime
    dispenseTime.replace("\"", "");
    dispenseTime.replace("\\", "");
    Serial.println("Dispense Time: " + dispenseTime);
  } 
  else 
  {
    Serial.println("Failed to get string: " + firebaseData.errorReason());
  }

  // Get current time from RTC
  DateTime now = rtc.now();
  char currentTime[6];
  sprintf(currentTime, "%02d:%02d", now.hour(), now.minute());

  // Print current RTC time
  Serial.println("Current RTC Time: " + String(currentTime));

  // Compare the time from Firebase with the RTC time
  if (String(currentTime) == dispenseTime) 
  {
    Serial.println("It's time to dispense medicine!");

    // Activate the buzzer
    digitalWrite(buzzerPin, HIGH);
    delay(2000); // Buzzer on for 2 seconds
    digitalWrite(buzzerPin, LOW);

    // Trigger the servo motor
    myServo.write(0);
    delay(2000); // Wait for 2 seconds

    // Rotate servo to 180 degrees
    myServo.write(180);
    delay(2000); // Wait for 2 seconds

    // Rotate servo back to 0 degrees
    myServo.write(0);
    delay(2000); // Wait for 2 seconds
  }
  else 
  {
    Serial.println("Not time yet.");
  }

  // Wait for a minute before checking again
  delay(60000);
}
