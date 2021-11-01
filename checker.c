/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 15:20:55 by fmota             #+#    #+#             */
/*   Updated: 2021/11/01 09:14:24 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	parse(char *str, t_list **stack1, t_list **stack2)
{
	int	len;
	int	(*f)(const char *, const char *, size_t);

	len = ft_strlen(str);
	if (len < 3 || len > 4)
		return (ft_error(0));
	str[len - 1] = 0;
	len = ft_strlen(str);
	f = &ft_strncmp;
	if ((len == 3 && !f(str, "rra", 3)) || (len == 2 && (!f(str, "sa", 2)
				|| !f(str, "ra", 2))))
		process_guidelines(str, stack1, 0, -1);
	else if ((len == 3 && !f(str, "rrb", 3)) || (len == 2 && (!f(str, "sb", 2)
				|| !f(str, "rb", 2))))
		process_guidelines(str, stack2, 0, -1);
	else if ((len == 3 && !f(str, "rrr", 3)) || (len == 2 && (!f(str, "ss", 2)
				|| !f(str, "pb", 2) || !f(str, "rr", 2))))
		process_guidelines(str, stack1, stack2, -1);
	else if (!f(str, "pa", 2))
		process_guidelines(str, stack2, stack1, -1);
	else
		return (ft_error(0));
	return (1);
}

static void	sort_check(t_list **stack1)
{
	static char	*maker;
	char		*cmd;
	t_list		*stack2;

	stack2 = 0;
	while (1)
	{
		cmd = get_next_line(&maker);
		if (!cmd || !ft_strlen(cmd))
		{
			free(cmd);
			break ;
		}
		if (!parse(cmd, stack1, &stack2))
		{
			free(maker);
			free(cmd);
			return ;
		}
		free(cmd);
	}
	if (arranged(*stack1) && !ft_lstsize(stack2))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
}

int	main(int argc, char **argv)
{
	int		len;
	int		*nb;
	char	*str;
	char	**str2;
	t_list	*stack;

	if (argc > 1)
	{
		check(argv + 1);
		str = ft_join(argv + 1, " ");
		str2 = ft_split(str, ' ');
		nb = 0;
		len = converter(str2, &nb);
		wipe_up1(str, str2);
		if (!len)
			ft_error(1);
		stack = 0;
		while (len--)
			ft_lstadd_front(&stack, ft_lstnew(&nb[len]));
		sort_check(&stack);
		wipe_up2(nb, stack);
	}
	return (0);
}
