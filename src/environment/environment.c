/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:53:32 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/17 20:18:21 jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"

t_list	*environment_create(char **envp)
{
	int			i;
	t_list		*env_list;
	t_env_var	*env_var_aux;

	if (envp == NULL)
		return (NULL);
	env_list = NULL;
	env_var_aux = NULL;
	i = -1;
	while(envp[++i])
	{
		env_var_aux = environment_variable_parse(envp[i]);
		if (env_var_aux == NULL)
			continue ;
		ft_lstadd_front(&env_list, ft_lstnew((void *) env_var_aux));        
	}
	return (env_list);
}

void	environment_print(t_list *env)
{
	while (env)
	{
		if (env == NULL)
			continue; ;
		environment_variable_print(env->content);
		env = env->next;
	}
}

void	environment_free(t_list **env)
{
	ft_lstclear(env, environment_variable_free);
}