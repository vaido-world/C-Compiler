#ifndef extern_
 #define extern_ extern
#endif

struct token {
  int token;
  int intvalue;
};

enum {
  T_PLUS, T_MINUS, T_STAR, T_SLASH, T_INTLIT
};

extern_ int     Line;
extern_ int     Putback;
extern_ FILE    *Infile;