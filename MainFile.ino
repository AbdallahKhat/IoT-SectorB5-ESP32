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