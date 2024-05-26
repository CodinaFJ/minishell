/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:19:35 by marubio-          #+#    #+#             */
/*   Updated: 2024/05/26 20:23:16 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//! lo del  extern char **environ; no se si es legal
void ft_env(void *ctx) 
{
    char *args;
    extern char **environ;
    char **env = environ;
    
    args = (char *) ctx;
    ft_printf("env called\n");
    (void) args;
    while (*env != NULL) 
    {
        printf("%s\n", *env);
        env++;
    }
}

/*int main() 
{
    char input[256];

    while (1) 
    {
        printf("MiShell> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
            break;
        else if (strcmp(input, "env") == 0)
            ft_env();
    }

    return (0);
}
*/
