/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:55:54 by marubio-          #+#    #+#             */
/*   Updated: 2024/01/19 17:32:16 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*								By: marubio-								*/

#include "../../includes/ft_printf.h"

void	ft_hexa(unsigned long long n, char type)
{
	if (n >= 16)
	{
		ft_hexa(n / 16, type);
		ft_hexa(n % 16, type);
	}
	else
	{
		if (n <= 9)
			ft_char(n + '0');
		else
		{
			if (type == 'x' || type == 'p')
				ft_char(n - 10 + 'a');
			if (type == 'X')
				ft_char(n - 10 + 'A');
		}
	}
}

int	ft_strlen_for_hexa(unsigned long long n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		len++;
		n = n / 16;
	}
	return (len);
}

int	ft_print_hex(unsigned long long n, const char type)
{
	if (n == 0)
		return (write(1, "0", 1));
	else
		ft_hexa(n, type);
	return (ft_strlen_for_hexa(n));
}
