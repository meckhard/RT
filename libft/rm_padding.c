/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rmpadding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 09:08:32 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/08/16 12:50:00 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	first_padding(char *str, unsigned int *i)
{
	unsigned int j;

	j = *i;
	if (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')
	{
		while (str[j] == ' ' || str[j] == '\t' || str[j] == '\n')
			j++;
	}
	*i = j;
}

static char	*centre_padding(char *str, unsigned int *j)
{
	unsigned int	i;

	i = *j;
	if ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && \
			(str[i + 1] == ' ' || str[i + 1] == '\t' || \
			str[i + 1] == '\n'))
	{
		while ((str[i] == ' ' || str[i] == '\t' || str[i] == '\n') && \
				(str[i + 1] == ' ' || str[i + 1] == '\t' || \
				str[i + 1] == '\n'))
		{
			i++;
		}
		if (str[i] == '\t' || str[i] == '\n')
			str[i] = ' ';
	}
	*j = i;
	return (str);
}

char		*rm_padding(char *str)
{
	char			*temp;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (str == NULL)
		return (NULL);
	temp = (char *)malloc(sizeof(char) * ft_strlen(str));
	first_padding(str, &i);
	if (str[i] == '\0')
		return (NULL);
	while (str[i] != '\0' && str[i])
	{
		centre_padding(str, &i);
		temp[j] = str[i];
		i++;
		j++;
	}
	if (temp[j - 1] == ' ' && (j - 1) != 0)
		temp[j - 1] = '\0';
	temp[j] = '\0';
	return (temp);
}
