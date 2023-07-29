/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:49:57 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/19 15:23:39 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	handle_signal(int signum, siginfo_t *info, void *context)
{
	static int	bit;
	static char	c;

	(void)context;
	if (signum == SIGUSR1)
		c = (c << 1) | 1;
	else if (signum == SIGUSR2)
		c = c << 1;
	bit++;
	if (bit == 8)
	{
		if (c == 0)
			kill(info->si_pid, SIGUSR1);
		ft_printf("%c", c);
		bit = 0;
		c = 0;
	}
	kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	server;

	ft_printf("the PID of server is: %d\n", getpid());
	server.sa_sigaction = handle_signal;
	sigemptyset(&server.sa_mask);
	server.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &server, NULL);
	sigaction(SIGUSR2, &server, NULL);
	while (1)
		pause();
	return (0);
}
