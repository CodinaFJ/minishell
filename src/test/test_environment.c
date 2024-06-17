/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_environment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 19:16:55 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/17 19:22:46y jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

static t_rc	test_environment_get(void *ctx)
{
	t_rc	rc = RC_OK;
	char	*mock_env[] = {
		"HOME=/home/",
		"USR=javier",
		NULL,
	};
	t_list	*env_list;

	env_list = environment_create(mock_env);
	(void) ctx;
	if (env_list == NULL || env_list->content == NULL)
	{
		rc = RC_NOK;
		return (rc);
	}
	t_env_var *env_var = (t_env_var *)env_list->content;
	rc = ft_strcmp("HOME", env_var->key) == 0 ? rc : RC_NOK;
	rc = ft_strcmp("/home/", env_var->content) == 0 ? rc : RC_NOK;
	env_var = (t_env_var *)env_list->next->content;
	rc = ft_strcmp("USR", env_var->key) == 0 ? rc : RC_NOK;
	rc = ft_strcmp("javier", env_var->content) == 0 ? rc : RC_NOK;
	
	char	*var = environment_get(env_list, "HOME");
	rc = ft_strcmp("/home/", var) == 0 ? rc : RC_NOK;

	var = environment_get(env_list, "USR");
	rc = ft_strcmp("javier", var) == 0 ? rc : RC_NOK;
	free(var);

	var = environment_get(env_list, "FAKE");
	rc = var == NULL ? rc : RC_NOK;
	free(var);
	ft_lstclear(&env_list, environment_variable_free);
	return (rc);
}

static t_rc	test_environment_create(void *ctx)
{
	t_rc	rc = RC_OK;
	char	*mock_env[] = {
		"HOME=/home/",
		"USR=javier",
		NULL,
	};
	t_list	*env_list;

	env_list = environment_create(mock_env);
	(void) ctx;
	if (env_list == NULL || env_list->content == NULL)
	{
		rc = RC_NOK;
		return (rc);
	}
	t_env_var *env_var = (t_env_var *)env_list->content;
	rc = ft_strcmp("HOME", env_var->key) == 0 ? rc : RC_NOK;
	rc = ft_strcmp("/home/", env_var->content) == 0 ? rc : RC_NOK;
	env_var = (t_env_var *)env_list->next->content;
	rc = ft_strcmp("USR", env_var->key) == 0 ? rc : RC_NOK;
	rc = ft_strcmp("javier", env_var->content) == 0 ? rc : RC_NOK;
	ft_lstclear(&env_list, environment_variable_free);
	return (rc);
}


static t_rc	test_environment_null_create(void *ctx)
{
	t_rc	rc = RC_OK;
	char	**mock_env; 
	t_list	*env_list;

	mock_env = NULL;
	env_list = environment_create(mock_env);
	(void) ctx;
	rc = env_list == NULL ? rc : RC_NOK;
	return (rc);
}

void	test_environment(void *ctx)
{
	ft_printf("\n-------------------------------------------\n");
	ft_printf("TEST ENVIRONMENT\n\n");
	
	print_test_res("environment_create", test_environment_create(ctx));
	print_test_res("environment_null_create", test_environment_null_create(ctx));
	print_test_res("environment_get", test_environment_get(ctx));

	ft_printf("-------------------------------------------\n");
}