#include "push_swap.h"


void print_arbre(t_arbre *arb)
{
	  if (!arb)
	  {
		    print_arbre(arb->de);
		    printf("%d\n", arb->val);
		    print_arbre(arb->un);
	  }
}

t_arbre *ft_new_node(int value)
{
	  t_arbre	*new;

	  new = malloc(sizeof(t_arbre));
	  if (!new)
		    return (NULL);
	  new->un = NULL;
	  new->de = NULL;
	  new->val = value;
	  new->parent = NULL;
	  return (new);
}

int ft_arbrelen(t_arbre *arb)
{
	  if (!arb)
		    return (0);
	  else 
		    return (ft_arbrelen(arb->un) + 1 + ft_arbrelen(arb->de));
}

void	ft_free_arbre(t_arbre *arb)
{
	  if (!arb)
		    return ;
	  ft_free_arbre(arb->un);
	  ft_free_arbre(arb->de);
	  free(arb);
}

t_arbre	*ft_add_node(t_arbre **arb, int value, int flag)
{
	  if (!*arb)
		    return (ft_new_node(value));
	  else if ((*arb)->val > value && flag)
		    (*arb)->un = ft_add_node(&(*arb)->un, value, flag);
	  else if ((*arb)->val > value && !flag)
	  {
		    (*arb)->un = ft_new_node(value);
		    return (NULL);
	  }
	  else if ((*arb)->val < value)
		    (*arb)->de = ft_add_node(&(*arb)->de, value, flag);
	  return (*arb);
}

int	ft_init_arbre(t_stack *stk, t_stack *index, t_arbre *arb, int max)
{
	  int	    len;
	  t_arbre *res;
	  t_stack *end;
	  t_stack *tmp;
	  t_arbre s;

	  end = stk->prev;
	  if (index != end)
	  {

		    res = &s;
		    tmp = index;
		    while (tmp != end && res)
		    {
				res = ft_add_node(&arb, tmp->content, 0);
				tmp = tmp->next;
		    }
		    len = ft_arbrelen(arb);
		    print_arbre(arb);
		    if (max < len)
				max = len;
		    max = ft_init_arbre(stk, stk->next, arb, max);
		    if (max == len)
				max = index->content;
	  }
	  return (max);
}
