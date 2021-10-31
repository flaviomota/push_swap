/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:24:22 by fmota             #+#    #+#             */
/*   Updated: 2021/05/18 13:24:22 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_intlen(int nb, int base)
{
	size_t			len;
	unsigned int	u_nb;

	len = 1;
	if (nb < 0)
	{
		u_nb = -nb;
		len = 2;
	}
	else
		u_nb = nb;
	while ((u_nb /= base) > 0)
		len++;
	return (len);
}