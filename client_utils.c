/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 07:33:24 by bmarek            #+#    #+#             */
/*   Updated: 2024/02/18 11:40:48 by bmarek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_succes_msg(int signal, siginfo_t *client, void *ucontext)
{
	const char	*success_msg;

	(void)client;
	(void)ucontext;
	success_msg = "\033[32m\n✅✅✅ SUCCESS! Message sent to server! ✅✅✅\033[0m\n";
	if (signal == SIGUSR2)
	{
		write(1, success_msg, ft_strlen(success_msg));
		exit(EXIT_SUCCESS);
	}
}

int	ft_atoi(const char *str)
{
	int	i;
	int	result;
	int	plus_minus;

	i = 0;
	result = 0;
	plus_minus = 1;
	while (str[i] != '\0')
	{
		while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == 43 || str[i] == 45)
		{
			if (str[i] == 45)
				plus_minus = plus_minus * (-1);
			i++;
		}
		while (str[i] >= 48 && str[i] <= 57)
		{
			result = result * 10 + str[i] - 48;
			i++;
		}
		return (result * plus_minus);
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
