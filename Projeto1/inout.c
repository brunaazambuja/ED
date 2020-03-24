#include <stdio.h> /* input, output */
#include <stdlib.h> /* malloc, calloc */
#include "inout.h" /* funções, ED */

/* 1 modulo - contém o tratamento de entradas e saidas */

FILE* abrearquivo(char *nome, char *funcao){

    FILE *fp;
    fp = fopen(nome, funcao);
    if(fp == NULL){
        printf("erro ao abrir arquivo %s\n", nome);
        exit(0);
    }
    return fp;
}
// ----------------------------------------------------------------- //

void crialista(Lista *li){

    li->primeiro = (apontador) malloc(sizeof(elemento));
    if(li->primeiro == NULL) return;
    li->ultimo = li->primeiro;
    li->primeiro->prox = NULL;
    

    return;
}
// ----------------------------------------------------------------- //

void insere_lista_final(Lista *li, pessoa paciente){

    li->ultimo->prox = (apontador) malloc(sizeof(elemento)); /* alocamos a memória que será utilizada para o novo paciente */
    if(li->ultimo->prox == NULL) return;
    li->ultimo = li->ultimo->prox;
    li->ultimo->dados = paciente; /* o próximo, depois do último da lista, apontará para esse paciente */
    li->ultimo->prox = NULL;

    return;
}
// ----------------------------------------------------------------- //

void insere_lista_ordenada(Lista* li, pessoa paciente, int parametro){ /* PARAMETRO: (0) por numero (1) por prioridade */

    apontador no = (apontador) malloc(sizeof(elemento)); /* tenta alocar um novo nó */
    if(no == NULL) return; /* vejo se consegui alocar esse novo nó */

    no->dados = paciente;
    if(li->primeiro == li->ultimo){ /* caso da lista vazia */
        li->ultimo = no;
        li->primeiro->prox = li->ultimo;
        li->ultimo->prox = NULL;
        return;
    }
        else{ /* caso da lista não vazia -- procurar onde inserir */
            apontador ant, atual = li->primeiro->prox;
            if(parametro == 1){
                /* enquanto o atual for diferente de nulo e o elemento da lista for menor que o elemento que eu quero inserir */
                while(atual != NULL && atual->dados.prioridade >= paciente.prioridade){
                    ant = atual;
                    atual = atual->prox;
                }
            }
                else if (parametro == 0){
                    /* enquanto o atual for diferente de nulo e o elemento da lista for menor que o elemento que eu quero inserir */
                    while(atual != NULL && atual->dados.numero < paciente.numero){
                        ant = atual;
                        atual = atual->prox;
                    }
                }
            if(atual == li->primeiro->prox){ /* o elemento atual é o início da lista? */
                no->prox = li->primeiro->prox; /* se sim, insere no início -- o nó.prox aponta para a lista */
                li->primeiro->prox = no; /* e o início da lista aponta para o novo nó */
            }
                else if (ant == li->ultimo){ 
                    no->prox = NULL;
                    ant->prox = no;
                    li->ultimo = li->ultimo->prox;
                }
                    else { /* se for no meio da lista */
                        no->prox = ant->prox; /* o nó prox aponta para onde o anterior estava apontando - pro atual */
                        ant->prox = no; /* e o anterior prox aponta para o novo nó */
                    }
        }
    return;
}
// ----------------------------------------------------------------- //

int retira_lista(Lista *li, int parametro, pessoa *paciente){

    int cont = 0;
    apontador atual = li->primeiro;
    apontador anterior;
    while(atual->prox != NULL && atual->dados.chegada != parametro){
        anterior = atual;
        atual = atual->prox;
        if(atual->dados.chegada == parametro) cont++; /* incrementamos um contador sempre que a pessoa da lista tiver a
        a característica que estou procurando */
    }
    if(cont == 0) return 0; /* se o contador for zero, significa que não achei ninguém na lista com esse parametro */
    anterior->prox = atual->prox;

    free(atual); /* desaloco o espaço ocupado anteriormente pela pessoa que retiramos da lista */

    return 1;
}
// ----------------------------------------------------------------- //

void entradaguiches(FILE *fp, int *t1, int *t2, int *t3, int *t4, int *t5){

    /* retorna o valor do número de guiches de cada serviço funcionando no dia */
    int x, tam, t = 0, i;
    fscanf(fp, "%d", &tam);
    /* preenche a struct de guiches, criando N filas para cada serviço */
    for (i = 0; i < tam; i++){
        fscanf(fp, "%d", &x);
        /* lê-se o arquivo até o fim (end of file) e incrementa o número de guiches de cada serviço */
        if(x == 0){
            (*t1)++;
        } else if(x == 1){
                (*t2)++;
            } else if(x == 2){
                    (*t3)++;
                } else if(x == 3){
                        (*t4)++;
                    } else if(x == 4){
                            (*t5)++;
                        }
    }
    if(((*t1) == 0) || ((*t2) == 0) || ((*t3) == 0) || ((*t4) == 0) ||( (*t5) == 0)) {
        printf("\nnúmero insuficiente de guichês, tente outra entrada!\n");
        exit(0); 
    }
    /* caso o número de guichês não seja suficiente, paro de rodar o programa! */

    return;
}
// ----------------------------------------------------------------- //

