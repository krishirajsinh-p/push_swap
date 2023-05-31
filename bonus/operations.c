/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:51:02 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/31 21:17:17 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap_bonus.h"

void	swap(t_stack *stack)
{
	t_node	*tmp;

	if (stack->size < 2)
		throw_error(NULL);
	tmp = stack->top->next;
	stack->top->next = tmp->next;
	tmp->next = stack->top;
	stack->top = tmp;
}

void	push(t_stack *from, t_stack *to)
{
	if (from->size < 1)
		throw_error(NULL);
	push_node(to, pop_node(from));
}

void	rotate(t_stack *stack)
{
	t_node	*itr;

	if (stack->size < 2)
		throw_error(NULL);
	itr = stack->top;
	while (itr->next != NULL)
		itr = itr->next;
	itr->next = stack->top;
	stack->top = stack->top->next;
	itr->next->next = NULL;
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*itr;
	t_node	*tmp;

	if (stack->size < 2)
		throw_error(NULL);
	itr = stack->top;
	while (itr->next->next != NULL)
		itr = itr->next;
	tmp = itr->next;
	itr->next = NULL;
	tmp->next = stack->top;
	stack->top = tmp;
}
