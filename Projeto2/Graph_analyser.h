/* Graph_analyser.h */

#ifndef Graph_analyser_h
#define Graph_analyser_h

#include "IO.h"

void Insert_Tree(root **node, int data);
root* NewNode(int data);
int Search_BSTtree(root *Bin_tree ,int data);
void PrimAlg(vertice **adjacency_list, root *BST_tree, vertice *min_vertice, int num_vertices, FILE *fp, int *min_weight, int_list *exit_list, int FirstOrSecond);
int SearchForPair(int source, int dest, int_list *exit_list);
void freeTree(root *BST_tree);
void UpdateKeys(vertice **adjacency_list, int num_vertices);
void Tranverse_and_print(int_list *exit_list, FILE *fp);
void InsertExitOrganized(int_list *exit_list, int source, int dest);
void freeExit(int_list *exit_list);

#endif /* Graph_analyser_h */

