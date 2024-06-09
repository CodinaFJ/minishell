/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:04:27 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/01 21:47:15 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "../../include/minishell.h"

void	handle_signal_sigint(void)
{
	ft_printf("\n");
	ft_printf(SHELL_PROMT);
}

void	handle_signal_sigquit(void)
{

}

void signal_handler(int signum, siginfo_t *info, void *context)
{
	(void) context;
	(void) info;
	if (signum == SIGINT)
		handle_signal_sigint();
	else if (signum == SIGQUIT)
		handle_signal_sigquit();
}

static void	register_sig_handlers(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART | SA_SIGINFO;
	sa.sa_sigaction = signal_handler;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGQUIT, &sa, NULL);
}

void signals_init(void)
{
	register_sig_handlers();
}
