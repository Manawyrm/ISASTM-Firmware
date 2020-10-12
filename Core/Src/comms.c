#include "comms.h"
#include "isa.h"



void receivePacket(uint8_t* Buf, uint32_t *Len)
{
	//printf("received %lu bytes\r\n", *Len);
	if (*Len >= 3)
	{
		switch(Buf[0]) {
			case 'i': 
				printf("%c", isa_ior((Buf[1] << 8) | Buf[2]));
				break;
			default: 
				printf("e");
				break;
		}


	}
}

/*
		command = Serial.read();
		if (command == 'i')
		{
			while (Serial.available() < 2) {}
			address = (Serial.read() << 8);
			address |= Serial.read();
			Serial.write(ioRead(address));
		}

		if (command == 'o')
		{
			while (Serial.available() < 3)	{}
			address = (Serial.read() << 8);
			address |= Serial.read();
			data = Serial.read();

			ioWrite(address, data);
			Serial.write('o');
		}

		if (command == 'r')
		{
			while (Serial.available() < 3)	{}
			address = ((uint32_t) Serial.read() << 16UL);
			address |= (Serial.read() << 8);
			address |= Serial.read();
			Serial.write(memRead(address));
		}

		if (command == 'w')
		{
			while (Serial.available() < 4)	{}
			address = ((uint32_t)Serial.read() << 16UL);
			address |= (Serial.read() << 8);
			address |= Serial.read();
			data = Serial.read();

			memWrite(address, data);
			Serial.write('w');
		}*/