#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include "ada.h"

/*++++++++++++++++++Obj declaration++++++++++++++++++*/
WiFiClient Ada;                                                                            
Adafruit_MQTT_Client    Amqtt(&Ada, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Subscribe Rec     = Adafruit_MQTT_Subscribe(&Amqtt, AIO_USERNAME"/feeds/SUBSCRIBE FEED NAME FROM IFTTT");             
Adafruit_MQTT_Publish   Txmss   = Adafruit_MQTT_Publish(&Amqtt, AIO_USERNAME"/feeds/SUBSCRIBE FEED NAME TO ADAFRUIT");
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*+++++++++++++++Feedbck declaration+++++++++++++++++*/
char Feedback_on[]      = "Hey!! Light is ON";
char Feedback_off[]     = "Hey!! Light is OFF";
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/

/*+++++++++++++++++Fn declaration++++++++++++++++++++*/
void init_Ada_parse(void);
void Google_Callback(void);
void Init_Ada_connect(void);
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*++++++++++++To ping Ada parsing++++++++++++++++++++*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/
void init_Ada_parse(void)
{
  Amqtt.subscribe(&Rec); 
}       
/*++++++++++++++To Make callback++++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
void Google_Callback(void)
{ 
  Adafruit_MQTT_Subscribe *subscription;
  while((subscription = Amqtt.readSubscription(5000))) 
  {
    if (subscription == &Rec) 
    {                  
      int Rec_State = atoi((char *)Rec.lastread);
      
      switch(Rec_State)
      {
        case 1  :  Txmss.publish(Feedback_on);
                   Serial.printf("Published value is:%s\n",Feedback_on);
                   break; 
        case 0  :  Txmss.publish(Feedback_off);  
                   Serial.printf("Published value is:%s\n",Feedback_off);          
                   break; 
        default :  Serial.println("Erro packet");
                   break;         
      }                              
    }
  }
}
/*+++++++++++++For Ada connection+++++++++++++++++++*/
/*++++++++++++++++++++++++++++++++++++++++++++++++++*/
void Init_Ada_connect(void) 
{  
  uint8_t ret,retries = 3;
  
  if (Amqtt.connected()) 
    return;

  while ((ret = Amqtt.connect()) != 0) 
  { 
    Serial.println(Amqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    Amqtt.disconnect();
    delay(5000); 
    retries--;
    if (retries == 0) 
      while (1);
  }
  Serial.println("Ada MQTT Connected!");
  Txmss.publish("Ada client Connected!");
}
