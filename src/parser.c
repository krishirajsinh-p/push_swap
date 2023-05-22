/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:48:02 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/21 21:55:02 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

static void	free_split(t_string split[])
{
	unsigned int	i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static bool	ft_stoi(t_string str, int *num)
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

static void	make_array(int argc, t_string argv[], t_array *array)
{
	t_string		*split;
	unsigned short	i;
	unsigned short	j;
	unsigned short	k;
	
	array->array = ft_calloc(array->size + 1, sizeof(int));
	if (array->array == NULL)
		throw_error();	//exit with err_msg
	k = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL)
		{
			free(array->array);
			throw_error();	//if split is null then free array mem and exit with msg
		}
		j = 0;
		while (split[j])
		{
			if (ft_stoi(split[j++], &array->array[k++]) == false)
			{
				free(array->array);
				free_split(split);
				throw_error();
			}
			free_split(split);	
		}
		i++;
	}
}

static bool	check_dup(t_array *array)
{
	unsigned short	i;
	unsigned short	j;

	i = 0;
	while (i < array->size)
	{
		j = i + 1;
		while (j < array->size)
		{
			if (array->array[i] == array->array[j])
			{
				free(array->array);
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

static void	sort_array(t_array *array)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < array->size - 1)
	{
		j = 0;
		while (j < array->size - i - 1)
		{
			if (array->array[j] > array->array[j + 1])
			{
				temp = array->array[j];
				array->array[j] = array->array[j + 1];
				array->array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

static unsigned short	count_nums(int argc, t_string argv[])
{
	unsigned short	count;
	unsigned short	i;
	unsigned short	j;

	count = 0;
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]))
				if (argv[i][j + 1] == ' ' || argv[i][j + 1] == '\0')
					count++;
			else
				if (argv[i][j] != ' ' && argv[i][j] != '-')
					throw_error();
			j++;
		}
		i++;
	}
	return (count);
}

void	parse(int argc, t_string argv[], t_data *stack)
{
	t_array	array;

	if (argc == 1)
		exit(EXIT_FAILURE);
	array.size = count_nums(argc, argv);
	//=====okay=====
	if (array.size == 1)
		exit(EXIT_SUCCESS);
	make_array(argc, argv, &array);
	if (check_dup(&array) == true)
	{
		free(array.array);
		throw_error();
	}
	sort_array(&array);
}
