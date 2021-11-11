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
		printf("In File: '%s'  \nOn Line %i:  \n", __FILE__, __LINE__);
		printf("Info: Target: '");
		get_current_path();
		printf("\\%s", argv[1]);
		printf("'\n");
		
		fprintf(stderr, "Error: Unable to Open File named '%s': %s. (errno: 2) \n", argv[1], strerror(errno));
		

		// _[errno=%i]\n errno
		exit(1);
	}
}