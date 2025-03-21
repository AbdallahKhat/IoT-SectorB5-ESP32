# IoT and MQTT Protocol



## What is the IOT

The **Internet of Things (IoT)** refers to a vast network of interconnected physical devices that communicate and exchange data over the internet. These devices include sensors, embedded systems, industrial automation equipment, smart home appliances, and more. IoT enables seamless data collection, analysis, and automation, transforming industries and everyday life.

---


## Key Components of IoT

1. **Sensors/Actuators**: Devices that collect data (sensors) or perform actions (actuators) based on received data.
2. **Connectivity**: The medium through which devices communicate (e.g., Wi-Fi, cellular, Bluetooth).
3. **Modem**: Hardware that enables communication over networks.
4. **User Interface**: The interface through which users interact with IoT systems (e.g., mobile apps, web dashboards).
---



## Layered Architecture of IoT

1. **Perception Layer**: The physical layer where sensors and actuators collect and interact with data.
2. **Network Layer**: Handles data transmission between devices, gateways, and the cloud.
3. **Processing Layer**: Processes and analyzes data, often using edge computing or cloud platforms.
4. **Application Layer**: Delivers IoT services and applications to end-users 
---



## IoT Value Chain

### 1. **Devices and Sensors**
   - **Prototype Boards**: Used for testing and development (e.g., Arduino, Raspberry Pi).
   - **Key Components**: 
     - **CPU**: Central processing unit for computation.
     - **Memory**: Storage for data and programs.
     - **Modem**: Enables network connectivity.
     - **Operating System**: Often lightweight OS like Linux or Real-Time Operating Systems (RTOS).
     - **Application on that OS**


### 2. **Wireless Sensor Network (WSN)**
   - A system of interconnected sensors that collect and transmit data wirelessly.
   - **Key Features**:
     1. **Sensor Nodes**: Devices that collect and transmit data.
     2. **Wireless Communication**: Enables data transfer without physical connections.
     3. **Self-Healing and Scalability**: Networks can adapt and expand without manual intervention.
     4. **Energy Efficiency**: Optimized for low power consumption, critical for battery-operated devices.
     5. **Multi-Hop Communication**: Data can be transmitted over multiple 
nodes to extend network coverage

### 3. **IoT Gateway**
   - Acts as a bridge between sensors and the cloud, especially when devices use different communication protocols.
   - **Functions**:
     - Aggregates and preprocesses sensor data.
     - Provides protocol translation, security, and local decision-making to reduce reliance on the cloud.

### 4. **Network Carrier**
   - Essential for large-scale IoT deployments, ensuring reliable data transmission.
   - **Types of Networks**:
     - Cellular (3G, 4G, 5G, NB-IoT, LTE).
     - Wired (ADSL, Fiber Network).
   - **Role**: Ensures secure and seamless data transfer between IoT gateways and cloud platforms.

### 5. **Application Enablement Platform**
   - A cloud-based solution that provides the infrastructure, APIs, and tools for developing, managing, and deploying IoT applications.
   - **Functions**:
     - Acts as a bridge between IoT devices and end-user applications.
     - Enables data storage, processing, and integration with third-party services.

### 6. **Big Data Analytics**
   - Leverages AI and machine learning to analyze, visualize, and derive actionable insights from IoT data.
   - **Applications**:
     - Predictive maintenance: Anticipating equipment failures before they occur.
     - Anomaly detection: Identifying unusual patterns in data.
     - Business intelligence: Improving decision-making through data-driven insights.
   - **Example**: Smart factories using real-time analytics to optimize production and prevent downtime.

### 7. **Device and Gateway Remote Management**
   - Ensures the smooth operation of IoT systems through remote monitoring and management.
   - **Functions**:
     - Firmware updates and security patches delivered Over-the-Air (OTA).
     - Remote diagnostics and troubleshooting.
   - **Importance**: Critical for scalability, security, and maintaining the efficiency of IoT ecosystems.
   - **Examples**: OTA updates for smart home devices, remote diagnostics for industrial machines.
---



## OSI Model

The OSI model is a conceptual framework used to understand and implement standard protocols in network communications. It divides the network communication process into seven layers, each with specific functions:

1. **Physical Layer (Layer 1)**:
   - Deals with the physical connection between devices.
   - Transmits raw bit streams over a physical medium (e.g., cables, radio waves).
   - Examples: Ethernet, USB, Bluetooth.

2. **Data Link Layer (Layer 2)**:
   - Provides node-to-node data transfer—a link between two directly connected nodes.
   - Handles error detection and correction from the physical layer.
   - Examples: Ethernet, PPP, MAC addresses.

3. **Network Layer (Layer 3)**:
   - Manages device addressing, tracks the location of devices on the network, and determines the best way to move data.
   - Handles packet forwarding, including routing through different routers.
   - Examples: IP, ICMP, ARP.

4. **Transport Layer (Layer 4)**:
   - Ensures complete data transfer.
   - Provides reliable data transfer services to the upper layers.
   - Examples: TCP, UDP.

5. **Session Layer (Layer 5)**:
   - Manages sessions between applications.
   - Establishes, manages, and terminates connections between applications.
   - Examples: NetBIOS, PPTP.

6. **Presentation Layer (Layer 6)**:
   - Translates data between the application layer and the network format.
   - Handles data encryption, decryption, compression, and translation.
   - Examples: SSL/TLS, JPEG, MPEG.

