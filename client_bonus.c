/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 18:28:56 by hel-band          #+#    #+#             */
/*   Updated: 2024/01/15 18:29:04 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void    ft_receipt(int signal)
{
	if (signal == SIGUSR1)
		ft_putstr("Received bit 1\n");
	else if (signal == SIGUSR2)
		ft_putstr("Received bit 0\n");
}
void	ft_send_signal(int pid, unsigned char str)
{
	int				i;
	unsigned char	shifted;

	i = 8;
	shifted = str;
	while (i--)
	{
		shifted = str >> i;
		if (shifted % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(420);
	}
}

void	ft_send_char(int pid, char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_send_signal(pid, str[i++]);
	ft_send_signal(pid, str[i]);
}

int	main(int ac, char **av)
{
	pid_t	server_pid;

    signal(SIGUSR1, ft_receipt);
	signal(SIGUSR2, ft_receipt);
	if (ac != 3)
	{
		ft_putstr("Usage:  <pid> <message>\n");
		return (0);
	}
	server_pid = ft_atoi(av[1]);
	ft_send_char(server_pid, av[2]);
	return (0);
}

