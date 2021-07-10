/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:00:23 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/07/10 18:45:37 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

void	get_left_right(t_philo *philo, int *l, int *r)
{
	*l = philo->id - 1;
	if (philo->id == philo->param->n_ph)
		*r = 0;
	else
		*r = philo->id;
}

void display(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->param->display);
	ft_putnbr_fd(get_utime(philo->param->t), 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->id, 1);
	ft_putendl_fd(str, 1);
	pthread_mutex_unlock(&philo->param->display);
}

void    take_forks(t_philo *philo)
{
	int l;
	int r;
	get_left_right(philo, &l, &r);
    pthread_mutex_lock(&philo->param->forks[l]);
	display(philo," has taking a fork");
	pthread_mutex_lock(&philo->param->forks[r]);
	display(philo," has taking a fork");
}

void eat(t_philo *philo)
{
	display(philo, " is eating");
	philo->is_eating = 1;
	usleep(philo->param->te * 1000);
	philo->last_te = get_time();
	philo->is_eating = 0;
}

void sleeping(t_philo *philo)
{
	int l;
	int r;
	get_left_right(philo, &l, &r);
	pthread_mutex_unlock(&philo->param->forks[l]);
	pthread_mutex_unlock(&philo->param->forks[r]);
	display(philo, " is sleeping");
	usleep(philo->param->ts * 1000);
	display(philo, " is thinking"); 
}

void    *routine(void *philo)
{
	if (((t_philo *)philo)->id % 2 == 0)
		usleep(200);
	take_forks(philo);
	eat(philo);
	sleeping(philo);
	return (NULL);
}