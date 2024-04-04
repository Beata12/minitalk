/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 07:33:28 by bmarek            #+#    #+#             */
/*   Updated: 2024/02/18 11:53:57 by bmarek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	display_message(char *received_message)
{
	write(1, "\e[1;32m Received » \e[0;37m", 28);
	write(1, "\e[1;33m", 7);
	write(1, received_message, ft_strlen(received_message));
	write(1, "\n", 1);
}

void	convert_pid_to_string(int pid, char *pid_str, int *digits)
{
	int	temp_pid;
	int	index;

	temp_pid = pid;
	index = 0;
	*digits = 0;
	while (temp_pid != 0)
	{
		pid_str[index++] = temp_pid % 10 + '0';
		temp_pid /= 10;
		(*digits)++;
	}
}

void	reverse_string(char *str, int length)
{
	int		start;
	int		end;
	char	temp;

	start = 0;
	end = length - 1;
	while (start < end)
	{
		temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
