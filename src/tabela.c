#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "../include/structs.h"
#include "../include/cores.h"
#include "../include/tabela.h"
#include "../include/sorteio.h"
#include "../include/utils.h"


int funcaoHash(int chave, int tamanho) {
    return chave % tamanho;
}


void inserirConcursoTabela(TabelaHash *tabelaHash, Sorteio sorteio, int chave) {
    if(buscarConcursoTabela(tabelaHash, chave) == NULL) {
        int indice = funcaoHash(chave, tabelaHash->tamanho);
        No* novo_no = malloc(sizeof(No));
        novo_no->sorteio = sorteio;
        novo_no->proximo = tabelaHash->tabela[indice];
        tabelaHash->tabela[indice] = novo_no;
        tabelaHash->qtdSorteios++;

    } else {
        printAmarelo("\nJá existe um sorteio na tabela com o código: [");
        printf("%i", chave);
        printAmarelo("]!\n");
    }
}


Sorteio* buscarConcursoTabela(TabelaHash *tabela, int chave) {
    Sorteio *sorteio = NULL;

    int indice = funcaoHash(chave, tabela->tamanho);
    No* no = tabela->tabela[indice];

    while(no != NULL){
        if(no->sorteio.codigo == chave) {
            return &no->sorteio;
        }
        no = no->proximo;
    }

    return sorteio;
}


void removerConcursoTabela(TabelaHash *tabela, int chave) {
    int indice = funcaoHash(chave, tabela->tamanho);
    No *no = tabela->tabela[indice];

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

            free(atual);

            tabela->qtdSorteios--;

            printVerde("\nSorteio com a chave [");
            printf("%i", chave);
            printVerde("] removido com sucesso!\n");

        }   
    }
}


void visualizarConcursosTabela(TabelaHash *tabela) {
    printf("INICIO\n");
    for(int i = 0; i < tabela->tamanho; i++) {
        if(tabela->tabela[i] == NULL) {
            printf("\t%i\t---\n", i);
        } else {
            No *temp = tabela->tabela[i];
            printf("\t%i\t", i);
            while(temp != NULL) {
                printf("%i\t", temp->sorteio.codigo);
                temp = temp->proximo;
            }
            printf("\n");
        }
    }
    printf("FIM\n");
}


void carregarConcursosArquivoTabela(TabelaHash *tabela, char *nomeArquivo) {
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
            criarSorteioByArquivo(tabela, numSorteio, data, numerosSorteados);
        }
        contLinha++;
    }
    printVerde("\nDados dos sorteios do arquivo: [");
    printf("%s", nomeArquivo);
    printVerde("] importados com sucesso!\n");
    fclose(file);
}


void liberarTabela(TabelaHash *tabela) {
    for(int i = 0; i < tabela->tamanho; i++){
        No* no = tabela->tabela[i];
        
        while(no != NULL) {
            No* temp = no;
            no = no->proximo;
            
            free(temp);
        }
    }
    
    free(tabela->tabela);
    free(tabela);
    iniciarTabela(tabela);
}

