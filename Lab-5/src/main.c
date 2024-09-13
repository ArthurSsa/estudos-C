#include <stdio.h>
#include <string.h>

// Definições de estruturas
typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    char nome[100];
} Titular;

typedef struct {
    Titular titular;
    Data dataAplicacao;
    Data dataVencimento;
    double valorAplicado;
    double valorBruto;
    double taxaJuros;
    double imposto;
} InformacaoFinanceira;

// Função para exibir informações do investimento
void exibirInformacoes(InformacaoFinanceira investimento) {
    printf("Nome: %s\n", investimento.titular.nome);
    printf("Data de Aplicação: %02d/%02d/%d\n", investimento.dataAplicacao.dia, investimento.dataAplicacao.mes, investimento.dataAplicacao.ano);
    printf("Data de Vencimento: %02d/%02d/%d\n", investimento.dataVencimento.dia, investimento.dataVencimento.mes, investimento.dataVencimento.ano);
    printf("Valor Aplicado: %.2f\n", investimento.valorAplicado);
    printf("Valor Bruto: %.2f\n", investimento.valorBruto);
    printf("Taxa de Juros: %.2f%%\n", investimento.taxaJuros);
    printf("Imposto: %.2f\n", investimento.imposto);
}

int main() {
    InformacaoFinanceira investimento1 = {
        .titular = {"Maria"},
        .dataAplicacao = {13, 8, 2023},
        .dataVencimento = {13, 9, 2024},
        .valorAplicado = 1000.00,
        .valorBruto = 1055.54,
        .taxaJuros = 5.00,
        .imposto = 158.33
    };

    exibirInformacoes(investimento1);

    return 0;
}
