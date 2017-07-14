/*
 *  File: strint.h
 *  Author: Rusty Mina (rusty.mina@eee.upd.edu.ph)
 *  Comments: Library for converting string to integers
 *  Revision History:
 *      July 10, 2017   -   Initial library commit
 */

#ifndef __STRINT__H_
#define __STRINT__H_
#endif

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/*
 *  String allocation
 */
char *strmk(char *str_p, char *str, int len);

/*
 *  String to Int function
 */
int stoi(char *num);

/*
 *  String to array of string
 */
char** split(char *str, char *delim, int *elem);

/*
 *  String to array of int
 */
int *stoai(char *str, int *elem);

/*
 *  Array of string to array of int
 */
int *astoai(char **str_p, int elem);