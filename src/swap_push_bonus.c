/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:27:14 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/01 00:24:25 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_bool	cmd_sa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2)
		return (false);
	if (stack_b != NULL)
		swap_nodes(stack_a);
	return (true);
}

t_bool	cmd_sb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size < 2)
		return (false);
	if (stack_a != NULL)
		swap_nodes(stack_b);
	return (true);
}

t_bool	cmd_pa(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size < 1)
		return (false);
	push_node(stack_a, pop_node(stack_b));
	return (true);
}

t_bool	cmd_pb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 1)
		return (false);
	push_node(stack_b, pop_node(stack_a));
	return (true);
}
