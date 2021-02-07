/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 11:16:30 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:12:55 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		flags_init(void)
{
	t_flags flags;

	flags.type = 0;
	flags.left_justify = 0;
	flags.zero_fill = 0;
	flags.width = 0;
	flags.precision = -1;
	flags.star_p = 0;
	flags.star_w = 0;
	return (flags);
}

int			manage_string(va_list arg, char const *buffer)
{
	int		char_count;
	int		index;
	t_flags	flags;

	char_count = 0;
	index = 0;
	while (1)
	{
		flags = flags_init();
		if (buffer[index] == 0)
			break ;
		else if (buffer[index] == '%' && buffer[index + 1] != 0)
		{
			index = parsing(index + 1, buffer, &flags);
			char_count += print_var(&flags, arg);
		}
		else if (buffer[index] != '%')
		{
			char_count += ft_putchar(buffer[index]);
		}
		index++;
	}
	return (char_count);
}

int			ft_printf(const char *input, ...)
{
	va_list		argptr;
	const char	*buffer;
	int			char_count;

	char_count = 0;
	buffer = ft_strdup(input);
	va_start(argptr, input);
	char_count = manage_string(argptr, buffer);
	va_end(argptr);
	return (char_count);
}
