/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:53:55 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/26 14:32:19 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENVIRONMENT_H
# define ENVIRONMENT_H
# include "../../lib/libft/include/libft.h"

typedef struct s_environment_variable
{
	char	*key;
	char	*content;
}			t_env_var;

/* ************************************************************************** */
/*	Variables																	*/
/* ************************************************************************** */

t_env_var	*environment_variable_parse(char *env_str);
void		environment_variable_print(t_env_var *var);
void		environment_variable_free(void *var);
t_env_var	*environment_variable_new(char *key, char *content);
int			environment_variable_cmp(void *var1, void *var2);

/* ************************************************************************** */
/*	Environment	operations																*/
/* ************************************************************************** */

char		*environment_get(t_list *env, char *key);
void		environment_set_keycontent(t_list *env, char *key, char *content);
void		environment_set_str(t_list *env, char *str);
void		environment_unset(t_list **env, char *key);

/* ************************************************************************** */
/*	Environment																	*/
/* ************************************************************************** */

t_list		*environment_create(char **envp);
void		environment_free(t_list **env);
void		environment_print(t_list *env);

#endif