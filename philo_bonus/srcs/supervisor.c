/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:30:37 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/09/04 15:33:50 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_bonus.h"

void *supervisor(void *philo)
{
    t_philo *p;
    size_t  cur_time;
    
    p = (t_philo *)philo;
    while (1)
    {
        if (!p->is_eating)
        {
            sem_wait(p->eating);
            cur_time = get_time();
            if (cur_time - p->last_te >= p->param->td)
            {
                sem_wait(((t_philo *)philo)->param->display);
                ft_putstr_fd(KRED, 1);
                ft_putnbr_fd(get_utime(((t_philo *)philo)->param->t), 1);
                write(1, " ", 1);
                ft_putnbr_fd(((t_philo *)philo)->id, 1);
                ft_putstr_fd(" died", 1);
                kill(p->pid, SIGINT);
                return (NULL);
            }
            sem_post(p->eating);
        }
        if (p->meals >= p->param->n_meals && p->param->n_meals != -1)
        {
            // sem_wait(((t_philo *)philo)->param->display);
            exit(0);```
        }
        usleep(1e3);
    }
    return (NULL);
}