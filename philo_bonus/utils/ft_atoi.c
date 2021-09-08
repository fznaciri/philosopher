/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 17:29:22 by mac               #+#    #+#             */
/*   Updated: 2021/09/04 16:29:45 by fnaciri-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/utils.h"

long	ft_atoi(const char *s)
{
	int		i;
	size_t	n;
	int		sign;

	sign = 1;
	i = 0;
	n = 0;
	while ((s[i] >= 9 && s[i] <= 16) || s[i] == 32)
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] != '\0' && (s[i] >= '0' && s[i] <= '9'))
	{
		n = n * 10 + s[i] - '0';
		i++;
	}
	return (n * sign);
}
