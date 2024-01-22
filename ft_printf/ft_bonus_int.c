/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bonus_int.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/14 14:40:19 by rjw           #+#    #+#                 */
/*   Updated: 2024/01/20 01:09:19 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_p2(t_p *c, t_fl *f, int prefix)
{
	if (f->width >= 0 && f->dash == false && f->dot == true)
		c->mal += f->width + (f->nbr == 0 && f->space == false && f->prec == 0);
	else if (f->width >= 0 && f->dash == false && f->zero == false)
		c->mal += f->width;
	if (f->sign != 'X')
		c->mal += 1;
	if (f->dot == true && f->prec - f->ap_len + prefix > 0)
		c->mal += f->prec - f->ap_len + prefix;
	else if (f->zero == true && f->width > 0 && f->dot == false)
		c->mal += f->width;
	if (f->nbr != 0 || (f->width && f->prec) || (f->nbr == 0
			&& f->dot == false))
	{
		c->mal += (long)unsigned_count(f, f->nbr);
	}
	else if (f->nbr == 0 && f->space == true && f->width > 0)
		c->mal += 1;
	if (f->width >= 0 && f->dash == true)
	{
		c->mal += f->width + (f->dot == true && f->nbr == 0 && f->space == false
				&& f->prec == 0);
	}
	return (c->mal);
}

/**
 * @brief d & i,
 * negative number negates the flag +,,
 * space will be ignored when there is +,
 * 0 is ignored when - is there,
 * s and c have their own structure
*/
int	int_bonus_count(t_p *c, t_fl *f)
{
	int		prefix;

	f->nbr = va_arg(c->va, int);
	prefix = ((f->nbr < 0) || f->plus || (f->width <= 0 && f->space));
	f->ap_len = signed_count(f->nbr) + (prefix == 1 && (f->nbr >= 0));
	if (f->ap_len - prefix >= f->prec)
		f->width -= f->ap_len;
	else
		f->width -= f->prec + prefix;
	if (f->nbr < 0)
	{
		f->sign = '-';
		f->nbr *= -1;
	}
	else if (f->plus == true && f->sign == 'X')
		f->sign = '+';
	else if (f->space == true && f->sign == 'X')
	{
		f->sign = ' ';
		f->width -= 1;
	}
	if (f->dash == true)
		f->zero = false;
	count_p2(c, f, prefix);
	return (c->mal);
}

static void	int_bonus_p2(t_p *p, t_fl *f, int prefix)
{
	if (f->width >= 0 && f->dash == false && f->dot == true)
	{
		p->i += cpy_number(p->str + p->i, ' ', f->width
				+ (f->nbr == 0 && f->space == false && f->prec == 0));
	}
	else if (f->width >= 0 && f->dash == false && f->zero == false)
		p->i += cpy_number(p->str + p->i, ' ', f->width);
	if (f->sign != 'X')
		p->i += cpy_number(p->str + p->i, f->sign, 1);
	if (f->dot == true)
		p->i += cpy_number(p->str + p->i, '0', f->prec - f->ap_len + prefix);
	else if (f->zero == true)
		p->i += cpy_number(p->str + p->i, '0', f->width);
	if (f->nbr != 0 || (f->width && f->prec) || (f->nbr == 0
			&& f->dot == false))
		p->i += ft_ultoa_base(f, f->nbr, p->str + p->i);
	else if (f->nbr == 0 && f->space == true && f->width > 0)
		p->i += cpy(p->str + p->i, " ");
	if (f->width >= 0 && f->dash == true)
	{
		p->i += cpy_number(p->str + p->i, ' ', f->width + (f->dot == true
					&& f->nbr == 0 && f->space == false && f->prec == 0));
	}
}

/**
 * @brief d & i,
 * negative number negates the flag +,,
 * space will be ignored when there is +,
 * 0 is ignored when - is there,
 * s and c have their own structure
*/
void	int_bonus(t_p *p, t_fl *f)
{
	int		prefix;

	f->nbr = va_arg(p->va, int);
	prefix = ((f->nbr < 0) || f->plus || (f->width <= 0 && f->space));
	f->ap_len = signed_count(f->nbr) + (prefix == 1 && (f->nbr >= 0));
	if (f->ap_len - prefix >= f->prec)
		f->width -= f->ap_len;
	else
		f->width -= f->prec + prefix;
	if (f->nbr < 0)
	{
		f->sign = '-';
		f->nbr *= -1;
	}
	else if (f->plus == true && f->sign == 'X')
		f->sign = '+';
	else if (f->space == true && f->sign == 'X')
	{
		f->sign = ' ';
		f->width -= 1;
	}
	if (f->dash == true)
		f->zero = false;
	int_bonus_p2(p, f, prefix);
}
