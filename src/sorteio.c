#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/structs.h"
#include "../include/sorteio.h"
#include "../include/tabela.h"



void criarSorteio(TabelaHash *tabelaHash) {
    Sorteio sorteio;
    printf("Qual o número do sorteio que você deseja criar? ");
    scanf("%i", &sorteio.codigo);
    printf("Em qual data ocorreu o sorteio? ");
    scanf("%s", sorteio.data);
    printf("Qual foram os números sorteados?\n");
    for(int i = 0; i < 6; i++) {
        printf("%iº: ", i+1);
        scanf("%i", &sorteio.numSorteados[i]);
    }
    printSorteio(tabelaHash, &sorteio);
    inserirConcursoTabela(tabelaHash, sorteio, sorteio.codigo);
}


void criarSorteioByArquivo(TabelaHash *tabela, int numSorteio, char *data, int *numSorteados) {
    Sorteio sorteio;

    sorteio.codigo = numSorteio;
    strcpy(sorteio.data, data);
    for(int i = 0; i < 6; i++) {
        sorteio.numSorteados[i] = numSorteados[i];
    }

    inserirConcursoTabela(tabela, sorteio, sorteio.codigo);
}


void printSorteio(TabelaHash *tabela, Sorteio *sorteio) {
    if(sorteio == NULL) {
        printf("Não encontrado!\n");
        return;
    }
    printf("%i - %s - ", sorteio->codigo, sorteio->data);
    for(int i = 0; i < 6; i++) {
        if(i < 5) {
            printf("%i, ", sorteio->numSorteados[i]);
        } else {
            printf("%i\n", sorteio->numSorteados[i]);
        }
    }
}