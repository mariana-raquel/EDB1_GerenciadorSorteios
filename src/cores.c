#include <stdio.h>

/**
 * @brief Método responsável por personalizar
 * os prints com a cor Vermelha.
 * 
 * @param valor
 */
void printVermelho(char valor[]) {
    printf("\033[0;31m");
    printf("%s", valor);
    printf("\033[0m");
}


/**
 * @brief Método responsável por personalizar
 * os prints com a cor Verde.
 * 
 * @param valor
 */
void printVerde(char valor[]) {
    printf("\033[0;32m");
    printf("%s", valor);
    printf("\033[0m");
}


/**
 * @brief Método responsável por personalizar
 * os prints com a cor Amarela.
 * 
 * @param valor
 */
void printAmarelo(char valor[]) {
    printf("\033[0;33m");
    printf("%s", valor);
    printf("\033[0m");
}


/**
 * @brief Método responsável por personalizar
 * os prints com a cor Azul.
 * 
 * @param valor
 */
void printAzul(char valor[]) {
    printf("\033[0;34m");
    printf("%s", valor);
    printf("\033[0m");
}


/**
 * @brief Método responsável por personalizar
 * os prints com a cor Magenta.
 * 
 * @param valor
 */
void printMagenta(char valor[]) {
    printf("\033[0;35m");
    printf("%s", valor);
    printf("\033[0m");
}


/**
 * @brief Método responsável por personalizar
 * os prints com a cor Ciano.
 * 
 * @param valor
 */
void printCiano(char valor[]) {
    printf("\033[0;36m");
    printf("%s", valor);
    printf("\033[0m");
}