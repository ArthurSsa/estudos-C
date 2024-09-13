#ifndef TIPOS_H
#define TIPOS_H

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef enum {
    PREFIXADO,
    IPCA,
    SELIC,
    CDI
} TipoInvestimento;

typedef struct {
    char nome[100];
    Data dataAplicacao;
    Data dataVencimento;
    double valorAplicado;
    double valorBruto;
    double taxaJuros;
    double imposto;
    TipoInvestimento tipo;
} InformacaoFinanceira;

#endif // TIPOS_H
