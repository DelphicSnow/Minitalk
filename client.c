/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkajanek <tkajanek@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:48:15 by tkajanek          #+#    #+#             */
/*   Updated: 2023/04/19 15:23:37 by tkajanek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	g_receiver = 0;

static void	sig_handler(int signum, siginfo_t *info, void *context)
{
	static int	i;

	(void)context;
	if (signum == SIGUSR2)
		i++;
	else if (signum == SIGUSR1)
	{
		ft_printf("server recieved %d bits\n", i);
	}
	g_receiver = 1;
}

static void	character_to_binary(char c, int pid)
{
	int	itr;
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		itr = 0;
		if ((c >> bit_index) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		bit_index--;
		while (g_receiver == 0)
		{
			if (itr == 5000)
			{
				ft_printf("No response from a server\n");
				exit(EXIT_FAILURE);
			}
			itr++;
			usleep(1);
		}
		g_receiver = 0;
	}
}

static void	send_message(char *message, pid_t server_pid)
{
	int	i;

	i = 0;
	while (message[i] != '\0')
	{
		character_to_binary(message[i], server_pid);
		i++;
	}
	character_to_binary('\0', server_pid);
}

int	main(int argc, char **argv)
{
	struct sigaction	client;
	pid_t				server_pid;
	char				*message;
	int					i;

	if (argc != 3)
	{
		ft_printf("Usage: %s <server PID> <message>\n", argv[0]);
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	message = argv[2];
	client.sa_sigaction = &sig_handler;
	client.sa_flags = SA_SIGINFO;
	sigemptyset(&client.sa_mask);
	if (sigaction(SIGUSR1, &client, NULL) == -1
		|| sigaction(SIGUSR2, &client, NULL) == -1)
	{
		ft_printf("Error setting up SIGUSR1 or SIGUSR2 signal handler");
		exit(EXIT_FAILURE);
	}
	send_message(message, server_pid);
}
