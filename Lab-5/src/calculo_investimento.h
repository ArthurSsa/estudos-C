#ifndef CALCULO_INVESTIMENTO_H
#define CALCULO_INVESTIMENTO_H

#include "tipos.h"

// Atualiza o valor bruto do investimento
void atualizarInvestimento(InformacaoFinanceira *investimento);

// Calcula a diferença em dias entre duas datas
int calcularDias(Data data1, Data data2);

// Calcula o número de meses entre duas datas
int calcularMeses(Data data1, Data data2);

#endif // CALCULO_INVESTIMENTO_H