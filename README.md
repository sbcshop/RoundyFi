# Roundy
<img src= "https://github.com/sbcshop/Roundy/blob/main/images/img1.png" />
<img src= "https://github.com/sbcshop/Roundy/blob/main/images/img.png" />

## RoundyFi
### RoundyFi is a round LCD display based on ESP-12E along with a compact and stylish 1.28-inch display module of 240×240 resolution, 65K RGB colors, clear and colorful displaying effect, expand its engagement with your project. RoundyFi comes with an embedded GC9A01 Driver and SPI Interface that minimize the required IO pins.
<img src= "https://github.com/sbcshop/Roundy/blob/main/images/img3.png" />

See there is a folder name RoundyFi, inside this folder, there are various applications:-
  * **Display Weather** -> Display the current weather via the "OpenWeatherMap" website, first of all, you need to make an account in OpenWeatherMap
    https://openweathermap.org/api and copy the API key and paste in the code, 
    Download the Arduino IDE https://www.arduino.cc/en/software
    There are also various libraries you need to install, we mention the libraries in a text file, which is inside the folder
    <img src= "https://github.com/sbcshop/Roundy/blob/main/images/img2.png" />
  
  * **Make Server**  -> Make server using RoundyFi. There are also various libraries you need to install, we mention the libraries in a text file, which is inside the folder.
    From this, we can communicate between server and client. for example, we make the mobile phone a client and RoundyFi as a server
    <img src= "https://github.com/sbcshop/Roundy/blob/main/images/img4.png" />

  * **Wifi Clock**  -> Make smart clock using wifi, it displays current time and week, using the internet. There are also various libraries you need to install, we mention the             libraries in a text file, which is inside the folder
    <img src= "https://github.com/sbcshop/Roundy/blob/main/images/img5.png" />

## RoundyPi
### RoundyPi is a round LCD display based on RP2040 along with a compact and stylish 1.28-inch display module of 240×240 resolution, 65K RGB colors, clear and colorful displaying effect, expand its engagement with your project. RoundyPi comes with an embedded GC9A01 Driver and SPI Interface that minimize the required IO pins. 
<img src= "https://github.com/sbcshop/Roundy/blob/main/images/img7.png" />

See there is a folder name RoundyPi, inside this folder, there are various applications:-
In this device we use Micropython and Circuit python(Adafruit Industries) both 

  * **Connect Air Monitoring Sensor** -> (Use Micropython) We add the four GP pins for Input/Output devices(GP0,GP1,GP2,GP3).For example, We connect Air monitoring breakout,         save this file "pmsa003.py" in the pico, this is the library of the air monitor sensors. and for round LCD you need to drag and drop the round LCD firmware "firmware.uf2".       for this first you need to press the boot button then connect the USB, don,t release the button until you connect the USB to the laptop. then you see a new device named         "RPI-RP2" drag this file "firmware.uf2" to this device as shown in figure 
  <img src= "https://github.com/sbcshop/Roundy/blob/main/images/img13.png" />
  <img src= "https://github.com/sbcshop/Roundy/blob/main/images/img6.png" />

  * **Display Images** -> For display images, I use CircuitPython because it is very easy, it is developed by adafruit industries, First of all, we need to insert the circuit python to the pico(it is circuit python firmware "adafruit-circuitpython-raspberry_pi_pico-en_US-7.1.1.uf2"). for this first you need to press the boot button then connect the USB, don,t release the button until you connect the USB to the laptop. then you see a new device named "RPI-RP2" drag this file 
    "adafruit-circuitpython- raspberry_pi_pico-en_US-7.1.1.uf2" to this device as shown in figure 
  <img src= "https://github.com/sbcshop/Roundy/blob/main/images/img13.png" />  
  When you properly insert the circuitpython then you see a new device looks like below image:-
  <img src= "https://github.com/sbcshop/Roundy/blob/main/images/img11.png" />  
  
  
  
  * **Memory card reader** -> 







