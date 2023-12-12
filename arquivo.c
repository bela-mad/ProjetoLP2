#include <stdlib.h>
#include <stdio.h>
#include "arquivo.h"

void salva_produto(Produto *produto, int qtdeProd) {

    FILE *fp_prod;
    fp_prod = fopen("Estoque de Produtos.txt", "wb");

    if(fp_prod == NULL){
        perror("\nNao foi possivel abrir o arquivo");
    }
    else {
        fwrite(&qtdeProd, sizeof(int), 1, fp_prod);
        fwrite(produto, sizeof(Produto), qtdeProd, fp_prod);
        fclose(fp_prod);
    }
}

Produto* recupera_produtos(Produto *produto, int *qtdeProd) {

    FILE *fp_prod;
    fp_prod = fopen("Estoque de Produtos.txt", "rb");

    if (fp_prod != NULL) {
        fread(qtdeProd, sizeof(int), 1, fp_prod);
        produto = realloc(produto, *qtdeProd * sizeof(Produto));
        fread(produto, sizeof(Produto), *qtdeProd, fp_prod);
        fclose(fp_prod);
    }
    return produto;
}

void salva_venda(Venda *venda, int qtdeVendas) {
    FILE *fp_vendas;
    fp_vendas = fopen("Vendas Feitas.txt", "wb");

    if(fp_vendas == NULL) {
        perror("\nNao foi possivel abrir o arquivo");
    }

    else {
        fwrite(&qtdeVendas,sizeof(int),1,fp_vendas);
        for(int i = 0; i < qtdeVendas; i++) {
            fwrite(&venda[i],sizeof(Venda) - sizeof(Produto*),1,fp_vendas);
            fwrite(venda[i].itens_comprados, sizeof(Produto),venda[i].qtde_itens, fp_vendas);
        }

        fclose(fp_vendas);
    }
}

Venda* recupera_vendas(Venda *venda, int *qtdeVendas) {

    FILE *fp_vendas;
    fp_vendas = fopen("VendasFeitas.txt", "rb");

    if (fp_vendas != NULL) {

        fread(qtdeVendas, sizeof(int), 1, fp_vendas);
        venda=realloc(venda, *qtdeVendas * sizeof(Venda));
        for(int i = 0; i < *qtdeVendas; i++) {
            fread(&venda[i],sizeof(Venda) - sizeof(Produto*),1,fp_vendas);
            venda[i].itens_comprados = malloc(sizeof(Produto)*venda[i].qtde_itens);
            fread(venda[i].itens_comprados,sizeof(Produto),venda[i].qtde_itens,fp_vendas);
        }

        fclose(fp_vendas);
    }

    return venda;
}

