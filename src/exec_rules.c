#include "exec_rules.h"

int exec_rules(char* argv[], int argc, struct parser* p)
{
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-f") != 0 && strcmp(argv[i], "-h") != 0)
        {
            int is_pres = 0;
            for (int j = 0; p->target[j] != NULL; j++)
                if (strcmp(p->target[j], argv[i]))
                {
                    is_pres = 1;
                    
                }
            if (!is_pres)
            {
                printf("rule does not exist\n");
                return 1;
            }
        }
    }

    return 0;
}
