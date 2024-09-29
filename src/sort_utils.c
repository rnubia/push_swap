/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 06:55:46 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/01 01:47:56 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"

t_bool	stack_sorted(t_stack *stack)
{
	t_node	*curr;
	size_t	i;

	if (stack->head != NULL)
	{
		curr = stack->head;
		i = 1;
		while (i < stack->size)
		{
			if (curr->index > curr->next->index)
				return (false);
			curr = curr->next;
			i ++;
		}
		return (true);
	}
	return (false);
}

void	set_range(t_stack *stack)
{
	t_node	*curr;
	size_t	i;

	stack->min = UINT_MAX;
	stack->max = 0;
	if (stack->head != NULL)
	{
		curr = stack->head;
		i = 0;
		while (i < stack->size)
		{
			if (curr->index < stack->min)
				stack->min = curr->index;
			if (curr->index > stack->max)
				stack->max = curr->index;
			curr = curr->next;
			i ++;
		}
	}
}

void	set_shift(t_stack *stack)
{
	t_node	*curr;
	size_t	mid;
	size_t	i;

	if (stack->head != NULL)
	{
		curr = stack->head;
		mid = stack->size / 2 + 1;
		i = 0;
		while (i < mid)
		{
			curr->shift = i ++;
			curr = curr->next;
		}
		mid = stack->size - mid;
		curr = stack->head->prev;
		i = 0;
		while (i < mid)
		{
			curr->shift = -(1 + i ++);
			curr = curr->prev;
		}
	}
}

/* check if "shift" is set actual before use */
/* warning: it makes "shift" not actual after */
void	rot_stack_a(t_stack *stack_a, t_node *target, t_prog *prog)
{
	int		rot;

	if (stack_a->head != NULL)
	{
		stack_a->head = target;
		rot = stack_a->head->shift;
		if (rot >= 0)
		{
			while (rot != 0)
			{
				add_cmd(prog, ra);
				rot --;
			}
		}
		else
		{
			while (rot != 0)
			{
				add_cmd(prog, rra);
				rot ++;
			}
		}
	}
}

/* check if "shift" is set actual before use */
/* warning: it makes "shift" not actual after */
void	rot_stack_b(t_stack *stack_b, t_node *target, t_prog *prog)
{
	int		rot;

	if (stack_b->head != NULL)
	{
		stack_b->head = target;
		rot = stack_b->head->shift;
		if (rot >= 0)
		{
			while (rot != 0)
			{
				add_cmd(prog, rb);
				rot --;
			}
		}
		else
		{
			while (rot != 0)
			{
				add_cmd(prog, rrb);
				rot ++;
			}
		}
	}
}
