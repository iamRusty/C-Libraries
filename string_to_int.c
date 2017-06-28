#include <stdio.h>
#include <string.h> /* from string import strlen */
#include <math.h>   /* from math import pow */
#include <stdlib.h> /* from stdlib import calloc, malloc */

int strtoint(char *num);
char** split(char *str, char *delim, int *elem);
char *strmk(char *str_p, char *str, int len);

/*
 *    String to Int function
 */
int strtoint(char *num) {
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
 *  String allocation
 */
char *strmk(char *str_p, char *str, int len) {
    str_p = (char *)calloc(len + 1, sizeof(char));
    strcpy(str_p, str);
    return(str_p);
}

int main (void) {
    // strtoint
    char try[5] = "-10";
    int hello;
    hello = strtoint(try);
    printf("%d\n", hello);

    // strmk
    char *yeyeye;
    char hellos[4] = "new";
    strmk(yeyeye, hellos, strlen(hellos));

    // split
    int elem = 0;
    char yeye[200] = "he he he he ha werwerwre wsd qwe w wr q er";
    char delim[2] = " ";
    char **fofo;
    fofo = split(yeye, delim, &elem);

    int counter = 0;
    while (counter < elem) {
        printf("%s\n", *(fofo + counter));
        counter++;
    }

    return 0;
}