/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 11:29:41 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/08/16 13:22:59 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	ft_char(char *str, char c)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			j++;
		i++;
	}
	return (j);
}

static void			split_main(t_split *sp, char *temp, char **split, char c)
{
	while (temp[sp->j] != '\0' && temp[sp->j])
	{
		sp->k = sp->j;
		while (temp[sp->k] != c && temp[sp->k] != '\0')
		{
			sp->k++;
		}
		split[sp->i] = ft_strnew(sp->k - sp->j);
		sp->k = sp->j;
		sp->l = 0;
		while (temp[sp->k] != c && temp[sp->k] != '\0')
		{
			split[sp->i][sp->l] = temp[sp->k];
			sp->k++;
			sp->l++;
		}
		split[sp->i][sp->l] = '\0';
		sp->j = sp->k;
		sp->i++;
		sp->j++;
	}
}

char				**ft_strsplit(char *str, char c)
{
	char	*temp;
	char	**split;
	t_split	sp;

	if (str == NULL)
		return (NULL);
	sp.j = 0;
	temp = rm_padding(str);
	if (temp == NULL)
		return (NULL);
	sp.i = ft_char(temp, c);
	split = ft_strnew2(sp.i + 2);
	sp.i = 0;
	split_main(&sp, temp, split, c);
	split[sp.i] = "\0";
	return (split);
}
