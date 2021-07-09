/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:55:59 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/07/08 17:07:27 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include "./utils.h"

typedef struct s_param t_param;

typedef struct s_philo
{
    pthread_t       thread;
    int             id;
    t_param  *param;
} t_philo;

typedef struct s_param
{
    int             n_ph;
    unsigned int    te;
    unsigned int    ts;
    unsigned int    td;
    int             n_meals;
    unsigned int    time;
    t_philo         *philos;
    pthread_mutex_t *forks;
    pthread_mutex_t display;
} t_param;

int init(t_param *param, int ac, char **av);
int start_threads(t_param *param);
void    take_forks(t_philo *philo);
void    *routine(void *philo);
#endif 