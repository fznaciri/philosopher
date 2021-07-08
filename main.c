/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 17:10:12 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/07/07 19:09:30 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philosopher.h"

int init(t_param *param, int ac, char **av)
{
    int i;

    i = 0;
    param->n_ph = ft_atoi(av[1]);
    param->td = ft_atoi(av[2]);
    param->te = ft_atoi(av[3]);
    param->ts = ft_atoi(av[4]);
    if (ac == 6)
        param->n_meals = ft_atoi(av[4]);
    else
        param->n_meals = 0;
    param->philos = (t_philo*)malloc(sizeof(*(param->philos)) * param->n_ph);
    param->forks = (pthread_mutex_t*)malloc(sizeof(*(param->forks)) * param->n_ph);
    if (!param->philos)
        return (1);
    if (!param->forks)
        return (1);
    while (i < param->n_ph)
    {
        param->philos[i].id = i;
        param->philos[i].param = param;
        pthread_mutex_init(&param->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&param->display, NULL);
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
    start_threads(&param.philos);

    return (0);
}