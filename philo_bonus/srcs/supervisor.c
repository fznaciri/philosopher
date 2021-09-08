/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:30:37 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/09/08 16:34:04 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

int	check_death(void *p)
{
	size_t	cur_time;

	cur_time = get_time();
	if (cur_time - ((t_philo *)p)->last_te >= ((t_philo *)p)->param->td)
	{
		sem_wait(((t_philo *)p)->param->display);
		ft_putstr_fd(KRED, 1);
		ft_putnbr_fd(get_utime(((t_philo *)p)->param->t), 1);
		write(1, " ", 1);
		ft_putnbr_fd(((t_philo *)p)->id, 1);
		ft_putstr_fd(" died", 1);
		kill(((t_philo *)p)->pid, SIGINT);
		return (1);
	}
	return (0);
}

void	*supervisor(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (1)
	{
		if (!p->is_eating)
		{
			sem_wait(p->eating);
			if (check_death(philo))
				return (NULL);
			sem_post(p->eating);
		}
		if (p->meals >= p->param->n_meals && p->param->n_meals != -1)
		{
			sem_wait(p->param->display);
			exit(0);
		}
		usleep(1e3);
	}
	return (NULL);
}
