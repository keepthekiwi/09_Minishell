/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skillian <skillian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 10:14:41 by skillian          #+#    #+#             */
/*   Updated: 2022/07/02 15:11:27 by skillian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./builtin.h"
#include "../includes/minishell.h"
#include "readline/readline.h"

static void	handle_cmd_signal(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
	}
}

static void	handle_global_signal(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	handle_quit(int sig)
{
	if (sig == SIGQUIT)
		printf("Quit: 3\n");
}

void	handle_cmd_signals(void)
{
	signal(SIGQUIT, handle_quit);
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_cmd_signal);
}

void	handle_global_signals(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, SIG_IGN);
	signal(SIGINT, handle_global_signal);
}
