#include <stdio.h>
#include <string.h> /* from string import strlen */
#include <math.h>   /* from math import pow */


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

int main (void) {
    char try[5] = "-10";

    int hello;
    hello = strtoint(try);

    printf("%d\n", hello);
    return 0;
}