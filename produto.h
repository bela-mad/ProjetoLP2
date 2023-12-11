#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED

//fazer função 1inserir_produto, 2atualizar_estoque, *4consulta_preco, 5mostra_estoque

typedef struct Tprod{

    int codigo;
    char descricao[80];
    float preco;
    int qtde;

} Produto;

void insere_produto(Produto *produto, int *qtdeProd);

void atualiza_estoque(Produto *produto, int *qtdeProd);

void consulta_preco(Produto *produto, int *qtdeProd);

void mostra_estoque(Produto *produto, int *qtdeProd);

#endif // PRODUTO_H_INCLUDED
