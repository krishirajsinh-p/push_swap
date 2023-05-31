/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:33:15 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/31 21:19:37 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap_bonus.h"

static void	apply_instructions(t_data *stack)
{
	while (true)
	{
		stack->cmd = get_next_line(0);
		if (stack->cmd == NULL)
			throw_error(NULL);
		if (stack->cmd[0] == '\n')
		{
			free(stack->cmd);
			stack->cmd = NULL;
			return ;
		}
		else
			exec_cmd(stack->cmd);
		free(stack->cmd);
		stack->cmd = NULL;
		stack->cmd = NULL;
	}
}

int	main(int argc, t_string argv[])
{
	t_data	stack;

	init_data(&stack);
	parse(argc, argv, &stack.array);
	fill_stack_a(&stack.a, &stack.array);
	apply_instructions(&stack);
	if (is_stack_sorted(&stack.a))
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_data(NULL);
	exit(EXIT_SUCCESS);
}
