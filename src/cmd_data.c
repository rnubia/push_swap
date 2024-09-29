/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:40:45 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/03 05:39:27 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

void	free_prog(t_prog *prog)
{
	t_cmd	*curr;

	while (prog->start != NULL)
	{
		curr = prog->start;
		prog->start = curr->next;
		free(curr);
	}
	prog->end = NULL;
}

static t_cmd	*new_cmd(t_op op)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(*new));
	if (new == NULL)
		ft_exit(ERROR_MEM);
	new->op = op;
	new->next = NULL;
	return (new);
}

static t_bool	merge_cmd(t_op *op1, t_op op2)
{
	if ((*op1 == sa && op2 == sb) || (*op1 == sb && op2 == sa)
		|| (*op1 == ra && op2 == rb) || (*op1 == rb && op2 == ra)
		|| (*op1 == rra && op2 == rrb) || (*op1 == rrb && op2 == rra))
	{
		if (*op1 == sa || *op1 == sb)
			*op1 = ss;
		if (*op1 == ra || *op1 == rb)
			*op1 = rr;
		if (*op1 == rra || *op1 == rrb)
			*op1 = rrr;
		return (true);
	}
	return (false);
}

void	add_cmd(t_prog *prog, t_op op)
{
	t_cmd	*cmd;

	if (prog->start == NULL)
	{
		cmd = new_cmd(op);
		prog->start = cmd;
		prog->end = prog->start;
	}
	else if (merge_cmd(&(prog->end->op), op) == true)
		;
	else
	{
		cmd = new_cmd(op);
		prog->end->next = cmd;
		prog->end = cmd;
	}
}
