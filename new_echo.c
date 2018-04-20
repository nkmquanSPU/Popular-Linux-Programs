#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_FILE_NAME_CHARS 255

int main(int argc, char *argv[])
{	
	int i;
	
	if (argc == 1) //repeat what user types until Ctrl + D is given
	{
		printf("\n");
		return 0;
	}
	else
	{
		for (i = 1; i < argc; i++)
		{
			printf("%s", argv[i]); //print [agr] from user
			printf(" ");			
		}
	
		printf("\n");	
	}	
	return 0;
}
