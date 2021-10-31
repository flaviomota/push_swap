/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   certify.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 14:51:33 by fmota             #+#    #+#             */
/*   Updated: 2021/10/31 17:57:43 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicate(int *nb, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
			if (nb[i] == nb[j++])
				return (1);
		++i;
	}
	return (0);
}

int	converter(char **str, int **nb)
{
	int	index;
	int	ret;
	int	*tmp;

	index = 0;
	while (str[index])
		if (!ft_isint(str[index++]))
			return (0);
	ret = index;
	tmp = malloc(sizeof(int) * index);
	if (!tmp)
		return (0);
	while (index--)
		tmp[index] = ft_atoi(str[index]);
	if (check_duplicate(tmp, ret))
	{
		free(tmp);
		ret = 0;
	}
	*nb = tmp;
	return (ret);
}

void	check(char **argv)
{
	int	index;

	index = 0;
	while (argv[index])
		if (!ft_strlen(argv[index++]))
			ft_error(1);
}

void	wipe_up1(char *str, char **str2)
{
	int	index;

	index = 0;
	free(str);
	while (str2[index])
		free(str2[index++]);
	free(str2);
}

void	wipe_up2(int *nb, t_list *stack)
{
	t_list	*tmp;

	free(nb);
	while (stack)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}
