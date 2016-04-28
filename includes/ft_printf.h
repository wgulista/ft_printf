#ifndef	FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>

/*typedef struct		s_buffer
{
	char				c;
	t_buffer			*next;
}					t_buffer;*/

typedef struct		s_env
{
	va_list			*args;
	char			type;
	int				diese;
	int				plus;
	int				flag_space;
	int				space;
	int				star;
	int				position;
	int				flag;
}					t_env;

typedef struct		s_count
{
	int				i;
	int				octet;
	int				func;
	int				value;
}					t_count;

typedef struct		s_printf
{
	char			*str;
	char			s_char;
	int				nb;
	unsigned int	u_nb;
}					t_printf;

int					conv_s(const char *str, int *i, va_list *args);
int					conv_S(const char *str, int *i, va_list *args);
int					(*p[14])(const char *str, int *i, va_list *args);	
int					check_flags(int c);

void				init_pointer();
void				init_var(t_count *cp);
void				init_env(t_env *env, va_list *args, int *i, const char *str);

void				find_n(t_env *env, int end, const char *str);
int					update_int(const char *str, int *i, va_list *args, int p_octet);

void				parse_space(const char *str, int *end, t_env *env);
void				calc_number(const char *str, int *end, char c, t_env *env);
int					end_space(t_env *env, int *i, int end);
int					ft_space(const char *str, int *i, t_env *env, char c);
int					ft_put_space(t_env *env);

int					calc_none_space(const char *str, int *i, va_list *args);


void				found_function(t_count *cp, const char *str, va_list *args);
void				find_plus(t_env *env, int *i, const char *str);
int					ft_printf(const char *format, ...);

#endif