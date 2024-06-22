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

/**
 * test_environment_new_variable
 * 
 * test creation of new variable given two strings
 */
static t_rc	test_environment_new_variable(void *ctx)
{
	t_rc	rc = RC_OK;
	t_env_var *env_var = environment_variable_new("FOO", "bar");

	(void) ctx;
	rc = assert_str("FOO", env_var->key);
	rc = assert_str("bar", env_var->content);
	environment_variable_free(env_var);

	env_var = environment_variable_new("FOO", NULL);
	rc = assert_str(env_var->key,"FOO");
	rc = assert_str(env_var->content,"");
	environment_variable_free(env_var);

	env_var = environment_variable_new(NULL, "bar");
	rc = env_var == NULL ? rc : RC_NOK;
	environment_variable_free(env_var);

	env_var = environment_variable_new(NULL, NULL);
	rc = env_var == NULL ? rc : RC_NOK;
	environment_variable_free(env_var);

	env_var = environment_variable_new("", "bar");
	rc = env_var == NULL ? rc : RC_NOK;
	environment_variable_free(env_var);

	env_var = environment_variable_new("FOO", "bar");
	rc = assert_str(env_var->key,"FOO");
	rc = assert_str(env_var->content,"bar");
	environment_variable_free(env_var);
	env_var = environment_variable_new("FOO", "");
	rc = assert_str(env_var->key,"FOO");
	rc = assert_str(env_var->content,"");
	environment_variable_free(env_var);

	return (rc);
}

/**
 * test_wrong_environment_get
 * 
 * test get content from variable of
 * an wrong environment.
 */
static t_rc	test_wrong_environment_get(void *ctx)
{
	t_rc	rc = RC_OK;
	t_list	*env_list;

	(void) ctx;
	env_list = NULL;
	char	*var = environment_get(env_list, "HOME");
	rc = var == NULL ? rc : RC_NOK;
	environment_variable_free(var);

	char	*mock_env[] = {
		"=/home/",
		"USR=",
		"STRING",
		NULL,
	};
	env_list = environment_create(mock_env);
	rc = ft_lstsize(env_list) == 1 ? rc : RC_NOK;
	ft_lstclear(&env_list, environment_variable_free);

	return (rc);
}

/**
 * test_environment_get
 * 
 * test get content from variable of
 * a previously saved environment.
 */
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
	rc =assert_str(env_var->key,"USR");
	rc =assert_str(env_var->content,"javier");
	env_var = (t_env_var *)env_list->next->content;
	rc =assert_str(env_var->key,"HOME");
	rc =assert_str(env_var->content,"/home/");
	
	char	*var = environment_get(env_list, "HOME");
	rc =assert_str(var,"/home/");
	free(var);

	var = environment_get(env_list, "USR");
	rc =assert_str(var,"javier");
	free(var);

	var = environment_get(env_list, "FAKE");
	rc = var == NULL ? rc : RC_NOK;
	free(var);
	ft_lstclear(&env_list, environment_variable_free);
	return (rc);
}

/**
 * test_environment_set
 * 
 * test adding variables to environment.
 */
static t_rc	test_environment_set(void *ctx)
{
	t_rc	rc = RC_OK;
	char	*mock_env[] = {
		"HOME=/home/",
		"USR=javier",
		NULL,
	};
	t_list	*env_list;
	char	*var;

	env_list = environment_create(mock_env);
	(void) ctx;
	if (env_list == NULL || env_list->content == NULL)
	{
		rc = RC_NOK;
		ft_lstclear(&env_list, environment_variable_free);
		return (rc);
	}

	var = environment_get(env_list, "USR");
	rc =assert_str(var,"javier");
	free(var);

	environment_set(env_list, "USR", "paco");
	var = environment_get(env_list, "USR");
	rc =assert_str(var,"paco");
	free(var);

	environment_set(env_list, "FOO", "bar");
	var = environment_get(env_list, "FOO");
	rc =assert_str(var,"bar");
	free(var);

	t_env_var *env_var = (t_env_var *)env_list->content;
	rc =assert_str(env_var->key,"USR");
	rc =assert_str(env_var->content,"paco");
	env_var = (t_env_var *)env_list->next->content;
	rc =assert_str(env_var->key,"HOME");
	rc =assert_str(env_var->content,"/home/");
	env_var = (t_env_var *)env_list->next->next->content;
	rc =assert_str(env_var->key,"FOO");
	rc =assert_str(env_var->content,"bar");

	environment_set(env_list, "BAR", "");
	var = environment_get(env_list, "BAR");
	rc =assert_str(var,"");
	free(var);

	ft_lstclear(&env_list, environment_variable_free);
	return (rc);
}

