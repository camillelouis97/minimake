#include "parser_struct.h"
#include "option_handler.h"

struct parser* option_handler(char* argv[], int argc)
{
    struct parser* p = init_parser();
    if (!p)
        return NULL;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "-f"))
        {
            p->f = fopen(argv[i + 1], "r");
            if (p->f == NULL)
            {
                // error
                return NULL;
            }
        }
        if (strcmp(argv[i], "-h"))
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
            // error
            return NULL;
        }
    }
    return p;
}
