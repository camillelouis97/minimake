#include "struct_parser.h"

struct parser* init_parser(void)
{
    struct parser* p = malloc(sizeof(struct parser));
    if (!p)
        return NULL;
    p->h_opt = 0;
    p->f = NULL;
    p->target = NULL;
    p->dep = NULL;
    p->rule = NULL;
    return p;
}

void free_array(char* arr[])
{
    if (arr)
    {
        for (int i = 0; arr[i] != NULL; i++)
            free(arr[i]);
        free(arr);
    }
}

void free_parser(struct parser* p)
{
    if (p)
    {
        if (p->f)
            fclose(p->f);
        free_array(p->target);
        free_array(p->dep);
        free_array(p->rule);
        free(p);
    }
}
