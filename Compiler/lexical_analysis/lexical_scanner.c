#define main main
#include <string.h>
#include "usage.c"
#include "get_current_path.c"

void main(int argc, char *argv[]) 
{ 
	if (argc != 2) 
	{
		usage(argv[0]);
	}
	
	FILE *Infile = Infile = fopen(argv[1], "r");
	if (Infile == NULL) 
	{
		printf("In File: '%s'  \n|On Line %i: ", __FILE__, __LINE__);

		fprintf(stderr, "Error: Unable to Open File named '%s': %s. (errno: %i) \n", argv[1], strerror(errno), errno);
		
		
		
		// tcc -run lexical_scanner.c c:/test
		// tcc -run lexical_scanner.c c:/
		// tcc -run lexical_scanner.c c:asd
		// Absolute Path Error Note
		// Simply print the input path
		// Print which path subfolder is inaccesible

		#include <ctype.h>
		if (isalpha(argv[1][0]) && argv[1][1] == ':' && argv[1][2] == '/') { 
		if (argv[1][3] == '\0'){
			printf("Does not contain filename.\n");
			printf("Drive folder is passed instead of a path to a folder.\n ");
			
		}
			printf("|For: fopen('");
			printf("%s", argv[1]);
			printf("', 'r');\n");
			printf("asd");
		
		// tcc -run lexical_scanner.c asd
		// Relative Path Error Note
		// If there is no / at the beginning of the input:
		// If there is no :\ as part of input
		// If starts with alphabet letter
		// If there is ./ at the beginning of the input:
		} else {
			//printf("Opening file ('");
			printf("|For: fopen('");
			get_current_path();
			printf("\\%s", argv[1]);
			printf("', 'r');\n");
			printf("123");
		}

		


		// _[errno=%i]\n errno
		
		exit(1);
	}
	else {
		printf("Opened file: ", argv[1]);
		printf("'");
		get_current_path();
		printf("\\%s' ", argv[1]);
		printf("without errors. ");
		puts("");
		
	}
}