#ifndef ARQUIVO_H_INCLUDED
#define ARQUIVO_H_INCLUDED
#include "produto.h"
#include "vendas.h"

void salva_produto(Produto *produto, int *qtdeProd);
void recupera_produtos(Produto *produto, int *qtdeProd);
void salva_venda(Venda *venda, int *qtdeVendas);
void recupera_vendas(Venda *venda, int *qtdeVendas);

#endif // ARQUIVO_H_INCLUDED

