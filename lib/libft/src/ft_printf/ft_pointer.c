/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:16:48 by marubio-          #+#    #+#             */
/*   Updated: 2024/01/19 17:32:41 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*								By: marubio-								*/

#include "../../includes/ft_printf.h"

int	ft_pointer(unsigned long long n)
{
	int	len;

	len = 0;
	len += ft_str("0x");
	if (n == 0)
	{
		len += ft_char('0');
		return (len);
	}
	len += ft_print_hex(n, 'p');
	return (len);
}
