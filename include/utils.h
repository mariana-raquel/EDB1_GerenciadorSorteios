#ifndef UTILS_H
#define UTILS_H

#include "../include/structs.h"

void iniciarTabela(TabelaHash *tabela);

void imprimirSorteio(Sorteio sorteio);

void inserirConcurso(TabelaHash *tabelaHash);

void buscarConcurso(TabelaHash *tabelaHash);

void removerConcurso(TabelaHash *tabelaHash);

void visualizarConcursos(TabelaHash *tabelaHash);

void carregarConcursosArquivo(TabelaHash *tabelaHash);

void apresentarEstatisticas(TabelaHash *tabela);

#endif