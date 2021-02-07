/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aduregon <aduregon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:43:59 by aduregon          #+#    #+#             */
/*   Updated: 2021/01/20 19:13:13 by aduregon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_flags
{
	int				left_justify;
	int				zero_fill;
	int				width;
	int				precision;
	int				star_p;
	int				star_w;
	char			type;
}					t_flags;

int					ft_printf(const char *input, ...);
int					ft_putchar(char c);
int					parsing(int index, char const *buffer, t_flags *flags);
int					is_flag(char c);
int					is_type(char c);
int					set_leftjustify(t_flags *flags, int index);
int					set_zerofill(t_flags *flags, int index);
int					set_precision(t_flags *flags, int index);
int					set_star_p(t_flags *flags, int index);
int					set_star_w(t_flags *flags, int index);
int					set_type(t_flags *flags, int index, char const *buffer);
int					print_var(t_flags *flags, va_list arg);
int					print_c(t_flags flags, va_list arg);
int					print_s(t_flags flags, va_list arg);
int					ft_putstr(char *str);
int					print_p(t_flags flags, va_list arg);
char				*ft_utoa(size_t add, int base);
char				*ft_stoa(size_t n);
int					ft_atoi_base(char *str, char *base);
int					print_d(t_flags flags, va_list arg);
int					ft_printminus(char *str);
int					prec_width(char *str, t_flags flags);
int					only_prec(char *str, t_flags flags);
int					only_width(char *str, t_flags flags);
int					print_u(t_flags flags, va_list arg);
int					prec_width_u(char *str, t_flags flags);
int					only_prec_u(char *str, t_flags flags);
int					only_width_u(char *str, t_flags flags);
int					print_x(t_flags flags, va_list arg);
int					manage_u(t_flags flags, char *str);
int					print_xup(t_flags flags, va_list arg);
int					print_perc(t_flags flags);
void				print_flags(t_flags *flags);
int					pos(t_flags flags, int tempw);
int					neg(t_flags flags, int tempw);
int					manage_min(char *str, int tempp);

#endif
