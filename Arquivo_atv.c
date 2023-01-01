/*Faça um programa  chamado "Cria_arq_prod" que salve em um arquivo binário chamado "Produtos.dat", 
o Codigo_Produto, o Nome_Produto, e o Preço_Produto dos produtos de um supermercado.
Depois faça um outro programa chamadao "Consulta_Produtos" no qual o programa solicita ao usuário que digite um
código de produto e,após consulta ao arquivo, mostra na tela o  nome do produto e o seu preço de venda. 
O programa só encerra quando o usuário consulta o código de produto -1.*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct produto
{
    int codigo_produto;
    char nome_produto[30];
    float preco_produto;
}Produto;

int i = 0; //quantidade de cadastro
Produto cadastro;

int menu()
{
    int op;

    printf("\tMENU OPCAO");
    printf("\n1. Cadastra Produto.");
    printf("\n2. Consulta Produto.");
    printf("\n0. Sair do Programa.");
    printf("\nDigite a Opcao Desejada: ");
    scanf("%d", &op);

    return op;
}

int cria_arq_produto(char *nome_arquivo)
{
    int continuar = 0;
    char resposta;
    FILE *fp;

    fp = fopen(nome_arquivo, "wb"); //nome do arq passa por parametro
    if (fp == NULL)
    {
        printf("Erro! Arquivo nao existe.");
        exit(1);
    }

    while (continuar == 0)
    {
        printf("digite o codigo do produto: ");
        scanf("%d", &cadastro.codigo_produto);
        fflush(stdin);
        printf("digite o nome do produto: ");
        fgets(cadastro.nome_produto, 30, stdin);
        fflush(stdin);
        printf("digite o valor do produto: ");
        scanf("%f", &cadastro.preco_produto);
        fflush(stdin);

        fwrite(&cadastro, sizeof(Produto), 1, fp);
        i++;

        printf("Deseja cadastrar mais produto <s/n>? ");
        scanf("%c", &resposta);

        if (resposta == 'n')
        {
            continuar = 1;
        }
    }

    // for (int j = 0; j < i; j++)
    // {
    //     fwrite(&cadastro, sizeof(Produto), 1, fp);
    // }
    
    fclose(fp);
    return i;
}

void consulta_produtos(char *nome_arquivo)
{
    int codigo;

    FILE *fp;

    fp = fopen(nome_arquivo, "rb"); //nome do arquivo passa por paramtro
    if (fp == NULL)
    {
        printf("ERRO! Arquivo nao existe.");
        exit(1);
    }

        printf("\tCONSULTA PRODUTO\n");
        printf("digite o codigo do produto (-1 Sair): ");
        scanf("%d", &codigo);


    while (codigo != -1)
    {

        while (!feof(fp)) //enquanto não for final do arquivo
        {
            fread(&cadastro, sizeof(Produto), 1, fp);

            while (feof(fp)) //se final do arquivo produto ñ encontrado
            {
                printf("Produto não Encontrado!\n");
                break;
            }
            

            if (cadastro.codigo_produto == codigo) //se codigo for igual do produto
            {
                printf("\nNOME: %s", cadastro.nome_produto); //printa nome do protudo
                printf("Valor: %.2f\n", cadastro.preco_produto); //printa valor do produto
                break;
            }
        }
        rewind(fp); //Volta o indicador de posição do fluxo para a posição inicial. Isto é, o começo do arquivo.
        
        printf("\tCONSULTA PRODUTO\n");
        printf("digite o codigo do produto (-1 Sair): ");
        scanf("%d", &codigo);
    }
    
    fclose(fp);
}



int main()
{
    int qtde;
    int opcao;

    while (opcao != 0)
    {
        opcao = menu();

        switch (opcao)
        {
        case 1:
            qtde = cria_arq_produto("Produtos.dat");
            break;
        case 2:
            consulta_produtos("Produtos.dat");
            break;
        case 0:
            printf("Programa Encerrado!");
            break;
        default:
            printf("Opcao Invalida! Tente Novamente.\n");
            break;
        }
    }

    return 0;
}
