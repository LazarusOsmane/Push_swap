

typedef struct arbre
{
	  int val;
	  struct arbre *left;
	  struct arbre *rigth;
	  struct arbre *parent;
} t_arbre;

t_arbre ft_new_arbre(int value)
{
	  t_arbre *arb;

	  arb = malloc(sizeof(t_arbre));
	  if (!arb)
		    return (NULL);
	  return (arb);
}
