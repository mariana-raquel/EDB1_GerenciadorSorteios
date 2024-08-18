#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/structs.h"
#include "../include/cores.h"
#include "../include/tabela.h"
#include "../include/utils.h"


/**
 * @brief Método responsável por criar a função hash que 
 * servirá para encontrar os índices necessários
 * 
 * @param chave
 * @param tamanho
 * 
 * @return
 */
int funcaoHash(int chave, int tamanho) {
    return chave % tamanho;
}


/**
 * @brief Método responsável por inserir um sorteio na tabela
 * 
 * @param tabelaHash
 * @param sorteio
 * @param chave
 */
void inserirConcursoTabela(TabelaHash *tabelaHash, Sorteio sorteio, int chave) {
    if(buscarConcursoTabela(tabelaHash, chave) == NULL) {
        int indice = funcaoHash(chave, tabelaHash->tamanho);
        No* novo_no = malloc(sizeof(No));
        novo_no->sorteio = sorteio;
        novo_no->proximo = tabelaHash->tabela[indice];
        tabelaHash->tabela[indice] = novo_no;
        tabelaHash->qtdSorteios++;

        adicionarNumerosSorteados(tabelaHash, sorteio.numSorteados);

    } else {
        printAmarelo("\nJá existe um sorteio na tabela com o código: [");
        printf("%i", chave);
        printAmarelo("]!\n");
    }
}


/**
 * @brief Método responsável por buscar um concurso na tabela
 * através de seu código
 * 
 * @param tabelaHash
 * @param chave
 * 
 * @return
 */
Sorteio* buscarConcursoTabela(TabelaHash *tabelaHash, int chave) {
    Sorteio *sorteio = NULL;

    int indice = funcaoHash(chave, tabelaHash->tamanho);
    No* no = tabelaHash->tabela[indice];

    while(no != NULL){
        if(no->sorteio.codigo == chave) {
            return &no->sorteio;
        }
        no = no->proximo;
    }

    return sorteio;
}


/**
 * @brief Método responsável por remover um concurso na tabela
 * através de seu código
 * 
 * @param tabelaHash
 * @param chave
 */
void removerConcursoTabela(TabelaHash *tabelaHash, int chave) {
    int indice = funcaoHash(chave, tabelaHash->tamanho);
    No *no = tabelaHash->tabela[indice];

    if(no != NULL) {
        No *anterior = NULL;
        No *atual = no;

        while(atual != NULL && atual->sorteio.codigo != chave){
            anterior = atual;
            atual = atual->proximo;
        }

        if(atual == NULL){
            printVermelho("Desculpe, não encontramos esse sorteio na lista! Verifique se informou o número corretamente\n");
        } else {

            if(anterior == NULL){
                no = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            removerNumerosSorteados(tabelaHash, atual->sorteio.numSorteados);
            free(atual);

            tabelaHash->qtdSorteios--;

            printVerde("\nSorteio com a chave [");
            printf("%i", chave);
            printVerde("] removido com sucesso!\n");

        }   
    }
}


/**
 * @brief Método responsável por carregar informações de concursos
 * com base em um arquivo csv ou tsv
 * 
 * @param tabelaHash
 * @param nomeArquivo
 */
void carregarConcursosArquivoTabela(TabelaHash *tabelaHash, char *nomeArquivo) {
    FILE *file;
    char *regex;
    if(strstr(nomeArquivo, "tsv") == 0) {
        regex = ",";
    } else {
        regex = "\t";
    }

    char line[200];
    int contLinha = 0;
    file = fopen(nomeArquivo, "r");

    if (file == NULL) {
        printVermelho("\nFalha ao abrir arquivo! Verifique se informou o nome corretamente!\n");
        return;
    }

    while (fgets(line, 100, file) != NULL) {
        if(contLinha > 0) {
            int cont = 0;
            int numSorteio = 0;
            char data[10]; 
            int numerosSorteados[6];

            char *pt = strtok(line, regex);
            while(pt) {
                if(cont == 0) {
                    numSorteio = atoi(pt);
                } else if (cont == 1) {
                    strcpy(data, pt);
                } else {
                    numerosSorteados[cont-2] = atoi(pt);
                }
                cont++;
                pt = strtok(NULL, regex);
            }
            criarSorteioByArquivo(tabelaHash, numSorteio, data, numerosSorteados);
        }
        contLinha++;
    }
    printVerde("\nDados dos sorteios do arquivo: [");
    printf("%s", nomeArquivo);
    printVerde("] importados com sucesso!\n");
    fclose(file);
}

