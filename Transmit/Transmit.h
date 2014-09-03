#ifndef Transmit_h
#define Transmit_h

#include "Arduino.h"

class Transmit
{
  public:
    Transmit();
    void binReadMsg();
    void binWriteMsgSerial();
    void binWriteMsg(String msg, int len);

  private:
    void awaitPreamble();
    char byteRead();
    void byteWrite(char msg);
    int ms;
	char PRE;
	char EOT;
};

#endif