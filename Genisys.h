#ifndef GENISYS_H
#define GENISYS_H

#include <Arduino.h>

class Genisys {

  public:
	  	Genisys();
	  	~Genisys();
		void begin (byte *localip, byte *remoteip, char *hostname);
		void poll ();
		void receiveOpCodes (void (*)(byte*));
		void sendOpCode (byte*);
		
  private:
		byte _ip[4];
		char *_opcodemsg;
		int _opcodelen;
		char *_pollmsg;
		int _polllen;
		EthernetUDP _udp;
		byte checksum (byte*);
		void setchecksum (byte*);
		bool checkchecksum (byte*);

};

#endif
