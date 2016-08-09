/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 17:17:12 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/08/08 12:58:45 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

char	*re_malloc(char *line, size_t size)
{
	char				*tmp;

	tmp = ft_strnew(size + 50);
	if (size > 0)
	{
		tmp = ft_strcpy(tmp, line);
	}
	return (tmp);
}

char	***re_3d_malloc(char ***arr, size_t size)
{
	char	***temp;
	int		cnt;

	cnt = 0;
	temp = (char ***)malloc(sizeof(char **) * (size + 10));
	while (temp[cnt])
	{
		temp[cnt] = NULL;
		cnt++;
	}
	cnt = 0;
	if (size > 0)
	{
		while (arr[cnt] && arr[cnt] != NULL)
		{
			temp[cnt] = arr[cnt];
			cnt++;
		}
	}
	return (temp);
}
