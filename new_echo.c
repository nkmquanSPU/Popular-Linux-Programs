#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{	
	
	int i;
	if (argc < 2) //if user does not pass in any [agr]
	{
		printf("Usage ./new_echo [arg] [arg] ... [arg] \n");
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
