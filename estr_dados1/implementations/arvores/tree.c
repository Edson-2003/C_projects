#include <stdio.h>
#include <stdlib.h>



struct tree
{
	int value;
	struct tree *left;
	struct tree *rigth;
};

struct tree* 
init()
{
	struct tree *sheet;
	sheet = (struct tree*) malloc(sizeof(struct tree));
	sheet->left = NULL;
	sheet->rigth = NULL;
	
	return sheet;
}





int
main()
{
	struct tree *tree;
	tree = init();

}
