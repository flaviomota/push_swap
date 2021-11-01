/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 12:03:37 by fmota             #+#    #+#             */
/*   Updated: 2021/11/01 09:15:44 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	gnl_read(char *buf, char **maker)
{
	int		index;
	char	*tmp;

	if (!*maker || !ft_strchr(*maker, '\n'))
	{
		index = read(0, buf, BUFFER_SIZE);
		while (index > 0)
		{
			buf[index] = 0;
			if (!*maker)
				*maker = ft_strdup(buf);
			else
			{
				tmp = *maker;
				*maker = ft_strjoin(*maker, buf);
				free(tmp);
			}
			if (ft_strchr(buf, '\n'))
				break ;
			index = read(0, buf, BUFFER_SIZE);
		}
	}
	free(buf);
}

static char	*gnl_development(char **maker)
{
	int		i;
	int		j;
	char	*ret;
	char	*tmp;

	if (!*maker)
		return (0);
	if (!ft_strchr(*maker, '\n'))
	{
		ret = ft_strdup(*maker);
		free(*maker);
		*maker = 0;
		return (ret);
	}
	i = ft_strlen(*maker);
	j = ft_strlen(ft_strchr(*maker, '\n'));
	ret = ft_substr(*maker, 0, i - j + 1);
	tmp = *maker;
	*maker = ft_substr(ft_strchr(*maker, '\n'), 1, j);
	free(tmp);
	return (ret);
}

char	*get_next_line(char **maker)
{
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (0);
	gnl_read(buf, maker);
	return (gnl_development(maker));
}
