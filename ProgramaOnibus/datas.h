#ifndef DATAS_H_INCLUDED
#define DATAS_H_INCLUDED

//--------------- Estrutura de Data --------------------------
typedef struct
{
    int dia;
    int mes;
    int ano;
} Data;

//----------------------- Estrutura de Hora -----------------------------------
typedef struct
{
    int hs;
    int mnto;
} Hora;

// ---- verifica se um ano é bisexto ------------------------
int bisexto(int ano);

//------------------ Incrementa a Data em um dia---------------------------------
Data incrementa(Data d);

//---------------- Verifica se duas dadas são iguais ---------------------------
int eh_igual(Data d1, Data d2);

//---------------- Verifica se duas horas são iguais ---------------------------
int eh_igual_hora(Hora d1, Hora d2);

//-------------  Cria uma nova data -------------------------
Data cria(int dia, int mes, int ano);

//-------------  Cria uma nova hora -------------------------
Hora cria_hora(int hr, int min);
#endif // DATAS_H_INCLUDED
