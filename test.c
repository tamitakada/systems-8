#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "str_funcs.h"

void random_populate_arr_n(char *arr, int n);
void random_populate_arr(char *arr, int len);
void print_str(char *arr);

void test_len() {
    srand(time(NULL));
    
    printf("-- Testing mystrlen --\n");
    int i;
    for (i = 0; i < 100; i++) {
        int len = (rand() % 300) + 1;
        char arr[len];
        random_populate_arr(arr, len);
        
        int official = strlen(arr);
        int self = mystrlen(arr);
        
        if (official != self) {
            printf(
                "Random Test #%d out of 100 failed: \nOfficial len: %d\nMy len: %d\nArray: [%s]\n",
                i, official, self, arr
            );
            break;
        } else if (i == 99) {
            printf("Random Tests Passed (100/100)\n");
        }
    }
}

void test_copy() {
    srand(time(NULL));
    
    printf("-- Testing mystrncpy --\n");
    int i;
    for (i = 0; i < 100; i++) {
        int len = (rand() % 300) + 1;
        char arr[len];
        random_populate_arr(arr, len);
        
        int dest_len = len + ((rand() % 100) + 1);
        char official_dest[dest_len];
        char dest[dest_len];
        
        int num = (rand() % (dest_len - len)) + 1;
        
        char *official = strncpy(official_dest, arr, num);
        char *self = mystrncpy(dest, arr, num);
        
        if (strcmp(official, self)) {
            printf(
                "Random Test #%d out of 100 failed: \nOfficial copy: [%s]\nMy copy: [%s]\nArray: [%s]\nUp to: %d\n",
                i, official, self, arr, num
            );
            break;
        } else if (i == 99) {
            printf("Random Tests Passed (100/100)\n");
        }
    }
}

void test_strcat() {
    srand(time(NULL));
    
    printf("-- Testing mystrcat --\n");
    int i;
    for (i = 0; i < 100; i++) {
        int len = (rand() % 300) + 1;
        char arr[len];
        random_populate_arr(arr, len);
        
        int excess_space = ((rand() % 100) + 1);
        int dest_len = len + excess_space;
        
        char official_dest[dest_len];
        random_populate_arr_n(official_dest, excess_space);
        
        char dest[dest_len];
        strcpy(dest, official_dest);
        
        char *official = strcat(official_dest, arr);
        char *self = mystrcat(dest, arr);

        if (strcmp(official, self)) {
            printf(
                "Random Test #%d out of 100 failed: \nOfficial arr: [%s]\nMy arr: [%s]\nTo add array: [%s]\n",
                i, official, self, arr
            );
            break;
        } else if (i == 99) {
            printf("Random Tests Passed (100/100)\n");
        }
    }
}

void test_strcmp() {
    srand(time(NULL));
    
    printf("-- Testing mystrcmp --\n");
    int i;
    for (i = 0; i < 100; i++) {
        int len = (rand() % 300) + 1;
        char arr[len];
        random_populate_arr(arr, len);
        
        char comp[len];
        
        int same_or_diff = (rand() % 3) + 1;
        if (same_or_diff == 1) {
            strcpy(comp, arr);
        } else {
            random_populate_arr(comp, len);
        }
        
        int official = strcmp(comp, arr);
        int self = mystrcmp(comp, arr);

        if (official != self) {
            printf(
                "Random Test #%d out of 100 failed: \nOfficial: %d\nSelf: %d\nArr 1: [%s]\nArr 2: [%s]",
                i, official, self, arr, comp
            );
            break;
        } else if (i == 99) {
            printf("Random Tests Passed (100/100)\n");
        }
    }
}

void test_chr() {
    srand(time(NULL));
    
    printf("-- Testing mystrchr --\n");
    int i;
    for (i = 0; i < 100; i++) {
        int len = (rand() % 300) + 1;
        char arr[len];
        random_populate_arr(arr, len);
        
        char to_add = rand();
        
        char *official = strchr(arr, to_add);
        char *self = mystrchr(arr, to_add);

        if (official != self) {
            printf(
                "Random Test #%d out of 100 failed: \nOfficial: %p\nSelf: %p\nArr: [%s]\nChar: %c",
                i, official, self, arr, to_add
            );
            break;
        } else if (i == 99) {
            printf("Random Tests Passed (100/100)\n");
        }
    }
}

void random_populate_arr(char *arr, int len) {
    random_populate_arr_n(arr, len - 1);
}

void random_populate_arr_n(char *arr, int n) {
    srand(time(NULL));

    int i;
    for (i = 0; i < n; i++) {
        arr[i] = rand();
    }
    
    arr[n] = '\0';
}
