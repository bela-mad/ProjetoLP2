#include <stdlib.h>
#include <stdio.h>
#include "arquivo.h"

void salva_produto(Produto *produto, int *qtdeProd){

    FILE *fp_prod;
    fp_prod = fopen("Estoque de Produtos.txt", "w");

    if(fp_prod == NULL){
        perror("\nNão foi possivel abrir o arquivo");
    }

    else{
        fwrite(produto, sizeof(Produto), qtdeProd, fp_prod);
        fclose(fp_prod);
        printf("\nProduto salvo com sucesso!");
    }
}

void recupera_produtos(Produto *produto, int *qtdeProd) {

    FILE *fp_prod;
    fp_prod = fopen("Estoque de Produtos.txt", "r");

    if (fp_prod != NULL) {

        produto = (Produto*)realloc(produto, *qtdeProd * sizeof(Produto));
        size_t items_read = fread(produto, sizeof(Produto), *qtdeProd, fp_prod);
        fclose(fp_prod);
        printf("\nLista de produtos recuperada com sucesso!");
    }
}

void salva_venda(Venda *venda, int *qtdeVendas){
    FILE *fp_vendas;
    fp_vendas = fopen("VendasFeitas.txt", "w");

    if(fp_vendas == NULL){
        perror("\nNão foi possivel abrir o arquivo");
    }
    else{
        fwrite(venda, sizeof(Venda), qtdeVendas, fp_vendas);
        fclose(fp_vendas);
        printf("\nVenda salva com sucesso!");
    }
}

void recupera_vendas(Venda *venda, int *qtdeVendas){

    *qtdeVendas = 0;

    FILE *fp_vendas;
    fp_vendas = fopen("VendasFeitas.txt", "r");

    if (fp_vendas != NULL) {

        venda = (Venda*)realloc(venda,(*qtdeVendas)*sizeof(Venda));

        size_t items_read = fread(venda, sizeof(Venda), *qtdeVendas, fp_vendas);
        fclose(fp_vendas);
        printf("\nLista de vendas recuperada com sucesso!");
    }
}
