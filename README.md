# Connected_Coffee_Maker

_DESCRIPTION_ : 

To control my coffee maker, I had to create a web server. It has been stored into an ESP32, with it, it's possible to control the power state of the machine and choose the size of the coffee. <br><br>
I also added a water sensor to have the water level into the water tank. 

_ESP32_ : 

<img width="250" alt="Capture d’écran 2021-07-09 à 11 29 22" src="https://user-images.githubusercontent.com/54947603/125057311-5ed45280-e0a9-11eb-96a8-4f94c4db7838.png">

_WATER SENSOR_ :

<img width="200" alt="Capture d’écran 2021-07-09 à 11 29 37" src="https://user-images.githubusercontent.com/54947603/125055713-cbe6e880-e0a7-11eb-8ca7-cff19969be24.png">

_HERE THE RESULT_ : <br><br>
_CLASSIC MODE_ :

<img width="438" alt="Capture d’écran 2021-07-09 à 11 29 22" src="https://user-images.githubusercontent.com/54947603/125057017-15840300-e0a9-11eb-9b96-c053dc202b68.png">


_DARK MODE_ :

<img width="448" alt="Capture d’écran 2021-07-09 à 11 29 37" src="https://user-images.githubusercontent.com/54947603/125057031-1a48b700-e0a9-11eb-8252-964dd0e34e9b.png">


_FINAL ASSEMBLY_ :

<img width="500" alt="Capture d’écran 2021-07-09 à 11 29 37" src="https://user-images.githubusercontent.com/54947603/125058730-db1b6580-e0aa-11eb-82f5-0ca763584735.png">

The relay is controlled with a GPIO pin and activates the power supply of the coffee maker. When you click "ON", a message appears (on the web app) saying : "Please wait a minute..." to give the time for the machine to warm up ! You also have in this example, the turn on of the green LED, and the turn off of the red LED. <br><br>
For the 2 buttons, both are controlled with GPIO. When you cick on your coffee size, the pin goes to the high state for a second (just enough to activate the coffee maker).
<br>

_SOURCES_ : 
  - https://tommydesrochers.com/la-meilleure-methode-pour-heberger-une-interface-web-sur-esp32-version-avancee-esp32-ep4/
  - https://www.w3schools.com/w3css/w3css_references.asp#margin
