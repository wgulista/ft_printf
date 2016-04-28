#include "../includes/ft_printf.h"

void    parse_space(const char *str, int *end, t_env *env)
{
  while (str[*end] == '-' || str[*end] == '#'
     || str[*end] == '+' || str[*end] == ' ')
    {
      if (str[*end] == '-')
    		env->position = 1;
      *end = *end + 1;
    }
}
 
void    calc_number(const char *str, int *end, char c, t_env *env)
{
  int   nb;
 
  nb = 0;
  while (str[*end] != '\0' && str[*end] != c
     && str[*end] >= '0' && str[*end] <= '9')
    {
      nb = nb * 10;
      nb = nb + str[*end] - '0';
      *end = *end + 1;
    }
  env->space = nb;
}
 
int end_space(t_env *env, int *i, int end)
{
  if (env->star == 1)
    env->space = va_arg(*(env->args), int);
  		*i = end - 1;
  env->flag = 1;
  return (0);
}
 
int ft_space(const char *str, int *i, t_env *env, char c)
{
  int   end;
 
  end = *i + 1;
  parse_space(str, &end, env);
  if (str[end] != '*' && (str[end] < '0' || str[end] > '9'))
    return (-1);
  if (str[end] == '0')
    {
      env->type = '0';
      end++;
    }
  else
    env->type = ' ';
  if (str[end] != '*')
    calc_number(str, &end, c, env);
  else
    env->star = 1;
  while (str[end] == '*')
    end++;
  if (str[end] == c)
    return (end_space(env, i, end));
  return (-1);
}
 
int ft_put_space(t_env *env)
{
  int   i;
 
  i = 0;
  while (i < env->space)
    {
      ft_putchar(env->type);
      i++;
    }
  return (env->space);
}