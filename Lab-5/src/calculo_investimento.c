#include "calculo_investimento.h"
#include <stdio.h>
#include <math.h>

int calcularDias(Data data1, Data data2) {
    int dias = (data2.ano - data1.ano) * 365 + (data2.mes - data1.mes) * 30 + (data2.dia - data1.dia);
    return dias;
}

int calcularMeses(Data data1, Data data2) {
    int anos = data2.ano - data1.ano;
    int meses = anos * 12 + (data2.mes - data1.mes);
    return meses;
}

void atualizarInvestimentoVariado(InformacaoFinanceira *investimento, float *taxasMensais, int numMeses) {
    double valor = investimento->valorAplicado;
    for (int i = 0; i < numMeses; i++) {
        double taxaMensal = taxasMensais[i] / 100;
        valor *= (1 + taxaMensal);
    }
    investimento->valorBruto = valor;
    investimento->imposto = investimento->valorBruto * 0.15; // Supondo imposto de 15%
}
