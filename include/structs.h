#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct sorteio {
    int codigo;
    char data[11];
    int numSorteados[6];
} Sorteio;

typedef struct numerosSorteados {
    int numero;
    int qtd;
} NumerosSorteados;

typedef struct no {
    Sorteio sorteio;
    struct no *proximo;
} No;

typedef struct tabelaHash {
    No** tabela;
    int tamanho;
    int qtdSorteios;
    NumerosSorteados numerosSorteados[60];
} TabelaHash;


#endif