/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/06 16:55:59 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/07/12 15:02:53 by fnaciri-         ###   ########.fr       */
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
#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"



typedef struct s_param t_param;

typedef struct s_philo
{
    pthread_t       thread;
    int             id;
    int             is_eating;
    size_t          last_te;
    int             meals;
    pthread_mutex_t eating;
    t_param  *param;
} t_philo;

typedef struct s_param
{
    int             n_ph;
    unsigned int    te;
    unsigned int    ts;
    unsigned int    td;
    int             n_meals;
    unsigned int    t;
    pthread_t       supervisor;
    t_philo         *philos;
    pthread_mutex_t *forks;
    pthread_mutex_t display;
} t_param;

int init(t_param *param, int ac, char **av);
int start_threads(t_param *param);
void    take_forks(t_philo *philo);
void    *routine(void *philo);
void *supervisor(void *param);
int     check_meals(t_param *param);
int     check_death(t_param *param);
void display(t_philo *philo, char *str, char *c);
#endif 