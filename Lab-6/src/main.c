#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculo_investimento.h"
#include "gerenciamento_investimento.h"
#include "tipos.h"

// Declaração de um array para armazenar os investimentos
InformacaoFinanceira transacoes[MAX_TRANSACOES];
int totalTransacoes = 0;

// Função para exibir o menu
void exibirMenu() {
    printf("\n--- Menu de Gerenciamento de Investimentos ---\n");
    printf("1. Adicionar investimento\n");
    printf("2. Editar investimento\n");
    printf("3. Ver todos os investimentos\n");
    printf("4. Deletar investimento\n");
    printf("5. Sair\n");
    printf("Escolha uma opção: ");
}

// Função para ler as informações do investimento do usuário
InformacaoFinanceira lerInvestimento() {
    InformacaoFinanceira investimento;

    printf("Nome do titular: ");
    scanf("%s", investimento.nome);

    printf("Data de Aplicação (dd mm aaaa): ");
    scanf("%d %d %d", &investimento.dataAplicacao.dia, &investimento.dataAplicacao.mes, &investimento.dataAplicacao.ano);

    printf("Data de Vencimento (dd mm aaaa): ");
    scanf("%d %d %d", &investimento.dataVencimento.dia, &investimento.dataVencimento.mes, &investimento.dataVencimento.ano);

    printf("Valor aplicado: ");
    scanf("%lf", &investimento.valorAplicado);

    printf("Taxa de juros (em %%): ");
    scanf("%lf", &investimento.taxaJuros);

    printf("Tipo de investimento (0: PREFIXADO, 1: IPCA, 2: SELIC, 3: CDI): ");
    int tipo;
    scanf("%d", &tipo);
    investimento.tipo = tipo;

    atualizarInvestimento(&investimento);  // Calcula o valor bruto e imposto

    return investimento;
}

// Função para editar um investimento
void editarInvestimento() {
    int index;
    printf("Digite o índice do investimento a ser editado (1 a %d): ", totalTransacoes);
    scanf("%d", &index);
    if (index > 0 && index <= totalTransacoes) {
        transacoes[index - 1] = lerInvestimento();
        printf("Investimento editado com sucesso!\n");
    } else {
        printf("Índice inválido!\n");
    }
}

// Função para deletar um investimento
void deletarInvestimento() {
    int index;
    printf("Digite o índice do investimento a ser deletado (1 a %d): ", totalTransacoes);
    scanf("%d", &index);
    if (index > 0 && index <= totalTransacoes) {
        for (int i = index - 1; i < totalTransacoes - 1; i++) {
            transacoes[i] = transacoes[i + 1];  // Move os investimentos para a esquerda
        }
        totalTransacoes--;
        printf("Investimento deletado com sucesso!\n");
    } else {
        printf("Índice inválido!\n");
    }
}

// Função para salvar os investimentos em um arquivo
void salvarInvestimentos(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para salvar os investimentos.\n");
        return;
    }
    fwrite(&totalTransacoes, sizeof(int), 1, arquivo);
    fwrite(transacoes, sizeof(InformacaoFinanceira), totalTransacoes, arquivo);
    fclose(arquivo);
    printf("Investimentos salvos com sucesso!\n");
}

// Função para carregar os investimentos a partir de um arquivo
void carregarInvestimentos(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para carregar os investimentos.\n");
        return;
    }
    fread(&totalTransacoes, sizeof(int), 1, arquivo);
    fread(transacoes, sizeof(InformacaoFinanceira), totalTransacoes, arquivo);
    fclose(arquivo);
    printf("Investimentos carregados com sucesso!\n");
}

// Função principal do programa
int main() {
    int opcao;

    // Carregar os investimentos ao iniciar
    carregarInvestimentos("investimentos.dat");

    do {
        exibirMenu();
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                InformacaoFinanceira novoInvestimento = lerInvestimento();
                adicionarInvestimento(transacoes, &totalTransacoes, novoInvestimento);
                printf("Investimento adicionado com sucesso!\n");
                break;
            }
            case 2:
                editarInvestimento();
                break;
            case 3:
                exibirInvestimentos(transacoes, totalTransacoes);
                break;
            case 4:
                deletarInvestimento();
                break;
            case 5:
                salvarInvestimentos("investimentos.dat");
                printf("Saindo do programa...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}
