#include <WiFi.h>
#include <PubSubClient.h>

// ----------------------------------------------------------
// Configuration Settings (Modify as needed)
// ----------------------------------------------------------

// Time delay for publishing messages (in milliseconds)
#define TIME_DELAY 5000

// Pin definitions
#define DIGITAL_LED_PIN 27                   // LED for simple on/off control
#define PWM_LED_PIN     12                   // LED for intensity control via analogWrite (limit: 0~255)
#define PIR_SENSOR_PIN  14                   // PIR sensor pin

#define CLIENT_ID "YOUR_CLIENT_ID"           // Set your desired MQTT client ID here

// WiFi Credentials
const char SSID[] = "YOUR_WIFI_SSID";        // WiFi SSID
const char PASS[] = "YOUR_WIFI_PASSWORD";    // WiFi Password

const char *MQTT_BROKER = "broker.emqx.io";  // MQTT Broker Used
const int MQTT_PORT = 1883;                  // Default MQTT Port


// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------

String message;

WiFiClient espClient;            // WiFi client instance
PubSubClient client(espClient);  // MQTT client instance


// ----------------------------------------------------------
// Functions
// ----------------------------------------------------------

void setup() {

  // Set pin mode for LEDs, PIR sensor.
  pinMode(DIGITAL_LED_PIN, OUTPUT);
  pinMode(PWM_LED_PIN, OUTPUT);
  pinMode(PIR_SENSOR_PIN, INPUT);

  // Begin serial for debugging
  Serial.begin(9600);

  // Connect to WiFi
  WiFi.begin(SSID, PASS);
  Serial.print("Connecting to WiFi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected to WiFi!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  // Set up MQTT
  client.setServer(MQTT_BROKER, MQTT_PORT);  // Configure MQTT broker settings
  client.setCallback(callback);              // Assign the callback function

  // Connect to MQTT broker
  if (!client.connect(CLIENT_ID)) {
    Serial.println("Failed to connect to MQTT Broker!");
  } else {
    Serial.println("Connected to MQTT Broker.");

    // Subscribe to topic
    if (client.subscribe("/test/led")) {
      Serial.println("Subscribed to topic: /test/led");
    } else {
      Serial.println("Subscription failed!");
    }
  }
}


void loop() {

  client.loop();  // Keep the MQTT connection alive

  // Read PIR sensor state
  int pirState = digitalRead(PIR_SENSOR_PIN);

  static unsigned long time = 0;

  if ((millis() - time) >= TIME_DELAY) {           // Freq. of publishing to /test/PIRtest topic
   
    if (pirState == 1) {
      Serial.println(pirState);
      client.publish("/test/PIRtest", "1");  
      digitalWrite(27, HIGH);
    } 
    
    else if (pirState == 0) {
      Serial.println(pirState);
      client.publish("/test/PIRtest", "0");
      digitalWrite(27, LOW);
    }
    
    time = millis();
  }

}


// Function to check if message is a numeric number.
bool isNumeric(const String &str) {
  // Empty string is not numeric.
  if (str.length() == 0) return false;
  
  // Allow a leading '-' for negative numbers
  int start = (str.charAt(0) == '-') ? 1 : 0;
  
  for (int i = start; i < str.length(); i++) {
    if (!isDigit(str.charAt(i))) {
      return false;
    }
  }
  return true;
}


// Callback function: Handles incoming messages.
void callback(char *topic, byte *payload, unsigned int length) {

  Serial.print("Message received on topic: ");
  Serial.println(topic);

  message = "";  // Clear the message before appending new data

  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }

  Serial.println("Message: " + message);

  // if message is numeric ---> send to analog led
  if(isNumeric(message)){
    analogWrite(PWM_LED_PIN, message.toInt());
  }
  else if (message == "LED_ON") {
    digitalWrite(DIGITAL_LED_PIN, HIGH);
  } 
  else if(message == "LED_OFF"){
    digitalWrite(DIGITAL_LED_PIN, LOW);
  }

}

