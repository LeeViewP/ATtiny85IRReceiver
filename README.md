# ATtiny85IRReceiver

Create a Infrared Usb receiver from an IR sensor and ATtiny85<br/>
check the [instructable](http://www.instructables.com/id/DIY-USB-IR-receiver/) for more information
<br/>

### Hardware:
- A digispark(clone)
- A 38kHz IR receiver
- A remote which uses the NEC protocol.

Solder the OUT leg of the IR receiver into digispark P2 (bend and add a little piece of heat shrink (or tape) to the horizontal part of the IR receiver. )<br/>
Solder the other legs into 5V and GND.

### How to use
Upload IrReceiverRead.ino to your digispark and read and save the remote keycodes.<br/>
Add your readed keycodes to defined remote control keys to IRReceiverforWDTVLive.ino.<br/>
Upload IRReceiverforWDTVLive.ino to your digispark and connect it to the computer and you are done 

### Note 
The values defined in IRReceiverforWDTVLive.ino is for Western Digital WD TV Live Remote.<br/>
Let the digispark sit for 30 seconds before using the remote. It has to do with the digispark bootloader.<br/>
