/* Graph_analyser.c */

#include "Graph_analyser.h"

/* Função para criar nova raíz */
root* NewNode(int data){
    
    root * newNode = malloc(sizeof(root));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    
    return newNode;
}
/* ----------------------------------------------------------- */

/* Função para inserir raíz na árvore */
void Insert_Tree(root **Bin_tree, int data){
    
    if(*Bin_tree == NULL){
        *Bin_tree = NewNode(data);
        
    } else if(data <= (*Bin_tree)->data){
        Insert_Tree(&(*Bin_tree)->left, data);
        
    } else{
        Insert_Tree(&(*Bin_tree)->right, data);
    }
    
    return;
}
/* ----------------------------------------------------------- */

/* Função de pesquisa na árvore */
int Search_BSTtree(root *Bin_tree ,int data){
    if(Bin_tree == NULL){
        return 0;
        
    } else if (Bin_tree->data == data){
        return 1;
        
    } else if(data <= Bin_tree->data){
        return Search_BSTtree(Bin_tree->left, data);
        
    } else{
        return Search_BSTtree(Bin_tree->right, data);
    }
    
}
/* ----------------------------------------------------------- */

/* Libera a memória utilizada pela árvore binária */
void freeTree(root *BST_tree){
    
    if(BST_tree == NULL) return;
    
    freeTree(BST_tree->left);
    freeTree(BST_tree->right);
    
    free(BST_tree);
}
/* ----------------------------------------------------------- */

/* Procura pelo par de números no arquivo de saída */
int SearchForPair(int source, int dest, int_list *exit_list){
    edge *aux = exit_list->first;
    
    /* Procurando na esquerda */
    while(aux->data.source != source && aux != NULL){
        aux = aux->next;
        if(aux == NULL) break;
    }

    /* Procurando na direita */
    if(aux != NULL){
        while(aux->data.dest != dest && aux->data.source == source){
            if(Verbose_error_check) 
                printf("Recebido %d\n", aux->data.dest);
            aux = aux->next;
            if(aux == NULL) break;
        }
    }
    /* Se número for encontrado  retorna 1*/
    if(aux != NULL && aux->data.source == source && aux->data.dest == dest){
        if(Verbose_error_check) 
            printf("Já inserido\n");
        return 1;
    }
    
    /* Retorna 0 caso não encontrado */
    if(Verbose_error_check) 
        printf("Não encontrado: %d %d\n\n\n\n", source, dest);
    return 0;
    
}
/* ----------------------------------------------------------- */

/* Imprime todos os valores da lista em um arquivo */
void Tranverse_and_print(int_list *exit_list, FILE *fp){
    edge *aux;
    
    aux = exit_list->first;
    while (aux != NULL) {
        fprintf(fp, "%d %d\n", aux->data.source, aux->data.dest);
        aux = aux->next;
    }
    
}
/* ----------------------------------------------------------- */

/* Insere todos os valores na lista de saída organizadamente */
void InsertExitOrganized(int_list *exit_list, int menor, int maior){
    edge *aux = exit_list->first, *aux_prev = NULL;
    int iterations = 0;
    
    /* Criando espaço temporário */
    edge *temp;
    temp = (edge *)malloc(sizeof(edge));
    if(temp == NULL){
        printf("Memória não alocada para saída temporária\n");
        exit(10);
    }
    temp->data.source = menor;
    temp->data.dest = maior;
    
    /* Lista vazia */
    if(aux == NULL){
        if(Verbose_error_check) 
            printf("Lista vazia\n");
        exit_list->first = temp;
        temp->next = NULL;
    }
    
    /* Lista não vazia */
    else{
        if(Verbose_error_check) 
            printf("Lista não vazia\n");
        /* Inserindo como primeiro */
        if(maior <= aux->data.dest && menor <= aux->data.source){
            if(Verbose_error_check)     
                printf("\n\nInserindo como primeiro\n\n");
            temp->next = aux;
            exit_list->first = temp;
        }
        else{
            if(Verbose_error_check) 
                printf("\n\nInserindo depois do primeiro\n\n");
            
            /* Encontrando a posição de acordo com a esquerda */
            while(menor > aux->data.source){
                iterations++;
                aux_prev = aux;
                aux = aux->next;
                if(aux == NULL) break;
                if(Verbose_error_check) 
                    printf("Comparando %d com %d\n",menor, aux->data.source);
            }
            
            /* Encontrando a posição de acordo com a direita */
            if(aux != NULL){
                while (maior > aux->data.dest && menor >= aux->data.source){

                    if(Verbose_error_check) 
                        printf("Comparando %d,%d com %d,%d\n", menor, maior, aux->data.source, aux->data.dest);
                        
                    iterations++;
                    aux_prev = aux;
                    aux = aux->next;
                    if(aux == NULL) break;
                }
            }
            
            if(aux_prev == NULL){
                exit_list->first = temp;
                temp->next = aux;
                return;
            }
            
            aux_prev->next = temp;
            if(aux != NULL) temp->next = aux;
            else temp->next = NULL;
        }
    }
}
/* ----------------------------------------------------------- */

