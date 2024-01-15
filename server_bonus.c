/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-band <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 19:04:19 by hel-band          #+#    #+#             */
/*   Updated: 2024/01/15 19:04:25 by hel-band         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_handle_signal(int sig, siginfo_t *info, void *context)
{
	static unsigned char	byt;
	static unsigned int		i;
	static pid_t			client_pid;

	(void)context;
	if (client_pid != info->si_pid)
	{
		i = 0;
		byt = 0;
	}
	client_pid = info->si_pid;
	byt |= (sig == SIGUSR1);
	i++;
	if (i == 8)
	{
		if (byt == '\0')
			write(1, "\n", 1);
		else
			write(1, &byt, 1);
		i = 0;
		byt = 0;
	}
	else
		byt <<= 1;
    if (sig == SIGUSR1)
        kill(info->si_pid, SIGUSR1);
    else if (sig == SIGUSR2)
        kill(info->si_pid, SIGUSR2);

}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = ft_handle_signal;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	ft_putnbr (getpid());
	while (1)
		pause();
	return (0);
}
