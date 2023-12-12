/*
*
*    Este programa tem como objetivo permitir ao usu�rio de um sistema de loja
*    que ele possa inserir produtos, atualizar a quantidade de itens de um produto no estoque,
*    realizar uma venda com diversos produtos, consultar o preço, mostrar os produtos e sua quantidade
*    em estoque e emitir um relat�rio de faturamento de vendas em um determinado periodo.
*
*    Isso deve ser feito de modo persistente e utilizar arquivos para armazenar os seus dados.
*    Deverá ter arquivos diferentes para o armazenamento de produtos, estoque de itens de produto, e vendas.
*    Deverá ser desenvolvido utilizando diferentes arquivos de c�digo e cabeçalho.
*
*    Autora: Isabela Madureira
*    Última atualização: 12/12/2023
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "arquivo.h"
#include "arquivo.c"
#include "produto.h"
#include "produto.c"
#include "vendas.h"
#include "vendas.c"
#include "estruturas.h"

int main() {

    //declaração das variáveis
    int opcao, qtdeProd = 0, qtdeVenda = 0;
    Produto *produto = (Produto*)malloc(sizeof(Produto));
    Venda *venda = (Venda*)malloc(sizeof(Venda));

    //recebe as informações armazenadas no arquivo de produto e de venda
    produto = recupera_produtos(produto, &qtdeProd);
    venda = recupera_vendas(venda, &qtdeVenda);

    do {
        //menu e suas opções
        printf("\n\t************************************************************************"
               "\n\t\t\t     SISTEMA DA LOJA A.I COMERCIAL\n"
               "\t************************************************************************"
               "\n\n\tSelecione uma das opcoes abaixo:\n\n"
               "\t| 1. Inserir um produto\n"
               "\t| 2. Atualizar a quantidade de itens de um produto no estoque\n"
               "\t| 3. Realizar uma venda\n"
               "\t| 4. Consulta de preco de um produto\n"
               "\t| 5. Mostrar na tela os produtos e a quantidade\n"
               "\t| 6. Relatorio de faturamento de vendas em um determinado periodo\n"
               "\t| 0. Sair do Programa\n");

        //recebe o valor de opcao
        printf("\n\tOpcao: ");
        scanf("%d", &opcao);

        printf("\n========================================================================================================================");

        //acesso às opções do menu
        switch (opcao) {

            //sair do menu
            case 0:
            {
                printf("\n\tMuito obrigada por utilizar nosso programa! Ate mais :)\n");

                //limpeza do conteúdo da tela
                printf("\n\tPressione qualquer tecla para fechar o programa... \n");
                exit(1);
            }

            //inserir um produto
            case 1:
            {
                produto = insere_produto(produto, &qtdeProd);

                //limpeza do conteúdo da tela
                printf("\n\tPressione ENTER para continuar ");
                scanf("%*c%*c");
                system("clear||cls");
                break;
            }

            //atualizar a quantidade de itens de um produto no estoque
            case 2:
            {
                atualiza_estoque(produto, qtdeProd);

                //limpeza do conteúdo da tela
                printf("\n Aperte ENTER para continuar ");
                scanf("%*c");
                system("clear || cls");
                break;
            }

            //realizar uma venda
            case 3:
            {
                venda = efetua_venda(produto, qtdeProd, venda, &qtdeVenda);

                //limpeza do conteúdo da tela
                printf("\n\tPressione ENTER para continuar ");
                scanf("%*c%*c");
                system("clear||cls");
                break;

            }

            //consulta de preco de um produto
            case 4:
            {
                consulta_preco(produto, &qtdeProd);

                //limpeza do conteúdo da tela
                printf("\n\tPressione ENTER para continuar ");
                scanf("%*c%*c");
                system("clear||cls");
                break;
            }

            //mostrar na tela os produtos e a quantidade
            case 5:
            {
                mostra_estoque(produto, qtdeProd);

                //limpeza do conteúdo da tela
                printf("\n\tPressione ENTER para continuar ");
                scanf("%*c%*c");
                system("clear||cls");
                break;
            }

            //relatorio de faturamento de vendas em um determinado periodo
            case 6:
            {
                relatorio_faturamento(venda, qtdeVenda);

                //limpeza do conteudo da tela
                printf("\n\tPressione ENTER para continuar ");
                scanf("%*c%*c");
                system("clear||cls");
                break;
            }

            default:
            {
                printf("\n\tOpa, valor invalido para opcao! Escolha novamente... \n");

                //limpeza do conteúdo da tela
                printf("\n\tPressione ENTER para continuar ");
                scanf("%*c%*c");
                system("clear||cls");
                break;
            }
        }

    } while(opcao!=0);

    return 0;
}
