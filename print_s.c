/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_s.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 10:53:50 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:15:04 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*resize_str(char *str, int precision)
{
	char	*newstr;
	int		index;

	index = 0;
	if (precision == 0)
	{
		str = ft_strdup("");
		return (str);
	}
	if (!(newstr = malloc(sizeof(char) * (precision + 1))))
		return (NULL);
	while (precision > 0)
	{
		newstr[index] = str[index];
		index++;
		precision--;
	}
	newstr[index] = 0;
	str = ft_strdup(newstr);
	free(newstr);
	return (str);
}

int		print_width(char *str, t_flags flags)
{
	int count;

	count = 0;
	count += ft_putstr(str);
	while (count < flags.width)
		count += ft_putchar(' ');
	return (count);
}

int		print_s(t_flags flags, va_list arg)
{
	char	*str;
	int		count;

	count = 0;
	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";
	if (flags.precision < 0)
		flags.precision = -1;
	if ((int)ft_strlen(str) > flags.precision && flags.precision != -1)
		str = resize_str(str, flags.precision);
	if (flags.left_justify == 1)
		count += print_width(str, flags);
	else
	{
		while ((flags.width - (int)ft_strlen(str)) > 0)
		{
			count += ft_putchar(' ');
			flags.width -= 1;
		}
		count += ft_putstr(str);
	}
	return (count);
}
