/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_prec_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:20:23 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:14:01 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		only_prec_u(char *str, t_flags flags)
{
	int count;
	int tempp;

	count = 0;
	tempp = flags.precision;
	if (flags.precision >= (int)ft_strlen(str))
	{
		while ((tempp-- - (int)ft_strlen(str)) > 0)
			count += ft_putchar('0');
	}
	count += ft_putstr(str);
	return (count);
}
