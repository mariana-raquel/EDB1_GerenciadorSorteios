# Gerenciador de Concursos da Mega-Sena com Tabela de Dispersão

## Sumário:
* **[Descrição](#descrição)**
* **[Funcionalidades](#funcionalidades)**
* **[Como executar?](#como-executar)**
* **[Discente](#discente)**

## Descrição:

O projeto envolve a criação de um gerenciador de concursos da Mega-Sena que utiliza uma tabela de dispersão para armazenar e acessar os dados dos concursos. Além das operações básicas de inserção, busca e remoção, o sistema deve ser capaz de calcular e apresentar estatísticas sobre os resultados dos concursos. A implementação deve ser feita na linguagem C.

O detalhamento do projeto encontra-se __*[aqui](./docs/projeto_2.pdf)*__.

O projeto está neste __*[repositório](https://github.com/mariana-raquel/EDB1_GerenciadorSorteios)*__.

## Funcionalidades:

### 1 - Inserir um concurso:
Permite o usuário inserir um novo concurso na tabela.

### 2 - Buscar concurso:
Permite o usuário buscar um concurso através do seu código.

### 3 - Remover concurso:
Permite o usuário remover um concurso através do seu código.

### 4 - Visualizar todos os concursos:
Permite o usuário visualizar todos os concursos inseridos na tabela.

### 5 - Carregar concursos de um Arquivo:
Permite o usuário inserir concursos na tabela através de dados presentes num arquivo CSV ou TSV.

### 6 - Apresentar estatísticas:
#### 6.1 - Quantidade de sorteios de um número:
Permite o usuário ver a quantidade de vezes que determinado número foi sorteado, dentre os concursos armazenados na tabela.

#### 6.2 - Quantidade de concursos em um determinado ano:
Permite o usuário quantidade de sorteios que ocorreram em determinado ano, bem como suas informações, dentre os concursos armazenados na tabela.

#### 6.3 - Dez Números Mais Sorteados:
Permite o usuário visualizar os 10 números mais sorteados dentre os concursos armazenados na tabela.

#### 6.4 - Dez Números Menos Sorteados:
Permite o usuário visualizar os 10 números menos sorteados dentre os concursos armazenados na tabela.

## Como executar?
Para compilar o projeto, no diretório base, execute:

``` 
$ make 
```
Para executar o projeto, utilize:
```
$ ./bin/gerenciador_sorteios
```
ou:
```
$ cd bin
$ ./gerenciador_sorteios
```
Obs.: Certifique-se de que possui o `gcc` e o `make` instalados.

> Para limpar os arquivos gerados durante a compilação (.o), juntamente com o executável:
> * make clean

## Discente:
Mariana Raquel de Morais (20230033690)