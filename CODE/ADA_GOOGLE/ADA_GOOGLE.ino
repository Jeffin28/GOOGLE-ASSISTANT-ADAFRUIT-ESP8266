#include "ada.h"
#include "global.h"
#include "random.h"

void setup() 
{
  Serial.begin(9600); 
  pinMode(2,OUTPUT);
  set_wifi();
  init_Ada_parse(); 
  Init_Ada_connect();
}

void loop() 
{
  Google_Callback();
}
