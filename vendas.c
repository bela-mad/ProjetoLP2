#include <stdlib.h>
#include <stdio.h>
#include "vendas.h"
#include "estruturas.h"
#include <time.h>

Venda *efetua_venda(Produto *produto,int qtdeProd, Venda *venda, int *qtde_vendas) {
    int cod_aux=0;
    int posicao_produto=0;
    int quant_itens=0;
    int op=0;
    int indice_nota=0;
    float valor_total_compra=0;

    time_t currentTime;
    struct tm*localTime;
    currentTime=time(NULL);
    localTime=localtime(&currentTime);

    if(*qtde_vendas) {
        venda = realloc(venda, ((*qtde_vendas) + 1) * sizeof(Venda));
    }
    venda[*qtde_vendas].qtde_itens=0;
    do {
        indice_nota=venda[*qtde_vendas].qtde_itens;
        if(indice_nota > 0) {
            venda[*qtde_vendas].itens_comprados = realloc(venda[*qtde_vendas].itens_comprados,(indice_nota+1) * sizeof(Produto));
        }
        else {
            venda[*qtde_vendas].itens_comprados = malloc(sizeof(Produto));
        }
        do {
            printf("\nDigite o codigo do produto que deseja vender: ");
            scanf("%d", &cod_aux);

            for(posicao_produto = 0; posicao_produto < (qtdeProd); posicao_produto++) {

                //verifica se o codigo recebido é igual ao de algum produto cadastrado
                if (cod_aux == produto[posicao_produto].codigo) {
                    break;
                }
            }
            if(posicao_produto == qtdeProd) {
                system("clear||cls");
                printf("\nProduto nao encontrado");
            }
        }
        while(posicao_produto == (qtdeProd));
        printf("\nDigite a quantidade que deseja: ");
        scanf("%d",&quant_itens);

        produto[posicao_produto].qtde-=quant_itens;

        salva_produto(produto, qtdeProd);
        venda[*qtde_vendas].itens_comprados[indice_nota]=produto[posicao_produto];
        venda[*qtde_vendas].itens_comprados[indice_nota].qtde=quant_itens;
        venda[*qtde_vendas].itens_comprados[indice_nota].item_venda=quant_itens*produto[posicao_produto].preco;
        valor_total_compra+=venda[*qtde_vendas].itens_comprados[indice_nota].item_venda;
        printf("\n\nValor %.2f\n\n", valor_total_compra);
        venda[*qtde_vendas].qtde_itens++;

        printf("\n\nDeseja adicionar outro produto?"
               "\n1 - Sim"
               "\n2 - Nao\n");
        scanf("%d", &op);

    } while(op != 2);

    venda[*qtde_vendas].valor_total = valor_total_compra;
    venda[*qtde_vendas].hora=localTime->tm_hour;
    venda[*qtde_vendas].minutos=localTime->tm_min;
    venda[*qtde_vendas].segundos=localTime->tm_sec;
    venda[*qtde_vendas].dia=localTime->tm_mday;
    venda[*qtde_vendas].mes=localTime->tm_mon+1;
    venda[*qtde_vendas].ano= localTime->tm_year+1900;
    venda[*qtde_vendas].codigoVenda=*qtde_vendas+1;

    (*qtde_vendas)++;

    salva_venda(venda, *qtde_vendas);

    return venda;
}

void relatorio_faturamento(Venda *venda, int qtde_vendas)
{
    int mes=0, ano=0;
    float faturamento=0;

    printf("\nInsira o mes de faturamento que deseja: ");
    scanf("%d", &mes);

    printf("\nInsira o ano de faturamento que deseja: ");
    scanf("%d", &ano);

    for(int i= 0; i < qtde_vendas; i++) {
        if( (mes == venda[i].mes) && (ano == venda[i].ano)) {

            printf("\n\nCodigo da Venda: %d\n", venda[i].codigoVenda);
            printf("\nHorario: %2d:%2d:%2d\n"
                   "Data: %2d/%2d/%2d\n", venda[i].hora, venda[i].minutos,
                   venda[i].segundos, venda[i].dia, venda[i].mes, venda[i].ano);
            printf("\nValor\t\t\tR$ %.2f\n\n", venda[i].valor_total);
            printf("__________________________________________________");
            faturamento+=venda[i].valor_total;
        }
    }
    printf("\n\n Total do faturamento: %.2f", faturamento);
}
