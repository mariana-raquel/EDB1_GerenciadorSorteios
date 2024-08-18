#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/structs.h"
#include "../include/tabela.h"
#include "../include/estatisticas.h"
#include "../include/cores.h"


/**
 * @brief Método responsável por inicialiar a 
 * estrutura da tabela hash
 * 
 * @param tabelaHash
 */
void iniciarTabela(TabelaHash *tabelaHash) {
    tabelaHash->qtdSorteios = 0;
    tabelaHash->tamanho = 10;
    tabelaHash->tabela = malloc(sizeof(No*) * tabelaHash->tamanho);
    for(int i = 0; i < tabelaHash->tamanho; i++) {
        tabelaHash->tabela[i] = NULL;
    }
    for(int i = 0; i < 60; i++) {
        tabelaHash->numerosSorteados[i].numero = i+1;
        tabelaHash->numerosSorteados[i].qtd = 0;
    }
}


/**
 * @brief Método responsável por montar a estrutura do Sorteio
 * com base nas informações vindas do arquivo
 * 
 * @param tabelaHash
 * @param numSorteio
 * @param data
 * @param numSorteados
 */
void criarSorteioByArquivo(TabelaHash *tabela, int numSorteio, char *data, int *numSorteados) {
    Sorteio sorteio;

    sorteio.codigo = numSorteio;
    strcpy(sorteio.data, data);
    for(int i = 0; i < 6; i++) {
        sorteio.numSorteados[i] = numSorteados[i];
    }

    inserirConcursoTabela(tabela, sorteio, sorteio.codigo);
}


/**
 * @brief Método responsável por um imprimir um sorteio
 * 
 * @param sorteio
 */
void imprimirSorteio(Sorteio sorteio) {
    printf("Sorteio: %i\tData: %s\tNúmeros Sorteados: ", sorteio.codigo, sorteio.data);
    for(int j = 0; j < 6; j++) {
        printf("%i\t", sorteio.numSorteados[j]);
    }
    printf("\n");
}


/**
 * @brief Método responsável por preenchar a lista dos números já sorteados
 * 
 * @param tabelaHash
 * @param numeros
 */
void adicionarNumerosSorteados(TabelaHash *tabelaHash, int *numeros) {
    for(int i = 0; i < 6; i++) {
        int ind = numeros[i]-1;
        tabelaHash->numerosSorteados[ind].qtd++;
    }
}


/**
 * @brief Método responsável por preenchar a lista dos números já sorteados
 * 
 * @param tabelaHash
 * @param numeros
 */
void removerNumerosSorteados(TabelaHash *tabelaHash, int *numeros) {
    for(int i = 0; i < 6; i++) {
        int ind = numeros[i]-1;
        tabelaHash->numerosSorteados[ind].qtd--;
    }
}

/**
 * @brief Método auxiliar para a inserção 
 * de um novo concurso na tabela 
 * 
 * @param tabelaHash
 */
void inserirConcurso(TabelaHash *tabelaHash) {
    Sorteio sorteio;
    printCiano("Qual o número do sorteio que você deseja criar? ");
    scanf("%i", &sorteio.codigo);
    printCiano("Em qual data ocorreu o sorteio? ");
    scanf("%s", sorteio.data);
    for(int i = 0; i < 6; i++) {
        printCiano("Qual foi o");
        printf(" %iº ", i+1);
        printCiano("número sorteado? ");
        scanf("%i", &sorteio.numSorteados[i]);
    }

    inserirConcursoTabela(tabelaHash, sorteio, sorteio.codigo);
}


/**
 * @brief Método auxiliar para a busca de um 
 * concurso na tabela
 * 
 * @param tabelaHash
 */
void buscarConcurso(TabelaHash *tabelaHash) {
    if(tabelaHash->qtdSorteios > 0) {
        int chave = 0;

        printCiano("Qual o número do sorteio que você deseja buscar? ");
        scanf("%i", &chave);

        Sorteio *sorteio = buscarConcursoTabela(tabelaHash, chave);

        if(sorteio == NULL) {
            printAmarelo("\nSorteio com a chave [");
            printf("%i", chave);
            printAmarelo("] não encontrado!\n");
        } else {
            imprimirSorteio(*sorteio);
        }
     } else {
        printAmarelo("Não existem concursos armazenados na tabela!\n");
    }
}


/**
 * @brief Método auxiliar para a remoção
 * de um concurso da tabela
 * 
 * @param tabelaHash
 */
