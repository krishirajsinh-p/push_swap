/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:53:49 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/31 16:57:29 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static unsigned int	count_r(t_node *node, unsigned int t_pos)
{
	unsigned int	counter;

	counter = 0;
	while (node && node->t_pos != t_pos)
	{
		node = node->next;
		counter++;
	}
	return (counter);
}

void	sort3(t_data *stack)
{
	int	f;
	int	s;
	int	t;

	if (is_stack_sorted(&stack->a))
		return ;
	f = stack->a.top->data;
	s = stack->a.top->next->data;
	if (stack->a.size == 3)
		t = stack->a.top->next->next->data;
	if (stack->a.size == 3 && ((s < t && f > t) || (t < f && f < s)))
	{
		if (count_r(stack->a.top, 0) == 1)
			exec_cmd(RA);
		else
			exec_cmd(RRA);
	}
	else
	{
		exec_cmd(SA);
		sort3(stack);
	}
}

void	sort5(t_data *stack)
{
	unsigned int	r;
	unsigned int	rr;
	unsigned int	i;

	i = 0;
	while (stack->a.size != 3)
	{
		r = count_r(stack->a.top, 3 + i);
		rr = stack->a.size - r;
		while (stack->a.top->t_pos != 3 + i)
		{
			if (r > rr)
				exec_cmd(RRA);
			else
				exec_cmd(RA);
		}
		exec_cmd(PB);
		i++;
	}
	sort3(stack);
	while (stack->b.size != 0)
		exec_cmd(PA);
	while (!is_stack_sorted(&stack->a))
		exec_cmd(RA);
}

static void	k_sort_ctd(t_data *stack)
{
	unsigned int	r;
	unsigned int	rr;

	while (stack->b.size != 0)
	{
		while (stack->b.top->t_pos != stack->b.size - 1)
		{
			r = count_r(stack->b.top, stack->b.size - 1);
			rr = stack->b.size - r;
			if (r <= rr)
				exec_cmd(RB);
			else
				exec_cmd(RRB);
		}
		exec_cmd(PA);
	}
}

void	k_sort(t_data *stack)
{
	unsigned int	i;
	int				k_num;

	i = 0;
	k_num = ft_sqrt(stack->a.size) * 1.5;
	while (stack->a.size)
	{
		if (stack->a.top->t_pos <= i + k_num)
		{
			exec_cmd(PB);
			if (stack->b.top->t_pos <= i)
				exec_cmd(RB);
			i++;
		}
		else
			exec_cmd(RA);
	}
	k_sort_ctd(stack);
}
