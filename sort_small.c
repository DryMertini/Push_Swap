/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maslan <maslan@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:17:50 by maslan            #+#    #+#             */
/*   Updated: 2026/07/18 22:17:51 by maslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	sort_three(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->value;
	mid = (*a)->next->value;
	bot = (*a)->next->next->value;
	if (top > mid && mid < bot && top < bot)
		sa(a);
	else if (top > mid && mid > bot)
	{
		sa(a);
		rra(a);
	}
	else if (top > mid && mid < bot && top > bot)
		ra(a);
	else if (top < mid && mid > bot && top < bot)
	{
		sa(a);
		ra(a);
	}
	else if (top < mid && mid > bot && top > bot)
		rra(a);
}

/* bring the smallest to top using whichever rotate direction is cheaper */
static void	bring_min_to_top(t_stack **a)
{
	int	size;
	int	min_pos;

	size = stack_size(*a);
	min_pos = find_min_pos(*a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(a);
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos-- > 0)
			rra(a);
	}
}

void	sort_small(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	while (size > 3)
	{
		bring_min_to_top(a);
		pb(a, b);
		size--;
	}
	sort_three(a);
	while (*b)
		pa(a, b);
}
