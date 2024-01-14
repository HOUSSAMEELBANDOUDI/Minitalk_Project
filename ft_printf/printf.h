/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:39:29 by hel-band          #+#    #+#             */
/*   Updated: 2023/11/16 13:46:38 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>

/* Mandatory part */

void	ft_putchar(char c, int *size);
void	ft_putstr(char *s, int *size);
void	ft_putnbr_hex(unsigned int n, int lent, char *hex, int *size);
void	ft_putnbr_vp(unsigned long nb, unsigned int lent, char *hex, int *size);
void	ft_putnbr_un(unsigned int n, int *size);
void	ft_putnbr(int n, int *size);
int		ft_printf(const char *format, ...);

#endif
