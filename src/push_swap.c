/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:26:05 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/01 05:36:14 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
	stack->min = 0;
	stack->max = 0;
}

static void	init_prog(t_prog *prog)
{
	prog->start = NULL;
	prog->end = NULL;
}

static void	sort_stack(t_stack *stack_a, t_stack *stack_b, t_prog *prog)
{
	pre_sort(stack_a, stack_b, prog);
	fine_sort(stack_a, stack_b, prog);
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;
	t_prog	sort;

	init_stack(&stack_a);
	init_stack(&stack_b);
	init_prog(&sort);
	if (argc > 1)
	{
		if (fill_stack(&stack_a, argv + 1) == false
			|| set_index(&stack_a) == false)
		{
			free_stack(&stack_a);
			ft_error(ERROR_MSG);
			return (RETURN_FAILURE);
		}
		if (stack_sorted(&stack_a) == false)
			sort_stack(&stack_a, &stack_b, &sort);
		print_prog(&sort);
		free_stack(&stack_a);
		free_stack(&stack_b);
		free_prog(&sort);
	}
	return (RETURN_SUCCESS);
}
