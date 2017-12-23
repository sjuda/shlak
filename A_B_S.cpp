//Alice-Bob Simulator
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <cmath>

class kg
{
public:
	void sertufinit(char sertif[])
	{
		int sz = 0;
		for (int i = 0; sertif[i] != 0; i++) sz++;
		sz++;
		if (sz == 8) for (int i = 0; i < 8; i++)sert[i] = sertif[i];
		else exit(101);
	}
	void keyinit()
	{
		srand(time(0));
		for (int i = 0; i < 8; i++) key[i] = rand();
	}
	double sertifindouble()
	{
		char buff[8] = { sert[0],sert[1],sert[2],sert[3],sert[4],sert[5],sert[6],sert[7] };
		sert[1] = sert[1] << 8;
		sert[2] = sert[2] << 16;
		sert[3] = sert[3] << 24;
		sert[4] = sert[4] << 32;
		sert[5] = sert[5] << 40;
		sert[6] = sert[6] << 48;
		sert[7] = sert[7] << 56;
		double val = sert[0] | sert[1] | sert[2] | sert[3] | sert[4] | sert[5] | sert[6] | sert[7];
		return val;
	}
	double keyindouble()
	{
		char buff[8] = { key[0],key[1],key[2],key[3],key[4],key[5],key[6],key[7] };
		key[1] = key[1] << 8;
		key[2] = key[2] << 16;
		key[3] = key[3] << 24;
		key[4] = key[4] << 32;
		key[5] = key[5] << 40;
		key[6] = key[6] << 48;
		key[7] = key[7] << 56;
		double val = key[0] | key[1] | key[2] | key[3] | key[4] | key[5] | key[6] | key[7];
		return val;
	}
	char* sertinchar()
	{
		char buff[8] = { sert[0],sert[1],sert[2],sert[3],sert[4],sert[5],sert[6],sert[7] };
		char *ptr = buff;
		return  ptr;
	}
	char* keyinchar()
	{
		char buff[8] = { key[0],key[1],key[2],key[3],key[4],key[5],key[6],key[7] };
		char *ptr = buff;
		return  ptr;
	}
private:
	char sert[8];
	char key[8];
};

kg hsh;

/**/ char buff2[8];
/**/ using namespace std;
char* handshake(char *sert, char *message)
{
	hsh.keyinit();
	char *buff = hsh.keyinchar();
	int f = 2;
	int r = *buff & f;
	r = r << 6;
	*buff = *buff >> 2;
	*buff |= r;
	//sendmsg(*buff);	- отправка в качестве сообщения buff.
	//char buff2[8] = getmsg();	- ожидание аналогичного сообщения от пользователя.
	*buff2 = *buff2 ^ *buff;
	int h = *buff2 & f;
	h = h >> 2;
	*buff2 = *buff2 >> 2;
	*buff2 |= h;
	return buff2;
}
char* encrypt(char message[])
{
	double *buff = NULL;
	double dkey = hsh.keyindouble();
	int sz = 0;
	int i = 0;
	for ( ;message[i] != 0; i++)
	{
		buff[i] = pow(dkey, message[i]);
	}
	buff[i + 1] = 0;
	return (char *)buff;
}
char* decrypt(char message[])
{
	double dkey = hsh.keyindouble;
	double *buffer = NULL;
	int i = 0;
	for ( ; message[i] != 0; i++) buffer[i] = log(dkey) / log(message[i]);
	buffer[i + 1] = 0;
	return (char *)buffer;
}

int main()
{
	return 0;
}
