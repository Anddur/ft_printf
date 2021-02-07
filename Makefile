NAME = libftprintf.a
LIBFT = ./libft/libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f
SRCS = ft_printf.c \
	ft_printminus.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_utoa.c \
	only_prec_u.c \
	only_prec.c \
	only_width_u.c \
	only_width.c \
	parsing_2.c \
	parsing.c \
	pos_neg.c \
	prec_width_u.c \
	prec_width.c \
	print_c.c \
	print_d.c \
	print_p.c \
	print_perc.c \
	print_s.c \
	print_u.c \
	print_var.c \
	print_x.c \
	print_xup.c \
	set_flag.c

OBJ = $(SRCS:.c=.o)

.c.o : $(CC) $(CFLAGS) -c $<

$(NAME) : $(OBJ)
	make -C ./libft
	cp $(LIBFT) ./$(NAME)
	$(AR) $(NAME) $^

all : $(NAME)

clean :
		$(RM) $(OBJ)
		make clean -C ./libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C ./libft

re : fclean all

.PHONY : all clean fclean re
