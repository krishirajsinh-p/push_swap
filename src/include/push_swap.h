/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:18:22 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/29 03:55:05 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../lib/libft/libft.h"

# define SA "sa"
# define SB "sb"
# define SS "ss"
# define PA "pa"
# define PB "pb"
# define RA "ra"
# define RB "rb"
# define RR "rr"
# define RRA "rra"
# define RRB "rrb"
# define RRR "rrr"

typedef struct s_node
{
	int				data;
	unsigned int	t_pos;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	unsigned int	size;
	t_node			*top;
}					t_stack;

typedef struct s_data
{
	t_stack			a;
	t_stack			b;
	t_array			array;
}					t_data;

//data_n_error.c
void	init_data(t_data *stack);
void	free_data(t_data *recv_data);
void	throw_error(t_string split[]);

//parser.c
void	parse(int argc, t_string argv[], t_array *array);

//stack.c
t_node	*create_node(int data, unsigned int pos, t_node *next);
void	push_node(t_stack *stack, t_node *node);
t_node	*pop_node(t_stack *stack);
void	fill_stack_a(t_stack *stack, t_array *array);

//operations.c
bool	swap(t_stack *stack);
bool	push(t_stack *from, t_stack *to);
bool	rotate(t_stack *stack);
bool	reverse_rotate(t_stack *stack);

//operations_utils.c
void	swap_init(t_string cmd, t_data *recv_data);
void	push_init(t_string cmd, t_data *recv_data);
void	rotate_init(t_string cmd, t_data *recv_data);
void	reverse_rotate_init(t_string cmd, t_data *recv_data);
void	exec_cmd(t_string cmd);

//sort.c
void	sort(t_data *stack);

#endif
