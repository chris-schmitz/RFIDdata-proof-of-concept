#  RFIDdata proof of concept

I have a microcontroller project that I'm working on where I'll be capturing various RFID tag ids and payloads. I know I'm going to need a way to access the payloads, compare the ids, etc. 

Rather than grind through the dev loop on the microcontroller I decided to make a proof of concept in regular C++ that I can then (hopefully) port over to the microcontroller's code base. That way I'll be able to take advantage of xcode's debugging tools while I think through and build out the class. 

