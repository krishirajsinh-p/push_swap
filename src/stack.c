/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:04:38 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/27 12:40:37 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_node	*create_node(int data, unsigned int pos, t_node *next)
{
	t_node	*node;

	node = (t_node *) ft_calloc(1, sizeof(t_node));
	if (node == NULL)
		throw_error(NULL);
	node->data = data;
	node->pos = pos;
	node->next = next;
	return (node);
}

void	push_node(t_stack *stack, t_node *node)
{
	node->next = stack->top;
	stack->top = node;
	stack->size++;
}

t_node	*pop_node(t_stack *stack)
{
	t_node	*node;

	if (stack->top != NULL)
	{
		node = stack->top;
		stack->top = stack->top->next;
		stack->size--;
		return (node);
	}
	else
		return (NULL);
}

bool	is_stack_sorted(t_stack *stack)
{
	t_node	*node;

	if (stack->size < 2)
		return (true);
	node = stack->top;
	while (node->next)
	{
		if (node->data > node->next->data)
			return (false);
		node = node->next;
	}
	return (true);
}

void	print_stack(t_stack *stack)	//remove
{
	t_node	*node;

	ft_printf("size: %d\n", stack->size);
	if (stack->size == 0)
	{
		ft_putstr("-> []\n");
		return ;
	}
	node = stack->top;
	while (node)
	{
		ft_printf("-> [%d]", node->data);
		node = node->next;
	}
	ft_putchar('\n');
}
