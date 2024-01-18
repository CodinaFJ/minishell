/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:59:56 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/18 22:26:27 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/binary_tree.h"

void	btree_insert(t_btree *btree ,t_btree *node, t_leaf leaf_side)
{
	if (leaf_side == LEFT)
	{
		if (btree->left != NULL)
			btree_free(&(btree->left));
		btree->left = node;
	}
	else if (leaf_side == RIGHT)
	{
		if (btree->right != NULL)
			btree_free(&(btree->left));
		btree->right = node;
	}
}
