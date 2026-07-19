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

/* ************************************************************************** */
/*                                                                            */
/*   ops_push.c                                                               */
/*                                                                            */
/*   pa : take top of b, put it on top of a.                                  */
/*   pb : take top of a, put it on top of b.                                  */
/*   No-op if the source stack is empty (subject requirement).                */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Generic "move the top of src on top of dst".
** Step by step:
**   1. detach the head of src   (moved = src head)
**   2. advance src to its next  (src = src->next)
**   3. point moved->next at the current dst head
**   4. dst head becomes moved
*/
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
