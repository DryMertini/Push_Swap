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

/* ************************************************************************** */
/*                                                                            */
/*   indexing.c                                                               */
/*                                                                            */
/*   assign_indices : after parsing, walk the stack once and give every       */
/*   node an "index" — its rank in sorted order (0 for the smallest).         */
/*                                                                            */
/*   Why: the sort algorithm doesn't care about actual values (they can be    */
/*   huge, like 2 billion). It only cares about relative order. Assigning     */
/*   small bounded indices 0..N-1 lets us split them into chunks cleanly.     */
/*                                                                            */
/*   Complexity: O(N²) — for each node, count how many have a smaller value.  */
/*   Only called once at the start; N is small so this is fine.               */
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
