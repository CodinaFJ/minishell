/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:16:28 by marubio-          #+#    #+#             */
/*   Updated: 2024/01/19 17:32:20 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*								By: marubio-								*/

#include "../../includes/ft_printf.h"

int	ft_numb(int n)
{	
	char	un;
	int		len;

	len = 0;
	if (n >= 0)
	{
		un = (n % 10) + '0';
		n = (n / 10);
		if (n != 0)
			len += ft_numb(n);
		len += write(1, &un, 1);
	}
	else
	{
		un = (n % 10) * -1 + '0';
		n = (n / 10);
		if (n != 0)
			len += ft_numb(n);
		else
			len += write(1, "-", 1);
		len += write(1, &un, 1);
	}
	return (len);
}
