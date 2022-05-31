1. Install ESP8266WiFi library for this you need to include below link to file->preferences->additional board manager

   http://arduino.esp8266.com/stable/package_esp8266com_index.json,https://dl.espressif.com/dl/package_esp32_index.json

   After that go to tools-> board ->board manager->write esp8266->install the board
   
2. Now choose board from tool -> board -> ESP8266 boards - > NodeMCU 1.0 ( ESP-12E Module), then upload the code

2. Install Arduino_GFX_Library, download the library from the below link, then go to include library->add zip library-> add the zip version of the Arduino_GFX_Library
   https://www.arduino.cc/reference/en/libraries/gfx-library-for-arduino/

3. Install NTPClient library from "include library->manage library->write 'NTPClient' and search, then download the latest version
   The NTP client enables the appliance or virtual machine to synchronize its internal clock with an NTP server on your network or on the internet.
   You can also configure the NTP client through the UI (the preferred method). For more information, see Performing time synchronization
