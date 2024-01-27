/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marubio- <marubio-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 12:19:35 by marubio-          #+#    #+#             */
/*   Updated: 2024/01/27 12:21:24 by marubio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//lo del  extern char **environ; no se si es legal
void ft_env(void) 
{
    extern char **environ;
    char **env = environ;

    while (*env != NULL) 
    {
        printf("%s\n", *env);
        env++;
    }
}

int main() 
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

