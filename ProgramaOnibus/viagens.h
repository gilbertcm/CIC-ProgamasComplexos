#ifndef VIAGENS_H_INCLUDED
#define VIAGENS_H_INCLUDED
#endif // VIAGENS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "datas.h"
#define TAM_CPF 14
#define TAM_NOME 30
#define TAM_ASSENTOS 40
#define RJ_SP 0
#define SP_RJ 1

typedef struct
{
    char cpf[TAM_CPF];
    char nome[TAM_NOME];
    int idade;
} Passageiro;

typedef struct
{
    Data data;
    Hora hora;
    int direcao;

    Passageiro *assento[TAM_ASSENTOS];
} Viagem;

int inicializa_viagens(Viagem *viagem, Data dt_ini, Data dt_fim, Hora *rio_sp, Hora *sp_rio);
// --- Cria o vetor viagem com as viagens no hor�rio do vetor de horas rio_sp e sp_rio das datas compreendidas entre dt_ini e dt_fim --
// --- Os assentos do onibus s�o inicializadas com 0 --

//-----------------------------------------------
// Menu de op��es para o usu�rio escolher
//-----------------------------------------------
int obter_opcao();


void compra_passagem(Viagem *viagem,Data di,Data df);

int tot_por_viagem(int viagem, int ida, int volta);
