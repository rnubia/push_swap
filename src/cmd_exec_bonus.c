/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_exec_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 02:02:10 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/01 05:20:41 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "checker_bonus.h"

t_bool	cmd_ss(t_stack *stack_a, t_stack *stack_b)
{
	return (cmd_sa(stack_a, stack_b) && cmd_sb(stack_a, stack_b));
}

t_bool	cmd_rr(t_stack *stack_a, t_stack *stack_b)
{
	return (cmd_ra(stack_a, stack_b) && cmd_rb(stack_a, stack_b));
}

t_bool	cmd_rrr(t_stack *stack_a, t_stack *stack_b)
{
	return (cmd_rra(stack_a, stack_b) && cmd_rrb(stack_a, stack_b));
}

t_bool	cmd_exec(t_stack *stack_a, t_stack *stack_b, t_op op)
{
	static t_bool	(*cmds[])(t_stack *a, t_stack *b) = {cmd_sa, cmd_sb, cmd_ss,
		cmd_pa, cmd_pb, cmd_ra, cmd_rb, cmd_rr, cmd_rra, cmd_rrb, cmd_rrr};

	return (cmds[op](stack_a, stack_b));
}
