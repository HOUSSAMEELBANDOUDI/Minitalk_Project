/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 23:31:10 by hel-band          #+#    #+#             */
/*   Updated: 2024/01/11 20:29:30 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"
#include <stdlib.h>

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
		{
			if (kill(pid, SIGUSR2) < 0)
				exit(1);
		}
		else
		{
			if (kill(pid, SIGUSR1) < 0)
				exit(1);
		}
		usleep(450);
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

	if (ac != 3)
	{
		ft_putstr("check the number of your arguments");
		return (0);
	}
	server_pid = ft_atoi(av[1]);
	if (server_pid <= 0)
	{
		ft_putstr("check your server_pid\n");
		return (0);
	}
	ft_send_char(server_pid, av[2]);
	return (0);
}
