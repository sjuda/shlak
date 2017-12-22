#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
#include <cstring>

//
//
unsigned char *key;
//
unsigned char str[4];
//
struct gamma { unsigned char state[4]; };
//
//
gamma new_gamma(unsigned char key[4])
{
	srand(*key);
	gamma gw;
	for (int i = 0; i < 4; i++)
	{
		gw.state[i] = rand();
	}
	return gw;
}
unsigned char encryption(unsigned char str[4], gamma g)
{
	unsigned char cipher[4];
	//if (sizeof(*str) != 4) exit(228);
	*cipher = *str ^ *g.state;
	int f = 1;
	int r = *cipher & f;
	r = r << 7;
	*cipher = *cipher << 1;
	*cipher |= r;
	return *cipher;
}
unsigned char decryption(unsigned char str[4], gamma g)
{
	//if (sizeof(*str) != 4) exit(228);
	int f = 1;
	int r = *str & f;
	r = r << 7;
	*str = *str << 1;
	*str |= r;
	*str = *str ^ *g.state;
	return *str;
}
