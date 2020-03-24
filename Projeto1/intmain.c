#include <stdio.h> /* input, output */
#include <stdlib.h> /* malloc, calloc */
#include "logic.h" /* funções (lógica e entrada/saída), ED */
#include <time.h>

#define VERBOSE 0 /* CASO QUEIRA ACOMPANHAR O PROCESSO - MUDAR VERBOSE PARA 1 */
#define Time_TEST_SIMULATOR 0
#define TIME_TEST_PROGRAM 0

/* 3 modulo - contém o programa princial */

/* sabendo que a execução do simulador será feita da seguinte forma:
 ./sim_senhas <arquivo_configuracao> <arquivo_carga_trabalho> <arquivo_saída>
 - o (1) parâmetro é o nome do arquivo com o padrão dos guichês;
 - o (2) parâmetro é o nome do arquivo com o padrão dos pacientes;
 - o (3) parâmetro é o nome do arquivo em que será escrita a saída. */

int main(int argc, char **argv){
    
    clock_t begin_t, end_t, begin_s, end_s;
    double run_time;
    
    begin_t = clock();
    
    int unidadetempo = 0, totalpacientes = 0;
    float tempomedio, quantidademedia = 0;
    
    FILE *fp1, *fp2, *fp3;
    /* primeiro, abre-se os arquivos de entrada e saída */
    fp1 = abrearquivo(argv[1], "r");
    fp2 = abrearquivo(argv[2], "r");
    fp3 = abrearquivo(argv[3], "w");
    
    /* faremos um vetor para cada serviço, contendo [número de guiches] posições que cada serviço possui,
     e seus respectivos dados - um vetor de structs */
    int tam1 = 0, tam2 = 0, tam3 = 0, tam4 = 0, tam5 = 0;
    entradaguiches(fp1, &tam1, &tam2, &tam3, &tam4, &tam5);

    if (VERBOSE) printf("tam1 %d tam2 %d tam3 %d tam4 %d tam5 %d\n", tam1, tam2, tam3, tam4, tam5);
    
    guiche* hemograma_simples = (guiche*) malloc(tam1*sizeof(guiche));
    guiche* pre_natal = (guiche*) malloc(tam2*sizeof(guiche));
    guiche* vacina = (guiche*) malloc(tam3*sizeof(guiche));
    guiche* hemograma_completo = (guiche*) malloc(tam4*sizeof(guiche));
    guiche* resultados = (guiche*) malloc(tam5*sizeof(guiche));
    
    /* faremos uma fila dinâmica para cada serviço - que contém todas as pessoas que chegam em determinada
     unidade de tempo por ordem de prioridade */
    Lista lista_hemograma_simples;
    Lista lista_pre_natal;
    Lista lista_vacina;
    Lista lista_hemograma_completo;
    Lista lista_resultados;
    
    /* criaremos também uma lista auxiliar com todos os pacientes do arquivo e uma lista de resposta */
    Lista lista_auxiliar;
    Lista lista_RESPOSTA;
    
    define_numero_guiche_por_ordem_no_arquivo(fp1, hemograma_simples, pre_natal, vacina, hemograma_completo, resultados);
    
    crialista(&lista_hemograma_simples);
    crialista(&lista_pre_natal);
    crialista(&lista_vacina);
    crialista(&lista_hemograma_completo);
    crialista(&lista_resultados);
    crialista(&lista_auxiliar);
    crialista(&lista_RESPOSTA);
    
    /* e por fim, teremos uma variável auxiliar que nos ajudará a desalocar essas listas no final da execução */
    apontador desaloca1 = lista_auxiliar.primeiro;
    apontador desaloca2 = lista_RESPOSTA.primeiro;
    
    insere_lista_auxiliar(fp2 ,&lista_auxiliar); /* insere todos os pacientes do arquivo numa lista auxiliar */
    
    if (VERBOSE) printa_lista(&lista_auxiliar, 100);
    
    begin_s = clock();
    while(1){
        
        if (VERBOSE) printf("\n\n---------------------UM LOOP - rodada [%d]-------------------------\n\n", unidadetempo);
        printf("AAAAA\n");
        
        /* insere todos os pacientes que chegaram na unidade de tempo atual na fila do seu serviço */
        le_pacientes(&lista_auxiliar, &lista_hemograma_simples, 0, unidadetempo);
        le_pacientes(&lista_auxiliar, &lista_pre_natal, 1, unidadetempo);
        le_pacientes(&lista_auxiliar, &lista_vacina, 2, unidadetempo);
        le_pacientes(&lista_auxiliar, &lista_hemograma_completo, 3, unidadetempo);
        le_pacientes(&lista_auxiliar, &lista_resultados, 4, unidadetempo);
        
        /* retira da lista auxiliar todos os pacientes que já chegaram */
        
        while(lista_auxiliar.primeiro->prox->dados.chegada == unidadetempo){
            if(lista_auxiliar.primeiro->prox == lista_auxiliar.ultimo){
                lista_auxiliar.ultimo = lista_auxiliar.primeiro;
                break;
            }
            lista_auxiliar.primeiro->prox = lista_auxiliar.primeiro->prox->prox;
        }
        
        
        if (VERBOSE) printa_lista(&lista_auxiliar, 100);
        
        /* printa as filas de cada serviço */
        if (VERBOSE) {
            printa_lista(&lista_hemograma_simples, 0);
            printa_lista(&lista_pre_natal, 1);
            printa_lista(&lista_vacina, 2);
            printa_lista(&lista_hemograma_completo, 3);
            printa_lista(&lista_resultados, 4);

        }
        
        /* verificamos se tem guiches vazios - se sim, mandamos o primeiro da fila para ele */
        manda_primeiro_da_fila_pros_guiches(hemograma_simples, tam1, &lista_hemograma_simples, 5);
        manda_primeiro_da_fila_pros_guiches(pre_natal, tam2, &lista_pre_natal, 10);
        manda_primeiro_da_fila_pros_guiches(vacina, tam3, &lista_vacina, 8);
        manda_primeiro_da_fila_pros_guiches(hemograma_completo, tam4, &lista_hemograma_completo, 7);
        manda_primeiro_da_fila_pros_guiches(resultados, tam5, &lista_resultados, 2);
        
        /* printa as filas de cada serviço */
        if (VERBOSE) {
            printf("\ndepois da mudança FILAS --------------------------------- \n");
            printa_lista(&lista_hemograma_simples, 0);
            printa_lista(&lista_pre_natal, 1);
            printa_lista(&lista_vacina, 2);
            printa_lista(&lista_hemograma_completo, 3);
            printa_lista(&lista_resultados, 4);

        }
        
        atualiza_tempo_espera(&lista_hemograma_simples);
        atualiza_tempo_espera(&lista_pre_natal);
        atualiza_tempo_espera(&lista_vacina);
        atualiza_tempo_espera(&lista_hemograma_completo);
        atualiza_tempo_espera(&lista_resultados);
        
        /* cada guiche possui um count down com o respectivo tempo de serviço, quando esse count down atinge zero,
         temos que tirar a pessoa do guiche, inserir na lista de resposta e mandar uma nova pessoa para o guiche -
         a primeira da fila - no próximo loop */
        atualiza_count_down_insere_resp(hemograma_simples, tam1, &lista_RESPOSTA);
        atualiza_count_down_insere_resp(pre_natal, tam2, &lista_RESPOSTA);
        atualiza_count_down_insere_resp(vacina, tam3, &lista_RESPOSTA);
        atualiza_count_down_insere_resp(hemograma_completo, tam4, &lista_RESPOSTA);
        atualiza_count_down_insere_resp(resultados, tam5, &lista_RESPOSTA);
        
        if (VERBOSE) printa_lista(&lista_RESPOSTA, 500);
        
        
        /* CASO DE PARADA ----- quando todas as filas estiverem vazias e a lista auxiliar também (a.k.a. todos foram atendidos) */
        if(verifica_caso_parada(&lista_hemograma_simples, hemograma_simples, tam1) && verifica_caso_parada(&lista_pre_natal, pre_natal, tam2) && verifica_caso_parada(&lista_vacina, vacina, tam3) && verifica_caso_parada(&lista_hemograma_completo, hemograma_completo, tam4) && verifica_caso_parada(&lista_resultados, resultados, tam5) && lista_auxiliar.ultimo == lista_auxiliar.primeiro)
            break;
        
        
        /* feito esse processo, rodamos mais um loop... */
        unidadetempo++;
        
    }
    end_s = clock();
    
    /* calculamos, finalmente, o tempo médio de espera total e a quantidade média de pacientes atendidos por unidade de tempo */
    tempomedio = calcula_tempo_medio_total(&lista_RESPOSTA, &totalpacientes);
    quantidademedia += totalpacientes;
    quantidademedia /= (unidadetempo + 1);
    
    printf("tempo médio de espera dos clientes na fila: %.2f\n", tempomedio);
    printf("total pacientes: %d\nunidade de tempo: %d\nquantidade média de clientes por unidade de tempo: %.2f\n", totalpacientes,unidadetempo, quantidademedia);
    
    fprintf(fp3, "%.2f ", tempomedio);
    fprintf(fp3, "%.2f\n", quantidademedia);
    
    printa_resposta_arquivo(fp3, &lista_RESPOSTA);
    
    
    /* desalocamos o espaço usado */
    desaloca(desaloca1);
    desaloca(desaloca2);
    free(hemograma_simples);
    free(hemograma_completo);
    free(vacina);
    free(resultados);
    free(pre_natal);
    
    end_t = clock();
    if (Time_TEST_SIMULATOR){
        run_time = (double)(end_s - begin_s)/CLOCKS_PER_SEC;
        printf("Tempo do simulador: %f segundos\n", run_time);
    }
    if(TIME_TEST_PROGRAM){
        run_time = (double)(end_t - begin_t)/CLOCKS_PER_SEC;
        printf("Tempo total do programa: %f segundos\n", run_time);
    }
    
    return 0;
}

