/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:18:22 by kpuwar            #+#    #+#             */
/*   Updated: 2023/04/28 15:36:01 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../lib/libft/libft.h"

# define ERROR_MSG "Error\n"

typedef t_list	t_stack;

// typedef struct s_array
// {
// 	size_t	size;
// 	void	*array;
// }	t_array;

//praser.c
bool	parse(int argc, t_string argv[]);

//operations.c
void	swap(t_stack **ptr);
void	push(t_stack **to, t_stack **from);
void	rotate(t_stack **ptr);
void	reverse_rotate(t_stack **ptr);

//praser_utils.c
unsigned short	count_nums(char **nums);
bool	ft_stoi(t_string str, int *num);
bool	check_dup(int *arr, int size);
void	free_split(t_string nums[]);

#endif
