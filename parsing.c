/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 11:36:05 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:14:24 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			parse_width(int index, char const *buffer, t_flags *flags)
{
	char	*width;
	int		i;
	int		size;

	i = index;
	size = 0;
	while (ft_isdigit(buffer[i++]))
		size++;
	if (!(width = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (ft_isdigit(buffer[index]))
		width[i++] = buffer[index++];
	width[i] = 0;
	flags->width = ft_atoi(width);
	free(width);
	return (index);
}

int			parse_prec(int index, char const *buffer, t_flags *flags)
{
	char	*precision;
	int		i;
	int		size;

	i = index;
	size = 0;
	while (ft_isdigit(buffer[i++]))
		size++;
	if (!(precision = malloc(sizeof(char) * (size + 1))))
		return (0);
	i = 0;
	while (ft_isdigit(buffer[index]))
		precision[i++] = buffer[index++];
	precision[i] = 0;
	flags->precision = ft_atoi(precision);
	free(precision);
	return (index);
}

int			set_star_w(t_flags *flags, int index)
{
	flags->star_w = 1;
	return (index + 1);
}

int			parsing(int i, char const *b, t_flags *flags)
{
	while (1)
	{
		if ((!is_flag(b[i]) && !is_type(b[i]) && !ft_isdigit(b[i]))
			|| flags->type == '%' || flags->type != 0)
			break ;
		else if (b[i] == '-')
			i = set_leftjustify(flags, i);
		else if (b[i] == '0' && flags->precision == -1 &&
				flags->width == 0)
			i = set_zerofill(flags, i);
		else if (b[i] == '*' && flags->precision == -1)
			i = set_star_w(flags, i);
		else if (ft_isdigit(b[i]) && flags->precision == -1)
			i = parse_width(i, b, flags);
		else if (b[i] == '.' && flags->type == 0)
			i = set_precision(flags, i);
		else if (b[i] == '*' && flags->precision == 0)
			i = set_star_p(flags, i);
		else if (ft_isdigit(b[i]) && flags->precision == 0 &&
				!flags->star_p)
			i = parse_prec(i, b, flags);
		else if (is_type(b[i]) && !is_type(flags->type))
			i = set_type(flags, i, b);
	}
	return (i - 1);
}
