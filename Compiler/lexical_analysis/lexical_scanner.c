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
		get_current_path();
		fprintf(stderr, "In File: '%s'  \nOn Line %i:  \nError: Unable to Open File named '%s': %s.\n", __FILE__, __LINE__, argv[1], strerror(errno));
		// _[errno=%i]\n errno
		exit(1);
	}
}