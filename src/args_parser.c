/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 16:14:55 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/01 01:34:38 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "push_swap.h"

void	swap_ints(int *num1, int *num2)
{
	int	tmp;

	tmp = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

static t_bool	ft_stoi(char *str, int *inbr)
{
	long long int	llnbr;
	int				sgn;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str ++;
	sgn = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sgn = -1;
		str ++;
	}
	if (*str == '\0')
		return (false);
	llnbr = 0;
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (false);
		llnbr = llnbr * 10 + ((long long int)(*(str ++) - '0')) * sgn;
		if (llnbr < INT_MIN || llnbr > INT_MAX)
			return (false);
	}
	*inbr = (int)llnbr;
	return (true);
}

static void	put_back(t_stack *stack, int data)
{
	t_node	*tail;
	t_node	*node;

	node = new_node(data);
	if (stack->head == NULL)
	{
		stack->head = node;
		node->next = node;
		node->prev = node;
		stack->min = 1;
	}
	else
	{
		tail = stack->head->prev;
		tail->next = node;
		node->prev = tail;
		node->next = stack->head;
		stack->head->prev = node;
	}
	stack->size ++;
	stack->max = stack->size;
}

static t_bool	fk_the_norm(char **split)
{
	ft_free_split(split);
	return (false);
}

t_bool	fill_stack(t_stack *stack, char **args)
{
	char	**split;
	char	**ptr;
	int		data;

	while (*args != NULL)
	{
		split = ft_split(*args, ' ');
		if (*split == NULL)
			return (fk_the_norm(split));
		ptr = split;
		while (*ptr != NULL)
		{
			if (ft_stoi(*ptr, &data) == false)
				return (fk_the_norm(split));
			put_back(stack, data);
			ptr ++;
		}
		ft_free_split(split);
		args ++;
	}
	return (true);
}
