#include "parser_struct.h"
#include "option_handler.h"

struct parser* option_handler(char* argv[], int argc)
{
    struct parser* p = init_parser();
    if (!p)
        return NULL;
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-f") == 0)
        {
            p->f = fopen(argv[i + 1], "r");
            if (p->f == NULL)
            {
                printf("file does not exist\n");
                return NULL;
            }
        }
        if (strcmp(argv[i], "-h") == 0)
        {
            // display help
            if (p->f == NULL)
                p->h_opt = 1;
        }
    }
    if (p->f == NULL)
    {
        p->f = fopen("makefile", "r");
        if (p->f == NULL)
            p->f = fopen("Makefile", "r");
        if (p->f == NULL)
        {
            printf("no makefile");
            return NULL;
        }
    }
    return p;
}
