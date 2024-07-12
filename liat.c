#include <stdio.h>
#include <stdlib.h>
#include "Devoir.h"


int main(int argc, char* argv[])
{
	char* option = argv[1];
	int n = atoi(argv[2]);
	char* filename = argv[3];
	char* txt = NULL;
	txt = allocation();
	readFile(option, n, filename, txt);
	free(txt);
	return 0;
}
