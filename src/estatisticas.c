#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/structs.h"
#include "../include/cores.h"
#include "../include/tabela.h"
#include "../include/utils.h"


/**
 * @brief Método responsável por mostrar a quantidade 
 * de sorteios de um determinado número
 * 
 * @param tabelaHash
 */
void qtdSorteiosPorNumero(TabelaHash *tabelaHash) {
    if(tabelaHash->qtdSorteios > 0) {
        int cont = 0;
        int numero;

        printCiano("Você deseja saber a quantidade de sorteios de qual número? ");
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
            printAmarelo("\nNão encontramos nenhum sorteio do número [");
            printf("%i", numero);
            printAmarelo("] dentre os");
            printf(" %i ", tabelaHash->qtdSorteios);
            printAmarelo("armazenados!\n");

        } else {
            printVerde("\nEncontramos um total de [");
            printf("%i", cont);
            printVerde("] sorteios para o número [");
            printf("%i", numero);
            printVerde("] dentre os");
            printf(" %i ", tabelaHash->qtdSorteios);
            printVerde("sorteios armazenados!\n");
        }
    } else {
        printAmarelo("Não existem concursos armazenados na tabela!\n");
    }
}


/**
 * @brief Método responsável por mostrar a quantidade de
 * sorteios realizados em determinado ano e as suas informações
 * 
 * @param tabelaHash
 */
void qtdSorteiosPorAno(TabelaHash *tabelaHash) {
    if(tabelaHash->qtdSorteios > 0) {
        int cont = 0;
        char ano[4];

        printCiano("Você deseja saber a quantidade de sorteios de qual ano? ");
        scanf("%s", ano);

        for(int i = 0; i < tabelaHash->tamanho; i++) {
            No *no = tabelaHash->tabela[i];

            while(no != NULL) {
                if(strstr(no->sorteio.data, ano) != 0) {
                    cont++;
                    imprimirSorteio(no->sorteio);
                }
                no = no->proximo;
            }
        }

        if(cont == 0) {
            printAmarelo("\nNão encontramos nenhum sorteio no ano [");
            printf("%s", ano);
            printAmarelo("] dentre os");
            printf(" %i ", tabelaHash->qtdSorteios);
            printAmarelo("armazenados!\n");
        } else {
            printVerde("\nEncontramos um total de [");
            printf("%i", cont);
            printVerde("] sorteios no ano de [");
            printf("%s", ano);
            printVerde("] dentre os");
            printf(" %i ", tabelaHash->qtdSorteios);
            printVerde("sorteios armazenados!\n");
        }
    } else {
        printAmarelo("Não existem concursos armazenados na tabela!\n");
    }
}


/**
 * @brief Método responsável por mostrar os 10 números mais sorteados
 * 
 * @param tabelaHash
 */
void dezNumerosMaisSorteados(TabelaHash *tabelaHash) {
    if(tabelaHash->qtdSorteios > 0) {
        NumerosSorteados numerosSorteados[60];
        for(int i = 0; i < 60; i++) {
            numerosSorteados[i].numero = tabelaHash->numerosSorteados[i].numero;
            numerosSorteados[i].qtd = tabelaHash->numerosSorteados[i].qtd;
        }

        ordenarNumerosSorteados(numerosSorteados);

        printMagenta("Estes são os 10 números mais sorteados:\n");
        for(int i = 59; i >= 50; i--) {
            printf("Número: %i - %i ocorrências\n", numerosSorteados[i].numero, numerosSorteados[i].qtd);
        }

    } else {
        printAmarelo("Não existem concursos armazenados na tabela!\n");
    }

}


/**
 * @brief Método responsável por mostrar os 10 números menos sorteados
 * 
 * @param tabelaHash
 */
void dezNumerosMenosSorteados(TabelaHash *tabelaHash) {
    if(tabelaHash->qtdSorteios > 0) {
        NumerosSorteados numerosSorteados[60];
        for(int i = 0; i < 60; i++) {
            numerosSorteados[i].numero = tabelaHash->numerosSorteados[i].numero;
            numerosSorteados[i].qtd = tabelaHash->numerosSorteados[i].qtd;
        }

        ordenarNumerosSorteados(numerosSorteados);

        printMagenta("Estes são os 10 números menos sorteados:\n");
        for(int i = 0; i < 10; i++) {
            printf("Número: %i - %i ocorrências\n", numerosSorteados[i].numero, numerosSorteados[i].qtd);
        }
    } else {
        printAmarelo("Não existem concursos armazenados na tabela!\n");
    }
}

