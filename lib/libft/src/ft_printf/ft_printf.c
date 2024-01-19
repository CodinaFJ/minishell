/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:28:20 by marubio-          #+#    #+#             */
/*   Updated: 2024/01/19 17:32:25 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*								By: marubio-								*/

#include "../../includes/ft_printf.h"

int	data_type(const char *type, int i, va_list ap)
{
	if (type[i + 1] == 'c')
		return (ft_char(va_arg(ap, int)));
	if (type[i + 1] == 's')
		return (ft_str(va_arg(ap, char *)));
	if (type[i + 1] == 'p')
		return (ft_pointer(va_arg(ap, unsigned long long)));
	if (type[i + 1] == 'i' || type[i + 1] == 'd')
		return (ft_numb(va_arg(ap, int)));
	if (type[i + 1] == 'u')
		return (ft_unsigned(va_arg(ap, unsigned int)));
	if (type[i + 1] == 'x')
		return (ft_print_hex(va_arg(ap, unsigned int), 'x'));
	if (type[i + 1] == 'X')
		return (ft_print_hex(va_arg(ap, unsigned int), 'X'));
	if (type[i + 1] == '%')
		return (ft_char(type[i + 1]));
	return (0);
}

int	ft_printf(char const *type, ...)
{
	va_list	ap;
	int		i;
	int		h;

	i = 0;
	h = 0;
	va_start(ap, type);
	while (type[i])
	{
		if (type[i] == '%' && ft_strchr_pf("cspdiuxX%", type[i + 1]))
		{
			h += data_type(type, i, ap);
			i++;
		}
		else
			h += ft_char(type[i]);
		i++;
	}
	va_end(ap);
	return (h);
}
// int main() {
//   double num;
//   num = 55.32;
//   ft_printf(" %c %x %x %x %x %x %x", 'c', INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
//   return 0;
// }