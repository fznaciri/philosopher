# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 17:16:37 by mac               #+#    #+#              #
#    Updated: 2021/07/08 17:05:38 by fnaciri-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= 	main.c \
					utils/*.c \
					srcs/*.c

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
LIBS			= -lpthread

NAME			= philo

all:			$(NAME)

$(NAME):		$(SRCS)
				@$(CC) ${CFLAGS} $(SRCS) -o ${NAME} ${LIBS}

clean:
				@$(RM) $(NAME) 

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re