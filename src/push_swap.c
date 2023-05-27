/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:33:15 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/27 12:44:47 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, t_string argv[])
{
	t_data	stack;

	init_data(&stack);
	parse(argc, argv, &stack);
	//make is_array_sorted, add to libft, check if arr sorted before adding to stack
	//enums in c for ops
	// sort
	// free_data(&stack);
	exit (EXIT_SUCCESS);
}
