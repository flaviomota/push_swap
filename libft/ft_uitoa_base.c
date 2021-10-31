/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:53:11 by fmota             #+#    #+#             */
/*   Updated: 2021/05/18 13:53:11 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*insert_str(unsigned long long int nb, int base, int size, char *s)
{
	while (nb != 0)
	{
		if ((nb % base) < 10)
			s[size - 1] = (nb % base) + 48;
		else
			s[size - 1] = (nb % base) + 55;
		nb /= base;
		size--;
	}
	return (s);
}

char	*ft_uitoa_base(unsigned long long int nb, int base)
{
	unsigned long long int	tmp;
	int						size;
	char					*str;

	tmp = nb;
	size = 0;
	str = 0;
	if (nb == 0)
		return (ft_strdup("0"));
	while (nb)
	{
		nb /= base;
		size++;
	}
	// if(!(str = malloc(sizeof(char) * (size + 1))))
	str = malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	str[size] = '\0';
	str = insert_str(tmp, base, size, str);
	return (str);
}