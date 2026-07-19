/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maslan <maslan@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:17:26 by maslan            #+#    #+#             */
/*   Updated: 2026/07/18 22:17:27 by maslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

/*
** Tries to read every token in one argv[i] (which may contain spaces).
** Returns 1 on success, 0 on any error.
** On success it appends one node per number to *a (in argv order — so the
** first argv ends up at the TOP of the stack, as the subject requires).
*/
static int	parse_one_arg(const char *arg, t_stack **a)
{
	char	**tokens;
	int		i;
	int		ok;
	int		value;
	t_stack	*node;

	tokens = ft_split(arg, ' ');
	if (!tokens || !tokens[0])
		return (free_split(tokens), 0);
	i = -1;
	while (tokens[++i])
	{
		value = ft_atoi_safe(tokens[i], &ok);
		if (!ok || has_duplicate(*a, value))
			return (free_split(tokens), 0);
		node = new_node(value);
		if (!node)
			return (free_split(tokens), 0);
		add_back(a, node);
	}
	return (free_split(tokens), 1);
}

int	parse_args(int argc, char **argv, t_stack **a)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!parse_one_arg(argv[i], a))
			return (0);
		i++;
	}
	if (!*a)
		return (0);
	return (1);
}
