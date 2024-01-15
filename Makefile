# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hel-band <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 15:44:59 by hel-band          #+#    #+#              #
#    Updated: 2024/01/10 15:53:17 by hel-band         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FT_PRINTF_PATH  =   ft_printf/
FT_PRINTF_LIB   =   libftprintf.a
FT_PRINTF       =   $(FT_PRINTF_PATH)$(FT_PRINTF_LIB)

SERVER          =   server
CLIENT          =   client

CC              =   cc
FLAGS           =   -Wall -Werror -Wextra
RM              =   rm -f
AR              =   ar rcs
INCLUDE         =   -I ./$(FT_PRINTF_PATH)

all: $(FT_PRINTF) $(SERVER) $(CLIENT)

$(FT_PRINTF):
	@MAKE -s -C $(FT_PRINTF_PATH)

$(SERVER): $(FT_PRINTF) server.c
	@$(CC) $(FLAGS) server.c -o $(SERVER) $(FT_PRINTF) $(INCLUDE)
	@echo "Server is ready - run ./server"

$(CLIENT): $(FT_PRINTF) client.c
	@$(CC) $(FLAGS) client.c -o $(CLIENT) $(FT_PRINTF) $(INCLUDE)
	@echo "Client is ready - run ./client"

clean:
	@MAKE clean -s -C $(FT_PRINTF_PATH)
	@echo "ft_printf objects are now deleted."

fclean: clean
	@$(RM) $(SERVER) $(CLIENT)
	@$(RM) $(FT_PRINTF_PATH)$(FT_PRINTF_LIB)
	@echo "and libftprintf.a server client"

re: fclean all

