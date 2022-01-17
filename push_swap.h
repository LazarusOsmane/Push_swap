/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:30:53 by engooh            #+#    #+#             */
/*   Updated: 2022/01/17 01:26:32 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack {
	  int	content;
	  struct s_stack *next;
}	t_stack;

void		ft_push_swap(int ac, char **av);
int		ft_check(int ac, char **av);

t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stack_new(int content);
t_stack	*ft_init_stack(int ac, char **av);

void		ft_stackadd_front(t_stack **alst, t_stack *new);
void		ft_push(t_stack **push, t_stack **recv, char *flag);
void		ft_swap(t_stack **stack, char *flag);
void		ft_rotate(t_stack **stack, char *flag);
#endif 
