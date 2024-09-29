/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 03:28:18 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/04 08:25:27 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"

static void	del_next_cmd(t_prog *prog, t_cmd *cmd)
{
	t_cmd	*del;

	del = cmd->next;
	if (del != NULL)
	{
		cmd->next = del->next;
		if (del->next == NULL)
			prog->end = cmd;
		free(del);
		del = NULL;
	}
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

static t_bool	prog_trunc(t_prog *prog)
{
	t_bool	state;
	t_cmd	*ptr;
	t_cmd	*aux;

	state = false;
	ptr = prog->start;
	while (ptr->next != NULL)
	{
		if (ptr->next->op == ss || ptr->next->op == rr || ptr->next->op == rrr)
		{
			aux = ptr->next;
			while (aux->next != NULL && aux->next->op == ptr->next->op)
				aux = aux->next;
			if (aux->next == NULL)
				return (state);
			if (merge_cmd(&(ptr->op), aux->next->op) == true)
			{
				del_next_cmd(prog, aux);
				state = true;
			}
		}
		ptr = ptr->next;
	}
	return (state);
}

/* to be optimized */
void	print_prog(t_prog *prog)
{
	t_cmd		*curr;
	static char	*ops[] = {"sa\n", "sb\n", "ss\n", "pa\n", "pb\n",
		"ra\n", "rb\n", "rr\n", "rra\n", "rrb\n", "rrr\n"};

	if (prog->start != NULL)
	{
		while (prog_trunc(prog) == true)
			;
		curr = prog->start;
		while (curr != NULL)
		{
			ft_putstr_fd(ops[curr->op], STDOUT_FILENO);
			curr = curr->next;
		}
	}
}
