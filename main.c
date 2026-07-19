/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maslan <maslan@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:16:35 by maslan            #+#    #+#             */
/*   Updated: 2026/07/18 22:16:38 by maslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Pick the cheapest sort routine for the size we actually have:
**   size 0..1     -> nothing to do
**   already sorted -> nothing to do
**   size 2        -> one sa
**   size 3        -> hand-written (at most 2 ops)
**   size 4..5     -> bring min to top, push to b, sort_three, pop back
**   size >5       -> chunk algorithm (hits the 700 / 5500 benchmarks)
*/
static void	sort_dispatch(t_stack **a, t_stack **b)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1 || is_sorted(*a))
		return ;
	if (size == 2)
		sa(a);
	else if (size == 3)
		sort_three(a);
	else if (size <= 5)
		sort_small(a, b);
	else
		sort_chunks(a, b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if (!parse_args(argc, argv, &a))
	{
		free_stack(&a);
		write(2, "Error\n", 6);
		return (1);
	}
	assign_indices(a);
	sort_dispatch(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
