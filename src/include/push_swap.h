/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:18:22 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/27 12:44:27 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../lib/libft/libft.h"

typedef struct s_node
{
	int				data;
	unsigned int	pos;
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
void	parse(int argc, t_string argv[], t_data *stack);

//stack.c
t_node	*create_node(int data, unsigned int pos, t_node *next);
void	push_node(t_stack *stack, t_node *node);
t_node	*pop_node(t_stack *stack);
bool	is_stack_sorted(t_stack *stack);

void	print_stack(t_stack *stack);	//remove

//operations.c
void	cmd_init(t_string cmd, t_data *recv_data);
void	cmd_init2(t_string cmd, t_data *recv_data);
void	exec_cmd(t_string cmd);

#endif
