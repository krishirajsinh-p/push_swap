/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:16:21 by kpuwar            #+#    #+#             */
/*   Updated: 2023/03/08 21:23:06 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

unsigned short	count_nums(char **nums)
{
	unsigned short	count;

	count = 0;
	while (nums[count])
		count++;
	return (count);
}

bool	ft_stoi(t_string str, int *num)
{
	unsigned short	i;
	long long		lln;

	i = 0;
	lln = 0;
	*num = 1;
	if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
		return (false);
	if (str[i] == '-')
	{
		*num = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == false)
			return (false);
		lln = (lln * 10) + (str[i++] - '0');
	}
	lln *= *num;
	*num = lln;
	return (lln <= INT32_MAX && lln >= INT32_MIN);
}

bool	check_dup(int *arr, int size)
{
	unsigned short	i;
	unsigned short	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				free(arr);
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

void	free_split(t_string nums[])
{
	unsigned short	i;

	i = 0;
	while (nums[i])
		free(nums[i++]);
	free(nums);
}
