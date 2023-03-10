/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:33:15 by kpuwar            #+#    #+#             */
/*   Updated: 2023/03/08 01:54:33 by kpuwar           ###   ########.fr       */
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

//if leaks make all typedef and struct null