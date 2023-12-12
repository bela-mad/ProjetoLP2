#include <stdlib.h>
#include <stdio.h>
#include "produto.h"
#include "estruturas.h"

Produto* insere_produto(Produto *produto, int *qtdeProd) {

    int codigoAux = 0, retorno = 1;
    if (*qtdeProd) {
        produto = (Produto*)realloc(produto,((*qtdeProd) + 1)*sizeof(Produto));
    }

    do {
        retorno = 1;
        printf("\nDigite o codigo do produto: ");
        scanf("%d", &codigoAux);
        scanf("%*c");

        for(int cont = 0; cont < (*qtdeProd); cont++) {
            //verifica se o codigo recebido é igual ao de algum produto cadastrado
            if(codigoAux == produto[cont].codigo) {
                printf("\n\tOpa, ja existe um produto cadastrado com esse codigo...\n");
                retorno = 0;
                break;
            }
        }
    }

    while(retorno == 0);
    produto[*qtdeProd].codigo = codigoAux;
    printf("\nDigite a descricao do produto: ");
    scanf("%79[^\n]", produto[*qtdeProd].descricao);
    scanf("%*c");

    printf("\nDigite o preco do produto: ");
    scanf("%f", &produto[*qtdeProd].preco);

    produto[(*qtdeProd)].qtde=0;
    (*qtdeProd)++;
    salva_produto(produto, *qtdeProd);

    return produto;
}

void atualiza_estoque(Produto *produto, int qtdeProd) {

    int aux_cod=0;
    int cont=0;
    int verifica_cod=0;
    int novo_estoque=0;
    int op_atualiza=-1;
    int op_update;

    if(qtdeProd==0) {
        printf("\n Nao existem produtos cadastrados no sistema...");
    }

    else {
        printf("\n1. Inserir Itens");
        printf("\n2. Excluir Itens");

        printf("\n\n Informe a opcao desejada: ");
        scanf("%d",&op_update);

        while(op_update!= 1 && op_update!= 2) {
            printf("\n Opcao invalida! ");
            printf("\n Informe a opcao desejada: ");
            scanf("%d",&op_update);
        }

        if(qtdeProd>0 && op_update==1) {
            do {
                printf("\n Informe o codigo do produto que deseja atualizar o estoque: ");
                scanf("%d",&aux_cod);

                for(cont=0; cont<qtdeProd; cont++) {
                    if(aux_cod==produto[cont].codigo) {

                        verifica_cod=1;
                        printf("\n-----------------------");
                        printf("\n Descricao: %s ",produto[cont].descricao);
                        printf("\n Estoque: %d ",produto[cont].qtde);
                        printf("\n-----------------------");
                        printf("\n Informe a quantidade de itens que deseja adicionar ao estoque do produto: ");
                        scanf("%d%*c",&novo_estoque);

                        while(novo_estoque<0) {

                            printf("\n Opa, valor invalido! Digite um valor maior o igual a 0...");
                            printf("\n Informe a quantidade de itens que deseja adicionar ao estoque do produto: ");
                            scanf("%d",&novo_estoque);
                            scanf("%*c");

                        }

                        produto[cont].qtde+= novo_estoque;
                        printf("\n Estoque atualizado com sucesso!");
                        break;
                    }
                }

                op_atualiza=0;

                if(verifica_cod==0) {
                    printf("\n Opa, esse codigo nao pertence a nenhum produto do sistema... \n");
                    printf("\n Deseja retornar ao menu para consultar o codigo do produto que deseja comprar?");
                    printf("\n (Digite 0 para retornar ao menu ou digite 1 para tentar novamente)\n");
                    scanf("%d%*c",&op_atualiza);
                }
            }
            while(op_atualiza!=0);
        }

        else if(qtdeProd>0 && op_update==2) {
            do {
                printf("\n Informe o codigo do produto que deseja atualizar o estoque: ");
                scanf("%d",&aux_cod);

                for(cont=0; cont<qtdeProd; cont++) {
                    if(aux_cod==produto[cont].codigo) {

                        verifica_cod=1;
                        printf(" Descricao: %s ",produto[cont].descricao);
                        printf(" Estoque: %d ",produto[cont].qtde);
                        printf("\n Informe a quantidade de itens que deseja excluir do estoque do produto: ");
                        scanf("%d",&novo_estoque);
                        scanf("%*c");

                        while(novo_estoque<0) {
                            printf("\n Opa, valor invalido! Digite um valor maior o igual a 0...");
                            printf("\n Informe a quantidade de itens que deseja excluir do estoque do produto: ");
                            scanf("%d",&novo_estoque);
                            scanf("%*c");
                        }

                        produto[cont].qtde-= novo_estoque;
                        printf("\n Estoque atualizado com sucesso!");

                        break;
                    }
                }
                op_atualiza=0;

                if(verifica_cod==0) {
                    printf("\n O codigo informado nao pertence a nenhum produto do sistema ");
                    printf("\n Deseja retornar ao menu para consultar o codigo do produto que deseja comprar? : ");
                    printf("\n(Digite 0 para retornar ao menu ou digite 1 para tentar novamente)\n");
                    scanf("%d%*c",&op_atualiza);
                }

            }
            while(op_atualiza!=0);

        }
        salva_produto(produto, qtdeProd);
    }
}

void consulta_preco(Produto *produto, int *qtdeProd) {

    int codigoAux=0, verifica=0;

    printf("\n\tDigite o codigo do produto que voce deseja saber o preco: ");
    scanf("%d", &codigoAux);

    for(int cont = 0; cont < (*qtdeProd) ; cont++) {
        if(codigoAux == produto[cont].codigo) {
            printf("\n\tO preco do produto %d eh R$%.2f\n", produto[cont].codigo, produto[cont].preco);
            verifica=1;
            break;
        }
    }

    if((verifica=0)) {
        printf("\n\tProduto nao encontrado\n");
    }
}

void mostra_estoque(Produto *produto, int qtdeProd) {

    if(!qtdeProd) {
        printf("\n\nNao ha nenhum produto registrado...\n");
    }
    else {
        printf("\n\n*************** Lista de produtos **************");
        printf("\n         Total de %d produtos cadastrados\n", qtdeProd);
        for(int i = 0; i < qtdeProd; i++) {

            printf("\n****************** Produto %d ******************\n", i+1);
            printf("\nDescricao do produto: %s", produto[i].descricao);
            printf("\nCodigo do produto: %d", produto[i].codigo);
            printf("\nPreco do produto: R$%.2f", produto[i].preco);
            printf("\nEstoque do produto: %d", produto[i].qtde);

            if(produto[i].qtde < 0) {
                printf("\nHa uma irregularidade no estoque desse produto. Verifique o estoque fisico...");
            }
            printf("\n\n************************************************\n");
        }
    }
}
