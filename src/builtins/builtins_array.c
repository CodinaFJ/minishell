/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 18:03:54 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/01 18:07:30by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static t_bool	is_array_correct(t_builtin **builtins_array)
{
	int	i;

	i = -1;
	while (++i < N_BUILTINS)
	{
		if (builtins_array[i] == NULL)
		{
			builtins_free(builtins_array);
			return (false);
		}
	}
	return (true);
}

t_builtin	**builtins_init(void)
{
	t_builtin	**builtins_array;
	int			i;

	i = 0;
	builtins_array = ft_calloc(N_BUILTINS + 1, sizeof(t_builtin *));
	if (builtins_array == NULL)
		return (NULL);
	builtins_array[0] = builtin_new("echo", ft_echo);
	builtins_array[1] = builtin_new("env", builtin_env);
	builtins_array[2] = builtin_new("pwd", ft_pwd);
	builtins_array[3] = builtin_new("exit", builtin_exit);
	builtins_array[4] = builtin_new("export", builtin_export);
	builtins_array[5] = builtin_new("unset", builtin_unset);
	if (is_array_correct(builtins_array))
		return (builtins_array);
	return (NULL);
}

t_bool	try_exec_builtin(void *ctx, char *name, char *command)
{
	int				i;
	t_minishell_ctx	*mini_ctx;

	i = 0;
	mini_ctx = (t_minishell_ctx *)ctx;
	while (mini_ctx->builtins[i] != NULL)
	{
		if (ft_strcmp(mini_ctx->builtins[i]->name, name) == 0)
		{
			// ft_printf("Try exec builtin: %s\n", name);
			mini_ctx->builtins[i]->f(command, ctx);
			return (true);
		}
		i++;
	}
	return (false);
}

void	*builtins_free(t_builtin **builtins_array)
{
	int	i;

	i = -1;
	if (builtins_array == NULL)
		return (NULL);
	while (++i < N_BUILTINS && builtins_array[i])
		builtin_free(builtins_array[i]);
	return (NULL);
}
