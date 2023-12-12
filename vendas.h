#ifndef VENDAS_H_INCLUDED
#define VENDAS_H_INCLUDED
#include "estruturas.h"

Venda *efetua_venda(Produto *produto,int qtdeProd, Venda *venda, int *qtde_vendas);
void relatorio_faturamento(Venda *venda, int qtde_vendas);


#endif // VENDAS_H_INCLUDED
