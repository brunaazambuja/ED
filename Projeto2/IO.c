/* IO.c */

#include "IO.h"

/* Alocação de Memória para a lista de adjacência */
void memoryAllocator(int num_vertices, vertice **adjacency_list){
    int i;
    
        float infinity = 1.0/0.0;
        for(i=0; i<num_vertices; i++){
            adjacency_list[i] = (vertice *)malloc(sizeof(vertice));
            if(adjacency_list[i] == NULL){
                printf("Memória não alocada para as arestas\n");
                exit(3);
            }
            adjacency_list[i]->first = NULL;
            adjacency_list[i]->last = NULL;
            adjacency_list[i]->parent = NULL;
            adjacency_list[i]->key = infinity;
            adjacency_list[i]->num_connections = 0;
            
        }
    
}
/* ----------------------------------------------------------- */

/* Inserção na lista de adjacência */
void Insert_list(vertice **adjacency_list, int source, int dest, int weight){
    edge *temp;
    
    temp = (edge *)malloc(sizeof(edge));
    if(temp == NULL){
        printf("Memória não alocada para aresta temporária\n");
    }
    if(Verbose_error_check){
        printf("Inserindo aresta com dados:\n%d->%d\nWeight = %d\n\n", source, dest, weight);
    }
    temp->data.source = source;
    temp->data.dest = dest;
    temp->data.weight = weight;
    adjacency_list[source]->num_connections++;
    
    /* se lista estiver vazia... */
    if(adjacency_list[source]->first == NULL){
        temp->next = NULL;
        /* novo elemento será o primeiro da lista */
        adjacency_list[source]->first = temp;
        adjacency_list[source]->last = temp;
        
    } else{
        /* novo elemento será o último da lista */
        adjacency_list[source]->last->next = temp;
        temp->next = NULL;
        adjacency_list[source]->last = temp;
    }
}
/* ----------------------------------------------------------- */

/* Lê e implementa os valores da matriz na lista */
void Implementer(int num_vertices, vertice **adjacency_matrix, FILE *fp, int *total_weight){
    int i = 0, j = 0, num_aux;
    
    while(fscanf(fp, "%d", &num_aux) != EOF){
        if(num_aux != 0){
            if(j > i) (*total_weight) += num_aux;
            Insert_list(adjacency_matrix, i, j, num_aux);
        }
        j++;
        
        if(j == num_vertices){
            j = 0;
            i++;
        }
    }
}
/* ----------------------------------------------------------- */

/* Desaloca memória utilizada pela lista de adjacência */
void freeList(vertice **adjacency_list, int num_vertices){
    int i;
    edge *aux, *aux_2;
    
    for(i=0; i<num_vertices; i++){
        aux = adjacency_list[i]->first;
        while(aux != NULL){
            aux_2 = aux->next;
            free(aux);
            aux = aux_2;
        }
    }
}

