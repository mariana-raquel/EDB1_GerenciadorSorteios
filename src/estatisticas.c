#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/structs.h"
#include "../include/tabela.h"
#include "../include/sorteio.h"


void qtdSorteiosPorNumero(TabelaHash *tabelaHash) {
    
    int cont = 0;
    int numero;

    printf("Você deseja saber a quantidade de sorteios de qual número? ");
    scanf("%i", &numero);

    for(int i = 0; i < tabelaHash->tamanho; i++) {
        No *no = tabelaHash->tabela[i];

        while(no != NULL) {
            for(int i = 0; i < 6; i++) {
                if(no->sorteio.numSorteados[i] == numero) {
                    cont++;
                }
            }
            no = no->proximo;
        }
    }

    if(cont == 0) {
        printf("Não encontramos nenhum sorteio do número %i\n", numero);
    } else {
        printf("Encontramos um total de %i de sorteios para o número %i dentre os %i sorteios armazenados!\n\n", cont, numero, tabelaHash->qtdSorteios);
    }
    

}

// * Dez Números Mais Sorteados: Mostrar os dez números que foram sorteados com maior frequência.
void dezNumerosMaisSorteados(TabelaHash *tabelaHash) {
    printf("em desenvolvimento\n");
}

// * Dez Números Menos Sorteados: Mostrar os dez números que foram sorteados com menor frequência.
void dezNumerosMenosSorteados(TabelaHash *tabelaHash) {
    printf("em desenvolvimento\n");
}

// * Quantidade de concursos em um determinado ano: Mostrar a quantidade de concursos que foram realizados em um determinado ano, bem como os seus dados
void qtdSorteiosPorAno(TabelaHash *tabelaHash) {
    int cont = 0;
    char ano[4];

    printf("Você deseja saber a quantidade de sorteios de qual ano? ");
    scanf("%s", ano);

    for(int i = 0; i < tabelaHash->tamanho; i++) {
        No *no = tabelaHash->tabela[i];

        while(no != NULL) {
            if(strstr(no->sorteio.data, ano) != 0) {
                cont++;
            }
            no = no->proximo;
        }
    }

    if(cont == 0) {
        printf("Não encontramos nenhum sorteio no ano %s\n", ano);
    } else {
        printf("Encontramos um total de %i de sorteios no ano de %s dentre os %i sorteios armazenados!\n\n", cont, ano, tabelaHash->qtdSorteios);
    }
}
