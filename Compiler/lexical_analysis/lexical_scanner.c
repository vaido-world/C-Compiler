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

		fprintf(stderr, "Error: Unable to Open File named '%s': %s. (errno: 2) \n", argv[1], strerror(errno));
		
		
		
		// tcc -run lexical_scanner.c c:asd
		#include <ctype.h>
		// Relative Path Error Note
		// If there is no / at the beginning of the input:
		// If there is no :\ as part of input
		// If starts with alphabet letter
		// If there is ./ at the beginning of the input:
		if (isalnum(argv[1][0]) && argv[1][1] == ':') { 
			printf("|For: fopen('");
			printf("%s", argv[1]);
			printf("', 'r');\n");
		
		// tcc -run lexical_scanner.c asd
		} else {
			//printf("Opening file ('");
			printf("|For: fopen('");
			get_current_path();
			printf("\\%s", argv[1]);
			printf("', 'r');\n");
		
		}

		

		
		// Absolute Path Error Note
		// Simply print the input path
		// Print which path subfolder is inaccesible

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