## RoundyFi
<img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img.png" />
<img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img1.png" />


### RoundyFi is a round LCD display based on ESP-12E along with a compact and stylish 1.28-inch display module of 240×240 resolution, 65K RGB colors, clear and colorful displaying effect, expand its engagement with your project. RoundyFi comes with an embedded GC9A01 Driver and SPI Interface that minimize the required IO pins.
<img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img3.png" />


## Steps To Setup The RoundyFi
1. Download and install Arduino IDE 
   https://www.arduino.cc/en/software

2. Open Arduino IDE
   <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img6.JPG" />

3. Now install Esp8266 board, for this go to file -> preferences
  <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img7.png" />
  
   * Paste two urls,in "additional board manager urls" 
     ```http://arduino.esp8266.com/stable/package_esp8266com_index.json```
     
     ```https://dl.espressif.com/dl/package_esp32_index.json```
     
     <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img8.png" />
   
   * Now install ESP8266 board, go tools -> boards -> board manager
     <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img9.png" />
     
   * Write ESP8266 in search bar
    <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img10.png" />
  
See there is a folder name RoundyFi, inside this folder, there are various applications:-
  * **Display Weather** -> Display the current weather via the "OpenWeatherMap" website, first of all, you need to make an account in OpenWeatherMap
    https://openweathermap.org/api and copy the API key and paste in the code, 
    Download the Arduino IDE https://www.arduino.cc/en/software
    There are also various libraries you need to install, we mention the libraries in a text file, which is inside the folder
    <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img2.png" />
  
  * **Make Server**  -> Make server using RoundyFi. There are also various libraries you need to install, we mention the libraries in a text file, which is inside the folder.
    From this, we can communicate between server and client. for example, we make the mobile phone a client and RoundyFi as a server
    <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img4.png" />

  * **Wifi Clock**  -> Make smart clock using wifi, it displays current time and week, using the internet. There are also various libraries you need to install, we mention the             libraries in a text file, which is inside the folder
    <img src= "https://github.com/sbcshop/RoundyFi/blob/main/images/img5.png" />

