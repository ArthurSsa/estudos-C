#include <stdio.h>
#include <string.h>
#include "tipos.h" // Certifique-se de incluir este arquivo
#include "calculo_investimento.h"
#include "gerenciamento_investimento.h"

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
    // Taxas mensais para o tipo IPCA
    float taxasIPCA[12] = {0.3, 0.25, 0.4, 0.35, 0.3, 0.25, 0.4, 0.35, 0.3, 0.25, 0.4, 0.35};

    InformacaoFinanceira investimentos[MAX_TRANSACOES];
    int totalTransacoes = 0;

    InformacaoFinanceira investimento1 = {
        .titular = {"Maria"},
        .dataAplicacao = {13, 8, 2023},
        .dataVencimento = {13, 9, 2024},
        .valorAplicado = 1000.00,
        .valorBruto = 0.0,
        .taxaJuros = 0.0,
        .imposto = 0.0,
        .tipo = IPCA
    };

    int numMeses = calcularMeses(investimento1.dataAplicacao, investimento1.dataVencimento);
    atualizarInvestimentoVariado(&investimento1, taxasIPCA, numMeses);

    adicionarInvestimento(investimentos, &totalTransacoes, investimento1);
    exibirInvestimentos(investimentos, totalTransacoes);

    return 0;
}
