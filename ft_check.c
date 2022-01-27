#include "push_swap.h"

int	ft_is_sort(int ac, char **av)
{
	  int	n;
	  int	nbr;

	  while (--ac > 0)
	  {
		    n = ac;
		    nbr = ft_atoi(av[ac]);
		    while (--n > 0)
				if (nbr < ft_atoi(av[n]))
					  return (0);
	  }
	  return (1);
}

int	ft_check(int ac, char **av)
{
	  int		i;
	  long	j;

	  if (ac > 2 && !ft_is_sort(ac, av))
	  {
		    i = 0;
		    while (++i < ac)
		    {
				j = -1;
				while (av[i][++j])
					  if (!ft_isdigit(av[i][j]) && av[i][j] != '-')
						    return (write(2, "Error\n", 6));
				j = i;
				while (++j < ac)
					  if (!ft_strcmp(av[i], av[j]))
						    return (write(2, "Error\n", 6));
				j = ft_atoi(av[i]);
				if (j < INT_MIN || j > INT_MAX)
					  return (write(2, "Error\n", 6));
		    }
	  }
	  else 
		    return (1);
	  return (0);
}
