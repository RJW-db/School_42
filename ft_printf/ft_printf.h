/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 13:26:28 by rde-brui      #+#    #+#                 */
/*   Updated: 2024/01/20 01:12:40 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define SPECIFIER "csdiupxX%"
# include <stdarg.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdlib.h>

typedef struct p_print
{
	const char		*fmt;
	short			spec;
	va_list			va;
	int				mal;
	char			*str;
	int				i;
	int				k;
	bool			count_or_str;
}	t_p;

typedef struct s_flags
{
	char	sp;
	bool	space;
	bool	plus;
	bool	dash;
	bool	zero;
	bool	hash;
	short	hsh;
	int		width;
	bool	dot;
	int		prec;
	int		f_len;
	int		ap_len;
	bool	minus;
	char	sign;
	long	nbr;
	char	*base;
	short	b_num;
	char	prefix[3];
	bool	stop;
	va_list	count;
}	t_fl;

typedef int				(*t_bns_count) (t_p *, t_fl *);
typedef void			(*t_bns_str) (t_p *, t_fl *);

int						fft_printf(const char *format, va_list temp);
int						ft_printf(const char *fmt, ...);
int						ft_format(t_p *p);

int						parse_format(t_p *c, t_fl *f, int i);
int						flag_check(t_p *c, t_fl *f);

int						spec_count_one(t_p *c, t_fl *f);
int						spec_count_two(t_p *c, t_fl *f);
void					spec_str_one(t_p *p, t_fl *f);
void					spec_str_two(t_p *p, t_fl *f);

int						unsigned_count(t_fl *f, unsigned long n);
int						signed_count(int n);
int						cpy(char *dst, const char *src);
int						cpy_number(char *str, const char c, int n);
int						cpy_num(char *dst, const char *src, int num);
int						signed_decimal_base(char *str, int n);
int						ft_ultoa_base(t_fl *f, unsigned long n, char *str);
size_t					str_len(const char *s);

int						chr_bonus_count(t_p *c, t_fl *f);
void					chr_bonus(t_p *p, t_fl *f);
int						str_bonus_count(t_p *c, t_fl *f);
void					str_bonus(t_p *p, t_fl *f);
int						int_bonus_count(t_p *c, t_fl *f);
void					int_bonus(t_p *p, t_fl *f);
void					nbr_bonus(t_p *p, t_fl *f);
int						nbr_bonus_count(t_p *c, t_fl *f);
#endif