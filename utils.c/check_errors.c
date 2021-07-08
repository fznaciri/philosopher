/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:44:09 by mac               #+#    #+#             */
/*   Updated: 2021/07/07 17:46:15 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

void	check_errors(int ac, char **av)
{
	int	i;

	i = 0;
	while (av[ac][i])
	{
		if (!(ft_isdigit(av[ac][i])))
			ft_puterror();
		i++;
	}
}