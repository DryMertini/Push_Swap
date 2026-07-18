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


/* ************************************************************************** */
/*                                                                            */
/*   parser_utils.c                                                           */
/*                                                                            */
/*   Helper functions for parsing:                                            */
/*   - is_valid_number : does a string look like an integer literal?          */
/*   - ft_atoi_safe    : convert AND check for int overflow                   */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Accepts an optional single '+' or '-' followed by at least one digit.
** Rejects empty string, leading whitespace, multiple signs, letters, etc.
*/
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

/*
** Parses a string into an int.
** *ok is set to 1 on success, 0 if the string is malformed or out of range.
** We accumulate the absolute value into a long so we can spot anything
** that would overflow int (INT_MIN = -2147483648, INT_MAX = 2147483647).
*/
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