void define_numero_guiche_por_ordem_no_arquivo(FILE* fp, guiche *p1, guiche *p2, guiche *p3, guiche *p4, guiche *p5){

    int total;
    rewind(fp); /* retornamos para o início do arquivo */
    fscanf(fp, "%d", &total);
    int n, t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, k;

    for(k = 1; k <= total; k++){
        fscanf(fp, "%d", &n);
        /* lê-se o arquivo até o fim (end of file) e preenche o campo "número do guiche" em ordem (de 1 ao total) */
        if(n == 0){
            p1[t1].numeroguiche = k;
            p1[t1].flag = 0;
            t1++;
        } else if(n == 1){
                p2[t2].numeroguiche = k;
                p2[t2].flag = 0;
                t2++;
            } else if(n == 2){
                    p3[t3].numeroguiche = k;
                    p3[t3].flag = 0;
                    t3++;
                } else if(n == 3){
                        p4[t4].numeroguiche = k;
                        p4[t4].flag = 0;
                        t4++;
                    } else if(n == 4){
                            p5[t5].numeroguiche = k;
                            p5[t5].flag = 0;
                            t5++;
                        }
    }
    return;
}
// ----------------------------------------------------------------- //

int calcula_prioridade(pessoa paciente){

    int prioridade = 0;
    if(paciente.condfis == 0 || paciente.condfis == 1) /* caso a pessoa seja gestante ou deficiente a prioridade é dois */
        prioridade += 2;
        else if(paciente.condfis == 2) /* caso a pessoa seja saudável a prioridade é um */
            prioridade += 1;
    if(paciente.idade < 65)
        prioridade += 1;
        else if(paciente.idade >= 65 && paciente.idade < 80)
            prioridade += 2;
            else if(paciente.idade >= 80)
                prioridade += 3;

    return prioridade; /* retorna esse valor */
}
// ----------------------------------------------------------------- //

void insere_lista_auxiliar(FILE* fp, Lista *li){

    pessoa pacientetemp;
    int i = 0;
    while(fscanf(fp, "%d %d %d %d", &pacientetemp.chegada, &pacientetemp.idade, &pacientetemp.serv, &pacientetemp.condfis) != EOF){
        pacientetemp.prioridade = calcula_prioridade(pacientetemp);
        pacientetemp.numero = i;
        pacientetemp.tempoesperado = 0;
        insere_lista_final(li, pacientetemp);
        i++;
    }
    return;
}
// ----------------------------------------------------------------- //

void le_pacientes(Lista *li_aux, Lista *li, int parametro, int unidadetempo){

    apontador aux = li_aux->primeiro->prox; /* aux apontará para o primeiro paciente da lista auxiliar */
    pessoa paciente;

    while(aux != NULL){
        if(aux->dados.chegada == unidadetempo && aux->dados.serv == parametro){
            paciente = aux->dados; /* copiamos os dados para uma struct temporária */
            paciente.prioridade = calcula_prioridade(paciente);
            paciente.tempoesperado = 0;
            insere_lista_ordenada(li, paciente, 1); /* inserimos a pessoa na fila do respectivo serviço, por ordem de prioridade */
        }
        aux = aux->prox;
    }

    return;
}
// ----------------------------------------------------------------- //

void printa_lista(Lista *li, int parametro){

    if(parametro == 0) printf("\npessoas da lista de HS:\n");
    if(parametro == 1) printf("\npessoas da lista de PN:\n");
    if(parametro == 2) printf("\npessoas da lista de VC:\n");
    if(parametro == 3) printf("\npessoas da lista de HC:\n");
    if(parametro == 4) printf("\npessoas da lista de RR:\n");
    if(parametro == 100) printf("\npessoas da lista auxiliar de ESPERA:\n");
    if(parametro == 500) printf("\npessoas da lista de RESPOSTA:\n");
    
     /* lembrar que o primeiro elemento li->primeiro não tem nada - apenas aponta para a primeira pessoa de fato! */
    if(li->primeiro == li->ultimo) {
        printf("ninguem\n");
        return;
    }
    apontador aux = li->primeiro->prox;
    while(aux != NULL){
        printf("%d %d %d %d %d --- %d TEMPO: %d\n", aux->dados.chegada, aux->dados.idade, aux->dados.serv, aux->dados.condfis, aux->dados.prioridade, aux->dados.numero, aux->dados.tempoesperado);
        aux = aux->prox;
    }

    return;
}
// ----------------------------------------------------------------- //

void printa_resposta_arquivo(FILE *fp, Lista *li){

    apontador aux = li->primeiro->prox;
    while(aux != NULL){
        fprintf(fp, "%d %d %d %d\n", aux->dados.guicheatendido, aux->dados.prioridade, aux->dados.tempoesperado, aux->dados.serv);
        aux = aux->prox;
    }

    return;
}
