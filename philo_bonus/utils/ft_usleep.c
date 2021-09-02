/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 15:13:45 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/09/02 12:32:58 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void    ft_usleep(size_t time)
{
    size_t start;
    
    start = get_time();
	usleep (time * 1e3 - 20000);
	while (get_time() - start < time)
        ;
}