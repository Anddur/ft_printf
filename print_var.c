/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_var.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 12:38:11 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:15:15 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_star_w(t_flags *flags, va_list arg)
{
	if (flags->star_w == 1)
	{
		flags->width = va_arg(arg, int);
	}
	if (flags->width < 0)
	{
		flags->width *= -1;
		flags->left_justify = 1;
	}
}

void	check_star_p(t_flags *flags, va_list arg)
{
	if (flags->star_p == 1)
	{
		flags->precision = va_arg(arg, int);
	}
}

int		print_var(t_flags *flags, va_list arg)
{
	int count;

	count = 0;
	check_star_w(flags, arg);
	check_star_p(flags, arg);
	if (flags->type == 'c')
		count += print_c(*flags, arg);
	if (flags->type == 's')
		count += print_s(*flags, arg);
	if (flags->type == 'p')
		count += print_p(*flags, arg);
	if (flags->type == 'd' || flags->type == 'i')
		count += print_d(*flags, arg);
	if (flags->type == 'u')
		count += print_u(*flags, arg);
	if (flags->type == 'x')
		count += print_x(*flags, arg);
	if (flags->type == 'X')
		count += print_xup(*flags, arg);
	if (flags->type == '%')
		count += print_perc(*flags);
	return (count);
}
