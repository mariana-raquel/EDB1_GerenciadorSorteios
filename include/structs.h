#ifndef STRUCTS_H
#define STRUCTS_H


typedef struct sorteio {
    int codigo;
    char data[11];
    int numSorteados[6];
} Sorteio;


/**
 * Estrutura responsável por representar 
 * os Nós que compõe a lista
 */
typedef struct no {
    Sorteio sorteio;
    int idSorteio;
    struct no *proximo;
} No;


#endif