#include <stdio.h>
#include <stdlib.h>
#include "../include/structs.h"
#include "../include/tabela.h"
#include "../include/estatisticas.h"
#include "../include/cores.h"


void iniciarTabela(TabelaHash *tabelaHash) {
    tabelaHash->qtdSorteios = 0;
    tabelaHash->tamanho = 10;
    tabelaHash->tabela = malloc(sizeof(No*) * tabelaHash->tamanho);
    for(int i = 0; i < tabelaHash->tamanho; i++) {
        tabelaHash->tabela[i] = NULL;
    }
}


void imprimirSorteio(Sorteio sorteio) {
    printf("Sorteio: %i\tData: %s\tNúmeros Sorteados: ", sorteio.codigo, sorteio.data);
    for(int j = 0; j < 6; j++) {
        printf("%i\t", sorteio.numSorteados[j]);
    }
    printf("\n");
}


void inserirConcurso(TabelaHash *tabelaHash) {
    Sorteio sorteio;
    printCiano("Qual o número do sorteio que você deseja criar? ");
    scanf("%i", &sorteio.codigo);
    printCiano("Em qual data ocorreu o sorteio? ");
    scanf("%s", sorteio.data);
    for(int i = 0; i < 6; i++) {
        printCiano("Qual foi o");
        printf(" %iº ", i+1);
        printCiano("número sorteado? ");
        scanf("%i", &sorteio.numSorteados[i]);
    }

    inserirConcursoTabela(tabelaHash, sorteio, sorteio.codigo);
}


void buscarConcurso(TabelaHash *tabelaHash) {
    int chave = 0;

    printCiano("Qual o número do sorteio que você deseja buscar? ");
    scanf("%i", &chave);

    Sorteio *sorteio = buscarConcursoTabela(tabelaHash, chave);

    if(sorteio == NULL) {
        printAmarelo("\nSorteio com a chave [");
        printf("%i", chave);
        printAmarelo("] não encontrado!\n");
    } else {
        imprimirSorteio(*sorteio);
    }

}


void removerConcurso(TabelaHash *tabelaHash) {

    int chave = 0;

    printCiano("Qual o número do sorteio que você deseja buscar? ");
    scanf("%i", &chave);

    removerConcursoTabela(tabelaHash, chave);

}


void visualizarConcursos(TabelaHash *tabelaHash) {
    if(tabelaHash->qtdSorteios > 0) {
        printMagenta("Lista de sorteios presentes na tabela:\n");
        for(int i = 0; i < tabelaHash->tamanho; i++) {
            if(tabelaHash->tabela[i] != NULL) {
                No *temp = tabelaHash->tabela[i];
                while(temp != NULL) {
                    imprimirSorteio(temp->sorteio);
                    temp = temp->proximo;
                }
            }
        }

    } else {
        printAmarelo("Não existem concursos armazenados na tabela!\n");
    }
}


void carregarConcursosArquivo(TabelaHash *tabelaHash) {
    char nomeArquivo[200];

    printCiano("Por favor, nos informe o caminho do arquivo ao qual deseja recuperar os dados: ");
    scanf("%s", nomeArquivo);

    carregarConcursosArquivoTabela(tabelaHash, nomeArquivo);
}


void apresentarEstatisticas(TabelaHash *tabela) {
    int opcao = 0;

    while(opcao < 1 || opcao > 4) {
        printCiano("Informe qual estatística deseja visualizar:\n");
        printCiano("1 - Quantidade de sorteios de um número\t\t\t");
        printCiano("3 - Dez Números Mais Sorteados\n");
        printCiano("2 - Quantidade de concursos em um determinado ano\t");
        printCiano("4 - Dez Números Menos Sorteados\n");

        scanf("%i", &opcao);
        if(opcao >= 1 && opcao <= 4) {
            switch (opcao) {
                case 1:
                    printVerde("Você escolheu a opção: 1 - Quantidade de sorteios de um número\n\n");
                    qtdSorteiosPorNumero(tabela);
                    break;
                case 2:
                    printVerde("Você escolheu a opção: 2 - Quantidade de concursos em um determinado ano\n\n");
                    qtdSorteiosPorAno(tabela);
                    break;
                case 3:
                    printVerde("Você escolheu a opção: 3 - Dez Números Mais Sorteados\n\n");
                    dezNumerosMaisSorteados(tabela);
                    break;
                case 4:
                    printVerde("Você escolheu a opção: 4 - Dez Números Menos Sorteados\n\n");
                    dezNumerosMenosSorteados(tabela);
                    break;
                default:
                    break;
            }
        } else {
            printVermelho("\nEscolha uma opção válida!\n\n");
        }
    }
}