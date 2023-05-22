/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 01:17:29 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/21 18:22:41 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	throw_error(void)
{
	ft_error(NULL);
}

void	ft_error(t_data *recv_data)
{
	static t_data	*data;

	if (recv_data && data == NULL)
		data = recv_data;
	else
	{
		ft_putendl_fd("ERROR\n", 2);
		//free data here
		data = NULL;
		exit(EXIT_FAILURE);
	}
}
