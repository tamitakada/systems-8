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
    while (source[i]) {
        dest[i] = source[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

char * mystrcat( char *dest, char *source ) {
    int end = mystrlen(dest);
    int i = 0;
    while (source[i]) {
        dest[end + i] = source[i];
        i++;
    }
    dest[end + i] = '\0';
    return dest;
}

int mystrcmp( char *s1, char *s2 ) {
    while (*s1) {
        if ((*s1) > (*s2)) return 1;
        else if ((*s1) < (*s2)) return -1;
        else {
            s1++;
            s2++;
        }
    }
    
    if ((*s1) == (*s2)) return 0;
    return -1;
}

char * mystrchr( char *s, char c ) {
    int i = 0;
    int len = mystrlen(s);
    while (i <= len) {
        if (s[i] == c) {
            char *p = &(s[i]);
            return p;
        }
        i++;
    }
    return NULL;
}

char * mystrstr( char *s1, char * s2 ) {
  int i = 0;
  while ((*s1) && (i != mystrlen(s2) - 1)) {
    if ((*s1) == s2[i]) i++;
    else i = 0;
    s1++;
  }

  if (i == (mystrlen(s2) - 1)) {
    s1--;
    return s1;
  }
  return NULL;
}
