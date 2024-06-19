/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_automata_lexer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:11:57 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/19 21:21:07 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

/**
 * test_automata_lexer_init
 * 
 * test initialization of automata
 * lexer
 */
t_rc	test_automata_lexer_init(void *ctx)
{
	t_rc	rc = RC_OK;
	t_automata_lexer	*automata;

	(void)ctx;
	automata = automata_lexer_init();
	rc = automata != NULL ? rc : RC_NOK;
	rc = automata->alphabet != NULL ? rc : RC_NOK;
	rc = ft_strs_rows((const char **) automata->alphabet) != 0 ? rc : RC_NOK;
	rc = automata->errors != NULL ? rc : RC_NOK;
	automata_lexer_free(automata);
	return(rc);
}

void	test_automata_lexer(void *ctx)
{
	ft_printf("\n---------------------------------------------------\n");
	ft_printf("TEST AUTOMATA LEXER\n\n");

	print_test_res("automata_lexer_init", test_automata_lexer_init(ctx));

	ft_printf("---------------------------------------------------\n");
}
