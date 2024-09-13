#ifndef GERENCIAMENTO_INVESTIMENTO_H
#define GERENCIAMENTO_INVESTIMENTO_H

#include "tipos.h"

#define MAX_TRANSACOES 100  // Defina o número máximo de transações aqui

// Adiciona um investimento à lista de transações
void adicionarInvestimento(InformacaoFinanceira *transacoes, int *totalTransacoes, InformacaoFinanceira investimento);

// Exibe informações sobre todos os investimentos
void exibirInvestimentos(InformacaoFinanceira *transacoes, int totalTransacoes);

#endif // GERENCIAMENTO_INVESTIMENTO_H
