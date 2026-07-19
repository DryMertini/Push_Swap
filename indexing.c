/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maslan <maslan@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:16:05 by maslan            #+#    #+#             */
/*   Updated: 2026/07/18 22:16:11 by maslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_indices(t_stack *stack)
{
	t_stack	*current;
	t_stack	*runner;
	int		count;

	current = stack;
	while (current)
	{
		count = 0;
		runner = stack;
		while (runner)
		{
			if (runner->value < current->value)
				count++;
			runner = runner->next;
		}
		current->index = count;
		current = current->next;
	}
}
