/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_prog_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:18:22 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/04 08:49:58 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "get_next_line.h"
#include "checker_bonus.h"

static size_t	ft_strlen(const char *str)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr != '\0')
		ptr ++;
	return (ptr - str);
}

static int	ft_strncmp(const char *str1, const char *str2, size_t cmplen)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)str1;
	ptr2 = (unsigned char *)str2;
	while (cmplen > 0)
	{
		if (*ptr1 != *ptr2 || *ptr1 == '\0')
			return ((int)(*ptr1 - *ptr2));
		cmplen --;
		ptr1 ++;
		ptr2 ++;
	}
	return (0);
}

static t_bool	cmd_read(char *str, t_op *op)
{
	size_t		len;
	t_op		iop;
	static char	*ops[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb", "rr",
		"rra", "rrb", "rrr"};

	len = ft_strlen(str);
	len --;
	if (*(str + len) == '\n')
	{
		iop = sa;
		while (iop <= rrr)
		{
			if (ft_strncmp(ops[iop], str, len) == 0)
			{
				*op = iop;
				return (true);
			}
			iop ++;
		}
	}
	return (false);
}

t_bool	check_prog(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;
	t_op	op;

	line = get_next_line(STDIN_FILENO);
	while (line != NULL)
	{
		if (cmd_read(line, &op) == false)
		{
			free(line);
			return (false);
		}
		if (*line != '\n')
			cmd_exec(stack_a, stack_b, op);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	return (true);
}
