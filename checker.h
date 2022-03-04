/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engooh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:29:32 by engooh            #+#    #+#             */
/*   Updated: 2022/03/04 17:51:25 by engooh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "push_swap.h"

char	*read_output(void);
int		ft_rules(t_stack **a, t_stack **b, char *rsl);
int		checker(int ac, char **av);
#endif 
