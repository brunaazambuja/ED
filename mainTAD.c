#include <stdlib.h>
#include <stdio.h>

int main(){
    Lista *Li; /* ponteiro pra lista ** - ponteiro pra ponteiro da minha struct elemento */
    Fila *fi; /* ponteiro pra fila ** - ponteiro pra ponteiro da minha struct elemento */
    li = crialista();
    
    return 0;
}


























/* estrutura de cada paciente */
typedef struct Tipopessoa {
    int chegada, idade, servico, condfis, prioridade;
    apontador proxpessoa; /*---------------------------------------- aponta para a próxima pessoa na mesma fila que ele */
    apontador primeirapessoa, ultimapessoa; /* --------------------- aponta para a última e a primeira pessoa da mesma fila que ele */
} TipoPessoa;


guiche->natal[1]->fila->prox

    TipoPessoa *p = criaPessoa();
    addPessoa(p,)

    int aux* = fila;

    while(aux->prox != NULL){
        if(aux->value == 2)
            break;
        aux = aux->prox;
    }





TipoGuiche* criaGuiche(TipoGuiche *guiche){
    /* alocando a memória e pegando o ponteiro que apontará para a struct TipoGuiche */
    TipoGuiche *p = (TipoGuiche*) malloc(sizeof(TipoGuiche));

    return p;
}




