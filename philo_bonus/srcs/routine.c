/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:00:23 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/09/08 16:39:07 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void	display(t_philo *philo, char *str, char *c)
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

void	eat(t_philo *philo)
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

void	*routine(t_philo *philo)
{
	while (1)
	{
		sem_wait(philo->param->forks);
		display(philo, " has taking a fork", KBLU);
		philo->param->n_forks--;
		sem_wait(philo->param->forks);
		display(philo, " has taking a fork", KBLU);
		philo->param->n_forks--;
		eat(philo);
		sem_post(philo->param->forks);
		philo->param->n_forks++;
		sem_post(philo->param->forks);
		philo->param->n_forks++;
		display(philo, " is sleeping", KMAG);
		ft_usleep(philo->param->ts);
		display(philo, " is thinking", KCYN);
	}
	return (NULL);
}
