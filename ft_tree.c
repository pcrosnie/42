#include "fillit.h"

t_noeud	*ft_node_init(int *coord_piece, int etape, s_noeud *prev, s_noeud **next)
{
	t_noeud *node;

	node = NULL;
	node = (t_noeud*)malloc(sizeof(t_noeud));
	if (node)
	{
		node->coord_piece = coord_piece;
		node->etape = etape;
		node->next = next;
		node->prev = prev;
		node->tmp = NULL;
	}
	return (node);	
}

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *))
{
	if (!root)
	{
		(*applyf)(root->item);
		if (root->left)
			btree_apply_prefix(root->left, applyf);
		if (root->right)
			btree_apply_prefix(root->right, applyf);
	}
}
