/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:40:33 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:14:43 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_c(t_flags flags, va_list arg)
{
	char	c;
	int		count;

	count = 1;
	c = va_arg(arg, int);
	if (!c)
		c = '\0';
	if (flags.zero_fill != 0 || flags.precision != -1)
		return (0);
	else
	{
		if (flags.left_justify)
		{
			ft_putchar(c);
			while (count++ < flags.width)
				ft_putchar(' ');
		}
		else
		{
			while (count++ < flags.width)
				ft_putchar(' ');
			ft_putchar(c);
		}
	}
	return (count - 1);
}
