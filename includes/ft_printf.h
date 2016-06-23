/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wgulista <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/22 15:52:27 by wgulista          #+#    #+#             */
/*   Updated: 2016/06/22 15:52:29 by wgulista         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/includes/libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>
# define WIDTH e->width
# define NBWIDTH e->nb_width
# define PREC e->precision
# define NBPREC e->nb_precision
# define FLAGS e->flags
# define MDF e->modifier
# define SPEC e->spec
# define SHARP e->f.sharp
# define ZERO e->f.zero
# define PLUS e->f.plus
# define MINUS e->f.minus
# define SPACE e->f.space
# define SIZE e->m.size
# define HH e->m.hh
# define H e->m.h
# define LL e->m.ll
# define L e->m.l
# define J e->m.j
# define Z e->m.z

typedef struct	s_flag
{
	short		sharp;
	short		zero;
	short		minus;
	short		plus;
	short		space;
}				t_flag;

typedef struct	s_mdf
{
	short		size;
	short		h;
	short		hh;
	short		l;
	short		ll;
	short		j;
	short		z;
}				t_mdf;

typedef struct	s_env
{
	char		*s;
	int			len;
	short		width;
	short		precision;
	short		nb_width;
	short		nb_precision;
	t_flag		f;
	t_mdf		m;
	char		spec;
	va_list		ap;
}				t_env;

int				check_char(char c, char *check);
char			*set_plus_minus(char **ret, intmax_t i, t_env *e);
char			*set_flags(char **ret, intmax_t i, t_env *e);
char			*set_width(char **ret, t_env *e);
char			*minus_bug(char **ret);
void			get_flags(t_env *e);
void			get_size(t_env *e);
void			get_prec(t_env *e);
void			get_width(t_env *e);

int				ft_size_gs(wint_t wint);
char			*wchar_conv(unsigned hexa);
char			*ft_str_accurate(char *str, intmax_t i, t_env *e);

void			conv_c(t_env *e);
void			conv_wc(t_env *e);
void			conv_s(t_env *e);
void			conv_ws(t_env *e);
void			conv_p(t_env *e);
void			conv_id(t_env *e);
void			conv_gd(t_env *e);
void			conv_o(t_env *e);
void			conv_go(t_env *e);
void			conv_u(t_env *e);
void			conv_gu(t_env *e);
void			conv_x(t_env *e);
void			conv_gx(t_env *e);

void			conv_parser(t_env *e);
void			non_conv(t_env *e);

void			new_env(t_env *e);
void			delete_env(t_env *e);
void			analyse(t_env *e);
int				ft_printf(const char *format, ...);

#endif
