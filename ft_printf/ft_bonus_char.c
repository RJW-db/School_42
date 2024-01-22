/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bonus_char.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/09 18:09:43 by rde-brui      #+#    #+#                 */
/*   Updated: 2024/01/20 01:12:47 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	chr_bonus_count(t_p *c, t_fl *f)
{
	va_arg(c->va, int);
	if (f->width == 0)
	{
		c->mal++;
	}
	else
	{
		c->mal += f->width;
	}
	return (c->mal);
}

void	chr_bonus(t_p *p, t_fl *f)
{
	if (f->dash == false)
	{
		p->i += cpy_number(p->str + p->i, ' ', f->width - 1);
	}
	p->str[p->i] = va_arg(p->va, int);
	p->i++;
	if (f->dash == true && f->width > 0)
	{
		p->i += cpy_number(p->str + p->i, ' ', f->width - 1);
	}
}
