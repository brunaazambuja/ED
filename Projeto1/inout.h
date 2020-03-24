#ifndef inout_h
#define inout_h

#include <stdio.h> /* input, output */
#include <stdlib.h> /* malloc, calloc */

/* protótipo de funções de tratamento de entrada e saída e estrutura de dados utilizadas */


// ---------------------------------------------------------------------- //
/* ESTRUTURA DE DADOS UTILIZADAS */

typedef struct Pessoa {
    int chegada, condfis, prioridade, idade, serv;
    int guicheatendido, tempoesperado, numero;
} pessoa;

typedef struct Elemento* apontador; // vai apontar para uma struct elemento

typedef struct Elemento {
    apontador prox;
    pessoa dados;
} elemento;

typedef struct lista {
    apontador primeiro, ultimo; // aponta para primeira e última struct da lista
} Lista;

typedef struct Guiche {
    int numeroguiche, contador, flag;
    pessoa atual; // contém os dados da pessoa que está sendo atendida por aquele guiche no momento
} guiche;

// ---------------------------------------------------------------------- //
/* FUNÇÕES UTILIZADAS */

    /* função para tratamento dos arquivos */
    FILE* abrearquivo(char *nome, char *funcao);

    /* funções para tratamento das TAD's */
    void crialista(Lista *li);
    int retira_lista(Lista *li, int parametro, pessoa *paciente);
    void insere_lista_auxiliar(FILE *fp, Lista *li);
    void insere_lista_ordenada(Lista* li, pessoa paciente, int parametro);
    void insere_lista_final(Lista *li, pessoa paciente);

    /* funções para tratamento dos dados */
    int calcula_prioridade(pessoa paciente);
    void entradaguiches(FILE *fp, int *t1, int *t2, int *t3, int *t4, int *t5);
    void define_numero_guiche_por_ordem_no_arquivo(FILE* fp, guiche *p1, guiche *p2, guiche *p3, guiche *p4, guiche *p5);
    void le_pacientes(Lista *li_aux, Lista *li, int parametro, int unidadetempo);

    /* funções para printar e acompanhar o processo de perto */
    void printa_resposta_arquivo(FILE *fp, Lista *li);
    void printa_lista(Lista *li, int parametro);



#endif