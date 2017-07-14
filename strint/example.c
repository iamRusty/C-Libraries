#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "strint.h"

int main(){
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