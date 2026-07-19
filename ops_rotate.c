/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maslan <maslan@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:17:02 by maslan            #+#    #+#             */
/*   Updated: 2026/07/18 22:17:03 by maslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/*
** Walk to the tail. Detach the head. Re-attach the head as the new tail.
** Before:  A -> B -> C -> D
** After:   B -> C -> D -> A
*/
static void	do_rotate(t_stack **stack)
{
	t_stack	*old_head;
	t_stack	*tail;

	if (!*stack || !(*stack)->next)
		return ;
	old_head = *stack;
	*stack = old_head->next;
	tail = *stack;
	while (tail->next)
		tail = tail->next;
	tail->next = old_head;
	old_head->next = NULL;
}

void	ra(t_stack **a)
{
	do_rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_stack **b)
{
	do_rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b)
{
	do_rotate(a);
	do_rotate(b);
	write(1, "rr\n", 3);
}
