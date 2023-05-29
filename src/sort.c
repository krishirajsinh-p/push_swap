/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:53:49 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/29 04:01:18 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	ft_sqrt(int number)
{
	int	i;

	if (number < 4)
		return (1);
	i = 2;
	while (i * i < number)
		i++;
	if (i * i > number)
	{
		if ((i * i - number) < ((i - 1) * (i - 1) + (-number)))
			return (i);
	}
	return (i - 1);
}

static unsigned int	count_r(t_node *node, unsigned int position)
{
	unsigned int	counter;

	counter = 0;
	while (node && node->t_pos != position)
	{
		node = node->next;
		counter++;
	}
	return (counter);
}

static void	k_sort2(t_data *stack)
{
	while (stack->b.size)
	{
		while (stack->b.top->t_pos != stack->b.size - 1)
		{
			if (2 * count_r(stack->b.top, stack->b.size - 1)\
			 <= stack->b.size + 3)
				exec_cmd(RB);
			else
				exec_cmd(RRB);
		}
		exec_cmd(PA);
	}
}

static void	k_sort1(t_data *stack)
{
	unsigned int	i;
	int				k_num;

	i = 0;
	k_num = ft_sqrt(stack->a.size) * 1.5;
	while (stack->a.top)
	{
		if (stack->a.top->t_pos <= i)
		{
			exec_cmd(PB);
			exec_cmd(RB);
			i++;
		}
		else if (stack->a.top->t_pos <= i + k_num)
		{
			exec_cmd(PB);
			i++;
		}
		else
			exec_cmd(RA);
	}
	k_sort2(stack);
}

void	sort(t_data *stack)	//add for 3 & 5
{
	if (stack->a.size == 2)
		exec_cmd(SA);
	else
		k_sort1(stack);
}
