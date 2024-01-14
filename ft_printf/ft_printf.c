/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:16:28 by hel-band          #+#    #+#             */
/*   Updated: 2023/11/16 16:31:33 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_printf_format(const char format, va_list lst, int *size)
{
	if (format == 'i' || format == 'd')
		ft_putnbr(va_arg(lst, int), size);
	else if (format == 'u')
		ft_putnbr_un(va_arg(lst, unsigned int), size);
	else if (format == 'c')
		ft_putchar((char)va_arg(lst, int), size);
	else if (format == 's')
		ft_putstr(va_arg(lst, char *), size);
	else if (format == 'x')
		ft_putnbr_hex(va_arg(lst, unsigned int), 16, "0123456789abcdef", size);
	else if (format == 'X')
		ft_putnbr_hex(va_arg(lst, int), 16, "0123456789ABCDEF", size);
	else if (format == 'p')
	{
		ft_putstr("0x", size);
		ft_putnbr_vp((unsigned long int) va_arg(lst, void *), 
			16, "0123456789abcdef", size);
	}
	else if (format == '%')
		ft_putchar('%', size);
	else
		ft_putchar(format, size);
}

int	ft_printf(const char *format, ...)
{
	va_list	lst;
	int		size;

	if (write(1, "", 0) < 0)
		return (-1);
	va_start (lst, format);
	size = 0;
	while (format && *format)
	{
		if (*format == '%')
			ft_printf_format(*(++format), lst, &size);
		else
			ft_putchar(*(format), &size);
		format++;
	}
	va_end(lst);
	return (size);
}
