/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uintlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmota <fmota@student.42lisboa.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 13:35:22 by fmota             #+#    #+#             */
/*   Updated: 2021/05/18 13:35:22 by fmota            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_uintlen(unsigned int nb, int base)
{
    size_t  len;

    len = 1;
    while ((nb /= base) > 0)
        len++;
    return (len);
}