/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:10:12 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/07/12 14:59:09 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"
#include <stdio.h>

int init(t_param *param, int ac, char **av)
{
    int i;

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
    param->forks = (pthread_mutex_t*)malloc(sizeof(*(param->forks)) * param->n_ph);
    if (!param->philos)
        return (1);
    if (!param->forks)
        return (1);
    i = 0;
    while (i < param->n_ph)
    {
        param->philos[i].id = i + 1;
        param->philos[i].param = param;
        param->philos[i].is_eating = 0;
        param->philos[i].last_te = get_time();
        param->philos[i].meals = 0;
        pthread_mutex_init(&param->forks[i], NULL);
        pthread_mutex_init(&param->philos[i].eating, NULL);
        i++;
    }
    pthread_mutex_init(&param->display, NULL);
    return (0);
}

int start_threads(t_param *param)
{
    int i;
    
    i = 0;
    while (i < param->n_ph)
	{
		pthread_create(&(param->philos[i].thread), NULL, &routine, &param->philos[i]);
        i++;
	}
    return (0);
}

int start_supervisor(t_param  *param)
{
    pthread_create(&param->supervisor, NULL, &supervisor, param);
    pthread_join(param->supervisor, NULL);
    return (0);
}

int main(int ac, char **av)
{
    t_param param;
    
    if (ac == 1)
		return (0);
    if (ac < 5 || ac > 6)
        ft_puterror();
    init(&param, ac, av);
    start_supervisor(&param);
    return (0);
}