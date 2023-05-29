/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:33:15 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/29 04:05:16 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, t_string argv[])
{
	t_data	stack;

	init_data(&stack);
	parse(argc, argv, &stack.array);
	if (ft_is_array_sorted(&stack.array) == true)
	{
		free_data(NULL);
		exit(EXIT_SUCCESS);
	}
	fill_stack_a(&stack.a, &stack.array);
	sort(&stack);
	free_data(NULL);
	exit(EXIT_SUCCESS);
}
