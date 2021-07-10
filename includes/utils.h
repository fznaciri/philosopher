/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:30:06 by mac               #+#    #+#             */
/*   Updated: 2021/07/10 18:44:25 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <unistd.h>
#include <sys/time.h>
long	ft_atoi(const char *s);
void	ft_puterror(void);
void	ft_putendl_fd(char *s, int fd);
//void	check_errors(int ac, char **av);
void	ft_putnbr_fd(int n, int fd);
size_t get_time();
size_t get_utime(size_t t0);
#endif