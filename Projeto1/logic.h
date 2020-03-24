#ifndef logic_h
#define logic_h

#include <stdio.h> /* input, output */
#include <stdlib.h> /* malloc, calloc */
#include "inout.h" /* funções de entrada e saída, TAD's */


/* protótipo de funções da lógica do programa */

/* FUNÇÕES UTILIZADAS */

    void manda_primeiro_da_fila_pros_guiches(guiche *p, int tam, Lista *li, int temposervico);
    void atualiza_tempo_espera(Lista *li);
    void atualiza_count_down_insere_resp(guiche *p, int tam, Lista *resp);
    int verifica_caso_parada(Lista *li, guiche *p, int tam);
    float calcula_tempo_medio_total(Lista *li, int *cont);
    void desaloca(apontador p);


#endif