#ifndef UTILS_H
#define UTILS_H

#include "../include/structs.h"

void iniciarTabela(TabelaHash *tabela);

void criarSorteioByArquivo(TabelaHash *tabela, int numSorteio, char *data, int *numSorteados);

void imprimirSorteio(Sorteio sorteio);

void inserirConcurso(TabelaHash *tabelaHash);

void buscarConcurso(TabelaHash *tabelaHash);

void removerConcurso(TabelaHash *tabelaHash);

void visualizarConcursos(TabelaHash *tabelaHash);

void carregarConcursosArquivo(TabelaHash *tabelaHash);

void adicionarNumerosSorteados(TabelaHash *tabelaHash, int *numeros);

void removerNumerosSorteados(TabelaHash *tabelaHash, int *numeros);

void imprimirSorteio(Sorteio sorteio);

void apresentarEstatisticas(TabelaHash *tabela);

void ordenarNumerosSorteados(NumerosSorteados vetor[]);

void liberarTabela(TabelaHash *tabela);

#endif