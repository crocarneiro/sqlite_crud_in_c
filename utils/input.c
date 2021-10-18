#include "input.h"

short int read_int(const char *label, int *result, int repeat)
{
    int a;
    int success;
    char buf[1024];

    if(repeat != 1) repeat = 0;

    do
    {
        fprintf(stdout, "%s", label);
        if(!fgets(buf, 1024, stdin))
            return 1;

        char *endptr;
        errno = 0;
        a = strtol(buf, &endptr, 10);
        if(errno == ERANGE)
        {
            fprintf(stdout, "Sorry, this number is too small or too large.\n");
            success = 0;
        }
        else if(endptr == buf)
        {
            success = 0;
        }
        else if(*endptr && *endptr != '\n')
        {
            success = 0;
        }
        else
        {
            success = 1;
        }
    } while(!success && repeat);

    *result = a;

    return success;
}