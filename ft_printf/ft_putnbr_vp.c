/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrvp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:22:50 by hel-band          #+#    #+#             */
/*   Updated: 2023/11/16 15:50:28 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_vp(unsigned long int nb, unsigned int lent
		, char *hex, int *size)
{
	if (nb >= lent)
	{
		ft_putnbr_vp(nb / lent, lent, hex, size);
		ft_putchar(hex[nb % lent], size);
	}
	else
		ft_putchar(hex[nb % lent], size);
}
