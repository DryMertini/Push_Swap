/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maslan <maslan@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:16:45 by maslan            #+#    #+#             */
/*   Updated: 2026/07/18 22:16:48 by maslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* move top node from src to dst, re-linking */
static void	do_push(t_stack **dst, t_stack **src)
{
	t_stack	*moved;

	if (!*src)
		return ;
	moved = *src;
	*src = moved->next;
	moved->next = *dst;
	*dst = moved;
}

void	pa(t_stack **a, t_stack **b)
{
	do_push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	do_push(b, a);
	write(1, "pb\n", 3);
}
