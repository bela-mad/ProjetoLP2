#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED

typedef struct {

    int codigo;
    char descricao[80];
    float preco;
    int qtde;
    float item_venda;

} Produto;

typedef struct {

    int codigoVenda;
    int dia;
    int mes;
    int ano;
    int hora;
    int minutos;
    int segundos;
    int qtde_itens;
    float valor_total;
    Produto *itens_comprados;

} Venda;


#endif // ESTRUTURAS_H_INCLUDED
