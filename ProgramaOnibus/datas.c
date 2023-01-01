#include "datas.h"

// Se a data d1 for iguala data d2 retorna verdadeiro (1) senão retorna falso (0)
int eh_igual(Data d1, Data d2)
{
    if ((d1.ano == d2.ano) && (d1.mes == d2.mes) && (d1.dia == d2.dia)) // verifica se datas são iguais.
        return 1; // verdadeiro
    return 0;     // falso
}

int eh_igual_hora(Hora d1, Hora d2)
{
    if ((d1.hs == d2.hs) && (d1.mnto == d2.mnto))
        return 1;
    return 0;
}

int bisexto(int ano)
// ---- verifica se um ano é bisexto ------------------------
{
    if(ano%4==0 && (ano%400==0 || ano%100!=0))
        return 1;
    return 0;
}

Data cria(int dia, int mes, int ano)
{
    Data data;
    data.dia = dia;
    data.mes = mes;
    data.ano = ano;
    return data;
}

Hora cria_hora(int hr, int min)
{
    Hora hora;
    hora.hs = hr;
    hora.mnto = min;

    return hora;
}

Data incrementa(Data d)
// Incrementa em um dia a data d
{
    Data novo_d;
    int max_dias[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    int max_meses = 12;

    //----- Considera o ano bisexto ------------------------
    if (bisexto(d.ano))
    {
        max_dias[1]=29;
    }
    //------------------------------------------------------------

    if (d.dia < max_dias[d.mes-1]) // Incrementa só precisa mudar o dia. Os meses e anos continuam inalterados.
    {
        novo_d.dia = d.dia+1;
        novo_d.mes = d.mes;
        novo_d.ano = d.ano;
    }
    else
    {
        if (d.mes < max_meses) // Além do dia, o mês é alterado para o próximo mês pois chegou ao fim.
        {
            novo_d.dia = 1;
            novo_d.mes = d.mes+1;
            novo_d.ano = d.ano;
        }
        else // chegou no fim do ano, precisa alterar o dia, o mês e o ano.
        {
            novo_d.dia = 1;
            novo_d.mes = 1;
            novo_d.ano = d.ano+1;
        }

    }

    return novo_d;
}
