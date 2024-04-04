/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 07:33:22 by bmarek            #+#    #+#             */
/*   Updated: 2024/02/18 11:52:22 by bmarek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	binary_to_char(int *sig_recived)
{
	int	result;
	int	i;

	result = 0;
	i = 0;
	while (i < 8)
	{
		result = (result << 1) | sig_recived[i];
		i++;
	}
	return ((char)result);
}

void	handle_message(t_message_data *data)
{
	char	*new_buffer;

	new_buffer = (char *)malloc(sizeof(char) * ((*(data->len)) + 2));
	if (!new_buffer)
		exit(EXIT_FAILURE);
	if (*(data->received_message))
	{
		strcpy(new_buffer, *(data->received_message));
		free(*(data->received_message));
	}
	*(data->received_message) = new_buffer;
	(*(data->received_message))[(*(data->len))
		- 1] = binary_to_char(data->sig_received);
	(*(data->received_message))[(*(data->len))] = '\0';
	if ((*(data->received_message))[(*(data->len)) - 1] == '\0')
	{
		display_message(*(data->received_message));
		free(*(data->received_message));
		*(data->received_message) = NULL;
		*(data->len) = 1;
		kill((data->sig_info)->si_pid, SIGUSR2);
	}
	else
		(*(data->len))++;
	*(data->i) = 0;
}

void	ft_handle_signal(int num_of_sig, siginfo_t *sig_info, void *context)
{
	static char		*str = NULL;
	static int		sig_recived[8];
	static int		i = 0;
	static int		length = 1;
	t_message_data	data;

	(void)context;
	sig_recived[i++] = num_of_sig == SIGUSR1;
	if (i == 8)
	{
		data.received_message = &str;
		data.sig_info = sig_info;
		data.sig_received = sig_recived;
		data.i = &i;
		data.len = &length;
		handle_message(&data);
	}
}

void	write_pid_as_string(int pid)
{
	char		pid_str[20];
	int			digits;
	const char	*color_start;
	const char	*color_end;

	convert_pid_to_string(pid, pid_str, &digits);
	reverse_string(pid_str, digits);
	pid_str[digits] = '\0';
	color_start = "\033[33;1m";
	color_end = "\033[0m";
	write(1, color_start, ft_strlen(color_start));
	write(1, pid_str, ft_strlen(pid_str));
	write(1, color_end, ft_strlen(color_end));
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;
	const char			*mt;
	const char			*pid_text;
	const char			*color_start;

	color_start = "\033[33;1m";
	pid = getpid();
	write(1, "        ", 9);
	mt = "\e[31mM\e[33mI\e[32mN\e[34mI\e[35mT\e[36mA\e[33;1mL\e[31mK\e[0m\n";
	pid_text = "\033[33;1mPID:\033[0m               ";
	write(1, mt, 56);
	write(1, color_start, ft_strlen(color_start));
	write(1, pid_text, 31);
	write_pid_as_string(pid);
	write(1, "\n\n", 2);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = ft_handle_signal;
	sigemptyset(&(sig.sa_mask));
	sigaction(SIGUSR2, &sig, NULL);
	sigaction(SIGUSR1, &sig, NULL);
	while (1)
		sleep(1);
	return (0);
}
