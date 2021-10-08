#include <stdio.h>
#include <string.h>

int mystrlen( char *s ) {
  int count = 0;
  while (*s) {
    s++;
    count++;
  }
  return count;
}

char * mystrncpy( char *dest, char *source, int n ) {
    int i = 0;
    int fill_with_nulls = 0;
    while (i < n) {
        if (!source[i]) fill_with_nulls = 1;
        if (fill_with_nulls) dest[i] = '\0';
        else dest[i] = source[i];
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
