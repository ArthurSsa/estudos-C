#include <stdio.h>
#include <string.h>
#include "calculo_investimento.h"
#include "gerenciamento_investimento.h"
#include "tipos.h"
#include "dados_taxas.h"

#define MAX_TRANSACOES 100

// Função para exibir informações do investimento
void exibirInformacoes(InformacaoFinanceira investimento) {
    printf("Nome: %s\n", investimento.nome);
    printf("Data de Aplicação: %02d/%02d/%d\n", investimento.dataAplicacao.dia, investimento.dataAplicacao.mes, investimento.dataAplicacao.ano);
    printf("Data de Vencimento: %02d/%02d/%d\n", investimento.dataVencimento.dia, investimento.dataVencimento.mes, investimento.dataVencimento.ano);
    printf("Valor Aplicado: %.2f\n", investimento.valorAplicado);
    printf("Valor Bruto: %.2f\n", investimento.valorBruto);
    printf("Taxa de Juros: %.2f%%\n", investimento.taxaJuros);
    printf("Imposto: %.2f\n", investimento.imposto);
    printf("-----------------------------\n");
}

int main() {
    // Inicializando as transações e o número total de transações
    InformacaoFinanceira transacoes[MAX_TRANSACOES];
    int totalTransacoes = 0;

    // Adicionando uma transação
    InformacaoFinanceira investimento1 = {
        .nome = "Selic",
        .dataAplicacao = {25, 3, 2021},
        .dataVencimento = {25, 3, 2022},
        .valorAplicado = 500.00,
        .taxaJuros = 7.5,
        .tipo = SELIC
    };

    adicionarInvestimento(transacoes, &totalTransacoes, investimento1);

    // Atualizando o valor bruto e o imposto da transação com rendimentos variáveis
    if (investimento1.tipo == IPCA) {
        atualizarInvestimento(&transacoes[0], taxasIPCA, 12);
    } else {
        atualizarInvestimento(&transacoes[0], NULL, 0);
    }

    // Adicionando outra transação
    InformacaoFinanceira investimento2 = {
        .nome = "LCA agro",
        .dataAplicacao = {29, 3, 2021},
        .dataVencimento = {29, 3, 2023},
        .valorAplicado = 100.00,
        .taxaJuros = 6.0,
        .tipo = CDI
    };

    adicionarInvestimento(transacoes, &totalTransacoes, investimento2);

    // Atualizando o valor bruto e o imposto da segunda transação
    if (investimento2.tipo == IPCA) {
        atualizarInvestimento(&transacoes[1], taxasIPCA, 12);
    } else {
        atualizarInvestimento(&transacoes[1], NULL, 0);
    }

    // Exibindo as informações do titular e suas transações
    printf("Titular: Maria\n\n");
    exibirInvestimentos(transacoes, totalTransacoes);

    // Calculando e exibindo o valor bruto e líquido total
    printf("Valor Bruto Total: R$%.2f\n", calcularValorBrutoTotal(transacoes, totalTransacoes));
    printf("Valor Líquido Total: R$%.2f\n", calcularValorLiquidoTotal(transacoes, totalTransacoes));

    return 0;
}