/* Libera a lista de saída */
void freeExit(int_list *exit_list){
    edge *aux, *aux_2;
    
    aux = exit_list->first;
    while(aux != NULL){
        aux_2 = aux;
        aux = aux->next;
        free(aux_2);
    }
    exit_list->first = NULL;
    
}
/* ----------------------------------------------------------- */

/* Algorítmo de Primm para um vértice mínimo escolhido */
void PrimAlg(vertice **adjacency_list, root *BST_tree, vertice *min_vertice, int num_vertices, FILE *fp, int *min_weight, int_list *exit_list, int FirstOrSecond){
    /* Parâmetro 0 para o encontro da primeira MST*/
    /* Parâmetro 1 para a procura de outra MST */
    /* Parâmetro 2 para o encontro da segunda MST */
    
    int found_edges = 0, i, j, menor, maior;
    edge *aux;
    
    /* atualizando chave do vértice inicial para 0 */
    min_vertice->key = 0;
    
    while(found_edges < (num_vertices - 1)){
        aux = min_vertice->first;
        
        Insert_Tree(&BST_tree, min_vertice->first->data.source);
        
        /* atualiza as chaves para cada conexão adjacente */
        for(i=0; i < min_vertice->num_connections; i++){

            /* se o peso da conexão for menor que chave do destino... */
            if(aux->data.weight < adjacency_list[aux->data.dest]->key){

                /* se a o vértice destino ainda não foi inserido na MST... */
                if(!Search_BSTtree(BST_tree, aux->data.dest)){
                    adjacency_list[aux->data.dest]->key = aux->data.weight;
                    adjacency_list[aux->data.dest]->parent = adjacency_list[aux->data.source];
                }
            }
            aux = aux->next; /* Nota: aux termina em NULL */
        }
        
        /* Encontra o primeiro vértice válido - não está na MST ainda */
        for(i=0; i < num_vertices; i++){
            if(!Search_BSTtree(BST_tree, adjacency_list[i]->first->data.source)){
                min_vertice = adjacency_list[i];
                break;
            }
        }
        
        /* Encontra o menor vértice válido, a partir do primeiro válido */
        for(j=i; j < num_vertices; j++){
            if(adjacency_list[j]->key < min_vertice->key){
                if(!Search_BSTtree(BST_tree, adjacency_list[j]->first->data.source)){
                    min_vertice = adjacency_list[j];
                }
            }
        }
        
        /* Encontrando o menor valor entre source e destino */
        menor = min_vertice->parent->first->data.source;
        maior = min_vertice->first->data.source;

        if(min_vertice->first->data.source < menor){
            menor = min_vertice->first->data.source;
            maior = min_vertice->parent->first->data.source;
        }
        
        if (FirstOrSecond == 0) {
            *min_weight += min_vertice->key;
        }
        
        if(FirstOrSecond == 0 || FirstOrSecond == 2){
            InsertExitOrganized(exit_list, menor, maior);
        }
        if(FirstOrSecond == 1){
            if(!SearchForPair(menor, maior, exit_list)){
                (*min_weight) = 1;
                return;
            }
            
        }
        found_edges++;
    }
    if(FirstOrSecond == 0 || FirstOrSecond == 2){
        Tranverse_and_print(exit_list, fp);
    }
}
/* ----------------------------------------------------------- */

/* Função que coloca cada vértice nas condições iniciais:
 (chave = infinito e nó pai = NULL) */
void UpdateKeys(vertice **adjacency_list, int num_vertices){
    
    int i;
    float infinity = 1.0/0.0;
    for(i=0; i<num_vertices;i++){
        adjacency_list[i]->key = infinity;
        adjacency_list[i]->parent = NULL;
    }
}

