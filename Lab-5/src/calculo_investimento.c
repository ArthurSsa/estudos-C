#include "calculo_investimento.h"
#include <stdio.h>
#include <math.h>

// Calcula a diferença em dias entre duas datas
int calcularDias(Data data1, Data data2) {
    // Simplesmente calcula a diferença entre anos e meses, sem considerar os dias exatos
    int dias = (data2.ano - data1.ano) * 365 + (data2.mes - data1.mes) * 30 + (data2.dia - data1.dia);
    return dias;
}

// Calcula o número de meses entre duas datas
int calcularMeses(Data data1, Data data2) {
    int anos = data2.ano - data1.ano;
    int meses = anos * 12 + (data2.mes - data1.mes);
    return meses;
}

// Atualiza o valor bruto do investimento
void atualizarInvestimento(InformacaoFinanceira *investimento) {
    int meses = calcularMeses(investimento->dataAplicacao, investimento->dataVencimento);
    double taxaMensal = investimento->taxaJuros / 100 / 12;

    // Atualiza valor bruto de acordo com o tipo de investimento
    switch (investimento->tipo) {
        case PREFIXADO:
        case IPCA:
        case SELIC:
        case CDI:
            investimento->valorBruto = investimento->valorAplicado * pow(1 + taxaMensal, meses);
            break;
        default:
            investimento->valorBruto = investimento->valorAplicado; // Sem taxa, apenas valor aplicado
            break;
    }
    
    // Calcula imposto (supondo 15% sobre o valor bruto)
    investimento->imposto = investimento->valorBruto * 0.15;
}
