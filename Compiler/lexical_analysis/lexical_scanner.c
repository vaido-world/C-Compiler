#include <string.h>
#include "usage.c"
void main(int argc, char *argv[]) 
{ 
	if (argc != 2) 
	{
		usage(argv[0]);
	}
	
	FILE *Infile = Infile = fopen(argv[1], "r");
	if (Infile == NULL) 
	{
		fprintf(stderr, "In File: '%s' \nOn Line %i: \n Error: Unable to Open File named '%s':  %s. \n", __FILE__, __LINE__, argv[1], strerror(errno));
		// _[errno=%i]\n errno
		exit(1);
	}
}