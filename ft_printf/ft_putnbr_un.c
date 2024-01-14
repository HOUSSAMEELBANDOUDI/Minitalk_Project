/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_un.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 17:07:11 by hel-band          #+#    #+#             */
/*   Updated: 2023/11/16 11:07:17 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putnbr_un(unsigned int nb, int *size)
{
	if (nb > 9)
	{
		ft_putnbr_un(nb / 10, size);
		ft_putchar((nb % 10) + 48, size);
	}
	else
		ft_putchar(nb + 48, size);
}
