/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_automata_exp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:11:59 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/17 18: by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_rc	test_automata_exp_init(void *ctx)
{
	t_rc	rc = RC_OK;
	t_automata_exp	*automata;

	(void)ctx;
	automata = automata_exp_init();
	rc = automata != NULL ? rc : RC_NOK;
	automata_exp_free(automata);
	return(rc);
}

void	test_automata_exp(void *ctx)
{
	ft_printf("\n-------------------------------------------\n");
	ft_printf("TEST AUTOMATA EXPANSER\n\n");

	print_test_res("automata_exp_init", test_automata_exp_init(ctx));

	ft_printf("-------------------------------------------\n");
}
