/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 13:00:23 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/07/13 19:13:14 by fnaciri-         ###   ########.fr       */
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

void display(t_philo *philo, char *str, char *c)
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

void    take_forks(t_philo *philo)
{
	int l;
	int r;
	get_left_right(philo, &l, &r);
    pthread_mutex_lock(&philo->param->forks[l]);
	display(philo," has taking a fork", KBLU);
	pthread_mutex_lock(&philo->param->forks[r]);
	display(philo," has taking a fork", KBLU);
}

void eat(t_philo *philo)
{
	display(philo, " is eating", KGRN);
	pthread_mutex_lock(&philo->eating);
	philo->is_eating = 1;
	philo->last_te = get_time();
	ft_usleep(philo->param->te);
	philo->meals++;
	pthread_mutex_unlock(&philo->eating);
	philo->is_eating = 0;
}

void sleeping(t_philo *philo)
{
	int l;
	int r;
	get_left_right(philo, &l, &r);
	pthread_mutex_unlock(&philo->param->forks[l]);
	pthread_mutex_unlock(&philo->param->forks[r]);
	display(philo, " is sleeping", KMAG);
	ft_usleep(philo->param->ts);
	display(philo, " is thinking", KCYN); 
}

void    *routine(void *philo)
{
	if (((t_philo *)philo)->id % 2 == 0)
		usleep(200);
	while (1)
	{
		take_forks(philo);
		eat(philo);
		sleeping(philo);
	}
	return (NULL);
}