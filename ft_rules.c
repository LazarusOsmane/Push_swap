#include "push_swap.h"

void ft_push(t_stack **push, t_stack **recv, char *flag) 
{
	  t_stack *swap;

	  if (!(*push))
		    return ;
	  swap = *push;
	  *push = (*push)->next;
	  swap->next = NULL;
	  if (*recv)
		    swap->next = *recv; 
	  *recv = swap;
	  ft_putstr_fd(flag, 1);
}

void ft_swap(t_stack **stack, char *flag)
{
	  t_stack *temp;

	  if (!((*stack)->next))
		    return ;
	  temp = *stack;
	  *stack = (*stack)->next;
	  temp->next = (*stack)->next;
	  (*stack)->next = temp;
	  ft_putstr_fd(flag, 1);
}

void	ft_rotate(t_stack **stack, char *flag)
{
	  t_stack	*temp;

	  temp = ft_stacklast(*stack)->next;
	  temp = &(**stack);
	  *stack = (*stack)->next;
	  temp->next = NULL;
	  ft_putstr_fd(flag, 1);
}
