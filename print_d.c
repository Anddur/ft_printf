/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 15:37:24 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:14:48 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		only_d(char *str)
{
	int count;

	count = 0;
	count += ft_putstr(str);
	return (count);
}

int		manage_d(t_flags flags, char *str)
{
	int count;

	count = 0;
	if (flags.precision != -1 && flags.width != 0)
	{
		count += prec_width(str, flags);
	}
	else if (flags.precision != -1 && flags.width == 0)
	{
		count += only_prec(str, flags);
	}
	else if ((flags.precision == -1 && flags.width != 0) ||
		(flags.precision == -1 && flags.width == 0 && flags.star_w == 1))
	{
		count += only_width(str, flags);
	}
	else if ((flags.precision == -1 && flags.width == 0) ||
		(flags.precision == -1 && flags.width == 0 && flags.star_w == 0))
	{
		count += only_d(str);
	}
	return (count);
}

int		print_d(t_flags flags, va_list arg)
{
	int		var;
	char	*str;
	int		count;

	count = 0;
	var = va_arg(arg, int);
	str = ft_itoa(var);
	if (flags.precision == 0 && str[0] == '0')
		str[0] = 0;
	count = manage_d(flags, str);
	return (count);
}