void addpacient(FILE *fp, TipoGuiche *guiche){

    int tmp, id, serv, cf, i, menorfila;
    TipoGuiche *aux = guiche;
    fscanf(fp, "%d %d %d %d", &tmp, &id, &serv, &cf);
    
    /* se a preferência for 1: botamos o paciente na fila em ordem - na fila daquele serviço de menor tamanho */
    if(cf == 2 && id < 65){
        switch (serv){
            case 0:
                menorfila = 0;
                for(i = 1; i < guiche->hemograma_simples[0]->Nfilas; i++){
                    if(guiche->hemograma_simples[i]->total < guiche->hemograma_simples[menorfila]->total){
                        menorfila = i;
                    }
                }
                /* adiciona a primeira pessoa da fila, forçando o apontador de "última" e "primeira" apontarem para essa mesma pessoa */
                if(aux->hemograma_simples[menorfila]->total == 0){
                    aux->hemograma_simples[menorfila]->pessoas->primeirapessoa = aux->hemograma_simples[menorfila]->pessoas->ultimapessoa;
                    aux->hemograma_simples[menorfila]->pessoas->proxpessoa = NULL;
                }
                /* caso a fila nao esteja vazia, percorre ela até a última pessoa */
                    else {
                        /* movendo o ponteiro de última pessoa para a próxima posição (depois da última) */
                        while(aux->hemograma_simples[menorfila]->pessoas->proxpessoa != NULL){
                            aux->hemograma_simples[menorfila]->pessoas = aux->hemograma_simples[menorfila]->pessoas->proxpessoa;
                        }
                    }
                aux->hemograma_simples[menorfila]->pessoas->chegada = tmp;
                aux->hemograma_simples[menorfila]->pessoas->idade = id;
                aux->hemograma_simples[menorfila]->pessoas->condfis = cf;
                aux->hemograma_simples[menorfila]->total++;
                break;

            case 1:
                menorfila = 0;
                for(i = 1; i < guiche->pre_natal[0]->Nfilas; i++){
                    if(guiche->pre_natal[i]->total < guiche->pre_natal[menorfila]->total){
                        menorfila = i;
                    }
                }
                /* adiciona a primeira pessoa da fila, forçando o apontador de "última" e "primeira" apontarem para essa mesma pessoa */
                if(aux->pre_natal[menorfila]->total == 0){
                    aux->pre_natal[menorfila]->pessoas->primeirapessoa = aux->pre_natal[menorfila]->pessoas->ultimapessoa;
                    aux->pre_natal[menorfila]->pessoas->proxpessoa = NULL;
                }
                /* caso a fila nao esteja vazia, percorre ela até a última pessoa */
                    else {
                        /* movendo o ponteiro de última pessoa para a próxima posição (depois da última) */
                        while(aux->pre_natal[menorfila]->pessoas->proxpessoa != NULL){
                            aux->pre_natal[menorfila]->pessoas = aux->pre_natal[menorfila]->pessoas->proxpessoa;
                        }
                    }
                aux->pre_natal[menorfila]->pessoas->chegada = tmp;
                aux->pre_natal[menorfila]->pessoas->idade = id;
                aux->pre_natal[menorfila]->pessoas->condfis = cf;
                aux->pre_natal[menorfila]->total++;
                
                break;
            case 2:
                menorfila = 0;
                for(i = 1; i < guiche->vacina[0]->Nfilas; i++){
                    if(guiche->vacina[i]->total < guiche->vacina[menorfila]->total){
                        menorfila = i;
                    }
                }
                /* adiciona a primeira pessoa da fila, forçando o apontador de "última" e "primeira" apontarem para essa mesma pessoa */
                if(aux->vacina[menorfila]->total == 0){
                    aux->vacina[menorfila]->pessoas->primeirapessoa = aux->vacina[menorfila]->pessoas->ultimapessoa;
                    aux->vacina[menorfila]->pessoas->proxpessoa = NULL;
                }
                /* caso a fila nao esteja vazia, percorre ela até a última pessoa */
                    else {
                        /* movendo o ponteiro de última pessoa para a próxima posição (depois da última) */
                        while(aux->vacina[menorfila]->pessoas->proxpessoa != NULL){
                            aux->vacina[menorfila]->pessoas = aux->vacina[menorfila]->pessoas->proxpessoa;
                        }
                    }
                aux->vacina[menorfila]->pessoas->chegada = tmp;
                aux->vacina[menorfila]->pessoas->idade = id;
                aux->vacina[menorfila]->pessoas->condfis = cf;
                aux->vacina[menorfila]->total++;
                
                break;
            case 3:
                menorfila = 0;
                for(i = 1; i < guiche->hemograma_completo[0]->Nfilas; i++){
                    if(guiche->hemograma_completo[i]->total < guiche->hemograma_completo[menorfila]->total){
                        menorfila = i;
                    }
                }
                /* adiciona a primeira pessoa da fila, forçando o apontador de "última" e "primeira" apontarem para essa mesma pessoa */
                if(aux->hemograma_completo[menorfila]->total == 0){
                    aux->hemograma_completo[menorfila]->pessoas->primeirapessoa = aux->hemograma_completo[menorfila]->pessoas->ultimapessoa;
                    aux->hemograma_completo[menorfila]->pessoas->proxpessoa = NULL;
                }
                /* caso a fila nao esteja vazia, percorre ela até a última pessoa */
                    else {
                        /* movendo o ponteiro de última pessoa para a próxima posição (depois da última) */
                        while(aux->hemograma_completo[menorfila]->pessoas->proxpessoa != NULL){
                            aux->hemograma_completo[menorfila]->pessoas = aux->hemograma_completo[menorfila]->pessoas->proxpessoa;
                        }
                    }
                aux->hemograma_completo[menorfila]->pessoas->chegada = tmp;
                aux->hemograma_completo[menorfila]->pessoas->idade = id;
                aux->hemograma_completo[menorfila]->pessoas->condfis = cf;
                aux->hemograma_completo[menorfila]->total++;
                
                break;
            case 4:
                menorfila = 0;
                for(i = 1; i < guiche->resultados[0]->Nfilas; i++){
                    if(guiche->resultados[i]->total < guiche->resultados[menorfila]->total){
                        menorfila = i;
                    }
                }
                /* adiciona a primeira pessoa da fila, forçando o apontador de "última" e "primeira" apontarem para essa mesma pessoa */
                if(aux->resultados[menorfila]->total == 0){
                    aux->resultados[menorfila]->pessoas->primeirapessoa = aux->resultados[menorfila]->pessoas->ultimapessoa;
                    aux->resultados[menorfila]->pessoas->proxpessoa = NULL;
                }
                /* caso a fila nao esteja vazia, percorre ela até a última pessoa */
                    else {
                        /* movendo o ponteiro de última pessoa para a próxima posição (depois da última) */
                        while(aux->resultados[menorfila]->pessoas->proxpessoa != NULL){
                            aux->resultados[menorfila]->pessoas = aux->resultados[menorfila]->pessoas->proxpessoa;
                        }
                    }
                aux->resultados[menorfila]->pessoas->chegada = tmp;
                aux->resultados[menorfila]->pessoas->idade = id;
                aux->resultados[menorfila]->pessoas->condfis = cf;
                aux->resultados[menorfila]->total++;
                
                break;
        }
    }

    return;
}
/* ----------------------------------------------------------------- */
#include <stdlib.h>
#include <stdio.h>

