#include "parser_struct.h"
#include "parser.h"

int check_rules(char* str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ':')
            return i;
    return -1;
}

int parse_file(struct parser* p)
{
    ssize_t nread;
    size_t len = 0;
    char* line = NULL;
    int target_len;

    while ((nread = getline(&line, &len, p->f)) != -1)
    {
        if ((target_len = check_rules(line)) != -1)
        {
            if (target_len == 0)
            {
                // error
                return 1;
            }
            p->target = arr_add(my_strncpy(line, target_len), p->target);
            p->dep = arr_add(my_strncpy(line + target_len,
                                        strlen(line) - target_len), p->dep);
            char *r = malloc(1);
            if (!(p->target || p->dep || r))
                return 1;
            r = "\0";
            while ((getline(&line, &len, p->f)) != -1)
            {
                if (check_rules(line))
                {
                    p->rule = arr_add(r, p->rule);
                    if (!p->rule)
                        return 1;
                    break;
                }
                if (line[0] != '\t')
                {
                    // error
                    return 1;
                }
                my_strcat(r, line);
            }
        }
    }

    return 0;
}
