/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_n_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:17:29 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/27 10:41:07 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	free_data(t_data *recv_data)
{
	static t_data	*stack;

	if (recv_data && stack == NULL)
		stack = recv_data;
	else
	{
		stack->array.size = 0;
		if (stack->array.element)
			free(stack->array.element);
		stack->array.element = NULL;
		while (stack->a.top)
			free(pop_node(&stack->a));
		while (stack->b.top)
			free(pop_node(&stack->b));
		stack = NULL;
	}
}

void	throw_error(t_string split[])
{
	if (split != NULL)
		ft_free_split(split);
	free_data(NULL);
	ft_putendl_fd("ERROR", 2);
	exit(EXIT_FAILURE);
}

void	init_data(t_data *stack)
{
	stack->array.size = 0;
	stack->array.element = NULL;
	stack->a.size = 0;
	stack->a.top = NULL;
	stack->b.size = 0;
	stack->b.top = NULL;
	free_data(stack);
	cmd_init("data", stack);
	cmd_init2("data", stack);
}
