/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pos_neg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 21:35:30 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:14:28 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pos(t_flags flags, int tempw)
{
	int count;

	count = 0;
	while ((tempw-- - flags.precision > 0)
			&& flags.width > flags.precision)
		count += ft_putchar(' ');
	return (count);
}

int		neg(t_flags flags, int tempw)
{
	int count;

	count = 0;
	while ((tempw-- - flags.precision - 1 > 0)
			&& flags.width > flags.precision)
		count += ft_putchar(' ');
	return (count);
}

int		manage_min(char *str, int tempp)
{
	int count;

	count = 0;
	while ((tempp-- - (int)ft_strlen(str)) > 0)
		count += ft_putchar('0');
	return (count);
}
