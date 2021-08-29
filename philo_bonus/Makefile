# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mac <mac@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 17:16:37 by mac               #+#    #+#              #
#    Updated: 2021/08/28 17:38:49 by mac              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= 	main_bonus.c \
					utils/*.c \
					srcs/*.c

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.
LIBS			= -lpthread

NAME			= philo_bonus

all:			$(NAME)

$(NAME):		$(SRCS)
				@$(CC) ${CFLAGS} $(SRCS) -o ${NAME} ${LIBS}

clean:
				@$(RM) $(NAME) 

fclean:			clean
				@$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re