/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:47:14 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:15:09 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		only_u(char *str)
{
	int count;

	count = 0;
	count += ft_putstr(str);
	return (count);
}

int		manage_u(t_flags flags, char *str)
{
	int count;

	count = 0;
	if (flags.precision != -1 && flags.width != 0)
	{
		count += prec_width_u(str, flags);
	}
	else if (flags.precision != -1 && flags.width == 0)
	{
		count += only_prec_u(str, flags);
	}
	else if ((flags.precision == -1 && flags.width != 0) ||
		(flags.precision == -1 && flags.width == 0 && flags.star_w == 1))
	{
		count += only_width_u(str, flags);
	}
	else if ((flags.precision == -1 && flags.width == 0) ||
		(flags.precision == -1 && flags.width == 0 && flags.star_w == 0))
	{
		count += only_u(str);
	}
	return (count);
}

int		print_u(t_flags flags, va_list arg)
{
	unsigned int	var;
	char			*str;
	int				count;

	count = 0;
	var = va_arg(arg, unsigned int);
	if (var == 0 && flags.precision != 0)
		str = ft_strdup("0");
	else
		str = ft_utoa(var, 10);
	count += manage_u(flags, str);
	return (count);
}
