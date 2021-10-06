#include <stdio.h>

int mystrlen( char *s ) {
  int count = 0;
  while (*s) {
    s++;
    count++;
  }
  return count;
}

char * mystrcpy( char *dest, char *source ) {
  int i = 0;
  while (*source) {
    dest[i] = source[i];
    i++;
    source++;
  }
  dest[i] = '\0';
  return dest;
}

/*
char * mystrcat( char *dest, char *source );
int mystrcmp( char *s1, char *s2 );
char * mystrchr( char *s, char c );
*/
