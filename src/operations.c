/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:51:02 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/27 12:16:39 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	swap(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	tmp = stack->top->next;
	stack->top->next = tmp->next;
	tmp->next = stack->top;
	stack->top = tmp;
}

static void	push(t_stack *from, t_stack *to)
{
	if (from->size < 1)
		return ;
	push_node(to, pop_node(from));
}

static void	rotate(t_stack *stack)
{
	t_node	*itr;

	if (stack->size < 2)
		return ;
	itr = stack->top;
	while (itr->next != NULL)
		itr = itr->next;
	itr->next = stack->top;
	stack->top = stack->top->next;
	itr->next->next = NULL;
}

static void	reverse_rotate(t_stack *stack)
{
	t_node	*itr;
	t_node	*tmp;

	if (stack->size < 2)
		return ;
	itr = stack->top;
	while (itr->next->next != NULL)
		itr = itr->next;
	tmp = itr->next;
	itr->next = NULL;
	tmp->next = stack->top;
	stack->top = tmp;
}

void	exec_cmd(t_string cmd)
{
	if (cmd[0] == 'r')
		cmd_init2(cmd, NULL);
	else
		cmd_init(cmd, NULL);
}

void	cmd_init(t_string cmd, t_data *recv_data)
{
	static t_data	*stack;

	if (!ft_strncmp(cmd, "data", 4) && recv_data != NULL)
		stack = recv_data;
	else
	{
		if (!ft_strncmp(cmd, "sa", 2))
			swap(&stack->a);
		else if (!ft_strncmp(cmd, "sb", 2))
			swap(&stack->b);
		else if (!ft_strncmp(cmd, "ss", 2))
		{
			swap(&stack->a);
			swap(&stack->b);
		}
		else if (!ft_strncmp(cmd, "pa", 2))
			push(&stack->b, &stack->a);
		else if (!ft_strncmp(cmd, "pb", 2))
			push(&stack->a, &stack->b);
	}
}

void	cmd_init2(t_string cmd, t_data *recv_data)
{
	static t_data	*stack;

	if (!ft_strncmp(cmd, "data", 4) && recv_data != NULL)
		stack = recv_data;
	else
	{
		if (!ft_strncmp(cmd, "ra", 2))
			rotate(&stack->a);
		else if (!ft_strncmp(cmd, "rb", 2))
			rotate(&stack->b);
		else if (!ft_strncmp(cmd, "rra", 3))
			reverse_rotate(&stack->a);
		else if (!ft_strncmp(cmd, "rrb", 3))
			reverse_rotate(&stack->b);
		else if (!ft_strncmp(cmd, "rrr", 3))
		{
			reverse_rotate(&stack->a);
			reverse_rotate(&stack->b);
		}
		else if (!ft_strncmp(cmd, "rr", 2))
		{
			rotate(&stack->a);
			rotate(&stack->b);
		}
	}
}
