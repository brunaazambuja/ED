//
//  Random_Numbers_Generator.c
//  Projeto Ed
//
//  Created by Ricardo Santos on 9/28/18.
//  Copyright © 2018 Ricardo Santos. All rights reserved.
//

#include "Random.h"

int Random_Numbers(int RANGE){
    int a = (rand() % (RANGE + 1));//Cria numero randomico de 0 a Range
    
    return a;
}

void InsertionSort(pacientes *array, int n){
    int i, j;
    pacientes temp;
    
    for(i=1; i<n; i++){
        temp = array[i];
        for(j=i; (j>0) && (temp.Chegada < array[j-1].Chegada); j--){
            array[j] = array[j-1];
        }
        array[j] = temp;
    }
}

int main(){
    /* DEFINIÇÃO DAS VARIÁVEIS, ARRAYS E SEEDS A SEREM UTILIZADAS */
    int a, i;
    pacientes *pessoas;
    time_t t;
    FILE* fp;
    FILE* fp2;
    fp = fopen("arquivo_configuracao", "w");
    fp2 = fopen("arquivo_carga_trabalho", "w");
    srand((unsigned) time(&t));/*----------->Seed aleatória para cada vez que o programa é iniciado*/
    
    /* CRIAÇÃO DO ARQUIVO DOS GUICHÊS */
    a = Random_Numbers(25);/*-------------------->Número de guichês a serem criados*/
    printf("Número de Guichês Gerados: %d\n", a);
    
    fprintf(fp, "%d\n", a);
    for(i=0; i<a; i++){
        fprintf(fp, "%d\n", Random_Numbers(4));/*---->Definição dos serviços de cada guichê*/
    }
    
    /* CRIAÇÃO DOS PACIENTES */
    int b = Random_Numbers(1000);/*------->Número de clientes a serem criados*/
    printf("Número de Pacientes Gerados: %d\n", b);
    
    pessoas = (pacientes *)malloc(b*sizeof(pacientes));/*---->Alocação de memória para criação de um array dos pacientes*/
    
    for(i = 0; i < b; i++){
        pessoas[i].Chegada = Random_Numbers(750);
        pessoas[i].Idade = Random_Numbers(100);
        pessoas[i].Servico = Random_Numbers(4);
        pessoas[i].Condicao_Fisica = Random_Numbers(2);
    }
    
    InsertionSort(pessoas, b);
    
    for(i=0; i<b; i++){
        fprintf(fp2, "%d %d %d %d\n", pessoas[i].Chegada, pessoas[i].Idade, pessoas[i].Servico, pessoas[i].Condicao_Fisica);
    }
    
    free(pessoas);
    fclose(fp);
    fclose(fp2);
    return 0;
}

