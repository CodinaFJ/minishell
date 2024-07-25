/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:41:46 by marubio-          #+#    #+#             */
/*   Updated: 2024/07/25 22:20:12 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include <stdio.h>
#include <string.h>

// TODO: no consigo gestionar bien comillas dobles (""hola"" se devuelve como hola"")
void ft_echo(void *command ,void *ctx) 
{
    char *args;
    
	(void) command;
    args = (char *) ctx;
    args = args + 4;

    while (*args == ' ')
        args++;

    ft_printf("Echo called\n");
    if (*args == '\0') 
	{
        printf("\n");
        return;
    }

    int omitNewline = 0;
    while (strncmp(args, "-n", 2) == 0) 
	{
        omitNewline = 1;
        args = args + 2;

        while (*args == ' ')
            args++;
    }

    while (*args != '\0') 
	{
        while (*args == ' ') 
            args++;

        if (*args == '"' || *args == '\'') 
		{
            char quote = *args;
            args++;  
            while (*args != '\0') 
			{
                if (*args == quote) 
				{
                    args++;
                    break;
                }
                printf("%c", *args);
                args++;
            }
        } 
		else 
		{
            while (*args != '\0' && *args != ' ') 
			{
                printf("%c", *args);
                args++;
            }
        }
        if (*args != '\0')
		    printf(" ");
    }

    if (!omitNewline)
        printf("\n");
}

/*int main() 
{
    char input[256];

    while (1) {
        printf("MiShell> ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
            break;
        else if (strcmp(input, "echo") == 0)
            ft_echo(input);
        else if (strncmp(input, "echo ", 5) == 0)
            ft_echo(input);
    }
    return (0);
}
*/