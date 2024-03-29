#include<stdio.h>
#include<string.h>
#define MAX_FILE_NAME_CHARS 255

int main(int argc, char *argv[])
{
	FILE *fp;
	char file_name[MAX_FILE_NAME_CHARS];
	char buffer[MAX_FILE_NAME_CHARS];
	char ch; 
	int i;
	
	if (argc == 1) //repeat what user types until Ctrl + D is given
	{
		while(!feof(stdin))
		{
			fgets(buffer, MAX_FILE_NAME_CHARS, stdin);
			printf("%s", buffer);			
		}
		return 0;
	}
	else if (argc == 2)
	{	for(i = 1; i < argc; i++)
		{
			strncpy(file_name, argv[i], MAX_FILE_NAME_CHARS);
			fp = fopen(file_name, "r"); //open and read from the file

			if(fp == NULL) //if the file does not exist
			{
					printf("%s: No such file or directory.\n", file_name);
				return 0;
			}

				while((ch = fgetc(fp)) != EOF) //while it is not the end of file
			{
				putchar(ch);
			}

			fclose(fp);

			fflush(stdout);
		}
	}	
	else
	{
		printf("Usage ./new_cat [file_name.txt] \n");
	}
	 return 0;
}
