
## Necessary material

 - arduino nano/uno : https://store.arduino.cc/arduino-nano
 - TM1638 : [here](https://www.amazon.fr/TM1638-Module-Touche-Tube-Num%C3%A9rique/dp/B00GNSO62Q)
 - arduino jumper : [here](https://www.amazon.fr/Elegoo-Breadboard-Femelle-Longueur-Arduino/dp/B01JD5WCG2/ref=pd_lpo_107_t_0/260-0494686-6803824?_encoding=UTF8&pd_rd_i=B01JD5WCG2&pd_rd_r=2730d741-c3ce-4ba0-90e2-4bf4085e4c8f&pd_rd_w=n3bdb&pd_rd_wg=EwQ59&pf_rd_p=368989f4-f820-4983-a3af-0354cd7992b0&pf_rd_r=RAP4T8MGWCBAR3ZX3PHP&psc=1&refRID=RAP4T8MGWCBAR3ZX3PHP)
## How does it work 

This timer is working without RTC, that means it's not a real clock. The timer works with the "delay()" function of arduino. So each time the loop is executed the timer fall behind, because the program needs to run some code before the 1 sec delay.

## How to use

 

 - Set start time 
	 1. Power up arduino
	 2. Use button 8 to increase time / button 7 to decrease time
	 3. Press button 1 to launch the timer

 - Increase/ decrease time when timer is running
	 1. Press button 6 
	 2. Use button 8/7 to increase/decrease time
	 3. Press button 1  to launch the timer with new remaining time

 - Stop timer
	 1. Press button 2
	 2. Now "Stop" is displayed 
	 3. After 50 seconds you can setup a new timer

