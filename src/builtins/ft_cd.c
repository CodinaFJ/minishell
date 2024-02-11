/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marubio- <marubio-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:43:26 by marubio-          #+#    #+#             */
/*   Updated: 2024/02/11 14:23:14 by marubio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void ft_cd(char *args) 
{
    if (args == NULL) 
    {
        ft_printf("cd: missing argument\n");
    } 
    
    else 
    {
        if (chdir(args) != 0) {
            perror("cd");
        }
    }
}