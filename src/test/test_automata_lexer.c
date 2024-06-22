/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_automata_lexer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 17:11:57 by jcodina-          #+#    #+#             */
/*   Updated: 2024/06/22 16:07:01 by jcodina-         ###   ########.fr       */
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
	rc = assert(automata != NULL);
	rc = assert(automata->alphabet != NULL);
	rc = assert(ft_strs_rows((const char **) automata->alphabet) != 0);
	rc = assert(automata->errors != NULL);
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
