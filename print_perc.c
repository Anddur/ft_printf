/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_perc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 17:07:38 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:14:59 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_perc(t_flags flags)
{
	int count;

	count = 0;
	if (flags.left_justify == 1)
	{
		count += ft_putchar('%');
		while (flags.width-- - 1 > 0)
			count += ft_putchar(' ');
	}
	else if (flags.zero_fill == 1)
	{
		while (flags.width-- - 1 > 0)
			count += ft_putchar('0');
		count += ft_putchar('%');
	}
	else
	{
		while (flags.width-- - 1 > 0)
			count += ft_putchar(' ');
		count += ft_putchar('%');
	}
	return (count);
}
