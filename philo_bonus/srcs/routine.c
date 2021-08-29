/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:00:23 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/08/28 17:57:56 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void display(t_philo *philo, char *str, char *c)
{
	sem_wait(philo->param->display);
	ft_putstr_fd(c, 1);
	ft_putnbr_fd(get_utime(philo->param->t), 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putendl_fd(str, 1);
	ft_putstr_fd(KNRM, 1);
	sem_post(philo->param->display);
}

void eat(t_philo *philo)
{
	display(philo, " is eating", KGRN);
	sem_wait(philo->eating);
	philo->is_eating = 1;
	philo->last_te = get_time();
	ft_usleep(philo->param->te);
	philo->meals++;
	sem_post(philo->eating);
	philo->is_eating = 0;
}

void    *routine(t_philo *philo)
{
	if (philo->id % 2 == 0)
		usleep(200);
	while (1)
	{
		sem_wait(philo->param->forks);
		display(philo," has taking a fork", KBLU);
		sem_wait(philo->param->forks);
		display(philo," has taking a fork", KBLU);
		eat(philo);
		sem_post(philo->param->forks);
		sem_post(philo->param->forks);
		display(philo, " is sleeping", KMAG);
		ft_usleep(philo->param->ts);
		display(philo, " is thinking", KCYN);
	}
	return (NULL);
}