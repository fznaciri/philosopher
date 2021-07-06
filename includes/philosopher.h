/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:55:59 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/07/06 17:10:59 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct s_philo
{
    int             id;
    unsigned int    te;
    unsigned int    ts;
    unsigned int    td;
    int             n_ph;
    int             n_meals;
    pthread_mutex_t *forks;
} t_philo;


#endif 