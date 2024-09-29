/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 00:37:49 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/01 04:54:26 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# define MSG_ALL_OK	"OK"
# define MSG_NOT_OK	"KO"

t_bool	cmd_sa(t_stack *stack_a, t_stack *stack_b);
t_bool	cmd_sb(t_stack *stack_a, t_stack *stack_b);
t_bool	cmd_ss(t_stack *stack_a, t_stack *stack_b);
t_bool	cmd_pa(t_stack *stack_a, t_stack *stack_b);
t_bool	cmd_pb(t_stack *stack_a, t_stack *stack_b);
t_bool	cmd_ra(t_stack *stack_a, t_stack *stack_b);
t_bool	cmd_rb(t_stack *stack_a, t_stack *stack_b);
t_bool	cmd_rr(t_stack *stack_a, t_stack *stack_b);
t_bool	cmd_rra(t_stack *stack_a, t_stack *stack_b);
t_bool	cmd_rrb(t_stack *stack_a, t_stack *stack_b);
t_bool	cmd_rrr(t_stack *stack_a, t_stack *stack_b);
t_bool	cmd_exec(t_stack *stack_a, t_stack *stack_b, t_op op);
t_bool	check_prog(t_stack *stack_a, t_stack *stack_b);

#endif
