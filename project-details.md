### **Project Description**

This project is a **motion detection and remote control system** built using **ESP32** and the **MQTT (Message Queuing Telemetry Transport)** protocol. The system detects motion using a **PIR (Passive Infrared) sensor**, sends the data to an **MQTT Broker**, and allows remote control of an LED via MQTT messages. The project demonstrates the integration of IoT concepts, enabling real-time monitoring and control over the internet.

---

### **Step 1: Establish a Wireless Network (Wi-Fi)**

#### **What We Need to Do**:
1. **Include the Wi-Fi Library**:  
  - Use #include <WiFi.h> to include the Wi-Fi library 
2. **Define Wi-Fi Credentials**
3. **Connect to Wi-Fi**:
  - Use `WiFi.begin(SSID, PASSWORD)` to start the Wi-Fi connection. 
#### **Code**:
```cpp
#include <WiFi.h> // Include the Wi-Fi library

const char* SSID = "YourUsername"; // Replace with your Wi-Fi SSID
const char* PASSWORD = "YourPassword"; // Replace with your Wi-Fi password

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  WiFi.begin(SSID, PASSWORD); // Start Wi-Fi connection

  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) { // Check if connected
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP()); // Print the IP address
}
```

### **Step 2: Establish MQTT Protocol Communication**

#### **What We Need to Do**:
1. **Include the MQTT Library**:
   - Use `#include <PubSubClient.h>` to include the MQTT library. 
2. **Define MQTT Broker Details**:
   - Define the MQTT broker address in our case :(`broker.hivemq.com`) and  the port ( `1883`).
3. **Create Wi-Fi and MQTT Client Instances**:
   - Create a `WiFiClient` object to handle the Wi-Fi connection.
   - Create a `PubSubClient` object to handle MQTT communication.

4. **Set Up the MQTT Broker and Callback Function**:
   - Use `client.setServer()` to configure the MQTT broker.
   - Use `client.setCallback()` to define a function that handles incoming MQTT messages.

5. **Connect to the MQTT Broker**:
   - Use `client.connect()` to connect to the MQTT broker.
   - For depugging purpose Print a success or failure message to the Serial Monitor.

6. **Subscribe to a Topic**:
   - Use `client.subscribe()` to subscribe to a topic (e.g., `/test/led`) for receiving messages.

7. **Define the Callback Function**:
   - The callback function processes incoming MQTT messages and prints the topic and payload to the Serial Monitor.

#### **Code**:
```cpp
#include <WiFi.h> // Include the Wi-Fi library
#include <PubSubClient.h> // Include the MQTT library

const char* SSID = "YourUsername"; // Replace with your Wi-Fi SSID
const char* PASSWORD = "YourPassword"; // Replace with your Wi-Fi password

const char* MQTT_BROKER = "broker.hivemq.com"; // Public MQTT broker
const int MQTT_PORT = 1883; // Default MQTT port

WiFiClient espClient; // Create a Wi-Fi client instance
PubSubClient client(espClient); // Create an MQTT client instance

// Callback function to handle incoming MQTT messages
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message received on topic: ");
  Serial.println(topic);
  Serial.print("Message: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

void setup() {
  Serial.begin(9600); // Start serial communication for debugging
  WiFi.begin(SSID, PASSWORD); // Start Wi-Fi connection

  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) { // Check if connected
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP()); // Print the IP address

  // Set up MQTT
  client.setServer(MQTT_BROKER, MQTT_PORT); // Configure MQTT broker
  client.setCallback(callback); // Set the callback function

  // Connect to MQTT broker
  if (client.connect("ESP32Client")) {
    Serial.println("Connected to MQTT Broker!");
    client.subscribe("/test/led"); // Subscribe to a topic
  } else {
    Serial.println("Failed to connect to MQTT Broker!");
  }
}

void loop() {
  client.loop(); // Maintain the MQTT connection
}
```

---

### **Step 3: Integrate Motion Detection and LED Control**

#### **What We Need to Do**:
1. **Define PIR Sensor and LED Pins**:
2. **Read PIR Sensor Data**:
   - Use `digitalRead()` to check the PIR sensor's state (motion detected or not).
3. **Publish Sensor Data to MQTT**:
   - If motion is detected, publish `1` to a topic (e.g., `/test/PIRtest`).
   - If no motion is detected, publish `0` to the same topic.

4. **Control the LED Based on MQTT Messages**:
   - Use the callback function to turn the LED on or off based on the received message.

#### **Code**:
```cpp
#define LED_PIN 12 // Pin for the LED
#define PIR_SENSOR_PIN 14 // Pin for the PIR sensor

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message received on topic: ");
  Serial.println(topic);
  Serial.print("Message: ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();

  // Control the LED based on the message
  if (strcmp(topic, "/test/led") == 0) {
    if ((char)payload[0] == '1') {
      digitalWrite(LED_PIN, HIGH); // Turn on the LED
    } else {
      digitalWrite(LED_PIN, LOW); // Turn off the LED
    }
  }
}

void setup() {
  pinMode(LED_PIN, OUTPUT); // Set LED pin as output
  pinMode(PIR_SENSOR_PIN, INPUT); // Set PIR sensor pin as input

  Serial.begin(9600);
  WiFi.begin(SSID, PASSWORD);

  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("ESP32 IP Address: ");
  Serial.println(WiFi.localIP());

  client.setServer(MQTT_BROKER, MQTT_PORT);
  client.setCallback(callback);

  if (client.connect("ESP32Client")) {
    Serial.println("Connected to MQTT Broker!");
    client.subscribe("/test/led");
  } else {
    Serial.println("Failed to connect to MQTT Broker!");
  }
}

void loop() {
  client.loop(); // Maintain MQTT connection

  // Read PIR sensor state
  int pirState = digitalRead(PIR_SENSOR_PIN);
  
  // Implement a non-blocking 1 second delay
  static unsigned long time = 0;
  if ((millis() - time) >= 1000) {

    if (pirState == HIGH) {
      client.publish("/test/PIRtest", "1"); // Motion detected
    } else {
      client.publish("/test/PIRtest", "0"); // No motion
    }
    
    time = millis();
  }
}
```
