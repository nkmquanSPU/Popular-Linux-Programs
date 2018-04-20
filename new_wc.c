#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX_FILE_NAME_CHARS 255

int main(int argc, char *argv[])
{
	FILE *fp;
	char file_name[MAX_FILE_NAME_CHARS];
	char buffer[MAX_FILE_NAME_CHARS];
	char flag[3];
	char l_flag[3] = "-l";
	char c_flag[3] = "-c";
	char l;
	char c;
	char ch;
	int line_count = 0;
	int char_count = 0;
	int word_count = 0;
	
	if (argc == 1) //repeat what user types until Ctrl + D is given
	{
		while(!feof(stdin))
		{
			fgets(buffer, MAX_FILE_NAME_CHARS, stdin);
			printf("%s", buffer);		
		}
		return 0;
	}
	if(argc != 3)
	{
		printf("Usage ./new_wc [-l|c] [file.txt] \n");
		return 0;
	}
	
	//get the file name from user
	strncpy(file_name, argv[2], MAX_FILE_NAME_CHARS);

	fp = fopen(file_name, "r");
	
	if(fp == NULL) //if the file does not exist
	{
		printf("%s: No such file or directory.\n", file_name);
		return 0;
	}
	
	//for the -l flag
	strncpy(flag, argv[1], 3); //take flag specified by user	
	
	
	//count words
	while((ch=getc(fp)) != EOF)
		if(ch == ' ' || ch == '\n')
			word_count++;

	fclose(fp);

	fp = fopen(file_name, "r");
	if(strcmp(flag, l_flag) == 0) //if -l flag is given
	{    	
		
		//count the number of lines in the text file
		for (l = getc(fp); l != EOF; l = getc(fp))
			if (l == '\n')
				line_count = line_count + 1; //increment count if we hit new line character
		printf("%d %d \n", line_count, word_count);
	} 
	else if (strcmp(flag, c_flag) == 0) //if -c flag is given
	{
	
		while((c = fgetc(fp)) != EOF) //while it is not the end of file		
			char_count++;
		printf("%d %d \n", char_count, word_count);
	}
	
	fclose(fp); //close the file
	return 0;
}
