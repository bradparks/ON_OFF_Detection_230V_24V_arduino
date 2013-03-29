ON_OFF_Detection with Galvanic Isolation
... made easy

This is a project for detecting if power source is on or off.
The power source could be any circuit not connected to the Arduino. Maybe a 24V DC circuit, a 12V DC Circuit or a 230V AC Circuit.


All you need is:
- a Photoresistor (LDR). See http://en.wikipedia.org/wiki/Photoresistor
- a 10K Ohm Resistor
- and a signal light suitable for your power source (230V AC in my project). See http://www.conrad.de/ce/de/overview/0233010/Signalleuchten-Fassungen for example signal lights.
  As you can see, there are signal lights for may power sources from 5v DC to 230V AC.

Advantages:
 - The Arduino circuit is clearly divided from the circuit you want to know if it's powered on. See http://en.wikipedia.org/wiki/Galvanic_isolation
 - You can detect almost all power sources if you find a suitable signal light.
 - It's simple to build an robust.
 - The c++ code is simple.
  
How it works:
Connect the signal light parallel to the consumer. If the consumer is turned on, then the light is on too. If the consumer is off, the light is off too.
Place the LDR in front of the signal light. If this is done, use one of the analog PIN's of your Arduino to "read" the resistance of the LDR. 
Depending on your LDR, the resistance is lower if the light is on and high of the light is off.
This makes it possible to detect if a power source is turned on.

My scatch under Arduino_Code includes code to get a clear 1 (on) or 0 (off) without flapping when the resistance changes.
Please also see the pictures included in the Fritzing folder.

You can find further informations at www.edvler-blog.de