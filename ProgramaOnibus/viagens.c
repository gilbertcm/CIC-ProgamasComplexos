#include "viagens.h"
#include <string.h>


int inicializa_viagens(Viagem *viagem, Data dt_ini, Data dt_fim, Hora *rio_sp, Hora *sp_rio)
// --- Cria o vetor viagem com as viagens no hor�rio do vetor de horas rio_sp e sp_rio das datas compreendidas entre dt_ini e dt_fim --
// --- Os assentos do onibus s�o inicializadas com 0 --
{
    int i;
    int j=0;
    Data dt_ini2;
    int contador=0;

    dt_ini2.dia = dt_ini.dia;
    dt_ini2.mes = dt_ini.mes;
    dt_ini2.ano = dt_ini.ano;

    for (i=0; !eh_igual(dt_ini,dt_fim); i++ )
    {
        viagem[i].data.dia = dt_ini.dia;
        viagem[i].data.mes = dt_ini.mes;
        viagem[i].data.ano = dt_ini.ano;
        viagem[i].hora.hs   = rio_sp[j].hs;
        viagem[i].hora.mnto = rio_sp[j].mnto;
        viagem[i].direcao   = RJ_SP;
        j++;
        if (j==5)
        {
                dt_ini = incrementa(dt_ini);
                j=0;
        }
        contador++;
        int k;
        for(k=0;k < TAM_ASSENTOS; k++)
        {
            viagem[i].assento[k] = NULL;
        }

    }

    for (  ; !eh_igual(dt_ini2,dt_fim); i++ )
    {
        viagem[i].data.dia = dt_ini2.dia;
        viagem[i].data.mes = dt_ini2.mes;
        viagem[i].data.ano = dt_ini2.ano;
        viagem[i].hora.hs   = sp_rio[j].hs;
        viagem[i].hora.mnto = sp_rio[j].mnto;
        viagem[i].direcao   = SP_RJ;
        j++;
        if (j==5)
        {
                dt_ini2 = incrementa(dt_ini2);
                j=0;
        }
        contador++;
        int k;
        for(k=0;k < TAM_ASSENTOS; k++)
        {
            viagem[i].assento[k] = 0;
        }


    }


return contador;
}

//-----------------------------------------------
// Menu de opcoes para o usuario escolher
//-----------------------------------------------
int obter_opcao()
{
    int opcao;

    {
        printf("\nMenu:");
        printf("\n1 - Comprar passagem");
        printf("\n2 - Total arrecadado para uma determinada viagem");
        printf("\n3 - Total arrecadado em um determinado mes");
        printf("\n4 - Nome do passageiro de uma  poltrona de uma determinada viagem");
        printf("\n5 - Horario de viagem mais rentavel");
        printf("\n6 - Media de idade dos passageiros");
        printf("\n7 - Terminar programa");
        printf("\nDigite a sua opcao: ");
        scanf("%d", &opcao);
        if (opcao < 1 || opcao >7)
            printf("\n\n Opcao invalida. Digite um numero entre 1 e 7 por favor...\n");
    } while ((opcao < 1) || (opcao > 7));
    return opcao;
}

void compra_passagem(Viagem *viagem,Data di,Data df)
{
    int achou_viagem = 0;
    int assento_desejado;
    Data dt_viagem;
    int dia_viagem, mes_viagem, ano_viagem, direcao_viagem;
    int hr_viagem, minutos_viagem;
    Hora hora_viagem;
    int i, indice_viagem=0;
    char cpf[TAM_CPF], nome[TAM_NOME];
    int idade;
    Passageiro passageiro;

    printf("\n---------------------------------------------------------");
    printf("\n    Compra de Passagem ");
    printf("\n---------------------------------------------------------");

    printf("\nDigite a dia desejado:");
    scanf("%d",&dia_viagem);

    printf("\nDigite a mes desejado:");
    scanf("%d",&mes_viagem);

    printf("\nDigite o ano desejado:");
    scanf("%d",&ano_viagem);

    printf("\nDigite a hora:");
    scanf("%d",&hr_viagem);

    printf("\nDigite os minutos:");
    scanf("%d",&minutos_viagem);


    dt_viagem = cria(dia_viagem, mes_viagem, ano_viagem);
    hora_viagem = cria_hora(hr_viagem, minutos_viagem);

    printf("\nDigite a direcao (0 - RJ-SP, 1 - SP-RJ)");
    scanf("%d",&direcao_viagem);

    while (!achou_viagem)
    {
        if (eh_igual(viagem[indice_viagem].data, dt_viagem) &&
            viagem[indice_viagem].direcao == direcao_viagem &&
            eh_igual_hora(viagem[indice_viagem].hora, hora_viagem))

            achou_viagem = 1; // verdadeiro
        else
            indice_viagem++;

        if(eh_igual(viagem[indice_viagem].data,df))

            achou_viagem = -1; // Viagem inv�lida - n�o est� no intervalo inicializado

    }

    if( achou_viagem == -1)
        printf("\nData Escolhida invalida, nao pertence ao ano corrente");
    else
    {
        printf("\n ---------- Assentos Disponiveis --------------------\n");

        for(i=0; i<TAM_ASSENTOS; i++)
        {
            if(viagem[indice_viagem].assento[i] == NULL)
                printf("%d, ", i+1);
        }
        printf("\n\n");
        printf("\n\nQual assento deseja comprar?");
        scanf("%d",&assento_desejado);

        printf("\nDigite o CPF: ");
        scanf("%s", cpf);

        printf("\nDigite o Nome: ");
        scanf("%s", nome);

        printf("\nDigite o Idade: ");
        scanf("%d", &idade);

        viagem[indice_viagem].assento[assento_desejado-1] = (Passageiro*) malloc(sizeof(Passageiro));
        strcpy(viagem[indice_viagem].assento[assento_desejado-1]->cpf, cpf);
        strcpy(viagem[indice_viagem].assento[assento_desejado-1]->nome, nome);
        viagem[indice_viagem].assento[assento_desejado-1]->idade = idade;

        printf("\nPassageiro inserido com sucesso");

    }
}

//------------------------------------------------------------------
// TOTAL ARRECADO NUMA DETERMINADA VIAGEM
//------------------------------------------------------------------

// int tot_por_viagem(int viagem, int ida, int volta)
// {
//      
//
//
// }
