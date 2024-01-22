/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rde-brui <rde-brui@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/11/15 13:29:00 by rde-brui      #+#    #+#                 */
/*   Updated: 2024/01/22 15:42:25 by rde-brui      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_str_one(t_p *p, t_fl *f)
{
	char			*null_check;

	if (f->sp == 'c')
	{
		p->i += cpy_number(p->str + p->i, va_arg(p->va, int), 1);
	}
	else if (f->sp == 's')
	{
		null_check = va_arg(p->va, char *);
		if (null_check == NULL || null_check == 0)
		{
			p->i += cpy(p->str + p->i, "(null)");
		}
		else
		{
			p->i += cpy(p->str + p->i, null_check);
		}
	}
	else if (f->sp == 'd' || f->sp == 'i')
	{
		p->i += signed_decimal_base(p->str + p->i, va_arg(p->va, int));
	}
}

void	spec_str_two(t_p *p, t_fl *f)
{
	if (f->sp == 'p')
	{
		f->nbr = va_arg(p->va, unsigned long);
		if (f->nbr == 0)
		{
			p->i += cpy(p->str + p->i, "(nil)");
		}
		else
		{
			p->i += cpy(p->str + p->i, "0x");
			p->i += ft_ultoa_base(f, f->nbr, p->str + p->i);
		}
	}
	else if (f->sp == 'x' || f->sp == 'X' || f->sp == 'u')
	{
		p->i += ft_ultoa_base(f, va_arg(p->va, unsigned int), p->str + p->i);
	}
	else if (f->sp == '%')
	{
		p->i += cpy(p->str + p->i, "%");
	}
}

int	ft_format(t_p *c)
{
	t_fl	flags;

	c->i = 0;
	c->mal = 0;
	c->k = 0;
	while (c->fmt && c->fmt[c->k] != '\0')
	{
		c->spec = parse_format(c, &flags, c->k);
		if (c->spec == -1)
		{
			if (c->count_or_str == true)
				c->mal++;
			else
				c->i += cpy_number(&c->str[c->i], c->fmt[c->k], 1);
			c->k++;
			continue ;
		}
		else
		{
			flag_check(c, &flags);
		}
		c->k++;
	}
	return (c->mal);
}

int	ft_printf(const char *format, ...)
{
	t_p		count;
	t_p		print;
	int		total;

	if (format == 0)
		return (-1);
	count.fmt = format;
	count.count_or_str = true;
	va_start(count.va, format);
	total = ft_format(&count);
	va_end(count.va);
	print.str = (char *)malloc((total + 1) * sizeof(char));
	if (print.str == NULL)
		return (0);
	print.str[total] = '\0';
	print.fmt = format;
	print.count_or_str = false;
	va_start(print.va, format);
	ft_format(&print);
	write(STDOUT_FILENO, print.str, total);
	va_end(print.va);
	free(print.str);
	return (total);
}

int	fft_printf(const char *format, va_list temp)
{
	t_p		count;
	t_p		print;
	int		total;

	if (format == 0)
		return (-1);
	count.fmt = format;
	count.count_or_str = true;
	va_copy(count.va, temp);
	total = ft_format(&count);
	va_end(count.va);
	print.str = (char *)malloc((total + 1) * sizeof(char));
	if (print.str == NULL)
		return (0);
	print.str[total] = '\0';
	print.fmt = format;
	print.count_or_str = false;
	va_copy(print.va, temp);
	ft_format(&print);
	write(STDOUT_FILENO, print.str, total);
	va_end(print.va);
	free(print.str);
	return (total);
}
