/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bonus_str.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/10 18:29:06 by rde-brui      #+#    #+#                 */
/*   Updated: 2024/01/20 01:09:29 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	flag_specific(t_p *p, t_fl *f, char *str)
{
	int		spaces;

	if (f->prec < f->ap_len)
	{
		spaces = f->width - f->prec;
		f->width = f->prec;
	}
	else
	{
		spaces = f->width - f->ap_len;
		f->width = f->ap_len;
	}
	if (f->dash == true)
	{
		p->i += cpy_num(p->str + p->i, str, f->width);
	}
	if (spaces > 0)
	{
		p->i += cpy_number(p->str + p->i, ' ', spaces);
	}
	if (f->dash == false)
	{
		p->i += cpy_num(p->str + p->i, str, f->width);
	}
}

static void	str_bonus_trun(t_p *p, t_fl *f)
{
	char	*null_check;

	null_check = va_arg(p->va, char *);
	if (null_check == NULL)
	{
		if (f->dash == true && f->prec >= 6)
		{
			p->i += cpy(p->str + p->i, "(null)");
		}
		else if (f->prec >= 6 && f->width <= 0)
		{
			p->i += cpy(p->str + p->i, "(null)");
		}
		else if (f->prec >= 6 && f->width > 0)
		{
			p->i += cpy_number(p->str + p->i, ' ', f->width - f->prec);
			p->i += cpy(p->str + p->i, "(null)");
		}
		else
		{
			p->i += cpy_number(p->str + p->i, ' ', f->width);
		}
	}
	else
		flag_specific(p, f, null_check);
}

/**
 * @brief	Allowed flags ".-6"   6 - minimum width
 * 			"%.-15s" not allowed order
*/
void	str_bonus(t_p *p, t_fl *f)
{
	t_p	tmp_copy;

	tmp_copy = *p;
	f->ap_len = spec_count_one(&tmp_copy, f);
	va_end(tmp_copy.va);
	if (f->dot == false && f->ap_len >= f->width)
	{
		spec_str_one(p, f);
	}
	else if (f->dot == false && f->ap_len < f->width)
	{
		if (f->dash == true)
			spec_str_one(p, f);
		p->i += cpy_number(p->str + p->i, ' ', f->width - f->ap_len);
		if (f->dash == false)
			spec_str_one(p, f);
	}
	else if (f->dot == true)
	{
		str_bonus_trun(p, f);
	}
}
