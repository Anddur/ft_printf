/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printminus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 17:08:04 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:13:28 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printminus(char *str)
{
	int index;

	index = 0;
	ft_putchar('-');
	while (str[index])
	{
		str[index] = str[index + 1];
		index++;
	}
	str[index] = 0;
	return (1);
}
