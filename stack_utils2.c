/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maslan <maslan@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:18:02 by maslan            #+#    #+#             */
/*   Updated: 2026/07/18 22:18:03 by maslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int	find_min_pos(t_stack *stack)
{
	int		min_value;
	int		min_pos;
	int		i;
	t_stack	*cur;

	min_value = stack->value;
	min_pos = 0;
	i = 0;
	cur = stack;
	while (cur)
	{
		if (cur->value < min_value)
		{
			min_value = cur->value;
			min_pos = i;
		}
		i++;
		cur = cur->next;
	}
	return (min_pos);
}

int	find_max_pos(t_stack *stack)
{
	int		max_value;
	int		max_pos;
	int		i;
	t_stack	*cur;

	max_value = stack->value;
	max_pos = 0;
	i = 0;
	cur = stack;
	while (cur)
	{
		if (cur->value > max_value)
		{
			max_value = cur->value;
			max_pos = i;
		}
		i++;
		cur = cur->next;
	}
	return (max_pos);
}

int	has_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}
