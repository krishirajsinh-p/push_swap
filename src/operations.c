/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpuwar <kpuwar@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 04:51:02 by kpuwar            #+#    #+#             */
/*   Updated: 2023/03/07 05:07:06 by kpuwar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/push_swap.h"

void	swap(t_stack **ptr)
{
	t_stack	*tmp;

	if (ft_lstsize(*ptr) < 2)
		return ;
	tmp = (*ptr)->next;
	(*ptr)->next = tmp->next;
	tmp->next = (*ptr);
	(*ptr) = tmp;
}

void	push(t_stack **to, t_stack **from)
{
	t_stack	*tmp;

	if (ft_lstsize(*from) == 0)
		return ;
	tmp = (*from);
	(*from) = (*from)->next;
	ft_lstadd_front(to, tmp);
}

void	rotate(t_stack **ptr)
{
	t_stack	*tmp;

	if (ft_lstsize(*ptr) < 2)
		return ;
	tmp = (*ptr);
	(*ptr) = (*ptr)->next;
	tmp->next = NULL;
	ft_lstadd_back(ptr, tmp);
}

void	reverse_rotate(t_stack **ptr)
{
	t_stack	*itr;
	t_stack	*tmp;

	if (ft_lstsize(*ptr) < 2)
		return ;
	itr = (*ptr);
	while (1)
	{
		if (itr->next->next == NULL)
		{
			tmp = itr->next;
			itr->next = NULL;
			tmp->next = (*ptr);
			(*ptr) = tmp;
			break ;
		}
		itr = itr->next;
	}
}

// void	ft_do(t_stack **a, t_stack **b, const t_string cmd)
// {
// 	if (!ft_strncmp(cmd, "sa", 2))
// 		swap(&a);
// 	else if (!ft_strncmp(cmd, "sb", 2))
// 		swap(&b);
// 	else
// 	{
//		
// 	}
//	
// }

/*
# define SA swap(&a);
# define SB swap(&b);
# define SS SA SB

# define PA push(&a, &b);
# define PB push(&b, &a);

# define RA rotate(&a);
# define RB rotate(&b);
# define RR RA RB

# define RRA reverse_rotate(&a);
# define RRB reverse_rotate(&b);
# define RRR RRA RRB
*/
