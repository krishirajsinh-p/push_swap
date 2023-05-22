/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:04:38 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/21 21:08:09 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_node	*create_node(int data, int ideal_index, t_node *next)
{
	t_node	*node;

	node = (t_node *) ft_calloc(1, sizeof(t_node));
	if (node)
		throw_error();
	node->data = data;
	node->ideal_index = ideal_index;
	node->next = next;
	return (node);
}

void	push_node(t_stack *stack, t_node	*node)
{
	if (stack->top == NULL)
		stack->top = node;
	else
	{
		node->next = stack->top;
		stack->top = node;
	}
	stack->size++;
}

t_node	*pop_node(t_stack *stack)
{
	t_node	*node;

	if (stack)
	{
		node = stack->top;
		stack->top = stack->top->next;
		stack->size--;
		return (node);
	}
	else
		return (NULL);
}
