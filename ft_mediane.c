/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mediane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 18:46:16 by engooh            #+#    #+#             */
/*   Updated: 2022/01/26 19:44:07 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	**ft_create_tabs(int ac, char **av, int size)
{
	int	i;
	int	**tabs;

	tabs = malloc(sizeof(int	*) * (size + 1));
	if (!tabs)
		return (NULL);
	while (size)
	{
		i = 5;
		tabs[size] = malloc(sizeof(int) * 5);
		if (tabs[size])
			return (NULL);
		while (--i && --ac > 0)
		{
			tabs[size][i] = ft_atio(av[ac]); 
		}
	}
	return (tabs);
}
