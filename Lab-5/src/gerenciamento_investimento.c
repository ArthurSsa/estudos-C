#include "gerenciamento_investimento.h"
#include <stdio.h>

#define MAX_TRANSACOES 100

// Adiciona um investimento à lista de transações
void adicionarInvestimento(InformacaoFinanceira *transacoes, int *totalTransacoes, InformacaoFinanceira investimento) {
    if (*totalTransacoes < MAX_TRANSACOES) {
        transacoes[*totalTransacoes] = investimento;
        (*totalTransacoes)++;
    } else {
        printf("Número máximo de transações atingido.\n");
    }
}

// Exibe informações sobre todos os investimentos
void exibirInvestimentos(InformacaoFinanceira *transacoes, int totalTransacoes) {
    for (int i = 0; i < totalTransacoes; i++) {
        InformacaoFinanceira investimento = transacoes[i];
        printf("Nome: %s\n", investimento.titular.nome);  // Verifique se a estrutura tem esse campo
        printf("Data de Aplicação: %02d/%02d/%d\n", investimento.dataAplicacao.dia, investimento.dataAplicacao.mes, investimento.dataAplicacao.ano);
        printf("Data de Vencimento: %02d/%02d/%d\n", investimento.dataVencimento.dia, investimento.dataVencimento.mes, investimento.dataVencimento.ano);
        printf("Valor Aplicado: %.2f\n", investimento.valorAplicado);
        printf("Valor Bruto: %.2f\n", investimento.valorBruto);
        printf("Taxa de Juros: %.2f%%\n", investimento.taxaJuros);
        printf("Imposto: %.2f\n", investimento.imposto);
        printf("-----------------------------\n");
    }
}
