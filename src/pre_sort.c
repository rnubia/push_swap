/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 05:36:29 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/04 07:02:08 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

/* check if "shift" is set actual before use */
static t_node	*seek_forward(t_stack *stack, unsigned int limit)
{
	t_node	*curr;

	if (stack->head != NULL)
	{
		curr = stack->head;
		if (curr->index < limit)
			return (curr);
		curr = curr->next;
		while (curr->shift > 0)
		{
			if (curr->index < limit)
				return (curr);
			curr = curr->next;
		}
	}
	return (NULL);
}

/* check if "shift" is set actual before use */
static t_node	*seek_reverse(t_stack *stack, unsigned int limit)
{
	t_node	*curr;

	if (stack->head != NULL)
	{
		curr = stack->head;
		if (curr == curr->prev)
			return (NULL);
		curr = curr->prev;
		while (curr->shift < 0)
		{
			if (curr->index < limit)
				return (curr);
			curr = curr->prev;
		}
	}
	return (NULL);
}

/* check if "shift" is set actual before use */
static t_node	*optimal_node(t_stack *stack_a)
{
	unsigned int	limit;
	t_node			*front;
	t_node			*back;

	limit = (stack_a->max - stack_a->min) * ALPHA + stack_a->min;
	if (stack_a->size > ELMIN + 1)
		limit ++;
	front = seek_forward(stack_a, limit);
	back = seek_reverse(stack_a, limit);
	if (front == NULL && back == NULL)
		return (NULL);
	if (front != NULL && back == NULL)
		return (front);
	if (front == NULL && back != NULL)
		return (back);
	if (front->shift < -(back->shift) + DELTA)
		return (front);
	else
		return (back);
	return (NULL);
}

static void	three_sort(t_stack *stack_a, t_prog *prog)
{
	t_node	*curr;

	curr = stack_a->head;
	if (stack_a->size == 2)
	{
		if (curr->index > curr->next->index)
		{
			swap_ints(&curr->shift, &curr->next->shift);
			stack_a->head = curr->next;
			add_cmd(prog, sa);
		}
	}
	if (stack_a->size == 3)
	{
		if ((curr->index == stack_a->min
				&& curr->next->index == stack_a->max)
			|| (curr->index == stack_a->max
				&& curr->prev->index == stack_a->min)
			|| (curr->next->index == stack_a->min
				&& curr->prev->index == stack_a->max))
		{
			swap_nodes(stack_a);
			add_cmd(prog, sa);
		}
	}
}

/* warning: it makes "shift" not actual after */
void	pre_sort(t_stack *stack_a, t_stack *stack_b, t_prog *prog)
{
	unsigned int	median;
	t_node			*optima;

	while (stack_a->size > ELMIN)
	{
		set_shift(stack_a);
		optima = optimal_node(stack_a);
		rot_stack_a(stack_a, optima, prog);
		push_node(stack_b, pop_node(stack_a));
		add_cmd(prog, pb);
		median = (stack_b->max - stack_b->min) * OMEGA + stack_b->min;
		if (median < stack_a->min)
			median = (stack_a->max - stack_a->min) * ALPHA * OMEGA
				+ stack_a->min - EPSLN;
		if (stack_b->head->index < median && stack_b->size > 1)
		{
			stack_b->head = stack_b->head->next;
			add_cmd(prog, rb);
		}
	}
	three_sort(stack_a, prog);
	set_shift(stack_a);
	while (stack_a->head->index != stack_a->min)
		stack_a->head = stack_a->head->next;
	rot_stack_a(stack_a, stack_a->head, prog);
}
