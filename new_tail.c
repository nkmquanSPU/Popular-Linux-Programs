#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_FILE_NAME_CHARS 255

int main(int argc, char *argv[])
{
	FILE *fp;
	char file_name[MAX_FILE_NAME_CHARS];
	char line[MAX_FILE_NAME_CHARS];
	char buffer[MAX_FILE_NAME_CHARS];
	char user_num_lines[3];
	char ignore[1024]; //to skip lines when reading from the file
	char ch;
	char c;
	int count = 0; //to count number of lines in the file
	int i;
	int default_n = 5;
	int number_of_lines; //number of lines that user wants to print
	
	if (argc == 1) //repeat what user types until Ctrl + D is given
	{
		while(!feof(stdin))
		{
			fgets(buffer, MAX_FILE_NAME_CHARS, stdin);
			printf("%s", buffer);			
		}
		return 0;
	}
	else if(argc == 3) //get the file name when user specify value of n
		strncpy(file_name, argv[2], MAX_FILE_NAME_CHARS);
	else if(argc == 2) //get the file name when user does not specify value of n
		strncpy(file_name, argv[1], MAX_FILE_NAME_CHARS);
	else
	{
		printf("Usage ./new_tail [-n N] <file_name.txt> \n");
		return 0;
	}
    fp = fopen(file_name, "r");
	
	if(fp == NULL) //if the file does not exist
	{
		printf("%s: No such file or directory.\n", file_name);
		return 0;
	}
	
	//count the number of lines in the text file
	for (c = getc(fp); c != EOF; c = getc(fp))
		if (c == '\n')
			count = count + 1; //increment count if we hit new line character
	
	fclose(fp); //close the file 

	fp = fopen(file_name, "r"); //re-open the file	
	
	if(argc ==  3) //if user specifies the value for n
	{
		strncpy(user_num_lines, argv[1], 3); //take arg  number of lines specified by user					
		number_of_lines = atoi(user_num_lines); //convert user's input to int (example -7)
		number_of_lines = number_of_lines * (-1); //convert negative to positive number (example 7)				
					
		for (i = 0; i < count - number_of_lines; i++)
			fgets(ignore, sizeof(ignore), fp);
				
	}
	else if(argc == 2) //if user does not specifies the value for n
	{
		for (i = 0; i < count - default_n; i++)
			fgets(ignore, sizeof(ignore), fp);
	}
	
	while((fgets(line, sizeof(line), fp) != NULL)) //while it is not the end of file
	{						
		printf("%s", line);				
	}
							
	fclose(fp);

	fflush(stdout);	
	return 0;
}
