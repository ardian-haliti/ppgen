#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void printword(void)
{
	FILE *wordlist;
	char word[10];
	int wordindex;
	unsigned char wordlen;
	//wordlen = ((unsigned int)(randint() % 2) + 5 );
	wordlen = ((((unsigned char)getrandchar()) % 4) + 3);
	/**/
	//unsigned char wordlen;
	//int wordlen = (unsigned int)((randint() % 10) + 2);
	switch (wordlen) {
		case 3:
			wordlist = fopen("./wordlists/3.txt","r");
			wordindex = (((unsigned int)randint() % 607) * 4);
			break;
		case 4:
			wordlist = fopen("./wordlists/4.txt","r");
			wordindex = (((unsigned int)randint() % 2023) * 5);
			break;
		case 5:
			wordlist = fopen("./wordlists/5.txt","r");
			wordindex = (((unsigned int)randint() % 3198) * 6);
			break;
		case 6:
			wordlist = fopen("./wordlists/6.txt","r");
			wordindex = (((unsigned int)randint() % 4663) * 7);
			break;
		default:
			abort();
	}
	
	fseek(wordlist, (long int) wordindex, SEEK_SET);
	fgets(word,(int)wordlen + 1,wordlist);
	printf("%s", word);
	fclose(wordlist);
}

unsigned short randint(void)
{
	int i;
	unsigned short result;
	i = 2;
	while(i > 0) {
		result = result << 8;
		result += (unsigned short)getrandchar();
		i--;
	}
	/*
	for(int i = 4; i > 0; i--) {
		c = getc(urandsrc);
		c = intpow(c, i);
		result += c;
	}
	*/
	return result;
}
/*
int intpow(int base, int exp)
{
	int result = 1;
	while(exp) {
		if(exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}
	return result;
}
*/
char getrandchar(void)
{
	FILE *src;
	src = fopen("/dev/urandom","r");
	char result = (char)getc(src);
	//fgets(result,1,src);
	fclose(src);
	return result;
}
