/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 12:55:12 by jcodina-          #+#    #+#             */
/*   Updated: 2024/02/02 12:57:55 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"

t_operator	*operator_new(char *op)
{
	t_operator	*optr;

	optr = ft_calloc(1, sizeof(t_operator));
	if (optr == NULL)
		return (NULL);
	optr->op = op;
	return (optr);
}

void		operator_print(t_operator *optr)
{
	if (optr == NULL)
		return ;
	ft_printf("Operator: %s\n", optr->op);
}
void		operator_free(t_operator *optr)
{
	if (optr == NULL)
		return ;
	if (optr->op != NULL)
		free(optr->op);
	free(optr);
}
