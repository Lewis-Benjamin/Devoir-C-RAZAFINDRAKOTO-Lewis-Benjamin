#include <stdio.h>
#include <stdlib.h>
#include "Devoir.h"

void readFile(char* option, int n, char* filename, char* txt){
	
	FILE *f = NULL;
	f=fopen(filename, "r");
	if(*option == 'n')
	{
		nOption(f, n,txt);
	}
	else if(*option == 'c')
	{
		cOption(f, n, txt);
	}
	fclose(f);
}

void nOption(FILE* f, int n,char* txt)
{
	int i, j, k, a = 0, t = 0;
	i = 0;
	while(feof(f) != 1)
	{
		fscanf(f, "%c", &txt[i]);
		if(txt[i]=='\n')
		{
			a++;
		}
		i++;
	}
	j = 0;
	while(j < i)
	{
		if(txt[j]=='\n')
		{
			t++;
		}
		if (a-t == n)
		{
			break;
		}
		j++;
	}
	k = j;
	while(k < i)
	{
		printf("%c", txt[k]);
		k++;
	}
}

void cOption(FILE* f, int n,char* txt)
{
	int i, j, k;
	i = 0;
	while(feof(f) != 1)
	{
		fscanf(f, "%c", &txt[i]);
		i++;
	}
	j = i - (n+1);
	k = j;
	while(k < i)
	{
		printf("%c", txt[k]);
		k++;
	}
}

char* allocation()
{
	char* txt = NULL;
	txt = (char*)malloc(10000*sizeof(char));
	if(txt == NULL)
	{
		printf("Erreur d'allocation");
		exit (1);
	}
	return (txt);
}
