/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marubio- <marubio-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:41:46 by marubio-          #+#    #+#             */
/*   Updated: 2024/01/27 12:22:40 by marubio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

//no consigo gestionar bien comillas dobles (""hola"" se devuelve como hola"")
void ft_echo(char *args) 
{
    args = args + 4;

    while (*args == ' ')
        args++;

   
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

int main() 
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
