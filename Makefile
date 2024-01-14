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

CC              =   gcc
FLAGS           =   -Wall -Werror -Wextra
RM              =   rm -f
AR              =   ar rcs
INCLUDE         =   -I ./$(FT_PRINTF_PATH)

all: $(FT_PRINTF) $(SERVER) $(CLIENT)

$(FT_PRINTF):
	MAKE -s -C $(FT_PRINTF_PATH)

$(SERVER): $(FT_PRINTF)
	$(CC) $(FLAGS) server.c -o $(SERVER) $(FT_PRINTF) $(INCLUDE)

$(CLIENT): $(FT_PRINTF)
	$(CC) $(FLAGS) client.c -o $(CLIENT) $(FT_PRINTF) $(INCLUDE)
	
clean:
	MAKE clean -s -C $(FT_PRINTF_PATH)

fclean: clean
	$(RM) $(SERVER) $(CLIENT)

re: fclean all
.PHONY: all clean fclean re
