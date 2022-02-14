#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <ArduinoJson.h>

#include <WiFiClient.h>

WiFiClient wifiClient;

#include <Arduino_GFX_Library.h>

#if defined(DISPLAY_DEV_KIT)
Arduino_GFX *gfx = create_default_Arduino_GFX();
#else /* !defined(DISPLAY_DEV_KIT) */
Arduino_DataBus *bus = new Arduino_ESP8266SPI(2 /* DC */, 15 /* CS */);
Arduino_GFX *gfx = new Arduino_GC9A01(bus, 16 /* RST */, 0 /* rotation */, true /* IPS */);
#endif

const char* ssid = "Write_your_wifi_name";
const char* password = "Write_your_wifi_password";

const String api_1 = "http://api.openweathermap.org/data/2.5/weather?q=";
const String qLocation = "write_your_city_name_here,write_your_country_name_here"; // write city name,country name
const String api_2 = "&units=metric"; //request return temp in celsius
const String api_3 = "&APPID=";
const String api_key = "Write_your_API_Key_of_openweathermap";  //your api key
const String rqs = api_1 + qLocation + api_2 + api_3 + api_key;

int f_color = ORANGE;

int color = ORANGE;//{ORANGE ,GREEN, BLUE, YELLOW};
int i = 0;
DynamicJsonDocument doc(24576);

void sendRqs(){
  HTTPClient http;
  http.begin(wifiClient, rqs);
  int httpCode = http.GET();

  if (httpCode > 0) { 

    String response = http.getString();
    //Serial.println(response);
    DeserializationError error = deserializeJson(doc, response);

    // Test if parsing succeeds.
    if (error) {

      String errorStr = error.c_str();

      Serial.println(errorStr);

      delay(10000);
    }else{
      Serial.println("deserializeJson() no error.");

      //--- Copy from ArduinoJson Assistant
      float coord_lon = doc["coord"]["lon"];
      float coord_lat = doc["coord"]["lat"];

      JsonObject weather_0 = doc["weather"][0];
      int weather_0_id = weather_0["id"];
      const char* weather_0_main = weather_0["main"];
      const char* weather_0_description = weather_0["description"];
      const char* weather_0_icon = weather_0["icon"];

      const char* base = doc["base"];

      JsonObject main = doc["main"];
      float main_temp = main["temp"];
      float main_feels_like = main["feels_like"];
      float main_temp_min = main["temp_min"];
      float main_temp_max = main["temp_max"];
      int main_pressure = main["pressure"];
      int main_humidity = main["humidity"];

      int visibility = doc["visibility"];

      float wind_speed = doc["wind"]["speed"];
      int wind_deg = doc["wind"]["deg"];

      int clouds_all = doc["clouds"]["all"];

      long dt = doc["dt"];

      JsonObject sys = doc["sys"];
      int sys_type = sys["type"];
      int sys_id = sys["id"];
      const char* sys_country = sys["country"];
      long sys_sunrise = sys["sunrise"];
      long sys_sunset = sys["sunset"];

      int timezone = doc["timezone"];
      long id = doc["id"];
      const char* name = doc["name"];
      int cod = doc["cod"];

      //--- End of ArduinoJson Assistant ---

      // Print values.
      Serial.println("temp_min: " + String(main_temp_min));
      Serial.println("temp_max: " + String(main_temp_max));
      Serial.println("temp: " + String(main_temp));
      Serial.println("humidity: " + String(main_humidity));
      Serial.println("pressure: " + String(main_pressure));
      Serial.println("visibility: " + String(visibility));
      Serial.println("wind speed: " + String(wind_speed));
      Serial.println("wind degree: " + String(wind_deg));
      Serial.println("clouds_all: " + String(clouds_all));

      /*
      Serial.println("sunrise: " + String(sys_sunrise));
      Serial.println("sunset: " + String(sys_sunset));
      Serial.println("timezone: " + String(timezone));
      */
      
      gfx->setCursor(30, 50);
      gfx->setTextColor(color);
      gfx->setTextSize(2);
      gfx->println("Temp:" + String(main_temp));

      
      gfx->setCursor(30, 70);
      gfx->setTextColor(color);
      gfx->setTextSize(2);
      gfx->println("Temp min:" + String(main_temp_min));

      
      gfx->setCursor(30, 90);
      gfx->setTextColor(color);
      gfx->setTextSize(2);
      gfx->println("Temp_max:" + String(main_temp_max));

      gfx->setCursor(30, 110);
      gfx->setTextColor(color);
      gfx->setTextSize(2);
      gfx->println("Humidity:" + String(main_humidity)+"%");

      gfx->setCursor(30, 130);
      gfx->setTextColor(color);
      gfx->setTextSize(2);
      gfx->println("visibility:" + String(visibility)); 

      gfx->setCursor(30, 150);
      gfx->setTextColor(color);
      gfx->setTextSize(2);
      gfx->println("Wind Speed:" + String(wind_speed));

      gfx->setCursor(30, 170);
      gfx->setTextColor(color);
      gfx->setTextSize(2);
      gfx->println("Clouds:" + String(clouds_all)+"%");

      gfx->setCursor(30, 190);
      gfx->setTextColor(color);
      gfx->setTextSize(2);
      gfx->println("Pressure:" + String(main_pressure));
      delay(5000);
      i = i+1;
      Serial.println(i);
      if (i>=3)
      {
        i = 0;
      }
   
    }

  }else{
    Serial.println("http.GET() == 0");
  }
  http.end();   //Close connection
}

void setup() {

  Serial.begin(9600);
  gfx->begin();
  gfx->fillScreen(BLACK);

#ifdef TFT_BL
  pinMode(TFT_BL, OUTPUT);
  digitalWrite(TFT_BL, HIGH);
#endif

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(800);
  }
}

void loop() {
  //display.clear();
  if (WiFi.status() == WL_CONNECTED) {
    sendRqs();

  }else{
   Serial.print("##");
  }
  
  Serial.println("DONE");
 

}
