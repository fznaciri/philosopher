# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/07 17:16:37 by mac               #+#    #+#              #
#    Updated: 2021/09/08 16:49:29 by fnaciri-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			= 	main.c \
					utils/check_errors.c \
					utils/ft_atoi.c \
					utils/ft_isdigit.c \
					utils/ft_putendl_fd.c \
					utils/ft_puterror.c \
					utils/ft_putnbr_fd.c \
					utils/ft_putstr_fd.c \
					utils/ft_usleep.c \
					utils/get_time.c \
					utils/str_digit.c \
					srcs/display.c \
					srcs/routine.c \
					srcs/supervisor.c
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