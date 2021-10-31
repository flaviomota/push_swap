/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_out_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:23:52 by fmota             #+#    #+#             */
/*   Updated: 2021/10/31 18:02:39 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_min(t_list *stack)
{
	int		min;
	int		nb;

	min = *((int *)stack->content);
	while (stack)
	{
		nb = *((int *)stack->content);
		if (min > nb)
			min = nb;
		stack = stack->next;
	}
	return (min);
}

int	stack_max(t_list *stack)
{
	int		max;
	int		nb;

	max = *((int *)stack->content);
	while (stack)
	{
		nb = *((int *)stack->content);
		if (max < nb)
			max = nb;
		stack = stack->next;
	}
	return (max);
}

int	arranged(t_list *stack)
{
	while (stack->next)
	{
		if (*((int *)stack->content) > *((int *)stack->next->content))
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	return (b);
}