/**
 * test_environment_unset
 * 
 * test removing variables from environment.
 */
static t_rc	test_environment_unset(void *ctx)
{
	t_rc	rc = RC_OK;
	char	*mock_env[] = {
		"HOME=/home/",
		"USR=javier",
		"FOO=bar",
		NULL,
	};
	t_list	*env_list;

	env_list = environment_create(mock_env);
	(void) ctx;
	if (env_list == NULL || env_list->content == NULL)
	{
		rc = RC_NOK;
		ft_lstclear(&env_list, environment_variable_free);
		return (rc);
	}

	t_env_var *env_var = (t_env_var *)env_list->content;
	rc =assert_str(env_var->key,"FOO");
	rc =assert_str(env_var->content,"bar");
	env_var = (t_env_var *)env_list->next->content;
	rc =assert_str(env_var->key,"USR");
	rc =assert_str(env_var->content,"javier");
	env_var = (t_env_var *)env_list->next->next->content;
	rc =assert_str(env_var->key,"HOME");
	rc =assert_str(env_var->content,"/home/");
	
	environment_unset(&env_list, "USR");
	env_var = (t_env_var *)env_list->content;
	rc =assert_str(env_var->key,"FOO");
	rc =assert_str(env_var->content,"bar");
	env_var = (t_env_var *)env_list->next->content;
	rc =assert_str(env_var->key,"HOME");
	rc =assert_str(env_var->content,"/home/");

	environment_unset(&env_list, "FOO");
	env_var = (t_env_var *)env_list->content;
	rc =assert_str(env_var->key,"HOME");
	rc =assert_str(env_var->content,"/home/");

	environment_unset(&env_list, "HOME");
	rc = ft_lstsize(env_list) == 0 ? rc : RC_NOK;

	ft_lstclear(&env_list, environment_variable_free);
	return (rc);
}
/**
 * test_environment_create
 * 
 * test creation of environment list
 * with a normal environment.
 */
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
	rc =assert_str(env_var->key,"USR");
	rc =assert_str(env_var->content,"javier");
	env_var = (t_env_var *)env_list->next->content;
	rc =assert_str(env_var->key,"HOME");
	rc =assert_str(env_var->content,"/home/");
	ft_lstclear(&env_list, environment_variable_free);
	return (rc);
}

/**
 * test_environment_null_create
 * 
 * test environment_create using a null environment
 * as input.
 */
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

/**
 * test_environment_null_strings_create
 * 
 * test environment_create using an environment
 * with empty strings as input.
 */
static t_rc	test_environment_null_strings_create(void *ctx)
{
	t_rc	rc = RC_OK;
	t_list	*env_list;
	char	*mock_env[] = {
		"",
		"",
		NULL,
	};

	env_list = environment_create(mock_env);
	(void) ctx;
	rc = env_list == NULL ? rc : RC_NOK;
	return (rc);
}

void	test_environment(void *ctx)
{
	ft_printf("\n---------------------------------------------------\n");
	ft_printf("TEST ENVIRONMENT\n\n");
	
	print_test_res("environment_new_variable", test_environment_new_variable(ctx));
	print_test_res("environment_create", test_environment_create(ctx));
	print_test_res("environment_null_create", test_environment_null_create(ctx));
	print_test_res("environment_null_strings_create", test_environment_null_strings_create(ctx));
	print_test_res("environment_get", test_environment_get(ctx));
	print_test_res("wrong_environment_get", test_wrong_environment_get(ctx));
	print_test_res("environment_set", test_environment_set(ctx));
	print_test_res("environment_unset", test_environment_unset(ctx));

	ft_printf("---------------------------------------------------\n");
}