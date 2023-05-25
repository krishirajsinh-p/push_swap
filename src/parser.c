/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 19:48:02 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/25 11:32:14 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

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
	
	array->element = ft_calloc(array->size + 1, sizeof(int));
	if (array->element == NULL)
		throw_error();
	k = 0;
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (split == NULL)
		{	//if split is null then free array mem and exit with msg
			free(array->element);
			throw_error();
		}
		j = 0;
		while (split[j])
		{
			if (ft_stoi(split[j++], &array->element[k++]) == false)
			{	//if stoi is unsuccessfull free array.array and split and throws error before exit
				free(array->element);
				ft_free_split(split);
				throw_error();
			}
			ft_free_split(split);	
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
			if (ft_isdigit(argv[i][j]) && argv[i][j + 1] == ' '
			|| argv[i][j + 1] == '\0')
				count++;
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
			&& argv[i][j] != '-')
				throw_error(NULL);
			j++;
		}
		i++;
	}
	return (count);
}

void	parse(int argc, t_string argv[], t_data *stack)
{
	if (argc == 1)
		exit(EXIT_FAILURE);
	stack->array.size = count_nums(argc, argv);
	if (stack->array.size == 1)
		exit(EXIT_SUCCESS);
	make_array(argc, argv, &stack->array);
	if (ft_check_dup(&stack->array) == true)
		throw_error(NULL);
	ft_check_dup(&stack->array);
	// ft_print_array(&array);
}
