/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_list_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdebruyn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 09:17:11 by cdebruyn          #+#    #+#             */
/*   Updated: 2016/08/18 13:45:42 by cdebruyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/rtv1.h"

t_light		*ft_light_new(t_vec *pos, t_col *intensity)
{
	t_light		*temp;

	temp = (t_light *)malloc(sizeof(t_light));
	if (temp == NULL)
		return (NULL);
//	if (pos == NULL)
//		temp->pos = NULL;
//	if (intensity == NULL)
//		temp->intensity = 0;
	if (pos != NULL)
	{
		temp->pos = *pos;
		temp->next = NULL;
	}
	if (intensity != NULL)
	{
		temp->intensity = *intensity;
		temp->next = NULL;
	}
	return (temp);
}

void	ft_light_add(t_light **alst, t_light *new)
{
		new->next = *alst;
		*alst = new;
}
