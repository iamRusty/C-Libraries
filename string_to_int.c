#include <stdio.h>
#include <string.h> /* from string import strlen */
#include <math.h>   /* from math import pow */
#include <stdlib.h> /* from stdlib import calloc, malloc, realloc, free, NULL */

int stoi(char *num);
char** split(char *str, char *delim, int *elem);
char *strmk(char *str_p, char *str, int len);
int *stoai(char *str, int *elem);
int *astoai(char **str_p, int elem);

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

    // Set last element(invisible) as NULL 
    ret = (char **)realloc(ret, (count + 1) * sizeof(char *));
    *(ret + count) = NULL;

    // Set return values
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
    ret = (int *)malloc((split_elem + 1) * sizeof(int));

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
 *  Array of string to array of int
 */
int *astoai(char **str_p, int elem) {

    // Initial array of int allocation
    int *ret;
    ret = (int *)malloc(elem * sizeof(int));
    
    // astoai proper
    int ct = 0;
    while (ct < elem) {
        ret[ct] = stoi(*(str_p + ct));
        ct++;
    }

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
    printf("\nstoi\n");
    char try[5] = "-10";
    int hello;
    hello = stoi(try);
    printf("%d\n", hello);

    // strmk
    printf("\nstrmk\n");
    char *yeyeye;
    char hellos[4] = "new";
    yeyeye = strmk(yeyeye, hellos, strlen(hellos));
    printf("%s\n", yeyeye);
    free(yeyeye);

    // split
    printf("\nsplit\n");
    int elem = 0;
    char yeye[200] = "12 1 2 -1 5 -100";
    char delim[2] = " ";
    char **fofo;
    fofo = split(yeye, delim, &elem);

    int counter = 0;
    while (counter < elem) {
        printf("%s\n", *(fofo + counter));
        //free(*(fofo + counter));  // FREE ALLOC
        counter++;
    }
    //free(fofo); // FREE ALLOC

    // stoai
    printf("\nstoai\n");
    char helloss[20] = "1 2 3";
    int elem2;
    int *hehe;
    hehe = stoai(helloss, &elem2);

    int counter2 = 0;
    while (counter2 < elem2) {
        printf("%d\n", hehe[counter2]); // FREE ALLOC
        counter2++;
    }
    free(hehe); // FREE ALLOC

    // astoai
    printf("\nastoai\n");
    int *hehehe;
    hehehe = astoai(fofo, elem);
    int counter3 = 0;
    while (counter3 < elem) {
        printf("%d\n", hehehe[counter3]);
        free(*(fofo + counter3));  // FREE ALLOC
        counter3++;
    }
    free(*(fofo + counter3));  // FREE ALLOC
    free(hehehe);   // FREE ALLOC
    
    return 0;
}