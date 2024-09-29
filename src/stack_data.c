/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 20:39:53 by rnubia            #+#    #+#             */
/*   Updated: 2022/05/31 21:52:03 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_node	*node;

	while (stack->size != 0)
	{
		node = stack->head;
		stack->head = node->next;
		free(node);
		stack->size --;
	}
	stack->head = NULL;
	stack->min = 0;
	stack->max = 0;
	stack->size = 0;
}

t_node	*new_node(int data)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(*node));
	if (node == NULL)
		ft_exit(ERROR_MEM);
	node->data = data;
	node->index = 0;
	node->shift = 0;
	node->score = 0;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/* warning: it makes "shift" not actual after */
void	push_node(t_stack *stack, t_node *node)
{
	t_node	*tail;

	if (stack->head == NULL)
	{
		stack->head = node;
		node->next = node;
		node->prev = node;
		stack->min = node->index;
	}
	else
	{
		tail = stack->head->prev;
		tail->next = node;
		node->prev = tail;
		node->next = stack->head;
		stack->head->prev = node;
		stack->head = node;
		if (node->index < stack->min)
			stack->min = node->index;
	}
	stack->size ++;
	if (node->index > stack->max)
		stack->max = node->index;
}

/* warning: it makes "shift" not actual after */
t_node	*pop_node(t_stack *stack)
{
	t_node	*node;

	if (stack->head == NULL)
		return (NULL);
	node = stack->head;
	if (stack->head->next == stack->head)
	{
			stack->head = NULL;
			stack->size = 0;
			stack->min = 0;
			stack->max = 0;
	}
	else
	{
		stack->head = stack->head->next;
		node->prev->next = node->next;
		node->next->prev = node->prev;
		stack->size --;
		if (node->index == stack->min || node->index == stack->max)
			set_range(stack);
	}
	return (node);
}

void	swap_nodes(t_stack *stack)
{
	t_node	*node1;
	t_node	*node2;
	t_node	*next;
	t_node	*prev;

	if (stack->head != NULL && stack->size > 1)
	{
		node1 = stack->head;
		node2 = node1->next;
		if (stack->size == 2)
			stack->head = node2;
		else
		{
			prev = node1->prev;
			next = node2->next;
			prev->next = node2;
			node2->prev = prev;
			node1->next = next;
			next->prev = node1;
			node2->next = node1;
			node1->prev = node2;
			stack->head = node2;
		}
		swap_ints(&node1->shift, &node2->shift);
	}
}
