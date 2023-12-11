#include <stdlib.h>
#include <stdio.h>
#include "produto.h"

void insere_produto(Produto *produto, int *qtdeProd)
{
    int codigoAux = 0, retorno = 1;
    (*qtdeProd)++;
    produto = (Produto*)realloc(produto,(*qtdeProd)*sizeof(Produto));

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &codigoAux);

    for (int cont = 0; cont <= (*qtdeProd); cont++)
    {
        //verifica se o codigo recebido é igual ao de algum produto cadastrado
        if (codigoAux == produto[cont].codigo)
        {
            printf("\n\tOpa, ja existe um produto cadastrado com esse codigo...");
            retorno = 0;
            break;
        }
    }

    //verifica se houve alteração no verificador
    //se o código já correspondia a outro produto, retorno devolve 0
    //e o programa não segue com a inserção de outras informações
    if (retorno)
    {
        printf("\nDigite a descricao do produto: ");
        scanf("%[^\n]", produto[(*qtdeProd)].descricao);
        scanf("%*c%*c");

        printf("\nDigite o preco do produto: ");
        scanf("%f", &produto[(*qtdeProd-1)].preco);

        produto[(*qtdeProd)].qtde=0;
    }
    else
    {
        qtdeProd--;
        produto = (Produto*)realloc(produto,(*qtdeProd)*sizeof(Produto));
    }
}

void atualiza_estoque (Produto *produto, int *qtdeProd)
{
    int escolha=0, quant=0, codigoAux = 0;

    printf("\nDigite o codigo do produto: \n");
    scanf("%d", &codigoAux);

    for (int aux = 0; aux < *qtdeProd ; aux++)
    {
        if (produto[aux].codigo == codigoAux)
        {
            do {
                printf("\nGostaria de adicionar ou excluir estoque?");
                printf("\n(Digite 1 para adicionar ou digite 2 para excluir)");
                scanf("%d", &escolha);

                switch(escolha)
                {

                case 1:
                {
                    printf("Produto %s", produto[aux].descricao);
                    printf("\nQuanto voce gostaria de adicionar? (Caso tenha digitado o codigo errado, digite 0) \n");
                    scanf("%d", &quant);
                    produto[aux].qtde+=quant;
                    printf("Estoque atualizado com sucesso!");
                    break;
                }
                case 2:
                {
                    printf("Produto %s", produto[aux].descricao);
                    printf("\nQuanto voce gostaria de excluir? (Caso tenha digitado o codigo errado, digite 0) \n");
                    scanf("%d", &quant);
                    produto[aux].qtde-=quant;
                    printf("Estoque atualizado com sucesso!");
                    break;
                }
                default:
                    printf("Opcao invalida, escolha novamente...");
                    break;
                }
            } while (escolha!=1 && escolha!=2);
        }

        else
        {
            printf("\nProduto nao encontrado\n");
            break;
        }
    }
}

void consulta_preco(Produto *produto, int *qtdeProd)
{

    int codigoAux=0;

    printf("\n\tDigite o codigo do produto que você deseja saber o preco: ");
    scanf("%d", &codigoAux);

    for (int aux = 0; aux < (*qtdeProd) ; aux++)
    {
        if (produto[aux].codigo == codigoAux)
        {
            printf("\n\tO preco do produto %d eh R$%.2f", produto[aux].codigo, produto[aux].preco);
            break;
        }

        else
        {
            printf("\n\tProduto nao encontrado\n");
            break;
        }
    }
}

//4
void mostra_estoque(Produto *produto, int *qtdeProd)
{
    if(!qtdeProd)
    {
        printf("\n\nNao ha nenhum produto registrado.\n");
    }
    else
    {
        printf("\n\n*************** Lista de produtos **************");
        printf("\n         Total de %d produtos cadastrados\n", *qtdeProd);
        for(int i = 0; i <= *qtdeProd; i++)
        {
            printf("\n****************** Produto %d ******************\n", i+1);
            printf("\nDescricao do produto: %s", produto[i].descricao);
            printf("\nCodigo do produto: %d", produto[i].codigo);
            printf("\nPreço do produto: R$%.2f", produto[i].preco);
            printf("\nEstoque do produto: %d", produto[i].qtde);
            if (produto[i].qtde < 0)
            {
                printf("\nHa uma irregularidade no estoque desse produto. Verifique o estoque fisico...");
            }
            printf("\n\n************************************************\n");
        }
    }
}
