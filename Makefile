# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/12 15:18:45 by tkajanek          #+#    #+#              #
#    Updated: 2023/04/12 16:33:43 by tkajanek         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER = server
NAME_CLIENT = client
SRC_SERVER = server.c
SRC_CLIENT = client.c
PRINT_F = ft_printf
CFLAGS += -Wall -Wextra -Werror

all:	library $(NAME_SERVER) $(NAME_CLIENT)

library:
	make -C $(PRINT_F) 

$(NAME_SERVER):
	cc $(SRC_SERVER) ft_printf/libftprintf.a -o $(NAME_SERVER)
	
$(NAME_CLIENT):
	cc $(SRC_CLIENT) ft_printf/libftprintf.a -o $(NAME_CLIENT)

clean:
	make clean -C $(PRINT_F)

fclean:	clean
	rm -f $(NAME_SERVER) $(NAME_CLIENT)
	make fclean -C $(PRINT_F)
	
re:	fclean all