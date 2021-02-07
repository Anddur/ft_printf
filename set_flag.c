/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 10:49:29 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:15:30 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_leftjustify(t_flags *flags, int index)
{
	flags->left_justify = 1;
	return (index + 1);
}

int		set_zerofill(t_flags *flags, int index)
{
	flags->zero_fill = 1;
	return (index + 1);
}

int		set_precision(t_flags *flags, int index)
{
	flags->precision = 0;
	return (index + 1);
}

int		set_star_p(t_flags *flags, int index)
{
	flags->star_p = 1;
	return (index + 1);
}

int		set_type(t_flags *flags, int index, char const *buffer)
{
	flags->type = buffer[index];
	return (index + 1);
}
