/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 17:38:34 by mac               #+#    #+#             */
/*   Updated: 2021/09/08 16:15:39 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo_bonus.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	t_param	param;

	if (ac == 1)
		return (0);
	if (ac < 5 || ac > 6)
		ft_puterror("Not valid Number of Arguments");
	init(&param, ac, av);
	start(&param);
	return (0);
}
