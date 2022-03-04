/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:33:44 by engooh            #+#    #+#             */
/*   Updated: 2022/03/04 20:53:35 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"



int ft_rules(t_stack **a, t_stack **b, char *rsl)
{
	if (!ft_strcmp(rsl, "ra\n"))
		return (ft_rotate(a, ""));
	else if (!ft_strcmp(rsl, "rb\n"))
		return (ft_rotate(b, ""));
	else if (!ft_strcmp(rsl, "sa\n"))
		return (ft_swap(a, ""));
	else if (!ft_strcmp(rsl, "sb\n"))
		return (ft_swap(b, ""));
	else if (!ft_strcmp(rsl, "pa\n"))
		return (ft_push(b, a,""));
	else if (!ft_strcmp(rsl, "pb\n"))
		return (ft_push(a, b,""));
	else if (!ft_strcmp(rsl, "rra\n"))
		return (ft_reverse(a,""));
	else if (!ft_strcmp(rsl, "rrb\n"))
		return (ft_reverse(b,""));
	else if (!ft_strcmp(rsl, "rrr\n"))
		return (ft_reverse(a,"") + ft_reverse(b, ""));
	else if (!ft_strcmp(rsl, "ss\n"))
		return (ft_swap(a,"") + ft_swap(b, ""));
	return (0);
}
