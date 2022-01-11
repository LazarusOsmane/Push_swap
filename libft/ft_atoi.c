/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <erickngooh.1@gmail.com>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 22:43:15 by engooh            #+#    #+#             */
/*   Updated: 2022/01/11 20:00:10 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

long	ft_atoi(const char *nptr)
{
	long int	n;

	n = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
		{
			while (ft_isdigit(*nptr))
			{
				n = (n * 10) - (*nptr++ - '0');
			}
		}
	}
	while (ft_isdigit(*nptr))
	{
		n = (n * 10) + (*nptr++ - '0');
	}
	return (n);
}
