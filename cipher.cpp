#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "stdafx.h"
//
//
unsigned char *key;
//
unsigned char str;
//
struct gamma { unsigned char *state; };
//
gamma g = new_gamma(key);
//
gamma new_gamma(unsigned char *key)
{
	gamma g;
	srand(*key);
	g.state = (unsigned char *)rand();
	return g;
}
unsigned char encryption(unsigned char str, gamma g)
{
	unsigned char *cipher;
	if (sizeof(cipher) == sizeof(int)) std::cout << "Cipher size is 4 bytes!";
	*cipher = str ^ *g.state;
	*cipher >> 1;
	return *cipher;
}
unsigned char decryption(unsigned char str, gamma g)
{
	unsigned char *cipher;
	if (sizeof(cipher) == sizeof(int)) std::cout << "Cipher size is 4 bytes!";
	str << 1;
	*cipher = str ^ *g.state;
	return *cipher;
}
int main()
{
	std::cin >> key;
	gamma gi = new_gamma(key);
	unsigned char *str = (unsigned char *)"aqw";
	unsigned char res = encryption(*str, gi);
	if ((sizeof(key) == sizeof(int))&&(sizeof(g.state) == sizeof(int))&&(sizeof(*str) == sizeof(int))) std::cout << "All buffers size is 4 bytes!";
	else exit(228);
	std::cout << "Result is " << res;
}
