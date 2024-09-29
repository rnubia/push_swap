/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_revrot_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 01:52:58 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/01 00:24:29 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_bool	cmd_ra(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2)
		return (false);
	if (stack_b != NULL)
		stack_a->head = stack_a->head->next;
	return (true);
}

t_bool	cmd_rb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size < 2)
		return (false);
	if (stack_a != NULL)
		stack_b->head = stack_b->head->next;
	return (true);
}

t_bool	cmd_rra(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2)
		return (false);
	if (stack_b != NULL)
		stack_a->head = stack_a->head->prev;
	return (true);
}

t_bool	cmd_rrb(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size < 2)
		return (false);
	if (stack_a != NULL)
		stack_b->head = stack_b->head->prev;
	return (true);
}
