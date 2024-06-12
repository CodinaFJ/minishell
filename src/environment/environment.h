/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:53:55 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/12 21:52:53 by jcodina-         ###   ########.fr       */
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


/* ************************************************************************** */
/*	Environment																  */
/* ************************************************************************** */

t_list		*environment_create(char **envp);
void		environment_print(t_list *env_list);
char		*environment_get(t_list *env ,char *key);
void		environment_variable_free(void *var);





#endif