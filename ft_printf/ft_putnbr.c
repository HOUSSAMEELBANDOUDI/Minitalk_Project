/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:37:38 by hel-band          #+#    #+#             */
/*   Updated: 2023/11/16 12:35:52 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr(int n, int *size)
{
	long	nb;

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-', size);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, size);
		ft_putchar((nb % 10) + 48, size);
	}
	else
		ft_putchar(nb + 48, size);
}
