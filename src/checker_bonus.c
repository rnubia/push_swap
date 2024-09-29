/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:15:09 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/04 08:34:46 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "push_swap.h"
#include "checker_bonus.h"

static void	ft_message(const char *message)
{
	ft_putendl_fd(message, STDOUT_FILENO);
}

static void	init_stack(t_stack *stack)
{
	stack->head = NULL;
	stack->size = 0;
	stack->min = 0;
	stack->max = 0;
}

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	init_stack(&stack_a);
	init_stack(&stack_b);
	if (argc > 1)
	{
		if (fill_stack(&stack_a, argv + 1) == false
			|| set_index(&stack_a) == false)
			ft_error(ERROR_MSG);
		else if (check_prog(&stack_a, &stack_b) == false)
			ft_error(ERROR_MSG);
		else if (stack_sorted(&stack_a) == true && stack_b.size == 0)
			ft_message(MSG_ALL_OK);
		else
			ft_message(MSG_NOT_OK);
		free_stack(&stack_a);
		free_stack(&stack_b);
	}
	return (RETURN_SUCCESS);
}
