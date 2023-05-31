/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 01:06:18 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/31 20:46:34 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap_bonus.h"

void	swap_init(t_string cmd, t_data *recv_data)
{
	static t_data	*stack;

	if (!ft_strncmp(cmd, "data", 4) && recv_data != NULL)
		stack = recv_data;
	else
	{
		if (!ft_strncmp(cmd, SA, 3))
			swap(&stack->a);
		else if (!ft_strncmp(cmd, SB, 3))
			swap(&stack->b);
		else if (!ft_strncmp(cmd, SS, 3))
		{
			swap(&stack->a);
			swap(&stack->b);
		}
		else
			throw_error(NULL);
	}
}

void	push_init(t_string cmd, t_data *recv_data)
{
	static t_data	*stack;

	if (!ft_strncmp(cmd, "data", 4) && recv_data != NULL)
		stack = recv_data;
	else
	{
		if (!ft_strncmp(cmd, PA, 3))
			push(&stack->b, &stack->a);
		else if (!ft_strncmp(cmd, PB, 3))
			push(&stack->a, &stack->b);
		else
			throw_error(NULL);
	}
}

void	rotate_init(t_string cmd, t_data *recv_data)
{
	static t_data	*stack;

	if (!ft_strncmp(cmd, "data", 4) && recv_data != NULL)
		stack = recv_data;
	else
	{
		if (!ft_strncmp(cmd, RA, 3))
			rotate(&stack->a);
		else if (!ft_strncmp(cmd, RB, 3))
			rotate(&stack->b);
		else if (!ft_strncmp(cmd, RR, 3))
		{
			rotate(&stack->a);
			rotate(&stack->b);
		}
		else
			throw_error(NULL);
	}
}

void	reverse_rotate_init(t_string cmd, t_data *recv_data)
{
	static t_data	*stack;

	if (!ft_strncmp(cmd, "data", 4) && recv_data != NULL)
		stack = recv_data;
	else
	{
		if (!ft_strncmp(cmd, RRA, 4))
			reverse_rotate(&stack->a);
		else if (!ft_strncmp(cmd, RRB, 4))
			reverse_rotate(&stack->b);
		else if (!ft_strncmp(cmd, RRR, 4))
		{
			reverse_rotate(&stack->a);
			reverse_rotate(&stack->b);
		}
		else
			throw_error(NULL);
	}
}

void	exec_cmd(t_string cmd)
{
	if (cmd[0] == 'p' && ft_strlen(cmd) == 3)
		push_init(cmd, NULL);
	else if (cmd[0] == 's' && ft_strlen(cmd) == 3)
		swap_init(cmd, NULL);
	else if (cmd[0] == 'r' && ft_strlen(cmd) == 3)
		rotate_init(cmd, NULL);
	else if (cmd[0] == 'r' && ft_strlen(cmd) == 4)
		reverse_rotate_init(cmd, NULL);
	else
		throw_error(NULL);
}
