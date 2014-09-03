These sketches and library were written as part of a lesson to demonstrate how information can be encoded into a binary format and transmitted through different media.

##Requirements
2 Arduino Unos
2 Computers running the Arduino IDE
2 Serial cables
2 Insulated copper wires with the ends stripped

##Setup
Connect an Arduino to a computer using a serial cable.
Import the Transmit library for use by the Arduino IDE.
Flash the sender.ini sketch to the Arduino

Connect the other Arduino to the other computer using the other serial cable.
Import the Transmit library for use by the Arduino IDE.
Flash the receiver.ini sketch to the Arduino

Connect a ground pin from one Arduino to a ground pin on the other and connect pin 13 of the Arduino flashed with sender.ini to pin 12 of the Arduino flashed with receiver.ini using the jumper wires.

##Demonstration
Open the serial monitor on both computers in the Arduino IDE.

In the serial monitor of the sender Arduino, type and send a message. You should then see a preamble followed by your message in ASCII-encoded binary followed by an end of transmission byte (EOT) followed by zeros (until another message is sent).

In the serial monitor of the receiver, once the receiver hears the preamble byte, it should print each incoming bit until it hears the EOT at which point it will print out the decoded message and stop printing (until it hears another preamble byte).

##Prerequisites
This demonstration is intended to follow an introduction to binary numbers similar to that of [CS Unplugged](http://csunplugged.org/binary-numbers) as well as an activity in which students use their newly acquired understanding of binary to encode short messages (less than 8 characters) in ASCII using face up or face down playing cards. Those messages can then be transmitted from one student to another by a student running between them carrying one card at a time and eventually decoded.

##Objectives
Students will be able to 
- convert numbers from decimal to binary and back.
- encode and decode characters using the ASCII standard
- measure and explain bitrate
- discuss how other information could be transmitted using binary

The purpose of this demonstration is to allow students to transfer their learning from the card passing exercise to electronic transmission without immediately jumping into the complexity of internet protocols.

As a result, this demonstration is intentionally not particularly sophisticated though suggestions for improvement (both algorithmic and didactic) are greatly appreciated either through issues or pull requests.