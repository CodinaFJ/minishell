/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:53:55 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/19 20:46:38 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
# include "../../lib/libft/include/libft.h"

typedef struct s_environment_variable
{
	char	*key;
	char	*content;
}	t_env_var;

/* ************************************************************************** */
/*	Variables																  */
/* ************************************************************************** */

t_env_var	*environment_variable_parse(char *env_str);
void		environment_variable_print(t_env_var *var);
t_env_var	*environment_variable_new(char *key, char *content);
void		environment_set(t_list *env, char *key, char *content);
void		environment_unset(t_list **env, char *key);


/* ************************************************************************** */
/*	Environment																  */
/* ************************************************************************** */

t_list		*environment_create(char **envp);
void		environment_print(t_list *env_list);
char		*environment_get(t_list *env ,char *key);
void		environment_variable_free(void *var);





#endif