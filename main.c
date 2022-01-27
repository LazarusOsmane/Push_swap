/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:40:33 by engooh            #+#    #+#             */
/*   Updated: 2022/01/26 13:00:49 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	main(int ac, char **av)
{
	  t_stack	*a;
	  t_stack	*b;
	  t_stack	*e;

	  a = ft_init_stack(ac, av);
	  b = a;
	  printf("stack a apres ft\n");
	  e = a->prev;
	  while (a)
	  {
		    printf("%d\n", a->content);
		    if (a == e)
				break;
		    a = a->next;
	  }
	  a = b;
	  ft_reverse(&a, "rra\n");
	  ft_reverse(&a, "rra\n");
	  ft_reverse(&a, "rra\n");
	  printf("stack a apres ft\n");
	  e = a->prev;
	  while (a)
	  {
		    printf("%d\n", a->content);
		    if (a == e)
				break;
		    a = a->next;
	  }
	  return (0);
}
