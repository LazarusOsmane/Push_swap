/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:30:53 by engooh            #+#    #+#             */
/*   Updated: 2022/02/13 19:56:14 by lazarus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_stack {
	int							content;
	int							index;
	struct s_stack	*next;
	struct s_stack	*prev;
}		t_stack;

typedef struct b_arbre
{
	int			val;
	struct b_arbre	*un;
	struct b_arbre	*de;
	struct b_arbre	*parent;
}	t_arbre;

void		ft_push_swap(int ac, char **av);
int		ft_big_sort(t_stack **a, t_stack **b);
int		*ft_get_stack_info(int size, t_stack *stack, int flag);
int		*ft_sort_in_tab(int *tab, int size);
void		ft_little_sort(t_stack **stack_a, t_stack **stack_b, int size);
void		ft_sort_five(t_stack **stack_a, t_stack **stack_b);
t_stack	*ft_init_stack(int ac, char **av);
int		ft_is_sort(int ac, char **av);
int		ft_check(int ac, char **av);
void		ft_pres_sort(t_stack **stack_a, t_stack **stack_b);

void		reind(t_stack *stack);
int		ft_stacklen(t_stack *stack);
void		ft_stack_add_front(t_stack **alst, t_stack *new);
void		ft_stack_add_back(t_stack **alst, t_stack *new, t_stack *temp);
void		ft_delstack(t_stack *stack, t_stack *tmp);

void		ft_push(t_stack **push, t_stack **recv, char *flag);
void		ft_swap(t_stack **stack, char *flag);
void		ft_rotate(t_stack **stack, char *flag);
void		ft_reverse(t_stack **stack, char *flag);
void		ft_repeate(t_stack **stack_a, t_stack **stack_b, char *flag);



void		ft_print_stack(t_stack *stack_a, char flag);
int		*ft_get_better_index(t_stack *a, t_stack *b, int *res);
int		ft_get_majoran(int val, t_stack *s);
t_stack	*ind(t_stack*stack, int index);
t_stack	*ft_stacklast(t_stack *stack, t_stack *temp);
t_stack	*ft_stack_new(int content, int index);
t_stack	*ft_init_stack(int ac, char **av);
void		ft_position_theorique(t_arbre **arb);	
void		ft_delarbre(t_arbre *arb);
void		ft_addnode(t_arbre **arb, t_arbre *new);
t_arbre	*ft_new_node(int value);
int		ft_init_arbre(t_stack *stk, t_stack *index, t_arbre *arb, int max);
//int		ft_val_to_top(t_stack *stack, int size, int i);
#endif 
