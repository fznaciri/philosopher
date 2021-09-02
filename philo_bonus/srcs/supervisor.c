/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:30:37 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/09/02 12:23:16 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void *supervisor(void *philo)
{
    t_philo *p;
    
    p = (t_philo *)philo;
    while (1)
    {
        if (!p->is_eating)
        {
            sem_wait(p->eating);
            if (get_time() - p->last_te >= p->param->td)
            {
                display(p, " died", KRED);
                kill(p->pid, SIGINT);
                return (NULL);
            }
            sem_post(p->eating);
        }
        if (p->meals >= p->param->n_meals && p->param->n_meals != -1)
            exit(0);
    }
    return (NULL);
}