/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   automata_exp_actions_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcodina- <fjavier.codina@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 19:27:13 by jcodina-          #+#    #+#             */
/*   Updated: 2024/07/20 22:56:39 by jcodina-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../include/minishell.h"

int	strr_find_dollar(t_automata_exp *automata)
{
	int	i;

	i = automata->cursor - 1;
	while (i > 0)
	{
		if (automata->str[i] == '$')
			break ;
		i--;
	}
	return (i);
}

char	*get_var_key(t_automata_exp *automata, int i)
{
	int		var_key_len;
	char	*var_key;

	var_key_len = automata->cursor - i - 1;
	var_key = (char *)ft_calloc(sizeof(char), var_key_len + 1);
	if (var_key == NULL)
		return (NULL);
	ft_strncpy(var_key, automata->str + i + 1, var_key_len);
	return (var_key);
}

char	*ft_str_rmv_index(char *str, const unsigned int index)
{
	unsigned int	i;
	unsigned int	j;
	char			*new_str;

	i = -1;
	j = -1;
	new_str = ft_calloc(1, ft_strlen(str));
	if (new_str == NULL)
		return (NULL);
	while (str[++i])
	{
		if (i == index)
			continue ;
		new_str[++j] = str[i];
	}
	new_str[++j] = 0;
	free(str);
	return (new_str);
}
