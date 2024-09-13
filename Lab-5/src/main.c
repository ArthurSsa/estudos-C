#include <stdio.h>
#include <string.h>
#include "calculo_investimento.h"
#include "gerenciamento_investimento.h"

// Função para exibir informações do investimento
void exibirInformacoes(InformacaoFinanceira investimento) {
    printf("Nome: %s\n", investimento.nome);
    printf("Data de Aplicação: %02d/%02d/%d\n", investimento.dataAplicacao.dia, investimento.dataAplicacao.mes, investimento.dataAplicacao.ano);
    printf("Data de Vencimento: %02d/%02d/%d\n", investimento.dataVencimento.dia, investimento.dataVencimento.mes, investimento.dataVencimento.ano);
    printf("Valor Aplicado: %.2f\n", investimento.valorAplicado);
    printf("Valor Bruto: %.2f\n", investimento.valorBruto);
    printf("Taxa de Juros: %.2f%%\n", investimento.taxaJuros);
    printf("Imposto: %.2f\n", investimento.imposto);
}

int main() {
    InformacaoFinanceira investimentos[MAX_TRANSACOES];
    int totalTransacoes = 0;

    InformacaoFinanceira investimento1 = {
        .nome = "Maria",
        .dataAplicacao = {13, 8, 2023},
        .dataVencimento = {13, 8, 2024},
        .valorAplicado = 1000.00,
        .taxaJuros = 5.00,
        .tipo = PREFIXADO
    };

    InformacaoFinanceira investimento2 = {
        .nome = "João",
        .dataAplicacao = {1, 1, 2023},
        .dataVencimento = {1, 1, 2024},
        .valorAplicado = 2000.00,
        .taxaJuros = 7.00,
        .tipo = IPCA
    };

    InformacaoFinanceira investimento3 = {
        .nome = "Ana",
        .dataAplicacao = {1, 1, 2023},
        .dataVencimento = {1, 1, 2024},
        .valorAplicado = 1500.00,
        .taxaJuros = 6.00,
        .tipo = SELIC
    };

    InformacaoFinanceira investimento4 = {
        .nome = "Carlos",
        .dataAplicacao = {1, 1, 2023},
        .dataVencimento = {1, 1, 2024},
        .valorAplicado = 2500.00,
        .taxaJuros = 8.00,
        .tipo = CDI
    };

    // Atualiza os investimentos
    atualizarInvestimento(&investimento1);
    atualizarInvestimento(&investimento2);
    atualizarInvestimento(&investimento3);
    atualizarInvestimento(&investimento4);

    // Adiciona investimentos
    adicionarInvestimento(investimentos, &totalTransacoes, investimento1);
    adicionarInvestimento(investimentos, &totalTransacoes, investimento2);
    adicionarInvestimento(investimentos, &totalTransacoes, investimento3);
    adicionarInvestimento(investimentos, &totalTransacoes, investimento4);

    // Exibe investimentos
    exibirInvestimentos(investimentos, totalTransacoes);

    return 0;
}
