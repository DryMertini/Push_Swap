/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maslan <maslan@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:17:56 by maslan            #+#    #+#             */
/*   Updated: 2026/07/18 22:17:57 by maslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_stack	*new_node(int value)
{
	t_stack	*node;

	node = (t_stack *)malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

/*
** Appends to the tail. We use this only during parsing because we want
** argv[1] to end up on TOP of stack a. If we add_back each new number,
** the first number stays at the head — which we treat as the top.
*/
void	add_back(t_stack **stack, t_stack *node)
{
	t_stack	*cur;

	if (!*stack)
	{
		*stack = node;
		return ;
	}
	cur = *stack;
	while (cur->next)
		cur = cur->next;
	cur->next = node;
}

void	free_stack(t_stack **stack)
{
	t_stack	*cur;
	t_stack	*next;

	if (!stack)
		return ;
	cur = *stack;
	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*stack = NULL;
}

int	stack_size(t_stack *stack)
{
	int	count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
