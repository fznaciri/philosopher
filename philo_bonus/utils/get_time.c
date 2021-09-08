/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 18:38:15 by fnaciri-          #+#    #+#             */
/*   Updated: 2021/09/08 14:26:25 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

size_t	get_time(void)
{
	struct timeval	tv;
	size_t			t;

	gettimeofday(&tv, NULL);
	t = (tv.tv_sec * 1e3) + (tv.tv_usec / 1e3);
	return (t);
}

size_t	get_utime(size_t t0)
{
	size_t	t;

	t = get_time() - t0;
	return (t);
}
