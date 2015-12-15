#include "fillit.h"

int	ft_search_range(int	n)
{
	int i;

	i = 1;
	while ((i * i) < (n * 4))
		i++;
	return (i + 1);
}

int     ft_check_limits(int *tab, int n)
{
        if ((tab[0] + tab[2] > n) || (tab[1] + tab[3] > n))
                return (0);
        if ((tab[0] + tab[4] > n) || (tab[1] + tab[5] > n))
                return (0);
        if ((tab[0] + tab[6] > n) || (tab[1] + tab[7] > n))
                return (0);
        return (1);
}

int		ft_check_overlap(int *tmp, t_noeud *ptr)
{
	t_noeud *ptr2;

	pt2 = ptr;
	while (ptr != NULL)
	{
		

void	ft_fill_next(t_noeud *ptr, int nb)
{
	int		i;
	int		j;
	int		index;
	int		*tmp;
	
	i = 0;
	index = 0;
	tmp = ref_tab[ptr->etape];
	while (i < nb)
	{
		j = 0;
		while (j < nb)
		{
			if (ft_check_limits(tmp, n) == 1 && ft_check_overlap(tmp, ptr) == 1)
				next[index++] = tmp;
			j++;
			tmp[1]++;
		}
		i++;
		tmp[0]++;
	}


t_noeud	*ft_def_start_possible_position()
{
	t_noeud	*ptr;

	i = 0;
	j = 0;
	n = ft_search_range(ft_count_pieces(ref_tab));
	ptr = (t_piece *)malloc(sizeof(t_piece));
	ptr->etape = 0;

