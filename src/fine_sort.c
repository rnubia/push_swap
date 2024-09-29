/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fine_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 03:58:34 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/03 20:34:39 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

/* check if "shift" is set actual before use */
static t_node	*find_place(t_stack *stack_a, t_node *node)
{
	t_node	*curr;
	size_t	i;

	if (stack_a->head != NULL && stack_a->size > 1)
	{
		curr = stack_a->head;
		i = 0;
		while (i < stack_a->size)
		{
			if (node->index < curr->index
				&& curr->index == stack_a->min)
				return (curr);
			if (node->index < curr->index
				&& node->index > curr->prev->index)
				return (curr);
			if (node->index > curr->prev->index
				&& curr->prev->index == stack_a->max)
				return (curr);
			curr = curr->next;
			i ++;
		}
	}
	return (NULL);
}

static int	ft_iabs(int num)
{
	if (num < 0)
		return (-num);
	return (num);
}

/* check if "shift a" & "shift b" is set actual before use */
static void	set_score(t_stack *stack_a, t_stack *stack_b)
{
	t_node			*place;
	t_node			*curr;
	size_t			i;

	if (stack_b->head != NULL)
	{
		curr = stack_b->head;
		i = 0;
		while (i < stack_b->size)
		{
			place = find_place(stack_a, curr);
			curr->score = ft_iabs(curr->shift) + ft_iabs(place->shift)
				+ stack_b->max - curr->index;
			curr = curr->next;
			i ++;
		}
	}
}

/* check if "score" is set actual before use */
static void	best_node(t_stack *stack_b, t_node **best)
{
	unsigned int	score;
	unsigned int	index;
	t_node			*curr;
	size_t			i;

	if (stack_b->head != NULL)
	{
		curr = stack_b->head;
		score = curr->score;
		index = curr->index;
		*best = curr;
		i = 0;
		while (i < stack_b->size)
		{
			if (curr->score < score
				|| (curr->score == score && curr->index > index))
			{
				score = curr->score;
				index = curr->index;
				*best = curr;
			}
			curr = curr->next;
			i ++;
		}
	}
}

/* warning: it makes "shift" not actual after */
void	fine_sort(t_stack *stack_a, t_stack *stack_b, t_prog *prog)
{
	t_node			*place;
	t_node			*best;

	while (stack_b->size > 0)
	{
		set_shift(stack_a);
		set_shift(stack_b);
		set_score(stack_a, stack_b);
		best_node(stack_b, &best);
		rot_stack_b(stack_b, best, prog);
		place = find_place(stack_a, best);
		rot_stack_a(stack_a, place, prog);
		push_node(stack_a, pop_node(stack_b));
		add_cmd(prog, pa);
	}
	set_shift(stack_a);
	while (stack_a->head->index != stack_a->min)
		stack_a->head = stack_a->head->next;
	rot_stack_a(stack_a, stack_a->head, prog);
}
