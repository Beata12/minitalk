/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 07:33:17 by bmarek            #+#    #+#             */
/*   Updated: 2024/02/18 11:40:51 by bmarek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal_to_pid(pid_t pid, int signal)
{
	const char	*good_msg;

	good_msg = "\033[31m❗Correct input:./client ⛔ PID ⛔ \"message\"❗\033[0m\n";
	if (kill(pid, signal) == -1)
	{
		write(2, good_msg, ft_strlen(good_msg));
		exit(EXIT_FAILURE);
	}
}

void	send_char_bits(pid_t pid, unsigned char c)
{
	int	i;
	int	n;

	i = 0;
	n = 7;
	while (i < 8)
	{
		if (c & (1 << n))
			send_signal_to_pid(pid, SIGUSR1);
		else
			send_signal_to_pid(pid, SIGUSR2);
		i++;
		n--;
		usleep(100);
	}
}

void	send_string_to_pid(int pid, const char *str)
{
	while (*str)
		send_char_bits(pid, *str++);
	send_char_bits(pid, '\0');
}

void	initialize_and_send(pid_t pid, char *message)
{
	struct sigaction	sig;
	const char			*good_msg;
	const char			*invalid_msg;

	invalid_msg = "\033[31m❗Invalid ⛔ PID ⛔ ❗\033[0m\n";
	good_msg = "\033[31m❗Correct input:./client ⛔ PID ⛔ \"message\"❗\033[0m\n";
	if (pid == 0 || message == NULL)
	{
		write(2, good_msg, ft_strlen(good_msg));
		exit(EXIT_FAILURE);
	}
	sig.sa_flags = SA_SIGINFO | SA_RESTART;
	sig.sa_sigaction = handle_succes_msg;
	sigemptyset(&(sig.sa_mask));
	sigaction(SIGUSR2, &sig, NULL);
	sigaction(SIGUSR1, &sig, NULL);
	if (!pid)
	{
		write(2, invalid_msg, ft_strlen(invalid_msg));
		exit(EXIT_FAILURE);
	}
	send_string_to_pid(pid, message);
}

int	main(int argc, char *argv[])
{
	pid_t		pid;
	char		*message;
	const char	*good_msg;

	good_msg = "\033[31m❗Correct input:./client ⛔ PID ⛔ \"message\"❗\033[0m\n";
	if (argc != 3)
	{
		write(2, good_msg, ft_strlen(good_msg));
		exit(EXIT_FAILURE);
	}
	pid = ft_atoi(argv[1]);
	message = argv[2];
	initialize_and_send(pid, message);
	return (0);
}
