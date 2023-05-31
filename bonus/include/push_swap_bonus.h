/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:18:22 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/31 20:49:19 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../../lib/libft/libft.h"

# define SA "sa\n"
# define SB "sb\n"
# define SS "ss\n"
# define PA "pa\n"
# define PB "pb\n"
# define RA "ra\n"
# define RB "rb\n"
# define RR "rr\n"
# define RRA "rra\n"
# define RRB "rrb\n"
# define RRR "rrr\n"

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
	t_string		cmd;
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
bool	is_stack_sorted(t_stack *stack);

//operations.c
void	swap(t_stack *stack);
void	push(t_stack *from, t_stack *to);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

//operations_utils.c
void	swap_init(t_string cmd, t_data *recv_data);
void	push_init(t_string cmd, t_data *recv_data);
void	rotate_init(t_string cmd, t_data *recv_data);
void	reverse_rotate_init(t_string cmd, t_data *recv_data);
void	exec_cmd(t_string cmd);

#endif
