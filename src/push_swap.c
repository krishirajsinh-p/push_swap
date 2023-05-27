/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:33:15 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/27 10:28:46 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, t_string argv[])
{
	t_data	stack;

	init_data(&stack);
	parse(argc, argv, &stack);
	// sort
	// free_data(&stack);
	exit (EXIT_SUCCESS);
}
