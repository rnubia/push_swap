/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:34:14 by rnubia            #+#    #+#             */
/*   Updated: 2022/05/29 05:12:53 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static void	free_index(t_index **begin)
{
	t_index	*curr;

	while (*begin != NULL)
	{
		curr = *begin;
		*begin = curr->next;
		free(curr);
	}
}

static t_index	*new_inode(t_node	*node)
{
	t_index	*new;

	new = (t_index *)malloc(sizeof(*new));
	if (new == NULL)
		ft_exit(ERROR_MEM);
	new->next = NULL;
	new->node = node;
	return (new);
}

static t_bool	case_after(t_index *begin, t_index *inode)
{
	int	data;

	data = inode->node->data;
	while (begin != NULL)
	{
		if (data > begin->node->data && begin->next == NULL)
		{
			begin->next = inode;
			return (true);
		}
		else if (data > begin->node->data && data < begin->next->node->data)
		{
			inode->next = begin->next;
			begin->next = inode;
			return (true);
		}
		else if (data == begin->node->data)
			return (false);
		else
			begin = begin->next;
	}
	return (false);
}

static t_bool	add_inode(t_index **begin, t_index	**inode)
{
	int	data;

	data = (*inode)->node->data;
	if (*begin == NULL)
		*begin = *inode;
	else if (data < (*begin)->node->data)
	{
		(*inode)->next = *begin;
		*begin = *inode;
	}
	else if (case_after(*begin, *inode) == true)
		;
	else
	{
		free_index(begin);
		free(*inode);
		*inode = NULL;
		return (false);
	}
	return (true);
}

t_bool	set_index(t_stack *stack)
{
	t_index	*index;
	t_index	*inode;
	t_node	*curr;
	size_t	i;

	index = NULL;
	curr = stack->head;
	i = 0;
	while (i < stack->size)
	{
		inode = new_inode(curr);
		if (add_inode(&index, &inode) == false)
			return (false);
		curr = curr->next;
		i ++;
	}
	i = 1;
	inode = index;
	while (inode != NULL)
	{
		inode->node->index = i ++;
		inode = inode->next;
	}
	free_index(&index);
	return (true);
}
