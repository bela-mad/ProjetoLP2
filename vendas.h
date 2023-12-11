#ifndef VENDAS_H_INCLUDED
#define VENDAS_H_INCLUDED

typedef struct Tvenda
{
    int codigoVenda;
    int dia;
    int mes;
    int ano;
    int hora;
    int minutos;
    int segundos;
    int qtde_itens;
    float valor_total;

} Venda;

#endif // VENDAS_H_INCLUDED
