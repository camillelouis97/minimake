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
    int res;
    if ((res = parse_file(p)))
        return res;
    int i = 0;
    for (; p->target[i] != NULL; i++);
    printf("%d: target\n", i);
    i = 0;
    for (; p->dep[i] != NULL; i++);
    printf("%d: dep\n", i);
    i = 0;
    for (; p->rule[i] != NULL; i++);
    printf("%d: rule\n", i);
    for (int i = 0; p->target[i] != NULL; i++)
    {
      printf("%d:\n", i);
      printf("%s\n", p->target[i]);
      printf("%s\n", p->dep[i]);
      printf("%s\n", p->rule[i]);
    }
    free_parser(p);
    return 0;
}
