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

#include "builtin.h"

t_builtin	**builtins_init()
{
	t_builtin	**builtins_array;
	int			i;

	i = 0;
	builtins_array = ft_calloc(N_BUILTINS + 1, sizeof(t_builtin *));
	if (builtins_array == NULL)
		return (NULL);
	builtins_array[N_BUILTINS + 1] = NULL;
	builtins_array[i++] = builtin_new("echo", ft_echo);
	builtins_array[i++] = builtin_new("env", ft_env);
	builtins_array[i++] = builtin_new("pwd", ft_pwd);
	builtins_array[i++] = builtin_new("exit", ft_exit);
 	builtins_array[i++] = builtin_new("cd", ft_cd);
	builtins_array[i++] = NULL;
	return (builtins_array);
}

t_bool	try_exec_builtin(t_builtin **builtins_array, char *name, char *args)
{
	int	i;

	i = 0;
	ft_printf("Try exec builtin: %s\n", name);
	while (builtins_array[i] != NULL)
	{
		if (ft_strcmp(builtins_array[i]->name, name) == 0)
		{
			builtins_array[i]->f(args);
			return (true);
		}
		i++;
	}
	return (false);
}