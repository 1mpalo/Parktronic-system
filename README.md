# Parktronic-system
The idea is to make a parktronic system which is going to help you with parking.
# Recommended IDE Setup
I used Arduino IDE version 1.8.19. With new ones I had problems wit connecting my arduino
# Libraries and components
## Libraries
NewPing for ultrasonic distance sensor - https://github.com/livetronic/Arduino-NewPing <br />
LiquidCrystal_I2C for LCD - https://github.com/johnrickman/LiquidCrystal_I2C
## Components
<img width="906" alt="clipboard_image_52e62548d4533e50" src="https://github.com/1mpalo/Parktronic-system/assets/148369119/d5ae4b3d-b8de-42ca-a154-41ecb367fadf">;
# Realization
We have some LED`s and ultrasonic distance sensor to signalize you about how far you are from a wall. When you get closer to it (it can be any surface) different LEDs start glowing. If the distance is okay, gree one glows, if you get closer yellow one and etc. Also a piezo statring making a sound the way you get closer. The frequency depends on the distance. The closer you get, the higher the frequency. We have an LCD which displays the distance and some phrases. If the distance is more then the max (200 sm), or if it is some problem with wiresthe, LCD displays that the distatnce is too long or a problem with wires.
# The wiring diagram and the scheme
<img width="1266" alt="clipboard_image_412fdf6f322553f4" src="https://github.com/1mpalo/Parktronic-system/assets/148369119/c6b5dec9-8366-45f6-8263-c4a93cc8458e">
<img width="1141" alt="image" src="https://github.com/1mpalo/Parktronic-system/assets/148369119/a420199c-a38e-446e-bb9a-590fbd42532e">

# The real photos and recordings
### The recording - https://imgur.com/lXsKpVk
![0-02-05-088ff5d24e8fa0debc1c09f6b14fd68a2a8dbfa675d9cccd9b5daea32b7062d6_33a08039fde94478](https://github.com/1mpalo/Parktronic-system/assets/148369119/795854e0-8560-45f9-908f-ca3e7efc8570)
![0-02-05-fffd2ccf53cb13effafa6b342918c14655e77caab91db4981db69d1071a88e7e_8b96344097b9a4f0](https://github.com/1mpalo/Parktronic-system/assets/148369119/73552bba-f5c0-4de8-88f7-7337347a9f24)




