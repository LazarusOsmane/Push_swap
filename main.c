/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:40:33 by engooh            #+#    #+#             */
/*   Updated: 2022/01/28 16:15:09 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*stack_a;

	stack_a = ft_init_stack(ac, av);
	ft_mediane_mediane(ac, stack_a);
	return (0);
}
