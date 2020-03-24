//
//  Random_Numbers_Generator.h
//  Projeto Ed
//
//  Created by Ricardo Santos on 9/28/18.
//  Copyright © 2018 Ricardo Santos. All rights reserved.
//

#ifndef Random_Numbers_Generator_h
#define Random_Numbers_Generator_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* STRUCT DOS PACIENTES */
typedef struct paciente{
    int Chegada, Idade, Servico, Condicao_Fisica;
} pacientes;

/* FUNCTIONS USED */
int Random_Numbers(int RANGE);
void InsertionSort(pacientes *array, int n);

#endif
