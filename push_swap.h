/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maslan <maslan@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 22:17:38 by maslan            #+#    #+#             */
/*   Updated: 2026/07/18 22:17:39 by maslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/* stack node: value = the raw int, index = its sorted rank (0 = smallest) */
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

/* ----- parser.c / parser_utils.c / ft_split.c -------------------------- */
int		parse_args(int argc, char **argv, t_stack **a);
int		ft_atoi_safe(const char *str, int *ok);
int		is_valid_number(const char *str);
char	**ft_split(const char *s, char c);
void	free_split(char **arr);

/* ----- stack_utils.c / stack_utils2.c --------------------------------- */
t_stack	*new_node(int value);
void	add_back(t_stack **stack, t_stack *node);
void	free_stack(t_stack **stack);
int		stack_size(t_stack *stack);
int		is_sorted(t_stack *stack);
int		find_min_pos(t_stack *stack);
int		find_max_pos(t_stack *stack);
int		has_duplicate(t_stack *stack, int value);

/* ----- operations: ops_*.c -------------------------------------------- */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

/* ----- indexing.c / sort_small.c / sort_chunks.c ---------------------- */
void	assign_indices(t_stack *stack);
void	sort_three(t_stack **a);
void	sort_small(t_stack **a, t_stack **b);
void	sort_chunks(t_stack **a, t_stack **b);

#endif
