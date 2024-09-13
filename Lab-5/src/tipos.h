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
    char nome[100];  // Campo 'nome' definido aqui
} Titular;

typedef struct {
    Titular titular;  // 'Titular' é uma estrutura que contém o campo 'nome'
    Data dataAplicacao;
    Data dataVencimento;
    double valorAplicado;
    double valorBruto;
    double taxaJuros;
    double imposto;
    TipoInvestimento tipo;
} InformacaoFinanceira;

#define MAX_TRANSACOES 100  // Definindo o número máximo de transações

#endif // TIPOS_H
