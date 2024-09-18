#ifndef TIPOS_H
#define TIPOS_H

#define MAX_TRANSACOES 100

// Definição da estrutura Data
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

// Enum para tipos de investimento
typedef enum {
    PREFIXADO,
    IPCA,
    SELIC,
    CDI
} TipoInvestimento;

// Estrutura para armazenar as informações de um investimento
typedef struct {
    char nome[100];           // Nome do titular
    Data dataAplicacao;
    Data dataVencimento;
    double valorAplicado;
    double valorBruto;
    double taxaJuros;
    double imposto;
    TipoInvestimento tipo;     // Tipo do investimento
} InformacaoFinanceira;

#endif // TIPOS_H
