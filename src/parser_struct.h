#include <stdio.h>
#include <stdlib.h>

typedef struct parser
{
    int h_opt;
    int index;
    FILE* f;
    char** target;
    char** dep;
    char** rule;
} parser;

struct parser* init_parser(void);
void free_parser(struct parser* p);
