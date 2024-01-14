/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_HEX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:41:22 by hel-band          #+#    #+#             */
/*   Updated: 2023/11/16 12:36:25 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_hex(unsigned int n, int lent, char *hex, int *size)
{
	long long	nb;

	nb = n;
	if (nb >= lent)
	{
		ft_putnbr_hex(nb / lent, lent, hex, size);
		ft_putchar(hex[nb % lent], size);
	}
	else
		ft_putchar(hex[nb % lent], size);
}
