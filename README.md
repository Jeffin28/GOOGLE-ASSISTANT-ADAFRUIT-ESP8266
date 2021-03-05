# GOOGLE-ASSISTANT-ADAFRUIT-ESP8266
## Overview

<p align="center">
  <img src="IMG/ADA_COVER.png" width="400" align="center">
</p 

**Adafruit IO** is a platform designed to display, respond, and interact with your project's data. Display your data in real-time, online Make your project internet-connected: Control motors, read sensor data, and more! Connect projects to web services like ***Twitter, RSS feeds, weather services***, etc. Connect your project to other internet-enabled devices. **Adafruit MQTT** is widely used in ***IoT*** (Internet of Things) embedded applications, where every sensor is connected to a server and we have access to control them over the internet. The MQTT Client module of NodeMCU is according to version **3.1.1** of the MQTT protocol. Make sure that your broker supports and is correctly configured for version 3.1.1. let’s see the functions used for MQTT on NodeMCU.

**IFTTT** defines a clear and concise protocol that your service’s API will implement. Each trigger and action for your service will map 1-to-1 to an API endpoint on your service built specifically for IFTTT. Trigger endpoints will be event streams that **IFTTT** will poll for new data. Conversely, action endpoints will be writable endpoints that **IFTTT** will send data to. For services that use OAuth, **IFTTT** is fully compatible with a couple of the common flavours of ***`OAuth 2.0`***.


## Concept

<p align="center">
  <img src="IMG/ADA_CONCEPT.png" width="400" align="center">
</p
  
<p><br>
<div align="center">  
  
I have used a `publish`and `subscribe` method for current demonstration.**ESP8266-12E** module incuded as a microcontroller for the communication with **Adafruit IO** and **IFTTT**.

</div>

Here we have some points to note:

> - You must need an **Adafruit IO** and **IFTTT** console/account for the demonstation.Details on below section (**Steps**). 
> - This concept works on ESP8266 Arduino Core v2.4.2 and v2.4.0.
> - For  **Adafruit IO**, please remember `key` and `feed` parameters along with your `username`:


## Software
* [Arduino IDE](https://www.arduino.cc/en/Main/Software) for Windows, Linux or Mac OS.

## Steps :
 1. **Download** the repo.
 
 2. For those who don't have an **Adafruit IO** and **IFTTT** console/account 😇 download the ***ADAFRUIT_IFTTT_GOOGLE ASSISTANT*** named pdf from the **DOC** folder and
    carefully read it.
    
 3. Open **LIB** folder from the downloaded repo then extract the `ZIP` file and place the 2 folders into your Arduino local directory folder
    (libraries). 
    Folders(libraries) with name given below :
    
    - Adafruit_IO_Arduino
    - Adafruit_MQTT_Library
    
    You have an alternate option to download the library from the Arduino library manager. But I am not suggesting that way in this case 👎. 
    
 4. The **source code** for our ESP8266 simulation can be found in the **CODE** folder. Open **source code** from the downloaded repo and make some changes as mentioned below :
   
   - Open **global.h** and provide your wifi router's `ssid` and `password` :
    
<p align="center">
  <img src="IMG/Screenshot%20(135).png" width="700" align="center">
</p  
  
<p><br> 
  
   - Open **ada.cpp** and fill your credentials here 👇 . For more info refer the document page ***number 2***.
   - Open the source code and do changes by Adafruit IO USERNAME & KEY.     
      
<p align="center">
  <img src="IMG/Screenshot%20(136).png" width="700" align="center">
</p        
  
<p><br>
  
   - Paste the publish and subscribe feed name in ada.h to the marked space:
   
<p align="center">
  <img src="IMG/Screenshot%20(137).png" width="700" align="center">
</p        
  
<p><br>  
  
## Compatibility
This library was tested with the NodeMCU V1.0 & ESP8266-12E board. It should also work with other standard ESP8266 that are compatible with the Arduino IDE.
ESP8266 core version that I have tested is `2.4.2`. 

## Working & Testing 
Demonstration of `publish` and `subscribe` between **ESP8266** and **Adafruit_IO** dashboard described in the documentation from ***page No:3 to 5***. 

WiFi Connection status :

<p><br>
<p align="center">
  <img src="IMG/Screenshot%20(138).png" width="600" align="center">
</p

Initial **Publish** and **Subscribe** status:

- Publish to IO:

<p><br>
<p align="center">
  <img src="IMG/Screenshot%20(142).png" width="600" align="center">
</p 
 
Subscribed message on ***ESP8266*** serial monitor from ***Adafruit_IO*** :

<p><br>
<p align="center">
  <img src="IMG/Screenshot%20(141).png" width="600" align="center">
</p   
  
 
<p><br>
<p align="center">
  <img src="IMG/Screenshot%20(85).png" width="240" align="center">
</p  
