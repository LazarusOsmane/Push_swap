/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:30:53 by engooh            #+#    #+#             */
/*   Updated: 2022/01/20 05:12:24 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>

typedef struct s_stack {
	struct s_stack	*next;
	int							content;
}	t_stack;

void		ft_push_swap(int ac, char **av);
int			ft_check(int ac, char **av);

t_stack	*ft_stacklast(t_stack *stack);
t_stack	*ft_stack_new(int content);
t_stack	*ft_init_stack(int ac, char **av);

t_stack	*ft_reverse(t_stack **stack, char *flag);
void		ft_stackadd_front(t_stack **alst, t_stack *new);
void		ft_push(t_stack **push, t_stack **recv, char *flag);
int			ft_swap(t_stack **stack, char *flag);
int			ft_rotate(t_stack **stack, char *flag);
void		ft_repeat_rules(t_stack **stack_a, t_stack **stack_b, char *flag);
void		ft_sort(t_stack **stack, int stacklen);
int	ft_mediane_mediane(t_stack *stack, int **tabs, int size, int i);
#endif 
