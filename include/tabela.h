#ifndef TABELA_H
#define TABELA_H

#include <stdbool.h>
#include "../include/structs.h"


int funcaoHash(int chave, int tamanho);

void inserirConcursoTabela(TabelaHash *tabela, Sorteio sorteio, int chave);

Sorteio* buscarConcursoTabela(TabelaHash *tabela, int chave);

void removerConcursoTabela(TabelaHash *tabela, int chave);

void visualizarConcursosTabela(TabelaHash *tabela);

void carregarConcursosArquivoTabela(TabelaHash *tabela, char *nomeArquivo);

void liberarTabela(TabelaHash *tabela);



#endif