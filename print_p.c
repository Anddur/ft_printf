/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:14:55 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:14:52 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		manage_p(t_flags flags, char *str)
{
	int count;

	count = 0;
	if (flags.left_justify == 1)
	{
		count += ft_putstr(str);
		while (count < flags.width)
			count += ft_putchar(' ');
	}
	else
	{
		while ((flags.width - (int)ft_strlen(str)) > 0)
		{
			count += ft_putchar(' ');
			flags.width -= 1;
		}
		count += ft_putstr(str);
	}
	return (count);
}

int		print_p(t_flags flags, va_list arg)
{
	size_t	punt;
	char	*tempstr;
	char	*addstr;
	int		count;

	punt = va_arg(arg, size_t);
	count = 0;
	tempstr = ft_utoa(punt, 16);
	if (!(addstr = malloc(sizeof(char) * (ft_strlen(tempstr) + 3))))
		return (0);
	addstr[0] = '0';
	addstr[1] = 'x';
	while (tempstr[count] != 0)
	{
		addstr[count + 2] = tempstr[count];
		count++;
	}
	if (!punt && flags.precision != 0)
		addstr[2] = '0';
	count = manage_p(flags, addstr);
	free(addstr);
	return (count);
}
