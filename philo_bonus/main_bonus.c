/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:38:34 by mac               #+#    #+#             */
/*   Updated: 2021/08/30 00:14:59 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"
#include <stdio.h>

int init(t_param *param, int ac, char **av)
{
    int i;
    
    if (!check_errors(ac, av))
        ft_puterror("Not Valid Arguments");
    param->n_ph = ft_atoi(av[1]);
    param->td = ft_atoi(av[2]);
    param->te = ft_atoi(av[3]);
    param->ts = ft_atoi(av[4]);
    param->t = get_time();
    if (ac == 6)
        param->n_meals = ft_atoi(av[5]);
    else
        param->n_meals = -1;
    param->philos = (t_philo*)malloc(sizeof(*(param->philos)) * param->n_ph);
    if (!param->philos)
        ft_puterror("Allocation Failed!");
    i = 0;
    while (i < param->n_ph)
    {
        param->philos[i].id = i + 1;
        param->philos[i].param = param;
        param->philos[i].is_eating = 0;
        param->philos[i].last_te = get_time();
        param->philos[i].meals = 0;
        sem_unlink("/philo_display");
        param->philos[i].eating = sem_open("/philo_eating", O_CREAT | O_EXCL,
					S_IRWXU, 1);
        i++;
    }
    sem_unlink("/philo_forks");
    sem_unlink("/philo_eating");
    param->display = sem_open("/philo_display", O_CREAT | O_EXCL, S_IRWXU, 1);
    param->forks = sem_open("/philo_display", O_CREAT | O_EXCL, S_IRWXU, param->n_ph);
    return (0);
}

int start(t_param *param)
{
    int i;
    int status;
    i = 0;
    while (i < param->n_ph)
    {
        param->philos[i].pid = fork();
        if (param->philos[i].pid < 0)
            return 1;
        if (param->philos[i].pid == 0)
        {
            pthread_create(&param->philos[i].supervisor, NULL, supervisor, &param->philos[i]);
            if (param->philos[i].id % 2 == 0)
                usleep(100);
            routine(&param->philos[i]);
        }
        pthread_join(param->philos[i].supervisor, NULL);
        exit (0);
    }
    i = 0;
    while (i < param->n_ph)
    {
        waitpid(-1, &status, 0);
		status = WEXITSTATUS(status);
    }
    while (++i < param->n_ph)
	{
        kill(param->philos[i].id, SIGTERM);
        sem_close(param->philos[i].eating); 
    }	
    sem_wait(param->display);
    ft_putstr_fd("All philosophers have eating at least ", 1);
    ft_putnbr_fd(((t_param*)param)->n_meals, 1);
    ft_putendl_fd(" meals", 1);
    sem_close(param->forks);
    sem_close(param->display);
    return (0);
}


int main(int ac, char **av)
{
    t_param param;
    
    if (ac == 1)
		return (0);
    if (ac < 5 || ac > 6)
        ft_puterror("Not valid Number of Arguments");
    init(&param, ac, av);
    start(&param);
    return (0);
}