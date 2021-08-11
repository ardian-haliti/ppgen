#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include "functions.h"

int main(int argc, char **argv)
{
	//int cflag = 0;
	char *cvalue = NULL;
	//char *svalue = NULL;
	//char *lvalue = NULL;
	int c;
	int wordcount = 4;
	//int wordlen = (((unsigned int)getrandchar() % 4) + 3);
	char sep = '-';
	//printf("Wordlen is: %d\n",wordlen);
	while ((c = getopt (argc, argv, "c:")) != -1) {
		switch (c) {
			case 'c':
				cvalue = optarg;
				break;
			/*case 'l':
				lvalue = optarg;
				//wordlen = lvalue;
				break;*/
			default:
				abort();
		}
	}

	if(cvalue != NULL) {
		int assigned = sscanf(cvalue, "%d", &wordcount);
	}
	//printf("cflag is: %d. lvalue is %s\n", cflag, lvalue);

	for(int i = wordcount; i > 0; i--) {
		//printf("%u", randint());
		printword();
		if(i > 1)
			printf("%c", sep);
	}

	printf("\n");
	//unsigned int testnum = randint();
	//printf("Char: %d\n", getrandchar());
	/*
	printf("Random bit: %u\n", testnum);
	printf("Bool is %d\n", (int)mybool2);
	*/
	//printf("%d\n", randint());
	//

	return 0;
}
