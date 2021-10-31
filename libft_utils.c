/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:05:29 by fmota             #+#    #+#             */
/*   Updated: 2021/10/31 17:05:32 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(int status)
{
	ft_putendl_fd("Error", 1);
	if (status)
		exit(status);
	return (status);
}

long	ft_atol(const char *str)
{
	int		sign;
	long	ret;

	ret = 0;
	sign = 1;
	while (ft_isspace(*str))
		++str;
	if (*str == '+' || *str == '-')
		if (*(str++) == '-')
			sign *= -1;
	while (ft_isdigit(*str))
	{
		ret = ret * 10 + sign * (*str++ - '0');
		if (sign < 0 && ret > 0)
			return (LONG_MIN);
		else if (sign > 0 && ret < 0)
			return (LONG_MAX);
	}
	return (ret);
}

int	ft_isint(char *str)
{
	int	index;

	index = 0;
	if (str[index] == '+' || str[index] == '-')
		++index;
	while (str[index])
		if (!ft_isdigit(str[index++]))
			return (0);
	if (ft_atol(str) < INT_MIN || ft_atol(str) > INT_MAX)
		return (0);
	return (1);
}

char	*ft_join(char **strs, char *sep)
{
	int		index;
	char	*str;
	char	*tmp;

	index = 0;
	while (strs[index])
	{
		if (!index)
			str = ft_strdup(strs[index++]);
		else
		{
			tmp = str;
			str = ft_strjoin(str, sep);
			free(tmp);
			tmp = str;
			str = ft_strjoin(str, strs[index++]);
			free(tmp);
		}
	}
	return (str);
}