/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <jcodina-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 21:37:49 by jcodina-          #+#    #+#             */
/*   Updated: 2024/01/18 22:30:49 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/binary_tree.h"

t_btree	*btree_new(char *content)
{
	t_btree	*btree;

	btree = ft_calloc(1, sizeof(t_btree));
	if (btree == NULL)
		return (NULL);
	ft_bzero(btree, sizeof(t_btree));
	btree->content = ft_strdup(content);
	btree->left = NULL;
	btree->right = NULL;
	return (btree);	
}

void	btree_free(t_btree **btree)
{
	if (*btree == NULL)
		return ;
	if ((*btree)->content != NULL)
		free((*btree)->content);
	if ((*btree)->left != NULL)
		btree_free(&(*btree)->left);
	if ((*btree)->right != NULL)
		btree_free(&(*btree)->right);
	free(*btree);
	*btree = NULL;
}

void	btree_print(t_btree *btree, char *level)
{
	ft_printf("[%s] -> %s\n", level, btree->content);
	if (btree->left != NULL)
		btree_print(btree->left, ft_strjoin(level, "l"));
	if (btree->right != NULL)
		btree_print(btree->right, ft_strjoin(level, "r"));
}

void	btree_clear(t_btree *btree)
{
	if (btree->content != NULL)
		free(btree->content);
	if (btree->left != NULL)
		btree_clear(btree->left);
	if (btree->right != NULL)
		btree_clear(btree->right);
}

t_btree	*btree_dup(t_btree *btree)
{
	t_btree	*new_btree;
	t_bool	error;

	error = false;
	new_btree = btree_new(btree->content);
	if (new_btree == NULL)
		return (NULL);
	if (btree->left != NULL)
	{
		new_btree->left =  btree_dup(btree->left);
		if (new_btree->left == NULL)
			error = true;
	}
	if (btree->right != NULL)
	{
		new_btree->right =  btree_dup(btree->right);
		if (new_btree->right == NULL)
			error = true;
	}
	if (error)
		btree_free(&new_btree);
	return (new_btree);
}
