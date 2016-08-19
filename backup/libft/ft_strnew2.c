/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 09:31:52 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/08/16 13:48:37 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strnew2(size_t size)
{
	char	**str;
	size_t	i;

	i = 0;
	if (size == 0)
	{
		ft_putstr(E_MESS02);
		return (NULL);
	}
	str = (char **)malloc(sizeof(char*) * size);
	while (i < size)
	{
		str[i] = "\0";
		i++;
	}
	return (str);
}
