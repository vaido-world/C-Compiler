//gcc main.c scan.c
// the job of the scanner is to identify the lexical elements, or tokens, in the input language.
#include "headers.h"

int     Line;
int	    Putback;
FILE	*Infile;

static void init() {
  Line = 1;
  Putback = '\n';
}

#include "scan.c"
#include "usage.c"


// List of printable tokens
char *tokstr[] = { "+", "-", "*", "/", "intlit" };


// Loop scanning in all the tokens in the input file.
// Print out details of each token found.
static void scanfile() {
  struct token T;

  while (scan(&T)) {
    printf("Token %s", tokstr[T.token]);
    if (T.token == T_INTLIT)
      printf(", value %d", T.intvalue);
    printf("\n");
  }
}


void main(int argc, char *argv[]) { 
	  if (argc != 2)
		usage(argv[0]);
	
  init();
	
  if ((Infile = fopen(argv[1], "r")) == NULL) {
    fprintf(stderr, "Unable to open %s: %s\n", argv[1], strerror(errno));
    exit(1);
  }

  scanfile();
  exit(0);
}