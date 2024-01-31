/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 20:00:43 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/31 20:19:09by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

t_builtin	*builtin_new(char *name, void (*f)(char *args))
{
	t_builtin	*builtin;

	if (name == NULL || f == NULL)
		return (NULL);
	builtin = ft_calloc(1, sizeof(t_builtin));
	builtin->name = ft_strdup(name);
	builtin->f = f;
	return (builtin);	
}

void	builtin_free(t_builtin *builtin)
{
	if (builtin == NULL)
		return ;
	if (builtin->name != NULL)
		free(builtin->name);
	free(builtin);	
}

t_builtin	**get_builtins_array()
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
	builtins_array[i++] = NULL;
	return (builtins_array);
}

void	try_exec_builtin(t_builtin **builtins_array, char *name, char *args)
{
	int	i;

	i = 0;
	ft_printf("Try exec builtin: %s\n", name);
	while (builtins_array[i] != NULL)
	{
		if (ft_strcmp(builtins_array[i]->name, name) == 0)
		{
			builtins_array[i]->f(args);
			return ;
		}
		i++;
	}
}