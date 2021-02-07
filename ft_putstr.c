/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 15:26:45 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:13:50 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count += ft_putchar(str[count]);
	}
	return (count);
}
