/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maslan <maslan@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:17:17 by maslan            #+#    #+#             */
/*   Updated: 2026/07/18 22:17:18 by maslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* looks like an int? sign optional, at least one digit, nothing else */
int	is_valid_number(const char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/* atoi with overflow check. use long so we notice if the number blows past int */
int	ft_atoi_safe(const char *str, int *ok)
{
	long	result;
	int		sign;
	int		i;

	*ok = 0;
	if (!is_valid_number(str))
		return (0);
	result = 0;
	sign = 1;
	i = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i])
		result = result * 10 + (str[i++] - '0');
	if (sign == 1 && result > 2147483647)
		return (0);
	if (sign == -1 && result > 2147483648)
		return (0);
	*ok = 1;
	return ((int)(result * sign));
}
