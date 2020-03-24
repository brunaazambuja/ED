#include <stdio.h> /* input, output */
#include <stdlib.h> /* malloc, calloc */
#include "logic.h" /* funções da lógica do programa, ED */

#define true 1
#define false 0


/* 2 modulo - contém a lógica do programa */

void manda_primeiro_da_fila_pros_guiches(guiche *p, int tam, Lista *li, int temposervico){

    /* essa função verifica quais guiches estão vazios, e se estiver ele passa a apontar para uma pessoa - a que 
    ele está atendendo - e nisso, sua flag se torna true (ou seja, guiche passa a estar ocupado) - e então, retira-se
    a primeira pessoa da fila */

    int i = 0;
    while(i < tam){

        if(li->primeiro == li->ultimo) return;

        if(p[i].flag == false){ /* caso o guiche esteja vazio */
            apontador no;
            no = li->primeiro->prox;
            p[i].atual = no->dados; /* a pessoa que vai ser atendida pelo guiche será a primeira da fila */
        
            if(li->primeiro->prox == li->ultimo) li->ultimo = li->primeiro;
                else li->primeiro->prox = li->primeiro->prox->prox;
            
            p[i].contador = temposervico; /* renovamos o countdown do guiche quando o atendimento começa */
            p[i].atual.guicheatendido = p[i].numeroguiche;
            p[i].flag = true; /* e por fim, guiche passa a estar cheio */
            free(no);
        }
        i++;
    }

    return;
}
// ----------------------------------------------------------------- //

void atualiza_tempo_espera(Lista *li){

    /* essa função percorre toda a fila dos pacientes que já chegaram, incrementando o tempo de espera em 1 unidade 
    de cada paciente que ainda não foi atendido */
    if(li->primeiro == li->ultimo) return;
    apontador aux = li->primeiro->prox;
    while(aux != NULL){
        aux->dados.tempoesperado++;
        aux = aux->prox;
    }
    return;
}
// ----------------------------------------------------------------- //

void atualiza_count_down_insere_resp(guiche *p, int tam, Lista *resp){

    /* essa função decrementa em uma unidade o countdown de cada guiche ao decorrer do tempo */
    pessoa pacientetemp;
    int i;
    for(i = 0; i < tam; i++){
        if(p[i].flag == true){
            p[i].contador--;
            if(p[i].contador == 0){ /* caso esse countdown chegue em zero, significa que a pessoa terminou de ser atendida */
                pacientetemp = p[i].atual;
                insere_lista_ordenada(resp, pacientetemp, 0); /* então, nesse caso, inserimos ela na lista de resposta */
                p[i].atual.chegada = 0; /* e atualizamos os dados da pessoa atual do guiche... */
                p[i].atual.condfis = 0;
                p[i].atual.guicheatendido = 0;
                p[i].atual.idade = 0;
                p[i].atual.numero = 0;
                p[i].atual.prioridade = 0;
                p[i].atual.serv = 0;
                p[i].atual.tempoesperado = 0;
                p[i].flag = false; /* ...que passará a estar vazio */
            }
        }
    }
    return;
}
// ----------------------------------------------------------------- //

int verifica_caso_parada(Lista *li, guiche *p, int tam){

    /* verifico se a fila e todos os guiches desse serviço estão vazios */
    int n = 0;
    if(li->primeiro == li->ultimo)
        n = 1;
        else return n;
    for(int i = 0; i < tam; i++){
        if(n && p[i].flag == false) n = 1;
            else n = 0;
    }
    return n;
}
// ----------------------------------------------------------------- //

float calcula_tempo_medio_total(Lista *li, int *cont){

    /* o tempo médio total será a soma dos tempos de espera de cada paciente sobre o total de pacientes */
    float x = 0;
    apontador aux = li->primeiro->prox;
    while(aux != NULL){
        x += aux->dados.tempoesperado;
        (*cont)++;
        aux = aux->prox;
    }
    x /= (*cont);
    return x;
}
// ----------------------------------------------------------------- //

void desaloca(apontador p){

    while (p->prox != NULL){ 
        apontador aux = p;
        p = p->prox;
        free(aux);
    }
    return;
}