/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rev_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maslan <maslan@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:16:54 by maslan            #+#    #+#             */
/*   Updated: 2026/07/20 16:01:59 by maslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/* reverse rotate: tail becomes the new head */
static void	do_rev_rotate(t_stack **stack)
{
	t_stack	*before_last;
	t_stack	*last;

	if (!*stack || !(*stack)->next)
		return ;
	before_last = *stack;
	while (before_last->next->next)
		before_last = before_last->next;
	last = before_last->next;
	before_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_stack **a)
{
	do_rev_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **b)
{
	do_rev_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b)
{
	do_rev_rotate(a);
	do_rev_rotate(b);
	write(1, "rrr\n", 4);
}
