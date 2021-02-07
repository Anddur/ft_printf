/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:55:42 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:15:21 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print_x(t_flags flags, va_list arg)
{
	unsigned int	var;
	char			*str;
	int				count;

	count = 0;
	var = va_arg(arg, unsigned int);
	if (var == 0 && flags.precision != 0)
		str = ft_strdup("0");
	else
		str = ft_utoa(var, 16);
	count += manage_u(flags, str);
	return (count);
}
