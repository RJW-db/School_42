/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bonus_flags.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 00:29:08 by rjw           #+#    #+#                 */
/*   Updated: 2024/01/20 14:17:16 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_width_prec(t_p *c, t_fl *f, int k, int *width_prec)
{
	if (f->stop == true)
	{
		if (c->fmt[k] != '.')
			return (k);
		f->dot = true;
		k++;
	}
	else
		f->stop = true;
	while (c->fmt[k] >= '0' && c->fmt[k] <= '9')
	{
		*width_prec = *width_prec * 10 + (c->fmt[k] - 48);
		k++;
	}
	return (k);
}

static int	get_flags(t_p *c, t_fl *f, int k)
{
	while (c->fmt[k] == ' ' || c->fmt[k] == '+' || c->fmt[k] == '-'
		|| c->fmt[k] == '0' || c->fmt[k] == '#')
	{
		if (c->fmt[k] == ' ')
			f->space = true;
		else if (c->fmt[k] == '+')
			f->plus = true;
		else if (c->fmt[k] == '-')
			f->dash = true;
		else if (c->fmt[k] == '0')
			f->zero = 48;
		else if (c->fmt[k] == '#')
			f->hash = true;
		f->f_len++;
		k++;
	}
	return (k);
}

static int	find_spec(t_fl *f, const char fmt, short i)
{
	while (SPECIFIER[i] != '\0')
	{
		if (fmt == SPECIFIER[i])
		{
			f->sp = fmt;
			f->b_num = 16;
			f->base = "0123456789abcdef";
			cpy(f->prefix, "0x");
			if (fmt == 'X')
			{
				f->base = "0123456789ABCDEF";
				cpy(f->prefix, "0X");
			}
			else if (fmt == 'u' || fmt == 'd' || fmt == 'i')
			{
				f->base = "0123456789";
				f->b_num = 10;
			}
			return (i);
		}
		i++;
	}
	return (-1);
}

static void	flags_reset(t_fl *f)
{
	f->space = false;
	f->plus = false;
	f->dash = false;
	f->zero = false;
	f->hash = false;
	f->hsh = 0;
	f->width = 0;
	f->dot = false;
	f->prec = 0;
	f->f_len = 0;
	f->ap_len = 0;
	f->sign = 'X';
	f->stop = false;
	cpy_number(f->prefix, '\0', 3);
}

int	parse_format(t_p *c, t_fl *f, int k)
{
	const int	begin = k;
	short		specifier;
	short		i;

	flags_reset(f);
	if (c->fmt[k] != '%')
		return (-1);
	k++;
	c->k++;
	i = 0;
	specifier = find_spec(f, c->fmt[k], i);
	if (specifier >= 0)
		return (specifier);
	k = get_flags(c, f, k);
	k = get_width_prec(c, f, k, &f->width);
	k = get_width_prec(c, f, k, &f->prec);
	specifier = find_spec(f, c->fmt[k], i);
	if (specifier == -1)
		flags_reset(f);
	c->k += k - begin - 1;
	return (specifier);
}
