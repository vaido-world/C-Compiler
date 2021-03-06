// tcc -b -Wall -run main.c input01
// the job of the scanner is to identify the lexical elements, or tokens, in the input language.
#include "headers.h"

int     Line = 1;
int	    Putback = '\n';

static void init() {
  puts("Initialising main.c");
}


	FILE	*Infile;
#include "scan.c"
#include "usage.c"





// Loop scanning in all the tokens in the input file.
// Print out details of each token found.




void main(int argc, char *argv[]) { 
	  if (argc != 2)
		usage(argv[0]);
	
  init();
  

  if ((Infile = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
    exit(1);
  }



  struct token T;



  // List of printable tokens
  const char *tokstr[] = { "+", "-", "*", "/", "intlit" };

  while (scan(&T)) {
    printf("Token: %s", tokstr[T.token]);
    if (T.token == T_INTLIT)
      printf(", value %d", T.intvalue);
    printf("\n");
  }
  
  puts("hello");
 
  exit(0);
}