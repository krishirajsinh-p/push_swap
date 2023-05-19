/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:33:15 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/19 22:09:24 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

int	main(int argc, t_string argv[])
{
	//declare stacks
	if (parse(argc, argv) == false)
		ft_error(ERROR_MSG);
	//algorithm
	//free stacks
	//free array
	system("leaks push_swap");
	return (EXIT_SUCCESS);
}

/*
stack
-a elements from argument, first argument at top
-b empty

parsing
-no parameters then exit without any output
-no duplicates
-check if all are number
-check if all are int within int range

output
-operations with '\n'
-cases of error output "Error\n" on stderr
*/