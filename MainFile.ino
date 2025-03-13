#include <WiFi.h>
#include <PubSubClient.h>


// Time delay for publishing messages
#define TIME_DELAY 5000  

#define LED_PIN 12
#define PIR_SENSOR_PIN 14  // Define PIR sensor pin

String message;
const char SSID[] = "Khater";  // WiFi SSID
const char PASS[] = "KhaterAB123";      // WiFi Password

const char *MQTT_BROKER = "broker.emqx.io";  // MQTT Broker
const int MQTT_PORT = 1883;                     // Default MQTT Port

WiFiClient espClient;            // WiFi client instance
PubSubClient client(espClient);  // MQTT client instance
bool Flag = 0;

void setup() {
  pinMode(12, OUTPUT); // Set pin 26  led as an output (LED)
  pinMode(27, OUTPUT); // Set pin 26  led as an output (LED)

  pinMode(PIR_SENSOR_PIN, INPUT); // Set pin 27 PIR sensor as input
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
  client.setServer(MQTT_BROKER, MQTT_PORT); // Configure MQTT broker settings
  client.setCallback(callback); // Assign the callback function

  // Connect to MQTT broker
  if (!client.connect("AbdallahKhater")) {
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
  client.loop(); // Keep the MQTT connection alive
  // Read PIR sensor state
  int pirState = digitalRead(PIR_SENSOR_PIN);
  static int time = 0; 
  if((millis() - time) >= 1000)
  {
    if(pirState == 1)
    {
      Serial.println(pirState);
      client.publish("/Test/PIRtest", "1"); // Publish motion detected message
      digitalWrite(27,HIGH);
    }
    else if(pirState == 0)
    {
    Serial.println(pirState);
    client.publish("/Test/PIRtest", "0"); // Publish motion detected message
    digitalWrite(27 , LOW);
    }
    time = millis();
  }
  if(Flag == 1) digitalWrite(27,HIGH);
  else digitalWrite(27,LOW);
 
}

// Callback function: Handles incoming messages
void callback(char *topic, byte *payload, unsigned int length) {
  Serial.print("Message received on topic: ");
  Serial.println(topic);

  message = ""; // Clear the message before appending new data
  for (int i = 0; i < length; i++) {
    message += (char)payload[i];
  }
  Serial.println("Message: " + message);

  // Check message content and update Flag accordingly
  int msg = message.toInt();
  analogWrite(12,msg);
  if(message == "LED_ON")
  {
    Flag = 1;
  }
  else
  {
    Flag = 0;
  }

}
