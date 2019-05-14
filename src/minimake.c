#include "option_handler.h"
#include "parser_struct.h"
#include "parser.h"

int main(int argc, char* argv[])
{
    struct parser* p = option_handler(argv, argc);
    if (p == NULL)
        return 1;
    if (p->h_opt)
        return 0;
    if (parse_file(p))
        return 1;
    for (int i = 0; p->target[i] != NULL; i++)
      printf(p->target[i]);
    free_parser(p);
    return 0;
}
