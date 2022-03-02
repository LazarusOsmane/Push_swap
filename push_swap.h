/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:30:53 by engooh            #+#    #+#             */
/*   Updated: 2022/03/01 14:23:03 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_stack
{
	int				val;
	int				index;
	int				len;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void		ft_sort_tree(t_stack **stack);
int			ft_big_sort(t_stack **s, int len, int *tab);
void		ft_sort_five(t_stack **stack_a, t_stack **stack_b);

int			*ft_sort_in_tab(int *tab, int size);
void		ft_val_top(t_stack **s, int a, int b, int *tab);
void		ft_sort_five(t_stack **stack_a, t_stack **stack_b);
int			*ft_get_better_index(t_stack *a, t_stack *b, int *res);
int			*ft_get_stack_info(int size, t_stack *stack, int flag);
void		ft_push_min_nbr(t_stack **stack_a, t_stack **stack_b, int len);

int			ft_check(int ac, char **av);
int			ft_is_sort(int ac, char **av);
void		ft_pres_sort(t_stack **stack_a, t_stack **stack_b);

int			ft_stacklen(t_stack *stack);
void		ft_delstack(t_stack *stack, t_stack *tmp);
void		ft_stack_add_front(t_stack **alst, t_stack *new);
void		ft_stack_add_back(t_stack **alst, t_stack *new, t_stack *temp);

void		ft_swap(t_stack **stack, char *flag);
void		ft_rotate(t_stack **stack, char *flag);
void		ft_reverse(t_stack **stack, char *flag);
void		ft_push(t_stack **push, t_stack **recv, char *flag);
void		ft_repeate(t_stack **stack_a, t_stack **stack_b, char *flag);

t_stack		*ind(t_stack*stack, int index);
t_stack		*ft_init_stack(int ac, char **av);
t_stack		*ft_stack_new(int content, int index);
t_stack		*ft_stacklast(t_stack *stack, t_stack *temp);
#endif 
