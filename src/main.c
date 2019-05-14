//#define _GNU_SOURCE
#define _POSIX_C_SOURCE >= 200809L || _XOPEN_SOURCE >= 700

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
    free_parser(p);
    return 0;
}
