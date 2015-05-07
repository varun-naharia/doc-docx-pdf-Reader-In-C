#include<stdio.h>
#include<String.h>
#include<stdlib.h>
//#include<conio.h>

int main()
{
	char *ch="s";
	char df;
	//char text;
	long unsigned int offset,i;
	offset = 2561;

	FILE *fileptr;
	char *buffer,*text;
	long filelen;
	int count;
	count=0;
	fileptr = fopen("file.doc", "rb");  // Open the file in binary mode
	fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
	filelen = ftell(fileptr);             // Get the current byte offset in the file
	rewind(fileptr);                      // Jump back to the beginning of the file
	filelen =filelen-2560;
	buffer = (char *)malloc((filelen+1)*sizeof(char)); // Enough memory for file + \0
	fseek(fileptr, 2561, SEEK_CUR);
	fread(buffer, filelen, 1, fileptr); // Read in the entire file
	fclose(fileptr); // Close the file
	for ( i = 0; i < strlen(buffer); ++i)
	{
		if(buffer[i]>127)
		{
			break;
		}
		else
		{
			count++;
		}
	}
	text = (char *)malloc((count+1)*sizeof(char)); // Enough memory for file + \0
	for ( i = 0; i < count; ++i)
	{
		text[i]=buffer[i];
		/*****************************************************************************
	    *	This Printf printing text content of the doc in one charchter per line   *
		*****************************************************************************/
		printf("%c\n",text[i] );
	}
	//printf("%d\n",count);

	/*******************************************************************************************
	*	This Printf printing some text content of the doc not whole text content in one line   *
	********************************************************************************************/
	printf("%d\n",strlen(text));
	printf("%s",text );
	
	return 0;
}
