/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 15:34:46 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/09/04 15:35:08 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	display(t_philo *philo, char *str, char *c)
{
	pthread_mutex_lock(&philo->param->display);
	ft_putstr_fd(c, 1);
	ft_putnbr_fd(get_utime(philo->param->t), 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putendl_fd(str, 1);
	ft_putstr_fd(KNRM, 1);
	pthread_mutex_unlock(&philo->param->display);
}