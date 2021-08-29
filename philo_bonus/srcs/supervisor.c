/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:30:37 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/08/28 17:33:13 by mac              ###   ########.fr       */
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
                sem_wait(p->param->display);
                return (NULL);
            }
            sem_post(p->eating);
        }
        if (p->meals >= p->param->n_meals && p->param->n_meals != -1)
            break;
    }
    return (NULL);
}