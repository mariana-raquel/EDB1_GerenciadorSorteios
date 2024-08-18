#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/structs.h"
#include "../include/cores.h"
#include "../include/utils.h"


/**
 * @brief Método responsável por verificar se o usuário
 * deseja utilizar outra funcionalidade.
 * 
 * @return
 */
int maisOpcoes() {
    int opcao = 0;
    printCiano("\nDeseja utilizar alguma outra funcionalidade?\n");
    printCiano("1 - Sim\t\t2 - Não\n");
    scanf("%i", &opcao);
    return opcao == 1 ? 0 : 7;
}

/**
 * @brief Método principal do programa contendo o menu 
 * com as funcionalidades disponíveis.
 * 
 * @return
 */
int main() {
    int opcao = 0;
    TabelaHash *tabelaHash = malloc(sizeof(TabelaHash));;
    iniciarTabela(tabelaHash);

    while(opcao < 1 || opcao > 7) {
        printCiano("\nInforme qual funcionalidade deseja utilizar:\n");
        printCiano("1 - Inserir um concurso\t\t\t\t");
        printCiano("5 - Carregar concursos de um Arquivo\n");
        printCiano("2 - Buscar concurso\t\t\t\t");
        printCiano("6 - Apresentar estatísticas\n");
        printCiano("3 - Remover concurso\t\t\t\t");
        printCiano("7 - Sair\n");
        printCiano("4 - Visualizar todos os concursos\n");

        scanf("%i", &opcao);
        if(opcao >= 1 && opcao <= 7) {
            switch (opcao) {
                case 1:
                    printVerde("Você escolheu a opção: 1 - Inserir um concurso\n\n");
                    inserirConcurso(tabelaHash);
                    opcao = maisOpcoes();
                    break;
                case 2:
                    printVerde("Você escolheu a opção: 2 - Buscar concurso\n\n");
                    buscarConcurso(tabelaHash);
                    opcao = maisOpcoes();
                    break;
                case 3:
                    printVerde("Você escolheu a opção: 3 - Remover concurso\n\n");
                    removerConcurso(tabelaHash);
                    opcao = maisOpcoes();
                    break;
                case 4:
                    printVerde("Você escolheu a opção: 4 - Visualizar todos os concursos\n\n");
                    visualizarConcursos(tabelaHash);
                    opcao = maisOpcoes();
                    break;
                case 5:
                    printVerde("Você escolheu a opção: 5 - Carregar concursos de um Arquivo\n\n");
                    carregarConcursosArquivo(tabelaHash);
                    opcao = maisOpcoes();
                    break;
                case 6:
                    printVerde("Você escolheu a opção: 6 - Apresentar estatísticas\n\n");
                    apresentarEstatisticas(tabelaHash);
                    opcao = maisOpcoes();
                    break;
                case 7:
                    printVerde("Você escolheu a opção: 7 - Sair\n");
                    break;
                default:
                    break;
            }
        } else {
            printVermelho("Escolha uma opção válida!\n");
        }
    }
    
    printMagenta("\nObrigado por utilizar nosso serviços!\n\n");
    liberarTabela(tabelaHash);

    return 0;
}

