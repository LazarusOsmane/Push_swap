/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:30:53 by engooh            #+#    #+#             */
/*   Updated: 2022/01/26 12:54:40 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_stack {
	struct s_stack	*next;
	struct s_stack	*prev;
	int							content;
}	t_stack;

void		ft_push_swap(int ac, char **av);


int		ft_is_sort(int ac, char **av);
int		ft_check(int ac, char **av);

t_stack	*ft_stacklast(t_stack *stack, t_stack *temp);
t_stack	*ft_stack_new(int content);
t_stack	*ft_init_stack(int ac, char **av);
void		ft_stack_add_front(t_stack **alst, t_stack *new);
void		ft_stack_add_back(t_stack **alst, t_stack *new, t_stack *temp);

void		ft_push(t_stack **push, t_stack **recv, char *flag);
void		ft_swap(t_stack **stack, char *flag);
void		ft_rotate(t_stack **stack, char *flag);
void		ft_reverse(t_stack **stack, char *flag);
void		ft_repeate(t_stack **stack_a, t_stack **stack_b, char *flag);
#endif 
