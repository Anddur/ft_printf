/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 16:40:59 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:13:55 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itohex(size_t add, int base, char *str, int count)
{
	while (add != 0)
	{
		if ((add % base) < 10)
			str[count - 1] = (add % base) + 48;
		else
			str[count - 1] = (add % base) + 87;
		add /= base;
		count--;
	}
	return (str);
}

char	*ft_utoa(size_t add, int base)
{
	char	*str;
	size_t	temp;
	int		count;

	temp = add;
	count = 0;
	while (temp != 0)
	{
		temp /= base;
		count++;
	}
	if (!(str = malloc(sizeof(char) * (count + 1))))
		return (NULL);
	str[count] = 0;
	str = ft_itohex(add, base, str, count);
	return (str);
}
