# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/05 19:35:03 by tkajanek          #+#    #+#              #
#    Updated: 2023/02/09 15:30:38 by tkajanek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
DEPS = ft_printf.h ./libft/libft.h
SRCS = ft_printf.c \
		ft_printf_conv.c \
		ft_print_unsigned.c \
		ft_print_ptr.c \
		ft_print_hex.c 
OBJS = $(SRCS:.c=.o)
LIBFT = ${wildcard libft/*.c}
LOBJS = ${LIBFT:.c=.o}
CFLAGS += -I./libft/ -Wall -Wextra -Werror

all: $(NAME)

$(NAME): runlibft $(OBJS) ${LOBJS}
	ar rc $(NAME) $(OBJS) ${LOBJS}
	
runlibft:
	make -C libft bonus

clean:
	rm -f $(OBJS)
	${MAKE} -C libft clean

fclean: clean
	rm -f $(NAME)
	${MAKE} -C libft fclean
	
re: fclean all

# -I./libft/ ukaze compilatoru cestu k headrum.
# Asi implicitne prirazuje pri kompilaci.

#"-C" command is used to change the current working directory
# to the specified directory ("libft" in this case).

# ${MAKE} reference is a variable that holds the name
# of the make command being used to build the project.
# the value of "${MAKE}" could be set to a different value,
# such as "gmake" or "pmake"
