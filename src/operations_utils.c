/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:06:18 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/28 11:17:33 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	swap_init(t_string cmd, t_data *recv_data)
{
	static t_data	*stack;

	if (!ft_strncmp(cmd, "data", 4) && recv_data != NULL)
		stack = recv_data;
	else
	{
		if (!ft_strncmp(cmd, SA, 2))
		{
			if (swap(&stack->a) == true)
				ft_putstr("sa\n");
		}
		else if (!ft_strncmp(cmd, SB, 2))
		{
			if (swap(&stack->b) == true)
				ft_putstr("sb\n");
		}
		else if (!ft_strncmp(cmd, SS, 2))
		{
			if (swap(&stack->a) || swap(&stack->b))
				ft_putstr("ss\n");
		}
	}
}

void	push_init(t_string cmd, t_data *recv_data)
{
	static t_data	*stack;

	if (!ft_strncmp(cmd, "data", 4) && recv_data != NULL)
		stack = recv_data;
	else
	{
		if (!ft_strncmp(cmd, PA, 2))
		{
			if (push(&stack->b, &stack->a) == true)
				ft_putstr("pa\n");
		}
		else if (!ft_strncmp(cmd, PB, 2))
		{
			if (push(&stack->a, &stack->b) == true)
				ft_putstr("pb\n");
		}
	}
}

void	rotate_init(t_string cmd, t_data *recv_data)
{
	static t_data	*stack;

	if (!ft_strncmp(cmd, "data", 4) && recv_data != NULL)
		stack = recv_data;
	else
	{
		if (!ft_strncmp(cmd, RA, 2))
		{
			if (rotate(&stack->a) == true)
				ft_putstr("ra\n");
		}
		else if (!ft_strncmp(cmd, RB, 2))
		{
			if (rotate(&stack->b) == true)
				ft_putstr("rb\n");
		}
		else if (!ft_strncmp(cmd, RR, 2))
		{
			if (rotate(&stack->a) || rotate(&stack->b))
				ft_putstr("rr\n");
		}
	}
}

void	reverse_rotate_init(t_string cmd, t_data *recv_data)
{
	static t_data	*stack;

	if (!ft_strncmp(cmd, "data", 4) && recv_data != NULL)
		stack = recv_data;
	else
	{
		if (!ft_strncmp(cmd, RRA, 3))
		{
			if (reverse_rotate(&stack->a) == true)
				ft_putstr("rra\n");
		}
		else if (!ft_strncmp(cmd, RRB, 3))
		{
			if (reverse_rotate(&stack->b) == true)
				ft_putstr("rrb\n");
		}
		else if (!ft_strncmp(cmd, RRR, 3))
		{
			if (reverse_rotate(&stack->a) || reverse_rotate(&stack->b))
				ft_putstr("rrr\n");
		}
	}
}

void	exec_cmd(t_string cmd)
{
	if (cmd[0] == 'p')
		push_init(cmd, NULL);
	else if (cmd[0] == 's')
		swap_init(cmd, NULL);
	else if (cmd[0] == 'r' && ft_strlen(cmd) == 2)
		rotate_init(cmd, NULL);
	else if (cmd[0] == 'r' && ft_strlen(cmd) == 3)
		reverse_rotate_init(cmd, NULL);
}
