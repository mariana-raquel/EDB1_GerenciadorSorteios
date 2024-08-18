#ifndef SORTEIO_H
#define SORTEIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/tabela.h"
#include "../include/structs.h"


void criarSorteio(TabelaHash *tabelaHash);

void criarSorteioByArquivo(TabelaHash *tabela, int numSorteio, char *data, int *numSorteados);

void printSorteio(TabelaHash *tabela, Sorteio *sorteio);

#endif