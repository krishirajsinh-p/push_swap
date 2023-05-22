/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:18:22 by kpuwar            #+#    #+#             */
/*   Updated: 2023/05/21 21:55:53 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../../lib/libft/libft.h"

typedef struct s_array
{
	unsigned short	size;
	int				*array;
}					t_array;

typedef struct s_node
{
	int				data;
	int				ideal_index;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	int				size;
	t_node			*top;
}					t_stack;

typedef struct s_data
{
	t_stack			a;
	t_stack			b;
}					t_data;

void			parse(int argc, t_string argv[], t_data *stack);

#endif
