#include "comms.h"
#include "isa.h"

#include "../../USB_DEVICE/App/usbd_cdc_if.h"
void send_char(uint8_t chara)
{
	CDC_Transmit_FS((uint8_t *) &chara, 1);
}

void receivePacket(uint8_t* Buf, uint32_t *Len)
{
	//printf("received %lu bytes\r\n", *Len);
	
		switch(Buf[0]) {
			case 'i': 
				if (*Len >= 3)
				{
					send_char(isa_ior((Buf[1] << 8) | Buf[2]));
				}
				break;
			case 'o': 
				if (*Len >= 4)
				{
					isa_iow((Buf[1] << 8) | Buf[2], Buf[3]);
					send_char('o');
				}
				break;	
			case 'r': 
				if (*Len >= 4)
				{
					send_char(isa_memr((Buf[1] << 16) |(Buf[2] << 8) | Buf[3]));
				}
				break;
			case 'w': 
				if (*Len >= 5)
				{
					isa_memw((Buf[1] << 16) |(Buf[2] << 8) | Buf[3], Buf[4]);
					send_char('w');
				}
				break;	
			default: 
				send_char('e');
				break;
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