7. **Application Layer (Layer 7)**:
   - Closest to the end user.
   - Provides network services directly to applications.
   - Examples: HTTP, FTP, SMTP, DNS.

## TCP/IP Model

The TCP/IP model is a more concise framework used for network communications, primarily focusing on the protocols used in the Internet. It has four layers:

1. **Network Access Layer (Link Layer)**:
   - Combines the functions of the Physical and Data Link layers of the OSI model.
   - Handles the physical transmission of data and the protocols for the local network.
   - Examples: Ethernet, Wi-Fi, ARP.

2. **Internet Layer**:
   - Corresponds to the Network layer in the OSI model.
   - Responsible for logical transmission of data over the entire network.
   - Examples: IP, ICMP, IGMP.

3. **Transport Layer**:
   - Similar to the Transport layer in the OSI model.
   - Ensures reliable data transfer and error correction.
   - Examples: TCP, UDP.

4. **Application Layer**:
   - Combines the functions of the Session, Presentation, and Application layers of the OSI model.
   - Provides protocols for specific applications to communicate over the network.
   - Examples: HTTP, FTP, SMTP, DNS.


| **Aspect**                | **OSI Model**                                                                 | **TCP/IP Model**                                                                 |
|---------------------------|-------------------------------------------------------------------------------|----------------------------------------------------------------------------------|
| **Number of Layers**       | 7 layers                                                                      | 4 layers  or 5 in some reference                                                               |
| **Layer Names**            | Physical, Data Link, Network, Transport, Session, Presentation, Application   | Network Access (Link), Internet, Transport, Application                          |
| **Purpose**                | Theoretical framework for understanding and standardizing network communication| Practical framework for real-world networking, especially the Internet           |
| **Development**            | Developed by the **International Organization for Standardization (ISO)**      | Developed by the **U.S. Department of Defense (DoD)**                            |
| **Usage**                 | Used as a reference model for understanding networks                          | Widely used in real-world implementations (e.g., the Internet)                   |
| **Application Layer**      | Separates Session, Presentation, and Application layers                       | Combines Session, Presentation, and Application into a single Application layer  |
| **Transport Layer**        | Provides both connection-oriented (TCP) and connectionless (UDP) services     | Focuses on TCP (reliable) and UDP (unreliable) for data transfer                |
| **Network Layer**          | Focuses on logical addressing and routing (e.g., IP)                          | Similar focus on logical addressing and routing (e.g., IP)                       |
| **Data Link Layer**        | Handles node-to-node data transfer and error detection                        | Combined into the **Network Access Layer** (handles physical and data link tasks)|
| **Physical Layer**         | Deals with physical transmission of raw bits                                  | Combined into the **Network Access Layer**                                       |

---

## What is MQTT?
**MQTT** is a lightweight messaging protocol designed for small, low-power devices with limited bandwidth. It operates on a **publish-subscribe** model, making it highly efficient for IoT applications.

### MQTT Characteristics:
- **Lightweight & Efficient:** Uses minimal bandwidth, making it ideal for IoT.
- **Publish-Subscribe Model:** Devices (clients) communicate through a central broker.
- **Quality of Service (QoS) Levels:** Ensures message delivery reliability.

### MQTT Architecture
MQTT follows a **client-broker** architecture:
- **Client:** Can be a publisher (sending data) or subscriber (receiving data).
- **Broker:** Manages message distribution between clients.
- **Topics:** Messages are published to topics, and subscribers receive messages from the topics they subscribe to.

### MQTT QoS Levels
MQTT provides three levels of message delivery:
1. **QoS 0 (At most once):** Fire-and-forget, no guarantee of delivery.
2. **QoS 1 (At least once):** Guaranteed to arrive but may be duplicated.
3. **QoS 2 (Exactly once):** Ensures message delivery without duplication.

### Example MQTT Workflow
1. A **temperature sensor** (client) publishes data to the topic `sensors/temperature`.
2. A **smart dashboard** (another client) subscribes to `sensors/temperature`.
3. The **broker** (e.g., Mosquitto) ensures the dashboard receives the published temperature data.

### Getting Started with MQTT
To use MQTT, you need:
- An **MQTT broker** (e.g., Mosquitto, EMQX, HiveMQ).
- An **MQTT client** (e.g., MQTT Explorer, Eclipse Paho, Node-RED, Python `paho-mqtt`).

### Use Cases of MQTT in IoT
- **Smart Homes:** Automating devices like lights, thermostats, and security systems.
- **Industrial IoT:** Monitoring machinery and predictive maintenance.
- **Healthcare:** Remote patient monitoring.
- **Agriculture:** Smart irrigation and weather monitoring.

---

## Practical Implementation
To explore how we applied these concepts in a real-world project using ESP32 and MQTT, check the detailed source code breakdown [here](project-details.md).

## 👥 Contributors
- [@Eng-abdelhamed](https://github.com/Eng-abdelhamed)
- [@zeyadkhaled3](https://github.com/zeyadkhaled3)
- [@AbdallahKhat](https://github.com/AbdallahKhat)
- [@MohamedElsayed-21](https://github.com/MohamedElsayed-21)

## 📄 License
This project is licensed under the [MIT License](LICENSE).

## 📽️ Demo Video
Click the thumbnail below to view the project demo on YouTube Shorts:

[![Watch the Demo](https://img.youtube.com/vi/KN6_ot1hBo0/0.jpg)](https://youtu.be/KN6_ot1hBo0)
