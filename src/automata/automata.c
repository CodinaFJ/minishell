/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 20:11:46 by jcodina-          #+#    #+#             */
/*   Updated: 2024/05/26 20:27:51 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "automata.h"

void    automata_free(t_automata *automata)
{
    if (automata == NULL)
        return ;
    if (automata->alphabet != NULL)
        ft_strs_free(automata->alphabet);
    if (automata->errors != NULL)
        ft_strs_free(automata->errors);
}
