/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 09:58:37 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/25 11:23:18 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	wft_print_array(t_array *array)
{
	unsigned int	i;

	ft_printf("[%i", array->element[0]);
	i = 1;
	while (i < array->size)
		ft_printf(",%i", array->element[i++]);
	ft_printf("]\n");
}
