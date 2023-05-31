/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 22:04:38 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/31 11:49:25 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

t_node	*create_node(int data, unsigned int t_pos, t_node *next)
{
	t_node	*node;

	node = (t_node *) ft_calloc(1, sizeof(t_node));
	if (node == NULL)
		throw_error(NULL);
	node->data = data;
	node->t_pos = t_pos;
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

void	fill_stack_a(t_stack *stack, t_array *array)
{
	int		i;
	t_node	*itr;

	i = array->size - 1;
	while (i >= 0)
		push_node(stack, create_node(array->element[i--], -1, NULL));
	ft_bubble_sort(array);
	itr = stack->top;
	while (itr)
	{
		itr->t_pos = ft_get_index(array, itr->data);
		itr = itr->next;
	}
	free(array->element);
	array->element = NULL;
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
