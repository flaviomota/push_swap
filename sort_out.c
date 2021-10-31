/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_out.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 13:20:55 by fmota             #+#    #+#             */
/*   Updated: 2021/10/31 18:02:25 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_3(t_list **stack)
{
	const int	nb1 = *((int *)(*stack)->content);
	const int	nb2 = *((int *)(*stack)->next->content);
	const int	nb3 = *((int *)(*stack)->next->next->content);

	if (nb1 == stack_min(*stack) && nb2 == stack_max(*stack))
	{
		process_guidelines("sa", stack, 0, 1);
		process_guidelines("ra", stack, 0, 1);
	}
	else if (nb2 == stack_min(*stack) && nb3 == stack_max(*stack))
		process_guidelines("sa", stack, 0, 1);
	else if (nb3 == stack_min(*stack) && nb2 == stack_max(*stack))
		process_guidelines("rra", stack, 0, 1);
	else if (nb2 == stack_min(*stack) && nb1 == stack_max(*stack))
		process_guidelines("ra", stack, 0, 1);
	else
	{
		process_guidelines("sa", stack, 0, 1);
		process_guidelines("rra", stack, 0, 1);
	}
}

static void	sort_big(t_list **stack1)
{
	int		nb1;
	int		nb2;
	t_list	*stack2;

	stack2 = 0;
	while (ft_lstsize(*stack1) > 3)
		process_guidelines("pb", stack1, &stack2, 1);
	if (!arranged(*stack1))
		sort_3(stack1);
	while (ft_lstsize(stack2))
	{
		nb1 = 0;
		nb2 = 0;
		find_min_rotate(*stack1, stack2, &nb1, &nb2);
		if ((nb1 >= 0 && nb2 >= 0) || (nb1 < 0 && nb2 < 0))
			rotate_same(stack1, &stack2, nb1, nb2);
		else
			rotate_diff(stack1, &stack2, nb1, nb2);
		process_guidelines("pa", &stack2, stack1, 1);
	}
}

static void	sort_final(t_list **stack)
{
	const int	i = min_max_index(*stack, stack_min(*stack));

	if (i < 0)
		process_guidelines("rra", stack, 0, -i);
	else
		process_guidelines("ra", stack, 0, i);
}

void	sort(t_list **stack)
{
	if (ft_lstsize(*stack) == 2)
		process_guidelines("sa", stack, 0, 1);
	else if (ft_lstsize(*stack) == 3)
		sort_3(stack);
	else
		sort_big(stack);
	sort_final(stack);
}
