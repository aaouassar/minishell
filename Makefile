# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaouassa <aaouassa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/08 13:19:40 by aaouassa          #+#    #+#              #
#    Updated: 2023/06/16 16:11:43 by aaouassa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

SRC = cd.c echo.c env.c exit.c pwd.c export.c export.helps.c unset.c unset.helps.c creat.c builtins.c helps1.c helps2.c helps3.c exec.c exec.utils1.c exec.utils2.c helpo.c

OBJS = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	 gcc  $(OBJS) -o $(NAME)

clean : 
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	
re : fclean all

