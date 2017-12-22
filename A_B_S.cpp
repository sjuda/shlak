//Alice-Bob Simulator
#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <vector>
#include <cmath>

/**/ char buff2[];
/**/ using namespace std;
char* handshake(char *sert, char *message)
{
	srand(time(0));
	int sz = 1;
	for (int i = 0; sert[i] != 0; i++) sz++;
	char key[sz];
	char buff[sz];
	for (int i = 0; i < sz; i++) key[i] = rand();
	// ключ сгенерирован;
	*buff = *sert ^ *key;
	int f = 2;
	int r = *buff & f;
	r = r << sz - 2;
	*buff = *buff >> 2;
	*buff |= r;
	//sendmsg(*buff);	- отправка в качестве сообщения buff.
	//char buff2[] = getmsg();	- ожидание аналогичного сообщения от пользователя.
	*buff2 = *buff2 ^ *key;
	int h = *buff2 & f;
	h = h >> 2;
	*buff2 = *buff2 >> 2;
	*buff2 |= h;
	return buff2;
}
char* encrypt(char *message, char *key)
{
	int k = 0;
	for (int i = 0; key[i] != 0; i++) k++;
	k++;
	int keey[k];
	int j = 0;
	for (; key[j] != 0; j++)
	{
		keey[j] = *(int *)key;
	}
	//
	int sz = 0;
	for (int i = 0; message[i] != 0; i++) sz++;
	sz++;
	int dec[sz];
	int i = 0;
	for (; message[i] != 0; i++)
	{
		dec[i] = *(int *)message;
	}
	if (dec[i] != 0) dec[i] = 0;
	int buffer[i];
	for (int i = 0; i < dec.size(); i++) buffer[i] = pow(keey[i],dec[i]);
	return (char *)buffer;
}
char* decrypt(char *message, char *key)
{
	int k = 0;
	for (int i = 0; key[i] != 0; i++) k++;
	k++;
	int keey[k];
	int j = 0;
	for (; key[j] != 0; j++)
	{
		keey[j] = *(int *)key;
	}
	//
	int sz = 0;
	for (int i = 0; message[i] != 0; i++) sz++;
	int buffer[sz] = *(int *)message;
	int res[sz];
	for (int i = 0; i < buffer.size(); i++) res[i] = log(key[i]) / log(buffer[i]);
	return (char *)res;
}

int main()
{
	return 0;
}
