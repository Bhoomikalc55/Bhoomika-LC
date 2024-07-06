Title:-IoT-Based Proactive Sensing System

>>Here are the workflow functionalities of the system

RFID Detection:The RFID reader detects a patient's RFID card when they enter or exit a room.
Two consecutive detections of the RFID tag are required to distinguish between entering and leaving.

Entry and Exit Detection:Upon entering the room, the RFID tag is detected near the doorway.
When leaving, the tag is detected again as the patient crosses the threshold.

Arduino Uno Integration:The Arduino Uno processes the RFID data and triggers subsequent actions based on entry or exit detection.

GSM Module Activation:When an exit is detected, the Arduino triggers the GSM module.

SOS SMS Notification:The GSM module sends an SOS SMS to the patient's guardian.

GPS Tracking Link:The SMS includes a real-time GPS tracking link generated by the GPS module.

Guardian Monitoring:Guardians can monitor the patient's real-time location through the provided GPS tracking link.

Emergency Response:Guardians receive timely alerts, enabling them to respond promptly to any emergencies or unexpected exits.

IoT System Reliability:The integration of these IoT components ensures a reliable system for tracking patient movements within the room.

Peace of Mind:Guardians benefit from real-time tracking and timely alerts, providing peace of mind regarding the patient's location and well-being.


Result-
• RFID Detection: When patients pass through the doorway, the RFID reader accurately identifies the presence of RFID cards or tags. The logic of the double detection made a clear distinction between entering and leaving.

• SMS Alert Generation: The system continuously alerted the guardian with an SOS SMS by triggering the GSM module when it detected an exit.

• System Reliability: A smooth and responsive monitoring system was made possible by the integration of the GPS, GSM, and Arduino Uno modules.

