#ifndef INPUT_H_
#define INPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
/**
 * Reads an int from the console.
 * The result of the function goes to the "result" parameter.
 * Returns 0 if success
 * Returns 1 if failure
 */
short int read_int(const char *label, int *result, int repeat);

#endif