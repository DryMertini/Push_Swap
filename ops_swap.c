/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maslan <maslan@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:17:10 by maslan            #+#    #+#             */
/*   Updated: 2026/07/18 22:17:11 by maslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/*
** Linked-list swap: we don't move data, we re-link pointers.
** Before:   A -> B -> rest
** After:    B -> A -> rest
** The caller's pointer to the head is updated to point at B.
*/
static void	do_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **a)
{
	do_swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	do_swap(b);
	write(1, "sb\n", 3);
}

/*
** ss does sa and sb together — but it is ONE printed operation, not two.
** That's why we call do_swap twice but write "ss\n" only once.
*/
void	ss(t_stack **a, t_stack **b)
{
	do_swap(a);
	do_swap(b);
	write(1, "ss\n", 3);
}
