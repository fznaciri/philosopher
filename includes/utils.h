/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:30:06 by mac               #+#    #+#             */
/*   Updated: 2021/07/07 17:34:01 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include <unistd.h>

long	ft_atoi(const char *s);
void	ft_puterror(void);
void	ft_putendl_fd(char *s, int fd);

#endif