/* .h */
struct aluno {
    int matricula;
    char nome[30];
    float n1, n2, n3;
};
typedef struct elemento* Lista;
typedef struct fila Fila;

/* .c */
struct fila {
    struct elemento *inicio;
    struct elemento *final;
};
struct elemento{
    struct aluno dados;
    struct elemento *prox;
};
typedef struct elemento Elem;
/* int main */
/* Lista *Li; */ /* ponteiro pra lista ** - ponteiro pra ponteiro da minha struct elemento */
/* Fila *fi; */ /* ponteiro pra fila ** - ponteiro pra ponteiro da minha struct elemento */
/* ------------------------------------------------------------------------------------- */
Lista* crialista(){
    /* criando o nó "inicio" - celula cabeça - que aponta pro primeiro elemento ** */
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}
/* int main */
/* li = crialista(); */

/* .c */
void liberalista(Lista* li){
    if (li != NULL){
        Elem* no;
        while((*li) != NULL){
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}

int tamanholista(Lista* li){
    if(li == NULL) return 0;
    int cont = 0;
    Elem* no = *li;
    while (no != NULL){
        cont++;
        no = no->prox;
    }
    return cont;
}

int listavazia(Lista* li){
    if(li == NULL) /* se a lista for nula */
        return 1;
    if(*li == NULL) /* se a lista apontar pro nulo - 
    ou seja, tem o primeiro elemento inicio (celula cabeça), mas ele aponta para NULL */
        return 1;
    return 0;
}

int insere_lista_inicio(Lista* li, struct aluno al){
    if(li == NULL) return 0; /* verifica se a lista é válida - se ela existe */
    Elem* no = (Elem*) malloc(sizeof(Elem)); /* cria um novo elemento da lista */
    if(no == NULL) return 0; /* se o nó que eu criei for nulo, retora 0 - deu erro */
    no->dados = al; /* copio os dados pro campo de dados do novo nó */
    no->prox = (*li); /* digo que o próximo dele é a própria lista - resolve caso de lista vazia ou não */
    *li = no; /* e o início passa a ser o novo nó que eu inseri */
    return 1;
}

int insere_lista_final(Lista* li, struct aluno al){
    if(li == NULL) return 0; /* testo se a lista é válida */
    Elem* no = (Elem*) malloc(sizeof(Elem)); /* tenta alocar um novo nó */
    if(no == NULL) return 0; /* vejo se consegui alocar esse novo nó */
    no->dados = al; /* copio a struct para o campo de dados desse novo nó */
    no->prox = NULL; /* digo que o campo próximo é nulo */
    if((*li) == NULL) /* verifico se a lista é vazia */
        *li = no; /* se for, aponto o ponteiro de início para esse meu novo nó */
        else{ 
            Elem *aux = *li; /* se nao for, percorro a lista inteira até o último elemento */
            while(aux->prox != NULL){
                aux = aux->prox;
            }
            aux->prox = no; /* e digo que o ponteiro de prox do último, ao invés de apontar para NULL, aponta para meu nó */
        }
    return 1;
}

int insere_lista_ordenada(Lista* li, struct aluno al){
    if(li == NULL) return 0; /* testo se a lista é válida */
    Elem* no = (Elem*) malloc(sizeof(Elem)); /* tenta alocar um novo nó */
    if(no == NULL) return 0; /* vejo se consegui alocar esse novo nó */
    no->dados = al;
    if(listavazia(li)){ /* caso da lista vazia */
        no->prox = (*li);
        *li = no;
        return 1;
    }
        else{ /* caso da lista não vazia -- procurar onde inserir */
            Elem *ant, *atual = *li;
            /* enquanto o atual for diferente de nulo e o elemento da lista for menor que o elemento que eu quero inserir */
            while(atual != NULL && atual->dados.matricula < al.matricula){
                ant = atual;
                atual = atual->prox;
            }
            if(atual == *li){ /* o elemento atual é o início da lista? */
                no->prox = (*li); /* se sim, insere no início -- o nó.prox aponta para a lista */
                *li = no; /* e o início da lista aponta para o novo nó */
            }
                else{ /* se não for o início da lista - insere ou no final ou no meio dela */
                    no->prox = ant->prox; /* o nó prox aponta para onde o anterior estava apontando - pro atual */
                    ant->prox = no; /* e o anterior prox aponta para o novo nó */
                }
        }
    return 1;
}

int remove_lista_inicio(Lista* li){
    if(li == NULL) return 0; /* verifico se a lista existe */
    if((*li) == NULL) return 0; /* verifico se a lista é vazia */
    Elem *no = *li; /* cria nó auxiliar que recebe o valor do início da lista - primeiro elemento */
    *li = no->prox; /* diz que o início da lista aponta para o próximo do primeiro */
    free(no); /* libera o ex-primeiro */
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL) return 0; /* verifico se a lista existe */
    if((*li) == NULL) return 0; /* verifico se a lista é vazia */
    Elem *ant, *no = *li; /* crio elementos auxiliares */
    while(no->prox != NULL){ /* percorro a lista até o final dela */
        ant = no; 
        no = no->prox;
    }
    if(no == (*li)) /* depois de percorrer, o nó é igual ao início da lista? */
        *li = no->prox; /* se for, tenho que remover o primeiro -- lista tinha apenas 1 elemento */
        else
            ant->prox = no->prox; /* se não for, o anterior vai apontar para onde aponta o nó -- ou seja, o próximo do atual */
    free(no); /* libero o nó */
    return 1;
}

int remove_lista(Lista* li, int mat){
    if(li == NULL) return 0; /* verifico se a lista existe */
    Elem *ant, *no = *li; /* crio elementos auxiliares */
    while(no != NULL && no->dados.matricula != mat){ /* percorro a lista até minha condição ser verdadeira */
        ant = no;
        no = no->prox;
    }
    if(no == NULL) return 0; /* elemento não encontrado -- condição não satisfeita */
    if(no == *li) /* se o elemento for encontrado e estiver no início da lista -- removo o primeiro */
        *li = no->prox;
        else /* se o elemento for encontrado e estiver no meio da lista -- removo um do meio */
            ant->prox = no->prox;
    free(no); /* libero o nó */
    return 1;
}

int consulta_lista_pos(Lista* li, int pos, struct aluno *al){
    if(li == NULL || pos <= 0) return 0; /* caso a posição seja inválida ou tenha sido passado uma lista vazia */
    Elem *no = *li; /* crio elementos auxiliares */
    int i = 1;
    while(no != NULL && i < pos){ /* percorro a lista até achar a posição que eu quero */
        no = no->prox;
        i++;
    }
    if(no == NULL) return 0; /* não foi achada a posição que eu passei */
        else{
            *al = no->dados; /* copio os dados do nó da posição que eu passei na struct aluno */
            return 1;
        }
}

int consulta_lista_dado(Lista* li, int mat, struct aluno *al){
    if(li == NULL) return 0; /* verifico se a lista é válida */
    Elem *no = *li; /* crio elementos auxiliares */
    while(no != NULL && no->dados.matricula != mat){ /* percorro a lista até o final, até encontrar o elemento que eu quero */
        no = no->prox;
    }
    if(no == NULL) return 0; /* caso lista seja vazia, ou elemento não encontrado */
        else{
            *al = no->dados; /* caso elemento seja encontrado, copio os dados do nó para a struct aluno */
            return 1;
        }
}
/* ----------------------------------------------------------------------------------------------------- */

Fila* criafila(){
    Fila* fi = (Fila*) malloc(sizeof(Fila)); /* aloco o espaço pro início da fila - célula cabeça */
    if(fi != NULL){ /* se conseguiu alocar */
        fi->final = NULL; /* o final e o início da fila apontam para NULL */
        fi->inicio = NULL;
    }
    return fi;
}

void liberafila(Fila* fi){
    if(fi != NULL){ /* verifica se fila é válida */
        Elem* no; /* cria elemento auxiliar */
        while(fi->inicio != NULL){ /* enquanto o início não apontar para NULL */
            no = fi->inicio;
            fi->inicio = fi->inicio->prox; /* percorremos a fila, mudando o ponteiro do início de elemento em elemento */
            free(no); /* liberando o anterior a cada vez */
        }
        free(fi); /* e no final, liberando o ponteiro pra ponteiro que apontava para o início da fila */
    }
}

int tamanhofila(Fila* fi){
    if(fi == NULL) return 0; /* verifica se fila é válida */
    int cont = 0;
    Elem *no = fi->inicio; /* cria elemento auxiliar que aponta para o início da fila */
    while(no != NULL){ /* percorre toda a fila e vai incrementando o contador */
        cont++;
        no = no->prox;
    }
    return cont; /* retorna o contador */
}

int filavazia(Fila* fi){
    if(fi == NULL) return 1; /* verifica se a fila é válida */
    if(fi->inicio == NULL) return 1; /* verifica se o início da fila aponta para NULL */
    return 0;
}

int insere_fila(Fila* fi, struct aluno al){
    if(fi == NULL) return 0; /* verifica se fila é válida */
    Elem *no = (Elem*) malloc(sizeof(Elem)); /* aloca memória para um novo nó */
    if(no == NULL) return 0; /* verifica se conseguiu alocar memória */
    no->dados = al; /* copia a struct para o campo de dados do novo nó */
    no->prox = NULL; /* aponta o campo próximo do novo nó para NULL */
    if(fi->final == NULL) /* caso de uma fila vazia - final dela aponta para NULL */
        fi->inicio = no; /* então o início recebe esse novo nó */
        else /* se não for uma fila vazia */
            fi->final->prox = no; /* adiciono o novo nó depois do último */
    fi->final = no; /* o ponteiro do final aponta para o novo último */
    return 1;
}

int remove_fila(Fila* fi){
    if(fi == NULL) return 0; /* verifica se fila é válida */
    if(fi->inicio == NULL) return 0; /* verifica se fila é vazia */
    Elem *no = fi->inicio; /* cria elemento auxiliar apontando para o início da fila */
    fi->inicio = fi->inicio->prox; /* o início aponta para o próximo */
    if(fi->inicio == NULL) /* se a fila tiver ficado vazia */
        fi->final = NULL; /* final passa a ser NULL também */
    free(no); /* libero o nó auxiliar */
    return 1;
}

/* em uma fila - a consulta se dá apenas no início */
int consulta_fila(Fila* fi, struct aluno *al){
    if(fi == NULL) return 0; /* verifica se fila é válida */
    if(fi->inicio == NULL) return 0; /* verifica se lista é vazia */
    *al = fi->inicio->dados; /* acessando a informação do início e retornando na struct al */
    return 1;
}









/* 

typedef struct celula *apontador;

typedef struct tipoitem {
    int dados;
} TipoItem;

typedef struct celula {
    TipoItem item;
    apontador prox;
} Celula;

typedef struct tipofila {
    apontador ultimo, primeiro;
} TipoFila;

void FazFilaVazia(TipoFila *fila){
    fila->primeiro = (apontador) malloc(sizeof(Celula));
    fila->ultimo = fila->primeiro;
    fila->primeiro->prox = NULL;
    return;
}

int Vazia(TipoFila *fila){
    return(fila->primeiro == fila->ultimo);
}

void Enfileira(TipoFila *fila, TipoItem x){
    fila->ultimo->prox = (apontador) malloc(sizeof(Celula));
    fila->ultimo = fila->ultimo->prox;
    fila->ultimo->item = x;
    fila->ultimo->prox = NULL;
    return;
}

void Desenfileira(TipoFila *fila, TipoItem *item){
    *item = fila->primeiro->item;
    fila->primeiro = fila->primeiro->prox;
    return;
}

int main(){
    int x;
    TipoFila *fila;
    FazFilaVazia(*fila);
    x = Vazia(*fila);
    Enfileira(*fila, x);
    Enfileira(*fila, x + 3);
    Desenfileira(*fila, x);

    return 0;
}
 */