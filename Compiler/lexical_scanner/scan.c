#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



// Tokens
enum tokens {
  T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT
};

// Token structure
struct token {
  int token;
  int intvalue;
};





// Function prototypes for all compiler files

int scan(struct token *t);

// 1. Put back an unwanted character
static void putback(int letter) {
  Putback = letter;
}

// Get the next character from the input file.
static int next(void) {
  int letter;

   // 2. Put back an unwanted character
  if (Putback) {		// Use the character put
    letter = Putback;		// back if there is one
    Putback = 0;
    return letter;
  }

  letter = fgetc(Infile);		// Read from input file
  if ('\n' == letter)
    Line++;			// Increment line count
  return letter;
}


// Skip past input that we don't need to deal with, 
// i.e. whitespace, newlines. Return the first
// character we do need to deal with.
static int skip(void) {
  int letter;

  letter = next();
  while ( ' ' == letter || 
         '\t' == letter || 
		 '\n' == letter || 
		 '\r' == letter || 
		 '\f' == letter) {
    letter = next();
  }
  return (letter);
}


// Return the position of character letter
// in string s, or -1 if letter not found
static int chrpos(char *s, int letter) {
  char *p;

  p = strchr(s, c);
  return (p ? p - s : -1);
}

// Scan and return an integer literal
// value from the input file. Store
// the value as a string in Text.
static int scanint(int letter) {
  int k, val = 0;

  // Convert each character into an int value
  while ((k = chrpos("0123456789", letter)) >= 0) {
    val = val * 10 + k;
    letter = next();
  }

  // We hit a non-integer character, put it back.
  putback(letter);
  return val;
}



int scan(struct token *scanned) {
  int letter;

  // Skip whitespace
  letter = skip();

  // Determine the token based on
  // the input character
  switch (letter) {
  case EOF:
    return (0);
  case '+':
    scanned -> token = T_PLUS;
    break;
  case '-':
    scanned -> token = T_MINUS;
    break;
  case '*':
    scanned -> token = T_STAR;
    break;
  case '/':
    scanned -> token = T_SLASH;
    break;
  default:

    // If it's a digit, scan the
    // literal integer value in
    if (isdigit(letter)) {
      scanned->intvalue = scanint(letter);
      scanned->token = T_INTLIT;
      break;
    }

    printf("Unrecognised character %c on line %d\n", letter, Line);
    exit(1);
  }

  // We found a token
  return (1);
}
