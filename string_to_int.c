#include <stdio.h>
#include <string.h> /* from string import strlen */
#include <math.h>   /* from math import pow */
#include <stdlib.h> /* from stdlib import calloc, malloc */

int stoi(char *num);
char** split(char *str, char *delim, int *elem);
char *strmk(char *str_p, char *str, int len);

/*
 *    String to Int function
 */
int stoi(char *num) {
    // Get string length
    int len = strlen(num);

    // Get sign of number
    int sign = 0;
    if (num[0] == '-')
        sign = 1;

    // Get value starting from ones digit
    int count = len - 1,
        val = 0,
        mult = 1;
    while (count > sign - 1) {
        val = val + (num[count] - '0') * mult;
        count--;
        mult *= 10;
    }

    return val * pow(-1, sign);
}

/*
 *  String to array of string
 */
char** split(char *str, char *delim, int *elem) {
    // Initial pointer-to-pointer allocation
    char **ret = (char **)malloc(1 * sizeof(char *));

    // strtok
    char *token;
    token = strtok(str, delim);

    // Split proper
    int count = 0;
    while (token != NULL) {
        // Adjust memory space
        ret = (char **)realloc(ret, (count + 1) * sizeof(char *));

        // Allocate memory for string and copy it
        *(ret + count) = strmk(*(ret + count), token, strlen(token));

        // Move to next string
        token = strtok(NULL, delim);
        count++;
    }

    *elem = count;
    return ret;
}

/*
 *  String to array of int
 */
int *stoai(char *str, int *elem) {
    char **split_p;
    int split_elem;

    // Default delimiter is space " "
    split_p = split(str, " ", &split_elem);

    // Initial array of int allocation
    int *ret;
    ret = (int *)malloc(split_elem * sizeof(int));

    // Loop stoi
    int count = 0;
    while (count < split_elem) {
        ret[count] = stoi(*(split_p + count));
        count++;
    }

    *elem = split_elem;
    return ret;
}

/*
 *  String allocation
 */
char *strmk(char *str_p, char *str, int len) {
    str_p = (char *)calloc(len + 1, sizeof(char));
    strcpy(str_p, str);
    return(str_p);
}

int main (void) {
    // stoi
    char try[5] = "-10";
    int hello;
    hello = stoi(try);
    printf("%d\n", hello);

    // strmk
    char *yeyeye;
    char hellos[4] = "new";
    strmk(yeyeye, hellos, strlen(hellos));

    // split
    int elem = 0;
    char yeye[200] = "he a o wyw w q";
    char delim[2] = " ";
    char **fofo;
    fofo = split(yeye, delim, &elem);

    int counter = 0;
    while (counter < elem) {
        printf("%s\n", *(fofo + counter));
        counter++;
    }

    // stoai
    char helloss[20] = "1 2 3";
    int elem2;
    int *hehe;
    hehe = stoai(helloss, &elem2);

    int counter2 = 0;
    while (counter2 < elem2) {
        printf("%d\n", hehe[counter2]);
        counter2++;
    }

    return 0;
}