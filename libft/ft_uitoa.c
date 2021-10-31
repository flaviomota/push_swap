/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:37:53 by fmota             #+#    #+#             */
/*   Updated: 2021/05/18 13:37:53 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_uitoa(unsigned long long int nb, int base)
{
    unsigned long long int  tmp;
    int						size;
	char					*str;

	tmp = nb;
	size = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb /= base)
		size++;
	// if(!(str = malloc(sizeof(char) * (size + 1))))
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (tmp > 0)
	{
		if ((tmp % base) < 10)
			str[size--] = (tmp % base) + 48;
		else
			str[size--] = (tmp % base) + 55;
		tmp /= base;
	}
	return (str);
}