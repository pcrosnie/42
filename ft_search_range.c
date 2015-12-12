#include "fillit.h"

int	ft_search_range(int	n)
{
	int i;

	i = 1;
	while ((i * i) < (n * 4))
		i++;
	return (i + 1);
}

int     ft_check_limits(int *tab)
{
        int n;

        n = ft_search_range(ft_count_pieces(ptr));
        if ((tab[0] + tab[2] > (n - 1)) || (tab[1] + tab[3] > (n - 1)))
                return (0);
        if ((tab[0] + tab[4] > (n - 1)) || (tab[1] + tab[5] > (n - 1)))
                return (0);
        if ((tab[0] + tab[6] > (n - 1)) || (tab[1] + tab[7] > (n - 1)))
                return (0);
        return (1);
}

int	ft_check_same_place(t_noeud *ptr, t_noeud *ptr2)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < 8)
	{
		j = 0;
		while (j < 8)
		{
			if (ptr2->tmp[i] == ptr->coord_piece[j]
				&& ptr2->tmp[i + 1] == ptr->coord_piece[j + 1])
				return (0);
			j += 2;
		}
		i += 2;
	}
	return (1);
}

int	ft_check_position(t_noeud *ptr)
{
	t_noeud *ptr2;

	ptr2 = ptr;
	while (ptr != NULL)
	{
		if (ft_check_same_place(ptr, ptr2) == 0)
			return (0);
		ptr = ptr->prev;
	}
	return (1);
}	

void	ft_increment_i(int *tab, t_noeud *ptr)
{
	int i;

	i = 0;
	while (i < ft_search_range(ft_count_pieces(ptr)))
	{
		ptr->tmp[i]++;
		i += 2;
	}
}	

void	ft_increment_j(t_noeud *ptr)
{
	int j;

	j = 1;
	while (j < ft_search_range(ft_count_pieces(ptr)))
	{
		ptr->tmp[j]++;
		j += 2;
	}
}

void	ft_set_j_to0(t_noeud *ptr, int *tab)
{
	int j;

	j = 1;
	while (j < 8)
	{
		ptr->tmp[j] = tab[j];
		j += 2;
	}
}

struct s_noeud	*ft_new_position(t_noeud *ptr)
{
	

void	ft_def_position(t_noeud *ptr, int **tab)
{
	int n;
	int j;
	int i;
	int index;

	i = 0;
	index = 0;
	ptr->tmp = tab[ptr->etape + 1]; 
	n = ft_search_range(ft_count_pieces(ptr));
	while (i < n)
	{
		j = 0;
		ft_set_j_to0(ptr, tab[ptr->etape + 1]);
		while (j < n)
		{
			if (ft_check_position(ptr, tab[ptr->etape + 1]) == 1 && ft_check_limit(tab[ptr->etape + 1]))
			{
				ptr->next[index++] = ft_new_position(ptr);
				ptr->next[index - 1]->prev = ptr;
			}
			ft_increment_j(ptr);
			j++;
		}
		ft_increment_i(ptr);
		i++;
	}
}
