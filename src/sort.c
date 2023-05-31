/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 04:53:49 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/31 13:31:26 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	ft_sqrt(int number)	//add to libft
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

static void	sort3(t_data *stack)
{
	int	f;
	int	s;
	int	t;

	if (is_stack_sorted(&stack->a))
		return ;
	f = stack->a.top->data;
	s = stack->a.top->next->data;
	t = stack->a.top->next->next->data;
	if ((s < t && f > t) || (t < f && f < s))
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

static void	sort5(t_data *stack)
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
	while (stack->b.size != 0)
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

static void	k_sort(t_data *stack)
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
	k_sort_ctd(stack);
}

void	sort(t_data *stack)
{
	if (stack->a.size == 2)
		exec_cmd(SA);
	else if (stack->a.size == 3)
		sort3(stack);
	else if (stack->a.size <= 5)
		sort5(stack);
	else
		k_sort(stack);
}
