#include "string.h"

/*
 *  String allocation
 */
char *strmk(char *str_p, char *str, int len) {
    str_p = (char *)calloc(len + 1, sizeof(char));
    strcpy(str_p, str);
    return(str_p);
}

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

/*
    // Get value starting LSB to MSB
    int count = len - 1,
        val = 0,
        mult = 1;
    while (count > sign - 1) {
        val = val + (num[count] - '0') * mult;
        count--;
        mult *= 10;
    }
*/

    // Get the value starting from MSB to LSB
    int count = sign,
        val = 0;
    while (count < len) {
        val = val * 10 + (num[count] - '0');
        count++;
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