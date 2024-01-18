/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:18:58 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/18 22:34:17 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/binary_tree.h"

int	main(int argc, char **argv)
{
	(void) argc;
	(void) argv;

	t_btree *btree = btree_new("Un nodo");

	btree_insert(btree, btree_new("Otro nodo"), LEFT);
	btree_insert(btree, btree_new("Nodo derecha"), RIGHT);
	btree_insert(btree->left, btree_new("Otro nodo 2"), RIGHT);
	btree_insert(btree->left, btree_new("Otro nodo 3"), LEFT);
	btree_print(btree, "O");
	btree_free(&btree);
	return (0);
}