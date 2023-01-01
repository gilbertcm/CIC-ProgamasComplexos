#include<stdio.h>
#include<stdlib.h>

struct t_prod
{
    int codigo; //identificação do produto
    char nome[30]; //nome do produto
    float preco; //preço do produto
    int qtde_estoque; //qtde de itens em estoque do produto
    char fabricante[30]; //Nome do fabricante do produto
};

typedef struct t_prod Produto;

int menu()
{
    int op;

    printf("\tMENU OPCAO.");
    printf("\n1. Cadastro de Produtos.");
    printf("\n2. Mostra Produto Sem Estoque.");
    printf("\n3. Mostra Produtos do Fabricante.");
    printf("\n4. Mostra Produto Mais Caro.");
    printf("\n0. Fechar o Programa.");
    printf("\nDigite qual a opcao desejada: ");
    scanf("%d", &op);

    system("cls");
    return op;
}

//cadastra os produtos
int cadastro_produtos(char *nome_arquivo)
{
    int tam = 0;
    int continuar = 0;
    char sair;
    Produto cad;
    FILE *fp;

    fp = fopen(nome_arquivo, "wb");
    if (fp == NULL)
    {
        printf("Não foi Possivel criar arquivo!");
        exit(1);
    }

    while (continuar == 0)
    {

        printf("Digite o Codigo do Produto: ");
        scanf("%d", &cad.codigo);
        printf("Digite o nome do Produto: ");
        scanf("%s", cad.nome);
        printf("Digite o Preco do Produto: ");
        scanf("%f", &cad.preco);
        printf("Digite a qtde em estoque: ");
        scanf("%d", &cad.qtde_estoque);
        printf("Digite o nome da Fabricante: ");
        scanf("%s", cad.fabricante);

        fwrite(&cad, sizeof(Produto), 1, fp);
        tam++;

        printf("Deseja cadastrar mais produto <s/n>? ");
        scanf(" %c", &sair);
        if (sair == 'n')
        {
            continuar = -1;
        }
    }
    fclose(fp);
    return tam;
}

//consulta produtos zerado em estoque;
void mostra_prod_sem_estoque(void)
{
    Produto cad;
    FILE *fp;

    fp = fopen("Produto.dat", "rb");
    if (fp == NULL)
    {
        printf("ERRO! Arquivo nao existe!");
        exit(1);
    }

    while (!feof(fp))
    {
        fread(&cad, sizeof(Produto), 1, fp);

        if (!feof(fp))
        {
            if (cad.qtde_estoque == 0)
            {
                printf("Produto sem estoque: %s\n", cad.nome);

            }
        }

    }
    printf("=================================\n");

    fclose(fp);
}

void mostra_produtos_fab()
{
    char nome_fabricante[30];
    Produto cad;
    FILE *fp;

    printf("Digite o Nome da Fabricante: ");
    scanf("%s", nome_fabricante);

    fp = fopen("Produto.dat", "rb");
    if (fp == NULL)
    {
        printf("ERRO! Arquivo nao Existe!");
        exit(1);
    }

    while (!feof(fp))
    {
        fread(&cad, sizeof(Produto), 1, fp);

        while (feof(fp))
        {
            printf("Nenhuma Fabricante Encontrada.\n");
            break;
        }


        if (!feof(fp))
        {
            if (strcmp(nome_fabricante, cad.fabricante) == 0)
            {
                printf("Produto do fabricante: %s\n", cad.nome);
                break;
            }
        }
    }
    printf("=================================\n");

    fclose(fp);
}

void mostra_mais_caro(void)
{
    Produto cad;
    FILE *fp;

    float temp = 0;

    fp = fopen("Produto.dat", "rb");
    if (fp == NULL)
    {
        printf("ERRO! Arquivo nao Encontrado.");
        exit(1);
    }

    while (fread(&cad, sizeof(Produto), 1, fp) > 0)
    {

            if (cad.preco > temp)
            {
                temp = cad.preco;
            }
    }
    printf("Produto mais caro: %s (R$ %.2f)\n", cad.nome, temp);
    printf("=================================\n");
    fclose(fp);
}


int main()
{
    int tam;
    int opcao;

    while (opcao != 0)
    {
        opcao = menu();

        switch (opcao)
        {
        case 1:
            tam = cadastro_produtos("Produto.dat");
            break;
        case 2:
            mostra_prod_sem_estoque();
            break;
        case 3:
            mostra_produtos_fab();
            break;
        case 4:
            mostra_mais_caro();
            break;
        case 0:
            printf("Encerrando Programa!");
            break;
        default:
            printf("Opcao Invalida! Tente Novamente.\n");
            break;
        }
    }

    return 0;
}
