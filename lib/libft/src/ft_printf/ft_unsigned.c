/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 14:34:21 by marubio-          #+#    #+#             */
/*   Updated: 2024/01/19 17:37:48 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*								By: marubio-								*/

#include "../../includes/ft_printf.h"

int	ft_unsigned(unsigned long long n)
{		
	char	un;
	int		len;

	len = 0;
	un = (n % 10) + '0';
	n = (n / 10);
	if (n != 0)
		len += ft_numb(n);
	len += write(1, &un, 1);
	return (len);
}
