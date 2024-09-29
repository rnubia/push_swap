/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnubia <rnubia@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 20:04:31 by rnubia            #+#    #+#             */
/*   Updated: 2022/06/04 08:25:53 by rnubia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RETURN_SUCCESS 0
# define RETURN_FAILURE 1

# define ERROR_MSG	"Error"
# define ERROR_SYS	"System error: "
# define ERROR_MEM	"memory not allocated"

/*  1 <= ALPHA * (ELMIN + 1) < 2 */
/* 0.5 > OMEGA */
/* -1 <= DELTA */
# define ALPHA	0.48
# define OMEGA	0.48
# define EPSLN	2
# define DELTA	9

# define ELMIN	3

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_node	t_node;
struct s_node
{
	int				data;
	unsigned int	index;
	int				shift;
	unsigned int	score;
	t_node			*prev;
	t_node			*next;
};

typedef struct s_stack
{
	t_node			*head;
	unsigned int	size;
	unsigned int	min;
	unsigned int	max;
}	t_stack;

typedef struct s_index	t_index;
struct s_index
{
	t_index	*next;
	t_node	*node;
};

typedef enum e_op
{
	sa,
	sb,
	ss,
	pa,
	pb,
	ra,
	rb,
	rr,
	rra,
	rrb,
	rrr
}	t_op;

typedef struct s_cmd	t_cmd;
struct s_cmd
{
	t_op	op;
	t_cmd	*next;
};

typedef struct s_prog
{
	t_cmd	*start;
	t_cmd	*end;
}	t_prog;

t_node	*new_node(int data);
t_node	*pop_node(t_stack *stack);
void	push_node(t_stack *stack, t_node *node);
void	swap_nodes(t_stack *stack);

t_bool	fill_stack(t_stack *stack, char **args);
t_bool	set_index(t_stack *stack);

void	set_range(t_stack *stack);
void	set_shift(t_stack *stack);
void	rot_stack_a(t_stack *stack_a, t_node *target, t_prog *prog);
void	rot_stack_b(t_stack *stack_b, t_node *target, t_prog *prog);

void	pre_sort(t_stack *stack_a, t_stack *stack_b, t_prog *prog);
void	fine_sort(t_stack *stack_a, t_stack *stack_b, t_prog *prog);
t_bool	stack_sorted(t_stack *stack);

void	add_cmd(t_prog *prog, t_op op);
void	print_prog(t_prog *prog);

void	free_stack(t_stack *stack);
void	free_prog(t_prog *prog);

void	ft_exit(const char	*error);
void	ft_error(const char *error);
void	ft_putstr_fd(const char *str, int fd);
void	ft_putendl_fd(const char *str, int fd);
void	swap_ints(int *num1, int *num2);

char	**ft_split(char const *str, char chr);
void	ft_free_split(char **wrdarr);

#endif
