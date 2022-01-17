#include "push_swap.h"

void    ft_stack_add_front(t_stack **alst, t_stack *new)
{
	  new->next = &(**alst);
	  *alst = new;
}

t_stack  *ft_stacklast(t_stack *stack)
{
	  if (stack && stack->next)
		    return (ft_stacklast(stack->next));
	  return (stack);
}

t_stack	*ft_stack_new(int content)
{
	  t_stack	*p;

	  p = malloc(sizeof(t_stack));
	  if (!p)
		    return (NULL);
	  p->next = NULL;
	  p->content = content;
	  return (p);
}

t_stack *ft_init_stack(int ac, char **av)
{
	  t_stack	*stack;

	  if (ft_check(ac, av))
		    return (NULL);
	  stack = ft_stack_new(ft_atoi(av[--ac]));
	  while (--ac > 0)
		    ft_stack_add_front(&stack, ft_stack_new(ft_atoi(av[ac])));
	  return(stack);
}
