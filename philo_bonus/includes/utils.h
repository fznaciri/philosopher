/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:30:06 by mac               #+#    #+#             */
/*   Updated: 2021/09/08 14:38:00 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

long	ft_atoi(const char *s);
void	ft_puterror(char *str);
void	ft_putendl_fd(char *s, int fd);
int		check_errors(int ac, char **av);
int		str_digit(char *s);
int		ft_isdigit(int c);
void	ft_putnbr_fd(int n, int fd);
size_t	get_time(void);
size_t	get_utime(size_t t0);
void	ft_putstr_fd(char *s, int fd);
void	ft_usleep(size_t time);

#endif
