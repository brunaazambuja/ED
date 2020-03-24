/* main.c */

#include "Graph_analyser.h"

int main(int argc, const char * argv[]) {

    /* ----DEFINIÇÃO DE VARIÁVEIS---- */
    int num_vertices, total_weight = 0, min_weight = 0, i, second_MST = 0;
    double run_time;
    clock_t begin, end;
    
    begin = clock();
    
    /* saídas para a primeira e segunda MST */
    int_list *exit_list, *exit_list_two;
    
    /* lista de adjacência */
    vertice **adjacency_list;
    
    /* vertice que inicía o algoritmo de busca */
    vertice *min_vertice;
   
    /* árvore de busca binária */
    root *BST_first = NULL;
    
    FILE * fp; /* para ler o arquvo de entrada */
    FILE *fp1; /* para ler e escrever o arquvo de saída */
    FILE *fp2; /* para ler e escrever o segundo arquvo de saída */
/* ------------------------------------------------------------------- */
    /* --Criando matriz auxiliar de leitura e lista de adjacência-- */
    /* abre o arquivo de entrada para leitura */
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("Não foi possível abrir o arquivo\n");
        exit(1);
    }
    /* vê o número de vértices */
    fscanf(fp, "%d", &num_vertices);
    
    if(Verbose_data) printf("\n\tNúmero de vértices: %d\n\n", num_vertices);
/* ------------------------------------------------------------------- */
    
    /* Aloca memória para os arrays de ponteiros */
    adjacency_list = (vertice **)malloc(num_vertices * sizeof(vertice *));
    if(adjacency_list == NULL){
        printf("Memória não alocada para a matriz da lista de adjacência\n");
        exit(2);
    }

    /* Aloca memória para a lista de adjacência */
    memoryAllocator(num_vertices, adjacency_list);
    
    /* Aloca memória para a primeira lista de saída */
    exit_list = (int_list *)malloc(num_vertices * sizeof(int_list));
    if(exit_list == NULL){
        printf("Memória não alocada para a matriz da lista de saída\n");
        exit(8);
    }
    exit_list->first = NULL;
    
    /* Aloca memória para a segunda lista de saída */
    exit_list_two = (int_list *)malloc(num_vertices * sizeof(int_list));
    if(exit_list_two == NULL){
        printf("Memória não alocada para a matriz da lista de saída\n");
        exit(8);
    }
    exit_list_two->first = NULL;
/* ------------------------------------------------------------------- */
    
    /* IMPLEMENTANDO OS VALORES NA LISTA DE ADJACÊNCIA */
    Implementer(num_vertices, adjacency_list, fp, &total_weight);
    /* fechando o arquivo */
    fclose(fp);
/* ------------------------------------------------------------------- */
    
    /* APLICANDO ALGORÍTMO DE PRIMM */
    /* Começando o algorítmo pelo vértice 0 */
    fp1 = fopen("Exit_Matrix_MST", "w+");
    if(fp1 == NULL){
        printf("Não foi possível abrir o arquivo\n");
        exit(7);
    }
    min_vertice = adjacency_list[3];
    PrimAlg(adjacency_list, BST_first, min_vertice, num_vertices, fp1, &min_weight, exit_list, 0);
    printf("MST com custo: %d\n", min_weight);
    printf("Economia vs malha totalmente conexa: %d\n", (total_weight-min_weight));
    /*Fim Do Algorítmo*/
    
    
    /* Checando por mais de uma MST, ou seja
    aplicando o algorítmo novamente pra cada vértice */
    rewind(fp1);
    for(i = 1; i<num_vertices; i++){
        /* reiniciando com as condições iniciais */
        freeTree(BST_first);
        UpdateKeys(adjacency_list, num_vertices);
        if(Verbose_error_check) printf("\n\n\n\n\nComeçando pelo vértice: %d\n\n\n\n\n", i);
        
        min_vertice = adjacency_list[i];
        PrimAlg(adjacency_list, BST_first, min_vertice, num_vertices, fp1, &second_MST, exit_list, 1);
        if(second_MST != 0) break;
    }
    fclose(fp1);
    
    if(second_MST == 1){
        printf("MST não é única!\n");
        fp2 = fopen("Second_MST", "w+");
        if(fp2 == NULL){
            printf("Não foi possível abrir o arquivo\n");
            exit(7);
        }
        freeTree(BST_first);
        UpdateKeys(adjacency_list, num_vertices);
        freeExit(exit_list); //exit_list->first = NULL
        min_vertice = adjacency_list[i];
        PrimAlg(adjacency_list, BST_first, min_vertice, num_vertices, fp2, &second_MST, exit_list_two, 2);
        fclose(fp2);
        
    } else printf("MST única!\n");
    
    /*Fim da checagem*/
    
    /* ----------------------------------------------------------- */
    /* Desalocando Memória */
    freeTree(BST_first);
    freeList(adjacency_list, num_vertices);
    freeExit(exit_list_two);
    free(exit_list);
    free(exit_list_two);
    free(adjacency_list);
    /*Memória Desalocada*/
    
    end = clock();
    if (Verbose_time){
        run_time = (double)(end - begin)/CLOCKS_PER_SEC;
        printf("Tempo total do programa: %f segundos\n", run_time);
    }
    
    return 0;
}

