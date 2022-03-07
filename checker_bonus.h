/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 15:10:14 by engooh            #+#    #+#             */
/*   Updated: 2022/03/07 15:13:26 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "push_swap.h"

int		*get_tab(t_stack *stack, int size);
int		ft_is_sort2(int ac, int *av);
char	*join(char *line, char *buf, int len);
char	*readstd(void);
int		ft_rules(t_stack **a, t_stack **b, char *rsl);
int		checker(int ac, char **av);
#endif 
