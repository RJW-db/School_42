/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bonus_sort_spec.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: rjw <rjw@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/01/12 16:05:47 by rjw           #+#    #+#                 */
/*   Updated: 2024/01/20 14:49:24 by rjw           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static const t_bns_count	g_bns_cnt[4] = {
[0] = chr_bonus_count,
[1] = str_bonus_count,
[2] = int_bonus_count,
[3] = nbr_bonus_count,
};

static const t_bns_str		g_bns_str[4] = {
[0] = chr_bonus,
[1] = str_bonus,
[2] = int_bonus,
[3] = nbr_bonus,
};

static void	bonus_function(t_p *c, t_fl *f)
{
	short	i;

	if (f->sp == 'c')
	{
		i = 0;
	}
	else if (f->sp == 's')
	{
		i = 1;
	}
	else if (f->sp == 'd' || f->sp == 'i')
	{
		i = 2;
	}
	else
		i = 3;
	if (c->count_or_str == true)
	{
		g_bns_cnt[i](c, f);
	}
	else
		g_bns_str[i](c, f);
}

int	flag_check(t_p *c, t_fl *f)
{
	short	count_flags;

	count_flags = f->f_len + f->width + f->dot;
	if (c->count_or_str == true && count_flags == 0)
	{
		if (f->sp == 'c' || f->sp == 's' || f->sp == 'd' || f->sp == 'i')
			c->mal += spec_count_one(c, f);
		else
			c->mal += spec_count_two(c, f);
	}
	else if (c->count_or_str == false && count_flags == 0)
	{
		if (f->sp == 'c' || f->sp == 's' || f->sp == 'd' || f->sp == 'i')
			spec_str_one(c, f);
		else
			spec_str_two(c, f);
	}
	else
		bonus_function(c, f);
	return (c->mal);
}
