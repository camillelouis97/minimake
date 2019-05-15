#define _GNU_SOURCE

#include "parser_struct.h"
#include "parser.h"

int check_rules(char* str)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == ':')
            return i;
    return -1;
}

int check_arr(struct parser* p)
{
  if (p->rule == NULL)
  {
    char *r = malloc(1);
    r[0] = '\0';
    p->rule = arr_add(r, p->rule);
    if (!p->rule)
      return 1;
  }
  for (int i = 0; p->target[i] != NULL; i++)
  {
    for (int j = 0; p->target[i][j] != '\0'; j++)
      if (p->target[i][j] == ' ')
      {
        printf("Multiple targets for one rule\n");
        return 1;
      }
    if (!p->rule[i])
    {
      char *r = malloc(1);
      r[0] = '\0';
      p->rule = arr_add_index(r, p->rule, i);
      if (!p->rule)
        return 1;
    }
  }
  return 0;
}

int parse_file(struct parser* p)
{
  ssize_t nread;
  size_t len = 0;
  char* line = NULL;
  int target_len;

  while ((nread = getline(&line, &len, p->f)) != -1)
  {
    if (strcmp(line, "\n") == 0)
      continue;
    if ((target_len = check_rules(line)) != -1)
    {
      if (target_len == 0)
      {
        printf("no rule\n");
        return 1;
      }
      p->target = arr_add(my_strncpy(line, target_len), p->target);
      p->index++;
      p->dep = arr_add(my_strncpy(line + target_len,
            strlen(line) - target_len), p->dep);
      if (!(p->target || p->dep))
        return 1;
    }
    else
    {
      if (line[0] != '\t' && line[0] != '#')
      {
        printf("no tab\n");
        return 1;
      }
      if (p->index == -1)
      {
        printf("*** recipe commences before first target.  Stop.\n");
        return 2;
      }
      p->rule = arr_add_index(my_strncpy(line, strlen(line)), p->rule, p->index);
      if (!p->rule)
        return 1;
    }
  }
  return check_arr(p);
}
