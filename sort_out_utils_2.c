/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_out_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:24:18 by fmota             #+#    #+#             */
/*   Updated: 2021/10/31 17:52:57 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	middle_index(t_list *stack, int nb)
{
	const int	size = ft_lstsize(stack);
	int			ret;
	int			atual;
	int			next;

	ret = 1;
	while (stack->next)
	{
		atual = *((int *)stack->content);
		next = *((int *)stack->next->content);
		if (nb > atual && nb < next)
			break ;
		++ret;
		stack = stack->next;
	}
	if (ret == size)
		ret = 0;
	else if (ret >= (size + 1) / 2)
		ret = -1 * (size - ret);
	return (ret);
}

int	min_max_index(t_list *stack, int nb)
{
	const int	size = ft_lstsize(stack);
	int			ret;
	int			x;

	ret = 0;
	x = stack_max(stack);
	if (nb <= stack_min(stack))
		x = stack_min(stack);
	else
		++ret;
	while (stack)
	{
		if (*((int *)stack->content) == x)
			break ;
		++ret;
		stack = stack->next;
	}
	if (ret >= (size + 1) / 2)
		ret = -1 * (size - ret);
	return (ret);
}

void	find_min_rotate(t_list *stack1, t_list *stack2, int *nb1, int *nb2)
{
	const int	size_b = ft_lstsize(stack2);
	int			i;
	int			j;
	int			nb;
	int			x;

	x = -1;
	while (stack2 && ++x >= 0)
	{
		nb = *((int *)stack2->content);
		if (nb < stack_min(stack1) || nb > stack_max(stack1))
			i = min_max_index(stack1, nb);
		else
			i = middle_index(stack1, nb);
		j = x;
		if (x >= (size_b + 1) / 2)
			j = -1 * (size_b - x);
		if (x == 0 || ft_abs(*nb1) + ft_abs(*nb2) > ft_abs(i) + ft_abs(j))
		{
			*nb1 = i;
			*nb2 = j;
		}
		stack2 = stack2->next;
	}
}

void	rotate_same(t_list **stack1, t_list **stack2, int nb1, int nb2)
{
	if (nb1 >= 0 && nb2 >= 0)
	{
		process_guidelines("rr", stack1, stack2, min(ft_abs(nb1), ft_abs(nb2)));
		if (ft_abs(nb1) <= ft_abs(nb2))
			process_guidelines("rb", stack2, 0, ft_abs(ft_abs(nb1)
					- ft_abs(nb2)));
		else
			process_guidelines("ra", stack1, 0, ft_abs(ft_abs(nb1)
					- ft_abs(nb2)));
	}
	else
	{
		process_guidelines("rrr", stack1, stack2, min(ft_abs(nb1),
				ft_abs(nb2)));
		if (ft_abs(nb1) <= ft_abs(nb2))
			process_guidelines("rrb", stack2, 0, ft_abs(ft_abs(nb1)
					- ft_abs(nb2)));
		else
			process_guidelines("rra", stack1, 0, ft_abs(ft_abs(nb1)
					- ft_abs(nb2)));
	}
}

void	rotate_diff(t_list **stack1, t_list **stack2, int nb1, int nb2)
{
	if (nb1 >= 0 && nb2 < 0)
	{
		process_guidelines("ra", stack1, 0, nb1);
		process_guidelines("rrb", stack2, 0, ft_abs(min(nb1, nb2)));
	}
	else
	{
		process_guidelines("rb", stack2, 0, nb2);
		process_guidelines("rra", stack1, 0, ft_abs(min(nb1, nb2)));
	}
}
