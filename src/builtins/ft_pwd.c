/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:43:01 by marubio-          #+#    #+#             */
/*   Updated: 2024/01/31 20:35:21 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

#include "builtin.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// TODO: lo del buffer[256] hay que arreglarlo
void ft_pwd(char *args) 
{
    char cwd[256];

    (void) args;
    ft_printf("pwd called\n");
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s\n", cwd);
    } else {
        perror("getcwd() error");
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
        else if (strcmp(input, "pwd") == 0)
            ft_pwd();
    }

    return (0);
}*/