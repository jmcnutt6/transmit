
#include "Arduino.h"
#include "Transmit.h"

Transmit::Transmit(){
  pinMode(12, INPUT);
  pinMode(13, OUTPUT);
  ms = 125;
  PRE = 170;
  EOT = 4;
}

void Transmit::awaitPreamble(){
  char a = byteRead();
  bool b;
  while(a != PRE){
    b = (bool) digitalRead(12);
    a = (a << 1) + b;
    delay(ms);
  }
}

char Transmit::byteRead(){
  char a = 0;
  bool b;
  for (int i=0; i<8; i++){
    b = (bool) digitalRead(12);
    digitalWrite(13,b);
    Serial.print(b);
    delay(ms);
    a = (a << 1) + b;
  }    
  Serial.println();
  return a;
}

void Transmit::binReadMsg(){
  awaitPreamble();
  char msg[140];
  int i = 0;
  msg[i] = byteRead();
  while (msg[i] != EOT ){
    i++;
    msg[i] = byteRead();  
  }
  msg[i] = '\0';
  Serial.println(msg);
}

void Transmit::byteWrite(char a){
  bool b; 
  for (int i=0; i<8; i++){
    b = ((a >> (7-i)) & 1);
    Serial.print(b);
    digitalWrite(13,b);
    delay(ms);
  }
  Serial.println(); 
}

void Transmit::binWriteMsg(String msg, int len){
  byteWrite(PRE);
  for (int i=0; i<len; i++) byteWrite(msg[i]);
  byteWrite(EOT);
}

void Transmit::binWriteMsgSerial(){
  if (Serial.available()>0){
    byteWrite(PRE);
    while (Serial.peek()>0) byteWrite(Serial.read());
    byteWrite(EOT);
  }
  else{
    byteWrite(0);
  }
}
