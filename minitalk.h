/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmarek <bmarek@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 07:41:02 by bmarek            #+#    #+#             */
/*   Updated: 2024/02/18 11:43:36 by bmarek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct message_data
{
	char		**received_message;
	siginfo_t	*sig_info;
	int			*sig_received;
	int			*i;
	int			*len;
}				t_message_data;

// Client
int				ft_atoi(const char *str);
void			handle_succes_msg(int signal, siginfo_t *client,
					void *ucontext);

size_t			ft_strlen(const char *str);

// Server
void			convert_pid_to_string(int pid, char *pid_str, int *digits);
void			reverse_string(char *str, int length);
void			display_message(char *received_message);

#endif