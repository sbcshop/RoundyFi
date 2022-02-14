#include "ESP8266WiFi.h"
#include <Arduino_GFX_Library.h>

#if defined(DISPLAY_DEV_KIT)
Arduino_GFX *gfx = create_default_Arduino_GFX();
#else /* !defined(DISPLAY_DEV_KIT) */
Arduino_DataBus *bus = new Arduino_ESP8266SPI(2 /* DC */, 15 /* CS */);
Arduino_GFX *gfx = new Arduino_GC9A01(bus, 16 /* RST */, 0 /* rotation */, true /* IPS */);
#endif /* !defined(DISPLAY_DEV_KIT) */

const char* ssid = "Write_your_wifi_name";
const char* password =  "Write_your_wifi_password";
 
WiFiServer wifiServer(80);
 
void setup() {
 
  Serial.begin(115200);
  gfx->begin();
  gfx->fillScreen(BLACK);

#ifdef TFT_BL
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
#endif
  gfx->setCursor(65, 30);
  gfx->setTextColor(ORANGE);
  gfx->setTextSize(3);
  gfx->println("Server");
  delay(1000);
 
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting..");
  }
 
  Serial.print("Connected to WiFi. IP:");
  Serial.println(WiFi.localIP());
 
  wifiServer.begin();
}
 
void loop()
{
  gfx->setCursor(65, 30);
  gfx->setTextColor(ORANGE);
  gfx->setTextSize(3);
  gfx->println("Server");
  
  WiFiClient client = wifiServer.available();
  if (client) 
  { 
    
    while (client.connected()) 
    {
      while (client.available()>0) 
      {
        char c = client.read();
        Serial.write(c);
        gfx->setCursor(120, 100);
        gfx->setTextColor(ORANGE);
        gfx->setTextSize(5);
        gfx->println(c);
        delay(2000);
        gfx->setCursor(120, 100);
        gfx->setTextColor(BLACK);
        gfx->setTextSize(5);

        gfx->println(c);
        }
      delay(10);
    }
    client.stop();
    Serial.println("Client disconnected");
  }
}
