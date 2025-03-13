# IoT and MQTT Protocol

## Introduction
The **Internet of Things (IoT)** is a network of physical devices that communicate and exchange data using the internet. These devices range from sensors and embedded systems to industrial automation systems, smart home devices, and more.

To facilitate efficient and lightweight communication in IoT applications, various communication protocols are used. One of the most popular is **MQTT (Message Queuing Telemetry Transport)**.

**Key Components**
  1- Sensors / Actuators
  2- Connectivity 
  3- Modem 
  4- User Interface
---


**Layerd Architechture**
1 - Perception Layes
2 - Network Layes
3 - Processing Layer
4- Application Layer



## IoT Value Chaing

1 - **Device and Sensors**
***
**Prototype Board** -> is only for testing

**key Components** -> CPU - Memory - Modem - OS[linux - RTOS] 

***

2- **Wireless Sensor Netwrok (WSN)**
***
**System of interconnection Sensors that collect and transmit data Wireless**

**KeyFeatures**

1 - Sensors Nodes

2 - Wireless communication

3 - Self Healing and Scalability 

4- **Energy efficiency**

***

3- **IoT GateWay**
***

Since many sensors operate on different communication protocols, we need an IoT
Gateway to bridge the gap.
• IoT Gateways aggregate and preprocess sensor data before sending it to the cloud.
• They provide protocol translation, security, and local decision-making to reduce
cloud dependence.

***
4- **Network Carrier**
***
For large-scale IoT deployments, a reliable Carrier Network is essential for data
transmission.
• This includes cellular networks (3G, 4G, 5G, NB-IoT, LTE, ADSL, Fiber Network) and
other long-range communication methods.
• These networks ensure secure and seamless data transfer between IoT gateways and
cloud platforms.
***

5- **Application Enablement Platform**
***
Cloud-based solution that provides infrastructure, APIs, and tools to develop,
manage, and deploy IoT applications, also acts as a bridge between IoT devices and
end-user applications
***
6 -**Big Data Analytics** 
***
Using AI and Machine Learning, data is analyzed, visualized, and turned into
actionable insights.
• This enables predictive maintenance, anomaly detection, and business intelligence.
Example: Smart factories using real-time analytics to prevent equipment failures.
***
7- **Device and Getwar Remote**
***
Finally, IoT solutions require Remote Device & Gateway Management to
• Ensure smooth operation.
• This involves firmware updates, security patches, and diagnostics to keep IoT systems
running efficiently.
• Remote management is critical for scalability and security in IoT ecosystems.
Examples: Over-the-Air (OTA) updates for smart home devices and remote diagnostics
for industrial machines.
***












## What is MQTT?
**MQTT** is a lightweight messaging protocol designed for small, low-power devices with limited bandwidth. It operates on a **publish-subscribe** model, making it highly efficient for IoT applications.

### Key Features of MQTT:
- **Lightweight & Efficient:** Uses minimal bandwidth, making it ideal for IoT.
- **Publish-Subscribe Model:** Devices (clients) communicate through a central broker.
- **Quality of Service (QoS) Levels:** Ensures message delivery reliability.
- **Persistent Sessions:** Retains information even if the connection drops.
- **Secure Communication:** Supports authentication and encryption (TLS/SSL).

## MQTT Architecture
MQTT follows a **client-broker** architecture:
- **Client:** Can be a publisher (sending data) or subscriber (receiving data).
- **Broker:** Manages message distribution between clients.
- **Topics:** Messages are published to topics, and subscribers receive messages from the topics they subscribe to.

## MQTT QoS Levels
MQTT provides three levels of message delivery:
1. **QoS 0 (At most once):** Fire-and-forget, no guarantee of delivery.
2. **QoS 1 (At least once):** Guaranteed to arrive but may be duplicated.
3. **QoS 2 (Exactly once):** Ensures message delivery without duplication.

## Example MQTT Workflow
1. A **temperature sensor** (client) publishes data to the topic `sensors/temperature`.
2. A **smart dashboard** (another client) subscribes to `sensors/temperature`.
3. The **broker** (e.g., Mosquitto) ensures the dashboard receives the published temperature data.

## Getting Started with MQTT
To use MQTT, you need:
- An **MQTT broker** (e.g., Mosquitto, EMQX, HiveMQ).
- An **MQTT client** (e.g., MQTT Explorer, Eclipse Paho, Node-RED, Python `paho-mqtt`).


## Use Cases of MQTT in IoT
- **Smart Homes:** Automating devices like lights, thermostats, and security systems.
- **Industrial IoT:** Monitoring machinery and predictive maintenance.
- **Healthcare:** Remote patient monitoring.
- **Agriculture:** Smart irrigation and weather monitoring.

## Conclusion
MQTT is a powerful protocol for IoT communication due to its lightweight nature, reliability, and efficiency. It is widely adopted in smart systems, making real-time data exchange seamless and scalable.

### First You need To Establish A Wireless Network[WIFI] 
```CPP
#include<WiFi.h> // including a Wifi Library

const char *UID = "Your sername";
const char *PWD = "Your Password";
void Setup()
{
WiFi.begin(UID , PWD ); // Wifi Begin Communication

  While(WiFi.Status!=WS_CONNECTED) // Cheking For WiFi Connection
{
  Serial.println("Connecting ...");
  delay(500);
}
 Serial.println(" Connection Successfully"); // Connect Done
 Serial.println(" ESB'S IP  :");
 Serial.print(WiFi.localIP());
}
void loop()
{
 Serial.print(WiFi.localIP());
}
```
### First You need To Establish MQTT Protocol Commands
```CPP
#include<WiFi.h> // including a Wifi Library
#include<PubSubClient.h> //  this Library you have to install it first as It Establish the MQTT PRotocol

const char *UID = "Your sername"; // your wifi username
const char *PWD = "Your Password"; // your wifi password

const char mqtt_proker[]= "broker.hive.mq"; // here i use a local broker on the internet Public proker
const char mqtt_port[] = "1883";

WiFiclient Client(espclient);  // here i make  a Wifi Object that include Everything related to my WiFi

// call back function when the Client work as Subs
void CallbackFunction(char * topic , byte * payload , unsigned int len); // Decleration

void Setup()
{
WiFi.begin(UID , PWD ); // Wifi Begin Communication

  While(WiFi.Status!=WS_CONNECTED) // Cheking For WiFi Connection
{
  Serial.println("Connecting ...");
  delay(500);
}
 Serial.println(" Connection Successfully"); // Connect Done
 Serial.println(" ESB'S IP  :");
 Serial.print(WiFi.localIP());

//  Establish Server For Specific Broker
Client.setServer(mqtt_proker,mqtt_port);

Client.setCallback(CallbackFunction);

if(Client.connect("AnyName")
{
Serial.println("Connected Success");
}
else{
Serial.println("Not Connect");
}
void loop()
{
 Serial.print(WiFi.localIP());
}

void CallbackFunction(char * topic , byte * payload , unsigned int len) // implementation
{
  Serial.print("Your Topic IS :");
  Serial.print(topic);
  serial.print("Your Message is : ");
  for(int i = 0 ;i < len ;i++)
    {
      Serial.print((char)payload[i]);
    }
}
```

