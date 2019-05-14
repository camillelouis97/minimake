#include "exec_rules.h"

int exec_rules(char* argv[], int argc, struct parser* p)
{
    for (int i = 1; i < argc; i++)
    {
        if (!(strcmp(argv[i], "-f") || strcmp(argv[i], "-h")))
        {
            int is_pres = 0;
            for (int j = 0; p->target[j] != NULL; j++)
                if (strcmp(p->target[j], argv[i]))
                {
                    is_pres = 1;
                    // exec rule
                }
            if (!is_pres)
            {
                // error
                return 1;
            }
        }
    }

    return 0;
}
