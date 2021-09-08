/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:29:10 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/09/08 16:42:08 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"
#include <stdio.h>

int	init(t_param *param, int ac, char **av)
{
	int	i;

	get_data(param, ac, av);
	param->philos = (t_philo *)malloc(sizeof(*(param->philos)) * param->n_ph);
	if (!param->philos)
		ft_puterror("Allocation Failed!");
	init_sem(param);
	i = 0;
	while (i < param->n_ph)
	{
		param->philos[i].id = i + 1;
		param->philos[i].param = param;
		param->philos[i].is_eating = 0;
		param->philos[i].last_te = get_time();
		param->philos[i].meals = 0;
		i++;
	}
	return (0);
}

void	init_sem(t_param *param)
{
	sem_unlink("/philo_display");
	sem_unlink("/philo_forks");
	param->display = sem_open("/philo_display", O_CREAT | O_EXCL, S_IRWXU, 1);
	param->forks = sem_open("/philo_forks", O_CREAT | O_EXCL, S_IRWXU,
			param->n_ph);
}

void	get_data(t_param *param, int ac, char **av)
{
	if (!check_errors(ac, av))
		ft_puterror("Not Valid Arguments");
	param->n_ph = ft_atoi(av[1]);
	param->n_forks = param->n_ph;
	param->td = ft_atoi(av[2]);
	param->te = ft_atoi(av[3]);
	param->ts = ft_atoi(av[4]);
	param->t = get_time();
	if (ac == 6)
		param->n_meals = ft_atoi(av[5]);
	else
		param->n_meals = -1;
}

int	start(t_param *param)
{
	int	i;

	i = 0;
	while (i < param->n_ph)
	{
		param->philos[i].pid = fork();
		if (param->philos[i].pid < 0)
			return (1);
		if (param->philos[i].pid == 0)
		{
			sem_unlink("/philo_eating");
			param->philos[i].eating = sem_open("/philo_eating",
					O_CREAT | O_EXCL, S_IRWXU, 1);
			pthread_create(&param->philos[i].supervisor, NULL, supervisor,
				&param->philos[i]);
			routine(&param->philos[i]);
			exit (0);
		}
		i++;
	}
	ft_wait(param);
	return (0);
}

void	ft_wait(t_param *param)
{
	int	i;
	int	status;

	i = -1;
	while (++i < param->n_ph)
	{
		waitpid(-1, &status, 0);
		status = WEXITSTATUS(status);
		if (!status)
			sem_post(param->display);
	}
	sem_wait(param->display);
	ft_putstr_fd("All philosophers have eating at least ", 1);
	ft_putnbr_fd(((t_param *)param)->n_meals, 1);
	ft_putendl_fd(" meals", 1);
	i = -1;
	while (++i < param->n_ph)
	{
		kill(param->philos[i].pid, SIGTERM);
		sem_close(param->philos[i].eating);
	}
	sem_close(param->forks);
	sem_close(param->display);
}
