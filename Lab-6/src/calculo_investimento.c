#include "calculo_investimento.h"
#include <stdio.h>
#include <math.h>

// Calcula o número de dias entre duas datas
int calcularDias(Data data1, Data data2) {
    int dias = (data2.ano - data1.ano) * 365 + (data2.mes - data1.mes) * 30 + (data2.dia - data1.dia);
    return dias;
}

// Calcula o número de meses entre duas datas
int calcularMeses(Data data1, Data data2) {
    int anos = data2.ano - data1.ano;
    int meses = anos * 12 + (data2.mes - data1.mes);
    return meses;
}

// Atualiza o valor bruto e o imposto de um investimento com taxa fixa
void atualizarInvestimento(InformacaoFinanceira *investimento) {
    int dias = calcularDias(investimento->dataAplicacao, investimento->dataVencimento);
    double taxaDiaria = investimento->taxaJuros / 100.0 / 365.0;
    
    // Calcula o valor bruto baseado na fórmula de juros compostos
    investimento->valorBruto = investimento->valorAplicado * pow((1 + taxaDiaria), dias);
    
    // Calcula o imposto (por exemplo, 15% do valor bruto)
    investimento->imposto = investimento->valorBruto * 0.15;
}

// Atualiza o valor bruto do investimento com taxa variável
void atualizarInvestimentoVariado(InformacaoFinanceira *investimento, float *taxasMensais, int numMeses) {
    double valor = investimento->valorAplicado;
    for (int i = 0; i < numMeses; i++) {
        double taxaMensal = taxasMensais[i] / 100;
        valor *= (1 + taxaMensal);
    }
    investimento->valorBruto = valor;
    investimento->imposto = investimento->valorBruto * 0.15; // Supondo imposto de 15%
}
