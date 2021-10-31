/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guidelines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:54:41 by fmota             #+#    #+#             */
/*   Updated: 2021/10/31 18:00:52 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sx(t_list **stack1, t_list **stack2)
{
	t_list	*tmp;

	(void)stack2;
	if (ft_lstsize(*stack1) >= 2)
	{
		tmp = (*stack1)->next;
		(*stack1)->next = tmp->next;
		ft_lstadd_front(stack1, tmp);
	}
}

static void	px(t_list **stack1, t_list **stack2)
{
	t_list	*tmp;

	if (ft_lstsize(*stack1))
	{
		tmp = *stack1;
		*stack1 = (*stack1)->next;
		ft_lstadd_front(stack2, tmp);
	}
}

static void	rx(t_list **stack1, t_list **stack2)
{
	t_list	*tmp;

	(void)stack2;
	if (ft_lstsize(*stack1) >= 2)
	{
		tmp = *stack1;
		*stack1 = (*stack1)->next;
		tmp->next = 0;
		ft_lstadd_back(stack1, tmp);
	}
}

static void	rrx(t_list **stack1, t_list **stack2)
{
	t_list	*last;
	t_list	*tmp;

	(void)stack2;
	if (ft_lstsize(*stack1) >= 2)
	{
		last = *stack1;
		while (last->next)
		{
			tmp = last;
			last = last->next;
		}
		tmp->next = 0;
		last->next = *stack1;
		*stack1 = last;
	}
}

void	process_guidelines(char *cmd, t_list **stack1, t_list **stack2, int nb)
{
	const int	len = ft_strlen(cmd);
	int			tmp;
	void		(*f)(t_list **, t_list **);

	tmp = ft_abs(nb);
	if (!ft_strncmp(cmd, "sa", len) || !ft_strncmp(cmd, "sb", len)
		|| !ft_strncmp(cmd, "ss", len))
		f = &sx;
	else if (!ft_strncmp(cmd, "pa", len) || !ft_strncmp(cmd, "pb", len))
		f = &px;
	else if (!ft_strncmp(cmd, "ra", len) || !ft_strncmp(cmd, "rb", len)
		|| !ft_strncmp(cmd, "rr", len))
		f = &rx;
	else
		f = &rrx;
	while (tmp--)
	{
		f(stack1, stack2);
		if (stack2 && f != px)
			f(stack2, 0);
		if (nb > 0)
			ft_putendl_fd(cmd, 1);
	}
}