void removerConcurso(TabelaHash *tabelaHash) {
    if(tabelaHash->qtdSorteios > 0) {
        int chave = 0;

        printCiano("Qual o número do sorteio que você deseja remover? ");
        scanf("%i", &chave);

        removerConcursoTabela(tabelaHash, chave);
     } else {
        printAmarelo("Não existem concursos armazenados na tabela!\n");
    }
}


/**
 * @brief Método responsável pela visualização 
 * dos sorteios inseridos na tabela
 * 
 * @param tabelaHash
 */
void visualizarConcursos(TabelaHash *tabelaHash) {
    if(tabelaHash->qtdSorteios > 0) {
        printMagenta("Lista de sorteios presentes na tabela:\n");
        for(int i = 0; i < tabelaHash->tamanho; i++) {
            if(tabelaHash->tabela[i] != NULL) {
                No *temp = tabelaHash->tabela[i];
                while(temp != NULL) {
                    imprimirSorteio(temp->sorteio);
                    temp = temp->proximo;
                }
            }
        }

    } else {
        printAmarelo("Não existem concursos armazenados na tabela!\n");
    }
}


/**
 * @brief Método auxiliar para o carregamentos 
 * dos dados a partir de um arquivo
 * 
 * @param tabelaHash
 */
void carregarConcursosArquivo(TabelaHash *tabelaHash) {
    char nomeArquivo[200];

    printCiano("Por favor, nos informe o caminho do arquivo ao qual deseja recuperar os dados: ");
    scanf("%s", nomeArquivo);

    carregarConcursosArquivoTabela(tabelaHash, nomeArquivo);
}


/**
 * @brief Método auxiliar para a apresentação das estatísticas
 * dos dados presentes na tabela
 * 
 * @param tabelaHash
 */
void apresentarEstatisticas(TabelaHash *tabelaHash) {
    int opcao = 0;

    while(opcao < 1 || opcao > 4) {
        printCiano("Informe qual estatística deseja visualizar:\n");
        printCiano("1 - Quantidade de sorteios de um número\t\t\t");
        printCiano("3 - Dez Números Mais Sorteados\n");
        printCiano("2 - Quantidade de concursos em um determinado ano\t");
        printCiano("4 - Dez Números Menos Sorteados\n");

        scanf("%i", &opcao);
        if(opcao >= 1 && opcao <= 4) {
            switch (opcao) {
                case 1:
                    printVerde("Você escolheu a opção: 1 - Quantidade de sorteios de um número\n\n");
                    qtdSorteiosPorNumero(tabelaHash);
                    break;
                case 2:
                    printVerde("Você escolheu a opção: 2 - Quantidade de concursos em um determinado ano\n\n");
                    qtdSorteiosPorAno(tabelaHash);
                    break;
                case 3:
                    printVerde("Você escolheu a opção: 3 - Dez Números Mais Sorteados\n\n");
                    dezNumerosMaisSorteados(tabelaHash);
                    break;
                case 4:
                    printVerde("Você escolheu a opção: 4 - Dez Números Menos Sorteados\n\n");
                    dezNumerosMenosSorteados(tabelaHash);
                    break;
                default:
                    break;
            }
        } else {
            printVermelho("\nEscolha uma opção válida!\n\n");
        }
    }
}


/**
 * @brief Método auxiliar responsável por ordenar 
 * os números sorteados para a apresentação das estatísticas
 * 
 * @param numerosSorteados
 */
void ordenarNumerosSorteados(NumerosSorteados numerosSorteados[]) {
    int j, qAtual, nAtual;
    for(int i = 1; i < 60; i++) {
        qAtual = numerosSorteados[i].qtd;
        nAtual = numerosSorteados[i].numero;
        j = i - 1;
        while(j >= 0 && numerosSorteados[j].qtd > qAtual) {
            numerosSorteados[j+1].qtd = numerosSorteados[j].qtd;
            numerosSorteados[j+1].numero = numerosSorteados[j].numero;
            j = j - 1;
        }
        numerosSorteados[j+1].qtd = qAtual;
        numerosSorteados[j+1].numero = nAtual;
    }
}


/**
 * @brief Método responsável por liberar a tabela
 * 
 * @param tabelaHash
 */
void liberarTabela(TabelaHash *tabelaHash) {
    for(int i = 0; i < tabelaHash->tamanho; i++){
        No* no = tabelaHash->tabela[i];
        
        while(no != NULL) {
            No* temp = no;
            no = no->proximo;
            
            free(temp);
        }
    }
    
    free(tabelaHash->tabela);
    free(tabelaHash);
}


