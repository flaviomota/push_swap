/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 12:27:27 by fmota             #+#    #+#             */
/*   Updated: 2021/02/15 12:27:27 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int ft_viability(char c, char const *set)
{
	int index;

	index = 0;
	while (set[index])
	{
		if (c == set[index])
			return (0);
		index++;
	}
	return (1);
}

static int ft_lensize(char const *s1, char const *set)
{
	size_t index;
	size_t count;

	index = ft_strlen(s1) - 1;
	count = 0;
	while (ft_viability(s1[count], set) == 0)
		count++;
	if (count == ft_strlen(s1))
		return (-1);
	while (ft_viability(s1[index], set) == 0)
	{
		index--;
		count++;
	}
	return (count);
}

char *ft_strtrim(char const *s1, char const *set)
{
	size_t count;
	size_t index;
	size_t len;
	char *cpy;

	count = 0;
	index = 0;
	if (!s1 && set)
		return (NULL);
	if (s1 && !set)
		return (ft_strdup(s1));
	if (!s1 && !set)
		return (NULL);
	len = ft_strlen(s1) - ft_lensize(s1, set);
	if (!(cpy = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (ft_lensize(s1, set) == -1)
		len = 0;
	while (ft_viability(s1[count], set) == 0)
		count++;
	while (index < len)
		cpy[index++] = s1[count++];
	cpy[index] = '\0';
	return (cpy);
}