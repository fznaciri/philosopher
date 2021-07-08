/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:55:59 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/07/07 18:46:11 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
#include "./utils.h"

typedef struct s_philo
{
    pthread_t       thread;
    int             id;
    struct t_param  *param;
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

#endif 