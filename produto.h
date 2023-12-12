#ifndef PRODUTO_H_INCLUDED
#define PRODUTO_H_INCLUDED
#include "estruturas.h"

Produto* insere_produto(Produto *produto, int *qtdeProd);
void atualiza_estoque(Produto *produto, int qtdeProd);
void consulta_preco(Produto *produto, int *qtdeProd);
void mostra_estoque(Produto *produto, int qtdeProd);


#endif // PRODUTO_H_INCLUDED
