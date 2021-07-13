/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:30:37 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/07/13 19:09:35 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosopher.h"

int     check_death(t_param *param)
{
    int i;

    i = 0;
    while (i < param->n_ph)
    {
        if (!param->philos[i].is_eating && param->philos[i].last_te)
        {
            pthread_mutex_lock(&param->philos[i].eating);
            if (get_time() - param->philos[i].last_te >= param->td)
            {
                display(&param->philos[i], " died", KRED);
                pthread_mutex_lock(&param->display);
                return (1);
            }
            pthread_mutex_unlock(&param->philos[i].eating);
        }
        i++;
    }
    return (0);
}

int     check_meals(t_param *param)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while(i < param->n_ph && param->n_meals != -1)
    {
        if (param->philos[i].meals >= param->n_meals)
            n++;
        i++;
    }
    if (n == param->n_ph)
        return (1);
    return  (0);
}

void *supervisor(void *param)
{
    start_threads(param);
    usleep(100);
    while (1)
    {
        if (check_death(param))
            return (NULL);
        if (check_meals(param))
        {
            pthread_mutex_lock(&((t_param*)param)->display);
            ft_putstr_fd("All philosophers have eating at least ", 1);
            ft_putnbr_fd(((t_param*)param)->n_meals, 1);
            ft_putendl_fd(" meals", 1);
            return (NULL);
        }
    }
    return (NULL);
}