/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 13:07:09 by fmota             #+#    #+#             */
/*   Updated: 2021/02/15 13:07:09 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char *new;
	unsigned int index;

	index = 0;
	if (!s)
		return (NULL);
	if (!f)
		return (ft_strdup(s));
	if (!(new = (char *)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[index])
	{
		new[index] = (*f)(index, s[index]);
		index++;
	}
	new[index] = '\0';
	return (new);
}