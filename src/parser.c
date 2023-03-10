/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:48:02 by kpuwar            #+#    #+#             */
/*   Updated: 2023/03/08 21:22:17 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static int	*to_int_arr(t_string nums[], unsigned short size)
{
	int				*arr;
	unsigned short	i;

	arr = (int *) ft_calloc((size + 1), sizeof(int));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (ft_stoi(nums[i], &arr[i]) == false)
		{
			free(arr);
			return (NULL);
		}
		i++;
	}
	if (check_dup(arr, size))
		return (NULL);
	return (arr);
}

bool	parse(int argc, t_string argv[])
{
	char			**split;
	int				*arr;
	unsigned short	size;

	if (argc < 2)
		return (NULL);
	else if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		if (split == NULL)
			return (false);
		size = count_nums(split);
		arr = to_int_arr(split, size);
		free_split(split);
	}
	else
	{
		size = argc - 1;
		arr = to_int_arr(&argv[1], size);
	}
	if (arr == NULL)
		return (false);
	//fill arr ints in stack
	free (arr);
	return (true);
}
