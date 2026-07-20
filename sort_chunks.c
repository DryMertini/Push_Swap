/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_chunks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maslan <maslan@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:17:44 by maslan            #+#    #+#             */
/*   Updated: 2026/07/18 22:17:45 by maslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static int	get_chunk_size(int size)
{
	if (size <= 100)
		return (16);
	return (80);
}

/* phase 2: pull max from b, rotate to top (cheaper way), pa. loop till empty */
static void	phase_two(t_stack **a, t_stack **b)
{
	int	size_b;
	int	max_pos;

	while (*b)
	{
		size_b = stack_size(*b);
		max_pos = find_max_pos(*b);
		if (max_pos <= size_b / 2)
		{
			while (max_pos-- > 0)
				rb(b);
		}
		else
		{
			max_pos = size_b - max_pos;
			while (max_pos-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

/* how many nodes in a have index in [lo, hi] — tells us when chunk is done */
static int	count_in_range(t_stack *a, int lo, int hi)
{
	int	count;

	count = 0;
	while (a)
	{
		if (a->index >= lo && a->index <= hi)
			count++;
		a = a->next;
	}
	return (count);
}

/* push every node in the chunk to b. sink small ones with rb (pre-orders b) */
static void	process_chunk(t_stack **a, t_stack **b, int lo, int hi)
{
	int	remaining;
	int	mid;
	int	idx;

	remaining = count_in_range(*a, lo, hi);
	mid = (lo + hi) / 2;
	while (remaining > 0)
	{
		idx = (*a)->index;
		if (idx >= lo && idx <= hi)
		{
			pb(a, b);
			remaining--;
			if (idx < mid && *b && (*b)->next)
				rb(b);
		}
		else
			ra(a);
	}
}

void	sort_chunks(t_stack **a, t_stack **b)
{
	int	size;
	int	chunk;
	int	lo;
	int	hi;

	size = stack_size(*a);
	chunk = get_chunk_size(size);
	lo = 0;
	while (lo < size)
	{
		hi = lo + chunk - 1;
		if (hi >= size)
			hi = size - 1;
		process_chunk(a, b, lo, hi);
		lo = hi + 1;
	}
	phase_two(a, b);
}
