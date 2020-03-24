/* IO.h */

#ifndef IO_h
#define IO_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Verbose_data 0 /* Checagem de dados - visão geral */
#define Verbose_error_check 0 /* Checagem de erros - visão detalhada */
#define Verbose_time 1 /* Checagem de tempo */

/* Conjunto de Structs de Dados das arestas */
typedef struct Info{
    int source, weight, dest;
} info;

typedef struct Node{
    struct Node *next;
    info data;
} edge;


/* Struct de Dados do Vértice */
typedef struct list{
    edge *first;
    edge *last;
    struct list *parent;
    float key;
    int num_connections;
} vertice;


/* Struct da Lista de Saída */
typedef struct exit{
    edge *first;
} int_list;


/* Struct da Árvore Binária */
typedef struct cell{
    int data;
    struct cell *left;
    struct cell *right;
} root;

void memoryAllocator(int num_vertices, vertice **adjacency_list);
void Implementer(int num_vertices, vertice **adjacency_matrix, FILE *fp, int *total_weight);
void Insert_list(vertice **adjacency_list, int source, int dest, int weight);
void freeList(vertice **adjacency_list, int num_vertices);

#endif /* IO_h */

