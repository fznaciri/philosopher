/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fnaciri- <fnaciri-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:44:09 by mac               #+#    #+#             */
/*   Updated: 2021/09/04 14:36:29 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

int	check_errors(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!str_digit(av[i]))
			return (0);
		i++;
	}
	return (1);
}
